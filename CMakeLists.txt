#!/usr/bin/env cmake

# CMake requirements.
cmake_minimum_required(VERSION 3.9...3.26.2)
# Cmake-js requirements
cmake_policy(SET CMP0091 NEW)
cmake_policy(SET CMP0042 NEW)
# Fallback for using newer policies on CMake < 3.12.
if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()
set(CMAKE_INCLUDE_CURRENT_DIR OFF)
# Single-threaded build-runs only for compatible behaviour
set(CMAKE_BUILD_PARALLEL_LEVEL 1)
# Set the host architecture to build with
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(USE_X64 TRUE)
else ()
  set(USE_X64 FALSE)
endif ()
if (${VCPKG_ROOT})
  set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif ()

message("\n")

set(CMAKE_INSTALL_MODE SYMLINK)
set(CMAKE_INSTALL_MESSAGE ALWAYS)
message(STATUS "\n")
message(STATUS "Initiating CMake v${CMAKE_VERSION}\n")
message(STATUS "\n")

project("StoneyDSP")
# Parse the project name into vars
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
message(STATUS "Detected ${PROJECT_NAME} version: v${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}.${${PROJECT_NAME}_VERSION_TWEAK}")

# Determine if built as a subproject (using add_subdirectory), or if it is the master project.
if (NOT DEFINED ${PROJECT_NAME_UPPER}_MASTER_PROJECT)
  set(${PROJECT_NAME_UPPER}_MASTER_PROJECT OFF)
  if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    # ... this is a top-level project, then;
    set(PROJECT_IS_TOP_LEVEL TRUE)
    set(${PROJECT_NAME_UPPER}_MASTER_PROJECT ON)
    set(MASTER_PROJECT_NAME ${PROJECT_NAME} CACHE STRING "Name of master project")
    set(MASTER_PROJECT_NAME_UPPER ${PROJECT_NAME_UPPER} CACHE STRING "Name of master project (uppercase)")
    set(MASTER_PROJECT_NAME_LOWER ${PROJECT_NAME_LOWER} CACHE STRING "Name of master project (lowercase)")
    message(STATUS "${PROJECT_NAME} is a top-level CMake project\n")
  else ()
    # ... this is not a top-level project, so;
    set(PROJECT_IS_TOP_LEVEL FALSE)
    message(STATUS "${PROJECT_NAME} is a sub-project of ${CMAKE_PROJECT_NAME}\n")
  endif ()
endif ()

# Ensure a valid build type is set
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  if (${PROJECT_NAME_UPPER}_MASTER_PROJECT)
    set(DEFAULT_BUILD_TYPE Debug)
  else ()
    message(WARNING "Default build type is not set (CMAKE_BUILD_TYPE)")
  endif ()
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  set(${CMAKE_INSTALL_DEBUG_LIBRARIES} TRUE)
endif ()
include(InstallRequiredSystemLibraries)


# Print the flags for the user
if (DEFINED CMAKE_BUILD_TYPE)
  message(STATUS "Generated CMake build type: ${CMAKE_BUILD_TYPE}")
else ()
  message(STATUS "Generated CMake config types: ${CMAKE_CONFIGURATION_TYPES}")
endif ()



if (${PROJECT_NAME}_MASTER_PROJECT AND NOT DEFINED CMAKE_CXX_VISIBILITY_PRESET)
  set(CMAKE_CXX_VISIBILITY_PRESET hidden CACHE STRING "Preset for the export of private symbols (C++)")
  set_property(CACHE CMAKE_CXX_VISIBILITY_PRESET PROPERTY STRINGS hidden default)
endif ()
if (${PROJECT_NAME}_MASTER_PROJECT AND NOT DEFINED CMAKE_C_VISIBILITY_PRESET)
  set(CMAKE_C_VISIBILITY_PRESET hidden CACHE STRING "Preset for the export of private symbols (C)")
  set_property(CACHE CMAKE_C_VISIBILITY_PRESET PROPERTY STRINGS hidden default)
