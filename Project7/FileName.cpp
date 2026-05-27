#include "gmock/gmock.h"
#include <string>

class Cal {
public:
	int getSum(int a, int b) {
		return a + b;
	}
};

class CalGlobalEnv : public testing::Environment {
public:
	void SetUp() override {
		std::cout << "global setup\n";
	}
	void TearDown() override {
		std::cout << "global teardown\n";
	}
};

class CalFixture : public testing::Test {
protected:
	Cal* cal;
	void runTest(int expect, int a, int b) {
		int result = cal->getSum(a, b);
		EXPECT_EQ(expect, result);
	}
	
	void SetUp() override {
		cal = new Cal();
	}
	void TearDown() override {
		delete cal;
	}
};

TEST_F(CalFixture, TC1) {
	runTest(3, 1, 2);
	runTest(5, 3, 2);
	runTest(6, 4, 2);

}

TEST(CalTest, TC2) {
	Cal* c = new Cal();
	int result = c->getSum(2, 2);
	EXPECT_EQ(4, result);
}

int main() {
	testing::InitGoogleMock();
	testing::AddGlobalTestEnvironment(new CalGlobalEnv);
	testing::GTEST_FLAG(filter) = "*.TC1*";
	// * all string
	// : or
	// - 제외
	
	return RUN_ALL_TESTS();
}