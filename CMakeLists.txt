cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(ENV{TRAVIS_BUILD_NUMBER} 1)
endif()

project(codecov VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(matrix matrix.h main.cpp)
add_executable(tests matrix.h test_main.cpp)

set_target_properties(matrix tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wall;-Wpedantic;-Wextra"
)

set_target_properties(tests PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
    COMPILE_OPTIONS "--coverage;-O0"
#    COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
    LINK_FLAGS "-lgcov --coverage"
)

target_link_libraries(matrix --coverage)

target_link_libraries(tests
    ${Boost_LIBRARIES}
)


install(TARGETS matrix RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT "HankHenshaw at github.com")

include(CPack)

enable_testing()

target_link_libraries(tests --coverage)
add_test(tests tests)