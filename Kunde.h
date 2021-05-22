#pragma once
#include "Domain.h"
#include "vector"
using namespace Domain;
namespace Client
{

  class Kunde
  {

  private:
    vector<Car> favourite_list;
    string username;

  public:
    Kunde(string username);

    void add_favourite(Car new_car);

    bool delete_favourite(Car new_car);

    vector<Car> show_all();

    string get_name();
  };
};