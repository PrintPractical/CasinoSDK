#include <StandardRng.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace CasinoSDK::Utilities;

class StandardRngTest : public ::testing::Test {
protected:
    void SetUp() override {
        rng = std::make_unique<StandardRng>();
    }

    void TearDown() override {
        // Clean up resources
    }

    std::unique_ptr<StandardRng> rng;
};

TEST_F(StandardRngTest, BoundsTest) {
    for(int i = 0; i < 1000; i++) {
        auto res = rng->RandomInt(1, 100);
        EXPECT_GE(res, 1);
        EXPECT_LE(res, 100);
    }
}

TEST_F(StandardRngTest, DistributionTest) {
    std::map<unsigned int, unsigned int> res;

    for(int i = 1; i <= 100; i++) {
        res[i] = 0;
    }

    for(int i = 0; i < 100000; i++) {
        res[rng->RandomInt(1,100)] += 1;
    }

    for(int i = 1; i <= 100; i++) {
        EXPECT_GE(res[i], 50);
    }
}

TEST_F(StandardRngTest, RandomIntMaxLTMin) {
    EXPECT_THROW(rng->RandomInt(10, 5), std::runtime_error);
}

TEST_F(StandardRngTest, RandomIntMaxEQMin) {
    EXPECT_THROW(rng->RandomInt(10, 10), std::runtime_error);
}