cmake_minimum_required(VERSION 3.5)

project(SecretMessagingBackEnd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES Encoder.cpp Encoder.h)
if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    add_executable(Tests ${SOURCES} Tests.cpp)

    message("Building with Emscripten. Emscripten bindings are included")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind")
    set(SOURCES ${SOURCES} EmscriptenBindings.h EmscriptenBindings.cpp)
    #Emscripten does not need entrypoint for the executable
    add_executable(SecretMessagingBackEnd ${SOURCES})

else()
    message("Not building with Emscripten")
    add_library(SecretMessagingBackEnd SHARED ${SOURCES})
    add_executable(Tests Tests.cpp)
    target_link_libraries(Tests PUBLIC SecretMessagingBackEnd)
endif()




include(GNUInstallDirs)
install(TARGETS SecretMessagingBackEnd
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
