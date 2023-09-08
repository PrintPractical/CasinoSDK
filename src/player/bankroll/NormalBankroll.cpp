/**
 * @file NormalBankroll.cpp
 * @author Chris Buchter
 * @see NormalBankroll.h
 * @version 0.1
 * @date 2023-09-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <NormalBankroll.h>

using namespace CasinoSDK::Player::Bankroll;

void NormalBankroll::DespositFunds(unsigned int amount) {
    mAvailableFunds += amount;
}

bool NormalBankroll::WithdrawFunds(unsigned int amount) {
    if(amount > mAvailableFunds) {
        return(false);
    }
    mAvailableFunds -= amount;
    return(true);
}

unsigned long NormalBankroll::GetAvailableFunds() {
    return(mAvailableFunds);
}

unsigned long NormalBankroll::GetReservedFunds() {
    return(mReservedFunds);
}

unsigned long NormalBankroll::GetTotalFunds() {
    return(mAvailableFunds + mReservedFunds);
}

bool NormalBankroll::MoveReservedToAvailable(unsigned long amount) {
    if(amount > mReservedFunds) {
        return(false);
    }
    mReservedFunds  -= amount;
    mAvailableFunds += amount;
    return(true);
}

bool NormalBankroll::MoveAvailableToReserved(unsigned long amount) {
    if(amount > mAvailableFunds) {
        return(false);
    }
    mAvailableFunds -= amount;
    mReservedFunds  += amount;
    return(true);
}
