#include "header.h"
#include "Client.cpp"
#include "Services.cpp"
#include "BookingServices.cpp"
//#include "test.cpp"
#include "Application.cpp"

int main() {
    Client client1("Nguyen Van A", "090888888", "nguyenvana@gmail.com", "123 Tran Hung Dao");
    Client client2("Nguyen Thi B", "012345678", "nguyenthib@gmail.com", "456 Nguyen Van Cu");
    Client client3("Tran Le C", "098765432", "tranlec@gmail.com", "789 Nguyen Tri Phuong");

    ServiceMediator mediator;  // Create a mediator object

    // Create instances of the services with the mediator
    BookTaxi taxi(&mediator, "Taxi", "Grab");
    BookMotorBike motorbike(&mediator, "Motorbike", "Be");
    BookFB fb(&mediator, "Fried Chicken", "KFC");

    Application application;

    if (client1.isAccessingApp()) {
        application.bookTaxi("Taxi", "Grab", "paypal", "Truong DH KHTN", "123 Tran Hung Dao", 5, "");
        cout << endl;
    }

    if (client2.isAccessingApp()) {
        application.bookBike("Motorbike", "Be", "Credit Card", "Truong DH Su Pham", "456 Nguyen Van Cu", "normal");
        cout << endl;
    }

    if (client3.isAccessingApp()) {
        application.bookFB("Fried Chicken", "KFC", "Cash", "KFC Tran Hung Dao", "789 Nguyen Tri Phuong", "fast food");
    }

    return 0;
}