#include "gmock/gmock.h"
#include "customer.cpp"

using std::cout;

using namespace testing;
const string NAME = "NAME";
const string TITLE = "TITLE";
class customer_fixture : public Test {
public:
    Customer cus = Customer(NAME);

    Rental create_rental_for(int price_code, int days_rented) {
        Movie movie{ TITLE, price_code };
        Rental rental{ movie, days_rented };
        return rental;
    }
};

TEST_F(customer_fixture, SampleTest) {
    
    cus.addRental(create_rental_for(Movie::REGULAR, 2));
    cus.addRental(create_rental_for(Movie::REGULAR, 3 ));
    cus.addRental(create_rental_for(Movie::NEW_RELEASE, 1 ));
    cus.addRental(create_rental_for(Movie::NEW_RELEASE, 2 ));
    cus.addRental(create_rental_for(Movie::CHILDREN, 3 ));
    cus.addRental(create_rental_for(Movie::CHILDREN, 4 ));

    string expected = "" +
        string{ "Rental Record for NAME\n" } +
        string{ "\tTITLE\t2.0\n" } +
        string{ "\tTITLE\t3.5\n" } +
        string{ "\tTITLE\t3.0\n" } +
        string{ "\tTITLE\t6.0\n" } +
        string{ "\tTITLE\t1.5\n" } +
        string{ "\tTITLE\t3.0\n" } +
        string{ "Amount owed is 19.0\n" } +
        string{ "You earned 7 frequent renter points" };

    EXPECT_EQ(expected, cus.statement());
}
TEST_F(customer_fixture, SampleTest1) {

    cus.addRental(create_rental_for(Movie::REGULAR, 2 ));
    string expected = "Rental Record for NAME\n\tTITLE\t2.0\nAmount owed is 2.0\nYou earned 1 frequent renter points";

    EXPECT_EQ(expected, cus.statement());
}
TEST_F(customer_fixture, SampleTest2) {
    cus.addRental(create_rental_for(Movie::NEW_RELEASE, 2 ));
    string expected = "Rental Record for NAME\n\tTITLE\t6.0\nAmount owed is 6.0\nYou earned 2 frequent renter points";

    EXPECT_EQ(expected, cus.statement());
}
TEST_F(customer_fixture, SampleTest3) {

    cus.addRental(create_rental_for(Movie::CHILDREN, 2 ));
    string expected = "Rental Record for NAME\n\tTITLE\t1.5\nAmount owed is 1.5\nYou earned 1 frequent renter points";

    EXPECT_EQ(expected, cus.statement());
}

TEST_F(customer_fixture, SampleTest4) {

    cus.addRental(create_rental_for(Movie::REGULAR, 5 ));
    string expected = "Rental Record for NAME\n\tTITLE\t6.5\nAmount owed is 6.5\nYou earned 1 frequent renter points";

    EXPECT_EQ(expected, cus.statement());
}
TEST_F(customer_fixture, SampleTest5) {

    cus.addRental(create_rental_for(Movie::NEW_RELEASE, 5 ));
    string expected = "Rental Record for NAME\n\tTITLE\t15.0\nAmount owed is 15.0\nYou earned 2 frequent renter points";

    EXPECT_EQ(expected, cus.statement());
}
TEST_F(customer_fixture, SampleTest6) {

    cus.addRental(create_rental_for(Movie::CHILDREN, 5 ));
    string expected = "Rental Record for NAME\n\tTITLE\t4.5\nAmount owed is 4.5\nYou earned 1 frequent renter points";

    EXPECT_EQ(expected, cus.statement());
}