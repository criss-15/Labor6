#pragma once
#include "Persistence.h"
#include <iostream>
#include "fstream"
using namespace std;
using namespace Repository;

#define AN_CURENT 2021;

namespace Controller
{
  class CarController
  {
  public:
    CarController(CarRepo &_repo) : repo(_repo){};

    //methods of car repo
    void save(const Car &car);
    Car del(int id);
    Car findOne(int id);
    void update_Kilometers(int id, int _kilometers); //oare const din add ne deranjeaza in update? (l-am introdus ca si constant, iar noi vrem sa il stergem)
    void update_Price(int id, int _price);           //do we need const here too? - intrebare pentru prof
    vector<Car> findAll();

    //individual methods of controller
    vector<Car> findBrand(string brand);
    vector<Car> findModel(string model);
    vector<Car> findBrandAndModel(string model, string brand);
    vector<Car> filterByAge(int age);
    vector<Car> filterByKilometers(int kilometers);
    vector<Car> filterByAgeAndKilometers(int age, int kilometers);
    vector<Car> sortByPrice();

    ~CarController(){};
    void renewfile();

  private:
    CarRepo &repo;
  };
};
