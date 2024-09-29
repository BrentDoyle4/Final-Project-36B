// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

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
    FILE *fa = NULL;
    char a[256];
    char *a_ptr = a;
    snprintf(a, 64, "JSON_Record1.json");
    fa = fopen(a_ptr, "w");
    Record r1 {Time1, gps_Classroom_UCDavis, Felix, Phone};
    x = r1.dump2JSON1();
    if (fa != NULL)
	    {
	      myJSON2File(a_ptr, &x);
	    }
	  else
	    {
	      printf(" can not open %s\n", a_ptr);
	      exit(1);
	    }
    fclose(fa);

    FILE *fb = NULL;
    char b[256];
    char *b_ptr = b;
    snprintf(b, 64,"JSON_Record2.json");
    fb = fopen(b_ptr, "w");
    Record r2 {Time2, gps_Silo_station, Felix, Tiffany, John, Phone, Bus, Computer};
    x = r2.dump2JSON3();
    if (fb != NULL)
	    {
	      myJSON2File(b_ptr, &x);
	    }
	  else
	    {
	      printf(" can not open %s\n", b_ptr);
	      exit(1);
	    }
    fclose(fb);

    FILE *fc = NULL;
    char c[256];
    char *c_ptr = c;
    snprintf(c, 64,"JSON_Record3.json");
    fc = fopen(c_ptr, "w");
    Record r3 {Time3, gps_8th_and_J_Street, Felix, Tiffany, John, Phone, Bus, Computer};
    x = r3.dump2JSON3();
    if (fc != NULL)
	    {
	      myJSON2File(c_ptr, &x);
	    }
	  else
	    {
	      printf(" can not open %s\n", c_ptr);
	      exit(1);
	    }
    fclose(fc);

    FILE *fd = NULL;
    char d[256];
    char *d_ptr = d;
    snprintf(d, 64,"JSON_Record4.json");
    fd = fopen(d_ptr, "w");
    Record r4 {Time4, gps_Moore_and_Pollock, Felix, Tiffany, Phone, Bus};
    x = r4.dump2JSON2();
    if (fd != NULL)
	    {
	      myJSON2File(d_ptr, &x);
	    }
	  else
	    {
	      printf(" can not open %s\n", d_ptr);
	      exit(1);
	    }
    fclose(fd);

    return 0;
}