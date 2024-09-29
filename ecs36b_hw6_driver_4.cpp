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
    char d[256];
    char *d_ptr = d;
    snprintf(d, 64,"JSON_Record4.json");
    myFile2JSON(d_ptr, &x);
    Record r4;
    bool d1 = r4.JSON2Object2(x);
    if (d1 == true) {
        y = r4.dump2JSON2();
        std::cout << y.toStyledString() << std::endl;
    }

    return 0;
}