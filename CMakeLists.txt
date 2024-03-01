cmake_minimum_required(VERSION 3.5)

project(SecretMessagingBackEnd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(SecretMessagingBackEnd SHARED main.cpp Encoder.cpp Encoder.h)
add_executable(Tests Tests.cpp)
target_link_libraries(Tests PUBLIC SecretMessagingBackEnd)

include(GNUInstallDirs)
install(TARGETS SecretMessagingBackEnd
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
