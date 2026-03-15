#include <iostream>
using namespace std;

class ListNode
{
public:
    int val_;
    ListNode *next = nullptr;

    // Constructor
    ListNode(int val)
    {
        val_ = val;
    }
};

class LinkedList
{
public:
    ListNode *head;
    ListNode *tail;

    LinkedList()
    {
        head = new ListNode(-1);
        tail = head;
    }

    void insertEnd(int n)
    {
        tail->next = new ListNode(n);
        tail = tail->next;
    }

    void print()
    {
        ListNode *curr = head->next;
        while(curr!= nullptr){
            cout<<curr->val_<<" ";
            curr=curr->next;
        }
    }
};

int main()
{
    LinkedList list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.print();
}