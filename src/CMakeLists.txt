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
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

set (OUTPUT_DIR
    ${CMAKE_SOURCE_DIR}/output
)
 
add_custom_command(TARGET ${PROJECT_NAME} 
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${OUTPUT_DIR})
