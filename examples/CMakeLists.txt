function(
	add_awl_example
	EXAMPLE_NAME
	ADDITIONAL_DEPS
)
	set(
		TARGET_NAME
		awl_example_${EXAMPLE_NAME}
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
		${ADDITIONAL_DEPS}
	)
endfunction()

add_awl_example(main "${fcppt_core_TARGET}")
add_awl_example(resize "${fcppt_core_TARGET}")
add_awl_example(show "${fcppt_core_TARGET}")
