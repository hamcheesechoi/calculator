#pragma once
#include <string>

using std::string;

class Movie {
public:
	static const int CHILDREN = 2;
	static const int NEW_RELEASE = 1;
	static const int REGULAR = 0;

	Movie(const string& title, int price_code) : title{ title }, priceCode{ price_code } {}

	int getPriceCode() {
		return priceCode;
	}

	void setPriceCode(int price_code)
	{
		priceCode = price_code;
	}

	string getTitle() const {
		return title;
	}

    double get_charge_for(int days_rented)
    {
        double thisAmount = 0;
        //determine amounts for rental
        switch (getPriceCode())
        {
        case Movie::REGULAR:
            thisAmount += 2;
            if (days_rented > 2)
                thisAmount += (days_rented - 2) * 1.5;
            break;
        case Movie::NEW_RELEASE:
            thisAmount += days_rented * 3;
            break;
        case Movie::CHILDREN:
            thisAmount += 1.5;
            if (days_rented > 3)
                thisAmount += (days_rented - 3) * 1.5;
            break;
        }
        return thisAmount;
    }

    int get_frequent_renter_points_for(int days_rented)
    {
        if (getPriceCode() == Movie::NEW_RELEASE && days_rented > 1) {
            return 2;
        }
        return 1;
    }

private:
	string title;
	int priceCode;
};