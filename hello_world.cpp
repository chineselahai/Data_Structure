
#include <iostream>
#include <string>
#include <cstdlib> // for system("clear")

using namespace std;

// Base class for common functionalities
class Base {
public:
    void clearScreen() {
        system("clear");
    }
};

// Stack operations
class Stack : public Base {
private:
    int top;
    int arr[5];

public:
    Stack() {
        top = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 4;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return 0;
        } else {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count() {
        return top + 1;
    }

    int peek(int pos) {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return 0;
        } else {
            return arr[pos];
        }
    }

    void change(int pos, int val) {
        arr[pos] = val;
        cout << "Value changed at location " << pos << endl;
    }

    void display() {
        cout << "All values in the Stack are " << endl;
        for (int i = 4; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

// Queue operations
class Queue : public Base {
private:
    int front;
    int rear;
    int arr[5];

public:
    Queue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == 4;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue full" << endl;
            return;
        } else if (isEmpty()) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        } else {
            rear++;
            arr[rear] = val;
        }
    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return x;
        } else if (rear == front) {
            x = arr[rear];
            rear = -1;
            front = -1;
            return x;
        } else {
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }

    int count() {
        return rear - front + 1;
    }

    void display() {
        cout << "All values in the Queue are - " << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << "  ";
        }
    }
};

// Sorting function
void selectionSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

// Sorting operations
void sortOperation() {
    int size;
    cout << "How many elements do you want to sort?: ";
    cin >> size;

    int* myarray = new int[size];

    cout << "Enter the " << size << " elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> myarray[i];
    }

    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }

    selectionSort(myarray, size); // sorting

    cout << endl << "After Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }

    delete[] myarray;
}

// Main menu
void mainMenu() {
    Stack stack;
    Queue queue;
    Base base;
    int choice, value, position;

    while (true) {
        cout << "--- Main Menu ---" << endl;
        cout << "1. Stack Operations" << endl;
        cout << "2. Queue Operations" << endl;
        cout << "3. Sorting" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                while (true) {
                    cout << "--- Stack Operations Menu ---" << endl;
                    cout << "1. Push" << endl;
                    cout << "2. Pop" << endl;
                    cout << "3. Is Empty" << endl;
                    cout << "4. Is Full" << endl;
                    cout << "5. Count" << endl;
                    cout << "6. Peek" << endl;
                    cout << "7. Change" << endl;
                    cout << "8. Display" << endl;
                    cout << "9. Clear Screen" << endl;
                    cout << "10. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter value to push: ";
                            cin >> value;
                            stack.push(value);
                            break;
                        case 2:
                            stack.pop();
                            break;
                        case 3:
                            cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                            break;
                        case 4:
                            cout << (stack.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                            break;
                        case 5:
                            cout << "Count: " << stack.count() << endl;
                            break;
                        case 6:
                            cout << "Enter position to peek: ";
                            cin >> position;
                            cout << "Value at position " << position << ": " << stack.peek(position) << endl;
                            break;
                        case 7:
                            cout << "Enter position and value to change: ";
                            cin >> position >> value;
                            stack.change(position, value);
                            break;
                        case 8:
                            stack.display();
                            break;
                        case 9:
                            base.clearScreen();
                            break;
                        case 10:
                            goto main_menu;
                        default:
                            cout << "Invalid choice." << endl;
                    }
                }
                break;

            case 2:
                while (true) {
                    cout << "--- Queue Operations ---" << endl;
                    cout << "1. Enqueue" << endl;
                    cout << "2. Dequeue" << endl;
                    cout << "3. Is Empty" << endl;
                    cout << "4. Is Full" << endl;
                    cout << "5. Count" << endl;
                    cout << "6. Display" << endl;
                    cout << "7. Clear Screen" << endl;
                    cout << "8. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            queue.enqueue(value);
                            break;
                        case 2:
                            queue.dequeue();
                            break;
                        case 3:
                            cout << (queue.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                            break;
                        case 4:
                            cout << (queue.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                            break;
                        case 5:
                            cout << "Count: " << queue.count() << endl;
                            break;
                        case 6:
                            queue.display();
                            break;
                        case 7:
                            base.clearScreen();
                            break;
                        case 8:
                            goto main_menu;
                        default:
                            cout << "Invalid choice." << endl;
                    }
                }
                break;

            case 3:
                cout << "--- Sorting ---" << endl;
                cout << "1. Start to Sort" << endl;
                cout << "2. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    sortOperation();
                } else if

 (choice == 2) {
                    goto main_menu;
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;

            case 4:
                cout << "Exiting..." << endl;
                return;

            default:
                cout << "Invalid choice." << endl;
        }

        main_menu:
        continue;
    }
}

int main() {
    mainMenu();
    return 0;
}
