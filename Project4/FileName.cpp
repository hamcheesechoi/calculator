#include <iostream>
class Robot {
public:
	int hp;
	void move() { std::cout << "move\n"; }
	void stop() {}
};
class SpeedRobot : public Robot {
public:

	int moodelID;

	void move() {
		std::cout << "speed move\n";
	}

	void move(int step) {
		std::cout << step << " move\n";
	}

	void run() {

	}

	void walk() {

	}
};

class PowerRobot : public Robot {
public:
	int mana;

	void attack() {

	}

	void jump() {

	}

};

class SmartRobot : public Robot {
public:
	int IQ;

	void fly() {

	}

	void sitDown() {

	}

	void standUp() {

	}
};

class Phone {
public:
	virtual void call() {
		std::cout << "calling...\n";
	}

};
class SmartPhone : public Phone {
public:
	void call() override {
		std::cout << "smart calling...\n";
	}
};

class FlipPhone : public Phone {
public:
	void call() override {
		std::cout << "Flipcalling..\n";
	}
};
class FoldPhone : public Phone {
public:
	void call() override {
		std::cout << "Foldcalling..\n";
	}
};
class Tabelet : public Phone {
public:
	void call() override {
		std::cout << "Tabelettt..\n";
	}
};
class User {
private:
	Phone* smartphone;
public:
	void setPhone(Phone* sp) {
		this->smartphone = sp;
	}
	void useCalling() {
		this->smartphone->call();
	}
};

class PhoneFactory {
public:
	//phone creator
	Phone* create(std::string type) {
		// create type phone
		if (type == "smart") return new SmartPhone();
		if (type == "flip") return new FlipPhone();
		if (type == "fold") return new FoldPhone();
		if (type == "tabelet") return new Tabelet();
	}
};
int main() {
	//User* usr = new User();
	//usr->setPhone(new SmartPhone());
	//usr->useCalling();
	//usr->setPhone(new FlipPhone());
	//usr->useCalling();
	//usr->setPhone(new FoldPhone());
	//usr->useCalling();

	User* usr = new User();
	PhoneFactory* pf = new PhoneFactory();
	usr->setPhone(pf->create("smart"));
	usr->useCalling();
	usr->setPhone(pf->create("tabelet"));
	usr->useCalling();
}