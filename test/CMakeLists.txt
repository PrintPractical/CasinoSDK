enable_testing()

add_executable(${PROJECT_NAME}_tests 
               tools/die/NormalDie.cpp
               utilities/rng/StandardRng.cpp
               player/bankroll/NormalBankroll.cpp)

target_link_libraries(${PROJECT_NAME}_tests 
                      ${PROJECT_NAME}
                      GTest::gtest_main
                      GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)