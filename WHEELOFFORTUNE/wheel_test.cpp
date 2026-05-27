#include "Wheel.cpp"
#include "gmock/gmock.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

TEST(WheelTest, TC1) {
	vector<string> strs = {
		"BUILDLEV",
		"EATREALROBOT"
	};
	string userdata = "ERABCDFGHIJKLMNOPQSTUVWXYZ";

	Wheel* wheel = new Wheel();
	int result = wheel->getPrice(strs, userdata);
	EXPECT_EQ(6500, result);
}
TEST(WheelTest, TC2) {
	vector<string> strs = {
		"ABS","ABS","AAAAAKBA"
	};
	string userdata = "XASBKQDJHMNPTLVUCGEWFORIYZ";

	Wheel* wheel = new Wheel();
	int result = wheel->getPrice(strs, userdata);
	EXPECT_EQ(9500, result);
}
TEST(WheelTest, TC3) {
	vector<string> strs = {
		"ABC","ABCDEFG","ABCDEFGH"
	};
	string userdata = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	Wheel* wheel = new Wheel();
	int result = wheel->getPrice(strs, userdata);
	EXPECT_EQ(16000, result);
}