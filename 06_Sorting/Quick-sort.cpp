#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &arr, int s, int e)
{
    // Base condition
    if (s >= e)
        return;

    int pivot = e; 
    int a = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] <= arr[pivot])
        {
            swap(arr[a], arr[i]);
            a++;
        }
    }

    swap(arr[a], arr[pivot]);

    quickSort(arr, s, a - 1); // Left
    quickSort(arr, a + 1, e); // Right
}

int main()
{
    vector<int> arr = {6, 2, 4, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}