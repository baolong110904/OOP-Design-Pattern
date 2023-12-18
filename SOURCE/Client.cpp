#include "header.h"

//Client constructor
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
//Constructor gettors - settors
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
