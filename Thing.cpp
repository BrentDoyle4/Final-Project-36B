#include "Thing.h"

Thing::Thing
(void)
{
  this->type = "";
  this->size = "";
}

Thing::Thing
(Person arg_owner)
{
  this->type = "";
  this->size = "";
  this->owner = arg_owner;
}

Json::Value
Thing::dump2JSON
()
{
    Json::Value result;
    result["type"] = this->type;
    result["size"] = this->size;
  
    #ifdef _ECS36B_DEBUG_
        std::cout << result.toStyledString() << std::endl;
    #endif /* _ECS36B_DEBUG_ */
    return result;
}

bool
Thing::JSON2Object
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

  if ((arg_jv["type"]).isNull() == true)
    {
      sbuf = "missing required attribute \"type\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }

  if ((arg_jv["type"]).isString() != true)
    {
      sbuf = "attribute \"type\" must be string";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["size"]).isNull() == true)
    {
      sbuf = "missing required attribute \"size\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }

  if ((arg_jv["size"]).isString() != true)
    {
      sbuf = "attribute \"size\" must be string";
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

  this->type = (arg_jv["type"]).asString();
  this->size = (arg_jv["size"]).asString();

  return true;
}