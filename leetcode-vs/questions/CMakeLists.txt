message("START")
message(STATUS ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(
	leetcode-vs
	PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
)