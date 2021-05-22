#pragma once
#include "Business.h"
#include <iostream>
#include "Kunde.h"
using namespace std;
using namespace Controller;

namespace UI
{
  class Console
  {
  private:
    vector<Client::Kunde> client_list;
    CarController &_ctrl;
    //methods of car repo
    void add(const Car &car);
    Car remove(int id);
    Car findOne(int id);
    void update_Kilometers(int id, int _kilometers);
    void update_Price(int id, int _price);
    vector<Car> getAll();

    //individual methods of controller
    vector<Car> findBrand(string brand);
    vector<Car> findModel(string model);
    vector<Car> findBrandAndModel(string brand, string model);
    vector<Car> filterByAge(int age);
    vector<Car> filterByKilometers(int kilometers);
    vector<Car> filterByAgeAndKilometers(int age, int kilometers);
    vector<Car> sortByPrice();
    Car reader();
    Client::Kunde find_client(string name);
    
  public:
    Console(CarController &ctrl) : _ctrl(ctrl){};
    void manager_run();
    void customer_run(Client::Kunde &client);
    ~Console(){};
  };
}