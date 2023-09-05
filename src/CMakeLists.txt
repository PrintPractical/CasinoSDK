add_library(${PROJECT_NAME} SHARED
            tools/die/NormalDie.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
                           tools/die)