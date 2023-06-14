set(SOURCES
    master.cpp
    stdafx.h
)

add_executable(master ${SOURCES})

target_link_libraries(master pvm3)
target_link_libraries(master stdc++)


add_definitions(-std=c++20)
target_link_libraries(master stdc++)

set (OUTPUT_DIR
    ${CMAKE_SOURCE_DIR}/output
)
 
add_custom_command(TARGET master 
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:master> ${OUTPUT_DIR})
