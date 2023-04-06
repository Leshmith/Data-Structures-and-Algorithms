#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <chrono>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
public:
    Stack() {
        head = NULL;
        top = NULL;
    }
    bool is_empty() const {
        return head == NULL && top == NULL;
    }
    void push(int n) {
        Node* new_node = new Node;
        new_node->data = n;
        new_node->next = NULL;

        if (is_empty()) {
            head = new_node;
            top = new_node;
        } else {
            top->next = new_node;
            top = new_node;
        }
    }
    int pop() {
        if (is_empty()) {
            throw "Stack Underflow";
        } else {
            int x = top->data;
            if (top == head) { 
                top = NULL;
                head = NULL;
            } else {
                Node* tmp = head;
                while (tmp->next != top) { 
                    tmp = tmp->next;
                }
                tmp->next = NULL; 
                top = tmp; 
            }
            return x;
        }
    }
    void display() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack: ";
            Node* tmp = head;
            while (tmp != NULL) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
private:
    Node* head;
    Node* top;
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