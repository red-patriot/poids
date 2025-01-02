include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(POIDS_CORE_TESTS
    "core/test_arithmetic.cpp"
    "core/test_base_quantity.cpp"
    "core/test_complex_scalar_support.cpp"
    "core/test_quantity.cpp"
    "core/test_quantity_reference.cpp"
    "core/test_traits.cpp"
)

set(KGMS_TESTS
    "kgms/test_base_constants.cpp"
    "kgms/test_dimensional_analysis.cpp"
    "kgms/test_metric_prefixes.cpp"
)

set(SI_TESTS
    "si/test_constants.cpp"
    "si/test_derived_units.cpp"
    "si/test_dimensional_analysis.cpp"
    "si/test_si_prefix.cpp"
)

add_executable(poids_test
    ${POIDS_CORE_TESTS}
    ${KGMS_TESTS}
    ${SI_TESTS}
)

set_target_properties(poids_test
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(poids_test
        PRIVATE
        -Wall
        -Wextra
        -Werror
    )
endif()

target_link_libraries(poids_test
    poids
    GTest::gtest 
    GTest::gtest_main
)

add_subdirectory("eigen_support")

include(GoogleTest)
gtest_discover_tests(poids_test)
