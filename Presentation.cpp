#include "Presentation.h"
#include <iomanip>
using namespace UI;
using namespace std;
using namespace Client;
using namespace Domain;

Car Console::reader()
{
  string model, brand, fuel;
  int yearofregistration, kilometers, price, power;
  cout << "Write the model : " << endl;
  cin >> model;
  cout << "Write the brand : " << endl;
  cin >> brand;
  cout << "Write the fuel type : " << endl;
  cin >> fuel;
  cout << "Write the year of registration : " << endl;
  cin >> yearofregistration;
  cout << "Write the kilometers of the car : " << endl;
  cin >> kilometers;
  cout << "Write the price : " << endl;
  cin >> price;
  cout << "Write the power of the car : " << endl;
  cin >> power;
  cout << endl;

  Car result(model, brand, fuel, yearofregistration, kilometers, price, power);
  return result;
}

void printer(vector<Car> my_vector)
{
  cout << fixed;
  cout << setprecision(8);
  cout << left << setw(15) << "Model";
  cout << right << setw(13) << "Brand";
  cout << right << setw(15) << "Fuel";
  cout << right << setw(15) << "Year";
  cout << right << setw(17) << "Kilometers";
  cout << right << setw(15) << "Price";
  cout << right << setw(15) << "Power";
  cout << "\n";
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout << "\n";
  for (int i = 0; i < my_vector.size(); i++)
  {
    cout << fixed;
    cout << setprecision(8);
    cout << i + 1 << ". ";
    cout << left << setw(15) << my_vector[i].get_Model();
    cout << right << setw(13) << my_vector[i].get_Brand();
    cout << right << setw(15) << my_vector[i].get_Fuel();
    cout << right << setw(15) << my_vector[i].get_Year();
    cout << right << setw(17) << my_vector[i].get_Kilometers();
    cout << right << setw(15) << my_vector[i].get_Price();
    cout << right << setw(15) << my_vector[i].get_Power();
    cout << "\n";
  }
  cout << endl;
}
Kunde Console::find_client(string name)
{
  for (int i = 0; i < client_list.size(); i++)
  {
    if (client_list[i].get_name() == name)
      return client_list[i];
  }
  throw exception();
}
void Console::manager_run()
{
  string command, model, brand;
  vector<Car> result;
  Car new_car("", "", "", 0, 0, 0, 0);
  int yearofregistration, km;

  cout << "Enter one of the commands to execute the specific command and write exit to end the program \n";
  cout << "add               - Add car" << endl;
  cout << "remove            - Remove car" << endl;
  cout << "find              - Find car" << endl;
  cout << "update price      - Update the price of car" << endl;
  cout << "update kilometers - Update the kilometers of a car" << endl;
  cout << "all               - Show all cars" << endl;
  cout << "find1             - Find cars by brand" << endl;
  cout << "find2             - Find cars by model" << endl;
  cout << "find3             - Find cars by brand and model" << endl;
  cout << "filter1           - Find cars by year" << endl;
  cout << "filter2           - Find cars by kilometers" << endl;
  cout << "filter3           - Find cars by year and kilometers" << endl;
  cout << "sort              - Sort cars by price" << endl;
  cout << "id                - Get a car's id" << endl;

  while (true)
  {
    cout << endl
         << "Insert command: " << endl;
    cin >> command;
    if (command == "exit")
      break;

    if (command == "add")
    {
      new_car = reader();
      //_ctrl.add(new_car);
      _ctrl.save(new_car);
      _ctrl.renewfile();
    }

    if (command == "remove")
    {
      new_car = reader();
      _ctrl.del(new_car.get_Id());
      _ctrl.renewfile();
    }

    if (command == "find")
    {
      new_car = reader();
      auto elem = _ctrl.findOne(new_car.get_Id());
      if (elem.get_Power() != -1) //if it is not the NULL_Car
        cout << "The car is in the list\n";
      else
        cout << "The car isn't in the list\n";
      _ctrl.renewfile();
    }
    if (command == "update price")
    {
      int id;
      cout << "pick a car's id";
      cin >> id;
      cout << "pick a new price : ";
      int new_price;
      cin >> new_price;
      _ctrl.update_Price(id, new_price);
      _ctrl.renewfile();
    }

    if (command == "update kilometers")
    {
      int id;

      cout << "pick a car's id";
      cin >> id;
      cout << "set the new number of kilometers : ";
      int new_km;
      cin >> new_km;
      _ctrl.update_Kilometers(id, new_km);
      _ctrl.renewfile();
    }

    if (command == "all")
    {
      result = _ctrl.findAll();
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "find1")
    {

      cout << "Select the brand you want to find  : ";
      cin >> brand;
      result = _ctrl.findBrand(brand);
      printer(result);
    }

    if (command == "find2")
    {

      cout << "Select the model you want to find";
      cin >> model;
      result = _ctrl.findModel(model);
      printer(result);
    }

    if (command == "find3")
    {

      cout << "Select the model and the brand you want to find \n";
      cout << "Model is : ";
      cin >> brand;
      cout << "Brand is : ";
      cin >> model;
      result = _ctrl.findBrandAndModel(brand, model);
      printer(result);
    }

    if (command == "filter1")
    {

      cout << "Choose the age of the cars you want to filter";
      cin >> yearofregistration;
      result = _ctrl.filterByAge(yearofregistration);
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "filter2")
    {

      int km;
      cout << "Choose the number of kilometers you want to filter";
      cin >> km;
      result = _ctrl.filterByKilometers(km);
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "filter3")
    {

      cout << "Choose the age and the number of kilometers \n";
      cout << "The age is : ";
      cin >> yearofregistration;
      cout << "The nubmer of kilometers is : ";
      cin >> km;
      result = _ctrl.filterByAgeAndKilometers(yearofregistration, km);
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "sort")
    {
      vector<Car> cars = sortByPrice();
      printer(cars);
    }

    if (command == "id")
    {
      int option = 0;
      cout << "Pick the car you want: \n";
      result = _ctrl.findAll();
      printer(result);

      cin >> option;
      cout << "The id is: " << result[option - 1].get_Id() << endl;
    }
  }
}

