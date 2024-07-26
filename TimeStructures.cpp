//Header files 
#include <iostream>
#include <algorithm> //sort
using namespace std;

//Struct with member variables
struct TimeType {

        int hour;
        int min;
};

//Function prototypes
int toMinutes(TimeType timeA);
TimeType toTime(int minutes);
TimeType timeDifference(TimeType timeB, TimeType timeC);
TimeType dynamicTimes();

int main() {

        //1st test examples converts hours and minutes to minutes and prints it iout 
        int minutes;
        TimeType timeA = { 10, 15 };
        minutes = toMinutes(timeA);
        cout << minutes << " minutes" << endl; // Should write: 615 minutes

        //2nd example coverts minutes to actual time and prints it out(Time in Sweden)
        int amountOfMinutes = 124;
        TimeType time = toTime(amountOfMinutes);
        cout << "Time 0" << time.hour << ":0" << time.min << endl;

        //3ird example takes two sets of hours and minutes and prints out the difference between the two
        TimeType timeB = { 10, 30 }, timeC = { 13, 20 }, difference;
        difference = timeDifference(timeB, timeC);
        cout << "Time difference 0" << difference.hour << ":" << difference.min << endl;

        //4th example shows the maximum difference between two sets of random times 
        TimeType maxDiff = dynamicTimes();
        cout << "Maxdifference is " << maxDiff.hour << ":" << maxDiff.min << endl;

        return 0;
}

//toMinutes() function converts hours to minutes and returns it 
int toMinutes(TimeType timeA) {

        return  (timeA.hour * 60) + timeA.min;
}

//toTime() function converts minutes to hours and minutes and returns it 
TimeType toTime(int amountOfMinutes) {

        TimeType time;
        time.hour = amountOfMinutes / 60; //Get hours
        time.min = amountOfMinutes % 60; //Get minutes 

        return time;
}

//timeDifference() function returns the difference between two sets of times 
TimeType timeDifference(TimeType timeB, TimeType timeC) {

        int timeBminutes = toMinutes(timeB); //Convert timeB to minutes
        int timeCminutes = toMinutes(timeC); //Convert timeC to minutes

        int amountOfMinutes = max(timeBminutes, timeCminutes) - min(timeBminutes, timeCminutes); //Get the amount of minutes bewteen the two variables 
        TimeType time = toTime(amountOfMinutes); //Covert to actual time; hours and minutes 

        return time;
}

//dynamicTimes() function returns maximum difference between two sets of randomized times 
TimeType dynamicTimes() {
        ;
        int size = 200; //Size of array
        int* times = new int[size]; //Dynamic array created and initialized 

        srand(time(0)); //Seed to use for random generator 

        //Loop through and generate 200 random numbers to use as minutes
        for (int i = 0; i < size; i++) {
                times[i] = (rand() % 200) + 1;
        }

        sort(times, times + size); //Sort array in ascending order 
        int max = times[size - 1]; //Take the maximum number from last index of array
        int min = times[0]; //Take the minimum number from first index of array

        TimeType maxTime = toTime(max); //Convert max number to hours and minutes
        TimeType minTime = toTime(min); //Convert minimum number to hours and minutes
        TimeType difference = timeDifference(maxTime, minTime); //Get the difference between the two sets of time 

        delete[] times; //deallocate memory 

        return difference;
}


