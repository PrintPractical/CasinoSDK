add_library(${PROJECT_NAME} SHARED
            tools/die/NormalDie.cpp
            utilities/rng/StandardRng.cpp
            player/bankroll/NormalBankroll.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
                           tools/die
                           utilities/rng
                           player/bankroll)