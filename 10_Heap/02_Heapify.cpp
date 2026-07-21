//  To make a heap out of a random array

#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
    vector<int> heap_;
    Heap()
    {
        heap_.push_back(0);
    }

    void heapify(vector<int> &arr)
    {
        // 1. Safely copy elements into heap_ with a dummy node at index 0
        heap_.clear();
        heap_.push_back(0);
        heap_.insert(heap_.end(), arr.begin(), arr.end());

        // 2. Start at the last parent node and work backwards
        int curr = (heap_.size() - 1) / 2;

        while (curr > 0)
        {
            int i = curr;
            // 3. Percolate down
            while (2 * 1 < heap_.size())
            {
                int left = 2 * i;
                int right = 2 * i + 1;
                int smallest = i;

                if (left < heap_.size() && heap_[left] < heap_[smallest])
                {
                    smallest = left;
                }
                if (right < heap_.size() && heap_[right] < heap_[smallest])
                {
                    smallest = right;
                }

                if (smallest != i)
                {
                    int tmp = heap_[i];
                    heap_[i] = heap_[smallest];
                    heap_[smallest] = tmp;

                    i = smallest;
                }
                else
                {
                    break;
                }
            }
            curr--;
        }
    }
};