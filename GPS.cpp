#include "GPS.h"

GPS_DD::GPS_DD()
{
  this->place = "";
}

GPS_DD::GPS_DD(string arg_place)
{
  this->place = arg_place;
}

string 
GPS_DD::getPlace()
{
  return this->place;
}

Json::Value
GPS_DD::dump2JSON
()
{
  Json::Value result;
    result["place"] = this->place;

#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}

bool
GPS_DD::JSON2Object
(Json::Value arg_jv)
{
  ecs36b_Exception my_exception;
  my_exception.data["typeid"] = string { removeNumberPrefix(typeid(*this).name()) };
  my_exception.data["method"] = "JSON2Object";
  std::string sbuf;

  if (arg_jv.isNull() == true)
    {
      sbuf = "input is a NULL json";
      my_exception.data["message"] = sbuf;
      my_exception.data["error_code"] = EXC_ERR_INPUT_NULL;
      throw my_exception;
    }

  if (arg_jv.isObject() != true)
    {
      sbuf = "input is not a json object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_INPUT_NOT_OBJECT;
      throw my_exception;
    }

  if ((arg_jv["place"]).isNull() == true)
    {
      sbuf = "missing required attribute \"place\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }

  if ((arg_jv["place"]).isString() != true)
    {
      sbuf = "attribute \"place\" must be string";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }

  if (arg_jv.isMember("hidden") && (arg_jv["hidden"].asString() == "SOS" || arg_jv["hidden"].asString() == "HELP")) 
  {
    sbuf = "A Critical Hidden detected";
    my_exception.data["message"] = sbuf;
    my_exception.data["input"] = arg_jv;
    throw my_exception;
  }

  this->place = (arg_jv["place"]).asString();
  
  return true;
}