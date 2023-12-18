#include "header.h"

using namespace std;

//Application Constructor
Application::Application() {
    accountService = new AccountService();
    paymentService = new PaymentService();
    bookingService = new BookingService(new ServiceMediator(), "", "");
}
//Function for Client to choose the Booking services
void Application::chooseService() {
    int choice;

    // Display available services
    cout << "Choose a service:\n";
    cout << "1. Taxi\n";
    cout << "2. Motorbike\n";
    cout << "3. Food & Beverage\n";

    // Get user input
    cout << "Enter your choice: ";
    cin >> choice;

    // Create specific booking service based on choice
    switch (choice) {
            case 1:
                bookingService = new BookTaxi(new ServiceMediator(), "", "");
                break;
            case 2:
                bookingService = new BookMotorBike(new ServiceMediator(), "", "");
                break;
            case 3:
                bookingService = new BookFB(new ServiceMediator(), "", "");
                break;
            default:
                cout << "Invalid choice!" << endl;
                return;
        }
        // Ask for specific service options
        bookingService->book();
}

// Function to book taxi and integrate with Account and Payment services
void Application::bookTaxi(string servicename, string brandname, string typeOfPayment, string pickupLocation, string dropOffLocation, int numseat, string typeseat) {
    BookTaxi* taxi = new BookTaxi(new ServiceMediator(), servicename, brandname);

    // Book taxi with specific details
    transform(typeOfPayment.begin(), typeOfPayment.end(), typeOfPayment.begin(),
              [](unsigned char c) { return tolower(c); });

    transform(typeseat.begin(), typeseat.end(), typeseat.begin(),
              [](unsigned char c) { return tolower(c); });

    // Book taxi with type of payments
    if (typeOfPayment == "cash") {
        paymentService->PaymentByCash();
    } else if (typeOfPayment == "credit card") {
        paymentService->PaymentByCreditCard();
    } else if (typeOfPayment == "banking account") {
        paymentService->PaymentByBankingAccount();
    }
    else if (typeOfPayment == "paypal") {
        paymentService->PaymentByPaypal();
    }
     else {
        cout << "Invalid payment type!" << endl;
        return;
    }
    //Choose type of seats
    if (typeseat == "luxury" && numseat <= 7) {
        taxi->bookLuxurySeats(*taxi);
    } else if (numseat <= 4) {
        taxi->book4Seats(*taxi);
    } else if (numseat <= 7) {
        taxi->book7Seats(*taxi);
    } else {
        cout << "Invalid seat type or number!" << endl;
        return;
    }

    cout << "Pickup location: " << pickupLocation << endl;
    cout << "Drop-off location: " << dropOffLocation << endl;
}

// Function to book motorbike 
void Application::bookBike(string servicename, string brandname, string typeOfPayment, string pickupLocation, string destination, string typeseat) {
    BookMotorBike* bike = new BookMotorBike(new ServiceMediator(), servicename, brandname);

    transform(typeOfPayment.begin(), typeOfPayment.end(), typeOfPayment.begin(),
                   [](unsigned char c) { return tolower(c); });

    transform(typeseat.begin(), typeseat.end(), typeseat.begin(),
                   [](unsigned char c) { return tolower(c); });

    // Book motorbike with specific details
    if (typeOfPayment == "cash") {
        paymentService->PaymentByCash();
    } else if (typeOfPayment == "credit card") {
        paymentService->PaymentByCreditCard();
    }
    else if (typeOfPayment == "cash") {
        paymentService->PaymentByCash();
    }
    else if (typeOfPayment == "banking account") {
        paymentService->PaymentByBankingAccount();
    }
    else if (typeOfPayment == "paypal") {
        paymentService->PaymentByPaypal();
    }
    else {
        cout << "Invalid payment type!" << endl;
        return;
    }
    //Choose type of seats
    if (typeseat == "luxury") {
        bike->bookLuxuryBike(*bike);
    } else if (typeseat == "normal") {
        bike->bookNormalBike(*bike);
    } else {
        cout << "Invalid seat type!" << endl;
        // Handle the invalid seat type case
        return;
    }

    cout << "Pickup location: " << pickupLocation << endl;
    cout << "Destination: " << destination << endl;
}
//// Function to book Food and Beverage 
void Application::bookFB(string servicename, string brandname, string typeOfPayment, string restaurant, string destination, string typeofFB) {
    BookFB* food = new BookFB(new ServiceMediator(), servicename, brandname);

    transform(typeOfPayment.begin(), typeOfPayment.end(), typeOfPayment.begin(),
                   [](unsigned char c) { return tolower(c); });

    transform(typeofFB.begin(), typeofFB.end(), typeofFB.begin(),
                   [](unsigned char c) { return tolower(c); });

    // Book food and beverage with specific details
    if (typeOfPayment == "cash") {
        paymentService->PaymentByCash();
    } else if (typeOfPayment == "credit card") {
        paymentService->PaymentByCreditCard();
    }
    else if (typeOfPayment == "cash") {
        paymentService->PaymentByCash();
    }
    else if (typeOfPayment == "banking account") {
        paymentService->PaymentByBankingAccount();
    }
    else if (typeOfPayment == "paypal") {
        paymentService->PaymentByPaypal();
    }
    else {
        cout << "Invalid payment type!" << endl;
        return;
    }
    //Choose type of food
    if (typeofFB == "fast food" || typeofFB == "junk food") {
        food->bookFastFood(*food);
    } else if (typeofFB == "drink" || typeofFB == "beverage") {
        food->bookDrinks(*food);
    }
     else if (typeofFB == "main course" || typeofFB == "main") {
        food->bookMainCourse(*food);
    } else {
        cout << "Invalid seat type!" << endl;
        return;
    }

    cout << "Restaurant: " << restaurant << endl;
    cout << "Destination: " << destination << endl;
}