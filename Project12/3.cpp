#define interface struct

interface Car{
    virtual void Accelerate() = 0;
    virtual void Accelerate_reverse() = 0; // <- ISP 위반!!!!!!!!
};

class RacingCar : public Car {
public:
    RacingCar(int max_fuel) {
        max_fuel_ = max_fuel;
        remaining_fuel_ = max_fuel;
    }

    void Accelerate() {
        power_++;
        remaining_fuel_--;
    }

    // 레이싱카는 후진이 안된다?! <= LSP위반!!!!!!

private:
    int max_fuel_;
    int remaining_fuel_;
    int power_;
};

class Cedan : public Car {

    void Accelerate() {
        // 후진 코드가 있다고 가정
    }
    void Accelerate_reverse() {
        // 후진 코드가 있다고 가정
    }
};


class Pilot {
public:
    Pilot() {
        vehicle_ = nullptr;
    }

    void setCar(Car* car) {
        vehicle_ = car;
    }

    void IncreaseSpeed() {
        vehicle_->Accelerate();
    }

private:
    Car* vehicle_;
};