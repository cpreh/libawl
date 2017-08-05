function(
	add_awl_test
	PATH_NAME
)
	set(
		MULTI_ARGS
		LINK_LIBS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	fcppt_utils_add_test(
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/test
		"${PATH_NAME}"
		LINK_LIBS
			${_LINK_LIBS}
			awl_interface
	)
endfunction()

add_awl_test(
	stream/lazy_function
)

add_awl_test(
	stream/object
)
