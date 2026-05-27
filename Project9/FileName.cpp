#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::string;
using std::vector;
#ifdef _DEBUG
#include "gmock/gmock.h"
using namespace testing;
#endif
class SplitAndSum {
public:
	int run(string text)
	{	
		if (text.empty())
		{
			return 0;
		}
		vector<string> values = split_string_to_vector(text);	
		
		// split
		// sum 
		return get_sum_by_stringvector(values);
	}
private:

	vector<string> split_string_to_vector(std::string& text)
	{
		text += "-";
		vector<string> values;
		int a = 0, b = 0;
		while (1) {
			b = text.find("-", a);
			if (b == -1) break;
			string temp = text.substr(a, b - a);
			values.push_back(temp);
			a = b + 1;
		}
		return values;
	}
	int get_sum_by_stringvector(const vector<string>& values)
	{
		int result = 0;
		for (const string& str : values) {
			int temp = stoi(str);
			result += temp;
		}
		return result;
	}
};
TEST(SplitAndSumTest, TC1) {
	SplitAndSum* splitandsum = new SplitAndSum();
	int result = splitandsum->run("100-10-20");
	EXPECT_EQ(130, result);
	delete splitandsum;
}

TEST(SplitAndSumTest, TC2) {
	SplitAndSum* splitandsum = new SplitAndSum();
	int result = splitandsum->run("100-10-25");
	EXPECT_EQ(135, result);
	delete splitandsum;
}

TEST(SplitAndSumTest, TC3) {
	SplitAndSum* splitandsum = new SplitAndSum();
	int result = splitandsum->run("110-10-25");
	EXPECT_EQ(145, result);
	delete splitandsum;
}

int main()
{
#ifdef _DEBUG
	InitGoogleMock();
	return RUN_ALL_TESTS();
#else
	SplitAndSum* splitandsum = new SplitAndSum();
	cout << splitandsum->run("100-10-20");
#endif
	return 0;
}