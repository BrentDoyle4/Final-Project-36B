// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

#include "Record.h"

Record::Record(JvTime _jt, GPS_DD _g, Person _p, Thing _t)
{
  this->when = _jt;
  this->where = _g;
  this->who_1 = _p;
  this->thing_1 = _t;
}

Record::Record(JvTime _jt, GPS_DD _g, Person _p1, Person _p2, Thing _t1, Thing _t2)
{
  this->when = _jt;
  this->where = _g;
  this->who_1 = _p1;
  this->who_2 = _p2;
  this->thing_1 = _t1;
  this->thing_2 = _t2;
}

Record::Record(JvTime _jt, GPS_DD _g, Person _p1, Person _p2, Person _p3, Thing _t1, Thing _t2, Thing _t3)
{
  this->when = _jt;
  this->where = _g;
  this->who_1 = _p1;
  this->who_2 = _p2;
  this->who_3 = _p3;
  this->thing_1 = _t1;
  this->thing_2 = _t2;
  this->thing_3 = _t3;
}

Record::Record()
{
}

Json::Value
Record::dump2JSON1()
{
  Json::Value result;
  result["when"] = (this->when).dump2JSON();
  result["where"] = (this->where).dump2JSON();
  result["who_1"] = (this->who_1).dump2JSON();
  result["thing_1"] = (this->thing_1).dump2JSON();
  return result;
}

Json::Value
Record::dump2JSON2()
{
  Json::Value result;
    result["when"] = (this->when).dump2JSON();
    result["where"] = (this->where).dump2JSON();
    result["who_1"] = (this->who_1).dump2JSON();
    result["who_2"] = (this->who_2).dump2JSON();
    result["thing_1"] = (this->thing_1).dump2JSON();
    result["thing_2"] = (this->thing_2).dump2JSON();
  return result;
}

Json::Value
Record::dump2JSON3()
{
  Json::Value result;
  result["when"] = (this->when).dump2JSON();
  result["where"] = (this->where).dump2JSON();
  result["who_1"] = (this->who_1).dump2JSON();
  result["who_2"] = (this->who_2).dump2JSON();
  result["who_3"] = (this->who_3).dump2JSON();
  result["thing_1"] = (this->thing_1).dump2JSON();
  result["thing_2"] = (this->thing_2).dump2JSON();
  result["thing_3"] = (this->thing_3).dump2JSON();
  return result;
}


