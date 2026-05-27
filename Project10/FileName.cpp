#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "gmock/gmock.h"
using namespace testing;

class sum_checker {

	struct sum_checker_condition {
		int plus_cnt = 0;
		int equal_cnt = 0;
		int plus_position = 0;
		int equal_position = 0;
	};

public:
	string check(const string& str) {
		sum_checker_condition cond;

		//+와 = 개수 확인
		if (!plus_equal_nondigit_checker(str, cond))
			return "ERROR";

		if (!validate_format(cond))
			return "ERROR";

		if (!can_be_calculated(cond, str.length())) 
			return "ERROR";

		return validate_answer(str, cond);

	}

private:

	bool plus_equal_nondigit_checker(const std::string& str, sum_checker_condition& cond)
	{
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '+') {
				cond.plus_cnt++;
				cond.plus_position = i;
			}
			else if (str[i] == '=') {
				cond.equal_cnt++;
				cond.equal_position = i;
			}
			else if (!(str[i] >= '0' && str[i] <= '9')) {
				return false;
			}
		}
		return true;
	}
	
	bool validate_format(sum_checker_condition& cond) {
		return cond.plus_cnt == 1 && cond.equal_cnt == 1 && cond.plus_position < cond.equal_position - 1;
	}

	bool can_be_calculated(sum_checker_condition& cond, const int& str_len) {
		return cond.plus_position >= 1 && cond.equal_position >= 3 && cond.equal_position < str_len - 1;
	}

	const std::string validate_answer(const std::string& str, sum_checker_condition& cond)
	{
		string str_first_term = str.substr(0, cond.plus_position);
		string str_second_term = str.substr(cond.plus_position + 1, cond.equal_position - cond.plus_position - 1);
		string str_answer = str.substr(cond.equal_position + 1);


		int first_term = stoi(str_first_term);
		int second_term = stoi(str_second_term);
		int answer = stoi(str_answer);

		if (first_term + second_term == answer) {
			return "PASS";
		}
		else return "FAIL";
	}

};

TEST(sumchecker_test, TC1) {
	string str = "25+61=86"; //PASS

	sum_checker* sc = new sum_checker();
	string res = sc->check(str);
	string expect = "PASS";
	 
	EXPECT_EQ(expect, res);
}

TEST(sumchecker_test, TC2) {
	string str = "12345+12345=24690"; //PASS

	sum_checker* sc = new sum_checker();
	string res = sc->check(str);
	string expect = "PASS";

	EXPECT_EQ(expect, res);
}
TEST(sumchecker_test, TC3) {
	string str = "12345+=12345"; // ERROR

	sum_checker* sc = new sum_checker();
	string res = sc->check(str);
	string expect = "ERROR";

	EXPECT_EQ(expect, res);
}
TEST(sumchecker_test, TC4) {
	string str = "5++5=10"; //ERROR

	sum_checker* sc = new sum_checker();
	string res = sc->check(str);
	string expect = "ERROR";

	EXPECT_EQ(expect, res);
}
TEST(sumchecker_test, TC5) {
	string str = "10000+1=10002"; //FAIL

	sum_checker* sc = new sum_checker();
	string res = sc->check(str);
	string expect = "FAIL";

	EXPECT_EQ(expect, res);
}
int main()
{
	InitGoogleTest();
	return RUN_ALL_TESTS();
	return 0;
}