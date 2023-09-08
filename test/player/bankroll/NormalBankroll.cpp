#include <NormalBankroll.h>
#include <gtest/gtest.h>

using namespace CasinoSDK::Player::Bankroll;

class NormalBankrollTest : public ::testing::Test {
protected:
    void SetUp() override {
        bankroll = std::make_unique<NormalBankroll>();
    }

    void TearDown() override {
        // Clean up resources
    }

    std::unique_ptr<NormalBankroll> bankroll;
};

TEST_F(NormalBankrollTest, InitialFunds0) {
    EXPECT_EQ(bankroll->GetTotalFunds(), 0);
}

TEST_F(NormalBankrollTest, Deposit100Dollars) {
    bankroll->DespositFunds(::Dollars(100));
    EXPECT_EQ(bankroll->GetTotalFunds(), 10000);
}

TEST_F(NormalBankrollTest, Deposit50Cents) {
    bankroll->DespositFunds(::Cents(50));
    EXPECT_EQ(bankroll->GetTotalFunds(), ::Cents(50));
}

TEST_F(NormalBankrollTest, WithdrawTooMuch) {
    bankroll->DespositFunds(::Dollars(100));
    EXPECT_EQ(bankroll->WithdrawFunds(::Dollars(150)), false);
}

TEST_F(NormalBankrollTest, WithdrawValidAmount) {
    bankroll->DespositFunds(::Dollars(100));
    EXPECT_EQ(bankroll->WithdrawFunds(::Dollars(50)), true);
    EXPECT_EQ(bankroll->GetTotalFunds(), ::Dollars(50));
}

TEST_F(NormalBankrollTest, Reserve50Dollars) {
    bankroll->DespositFunds(::Dollars(100));
    EXPECT_EQ(bankroll->MoveAvailableToReserved(::Dollars(50)), true);
    EXPECT_EQ(bankroll->GetTotalFunds(), ::Dollars(100));
    EXPECT_EQ(bankroll->GetAvailableFunds(), ::Dollars(50));
    EXPECT_EQ(bankroll->GetReservedFunds(), ::Dollars(50));
}

TEST_F(NormalBankrollTest, ReserveTooMuch) {
    bankroll->DespositFunds(::Dollars(100));
    EXPECT_EQ(bankroll->MoveAvailableToReserved(::Dollars(150)), false);
    EXPECT_EQ(bankroll->GetTotalFunds(), ::Dollars(100));
    EXPECT_EQ(bankroll->GetAvailableFunds(), ::Dollars(100));
    EXPECT_EQ(bankroll->GetReservedFunds(), ::Dollars(0));
}

TEST_F(NormalBankrollTest, ReserveToAvailable50Dollars) {
    bankroll->DespositFunds(::Dollars(100));
    EXPECT_EQ(bankroll->MoveAvailableToReserved(::Dollars(100)), true);
    EXPECT_EQ(bankroll->MoveReservedToAvailable(::Dollars(50)), true);
    EXPECT_EQ(bankroll->GetTotalFunds(), ::Dollars(100));
    EXPECT_EQ(bankroll->GetAvailableFunds(), ::Dollars(50));
    EXPECT_EQ(bankroll->GetReservedFunds(), ::Dollars(50));
}

TEST_F(NormalBankrollTest, ReserveToAvailableTooMuch) {
    bankroll->DespositFunds(::Dollars(100));
    EXPECT_EQ(bankroll->MoveAvailableToReserved(::Dollars(100)), true);
    EXPECT_EQ(bankroll->MoveReservedToAvailable(::Dollars(150)), false);
    EXPECT_EQ(bankroll->GetTotalFunds(), ::Dollars(100));
    EXPECT_EQ(bankroll->GetAvailableFunds(), ::Dollars(0));
    EXPECT_EQ(bankroll->GetReservedFunds(), ::Dollars(100));
}