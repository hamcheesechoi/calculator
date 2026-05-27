#include "gmock/gmock.h"
#include "Cal.cpp"
/*
TEST(대분류, 테스트 함수명){
}
*/
TEST(CalTest, TC1) {
	cal c;
	int result = c.getSum(1, 2);
	int expect = 3;
	EXPECT_EQ(expect, result);
}
TEST(CalTest, TC2) {
	cal c;
	int result = c.getSum(1, 2);
	int expect = 4;
	EXPECT_EQ(expect, result);
}
TEST(CalTest, abssum_all_positive) {
	cal c;
	std::vector<int> v = { 1,2,3,4 };

	std::vector<int> res = c.get_absolute_sum(v);

	std::vector<int> expect = { 1,2,3,4 };
	EXPECT_EQ(expect, res);
}
TEST(CalTest, abssum_all_negative) {
	cal c;
	std::vector<int> v = { -1,-2,-3,-4 };

	std::vector<int> res = c.get_absolute_sum(v);

	std::vector<int> expect = { 1,2,3,4 };
	EXPECT_EQ(expect, res);
}
TEST(CalTest, abssum_all_zero) {
	cal c;
	std::vector<int> v = { 0,0,0,0 };

	std::vector<int> res = c.get_absolute_sum(v);

	std::vector<int> expect = { 0,0,0,0 };
	EXPECT_EQ(expect, res);
}
TEST(CalTest, abssum_mix) {
	cal c;
	std::vector<int> v = { 1,2,-3,-4 };

	std::vector<int> res = c.get_absolute_sum(v);

	std::vector<int> expect = { 1,2,3,4 };
	EXPECT_EQ(expect, res);
}