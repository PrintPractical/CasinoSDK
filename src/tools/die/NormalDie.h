#pragma once
/**
 * @file NormalDie.h
 * @author Chris Buchter
 * @brief A normal die with completely random outcomes.
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <IDie.h>
#include <IRng.h>
#include <memory>

namespace CasinoSDK {
namespace Tools {
/**
 * @brief Implementation of a normal die. 
 */
class NormalDie : public IDie {
public:
    /**
     * @brief Construct a new Normal Die object
     */
    NormalDie();
    /**
     * @brief Destroy the Normal Die object
     */
    virtual ~NormalDie() = default;

public:
    /**
     * @brief Set the number of sides on the Die.
     * 
     * @param sides The number of desired sides.
     */
    void SetSides(unsigned int sides);
    
    /**
     * @brief Set the RNG for the die.
     * 
     * @param rng Shared pointer to the RNG object
     */
    void SetRng(std::shared_ptr<Utilities::IRng> rng);

public:
    /**
     * @see IDie::Roll()
     */
    unsigned int Roll() override;
    /**
     * @see IDie::GetSides()
     */
    unsigned int GetSides() override;

private:
    std::shared_ptr<Utilities::IRng> mRng; 
    int mSides = 6;
};
}
}