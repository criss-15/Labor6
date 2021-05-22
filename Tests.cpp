#include <iostream>
#include "Domain.h"
#include "Business.h"
#include "Persistence.h"
#include <cassert>
#include <vector>
using namespace std;
using namespace Controller;
using namespace Domain;

void test_save_car()
{
  CarRepo repo;
  CarController carctrl(repo);

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

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  assert(repo.size() == 11);
}

void test_remove_car()
{
  CarRepo repo;
  CarController carctrl(repo);

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

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  carctrl.del(1);
  carctrl.del(2);
  carctrl.del(3);
  assert(repo.size() == 8);
}

void test_find_car()
{
  CarRepo repo;
  CarController carctrl(repo);

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

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  Car car = carctrl.findOne(10);
  assert(car.get_Id() == 10);

  carctrl.del(1);
  assert(repo.size() == 10);
}

void test_update_kilometers()
{
  CarRepo repo;
  CarController carctrl(repo);

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

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  Car _car("", "", "", 0, 0, 0, 0);
  repo.update_Kilometers(4, 800);
    _car = carctrl.findOne(4);
  assert(_car.get_Kilometers() == 800);

  repo.update_Kilometers(5, 12000);
     _car = carctrl.findOne(5);
  assert(car2.get_Kilometers() == 12000);

  repo.update_Kilometers(6, 30000);
    _car = carctrl.findOne(6);
  assert(car3.get_Kilometers() == 30000);

  repo.update_Kilometers(7, 40000);
    _car = carctrl.findOne(7);
  assert(car4.get_Kilometers() == 40000);

  repo.update_Kilometers(9, 13000);
    _car = carctrl.findOne(9);
  assert(car5.get_Kilometers() == 13000);

  repo.update_Kilometers(10, 8000);
    _car = carctrl.findOne(10);
  assert(car6.get_Kilometers() == 8000);
}

void test_update_price()
{
  CarRepo repo;
  CarController carctrl(repo);

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

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);
  Car _car("", "", "", 0, 0, 0, 0);
  carctrl.update_Price(4, 75000);
    _car = carctrl.findOne(4);
  assert(_car.get_Price() == 75000);

  carctrl.update_Price(5, 120000);
    _car = carctrl.findOne(5);
  assert(_car.get_Price() == 120000);

  carctrl.update_Price(6, 39000);
    _car = carctrl.findOne(6);
  assert(_car.get_Price() == 39000);

  repo.update_Price(7, 45000);
    _car = carctrl.findOne(7);
  assert(_car.get_Price() == 45000);

  repo.update_Price(9, 135000);
    _car = carctrl.findOne(9);
  assert(_car.get_Price() == 135000);

  repo.update_Price(10, 87000);
  _car = carctrl.findOne(10);
  assert(_car.get_Price() == 87000);
}

void test_findBrand()
{
  CarRepo repo;
  CarController carctrl(repo);

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

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  vector<Car> cars = carctrl.findBrand("Volkswagen");
  assert(cars.size() == 2); 

  cars = carctrl.findBrand("BMW");
  assert(cars.size() == 2); 

  cars = carctrl.findBrand("Audi");
  assert(cars.size() == 3); 

  cars = carctrl.findBrand("Land Rover");
  assert(cars.size() == 1);

  cars = carctrl.findBrand("Porsche");
  assert(cars.size() == 2); 
}

void test_findModel()
{
  CarRepo repo;
  CarController carctrl(repo);

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

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  vector<Car> cars = carctrl.findModel("Cabriolet");
  assert(cars.size() == 1); 

  cars = carctrl.findModel("Polo");
  assert(cars.size() == 1); 

  cars = carctrl.findModel("Q7");
  assert(cars.size() == 1); 

  cars = carctrl.findModel("X6");
  assert(cars.size() == 1);

  cars = carctrl.findModel("Range Rover Velar");
  assert(cars.size() == 1); 

  cars = carctrl.findModel("A6");
  assert(cars.size() == 1);

  cars = carctrl.findModel("Macan Facelift");
  assert(cars.size() == 1);
}

