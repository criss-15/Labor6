#pragma once
#include <exception>
#include <string>
using namespace std;

class RepoError : public exception
{
private:
  string msg;

public:
  RepoError(const string &);
  const string &get_msg() const;
};