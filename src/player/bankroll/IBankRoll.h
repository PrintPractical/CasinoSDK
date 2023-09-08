#pragma once
/**
 * @file IBankRoll.h
 * @author Chris Buchter
 * @brief Interface for a Player's Bankroll
 * @version 0.1
 * @date 2023-09-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

namespace CasinoSDK {
namespace Player {
namespace Bankroll {
/**
 * @brief Helper function used to call IBankRoll functions with Dollars.
 * 
 * @param amount Amount of dollars.
 * @return unsigned long The amount that should be used with IBankRoll.
 */
inline unsigned long Dollars(unsigned long amount) {return(100 * amount);}
/**
 * @brief Helper function used to call IBankRoll functions with Cents.
 * 
 * @param amount Amount of cents.
 * @return unsigned long The amount that should be used with IBankRoll.
 */
inline unsigned long Cents(unsigned long amount) {return(amount);}

/**
 * @brief Interface for a Player's Bankroll.
 */
class IBankRoll {
public:
    /**
     * @brief Used to deposit funds into the Bankroll.
     * 
     * @param amount Amount to deposit.
     */
    virtual void DespositFunds(unsigned int amount) = 0;
    /**
     * @brief Used to withdraw funds for betting etc.
     * 
     * @param amount Amount to be withdrawn.
     * @return true The requested amount was withdrawn.
     * @return false The requested amount was not available, so nothing happened.
     */
    virtual bool WithdrawFunds(unsigned int amount) = 0;
    /**
     * @brief Get the Available Funds in the Bankroll.
     * 
     * @return unsigned long The amount of available funds in the Bankroll.
     */
    virtual unsigned long GetAvailableFunds() = 0;
    /**
     * @brief Get the Reserved Funds.
     * 
     * @return unsigned long The amount of reserved funds in the Bankroll.
     */
    virtual unsigned long GetReservedFunds() = 0;
    /**
     * @brief Get the Total Funds.
     * 
     * @return unsigned long The amount of funds in the Bankroll (available + reserved).
     */
    virtual unsigned long GetTotalFunds() = 0;
    /**
     * @brief Move an amount of money from reserved to available funds.
     * 
     * @param amount The amount to be moved.
     * @return true The amount was transfered successfully.
     * @return false The amount was not available in reserved, so the transaction failed and nothing was moved.
     */
    virtual bool MoveReservedToAvailable(unsigned long amount) = 0;
    /**
     * @brief Move an amount of money from available to reserved funds.
     * 
     * @param amount The amount to be moved.
     * @return true The amount was transfered successfully.
     * @return false The amount was not available in available, so the transaction failed and nothing was moved.
     */
    virtual bool MoveAvailableToReserved(unsigned long amount) = 0;
};
}
}
}