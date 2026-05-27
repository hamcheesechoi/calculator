#include <vector>
#include "gmock/gmock.h"
using std::vector;

class EvenOdd {
public:
	vector<char> run(vector<int> nums) {
		vector<char> ret;
		int cnt_o = 0;
		for (int num : nums) {
			if (num % 2 == 0) // odd
			{
				ret.push_back('O');
				cnt_o++;
			}
			else {
				ret.push_back('X');
			}
		}

		if (cnt_o == 0 || cnt_o == 4) {
			return {};
		}

		return ret;
	}
};
class EvenOddFixture : public testing::Test {
protected:
	EvenOdd* eo;

	void runTest(vector<char> expect, vector<int> nums) {
		vector<char> ret = eo->run(nums);
		EXPECT_EQ(expect, ret);
	}

	void SetUp() override {
		eo = new EvenOdd();
	}

	void TearDown() override {
		delete eo;
	}
};
TEST(TEST_EvenOdd, TC1) {
	EvenOdd* eo = new EvenOdd();
	vector<int> nums = { 2,2,2,2 };
	vector<char> expect = {};
	vector<char> ret = eo->run(nums);
	EXPECT_EQ(expect, ret);
}

TEST(TEST_EvenOdd, TC2) {
	EvenOdd* eo = new EvenOdd();
	vector<int> nums = { 2,2,2,3 };
	vector<char> expect = {'O','O','O','X'};
	vector<char> ret = eo->run(nums);
	EXPECT_EQ(expect, ret);
}

TEST_F(EvenOddFixture, TC3) {
	runTest({ 'O','O','X','X' }, { 2,2,3,3 });
}
int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}