void Console::customer_run(Kunde &client)
{
  string command, username, brand, model;
  Car new_car("", "", "", 0, 0, 0, 0);
  int yearofregistration, km;
  vector<Car> result;

  cout << "Enter one of the commands to execute the specific command and write exit to end the program \n";
  cout << "find              - Find car" << endl;
  cout << "update price      - Update the price of car" << endl;
  cout << "update kilometers - Update the kilometers of a car" << endl;
  cout << "all               - Show all cars" << endl;
  cout << "find1             - Find cars by brand" << endl;
  cout << "find2             - Find cars by model" << endl;
  cout << "find3             - Find cars by brand and model" << endl;
  cout << "filter1           - Find cars by year" << endl;
  cout << "filter2           - Find cars by kilometers" << endl;
  cout << "filter3           - Find cars by year and kilometers" << endl;
  cout << "sort              - Sort cars by price" << endl;
  cout << "addfav            - Add a favourite car" << endl;
  cout << "removefav         - Remove a favourite car" << endl;
  cout << "change            - Change user" << endl;
  cout << "show              - Shows favourite cars" << endl;
  cout << "id                - Get a car's id" << endl;

  while (true)
  {
    cout << "Insert command: " << endl;
    cin >> command;

    if (command == "exit")
      break;

    if (command == "find")
    {
      new_car = reader();
      auto elem = _ctrl.findOne(new_car.get_Id());
      if (elem.get_Power() != -1) //if it is not the NULL_Car
        cout << "The car is in the list\n";
      else
        cout << "The car isn't in the list\n";
      _ctrl.renewfile();
    }

    if (command == "update price")
    {
      int id;
      cout << "pick an id: ";
      cin >> id;
      new_car = reader();
      cout << "pick a new price : ";
      int new_price;
      cin >> new_price;
      _ctrl.update_Price(id, new_price);
      _ctrl.renewfile();
    }

    if (command == "update kilometers")
    {
      int id;
      cout << "pick a car with the id";
      cin >> id;
      cout << "set the new number of kilometers : ";
      
      
      int new_km;
      cin >> new_km;
      _ctrl.update_Kilometers(id, new_km);
      _ctrl.renewfile();
    }

    if (command == "all")
    {
      result = _ctrl.findAll();
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "find1")
    {

      cout << "Select the brand you want to find  : ";
      cin >> brand;
      result = _ctrl.findBrand(brand);
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "find2")
    {

      cout << "Select the model you want to find";
      cin >> model;
      result = _ctrl.findModel(model);
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "find3")
    {

      cout << "Select the model and the brand you want to find \n";
      cout << "Brand is : ";
      cin >> brand;
      cout << "Model is : ";
      cin >> model;
      result = _ctrl.findBrandAndModel(brand, model);
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "filter1")
    {

      cout << "Choose the age of the cars you want to filter";
      cin >> yearofregistration;
      result = _ctrl.filterByAge(yearofregistration);
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "filter2")
    {

      cout << "Choose the number of kilometers you want to filter";
      cin >> km;
      result = _ctrl.filterByKilometers(km);
      printer(result);
      _ctrl.renewfile();
    }

    if (command == "filter3")
    {

      cout << "Choose the age and the number of kilometers \n";
      cout << "The age is : ";
      cin >> yearofregistration;
      cout << "The nubmer of kilometers is : ";
      cin >> km;
      result = _ctrl.filterByAgeAndKilometers(yearofregistration, km);
      printer(result);
    }

    if (command == "addfav")
    {
      int option = 0;
      cout << "Pick the car you want to add \n";
      result = _ctrl.findAll();
      printer(result);

      cin >> option;
      client.add_favourite(result[option - 1]);
    }

    if (command == "removefav")
    {

      cout << "Pick the car you want to remove\n";
      new_car = reader();
      client.delete_favourite(new_car);
    }

    if (command == "show")
    {

      result = client.show_all();
      printer(result);
    }

    if (command == "change")
    {
      cout << "select a new user";
      cin >> username;
      client = find_client(username);
      customer_run(client);
    }

    if (command == "id")
    {
      int option = 0;
      cout << "Pick the car you want: \n";
      result = _ctrl.findAll();
      printer(result);

      cin >> option;
      cout << "The id is: " << result[option - 1].get_Id() << endl;
    }

    cout << endl;
  }
}

