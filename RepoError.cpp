#include "RepoError.h"

RepoError::RepoError(const string &_msg){
  msg = _msg;
}

const string& RepoError::get_msg() const{
  return msg;
}