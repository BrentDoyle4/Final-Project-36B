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

    char c[256];
    char *c_ptr = c;
    snprintf(c, 64,"JSON_Record3.json");
    myFile2JSON(c_ptr, &x);
    Record r3;
    bool c1 = r3.JSON2Object3(x);
    if (c1 == true) {
        y = r3.dump2JSON3();
        std::cout << y.toStyledString() << std::endl;
    }

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