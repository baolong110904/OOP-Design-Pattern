#pragma once
#include "header.h"

void AccountService::getAccount(string email){
    cout << "Getting the account of " << email << endl;
}

void PaymentService::PaymentByPaypal(){
    cout << "Payment by PayPal" << endl;
}
void PaymentService::PaymentByCreditCard(){
    cout << "Payment by Credit Card" << endl;
}
void PaymentService::PaymentByBankingAccount(){
    cout << "Payment by Banking Account" << endl;
}
void PaymentService::PaymentByCash(){
    cout << "Payment by Cash" << endl;
}

BookingService::BookingService(){
    serviceName = "Null";
    brandName = "Null";
}
BookingService::BookingService(string serviceName, string brandName){
    this->serviceName = serviceName;
    this->brandName = brandName;
}
bool BookingService::isAvailable(){
    return true;
}
void BookingService::book(){
    if(isAvailable() == true){
        cout << "Client is booking " << serviceName << " of " << brandName << endl;
    }
    else    
        cout << "Booking Service is unavailable now!" << endl;
};