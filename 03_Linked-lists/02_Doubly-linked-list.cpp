#include <iostream>
using namespace std;

class ListNode
{
public:
    int val_;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;

    ListNode(int value)
    {
        val_ = value;
    }
};

class DoublyLinkedList
{
public:
    ListNode *head;
    ListNode *tail;

    DoublyLinkedList()
    {
        head = new ListNode(-1);
        tail = head;
    }

    void insertEnd(int n)
    {
        tail->next = new ListNode(n);
        tail->next->prev = tail;
        tail = tail->next;
    }

    void removeEnd()
    {
        if (head->next == nullptr)
            return;
        ListNode *secondLastNode;
        secondLastNode = tail->prev;
        secondLastNode->next = nullptr;
        delete tail;
        tail = secondLastNode;
    }

    void removeByIndex(int index)
    {
        ListNode *curr = head;

        for (int i = 0; i < index && curr->next != nullptr; i++)
        {
            curr = curr->next;
        }

        if (curr->next != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = temp->next;

            // CRITICAL CHECK: Only update 'prev' if there IS a next node
            if (temp->next != nullptr)
            {
                temp->next->prev = curr;
            }

            if (temp == tail)
            {
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

    ~DoublyLinkedList()
    {
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkedList doublyList;
    doublyList.insertEnd(10);
    doublyList.insertEnd(20);
    doublyList.insertEnd(30);

    doublyList.removeByIndex(1);

    doublyList.print();

    return 0;
}