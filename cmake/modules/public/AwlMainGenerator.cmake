if(
	NOT
	${PROJECT_NAME}
	STREQUAL
	"awl"
	AND
	NOT
	awl_FOUND
)
	message(
		FATAL_ERROR
		"AwlMainGenerator included without prior find_package(awl)"
	)
endif()

function(
	awl_utils_add_portable_executable
	target_name
	main_function_name
)
	set(
		AWL_UTILS_FULLY_QUALIFIED_MAIN_FUNCTION_NAME
		"${main_function_name}"
	)

	string(
		REPLACE
		"::"
		";"
		awl_utils_current_namespace_list
		${main_function_name}
	)

	list(
		LENGTH
		awl_utils_current_namespace_list
		awl_utils_current_number_of_namespaces
	)

	math(
		EXPR
		awl_utils_current_number_of_namespaces_minus_one
		"${awl_utils_current_number_of_namespaces}-1"
	)

	math(
		EXPR
		awl_utils_current_number_of_namespaces_minus_two
		"${awl_utils_current_number_of_namespaces_minus_one}-1"
	)

	set(
		AWL_UTILS_MAIN_FUNCTION_NAMESPACES_BEGIN
		""
	)

	set(
		AWL_UTILS_MAIN_FUNCTION_NAMESPACES_END
		""
	)

	if(
		${awl_utils_current_number_of_namespaces_minus_one}
		GREATER
		0
	)
		foreach(
			i RANGE 0
			${awl_utils_current_number_of_namespaces_minus_two}
		)
			list(
				GET
				awl_utils_current_namespace_list
				${i}
				awl_utils_current_namespace
			)

			set(
				AWL_UTILS_MAIN_FUNCTION_NAMESPACES_BEGIN
"${AWL_UTILS_MAIN_FUNCTION_NAMESPACES_BEGIN}namespace ${awl_utils_current_namespace}
{
")

			set(
				AWL_UTILS_MAIN_FUNCTION_NAMESPACES_END
"${AWL_UTILS_MAIN_FUNCTION_NAMESPACES_END}
}")
		endforeach()
	endif()

	list(
		GET
		awl_utils_current_namespace_list
		${awl_utils_current_number_of_namespaces_minus_one}
		AWL_UTILS_MAIN_FUNCTION_NAME
	)

	set(
		awl_utils_temp_target_name
		${CMAKE_BINARY_DIR}/targets/${target_name}.cpp
	)

	configure_file(
		${awl_utils_prototype_file_name}
		${awl_utils_temp_target_name}
		@ONLY
	)

	add_executable(
		${target_name}
		WIN32
		${awl_utils_temp_target_name}
		${ARGN}
	)
endfunction()
