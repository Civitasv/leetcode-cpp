add_executable(leetcode leetcode.cpp)

target_include_directories(leetcode PUBLIC
$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)