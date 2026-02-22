cmake_minimum_required(VERSION 3.14)
project(06_response_handler VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Fetch springbootplusplus_web (HTTP request/response, dispatcher, ResponseEntity, etc.)
FetchContent_Declare(
    springbootplusplus_web
    GIT_REPOSITORY https://github.com/compilerNayan/springbootplusplus_web.git
    GIT_TAG        main
)

FetchContent_MakeAvailable(springbootplusplus_web)

# Header-only INTERFACE library; exposes springbootplusplus_web
add_library(06_response_handler INTERFACE)

set_target_properties(06_response_handler PROPERTIES
    VERSION ${PROJECT_VERSION}
)

target_include_directories(06_response_handler INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Link springbootplusplus_web (provides HttpRequestManager, ResponseEntity, dispatcher, etc.)
if(TARGET springbootplusplus_web::springbootplusplus_web)
    target_link_libraries(06_response_handler INTERFACE springbootplusplus_web::springbootplusplus_web)
elseif(TARGET springbootplusplus_web)
    target_link_libraries(06_response_handler INTERFACE springbootplusplus_web)
else()
    FetchContent_GetProperties(springbootplusplus_web)
    if(springbootplusplus_web_SOURCE_DIR)
        target_include_directories(06_response_handler INTERFACE
            $<BUILD_INTERFACE:${springbootplusplus_web_SOURCE_DIR}/src>
        )
    endif()
endif()

include(GNUInstallDirs)

install(TARGETS 06_response_handler
    EXPORT 06_response_handlerTargets
)

install(EXPORT 06_response_handlerTargets
    FILE 06_response_handlerTargets.cmake
    NAMESPACE 06_response_handler::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/06_response_handler
)