endif ()
if (${PROJECT_NAME}_MASTER_PROJECT AND NOT DEFINED CMAKE_VISIBILITY_INLINES_HIDDEN)
  set(CMAKE_VISIBILITY_INLINES_HIDDEN ON CACHE BOOL "Whether to add a compile flag to hide symbols of inline functions")
endif ()




# Generate CMAKE_INSTALL_<DIR> etc...
if (NOT CMAKE_INSTALL_INCLUDEDIR)
  set(CMAKE_INSTALL_INCLUDEDIR include CACHE PATH "C/C++ header files (include)")
endif ()
if (NOT CMAKE_INSTALL_BINDIR)
  set(CMAKE_INSTALL_BINDIR bin CACHE PATH "User executables (bin)")
endif ()
if (NOT CMAKE_INSTALL_SBINDIR)
  set(CMAKE_INSTALL_SBINDIR sbin CACHE PATH "System admin executables (sbin)")
endif ()
if (NOT CMAKE_INSTALL_LIBDIR)
  set(CMAKE_INSTALL_LIBDIR lib CACHE PATH "Object code libraries (lib)")
endif ()
if (NOT CMAKE_INSTALL_LIBEXECDIR)
  set(CMAKE_INSTALL_LIBEXECDIR libexec CACHE PATH "Program executables (libexec)")
endif ()
if (NOT CMAKE_INSTALL_SHAREDSTATEDIR)
  set(CMAKE_INSTALL_SHAREDSTATEDIR com CACHE PATH "Modifiable architecture-independent data (com)")
endif ()
if (NOT CMAKE_INSTALL_DATADIR)
  set(CMAKE_INSTALL_DATADIR ${CMAKE_INSTALL_DATAROOTDIR} CACHE PATH "Read-only architecture-independent data (DATAROOTDIR)")
endif ()
if (NOT CMAKE_INSTALL_LOCALSTATEDIR)
  set(CMAKE_INSTALL_LOCALSTATEDIR var CACHE PATH "Modifiable single-machine data (var)")
endif ()
if (NOT CMAKE_INSTALL_SYSCONFDIR)
  set(CMAKE_INSTALL_SYSCONFDIR etc CACHE PATH "Read-only single-machine data (etc)")
endif ()
if (NOT CMAKE_INSTALL_RUNSTATEDIR)
  set(CMAKE_INSTALL_RUNSTATEDIR ${CMAKE_INSTALL_LOCALSTATEDIR}/run CACHE PATH "Run-time variable data (LOCALSTATEDIR/run)")
endif ()
if (NOT CMAKE_INSTALL_LOCALEDIR)
  set(CMAKE_INSTALL_LOCALEDIR ${CMAKE_INSTALL_DATAROOTDIR}/locale CACHE PATH "Locale-dependent data (DATAROOTDIR/locale)")
endif ()
if (NOT CMAKE_INSTALL_DOCDIR)
  set(CMAKE_INSTALL_DOCDIR ${CMAKE_INSTALL_DATAROOTDIR}/doc/${PROJECT_NAME} CACHE PATH "Documentation root (DATAROOTDIR/doc/PROJECT_NAME)")
endif ()
if (NOT CMAKE_INSTALL_INFODIR)
  set(CMAKE_INSTALL_INFODIR ${CMAKE_INSTALL_DATAROOTDIR}/info CACHE PATH "Info documentation (DATAROOTDIR/info)")
endif ()
if (NOT CMAKE_INSTALL_MANDIR)
  set(CMAKE_INSTALL_MANDIR ${CMAKE_INSTALL_DATAROOTDIR}/man CACHE PATH "Man documentation (DATAROOTDIR/man)")
endif ()
# Don't set this var! https://cmake.org/cmake/help/latest/command/install.html#installing-files
if (NOT CMAKE_INSTALL_DATAROOTDIR)
  set(CMAKE_INSTALL_DATAROOTDIR share CACHE PATH "Read-only architecture-independent data root (share)")
