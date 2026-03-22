#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int m, int e)
{
    vector<int> L(arr.begin() + s, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + e + 1);

    int i = 0, j = 0, k = s;

    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // leftover elements
    while (i < L.size())
        arr[k++] = L[i++];

    while (j < R.size())
        arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int m = (s + e) / 2;

    mergeSort(arr, s, m);       // left
    mergeSort(arr, m + 1, e);   // right
    merge(arr, s, m, e);        // combine
}

int main(){
    
    return 0;
}