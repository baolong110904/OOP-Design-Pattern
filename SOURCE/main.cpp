#include "header.h"
#include "Client.cpp"
#include "Services.cpp"
#include "BookingServices.cpp"
#include "test.cpp"

int main() {
  Client client;
  cin >> client;
  cout << client;
  
  Application application;
  if(client.isAccessingApp()){
        application.chooseService();
        //application.bookTaxiByCash(client.getEmail());
  }
  return 0;
}