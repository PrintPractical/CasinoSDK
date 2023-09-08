#pragma once
/**
 * @file NormalBankroll.h
 * @author Chris Buchter
 * @brief Implementation of a Normal Bankroll.
 * @version 0.1
 * @date 2023-09-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <IBankRoll.h>

namespace CasinoSDK {
namespace Player {
namespace Bankroll {
class NormalBankroll : public IBankRoll {
public:
    NormalBankroll() = default;
    virtual ~NormalBankroll() = default;

public:
    void DespositFunds(unsigned int amount) override;
    bool WithdrawFunds(unsigned int amount) override;
    unsigned long GetAvailableFunds() override;
    unsigned long GetReservedFunds() override;
    unsigned long GetTotalFunds() override;
    bool MoveReservedToAvailable(unsigned long amount) override;
    bool MoveAvailableToReserved(unsigned long amount) override;

private:
    unsigned long mAvailableFunds;
    unsigned long mReservedFunds;
};
}
}
}