
#include "JvTime.h"
#include "string.h"

JvTime *
getNowJvTime
(void)
{
  time_t ticks; 
  ticks = time(NULL);
  struct std::tm * my_tm_ptr = gmtime(&ticks);
  JvTime * jvT_ptr = new JvTime();
  int rc = jvT_ptr->setStdTM(my_tm_ptr);
  if (rc != 0)
    {
      std::cout << "error: failed to set time!" << std::endl;
      delete jvT_ptr;
      return NULL;
    }
  return jvT_ptr;
}

JvTime::JvTime
(const char *time_str)
{
  const char zero_str[] = "0000-00-00T00:00:00+0000";    
  this->good = true;

  if ((time_str == NULL) || (strlen(time_str) != strlen(zero_str)))
    {
      this->good = false;
    }

  if (((time_str[0] < '0') || (time_str[0] > '9')) ||
      ((time_str[1] < '0') || (time_str[1] > '9')) ||
      ((time_str[2] < '0') || (time_str[2] > '9')) ||
      ((time_str[3] < '0') || (time_str[3] > '9')) ||
      (time_str[4] != '-') ||
      ((time_str[5] < '0') || (time_str[5] > '9')) ||
      ((time_str[6] < '0') || (time_str[6] > '9')) ||
      (time_str[7] != '-') ||
      ((time_str[8] < '0') || (time_str[8] > '9')) ||
      ((time_str[9] < '0') || (time_str[9] > '9')) ||
      (time_str[10] != 'T') ||
      ((time_str[11] < '0') || (time_str[11] > '9')) ||
      ((time_str[12] < '0') || (time_str[12] > '9')) ||
      (time_str[13] != ':') ||
      ((time_str[14] < '0') || (time_str[14] > '9')) ||
      ((time_str[15] < '0') || (time_str[15] > '9')) ||
      (time_str[16] != ':') ||
      ((time_str[17] < '0') || (time_str[17] > '9')) ||
      ((time_str[18] < '0') || (time_str[18] > '9')) ||
      (time_str[19] != '+') ||
      ((time_str[20] < '0') || (time_str[20] > '9')) ||
      ((time_str[21] < '0') || (time_str[21] > '9')) ||
      ((time_str[22] < '0') || (time_str[22] > '9')) ||
      ((time_str[23] < '0') || (time_str[23] > '9')))
    {
      this->good = false;
    }

  if (this->good == true)
    {
      sscanf(time_str, "%4d-%2d-%2dT%2d:%2d:%2d+%4s",
	     &(this->year), &(this->month), &(this->day),
	     &(this->hour), &(this->minute), &(this->second),
	     this->tail4);
    }
  else
    {
      sscanf(zero_str, "%4d-%2d-%2dT%2d:%2d:%2d+%4s",
	     &(this->year), &(this->month), &(this->day),
	     &(this->hour), &(this->minute), &(this->second),
	     this->tail4);
    }
  return;
}

struct std::tm *
JvTime::getStdTM
(void)
{
  struct std::tm * result = (struct std::tm *) malloc(sizeof(struct std::tm));
  bzero(result, sizeof(struct std::tm));

  result->tm_sec = this->second;
  result->tm_min = this->minute;
  result->tm_hour = this->hour;
  result->tm_mday = this->day;
  result->tm_mon = (this->month) - 1;
  result->tm_year = (this->year) - 1900;

  return result;
}

int
JvTime::setStdTM
(struct std::tm *arg_tm_ptr)
{
  if (arg_tm_ptr == NULL) return -1;

  this->second = arg_tm_ptr->tm_sec;
  this->minute = arg_tm_ptr->tm_min;
  this->hour   = arg_tm_ptr->tm_hour;
  this->day    = arg_tm_ptr->tm_mday;
  this->month  = (arg_tm_ptr->tm_mon) + 1;
  this->year   = (arg_tm_ptr->tm_year) + 1900;

  bzero(this->tail4, 16);
  snprintf(this->tail4, (strlen("0000") + 1), "0000");

  return 0;
}

std::string *
JvTime::getTimeString
(void)
{
  struct std::tm * tm_ptr = this->getStdTM();

  char buffer[128];
  bzero(buffer, 128);
  std::strftime(buffer, 32, "%Y-%m-%dT%H:%M:%S+", tm_ptr);
  snprintf(buffer, 128, "%s%s", buffer, this->tail4);
  return (new std::string(buffer));
}

bool
JvTime::operator==
(JvTime& aJT)
{
  if ((this->year == aJT.year) &&
      (this->month == aJT.month) &&
      (this->day == aJT.day) &&
      (this->hour == aJT.hour) &&
      (this->minute == aJT.minute) &&
      (this->second == aJT.second) &&
      (strncmp(this->tail4, aJT.tail4, 4) == 0))
    return true;
  else
    return false;
}

Json::Value
JvTime::dump2JSON
()
{
  Json::Value result;
  std::string *str_ptr = this->getTimeString();
  result["time"] = (*str_ptr);
  delete str_ptr;

#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */

  return result;
}

bool
JvTime::JSON2Object
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

  if ((arg_jv["time"]).isNull() == true)
    {
      sbuf = "missing required attribute \"time\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = arg_jv;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }

  if ((arg_jv["time"]).isString() != true)
    {
      sbuf = "attribute \"time\" must be string";
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

  JvTime jv_copy { ((arg_jv["time"]).asString()).c_str() };
  (*this) = jv_copy;

  return true;
}
