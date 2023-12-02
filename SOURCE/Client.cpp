#pragma once
#include "header.h"

Client::Client(){
    Name = "Null";
    phoneNumber = "Null";
    emailAddress = "Null";
    houseAddress = "Null";
}
Client::Client(string Name, string phoneNumber, string emailAddress, string houseAddress){
    this->Name = Name;
    this->phoneNumber = phoneNumber;
    this->emailAddress = emailAddress;
    this->houseAddress = houseAddress;
}
bool Client::isAccessingApp() {
    return true;
}
void Client::setEmail(string emailAddress){
    this->emailAddress = emailAddress;
}
string Client::getEmail(){
    return emailAddress;
}
string Client::getName(){
    return Name;
}
void Client::setName(string Name){
    this->Name = Name;
}
string Client::getPhone(){
    return phoneNumber;
}
void Client::setPhone(string phoneNumber){
    this->phoneNumber = phoneNumber;
}
string Client::getHouse(){
    return houseAddress;
}
void Client::setHouse(string houseAddress){
    this->houseAddress = houseAddress;
}
ostream& operator<<(ostream& os, const Client& client) {
    os << "Name: " << client.Name << endl;
    os << "Phone Number: " << client.phoneNumber << endl;
    os << "Email address: " << client.emailAddress << endl;
    os << "House address: " << client.houseAddress << endl;
    return os;
    }
istream& operator>>(istream& is, Client& client) {
    cout << "Enter Name: ";
    is >> client.Name;

    cout << "Enter Phone Number: ";
    is >> client.phoneNumber;

    cout << "Enter Email Address: ";
    is >> client.emailAddress;

    cout << "Enter House Address: ";
    is.ignore();
    getline(is, client.houseAddress);

    return is;
}