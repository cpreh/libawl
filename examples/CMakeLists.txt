include(
	CMakeParseArguments
)

function(
	add_awl_example
	EXAMPLE_NAME
)
	set(
		TARGET_NAME
		awl_example_${EXAMPLE_NAME}
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


	add_executable(
		${TARGET_NAME}
		${EXAMPLE_NAME}.cpp
	)

	fcppt_utils_set_target_compiler_flags(
		${TARGET_NAME}
	)

	target_include_directories(
		${TARGET_NAME}
		PRIVATE
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include
	)

	target_link_libraries(
		${TARGET_NAME}
		PRIVATE
		${awl_TARGET}
		${_LINK_LIBS}
	)
endfunction()

add_awl_example(
	main
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_awl_example(
	resize
	LINK_LIBS
		${fcppt_core_TARGET}
		${fcppt_log_TARGET}
)

add_awl_example(
	show
	LINK_LIBS
		${fcppt_core_TARGET}
)