bool
Record::JSON2Object1
(Json::Value arg_jv)
{
bool br;


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

  if ((arg_jv["when"]).isNull() == true)
    {
      sbuf = "missing required attribute \"when\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["where"]).isNull() == true)
    {
      sbuf = "missing required attribute \"where\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["who_1"]).isNull() == true)
    {
      sbuf = "missing required attribute \"who_1\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["thing_1"]).isNull() == true)
    {
      sbuf = "missing required attribute \"thing_1\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["when"]).isObject() != true)
    {
      sbuf = "attribute \"when\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["where"]).isObject() != true)
    {
      sbuf = "attribute \"where\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["who_1"]).isObject() != true)
    {
      sbuf = "attribute \"who_1\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["thing_1"]).isObject() != true)
    {
      sbuf = "attribute \"thing_1\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if (((arg_jv["when"])["time"]).isNull() == true)
    {
      sbuf = "missing required attribute \"time\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["where"])["place"]).isNull() == true)
    {
      sbuf = "missing required attribute \"place\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_1"])["name"]).isNull() == true)
    {
      sbuf = "missing required attribute \"name\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_1"])["description"]).isNull() == true)
    {
      sbuf = "missing required attribute \"description\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_1"])["type"]).isNull() == true)
    {
      sbuf = "missing required attribute \"type\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_1"])["size"]).isNull() == true)
    {
      sbuf = "missing required attribute \"size\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (arg_jv.isMember("hidden") && (arg_jv["hidden"].asString() == "SOS" || arg_jv["hidden"].asString() == "HELP")) 
  {
    sbuf = "A Critical Hidden detected";
    my_exception.data["message"] = sbuf;
    my_exception.data["input"] = arg_jv;
    throw my_exception;
  }
  


  if ((((arg_jv["when"])["time"]).isString() == true))
      {
        JvTime *lv_J_ptr = new JvTime();
        br = lv_J_ptr->JSON2Object(arg_jv["when"]);
        if (br == false) return false;
        ((JvTime&) this->when) = *lv_J_ptr;
      }
  if ((((arg_jv["where"])["place"]).isString() == true))
        {
          GPS_DD *lv_G_ptr = new GPS_DD();
          br = lv_G_ptr->JSON2Object(arg_jv["where"]);
          if (br == false) return false;
          ((GPS_DD&) this->where) = *lv_G_ptr;
        }  
  if ((((arg_jv["who_1"])["name"]).isString() == true))
        {
          Person *lv_W1_ptr = new Person();
          br = lv_W1_ptr->JSON2Object(arg_jv["who_1"]);
          if (br == false) return false;
          ((Person&) this->who_1) = *lv_W1_ptr;
        } 
  if ((((arg_jv["who_1"])["description"]).isString() == true))
        {
          Person *lv_W1_ptr = new Person();
          br = lv_W1_ptr->JSON2Object(arg_jv["who_1"]);
          if (br == false) return false;
          ((Person&) this->who_1) = *lv_W1_ptr;
        }  
  if ((((arg_jv["thing_1"])["type"]).isString() == true))
        {
          Thing *lv_T1_ptr = new Thing();
          br = lv_T1_ptr->JSON2Object(arg_jv["thing_1"]);
          if (br == false) return false;
          ((Thing&) this->thing_1) = *lv_T1_ptr;
        }  
  if ((((arg_jv["thing_1"])["size"]).isString() == true))
        {
          Thing *lv_T1_ptr = new Thing();
          br = lv_T1_ptr->JSON2Object(arg_jv["thing_1"]);
          if (br == false) return false;
          ((Thing&) this->thing_1) = *lv_T1_ptr;
        }  

  return true;
}

