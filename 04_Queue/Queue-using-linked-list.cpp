#include <iostream>
#include <stdexcept>
using namespace std;

class ListNode
{
public:
    int val_;

    ListNode *next = nullptr;

    ListNode(int val)
    {
        val_ = val;
    }
};

class Queue
{
private:
    ListNode *right = nullptr;
    ListNode *left = nullptr;

public:
    Queue()
    {
        left = new ListNode(-1);
        right = left;
    }

    void enqueue(int value)
    {
        right->next = new ListNode(value);
        right = right->next;
        right->next = nullptr;
    }

    int dequeue()
    {
        if (left->next == nullptr)
            throw out_of_range("Queue is empty!");
        ListNode *temp = left->next;
        int val = temp->val_;
        left->next = left->next->next;

        if (left->next == nullptr)
        {
            right = left;
        }
        delete temp;
        return val;
    }

    void print()
    {
        ListNode *curr = left->next;
        while (curr != nullptr)
        {
            cout << curr->val_ << " ";
            curr = curr->next;
        }
        cout<< endl;
    }

    ~Queue()
    {
        ListNode *curr = left;
        while (curr != nullptr)
        {
            ListNode *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    cout << "Queue contents: ";
    q1.print();

    cout << "Dequeued: " << q1.dequeue() << endl;
    cout << "Queue after dequeue: ";
    q1.print();

    return 0;
}