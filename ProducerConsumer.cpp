/* Producer consumer problem */

#include <iostream>
#define MAX 5
using namespace std;

char buffer[MAX] = {'0', '0', '0', '0', '0'};
int front = -1;
int rear = -1;

bool isFull();
bool isEmpty();
void produce();
void consume();
void display();

int main() {

    // Menu

    while(true) {
        char choice;
        cout << endl << endl
             << "1. Produce" << endl
             << "2. Consume" << endl
             << "3. Display buffer" << endl
             << "4. Exit" << endl << endl
             << "Make your choice: ";
        
        cin >> choice;

        switch(choice) {
            case '1':
                produce();
                break;
            case '2':
                consume();
                break;
            case '3':
                display();
                break;
            case '4':
                exit(0);
                break;
            default:
                cout << "Make a valid choice!\n\n";
        }
    }
    return 0;
}

bool isFull() {
    if((front == 0 && rear == MAX-1) || front == rear + 1) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if(front == -1) {
        return true;
    }
    return false;
}

void produce() {

    if(!isFull()) {
        char val;

        cout << "Enter a value(char): ";
        cin >> val;     

        if(isEmpty()) {
            front = rear = 0;
            buffer[rear] = val;            
        }
        else {
            buffer[++rear] = val;
        }
        display();
    }
    else {
        cout << "Buffer is full." << endl;
    }
    
}

void consume() {
    if(!isEmpty()) {
        cout << "Consumed process: " << buffer[front] << endl;

        buffer[front] = '0';

        if(++front == rear+1) {
            front = rear = -1;
        }

        display();
    }
    else {
        cout << "Buffer is empty." << endl;
    }
}

void display() {
    cout << "Buffer: | ";
    for(char c : buffer) {
        cout << c << " | ";
    }
    cout << endl;
}