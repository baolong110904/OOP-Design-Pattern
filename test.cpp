#pragma once
#include "header.h"
Application::Application() {
    accountService = new AccountService();
    paymentService = new PaymentService();
    bookingService = new BookingService();
}

void Application::bookTaxiByCash(string email, int numSeats) {
    BookTaxi* taxi = new BookTaxi("Taxi", "Grab");
    accountService->getAccount(email);
    paymentService->PaymentByCash();

    // Book taxi with specific details
    if (numSeats <= 4) {
        taxi->book4Seats(*taxi);
    } else if (numSeats <= 7) {
        taxi->book7Seats(*taxi);
    } else {
        taxi->bookLuxurySeats(*taxi);
    }
    taxi->book();
}

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
    string brandName;
    // Create specific booking service based on choice
    switch (choice) {
    case 1:
        cout << "Enter your preferred Taxi brand (e.g., Grab, Uber): ";
        cin.ignore();
        getline(cin, brandName);

        bookingService = new BookTaxi("Taxi", brandName);
        break;
    case 2:
        cout << "Enter your preferred Motorbike brand (e.g., Honda, Yamaha): ";
        cin.ignore();
        getline(cin, brandName);

        bookingService = new BookMotorBike("Motorbike", brandName);
        break;
    case 3:
        cout << "Enter your preferred Food & Beverage brand (e.g., KFC, McDonald's): ";
        cin.ignore();
        getline(cin, brandName);

        bookingService = new BookFB("Food & Beverage", brandName);
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }
    if (choice == 1) { // If the chosen service is Taxi
        int num;
        cout << "Enter your preferred number of seats (e.g., 4, 7, Luxury): ";
        cin >> num;

        if (num > 0) {
            bookTaxiByCash(client->getEmail(), num);
        } else {
            cout << "Invalid number of seats!" << endl;
        }
    }
}



// Function to book motorbike by credit card
void Application::bookBikeByCreditCard(string pickupLocation, string destination) {
    BookMotorBike* bike = new BookMotorBike("Motorbike", "Honda");

    // Book motorbike with specific details
    bike->book();
    cout << "Pickup location: " << pickupLocation << endl;
    cout << "Destination: " << destination << endl;

    // Choose credit card payment
    paymentService->PaymentByCreditCard();
}
