/**
 * @file IDie.h
 * @author Chris Buchter
 * @brief Interface for a Die object
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

namespace CasinoSDK {
namespace Tools {
/**
 * @brief Pure virtual interface for a Die object used in various Casino games. 
 */
class IDie {
public:
    /**
     * @brief Roll the die!
     * 
     * @return unsigned int The value that the die returns.
     */
    virtual unsigned int Roll() = 0;

    /**
     * @brief Get the number of sides for a die.
     * 
     * @return unsigned int The number of sides on a Die object.
     */
    virtual unsigned int GetSides() = 0;
};
}
}