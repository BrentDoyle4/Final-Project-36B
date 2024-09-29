#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

#include "ecs36b_Common.h"
#include "ecs36b_Exception.h"

using namespace std;

class GPS_DD
{
 private:
  string place;
 public:
  explicit GPS_DD();
  explicit GPS_DD(string);
  string getPlace();
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif