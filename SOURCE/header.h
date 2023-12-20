#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cctype>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>

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

class ServiceMediator {
public:
    void notifyBooking(const string& serviceName, const string& brandName) {
        cout << "Mediator: Notifying that " << serviceName << " of " << brandName << " is booked!" << endl;
    }
};

class BookingService{
protected:
    string serviceName;
    string brandName;
    ServiceMediator* mediator;
public:
    BookingService();
    BookingService(ServiceMediator* mediator, string serviceName, string brandName) : mediator(mediator), serviceName(serviceName), brandName(brandName) {}
    bool isAvailable();
    virtual void book();
};

class BookTaxi : public BookingService {
public:
    BookTaxi(ServiceMediator* mediator, string serviceName, string brandName) : BookingService(mediator, serviceName, brandName) {};
    void book7Seats(BookTaxi& taxi);
    void book4Seats(BookTaxi& taxi);
    void bookLuxurySeats(BookTaxi& taxi);
    void book() override;
};

class BookMotorBike : public BookingService {
public:
    BookMotorBike(ServiceMediator* mediator, string serviceName, string brandName) : BookingService(mediator, serviceName, brandName){};
    void bookNormalBike(BookMotorBike& bike);
    void bookLuxuryBike(BookMotorBike& bike);
    void book() override;
};

class BookFB : public BookingService {
public:
    BookFB(ServiceMediator* mediator, string serviceName, string brandName) : BookingService(mediator, serviceName, brandName){};
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
    vector<Client> client;
public:
    Application(vector<Client> c);
    Client getClient(int i){
        return client[i];
    }
    void bookTaxi(string servicename, string brandname, string typeOfPayment, string pickupLocation, string dropOffLocation, int numseat, string typeseat);
    void bookBike(string servicename, string brandname, string typeOfPayment, string pickupLocation, string destination, string typeseat);
    void bookFB(string servicename, string brandname, string typeOfPayment, string restaurant, string destination, string typeofFB);
    void chooseService();
};


#endif