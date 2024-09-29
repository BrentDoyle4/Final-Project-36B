#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

#include "GPS.h"
#include "JvTime.h"
#include "ecs36b_Exception.h"

class Person
{
 private:
  std::string name;
  std::string description;
   
public:
  Person(std::string, std::string);
  Person();
  std::string getName();
  std::string getDescription();
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif  /* _PERSON_H_ */