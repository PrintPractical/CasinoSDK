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
#include <StandardRng.h>
#include <cstdlib>

using namespace CasinoSDK::Tools;

NormalDie::NormalDie() {
    mRng = std::make_shared<Utilities::StandardRng>();
}

void NormalDie::SetSides(unsigned int sides) {
    mSides = sides;
}

void NormalDie::SetRng(std::shared_ptr<Utilities::IRng> rng) {
    mRng = rng;
}

unsigned int NormalDie::Roll() {
    return(mRng->RandomInt(1, mSides));
}

unsigned int NormalDie::GetSides() {
    return(mSides);
}