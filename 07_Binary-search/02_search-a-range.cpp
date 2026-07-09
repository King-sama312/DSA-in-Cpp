// we are not given an array but a range like 1-100, then there is going to be some helper function which will tell us if the mid value is correct or not, and then we can use binary search to find the correct value.


#include <iostream>
#include<vector>
using namespace std;



// return 1 if n is too big, -1 if it's too small and 0 if it is correct
int isCorrect(int n)
{
    if (n > 10)
        return 1;
    else if (n < 10)
        return -1;
    else
        return 0;
}

int binarySearch(int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isCorrect(mid) > 0)
            high = mid - 1;
        else if (isCorrect(mid) < 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main(){
    int value = binarySearch(1,100);

    cout <<value;

    return 0;
}