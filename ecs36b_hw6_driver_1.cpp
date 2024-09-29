#include "Person.h"
#include "GPS.h"
#include "Thing.h"
#include "Record.h"
#include "JvTime.h"

int
main(int argc, char *argv[])
{
    // if (argc != 3) return -1;

    Json::Value x;
    Json::Value y;
    char a[256];
    char *a_ptr = a;
    snprintf(a, 64,"JSON_Record1.json");
    myFile2JSON(a_ptr, &x);
    Record r1;
    bool a1 = r1.JSON2Object1(x);
    if (a1 == true){
        y = r1.dump2JSON1();
        std::cout << y.toStyledString() << std::endl;
    }

    return 0;
}