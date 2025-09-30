#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;

template<typename T>
class stack {
private:
    T *ptr;
    int capacity;
    int top;

public:
    stack(T n) 
    { 
        // int elements;
        // cout<<"enter the space you want to allocate for stack "<<endl;
        // cin>>elements;
        ptr = new T[n];  
        top = 0;
        capacity = n;

        // for(int i=0;i<n;i++)
        // {
        //  cout << "enter the elements  " << endl;  
        // cin>> elements;
        // push(elements);
       }
    void push(T n) 
    {
        // cout<<"pushing"<<n<<endl;
        if (top < capacity)
         {
            ptr[top] = n;
            top++;
        }
        else {
            // cout << "Stack Overflow" << endl;
        }
    }

    T pop() {
        if (top == 0) {
            cout << "stack Underflow" << endl;
            return T{};   
        }
        else {
            top--;
            return ptr[top];
        }
    }

    bool isFull() {
        return top >= capacity;
    }
  bool isEmpty(){
    if(top==0){
    return true;
    }

  }
    T gettop() {
        if (top == 0) {
            cout << "Stack is empty\n";
        }
        return top;
    }

    T stacktop() {
        if (top == 0) {
            cout << "Stack is empty\n";
            // return T{};
            return -1;  
        }
        return ptr[top - 1];
    }

    stack(const stack &ref) {
        // cout << "copy constructor called" << endl;
        capacity = ref.capacity;
        top = ref.top;
        ptr = new T[capacity];
        for (int i = 0; i < top; i++) {
            ptr[i] = ref.ptr[i];
        }
    }

    stack& operator=(const stack &ref) {
        cout << "Assignment Operator called" << endl;
        if (this != &ref) {
            delete[] ptr;
            top = ref.top;
            capacity = ref.capacity;
            ptr = new T[capacity];
            for (int i = 0; i < top; i++) {
                ptr[i] = ref.ptr[i];
            }
        }
        return *this;
    }

    void display() {
        if (top == 0) {
            cout << "stack is empty" << endl;
            return;
        }
        for (int i = 0; i < top; i++) {
            cout << "the elements are " << ptr[i] << " " << endl;
        }
    }
T stackread(){
    for(int i=0;i<top;i++){
        cout<<ptr[i]<<" ";
    }
    return T{};
}
    ~stack() {
        cout << "destructor called" << endl;
        delete[] ptr;
    }
};

#endif
