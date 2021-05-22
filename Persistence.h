#pragma once
#include "Domain.h"
#include <iostream>
#include <vector>
#include "CRUD_Repository.h"
using namespace std;
using namespace Domain;

#define NULL_CAR Car("","","",-1,-1,-1,-1)

namespace Repository
{
  class CarRepo : public CrudRepository<Car>
  {
  public:
    CarRepo();
    //void add(const Car &car);
    Car findOne(int id);
    Car save(Car entity);
    //bool remove(const Car &car);
    Car del(int id);
    void update_Kilometers(int id, int _kilometers);
    void update_Price(int id, int _price);
    int size();
    //vector<Car> getAll();
    vector<Car> findAll();
    //~CarRepo();

  private:
    vector<Car> list;
  };
};