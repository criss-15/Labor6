#include "Domain.h"
#include <iomanip> //setprecision

using namespace Domain;

Car::Car(const string &model, const string &brand, const string &fuel, const int &yearofregistration,
         const int &kilometers, const int &price, const int &power)
{
  this->thisID = id++;
  this->model = model;
  this->brand = brand;
  this->fuel = fuel;
  this->yearOfRegistration = yearofregistration;
  this->kilometers = kilometers;
  this->price = price;
  this->power = power;
}

int Car::get_Power()
{
  return this->power;
}

string Car::get_Model()
{

  return this->model;
}

string Car::get_Brand()
{
  return this->brand;
}

int Car::get_Kilometers()
{
  return this->kilometers;
}

int Car::get_Price()
{
  return this->price;
}

int Car::get_Year()
{
  return this->yearOfRegistration;
}

string Car::get_Fuel()
{
  return this->fuel;
}

void Car::set_Kilometers(int _kilometers)
{

  this->kilometers = _kilometers;
}

void Car::set_Price(int _price)
{
  this->price = _price;
}

bool Car::checker(Car other)
{
  if (this->price == other.get_Price() && this->kilometers == other.get_Kilometers() && this->fuel == other.get_Fuel() && this->yearOfRegistration == other.get_Year() &&
      this->brand == other.get_Brand() && this->power == other.get_Power() && this->model == other.get_Model())
    return true;
  return false;
}

bool Car::operator==(const Car& other){
  return checker(other);
}

Car::~Car() = default;

int Car::get_Id()
{
  return this->thisID;
}