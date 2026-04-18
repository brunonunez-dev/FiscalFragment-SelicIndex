#include <gtest/gtest.h>
#include <iostream>

// Teste de fumaça (Smoke Test)
TEST(GlobalCheck, ItWorks) {
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    std::cout << "Running main tests!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}