void test_findBrandAndModel()
{
  CarRepo repo;
  CarController carctrl(repo);

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

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  vector<Car> cars = carctrl.findBrandAndModel("Cabriolet", "BMW");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("Polo", "Volkswagen");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("Q7", "Audi");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("X6", "BMW");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("Range Rover Velar", "Land Rover");
  assert(cars.size() == 1);

  cars = carctrl.findBrandAndModel("A6", "Audi");
  assert(cars.size() == 1); 

  cars = carctrl.findBrandAndModel("Macan Facelift", "Porsche");
  assert(cars.size() == 1); 
}

void test_filterByAge()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X7", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  vector<Car> cars = carctrl.filterByAge(2020);
  assert(cars.size() == 2); 

  cars = carctrl.filterByAge(2015);
  assert(cars.size() == 2); 

  cars = carctrl.filterByAge(2018);
  assert(cars.size() == 2); 

  cars = carctrl.filterByAge(2021);
  assert(cars.size() == 2); 
}

void test_filterByKilometers()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X7", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  vector<Car> cars = carctrl.filterByKilometers(80000);
  assert(cars.size() == 1); 
}

void test_filterByAgeAndKilometers()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X7", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  vector<Car> cars = carctrl.filterByAgeAndKilometers(2020, 700);
  assert(cars.size() == 1); 

  cars = carctrl.filterByAgeAndKilometers(2015, 100000);
  assert(cars.size() == 1); 

  cars = carctrl.filterByAgeAndKilometers(2018, 10000);
  assert(cars.size() == 1); 

  cars = carctrl.filterByAgeAndKilometers(2021, 0);
  assert(cars.size() == 2); 
}

void test_sortByPrice()
{
  CarRepo repo;
  CarController carctrl(repo);

  Car car1("A5", "Audi", "DIESEL", 2017, 1000, 10000, 100);          //remove
  Car car2("Logan", "Dacia", "BENZIN", 2019, 2000, 5000, 90);        //remove
  Car car3("Tiguan", "Volkswagen", "DIESEL", 2020, 500, 20000, 110); //remove
  Car car4("Cabriolet", "BMW", "DIESEL", 2020, 700, 70000, 150);
  Car car5("Polo", "Volkswagen", "BENZIN", 2015, 100000, 2000, 90);
  Car car6("Q7", "Audi", "DIESEL", 2015, 25000, 75000, 100);
  Car car7("X7", "BMW", "DIESEL", 2021, 0, 80000, 200);
  Car car8("Range Rover Velar", "Land Rover", "DIESEL", 2018, 80000, 50000, 240);
  Car car9("A6", "Audi", "DIESEL", 2021, 0, 16790, 150);
  Car car10("Macan Facelift", "Porsche", "DIESEL", 2018, 10000, 30000, 200);
  Car car11("Gama Panamera", "Porsche", "DIESEL", 2019, 20000, 25000, 200); // nu avem

  carctrl.save(car1);
  carctrl.save(car2);
  carctrl.save(car3);
  carctrl.save(car4);
  carctrl.save(car5);
  carctrl.save(car6);
  carctrl.save(car7);
  carctrl.save(car8);
  carctrl.save(car9);
  carctrl.save(car10);
  carctrl.save(car11);

  vector<Car> cars = carctrl.sortByPrice();
  assert(cars[0].get_Price() == 2000);

  assert(cars[cars.size() - 1].get_Price() == 80000);
}

void test_all()
{
  cout << "Beginning of tests!" << endl;
  test_save_car();
  test_remove_car();
  test_find_car();
  test_update_kilometers();
  test_update_price();
  test_findBrand();
  test_findModel();
  test_findBrandAndModel();
  test_filterByAge();
  test_filterByKilometers();
  test_filterByAgeAndKilometers();
  test_sortByPrice();
  cout << "End of tests!" << endl;
}