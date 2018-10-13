#include <stdio.h>  //include appropriate libraries
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>  //for using errno
#include <sys/types.h>
#include <limits.h>
#include "store.h"  //include the header file

//fiunction prototypes
car cars[MAX_CARS];
int getMin(char id[]);
int getMax(char id[]);
float getSum(char id[]);
float getAvg(car cars[], char id[]);

int main (int argc, char *argv[])
{
	char input[SIZE];   //user input
	char output[SIZE];  //output for user
	int fdIn, fdOut, error;
	char id[9]; //stores id that user enters
	float avg;

  	fdIn = atoi(argv[1]); //convert from ascii to int
    fdOut = atoi(argv[2]);

	FILE *finput;   //get car record from this file
	finput = fopen("gasData.txt","r");

	int i;  //read input from file using fscanf
	for (i = 0; i < MAX_CARS; i++)
	{
	    //printf("In for loop reading");
		fscanf(finput, "%s %d %f", cars[i].id, &cars[i].odometer, &cars[i].gallons);
	}

    int j;  //display onto the screen
	for (j = 0; j < MAX_CARS; j++)
	{

		printf("element = %d: id = %s, odometer = %d, gallons = %.6f\n", j, cars[j].id,cars[j].odometer, cars[j].gallons);
	}

	if (argc < 2)   //if arg count <2 throws an error
	{
		printf("Error in Server. Invalid parameter\n");
		exit(1);
	}

	while(1)
	{
		error = read(fdIn, input, SIZE);
		if(error == -1 )    //throws an error if read function does not work
		{
			printf ("Error on read pipe from parent: %d\n", errno);
			exit(8);
		}

		input[error] = 0;
   		output[0] = '\0';

		if(strncmp(input, "exit", 4) == 0)  //compares user input to see if exit is entered
        {
             strcpy(output, "Server complete. \n");
        }

		else if(strncmp(input, "mpg,",4) == 0)  //compares user input only up to 4 characters
		{
			strcpy(id, &input[4]);
            avg = getAvg(cars, id); //displays average
			if(avg == -1)
				sprintf(output, "ID not found");    //otherwise id is not found
			else
				sprintf(output, "Average MPG = %f", avg);
		}
		else if(strncmp(input, "list,",5) == 0) //compares user input to see if user entered list
		{
			strcpy(id, &input[5]); //copy 1st 5 chars of user input to id

			int temp=0;
			float temp1 =0.0;
            char store[MAX_CARS];
            int k,m,n,z;    //variable declarations for for loops
            int x=0;    //keeps track of when to increment counter only if the strings match
            for(m = 0; m < MAX_CARS; m++)
            {   //printf("In the m for loop,%s\n",cars[k].id);
                if(strcmp(id, cars[m].id) == 0)
                {
                    store[x] = m;
                    x++;
                }
            }
            for(n = x; n<MAX_CARS; n++) //save element number into an array
                store[n] =-1;

            for(k = 0; k < x-1; k++)    //sorting in ascending order
            {   for(z = k+1; z < x; z++)
                {   if (cars[store[k]].odometer > cars[store[z]].odometer)
                    {
                            temp = cars[store[k]].odometer; //swap odometer
                            cars[store[k]].odometer = cars[store[z]].odometer;
                            cars[store[z]].odometer = temp;
                            //use store[z] to access the elements matching to the id user entered
                            temp1 = cars[store[k]].gallons;
                            cars[store[k]].gallons = cars[store[z]].gallons;
                            cars[store[z]].gallons = temp1;
                    }
                }
            }
            for (k = 0; k < x; k++) //print result
            {
                sprintf(output + strlen(output),"element = %d: id = %s, odometer = %d, gallons = %.6f\n", store[k], id,cars[store[k]].odometer, cars[store[k]].gallons);
            }
		}
		else    //otherwise display error msg
            strcpy(output, "Invalid command");

        error = write(fdOut, output, strlen(output));

		if (error == -1) //throws an error if write function does not work
        {
			printf( "Error while writing to parent: %d\n", errno);
            exit(9);
        }

		if (strncmp(input, "exit", 4) == 0) //exits otherwise
			exit(10);
	}
}

//this function gets the max odomenter
int getMax(char id[])
{
	int maxOdometer = 0;
    int i;
	for (i = 0; i < MAX_CARS; i++)
	{
		if(strcmp(id, cars[i].id) == 0)
		{
			if (maxOdometer < cars[i].odometer)
				maxOdometer = cars[i].odometer;
		}
	}
	return maxOdometer;
}

//this function gets the min odomenter
int getMin(char id[])
{
	int flag=0;
	int minOdometer = 999999;
    int i;
	for (i = 0; i < MAX_CARS; i++)
	{
		if(strcmp(id, cars[i].id) == 0)
		{
			flag = 1;
			if (minOdometer > cars[i].odometer)
				minOdometer = cars[i].odometer;
		}
	}

	if (!flag)
	{
		printf("Input id not found\n");
		exit(11);
	}
	return minOdometer;
}

//this function calculates the sum of the gallons
float getSum(char id[])
{
	float sum = 0;
	int i;
	for (i = 0; i < MAX_CARS; i++)
	{
		if(strcmp(id, cars[i].id) == 0)
			sum += cars[i].gallons;
	}
	return sum;
}

//this function calculates the avg and returns it
float getAvg(car cars[], char id[])
{
	int minimum = 0, maximum = 0;
	float sum = 0, avg = 0;

	minimum = getMin(id);
	maximum = getMax(id);
	sum = getSum(id);

	avg= ((float)maximum-(float)minimum) / sum;

	return avg;
}