endif ()
include(GNUInstallDirs)


# Set the binary output dir, if not set
if (NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/bin" CACHE PATH "Executable/dll output dir.")
endif ()
# Set the archive output dir, if not set
if (NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/lib" CACHE PATH "Archive output dir.")
endif ()
# Set the library output dir, if not set
if (NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/lib" CACHE PATH "Library output dir.")
endif ()
# Set the MSVC debug symbol output dir, if not set
if (NOT CMAKE_PDB_OUTPUT_DIRECTORY)
  set(CMAKE_PDB_OUTPUT_DIRECTORY      "${CMAKE_CURRENT_BINARY_DIR}/bin" CACHE PATH "PDB (MSVC debug symbol)output dir.")
endif ()
set(CMAKE_CFG_INTDIR                  "${CMAKE_CURRENT_BINARY_DIR}/int" CACHE PATH "CMake build artefacts directory.")


# Read the .gitignore file, if found
if (${CMAKE_CURRENT_SOURCE_DIR}/.gitignore)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/.gitignore ${PROJECT_NAME}_GITIGNORE_FILE)
endif()
# Read the .gitattributes file, if found
if (${CMAKE_CURRENT_SOURCE_DIR}/.gitattributes)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/.gitattributes ${PROJECT_NAME}_GITATTRIBUTES_FILE)
endif()
# Read the .gitattributes file, if found
if (${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules)
  file(READ ${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules ${PROJECT_NAME}_GITMODULES_FILE)
endif()


if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(PEDANTIC_COMPILE_FLAGS -pedantic-errors -Wall -Wextra -pedantic
      -Wold-style-cast -Wundef
      -Wredundant-decls -Wwrite-strings -Wpointer-arith
      -Wcast-qual -Wformat=2 -Wmissing-include-dirs
      -Wcast-align
      -Wctor-dtor-privacy -Wdisabled-optimization
      -Winvalid-pch -Woverloaded-virtual
      -Wconversion -Wundef
      -Wno-ctor-dtor-privacy -Wno-format-nonliteral)
  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.6)
      set(PEDANTIC_COMPILE_FLAGS ${PEDANTIC_COMPILE_FLAGS}
         -Wno-dangling-else -Wno-unused-local-typedefs)
  endif ()
  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0)
      set(PEDANTIC_COMPILE_FLAGS ${PEDANTIC_COMPILE_FLAGS} -Wdouble-promotion
          -Wtrampolines -Wzero-as-null-pointer-constant -Wuseless-cast
          -Wvector-operation-performance -Wsized-deallocation -Wshadow)
  endif ()
  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 6.0)
      set(PEDANTIC_COMPILE_FLAGS ${PEDANTIC_COMPILE_FLAGS} -Wshift-overflow=2
          -Wnull-dereference -Wduplicated-cond)
  endif ()
  set(WERROR_FLAG -Werror)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(PEDANTIC_COMPILE_FLAGS -Wall -Wextra -pedantic -Wconversion -Wundef
      -Wdeprecated -Wweak-vtables -Wshadow
      -Wno-gnu-zero-variadic-macro-arguments)
  # check_cxx_compiler_flag(-Wzero-as-null-pointer-constant HAS_NULLPTR_WARNING) // Crashing github workflows...
  if (HAS_NULLPTR_WARNING)
    set(PEDANTIC_COMPILE_FLAGS ${PEDANTIC_COMPILE_FLAGS}
        -Wzero-as-null-pointer-constant)
  endif ()
  set(WERROR_FLAG -Werror)
endif ()

if (MSVC)
  set(PEDANTIC_COMPILE_FLAGS /W3)
  set(WERROR_FLAG /WX)
endif ()

add_subdirectory("./Development/fmtlib/fmt")
add_subdirectory("./Development/catchorg/Catch2")
add_subdirectory("./Development/StoneyDSP/cmodule")
# add_subdirectory("./Development/StoneyDSP/CMakeProject1")
