#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class ArrayStack {
private:
    int arr[MAX_SIZE];
    int topIndex;

public:
    ArrayStack() : topIndex(-1) {}

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == MAX_SIZE - 1;
    }

    bool push(int value) {
        if (isFull()) {
            return false;
        }
        arr[++topIndex] = value;
        return true;
    }

    bool pop(int &value) {
        if (isEmpty()) {
            return false;
        }
        value = arr[topIndex--];
        return true;
    }

    bool peek(int &value) const {
        if (isEmpty()) {
            return false;
        }
        value = arr[topIndex];
        return true;
    }
};

int main() {
    ArrayStack stack;
    int x;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    if (stack.peek(x)) {
        cout << "Top value: " << x << '\n';
    }

    while (stack.pop(x)) {
        cout << "Popped: " << x << '\n';
    }

    return 0;
}