bool
Record::JSON2Object2
(Json::Value arg_jv)
{
bool br;

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
  if ((arg_jv["when"]).isNull() == true)
    {
      sbuf = "missing required attribute \"when\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["where"]).isNull() == true)
    {
      sbuf = "missing required attribute \"where\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["who_1"]).isNull() == true)
    {
      sbuf = "missing required attribute \"who_1\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["thing_1"]).isNull() == true)
    {
      sbuf = "missing required attribute \"thing_1\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["who_2"]).isNull() == true)
    {
      sbuf = "missing required attribute \"who_2\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["thing_2"]).isNull() == true)
    {
      sbuf = "missing required attribute \"thing_2\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["when"]).isObject() != true)
    {
      sbuf = "attribute \"when\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["where"]).isObject() != true)
    {
      sbuf = "attribute \"where\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["who_1"]).isObject() != true)
    {
      sbuf = "attribute \"who_1\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["thing_1"]).isObject() != true)
    {
      sbuf = "attribute \"thing_1\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["who_2"]).isObject() != true)
    {
      sbuf = "attribute \"who_2\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["thing_2"]).isObject() != true)
    {
      sbuf = "attribute \"thing_2\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if (((arg_jv["when"])["time"]).isNull() == true)
    {
      sbuf = "missing required attribute \"time\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["where"])["place"]).isNull() == true)
    {
      sbuf = "missing required attribute \"place\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_1"])["name"]).isNull() == true)
    {
      sbuf = "missing required attribute \"name\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_1"])["description"]).isNull() == true)
    {
      sbuf = "missing required attribute \"description\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_1"])["type"]).isNull() == true)
    {
      sbuf = "missing required attribute \"type\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_1"])["size"]).isNull() == true)
    {
      sbuf = "missing required attribute \"size\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_2"])["name"]).isNull() == true)
    {
      sbuf = "missing required attribute \"name\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_2"])["description"]).isNull() == true)
    {
      sbuf = "missing required attribute \"description\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_2"])["type"]).isNull() == true)
    {
      sbuf = "missing required attribute \"type\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_2"])["size"]).isNull() == true)
    {
      sbuf = "missing required attribute \"size\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (arg_jv.isMember("hidden") && (arg_jv["hidden"].asString() == "SOS" || arg_jv["hidden"].asString() == "HELP")) 
  {
    sbuf = "A Critical Hidden detected";
    my_exception.data["message"] = sbuf;
    my_exception.data["input"] = arg_jv;
    throw my_exception;
  }
  


  if ((((arg_jv["when"])["time"]).isString() == true))
      {
        JvTime *lv_J_ptr = new JvTime();
        br = lv_J_ptr->JSON2Object(arg_jv["when"]);
        if (br == false) return false;
        ((JvTime&) this->when) = *lv_J_ptr;
      }
  if ((((arg_jv["where"])["place"]).isString() == true))
        {
          GPS_DD *lv_G_ptr = new GPS_DD();
          br = lv_G_ptr->JSON2Object(arg_jv["where"]);
          if (br == false) return false;
          ((GPS_DD&) this->where) = *lv_G_ptr;
        }  
  if ((((arg_jv["who_1"])["name"]).isString() == true))
        {
          Person *lv_W1_ptr = new Person();
          br = lv_W1_ptr->JSON2Object(arg_jv["who_1"]);
          if (br == false) return false;
          ((Person&) this->who_1) = *lv_W1_ptr;
        } 
  if ((((arg_jv["who_1"])["description"]).isString() == true))
        {
          Person *lv_W1_ptr = new Person();
          br = lv_W1_ptr->JSON2Object(arg_jv["who_1"]);
          if (br == false) return false;
          ((Person&) this->who_1) = *lv_W1_ptr;
        }  
  if ((((arg_jv["who_2"])["name"]).isString() == true))
        {
          Person *lv_W2_ptr = new Person();
          br = lv_W2_ptr->JSON2Object(arg_jv["who_2"]);
          if (br == false) return false;
          ((Person&) this->who_2) = *lv_W2_ptr;
        } 
  if ((((arg_jv["who_2"])["description"]).isString() == true))
        {
          Person *lv_W2_ptr = new Person();
          br = lv_W2_ptr->JSON2Object(arg_jv["who_2"]);
          if (br == false) return false;
          ((Person&) this->who_2) = *lv_W2_ptr;
        }  
  if ((((arg_jv["thing_1"])["type"]).isString() == true))
        {
          Thing *lv_T1_ptr = new Thing();
          br = lv_T1_ptr->JSON2Object(arg_jv["thing_1"]);
          if (br == false) return false;
          ((Thing&) this->thing_1) = *lv_T1_ptr;
        }  
  if ((((arg_jv["thing_1"])["size"]).isString() == true))
        {
          Thing *lv_T1_ptr = new Thing();
          br = lv_T1_ptr->JSON2Object(arg_jv["thing_1"]);
          if (br == false) return false;
          ((Thing&) this->thing_1) = *lv_T1_ptr;
        }  
  if ((((arg_jv["thing_2"])["type"]).isString() == true))
        {
          Thing *lv_T2_ptr = new Thing();
          br = lv_T2_ptr->JSON2Object(arg_jv["thing_2"]);
          if (br == false) return false;
          ((Thing&) this->thing_2) = *lv_T2_ptr;
        }  
  if ((((arg_jv["thing_2"])["size"]).isString() == true))
        {
          Thing *lv_T2_ptr = new Thing();
          br = lv_T2_ptr->JSON2Object(arg_jv["thing_2"]);
          if (br == false) return false;
          ((Thing&) this->thing_2) = *lv_T2_ptr;
        } 

  return true;
}

