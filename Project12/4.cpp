#include <iostream>
using namespace std;

int main() {

	const double cel_temp = 24; // 섭씨 
	const double faren_temp = (cel_temp * 9 / 5) + 32; // 화씨로 변환
	cout << "섭씨 온도를 화씨로 변환: " << faren_temp << endl;
	const double meter = 10.0; // 길이(미터)
	double area = meter * meter; // 면적 계산 
	cout << "정사각형 면적: " << area << endl;

	return 0;
}