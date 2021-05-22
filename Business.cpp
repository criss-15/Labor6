#include "Business.h"
using namespace Controller;

void CarController::save(const Car &car)
{
  this->repo.save(car);
}

Car CarController::del(int id)
{
  return this->repo.del(id);
}

Car CarController::findOne(int id)
{
  return repo.findOne(id);
}

void CarController::update_Kilometers(int id, int _kilometers)
{
  this->repo.update_Kilometers(id, _kilometers);
}

void CarController::update_Price(int id, int _price)
{
  this->repo.update_Price(id, _price);
}

vector<Car> CarController::findAll()
{ // use a copy of the list in the controller
  return this->repo.findAll();
}

vector<Car> CarController::findBrand(string brand)
{
  vector<Car> result;
  vector<Car> copy_list;
  copy_list = findAll();
  for (int i = 0; i < copy_list.size(); i++)
  {
    if (copy_list[i].get_Brand() == brand)
      result.push_back(copy_list[i]);
  }
  return result;
}

vector<Car> CarController::findModel(string model)
{
  vector<Car> result;
  vector<Car> copy_list;
  copy_list = findAll();
  for (int i = 0; i < copy_list.size(); i++)
  {
    if (copy_list[i].get_Model() == model)
      result.push_back(copy_list[i]);
  }
  return result;
}

vector<Car> CarController::findBrandAndModel(string model, string brand)
{
  vector<Car> result;
  vector<Car> copy_list;
  copy_list = findAll();

  for (int i = 0; i < copy_list.size(); i++)
  {
    if (copy_list[i].get_Brand() == brand && copy_list[i].get_Model() == model)
      result.push_back(copy_list[i]);
  }
  return result;
}

vector<Car> CarController::filterByAge(int age)
{
  vector<Car> result;
  vector<Car> copy_list;
  copy_list = findAll();
  for (int i = 0; i < copy_list.size(); i++)
  {
    if (copy_list[i].get_Year() == age)
      result.push_back(copy_list[i]);
  }
  return result;
}

vector<Car> CarController::filterByKilometers(int kilometers)
{
  vector<Car> result;
  vector<Car> copy_list;
  copy_list = findAll();
  for (int i = 0; i < copy_list.size(); i++)
  {
    if (copy_list[i].get_Kilometers() == kilometers)
      result.push_back(copy_list[i]);
  }
  return result;
}

vector<Car> CarController::filterByAgeAndKilometers(int age, int kilometers)
{

  vector<Car> result;
  vector<Car> copy_list;
  copy_list = findAll();
  for (int i = 0; i < copy_list.size(); i++)
  {
    if (copy_list[i].get_Year() == age && copy_list[i].get_Kilometers() == kilometers)
      result.push_back(copy_list[i]);
  }
  return result;
}
void CarController::renewfile()
{
  vector<Car> copy_list;
  copy_list = findAll();
  ofstream myfile;
  myfile.open("All_file");
  remove("All_file");
  for (int i = 0; i < copy_list.size(); i++)
  {
    myfile << copy_list[i].get_Model() << ",";
    myfile << copy_list[i].get_Brand() << ",";
    myfile << copy_list[i].get_Fuel() << ",";
    myfile << copy_list[i].get_Year() << ",";
    myfile << copy_list[i].get_Kilometers() << ",";
    myfile << copy_list[i].get_Price() << "\n";
  }
  myfile.close();
}
vector<Car> CarController::sortByPrice()
{
  vector<Car> copy_list;
  copy_list = findAll();
  for (int i = 0; i < copy_list.size() - 1; i++)
  {

    for (int j = i; j < copy_list.size(); j++)
    {
      if (copy_list[i].get_Price() > copy_list[j].get_Price())
        swap(copy_list[i], copy_list[j]);
    }
  }
  return copy_list;
}
