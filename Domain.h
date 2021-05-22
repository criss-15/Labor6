#pragma once
#include <iostream>
using namespace std;

namespace Domain
{
  class Car
  {
  public:
    Car(const string &model, const string &brand, const string &fuel, const int &yearofregistration,
        const int &kilometers, const int &price, const int &power);
    string get_Model();
    string get_Brand();
    int get_Year();
    int get_Kilometers();
    int get_Price();
    int get_Power();
    string get_Fuel();
    void set_Kilometers(int _kilometers);
    void set_Price(int _price);
    bool checker(Car other);
    bool operator==(const Car &other);
    //static member function
    int get_Id();

    ~Car();

  private:
    //static data member to count the objects created
    static int id;

    int thisID;
    string model;
    string brand;
    string fuel;
    int yearOfRegistration;
    int kilometers;
    int price;
    int power;
  };
};