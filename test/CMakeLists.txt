include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(POIDS_CORE_TESTS
    "core/test_arithmetic.cpp"
    "core/test_base_quantity.cpp"
    "core/test_quantity.cpp"
)

set(KGMS_TESTS
    "kgms/test_base_constants.cpp"
    "kgms/test_dimensional_analysis.cpp"
    "kgms/test_metric_prefixes.cpp"
)

set(ANGLE_TESTS
    "angle/test_angle_system.cpp"
)

add_executable(poids_test
    ${POIDS_CORE_TESTS}
    ${KGMS_TESTS}
    ${ANGLE_TESTS}
)

set_target_properties(poids_test
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(poids_test
    poids
    GTest::gtest 
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(poids_test)
