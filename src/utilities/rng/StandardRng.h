#pragma once
/**
 * @file StandardRng.h
 * @author Chris Buchter
 * @brief Implementation of the interface using std rand.
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <IRng.h>

namespace CasinoSDK {
namespace Utilities {
/**
 * @brief Implementation of a Standard RNG using std rand.
 */
class StandardRng : public IRng {
public:
    /**
     * @brief Construct a new Standard Rng object.
     */
    StandardRng() = default;
    /**
     * @brief Destroy the Standard Rng object.
     */
    virtual ~StandardRng() = default;

public:
    /**
     * @see IRng::Seed()
     */
    void Seed(unsigned int seed) override;
    /**
     * @see IRng::RandomInt()
     */
    int RandomInt(int min, int max) noexcept(false) override;
};
}
}