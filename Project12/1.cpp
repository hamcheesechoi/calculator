#include <exception>
#include <string>

using namespace std;

class Car : public Vehicle {
public:
    void ChangeGear(Gear gear) override {
        if (Gear::R == gear && GetGear() == Gear::D) {
            //string exception_msg = string("Can't change to REVERSE gear when ") + GetGearName(gear) + string(" gear is engaged!");
            //throw exception(exception_msg.c_str());

			this->gear_ = Gear::P;
			this->gear_ = Gear::R;
        }
    }
};


class Plane : public Vehicle {

    // A plane can reverse engine gear while moving forward, no problem here
};


enum class Gear {
	P, //Parking
	R, //Reverse
	N, //Neutral
	D, //Drive
};

class Vehicle {
public:
	Gear GetGear() {
		return gear_;
	}

	virtual void ChangeGear(Gear gear) {
		gear_ = gear;
	}

	std::string GetGearName(Gear gear) {
		if (gear == Gear::P) return "Parking";
		if (gear == Gear::R) return "Reverse";
		if (gear == Gear::N) return "Neutral";
		if (gear == Gear::D) return "Drive";
	}

	Gear gear_;
private:
};