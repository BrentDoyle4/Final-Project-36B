# Makefile for hw4, s2023 quarter
#
# example: $ ./test_dump

CC 	= g++ -std=c++14
CFLAGS 	= -g -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -lcurl -ljsonrpccpp-client

# rules.
all: 		ecs36b_hw6_driver_1 ecs36b_hw6_driver_2 ecs36b_hw6_driver_3 ecs36b_hw6_driver_4

#
#
ecs36b_JSON.o:	ecs36b_JSON.cpp
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

Record.o:	Record.cpp Record.h
	$(CC) -c $(CFLAGS) Record.cpp

GPS.o:		GPS.cpp GPS.h
	$(CC) -c $(CFLAGS) GPS.cpp

JvTime.o:	JvTime.cpp JvTime.h
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp Person.h
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h
	$(CC) -c $(CFLAGS) Thing.cpp

test_dump.o:	test_dump.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) test_dump.cpp

test_DumpToFile.o:	test_DumpToFile.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) test_DumpToFile.cpp

test_FileToObject.o:	test_FileToObject.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) test_FileToObject.cpp

ecs36b_hw6_driver_1.o:	ecs36b_hw6_driver_1.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) ecs36b_hw6_driver_1.cpp

ecs36b_hw6_driver_2.o:	ecs36b_hw6_driver_2.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) ecs36b_hw6_driver_2.cpp

ecs36b_hw6_driver_3.o:	ecs36b_hw6_driver_3.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) ecs36b_hw6_driver_3.cpp

ecs36b_hw6_driver_4.o:	ecs36b_hw6_driver_4.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) ecs36b_hw6_driver_4.cpp

test_dump:	GPS.o test_dump.o Thing.o Person.o JvTime.o Record.o
	g++ -std=c++14 test_dump.o GPS.o Thing.o Person.o JvTime.o Record.o -o test_dump $(LDFLAGS)

test_DumpToFile:	GPS.o test_DumpToFile.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o
	g++ -std=c++14 test_DumpToFile.o GPS.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o -o test_DumpToFile $(LDFLAGS)

test_FileToObject:	GPS.o test_FileToObject.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o
	g++ -std=c++14 test_FileToObject.o GPS.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o -o test_FileToObject $(LDFLAGS)

ecs36b_hw6_driver_1:	GPS.o ecs36b_hw6_driver_1.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o
	g++ -std=c++14 ecs36b_hw6_driver_1.o GPS.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o -o ecs36b_hw6_driver_1 $(LDFLAGS)

ecs36b_hw6_driver_2:	GPS.o ecs36b_hw6_driver_2.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o
	g++ -std=c++14 ecs36b_hw6_driver_2.o GPS.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o -o ecs36b_hw6_driver_2 $(LDFLAGS)

ecs36b_hw6_driver_3:	GPS.o ecs36b_hw6_driver_3.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o
	g++ -std=c++14 ecs36b_hw6_driver_3.o GPS.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o -o ecs36b_hw6_driver_3 $(LDFLAGS)

ecs36b_hw6_driver_4:	GPS.o ecs36b_hw6_driver_4.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o
	g++ -std=c++14 ecs36b_hw6_driver_4.o GPS.o Thing.o Person.o JvTime.o Record.o ecs36b_JSON.o -o ecs36b_hw6_driver_4 $(LDFLAGS)

clean:
	rm -f *.o *~ core ecs36b_hw6_driver_1 ecs36b_hw6_driver_2 ecs36b_hw6_driver_3 ecs36b_hw6_driver_4