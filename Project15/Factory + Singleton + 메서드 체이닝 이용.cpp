#include <iostream>
#include <string>

using std::string;

class Phone {
public:
    virtual void call() {
        std::cout << "Call..\n";
    }
};

class SmartPhone : public Phone {
public:
    void call() override {
        std::cout << "Smart Call..\n";
    }
};

class BrickPhone : public Phone {
public:
    void call() override {
        std::cout << "Brick Call..\n";
    }
};

//Simple Factory Pattern
class Factory {
public:
    static Factory& get_instance() {
        static Factory instance;
        return instance;
    }

    Phone* makePhone(string name) {
        if (name == "smart") return new SmartPhone();
        if (name == "brick") return new BrickPhone();
        return nullptr;
    }

};

class Factory {
public:
    virtual Phone* makePhone() = 0;
private:
    Factory() {};
    Factory& operator=(Factory&&) = delete;	// 이동 대입
    Factory& operator=(const Factory&) = delete;// 복사 대입
    Factory(Factory&&) = delete;				// 이동 생성자
    Factory(const Factory&) = delete;			// 복사 생성자
};

class SmartPhone_Factory : public Factory {
public:
    Phone* makePhone() override {
        return new SmartPhone();
    }
};

class Brick_Factory : public Factory {
public:
    Phone* makePhone() override {
        return new BrickPhone();
    }
};

int main() {
    Phone* phone = Factory::get_instance().makePhone("smart");

}