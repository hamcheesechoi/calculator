// github: UTF-8
// VS: EUC-KR-cp949
// 한글로 무언가 작성 시 인코딩 문제로 인해 글자가 깨질 수 있습니다. 이 점 유의하시기 바랍니다.

class Cal {
private:
	int result;
public:
	void getsum(int a, int b) {
		result = a + b;
	}
	void getsum(int a, int b) {
		result = a - b;
	}
	int getMul(int a, int b) {
		return a * b;
	}
	int getresult() {
		return result;
	}
};

int main() {

}