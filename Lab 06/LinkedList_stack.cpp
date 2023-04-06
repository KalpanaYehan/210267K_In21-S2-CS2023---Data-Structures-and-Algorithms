#include <iostream>
#include<chrono>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    // Constructor to initialize the node with the given data
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top; // Pointer to the top node in the stack

public:
    // Constructor to initialize the top of the stack to NULL
    Stack() {
        top = NULL;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Function to push an element onto the top of the stack
    void push(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            top = newNode;
        } 
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    // Function to pop element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1; // Return -1 to indicate an empty stack
        } else {
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }
    // to display the value that store  in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } 
        else {
            Node* curr = top;
            cout<<"[";
            while (curr != NULL) {
                cout << curr->data <<",";
                curr = curr->next;
            }
            cout<<"]"<<endl;
        }
    }
    int StackTop(){
        if (top==NULL){
            cout<<"stack is empty";
        }
        else{
            return top -> data;
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
    cout<<"Time taken to exicute : "<<time_taken<<" micro seconds"<<endl;
    return 0;
}