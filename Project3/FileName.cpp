#include <iostream>

struct Marin_struct {
	int hp = 100;

	void run() {
		std::cout << "ms";
	}
};

// class 는 default private
class Marin_class {
	int hp = 100;
public:
	void run() {
		std::cout << "mc";
	}
};

class Zergling_class {
	int hp = 80;
	int mana = 200;

public:
	void attack() {
		hp += 1;
		mana -= 10;
	}

	void move() {
		hp -= 10;
		mana += 5;
	}

	void status() {
		std::cout << "hp: " << this->hp << ", mana : " << this->mana << "\n";
	}
};

class Calculator {
private:

	int result;
public:

	void plus(int a, int b) {
		result = a + b;
	}
	void minus(int a, int b) {
		result = a - b;
	}
	void device(int a, int b) {
		if (b == 0) {
			std::cout << "ERROR : secound paramter shouldn't be zero." << "\n";
			return;
		}
		result = a / b;
	}
	void multiple(int a, int b) {
		result = a * b;
	}
	void print_result() {
		std::cout << result << "\n";
	}
};

class Gainmachine {
private:
	int totalcoin;

public:
	void inputcoin(int amount) {
		if (amount > 5 || amount < 1) {
			std::cout << "ERR" << "\n";
			return;
		}
		totalcoin += amount;

		if (totalcoin > 10) {
			totalcoin = 10;
		}
	}

	void playgame() {
		if (totalcoin < 1) {
			std::cout << "not enough money to play game" << "\n";
			return;
		}
		totalcoin -= 1;
	}

	void status() {
		std::cout << "coins left : " << totalcoin << "\n";
	}
};
int main() {
	/*Marin_struct* ms = new Marin_struct();
	Marin_class* mc = new Marin_class();

	ms->run();
	mc->run();*/

	//Zergling_class* zc = new Zergling_class();
	//zc->status();
	//zc->attack();
	//zc->status();
	//zc->move();
	//zc->status();

	Calculator* calc = new Calculator();
	calc->plus(1, 3);
	calc->print_result();
}