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
