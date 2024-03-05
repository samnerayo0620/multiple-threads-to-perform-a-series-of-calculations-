
/*
 @file: pthreads_p2.cpp

 @author: Samuel Nerayo, snerayo@seattleu.edu

 @description: A program that uses multiple threads to perform a series of calculations on the same data.

 @course: CPSC 3500
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int numbers[10];

// This function shows the skeleton that pthread
// functions must adhere to.
// Copy this skeleton for any pthread function
// you need to define.
// In the copy, modify the name of the function
// and the function body as needed.

// This function will Count and print out how many of the entered numbers are negative
void *countNegatives(void *arg) {
    int count;
    for(int i = 0; i < 10; i++)
    {
        if (numbers[i] < 0)
            count++;
    }
    cout <<"\nTotal negative numbers: "<< count << endl;
    return 0;
}
// This function will calculate and print the average value of all the numbers entered
void *average(void *arg) {
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += numbers[i];
    cout << "\nAverage: " << (double) sum / 10 <<endl;
    return 0;
}
// This function will Print the numbers in reverse order from the order in which they were entered.
void *reverse(void *arg) {
    cout <<"\nThe numbers in reverse: " <<endl;
    for(int i = 9; i >= 0; i--)
        cout<< numbers[i] << " " << endl;
    return 0;
}

int main() {
    // id is used to store a unique thread identifier,
    // returned by the call to create a new POSIX thread
    pthread_t id1,id2,id3;

    // rc is used to store the code returned by the
    // call to create a new POSIX thread. The value is
    // zero (0) if the call succeeds.
    int rc;

    // Reads the input integers and store in array
    cout << "Enter a 10 integers " << endl;
    for(int i = 0; i < 10; i++){
        cin >> numbers[i]; // store numbers in index i
    }

    rc = pthread_create(&id1, NULL, countNegatives, NULL);
    // will add a small delay in between creating the next thread
    sleep(1);
    if (rc){
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }

    rc = pthread_create(&id2, NULL, average, NULL);
    // will add a small delay in between creating the next thread
    sleep(1);
    if (rc){
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }

    rc = pthread_create(&id3, NULL, reverse, NULL);
    // will add a small delay in between creating the next thread
    sleep(1);
    if (rc){
        cout << "ERROR; return code from pthread_create() is " << rc << endl;
        return -1;
    }
    // NOTE: Using exit here will immediately end execution of all threads
    pthread_exit(0);
}


