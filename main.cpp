#include "Business.h"
#include "Domain.h"
#include "Kunde.h"
#include "Persistence.h"
#include "Presentation.h"
#include "RepoError.h"
#include "Tests.h"
#include <iostream>
#include <fstream>
using namespace std;

//initialise static member function
int Car::id = 1;

int main()
{

  Repository::CarRepo repo;
  Controller::CarController ctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X6", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  /*
    ifstream inFile("Population_file.txt");
    if(inFile.is_open())
    {

        while(inFile.good())
        {
            Car car1(inFile.get(),inFile.get(),inFile.get(),inFile.get(),inFile.get(),inFile.get())
        }
    }
    */
  ctrl.save(car1);
  ctrl.save(car2);
  ctrl.save(car3);
  ctrl.save(car4);
  ctrl.save(car5);
  ctrl.save(car6);
  ctrl.save(car7);
  ctrl.save(car8);
  ctrl.save(car9);
  ctrl.save(car10);
  ctrl.save(car11);

  UI::Console ui(ctrl);

  int choice = 0;

  cout << "1. Manager" << endl;
  cout << "2. Client" << endl;
  cout << "3. Show clients" << endl;
  cout << "0. Exit" << endl;

  vector<Client::Kunde> clients;

  while (true)
  {
    cout << "Enter option: " << endl;
    cin >> choice;

    if (choice == 0)
      break;

    if (choice == 1)
      ui.manager_run();

    if (choice == 2)
    {
      string name;
      bool ok = false;
      cout << "Enter the name of the user: " << endl;
      cin >> name;

      for (int i = 0; i < clients.size(); i++)
        if (clients[i].get_name() == name)
        {
          ui.customer_run(clients[i]);
          ok = true;
        }

      if (!ok)
      {
        Client::Kunde newClient(name);
        ui.customer_run(newClient);
        clients.push_back(newClient);
      }
    }

    if (choice == 3)
    {
      for (auto elem : clients)
        cout << elem.get_name() << " ";
      cout << endl;
    }
  }

  return 0;
}