#include "header.h"


//Book a Taxi Services
void BookTaxi::book7Seats(BookTaxi& taxi){
    cout << "Client is booking 7-seat" << taxi.serviceName << " of " << taxi.brandName << endl;
}
void BookTaxi::book4Seats(BookTaxi& taxi){
    cout << "Client is booking 4-seat" << taxi.serviceName << " of " << taxi.brandName << endl;
}
void BookTaxi::bookLuxurySeats(BookTaxi& taxi){
    cout << "Client is booking Luxury" << taxi.serviceName << " of " << taxi.brandName << endl;
}
void BookTaxi::book(){
    cout << serviceName << " is coming to Client!" << endl;
    mediator->notifyBooking(serviceName, brandName);
}

//Book a motorbike Services
void BookMotorBike::bookNormalBike(BookMotorBike& bike){
    cout << "Client is booking a normal" << bike.serviceName << " of " << bike.brandName << endl;
}
void BookMotorBike::bookLuxuryBike(BookMotorBike& bike){
    cout << "Client is booking a Luxury" << bike.serviceName << " of " << bike.brandName << endl;
}
void BookMotorBike::book(){
    cout << serviceName  << " is coming to Client!"<< endl;
    mediator->notifyBooking(serviceName, brandName);
}


//Book Food and Beverage
void BookFB::bookFastFood(BookFB& food){
    cout << "Client is booking " << food.serviceName << " of " << food.brandName << endl;
}
void BookFB::bookDrinks(BookFB& drink){
    cout << "Client is booking a Luxury" << drink.serviceName << " of " << drink.brandName << endl;
}
void BookFB::bookMainCourse(BookFB& mc){
    cout << "Client is booking " << mc.serviceName << " of " << mc.brandName << endl;
}
void BookFB::book(){
    cout << serviceName << " of " << brandName << " is being delivered to Client!"<< endl;
    mediator->notifyBooking(serviceName, brandName);
}