void Console::add(const Car &car)
{

  this->_ctrl.save(car);
}

Car Console::remove(int id)
{
  return this->_ctrl.del(id);
}

Car Console::findOne(int id)
{
  return this->_ctrl.findOne(id);
}

void Console::update_Price(int id, int _price)
{
  this->_ctrl.update_Price(id, _price);
}

void Console::update_Kilometers(int id, int _kilometers)
{
  this->_ctrl.update_Kilometers(id, _kilometers);
}

vector<Car> Console::getAll()
{

  return this->_ctrl.findAll();
}

vector<Car> Console::findBrand(string brand)
{
  return this->_ctrl.findBrand(brand);
}

vector<Car> Console::findModel(string model)
{
  return this->_ctrl.findModel(model);
}

vector<Car> Console::findBrandAndModel(string brand, string model)
{
  return this->_ctrl.findBrandAndModel(brand, model);
}

vector<Car> Console::filterByAge(int age)
{
  return this->_ctrl.filterByAge(age);
}

vector<Car> Console::filterByKilometers(int kilometers)
{
  return this->_ctrl.filterByKilometers(kilometers);
}
vector<Car> Console::filterByAgeAndKilometers(int age, int kilometers)
{
  return this->_ctrl.filterByAgeAndKilometers(age, kilometers);
}

vector<Car> Console::sortByPrice()
{
  return this->_ctrl.sortByPrice();
}