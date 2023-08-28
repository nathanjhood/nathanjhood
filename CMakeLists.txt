cmake_minimum_required (VERSION 3.7...3.27 FATAL_ERROR)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/share/cmake/Modules")

if (NOT DEFINED StoneyDSP_MASTER_PROJECT)
	set (StoneyDSP_MASTER_PROJECT OFF)
	if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
		set (StoneyDSP_MASTER_PROJECT ON)
		message (STATUS "CMake version: ${CMAKE_VERSION}")
	endif ()
endif ()

#[===[
Joins arguments and places them in ${result}.
]===]
function (join result)
	set (__result "")
	foreach (arg ${ARGN})
		set (__result "${__result}${arg}")
	endforeach ()
	set (result "${__result}" PARENT_SCOPE)
endfunction ()

#[===[
Adds a library compiled with C++20 module support.
'enabled' is a CMake variable that specifies if modules are enabled.
If modules are disabled, 'add_module_library' falls back to creating a
non-modular library.

Usage:

add_module_library(<name> [sources...] FALLBACK [sources...] [IF enabled])
]===]
function (add_module_library name)
	cmake_parse_arguments(AML "" "IF" "FALLBACK" ${ARGN})
	set (sources ${AML_UNPARSED_ARGUMENTS})

	add_library (${name})
	set_target_properties (${name} PROPERTIES LINKER_LANGUAGE CXX)

	if (NOT ${${AML_IF}})
		# Create a non-modular library
		target_sources (${name} PRIVATE ${AML_FALLBACK})
		return ()
	endif ()

	# Modules require C++20
	target_compile_features (${name} PUBLIC cxx_std_20)
	if (CMAKE_COMPILER_IS_GNUCXX)
		target_compile_options (${name} PUBLIC -fmodules-ts)
	endif ()

	# 'std' is affected by CMake options, and may be higher than C++20.
	get_target_property (std ${name} CXX_STANDARD)

	if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
		set (pcms)
		foreach (src ${sources})
			get_filename_component (pcm ${src} NAME_WE)
			set (pcm ${pcm}.pcm)

			# propagate '-fmodule-file=*.pcm' to targets that link with this
			# library.
			target_compile_options (${name}
				PUBLIC
					-fmodule-file=${CMAKE_BINARY_DIR}/${pcm}
			)

			# Use an absolute path to prevent 'target_link_libraries' prepending
			# '-l' to it.
			set (pcms ${pcms} ${CMAKE_CURRENT_BINARY_DIR}/${pcm})

			add_custom_command(
				OUTPUT ${pcm}
				COMMAND ${CMAKE_CXX_COMPILER}
					-std=c++${std} -x c++module --precompile -c
					-o ${pcm} ${CMAKE_CURRENT_SOURCE_DIR}/${src}
					"-I$<JOIN:$<TARGET_PROPERTY:${name},INCLUDE_DIRECTORIES>,;-I>"
					# Required by the '-I' expression above:
					COMMAND_EXPAND_LISTS
					DEPENDS ${src}
			)
		endforeach () # src ${sources}

		set(sources)
		foreach (pcm ${pcms})
			get_filename_component (pcm_we ${pcm} NAME_WE)
			set (obj ${pcm_we}.o)
			# Use an absolute path to prevent 'target_link_libraries' prepending
			# '-l' to it.
			set (sources ${sources} ${pcm} ${CMAKE_CURRENT_BINARY_DIR}/${obj})
			add_custom_command (
				OUTPUT ${obj}
				COMMAND ${CMAKE_CXX_COMPILER} $<TARGET_PROPERTY:${name},COMPILE_OPTIONS>
				-c -o ${obj} ${pcm}
				DEPENDS ${pcm}
			)
		endforeach ()
	endif () # CMAKE_CXX_COMPILER_ID MATCHES "Clang"
	target_sources (${name} PRIVATE ${sources})
endfunction ()

project (StoneyDSP)

include (GNUInstallDirs)
include (CMakePackageConfigHelpers)

set (PROJECT_VERSION_MAJOR 1)
set (PROJECT_VERSION_MINOR 0)
set (PROJECT_VERSION_PATCH 0)

include (GetSourceInfo)
get_source_info ()
set (PROJECT_VERSION_TWEAK "${git_revision}")
# set(PROJECT_VERSION_TWEAK "x")

