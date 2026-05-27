#include <iostream>
#include <string>
#include <vector>
#include "Wheel.cpp"
#include "gmock/gmock.h"
using namespace std;
using namespace testing;

int main()
{	
#ifdef _DEBUG
	InitGoogleMock();
	return RUN_ALL_TESTS();
#else
	vector<string> strs;
	string userdata = "";
	int n = 0;

	freopen_s(new FILE*, "input1.txt", "r", stdin);
	cin >> n;

	//입력
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	cin >> userdata;

	
	Wheel* wheel = new Wheel();
	int sum = wheel->getPrice(strs, userdata);
	cout << "$" << sum << endl;

	return 0;
#endif
}