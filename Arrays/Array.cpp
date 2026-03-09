//  arrays are usually fixed in size and contiguous
// Being contiguous means that the elements of an array are stored right next to each other in RAM
// For example:
// address:   1000  1001  1002
// element:     12   4      5
#include <iostream>
using namespace std;

int main()
{
    // Warning: these are just code examples, arrays of same name will conflict, if you want to run all this code then change the names to something like arr1, arr2 and so on..
    // Or you can run individually

    // Initilize an array: Here you are telling the compiler that the size of arr is 5
    int arr[5] = {1, 2, 3, 4, 5};

    // Universal initilization: SIze will automatically be decided on the number of elements, in this case it's 4
    int arr[] = {1, 2, 3, 4};

    // Partial initilzation: The first three elements will be 1,2,3 while all other remaining will be set to zero
    int arr[10] = {1, 2, 3};

    // Filling with zeros: To quickly fill all the elements with 0
    int arr[100] = {0};

    // If you want to take input from user than you would use a for loop
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter element " << i << " :";
        cin >> arr[i];
    }
}
