//  we are given an array to find a value in it, we can use binary search to find the value in O(logn) time complexity.
//  The array must be sorted for binary search to work.
// We will use 2-pointers for binary search.

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int L = 0;
    int R = arr.size() - 1;

    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (arr[mid] < target)
            L = mid + 1;
        else if (arr[mid] > target)
            R = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    vector<int> myArray = {1, 3, 3, 4, 5, 6, 7, 8};

    int value = binarySearch(myArray, 6);

    cout << value;
}