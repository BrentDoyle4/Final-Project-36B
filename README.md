# Final-Project-36B
This was my final project my ECS 36B course (Software Development &amp; Object-Oriented Programming in C++). This final project was final edition of the project we worked on throughout the whole quarter. The main spotlight is the dump2JSON, JSON2File, file2JSON, and JSON2Object. This whole project demonstrates complex concepts of OOP.

Make: Compiles all the .cpp and .h together to create an executable test file to test the classes and the information that is stored inside.  Creates executables of ecs36b_hw6_driver_1, ecs36b_hw6_driver_2, ecs36b_hw6_driver_3, and ecs36b_hw6_driver_4. Those 4 are used to test each conditon of homework 6.

make clean: Deletes all the .o files and executable files in the directory.

Thing.cpp / Thing.h:  Contains a class that holds a thing with its type and size.

Person.cpp / Person.h: Contains a class that holds a person with their name and description.

GPS.cpp / GPS.h: Contains a class that holds a location with the name of the location.

JvTime.cpp / JvTime.h: Contains a class that holds a time with the times' date and number.

Record.cpp / Record.h: Contains a class that holds the classes from JvTime, GPS, Person, and Thing.

ecs36b_JSON: JSON function given from Professor Wu used for a variety of different situations.

test_dump.cpp:  The cpp test_dump file that uses the classes from other cpp and .h files to store information and display that information. Displays the 4 JSON records to terminal.

test_DumpToFile: Uses dump2JSON function and JSON2File function to dump the 4 JSON records each into a file of their own.

test_FileToObject:  Uses file2JSON and JSON2Object functions and takes the 4 JSON record files and turns them into objects, then uses dump2JSON function to display those 4 JSON record objects to terminal.  Used to test the new part of the JSON2Object, “throw” ecs36b_exception objects.

ecs36b_hw6_driver_1: Used to test the new part of the JSON2Object, “throw” ecs36b_exception objects.

ecs36b_hw6_driver_2: Used to test the new part of the JSON2Object, “throw” ecs36b_exception objects.

ecs36b_hw6_driver_3: Used to test the new part of the JSON2Object, “throw” ecs36b_exception objects.

ecs36b_hw6_driver_4: Used to test the new part of the JSON2Object, “throw” ecs36b_exception objects.
