/*
Author: Mihriban Guneydas
Instructions:This code compiled and run on VS Code, with
Please run this code on VS Code with C/C++ v1.7.1(by Microsoft), Code Runner v0.11.6(by Jun Han) extensions
References: https://www.programiz.com/dsa/counting-sort*/

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void countSort(int array[], int size) {
    // The size of count must be at least the (max+1) but
    // we cannot assign declare it as int count(max+1) in C++ as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int output[100000];
    int count[100000];
    int max = array[0];
    // Find the largest element of the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }
    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}
// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
// Driver code
int main() {
    string filename("AscendingOrder.txt");
    int number;
    int arr[100000];
    int i = 0;
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    while (input_file >> number) {
        //cout << number << "; ";
        arr[i] = number;
        ++i;
    }
    cout << endl;
    input_file.close();
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start = clock();
    countSort(arr, 100000);
    clock_t finish = clock();
    double doneTime = double(finish - start) / double(CLOCKS_PER_SEC / 1000);
    //cout << "\nSorted array is \n";
    //printArray(arr, 100000);
    cout << endl <<"Counting sort for ascending order numbers takes "<< doneTime * 1000.0 << " milliseconds" << endl;
    return 0;
}
