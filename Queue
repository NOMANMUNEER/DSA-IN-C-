#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " added to the queue." << endl;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int dequeuedValue = arr[front];
        front = (front + 1) % capacity;
        size--;
        return dequeuedValue;
    }

    int peek() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.display();

    queue.enqueue(60);

    cout << "Front element: " << queue.peek() << endl;

    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Dequeued element: " << queue.dequeue() << endl;

    queue.display();

    if (queue.isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    cout << "Current queue size: " << queue.getSize() << endl;

    return 0;
}
