#pragma once
#include "header.h"

using namespace std;

Application::Application() {
    accountService = new AccountService();
    paymentService = new PaymentService();
    bookingService = new BookingService(new ServiceMediator(), "", "");
}
void Application::chooseService() {
int choice;

// Display available services
std::cout << "Choose a service:\n";
std::cout << "1. Taxi\n";
std::cout << "2. Motorbike\n";
std::cout << "3. Food & Beverage\n";

// Get user input
std::cout << "Enter your choice: ";
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
            std::cout << "Invalid choice!" << endl;
            return;
    }

    // Ask for specific service options
    bookingService->book();
}

  // Function to book taxi by cash
void Application::bookTaxi(string servicename, string brandname, string typeOfPayment, string pickupLocation, string dropOffLocation, int numseat, string typeseat) {
    BookTaxi* taxi = new BookTaxi(new ServiceMediator(), servicename, brandname);

    // Book taxi with specific details
    transform(typeOfPayment.begin(), typeOfPayment.end(), typeOfPayment.begin(),
              [](unsigned char c) { return std::tolower(c); });

    transform(typeseat.begin(), typeseat.end(), typeseat.begin(),
              [](unsigned char c) { return std::tolower(c); });

    // Book taxi with specific details
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
        std::cout << "Invalid payment type!" << std::endl;
        return;
    }

    if (typeseat == "luxury" && numseat <= 7) {
        taxi->bookLuxurySeats(*taxi);
    } else if (numseat <= 4) {
        taxi->book4Seats(*taxi);
    } else if (numseat <= 7) {
        taxi->book7Seats(*taxi);
    } else {
        std::cout << "Invalid seat type or number!" << std::endl;
        return;
    }

    std::cout << "Pickup location: " << pickupLocation << endl;
    std::cout << "Drop-off location: " << dropOffLocation << endl;
}

  // Function to book motorbike by credit card
void Application::bookBike(string servicename, string brandname, string typeOfPayment, string pickupLocation, string destination, string typeseat) {
    BookMotorBike* bike = new BookMotorBike(new ServiceMediator(), servicename, brandname);

    std::transform(typeOfPayment.begin(), typeOfPayment.end(), typeOfPayment.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::transform(typeseat.begin(), typeseat.end(), typeseat.begin(),
                   [](unsigned char c) { return std::tolower(c); });

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
        std::cout << "Invalid payment type!" << std::endl;
        // Handle the invalid payment type case
        return;
    }

    if (typeseat == "luxury") {
        bike->bookLuxuryBike(*bike);
    } else if (typeseat == "normal") {
        bike->bookNormalBike(*bike);
    } else {
        std::cout << "Invalid seat type!" << std::endl;
        // Handle the invalid seat type case
        return;
    }

    std::cout << "Pickup location: " << pickupLocation << endl;
    std::cout << "Destination: " << destination << endl;
}

void Application::bookFB(string servicename, string brandname, string typeOfPayment, string restaurant, string destination, string typeofFB) {
    BookFB* food = new BookFB(new ServiceMediator(), servicename, brandname);

    std::transform(typeOfPayment.begin(), typeOfPayment.end(), typeOfPayment.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    std::transform(typeofFB.begin(), typeofFB.end(), typeofFB.begin(),
                   [](unsigned char c) { return std::tolower(c); });

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
        std::cout << "Invalid payment type!" << std::endl;
        // Handle the invalid payment type case
        return;
    }

    if (typeofFB == "fast food" || typeofFB == "junk food") {
        food->bookFastFood(*food);
    } else if (typeofFB == "drink" || typeofFB == "beverage") {
        food->bookDrinks(*food);
    }
     else if (typeofFB == "main course" || typeofFB == "main") {
        food->bookMainCourse(*food);
    } else {
        std::cout << "Invalid seat type!" << std::endl;
        // Handle the invalid seat type case
        return;
    }

    std::cout << "Restaurant: " << restaurant << endl;
    std::cout << "Destination: " << destination << endl;
}