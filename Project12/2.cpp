#pragma once
#define interface struct

interface Bird{
    virtual void Molt() = 0;
};

interface FlyableBird{
	virtual void Fly() = 0;
};
interface SwimableBird{
	virtual void Swim() = 0;
};

#include <string>
using namespace std;

class Eagle : public Bird, FlyableBird {
public:
    Eagle(int initial_feather_count) {
        number_of_feathers_ = initial_feather_count;
    }

    void Fly() override {
        current_location_ = "in the air";
    }

    void Molt() override {
        number_of_feathers_ -= 1;
    }

private:
    string current_location_;
    int number_of_feathers_;
};


class Penguin : public Bird, SwimableBird {
public:
	Penguin(int initial_feather_count) {
		number_of_feathers_ = initial_feather_count;
	}

	void Molt() override {
		number_of_feathers_ -= 1;
	}

	void Swim() override {
		current_location_ = "in the water";
	}

private:
	string current_location_;
	int number_of_feathers_;
};