#include <iostream>
#include <vector>
using namespace std;

// Min Heap implementation
class Heap
{
public:
    vector<int> heap_;
    Heap()
    {
        heap_.push_back(0);
    }

    void push(int val)
    {
        heap_.push_back(val);

        // Get the index of the newly inserted value
        int i = heap_.size() - 1;

        // Bubble up or percolate up
        while (i > 1 && heap_[i] < heap_[i / 2])
        {
            int tmp = heap_[i];
            heap_[i] = heap_[i / 2];
            heap_[i / 2] = tmp;
            i = i / 2;
        }
    }

    // In min heap we pop the smallest value i.e root i.e min priority
    int pop()
    {
        if (heap_.size() == 1)
            return -1;
        if (heap_.size() == 2)
        {
            int res = heap_.back();
            heap_.pop_back();
            return res;
        }

        // Move the last value to the root
        int res = heap_[1];
        heap_[1] = heap_[heap_.size() - 1];
        heap_.pop_back();

        int i = 1;
        // Perlocate down
        //  check if we have left child by checking left child's index is not out of bounds
        while ((2 * i < heap_.size()))
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i; // Assume parent is the smallest for now

            // If left child exists and is smaller than parent
            if (left < heap_.size() && heap_[left] < heap_[smallest])
            {
                smallest = left;
            }
            // If right child exists and is smaller than the current smallest
            if (right < heap_.size() && heap_[right] < heap_[smallest])
            {
                smallest = right;
            }
            // If the parent is no longer the smallest, swap and continue
            if (smallest != i)
            {
                int tmp = heap_[i];
                heap_[i] = heap_[smallest];
                heap_[smallest] = tmp;

                i = smallest; // Move down the tree
            }
            else
            {
                break; // Parent is smaller than both children
            }
        }
        return res;
    }
};