bool
Record::JSON2Object3
(Json::Value arg_jv)
{
bool br;

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
  if ((arg_jv["when"]).isNull() == true)
    {
      sbuf = "missing required attribute \"when\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["where"]).isNull() == true)
    {
      sbuf = "missing required attribute \"where\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["who_1"]).isNull() == true)
    {
      sbuf = "missing required attribute \"who_1\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["thing_1"]).isNull() == true)
    {
      sbuf = "missing required attribute \"thing_1\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["who_2"]).isNull() == true)
    {
      sbuf = "missing required attribute \"who_2\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["thing_2"]).isNull() == true)
    {
      sbuf = "missing required attribute \"thing_2\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["who_3"]).isNull() == true)
    {
      sbuf = "missing required attribute \"who_3\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["thing_3"]).isNull() == true)
    {
      sbuf = "missing required attribute \"thing_3\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if ((arg_jv["when"]).isObject() != true)
    {
      sbuf = "attribute \"when\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["where"]).isObject() != true)
    {
      sbuf = "attribute \"where\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["who_1"]).isObject() != true)
    {
      sbuf = "attribute \"who_1\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["thing_1"]).isObject() != true)
    {
      sbuf = "attribute \"thing_1\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["who_2"]).isObject() != true)
    {
      sbuf = "attribute \"who_2\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["thing_2"]).isObject() != true)
    {
      sbuf = "attribute \"thing_2\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["who_3"]).isObject() != true)
    {
      sbuf = "attribute \"who_3\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if ((arg_jv["thing_3"]).isObject() != true)
    {
      sbuf = "attribute \"thing_3\" must be object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }
  if (((arg_jv["when"])["time"]).isNull() == true)
    {
      sbuf = "missing required attribute \"time\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["where"])["place"]).isNull() == true)
    {
      sbuf = "missing required attribute \"place\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_1"])["name"]).isNull() == true)
    {
      sbuf = "missing required attribute \"name\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_1"])["description"]).isNull() == true)
    {
      sbuf = "missing required attribute \"description\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_1"])["type"]).isNull() == true)
    {
      sbuf = "missing required attribute \"type\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_1"])["size"]).isNull() == true)
    {
      sbuf = "missing required attribute \"size\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_2"])["name"]).isNull() == true)
    {
      sbuf = "missing required attribute \"name\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_2"])["description"]).isNull() == true)
    {
      sbuf = "missing required attribute \"description\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_2"])["type"]).isNull() == true)
    {
      sbuf = "missing required attribute \"type\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_2"])["size"]).isNull() == true)
    {
      sbuf = "missing required attribute \"size\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_3"])["name"]).isNull() == true)
    {
      sbuf = "missing required attribute \"name\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["who_3"])["description"]).isNull() == true)
    {
      sbuf = "missing required attribute \"description\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_3"])["type"]).isNull() == true)
    {
      sbuf = "missing required attribute \"type\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (((arg_jv["thing_3"])["size"]).isNull() == true)
    {
      sbuf = "missing required attribute \"size\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }
  if (arg_jv.isMember("hidden") && (arg_jv["hidden"].asString() == "SOS" || arg_jv["hidden"].asString() == "HELP")) 
  {
    sbuf = "A Critical Hidden detected";
    my_exception.data["message"] = sbuf;
    my_exception.data["input"] = arg_jv;
    throw my_exception;
  }

  if ((((arg_jv["when"])["time"]).isString() == true))
      {
        JvTime *lv_J_ptr = new JvTime();
        br = lv_J_ptr->JSON2Object(arg_jv["when"]);
        if (br == false) return false;
        ((JvTime&) this->when) = *lv_J_ptr;
      }
  if ((((arg_jv["where"])["place"]).isString() == true))
        {
          GPS_DD *lv_G_ptr = new GPS_DD();
          br = lv_G_ptr->JSON2Object(arg_jv["where"]);
          if (br == false) return false;
          ((GPS_DD&) this->where) = *lv_G_ptr;
        }  
  if ((((arg_jv["who_1"])["name"]).isString() == true))
        {
          Person *lv_W_ptr = new Person();
          br = lv_W_ptr->JSON2Object(arg_jv["who_1"]);
          if (br == false) return false;
          ((Person&) this->who_1) = *lv_W_ptr;
        } 
  if ((((arg_jv["who_1"])["description"]).isString() == true))
        {
          Person *lv_T_ptr = new Person();
          br = lv_T_ptr->JSON2Object(arg_jv["who_1"]);
          if (br == false) return false;
          ((Person&) this->who_1) = *lv_T_ptr;
        }  
  if ((((arg_jv["who_2"])["name"]).isString() == true))
        {
          Person *lv_W_ptr = new Person();
          br = lv_W_ptr->JSON2Object(arg_jv["who_2"]);
          if (br == false) return false;
          ((Person&) this->who_2) = *lv_W_ptr;
        } 
  if ((((arg_jv["who_2"])["description"]).isString() == true))
        {
          Person *lv_T_ptr = new Person();
          br = lv_T_ptr->JSON2Object(arg_jv["who_2"]);
          if (br == false) return false;
          ((Person&) this->who_2) = *lv_T_ptr;
        }  
  if ((((arg_jv["who_3"])["name"]).isString() == true))
        {
          Person *lv_W_ptr = new Person();
          br = lv_W_ptr->JSON2Object(arg_jv["who_3"]);
          if (br == false) return false;
          ((Person&) this->who_3) = *lv_W_ptr;
        } 
  if ((((arg_jv["who_3"])["description"]).isString() == true))
        {
          Person *lv_T_ptr = new Person();
          br = lv_T_ptr->JSON2Object(arg_jv["who_3"]);
          if (br == false) return false;
          ((Person&) this->who_3) = *lv_T_ptr;
        }  
  if ((((arg_jv["thing_1"])["type"]).isString() == true))
        {
          Thing *lv_T_ptr = new Thing();
          br = lv_T_ptr->JSON2Object(arg_jv["thing_1"]);
          if (br == false) return false;
          ((Thing&) this->thing_1) = *lv_T_ptr;
        }  
  if ((((arg_jv["thing_1"])["size"]).isString() == true))
        {
          Thing *lv_T_ptr = new Thing();
          br = lv_T_ptr->JSON2Object(arg_jv["thing_1"]);
          if (br == false) return false;
          ((Thing&) this->thing_1) = *lv_T_ptr;
        }  
  if ((((arg_jv["thing_2"])["type"]).isString() == true))
        {
          Thing *lv_T_ptr = new Thing();
          br = lv_T_ptr->JSON2Object(arg_jv["thing_2"]);
          if (br == false) return false;
          ((Thing&) this->thing_2) = *lv_T_ptr;
        }  
  if ((((arg_jv["thing_2"])["size"]).isString() == true))
        {
          Thing *lv_T_ptr = new Thing();
          br = lv_T_ptr->JSON2Object(arg_jv["thing_2"]);
          if (br == false) return false;
          ((Thing&) this->thing_2) = *lv_T_ptr;
        } 
  if ((((arg_jv["thing_3"])["type"]).isString() == true))
        {
          Thing *lv_T_ptr = new Thing();
          br = lv_T_ptr->JSON2Object(arg_jv["thing_3"]);
          if (br == false) return false;
          ((Thing&) this->thing_3) = *lv_T_ptr;
        }  
  if ((((arg_jv["thing_3"])["size"]).isString() == true))
        {
          Thing *lv_T_ptr = new Thing();
          br = lv_T_ptr->JSON2Object(arg_jv["thing_3"]);
          if (br == false) return false;
          ((Thing&) this->thing_3) = *lv_T_ptr;
        } 

  return true;
}