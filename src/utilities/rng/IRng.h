/**
 * @file IRng.h
 * @author Chris Buchter
 * @brief An interface for a RandomNumberGenerator.
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

namespace CasinoSDK {
namespace Utilities {
/**
 * @brief Interface for a Random Number Generator.
 */
class IRng {
public:
    /**
     * @brief Seed for the RNG.
     * 
     * @param seed Seed.
     */
    virtual void Seed(unsigned int seed) = 0;
    /**
     * @brief Get random integer from the RNG.
     * 
     * @param min Inclusive min to be generated.
     * @param max Inclusive max to be generated.
     * @return int The random integer.
     * @exception Throws an exception if max <= min
     */
    virtual int RandomInt(int min, int max) noexcept(false) = 0;
};
}
}