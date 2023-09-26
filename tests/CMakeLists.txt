enable_testing()
find_package(GTest CONFIG REQUIRED)

add_executable(test_poids 
               "test-dimension.cpp"
               "test-generic-dimension.cpp"
               "test-metric.cpp"
               "test-rational.cpp"
               "test-unit.cpp"
)

target_include_directories(test_poids 
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/poids
)

target_link_libraries(test_poids 
                      PRIVATE 
                      GTest::gtest 
                      GTest::gtest_main)

add_test(test_poids test_poids)
