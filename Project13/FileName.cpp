#include <iostream>
#include <string>
class Order {
private:
    double totalPrice;
    std::string customerType;
public:
    Order(double price, std::string type) : totalPrice(price), customerType(type) {}

    double calculateDiscount(std::string type, double price) {
        if (type == "VIP") {
            return price * 0.1;
        }
        else {
            return 0;
        }
    }
    double calculateTotal() {
        double discount = calculateDiscount(getCustomerType(), totalPrice);
        
        return totalPrice - discount;
    }
    double getTotalPrice() const {
        return totalPrice;
    }
    std::string getCustomerType() const {
        return customerType;
    }
};

class discount_polity {
public:
    static double get_discount(const Order& order) {
        int discount = 0;
        if (order.getCustomerType() == "VIP") {
            discount = order.getTotalPrice() * 0.1;
        }
        return discount;
    }
};
class Invoice {
private:
    Order& order;
public:
    Invoice(Order& o) : order(o) {}
    double calculateFinalAmount() {
        double discount = order.calculateDiscount(order.getCustomerType(), order.getTotalPrice());
        return order.getTotalPrice() - discount;
    }
};
class PaymentProcessor {
public:
    static double processPayment(Order& order) {

        double discount = order.calculateDiscount(order.getCustomerType(), order.getTotalPrice());
        return order.getTotalPrice() - discount;
    }
};
int main() {
    Order order1(100.0, "Regular");
    Order order2(200.0, "VIP");
    Invoice invoice1(order1);
    Invoice invoice2(order2);
    std::cout << "Regular 고객 최종 금액: " << invoice1.calculateFinalAmount() << "원" << std::endl;
    std::cout << "VIP 고객 최종 금액: " << invoice2.calculateFinalAmount() << "원" << std::endl;
    std::cout << "Regular 고객 결제 금액: " << PaymentProcessor::processPayment(order1) << "원" << std::endl;
    std::cout << "VIP 고객 결제 금액: " << PaymentProcessor::processPayment(order2) << "원" << std::endl;
    return 0;
}