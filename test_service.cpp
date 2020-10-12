#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Service.h"

class MockDatabase : public Database {
public:
    MOCK_METHOD(std::vector<Transaction>, getTransactions, (), (const, override));
};

using ::testing::Return;
using ::testing::SizeIs;
TEST(server, getPositiveTransactions_filters_the_transactions_as_expected){

    MockDatabase mockDatabase;
    EXPECT_CALL(mockDatabase, getTransactions()).WillOnce(Return(std::vector<Transaction>({
        Transaction{66.6},
        Transaction{42.0},
        Transaction{-69.0},
        Transaction{-127.1},
        Transaction{256.0}
    })));
    Server server(&mockDatabase);
    ASSERT_THAT(server.getPositiveTransactions(), SizeIs(3));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
