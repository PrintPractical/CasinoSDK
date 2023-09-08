#include <NormalDie.h>
#include <IRng.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <map>

using namespace CasinoSDK::Tools;

class MockRng : public CasinoSDK::Utilities::IRng {
public:
    MOCK_METHOD(void, Seed, (unsigned int seed), (override));
    MOCK_METHOD(int, RandomInt, (int min, int max), (noexcept, override));
};

class NormalDieTest : public ::testing::Test {
protected:
    void SetUp() override {
        die = std::make_unique<NormalDie>();
        mockRng = std::make_shared<MockRng>();
    }

    void TearDown() override {
        // Clean up resources
    }

    std::unique_ptr<NormalDie> die;
    std::shared_ptr<MockRng>   mockRng;
};

TEST_F(NormalDieTest, DefaultsTo6Sides) {
    EXPECT_EQ(die->GetSides(), 6);
}

TEST_F(NormalDieTest, SetTo20Sides) {
    die->SetSides(20);
    EXPECT_EQ(die->GetSides(), 20);
}

TEST_F(NormalDieTest, Roll6Sided50Times) {
    for(int i = 0; i < 50; i++) {
        auto res = die->Roll();
        EXPECT_LE(res, 6);
        EXPECT_GE(res, 1);
    }
}

TEST_F(NormalDieTest, DistributionOver100Rolls) {
    std::map<unsigned int, unsigned int> res;

    for(int i = 1; i <= 6; i++) {
        res[i] = 0;
    }

    for(int i = 0; i < 100; i++) {
        res[die->Roll()] += 1;
    }

    for(int i = 1; i <= 6; i++) {
        EXPECT_GE(res[i], 10);
    }
}

TEST_F(NormalDieTest, MockedRngResult6) {
    die->SetRng(mockRng);
    EXPECT_CALL(*mockRng, RandomInt(1, 6)).Times(::testing::AtLeast(1)).WillOnce(::testing::Return(6));
    EXPECT_EQ(die->Roll(), 6);
}