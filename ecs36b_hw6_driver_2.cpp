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
    char b[256];
    char *b_ptr = b;
    snprintf(b, 64,"JSON_Record2.json");
    myFile2JSON(b_ptr, &x);
    Record r2;
    bool b1 = r2.JSON2Object3(x);
    if (b1 == true) {
        y = r2.dump2JSON3();
        std::cout << y.toStyledString() << std::endl;
    }

    return 0;
}