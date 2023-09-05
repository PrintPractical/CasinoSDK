#include <NormalDie.h>
#include <gtest/gtest.h>
#include <map>

using namespace CasinoSDK::Tools;

TEST(NormalDieTest, DefaultsTo6Sides) {
    auto die = NormalDie();
    EXPECT_EQ(die.GetSides(), 6);
}

TEST(NormalDieTest, SetTo20Sides) {
    auto die = NormalDie();
    die.SetSides(20);
    EXPECT_EQ(die.GetSides(), 20);
}

TEST(NormalDieTest, Roll6Sided50Times) {
    auto die = NormalDie();
    die.SetSides(6);
    for(int i = 0; i < 50; i++) {
        auto res = die.Roll();
        EXPECT_LE(res, 6);
        EXPECT_GE(res, 1);
    }
}

TEST(NormalDieTest, DistributionOver100Rolls) {
    std::map<unsigned int, unsigned int> res;
    auto die = NormalDie();
    die.SetSides(6);

    for(int i = 1; i <= 6; i++) {
        res[i] = 0;
    }

    for(int i = 0; i < 100; i++) {
        res[die.Roll()] += 1;
    }

    for(int i = 1; i <= 6; i++) {
        EXPECT_GE(res[i], 10);
    }
}