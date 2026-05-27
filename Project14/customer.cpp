#include <vector>
#include <string>
#include "movie.cpp"
#include "rental.cpp"

using std::vector;
using std::string;

class Customer {
private:
    string name;
    vector<Rental> rentals;

    string roundDoubleToString(double tar) {
        char buf[20] = { 0 };
        sprintf_s(buf, sizeof(buf), "%.1f", tar);
        return string{ buf };
    }

public:
    Customer(const string& name) : name{ name } {}

    void addRental(Rental arg) {
        rentals.push_back(arg);
    }

    string getName() const {
        return name;
    }

    string statement() {

        string result = get_statement_header();
        result += get_rental_line_report();
        result += get_statement_footer();

        return result;
    }
    string get_statement_footer()
    {
        string result = "";
        result += "Amount owed is " + roundDoubleToString(get_total_amount()) + "\n";
        result += "You earned " + std::to_string(get_frequent_renter_points()) + " frequent renter points";
        return result;
    }
    string get_statement_header() {
        return "Rental Record for " + getName() + "\n";
    }
    string get_rental_line_report()
    {
        string result = "";
        for (Rental each : rentals) {

            result += "\t" + each.getMovie().getTitle();
            result += "\t" + roundDoubleToString(each.get_charge()) + "\n";
        }
        return result;
    }
    int get_frequent_renter_points()
    {
        int frequentRenterPoints = 0;
        for (Rental each : rentals) {
            frequentRenterPoints+=each.getMovie().get_frequent_renter_points_for(each.getDaysRented());
        }
        return frequentRenterPoints;
    }
    double get_total_amount()
    {
        double totalAmount = 0.0;
        for (Rental each : rentals) {

            totalAmount += each.get_charge();
        }
        return totalAmount;
    }
};