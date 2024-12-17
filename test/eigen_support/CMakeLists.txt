find_package(Eigen3)

if (${Eigen3_FOUND})
    add_executable(poids_test_eigen_support
        "test_vector_support.cpp"
    )

    set_target_properties(poids_test_eigen_support
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(poids_test_eigen_support
            PRIVATE
            -Wall
            -Wextra
            -Werror
        )
    endif()

    target_link_libraries(poids_test_eigen_support
        poids
        Eigen3::Eigen
        GTest::gtest 
        GTest::gtest_main
    )
else()
    MESSAGE(WARNING "EIGEN3 was not found, you will not be able to use EIGEN support")
endif()

