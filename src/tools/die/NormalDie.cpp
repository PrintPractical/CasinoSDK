/**
 * @file NormalDie.cpp
 * @author Chris Buchter
 * @see NormalDie.h
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <NormalDie.h>
#include <cstdlib>

using namespace CasinoSDK::Tools;

void NormalDie::SetSides(unsigned int sides) {
    mSides = sides;
}

unsigned int NormalDie::Roll() {
    return((std::rand() % mSides) + 1);
}

unsigned int NormalDie::GetSides() {
    return(mSides);
}