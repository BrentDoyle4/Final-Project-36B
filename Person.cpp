#include "Person.h"

Person::Person(std::string name, std::string description)
{
  this->name = name;
  this->description = description;
}

Person::Person()
{
  this->name = "";
  this->description = "";
}

std::string
Person::getName()
{
  return this->name;
}

std::string
Person::getDescription()
{
  return this->description;
}

Json::Value
Person::dump2JSON
()
{
  Json::Value result;
    result["name"] = this->name;
    result["description"] = this->description;

#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}

bool
Person::JSON2Object
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

  if ((arg_jv["name"]).isNull() == true)
    {
      sbuf = "missing required attribute \"name\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }

  if ((arg_jv["name"]).isString() != true)
    {
      sbuf = "attribute \"name\" must be string";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["description"]).isNull() == true)
    {
      sbuf = "missing required attribute \"description\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }

  if ((arg_jv["description"]).isString() != true)
    {
      sbuf = "attribute \"description\" must be string";
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

  this->name = (arg_jv["name"]).asString();
  this->description = (arg_jv["description"]).asString();

  return true;
}