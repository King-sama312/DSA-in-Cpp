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

    void removeEnd()
    {
        if (head->next == nullptr)
            return;
        ListNode *curr = head;
        while (curr->next != tail)
        {
            curr = curr->next;
        }
        delete tail;
        curr->next = nullptr;
        tail = curr;
    }

    void removeByIndex(int index) {
    ListNode* curr = head;
    
    for (int i = 0; i < index && curr->next != nullptr; i++) {
        curr = curr->next;
    }

    if (curr->next != nullptr) {
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        
        // Special case: if we deleted the actual tail, 
        // we must move the tail pointer back to curr!
        if (temp == tail) {
            tail = curr;
        }

        delete temp; 
    }
}
    void print()
    {
        ListNode *curr = head->next;
        while (curr != nullptr)
        {
            cout << curr->val_ << " ";
            curr = curr->next;
        }
    }

    ~LinkedList(){
        ListNode*curr = head;
        while(curr != nullptr){
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
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

    return 0;
}