// Now that we have understood what arrays are
// We are going to start with Static arrays, as the name suggests, static arrays are fixed in size that means you can't change their size after initilzation

// As this repo is for DSA, we are going to learn how can we insert and remove elements in an array
// 1. Insert end  O(1)
// 2. Remove end  O(1)
// 3. Insert middle O(n)
// 4. Remove middle  O(n)

// Before we start insertion and deletion there are two things you have to understand
// First is 'capacity' of an array: The number of elements it can hold,
//  example = int arr[5], here 5 is capacity

// Second is 'length' of an array: The number of elements that are present in array
// example = int arr[5] = {1,2.3}  , Here 3 is the length of array

#include<iostream>
using namespace std;


void insertEnd(int arr[], int &length, int capacity, int value)
{
    if (length < capacity)
    {
        arr[length] = value;
        length++;
    }
}

void removeEnd(int arr[], int &length)
{
    if (length > 0)
        length--;
}

void insertMiddle(int arr[], int &length, int capacity, int index, int value){
    if(length>=capacity) return;

    for(int i = length; i>=index; i--){
        arr[i] = arr[i-1];
    }

    arr[index] = value;
    length++;
}

void removeMiddle(int arr[], int &length, int index){
    if(index>=length || index<0) return;

    for(int i =index+1; i<length; i++){
        arr[i-1] = arr[i];
    }
    length --;
}

void printArray(int arr[], int length){
    for(int i = 0; i<length; i++){
        cout<< arr[i]<<" ";
    }
}

int main(){
    int arr[5];
    int length = 0;
    int capacity = 5;

    insertEnd(arr, length, capacity, 10);
    insertEnd(arr, length, capacity, 20);
    insertEnd(arr, length, capacity, 30);
    insertEnd(arr, length, capacity, 40);

    printArray(arr, length);
}