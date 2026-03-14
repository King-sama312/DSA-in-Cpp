// A stack is like a stack of plates; you only ever add or remove from the very top.
// it follows LIFO = Last in first out principle, as you can imagine that the top plate is the one placed last but removed first

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Stack{
    private:
    vector<int> stack_;

    public:
    Stack(){}

    void push(int n){
        stack_.push_back(n);
    }

    int pop(){
        if(stack_.empty()) throw out_of_range("Stack is empty, can't pop!");

        int res = stack_.back(); 
        stack_.pop_back();
        return res;
    }

    int peek(){
        if(stack_.empty()) throw out_of_range("Stack is empty, can't pop!");

        return stack_.back();
    }

    bool isEmpty(){
        return stack_.empty();
    }
};

int main(){


    return 0;
}