set (PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}-${PROJECT_VERSION_TWEAK}" CACHE STRING "Value given to the ``VERSION`` option of the most recent call to the ``project()`` command, if any." FORCE)
set (PROJECT_DESCRIPTION "A quick one-and-done Win32 API project implementing a COM blank application window for Windows platforms in C++." CACHE STRING "Short project description given to the project command." FORCE)
set (PROJECT_HOMEPAGE_URL "https://github.com/StoneyDSP/CxxWin.git" CACHE STRING "The homepage URL of the project." FORCE)

option (OPTION_SHARED_LIBS "Global flag to cause ``add_library()`` to create shared libraries if on." ON)

if (OPTION_SHARED_LIBS)
	set (BUILD_SHARED_LIBS ON CACHE BOOL "Global flag to cause ``add_library()`` to create shared libraries if on." FORCE)
else ()
	set (BUILD_SHARED_LIBS OFF CACHE BOOL "Global flag to cause ``add_library()`` to create shared libraries if on." FORCE)
endif ()

set(StoneyDSP_REQUIRED_DEFS)
list(APPEND StoneyDSP_REQUIRED_DEFS
	UNICODE
	_UNICODE
)

set(StoneyDSP_REQUIRED_FLAGS)
if(NOT (CYGWIN OR MSYS))
	list(APPEND StoneyDSP_REQUIRED_FLAGS -municode)
endif()

list(APPEND StoneyDSP_REQUIRED_FLAGS -mwindows)



if (StoneyDSP_MASTER_PROJECT AND CMAKE_GENERATOR MATCHES "Visual Studio")
	include (FindSetEnv)
	if (WINSDK_SETENV)
		set (MSBUILD_SETUP "call \"${WINSDK_SETENV}\"")
	endif ()
	join(netfxpath
	"C:\\Program Files\\Reference Assemblies\\Microsoft\\Framework\\"
	".NETFramework\\v4.0"
	)
	file (WRITE run-msbuild.bat "
	${MSBUILD_SETUP}
	${CMAKE_MAKE_PROGRAM} -p:FrameworkPathOverride=\"${netfxpath}\" %*")
endif ()

set (StoneyDSPTargets)


add_executable (executable)
add_executable (StoneyDSP::executable ALIAS executable)

target_include_directories (executable

    PRIVATE

        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

set_target_properties (executable

    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY bin
        LIBRARY_OUTPUT_DIRECTORY lib
        ARCHIVE_OUTPUT_DIRECTORY lib
        PDB_OUTPUT_DIRECTORY     bin
)

target_sources (executable

    PRIVATE

        FILE_SET executable_PRIVATE_HEADERS
        TYPE HEADERS

        BASE_DIRS
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}>
            $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
        FILES
            # include/${PROJECT_NAME}/main.h
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}/Main.h>
            $<INSTALL_INTERFACE:include/${PROJECT_NAME}/Main.h>
)

target_sources (executable

    PRIVATE
        # src/runtime/main.cpp
        "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/Main.cpp"
)

set_target_properties (executable

    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY bin
        LIBRARY_OUTPUT_DIRECTORY lib
        ARCHIVE_OUTPUT_DIRECTORY lib
        PDB_OUTPUT_DIRECTORY     bin
)

target_compile_definitions(executable

	PUBLIC
		${StoneyDSP_REQUIRED_DEFS}
)

target_compile_options(executable

	PUBLIC
		${StoneyDSP_REQUIRED_FLAGS}
)

target_link_options (executable

	PUBLIC
		${StoneyDSP_REQUIRED_FLAGS}
)

# target_link_libraries (executable

#     ${PROJECT_NAME}::window
# )

list (APPEND StoneyDSPTargets executable)

install (
	TARGETS StoneyDSPTargets
	EXPORT StoneyDSPTargets
	LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
	ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
	INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    # FILE_SET StoneyDSP_PUBLIC_HEADERS
)

install (
	EXPORT StoneyDSPTargets
	FILE StoneyDSPTargets.cmake
	NAMESPACE StoneyDSP::
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/StoneyDSP"
)

# ##-- Create package config

configure_package_config_file (
	"${CMAKE_CURRENT_SOURCE_DIR}/share/StoneyDSPConfig.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/StoneyDSPConfig.cmake"
	INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/StoneyDSP"
)

install (
	FILES
	"${CMAKE_CURRENT_BINARY_DIR}/StoneyDSPConfig.cmake"
		# "${CMAKE_CURRENT_BINARY_DIR}/StoneyDSPConfigVersion.cmake"
	DESTINATION
		"${CMAKE_INSTALL_LIBDIR}/cmake/StoneyDSP"
)

export (
	EXPORT StoneyDSPTargets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/StoneyDSPTargets.cmake"
	NAMESPACE StoneyDSP::
)
