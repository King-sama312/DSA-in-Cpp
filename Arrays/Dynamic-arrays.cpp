// We will be implementing <vector> of C++ from scratch


#include <iostream>
#include <stdexcept>
using namespace std;

class Array
{
private:
    int length;
    int capacity;
    int *arr;

    void resize()
    {
        capacity = capacity * 2;
        int *newArr = new int[capacity];
        for (int i = 0; i < length; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    // Constructor
    Array(int cap = 2)
    {
        capacity = cap;
        length = 0;
        arr = new int[capacity];
    }
    // Destructor
    ~Array()
    {
        delete[] arr;
    }

    // Copy constructor
    Array(const Array &other)
    {
        this->capacity = other.capacity;
        this->length = other.length;

        this->arr = new int[capacity];

        for (int i = 0; i < length; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    // Assignment operator
    Array &operator=(const Array &other)
    {
        if (this == &other)
            return *this;
        delete[] this->arr;
        this->capacity = other.capacity;
        this->length = other.length;

        this->arr = new int[capacity];

        for (int i = 0; i < length; i++)
        {
            this->arr[i] = other.arr[i];
        }
        return *this;
    }

    void pushback(int n)
    {
        if (length >= capacity)
            resize();
        arr[length] = n;
        length++;
    }

    void popback(){
        if(length <0) return;
        length--;
    }

    void insert(int i, int value)
    {
        if (length < 0)
            return;
        if (length >= capacity)
            resize();

        for (int j = length; j > i; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[i] = value;
        length++;
    }

    void erase(int i)
    {
        if (i < 0 || i >= length)
            throw out_of_range("Out of bounds");

        for (int j = i; j < length - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        length--;
    }

    int get(int i)
    {
        if (i < 0 || i >= length)
            throw out_of_range("Out of bounds");
        else
            return arr[i];
    }

    void set(int i, int value)
    {
        if (i < 0 || i >= length)
            throw out_of_range("Out of bounds");
        arr[i] = value;
    }

    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Array a;
    Array c;
    a.pushback(10);
    a.pushback(20);
    a.pushback(30);
    a.pushback(40);
    a.pushback(50);
    
    Array b =a;
    c=b;
    a.print();
    b.popback();
    b.print();
    c.print();
    return 0;
}