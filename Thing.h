#ifndef _THING_H_
#define _THING_H_

// Thing.h

#include "Person.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Exception.h"

class Thing
{
 private:
 protected:
 public:
  
  std::string type;
  std::string size;
  Person      owner;
  
  Thing(void);
  Thing(Person arg_owner);
  virtual Json::Value dump2JSON();
  virtual bool JSON2Object(Json::Value);
};

#endif /* _THING_H_ */