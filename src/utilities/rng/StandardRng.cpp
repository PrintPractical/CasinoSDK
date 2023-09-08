/**
 * @file StandardRng.cpp
 * @author Chris Buchter
 * @see StandardRng.h
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <StandardRng.h>
#include <cstdlib>
#include <stdexcept>


using namespace CasinoSDK::Utilities;

void StandardRng::Seed(unsigned int seed) {
    std::srand(seed);
}

int StandardRng::RandomInt(int min, int max) noexcept(false) {
    if(max <= min) {
        throw std::runtime_error("random number fault: requested max <= min");
    }
    return((std::rand() % (max-min+1)) + min);
}