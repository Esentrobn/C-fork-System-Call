#ifndef STORE_H_INCLUDED    //header file
#define STORE_H_INCLUDED

#define SIZE 256    //constant maximum size used for running the for loops, for example
#define MAX_CARS 12 //max number of cars

#define get(x) (((x) & (0xFF << 8)) >> 8)
//used in getting the exit status in the Interface from the server

typedef struct
{
    char id[8];
    int odometer;
    float gallons;
}car;
//this struct car, has the properties of the car that is id, odometer, and no. of gallons

#endif // STORE_H_INCLUDED
