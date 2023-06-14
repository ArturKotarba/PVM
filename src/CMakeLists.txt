include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES
    main.cpp
    stdafx.h
    GraphicsImgReader.h
    GraphicsImgReader.cpp
    SDLWindow.h
    SDLWindow.cpp
    ScreenManager.h
    ScreenManager.cpp
    BuildingAreaCalculator.h
    BuildingAreaCalculator.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-std=c++20)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} pvm3)
target_link_libraries(${PROJECT_NAME} m)
target_link_libraries(${PROJECT_NAME} stdc++)

set (OUTPUT_DIR
    ${CMAKE_SOURCE_DIR}/output
)
 
add_custom_command(TARGET ${PROJECT_NAME} 
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${OUTPUT_DIR})
