#include <iostream>
#include<chrono>
using namespace std;

const int max_size = 20; // Maximum size of the stack
class Stack {
private:
    int top;           // Index of the top element in the stack
    int arr[max_size]; // Array to store elements in the stack

public:
    // Constructor to initialize the top of the stack to -1
    Stack() {
        top = -1;
    }
    // Function to check if the stack is empty
    bool isEmpty() {
        if(top == -1){
           return true;
        }
        else{
           return false;
        }
    }
    // Function to check if the stack is full
    bool isFull() {
        if(top == max_size - 1){
           return true;
        }
        else{
            return false;
        }
    }
    // Function to push an element onto the top of the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            top++;
            arr[top] = value;
        }
    }
    // Function to pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1; // Return -1 to indicate an empty stack
        } else {
            int value = arr[top];
            top--;
            return value;
        }
    }
    void display(){
        cout<<"[";
        for (int i=top;i>=0;i--){
            cout<<arr[i]<<",";
        }
        cout<<"]"<<endl;
    }
    int StackTop(){
        if (top==-1){
            cout<<"satck is empty";
        }
        else{
            return arr[top];
        }
    }
};
int main() {
    auto start = chrono::high_resolution_clock::now();
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    cout<<"current stack is :"<<endl;
    s.display();
    s.pop();
    s.pop(); 
    s.pop(); 
    s.pop(); 
    s.pop();
    cout<<"current stack is :"<<endl;
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    cout<<"current stack is :"<<endl;
    s.display();
    auto end = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::microseconds>(end-start).count();
    cout<<"Time taken to execute :"<<time_taken<<"micro seconds"<<endl;
    return 0;
}