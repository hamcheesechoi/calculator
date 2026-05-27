#include <iostream>
#define Logger singleton::get_instance();

class singleton {

public:
	static singleton& get_instance() {
		static singleton instance;
		return instance;
	}
	void func() {
		a += 10;
		std::cout << a << "\n";
	}
private:
	int a = 10;
	singleton() {};
	//객체 복사 방지 
	singleton& operator=(singleton &&) = delete;	// 이동 대입
	singleton& operator=(const singleton&) = delete;// 복사 대입
	singleton(singleton&&) = delete;				// 이동 생성자
	singleton(const singleton&) = delete;			// 복사 생성자
};


int main() {
	// 객체 복사됨
	singleton& s = singleton::get_instance();
}