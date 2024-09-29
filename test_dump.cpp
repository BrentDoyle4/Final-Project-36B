#include "Person.h"
#include "GPS.h"
#include "Thing.h"
#include "Record.h"
#include "JvTime.h"

int
main(int argc, char *argv[])
{
    // if (argc != 3) return -1;

    JvTime Time1{"2023-04-12T18:00:00+0000"};
    JvTime Time2{"2023-04-12T18:10:00+0000"};
    JvTime Time3{"2023-04-12T18:20:00+0000"};
    JvTime Time4{"2023-04-12T18:32:00+0000"};

    GPS_DD gps_Classroom_UCDavis {"Room 176 of Everson Hall" };
    GPS_DD gps_Silo_station {"The Silo Station"};
    GPS_DD gps_8th_and_J_Street {"8th and J Street Stop"};
    GPS_DD gps_Moore_and_Pollock {"Moore and Pollock Stop"};

    Person Felix {"Felix", "Instructor"};
    Person John {"John", "Student"};
    Person Tiffany {"Tiffany", "Bus Driver"};

    Thing Computer { John };
    Computer.type = "Computer";
    Computer.size = "Small";

    Thing Phone { Felix };
    Phone.type = "Android Device";
    Phone.size = "Small";

    Thing Bus { Tiffany };
    Bus.type = "Unitrans L Line Bus";
    Bus.size = "Large";

    Json::Value x;
    Record r1 {Time1, gps_Classroom_UCDavis, Felix, Phone};
    x = r1.dump2JSON1();
    std::cout << x.toStyledString() << std::endl;

    Record r2 {Time2, gps_Silo_station, Felix, Tiffany, John, Phone, Bus, Computer};
    x = r2.dump2JSON3();
    std::cout << x.toStyledString() << std::endl;

    Record r3 {Time3, gps_8th_and_J_Street, Felix, Tiffany, John, Phone, Bus, Computer};
    x = r3.dump2JSON3();
    std::cout << x.toStyledString() << std::endl;

    Record r4 {Time4, gps_Moore_and_Pollock, Felix, Tiffany, Phone, Bus};
    x = r4.dump2JSON2();
    std::cout << x.toStyledString() << std::endl;



    return 0;
}