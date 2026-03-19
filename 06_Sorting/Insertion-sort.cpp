#include <iostream>
using namespace std;
#include <vector>

vector<int> insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && arr[j + 1] < arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {10, 34, 20, 60, 1};

    insertionSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}