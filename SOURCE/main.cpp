#include "header.h"

int main() {
    Client client1("Bui Minh Quan", "090888888", "BuiMinhQuanGay@gmail.com", "123 Tran Hung Dao");
    Client client2("Luong Quoc Dung", "012345678", "LuongQuocDung@gmail.com", "456 Nguyen Van Cu");
    Client client3("Nguyen Thien Bao", "098765432", "NguyenThienBao@gmail.com", "789 Nguyen Tri Phuong");

    ServiceMediator mediator;  // Create a mediator object

    // Create instances of the services with the mediator
    BookTaxi taxi(&mediator, "Taxi", "Grab");
    BookMotorBike motorbike(&mediator, "Motorbike", "Be");
    BookFB fb(&mediator, "Fried Chicken", "KFC");

    Application application({client1, client2, client3});

    if (application.getClient(0).isAccessingApp()) {
        application.bookTaxi("Taxi", "Grab", "paypal", "Truong DH KHTN", "123 Tran Hung Dao", 5, "");
        cout << endl;
    }

    if (application.getClient(1).isAccessingApp()) {
        application.bookBike("Motorbike", "Be", "Credit Card", "Truong DH Su Pham", "456 Nguyen Van Cu", "normal");
        cout << endl;
    }

    if (application.getClient(2).isAccessingApp()) {
        application.bookFB("Fried Chicken", "KFC", "Cash", "KFC Tran Hung Dao", "789 Nguyen Tri Phuong", "fast food");
    }

    return 0;
}
