#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* arr;
    int capacity;
    int size;

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~MaxHeap() {
        delete[] arr;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap Overflow!" << endl;
            return;
        }

        arr[size] = value;
        int i = size;
        size++;

        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMax() {
        if (size <= 0) {
            cout << "Heap Underflow!" << endl;
            return -1;
        }

        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapify(0);

        return root;
    }

    int getMax() {
        if (size > 0) {
            return arr[0];
        }
        return -1;
    }

    void display() {
        if (size == 0) {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Heap elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap(10);

    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(10);
    heap.insert(40);

    heap.display();

    cout << "Max element: " << heap.getMax() << endl;

    cout << "Extracted Max: " << heap.extractMax() << endl;

    heap.display();

    return 0;
}
