#ifndef _RECORD_H_
#define _RECORD_H_

// Record.h

#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"
#include "ecs36b_Exception.h"

class Record
{
 private:
    JvTime when;
    GPS_DD where;
    Person who_1;
    Person who_2;
    Person who_3;
    Thing thing_1;
    Thing thing_2;
    Thing thing_3;
  
public:
  Record(JvTime, GPS_DD, Person, Thing);
  Record(JvTime, GPS_DD, Person, Person, Thing, Thing);
  Record(JvTime, GPS_DD, Person, Person, Person, Thing, Thing, Thing);
  Record();
    virtual Json::Value dump2JSON1();
    virtual Json::Value dump2JSON2();
    virtual Json::Value dump2JSON3();
    virtual bool JSON2Object1(Json::Value);
    virtual bool JSON2Object2(Json::Value);
    virtual bool JSON2Object3(Json::Value);

};

#endif  /* _RECORD_H_ */