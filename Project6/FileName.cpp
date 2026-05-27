#include <iostream>
#include <memory>

std::unique_ptr<int> plus(std::unique_ptr<int> up) {
	*up += 10;
	return up;
}

void show(std::unique_ptr<int>& up) {
	std::cout << "s" << "\n";
}

void getResource(std::unique_ptr<int> up) {
	std::cout << *up << "\n";
}

int main() {
	std::unique_ptr<int> up = std::make_unique<int>(15);
	std::cout << *up;
	std::unique_ptr<int>& sample = up;
	int* sample_pointer = up.get();
	std::cout << "\n" << *sample << "\n";
	std::cout << "\n" << *sample_pointer << "\n";
	//std::unique_ptr<int> sample = up;


	up = plus(std::move(up));
	show(up);
	getResource(std::move(up)); 

	std::cout << *up << "\n";// error!!

	int a = 5;
	int& b = a;
	b += 1;
	std::cout << "\n" << a << "\n";
}