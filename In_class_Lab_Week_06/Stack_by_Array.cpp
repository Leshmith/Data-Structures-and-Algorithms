#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <chrono>
using namespace std;

#define MAX_SIZE 10 // Maximum size of the stack

class Stack {
    private:
        int top; 
        int arr[MAX_SIZE]; 
    
    public:
        Stack() {
            top = -1; 
        }

        bool isEmpty() {
            return top == -1; 
        }

        bool isFull() {
            return top == MAX_SIZE - 1; 
        }

        void push(int x) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                arr[top] = x;
            }
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1; 
            } else {
                int x = arr[top];
                top--;
                return x;
            }
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1; 
            } else {
                return arr[top];
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack: ";
                for (int i = top; i >= 0; i--) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    
    auto started = std::chrono::high_resolution_clock::now();
    
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

    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

    s.display();
    
    auto done = std::chrono::high_resolution_clock::now();

    std::cout <<"Time taken = "<< std::chrono::duration_cast<std::chrono::microseconds>(done-started).count()<< " micro seconds";

    return 0;
}
