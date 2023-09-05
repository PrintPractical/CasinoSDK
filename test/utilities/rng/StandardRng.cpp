#include <StandardRng.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace CasinoSDK::Utilities;

TEST(StandardRngTest, SeedResultsInSameResult) {
    auto rng = StandardRng();
    rng.Seed(1234);
    EXPECT_EQ(rng.RandomInt(1,100), 32);
    EXPECT_EQ(rng.RandomInt(1,100), 17);
}

TEST(StandardRngTest, BoundsTest) {
    auto rng = StandardRng();
    for(int i = 0; i < 1000; i++) {
        auto res = rng.RandomInt(1, 100);
        EXPECT_GE(res, 1);
        EXPECT_LE(res, 100);
    }
}

TEST(StandardRngTest, RandomIntMaxLTMin) {
    auto rng = StandardRng();
    EXPECT_THROW(rng.RandomInt(10, 5), std::runtime_error);
}

TEST(StandardRngTest, RandomIntMaxEQMin) {
    auto rng = StandardRng();
    EXPECT_THROW(rng.RandomInt(10, 10), std::runtime_error);
}