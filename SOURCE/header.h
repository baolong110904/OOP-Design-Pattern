#pragma once
#include <bits/stdc++.h>

using namespace std;

class Client {
private:
    string Name;
    string phoneNumber;
    string emailAddress;
    string houseAddress;
public:
    Client();
    Client(string Name, string phoneNumber, string emailAddress, string houseAddress);
    bool isAccessingApp();
    
    string getEmail();
    string getName();
    string getPhone();
    string getHouse();
    void setName(string Name);
    void setPhone(string phoneNumber);
    void setEmail(string emailAddress);
    void setHouse(string houseAddress);

    friend ostream& operator<<(ostream& os, const Client& client);
    friend istream& operator>>(istream& is, Client& client);

};

class AccountService{
public:
    void getAccount(string email);
};
class PaymentService{
public:
    void PaymentByPaypal();
    void PaymentByCreditCard();
    void PaymentByBankingAccount();
    void PaymentByCash();
};
class BookingService{
protected:
    string serviceName;
    string brandName;
public:
    BookingService();
    BookingService(string serviceName, string brandName);
    bool isAvailable();
    virtual void book();
};
class BookTaxi : public BookingService {
public:
    BookTaxi(string serviceName, string brandName) : BookingService(serviceName, brandName){};
    void book7Seats(BookTaxi& taxi);
    void book4Seats(BookTaxi& taxi);
    void bookLuxurySeats(BookTaxi& taxi);
    void book() override;
};

class BookMotorBike : public BookingService {
public:
    BookMotorBike(string serviceName, string brandName) : BookingService(serviceName, brandName){};
    void bookNormalBike(BookMotorBike& bike);
    void bookLuxuryBike(BookMotorBike& bike);
    void book() override;
};

class BookFB : public BookingService {
public:
    BookFB(string serviceName, string brandName) : BookingService(serviceName, brandName){};
    void bookFastFood(BookFB& food);
    void bookDrinks(BookFB& drink);
    void bookMainCourse(BookFB& mc);
    void book() override;
};

class Application {
protected:
    AccountService* accountService;
    PaymentService* paymentService;
    BookingService* bookingService;
    Client* client;
public:
    Application();
    void bookTaxiByCash(string email, int numSeats);
    void chooseService();
    // Function to book motorbike by credit card
    void bookBikeByCreditCard(string pickupLocation, string destination);
};


