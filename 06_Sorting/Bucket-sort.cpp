#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void bucketSort(vector<int>& arr) {
    if (arr.empty()) return;

    // 1. Find the min and max to determine the range of values
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());

    // Edge case: If all elements are the same, it's already sorted.
    // This also prevents a division by zero later!
    if (max_val == min_val) return;

    // We typically create as many buckets as there are elements
    int bucket_count = arr.size(); 
    vector<vector<int>> buckets(bucket_count);

    // 2. SCATTER: Distribute array elements into their respective buckets
    for (int i = 0; i < arr.size(); i++) {
        // This formula normalizes the value and maps it to a bucket index
        // It ensures min_val goes to bucket 0, and max_val goes to the last bucket
        int bucket_index = (bucket_count - 1) * (arr[i] - min_val) / (max_val - min_val);
        buckets[bucket_index].push_back(arr[i]);
    }

    // 3. SORT: Sort the individual buckets
    for (int i = 0; i < bucket_count; i++) {
        // sort is highly optimized for this
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. GATHER: Put the sorted elements back into the original array
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

}

int main()
{
    vector<int> arr = {150, 932, 432, 789, 210};

    bucketSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}