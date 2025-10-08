// Zajkub Vang

#include "Headers.h"
#include <vector>

void menu() {
    cout << "\n========== Main Menu ==========\n";
    cout << "Singly Linked List Operations:\n";
    cout << "  1. Add to front\n";
    cout << "  2. Add to back\n";
    cout << "  3. Remove from front\n";
    cout << "  4. Remove from back\n";
    cout << "  5. Insert at index\n";
    cout << "  6. Remove at index\n";
    cout << "  7. Find value\n";
    cout << "  8. Print list\n";
    cout << "------------------------------\n";
    cout << "Stack Operations:\n";
    cout << "  9. Push number\n";
    cout << " 10. Pop number\n";
    cout << " 11. Check if empty\n";
    cout << " 12. Show top\n";
    cout << " 13. Show average\n";
    cout << " 14. Print stack\n";
    cout << "------------------------------\n";
    cout << " 15. Exit\n";
    cout << "==============================\n";
    cout << "Choose an option: ";
}

int main()
{
    LinkedList myList;
    Stack s;

    int listCount, value, index;

    cout << "\nCreating the singly linked list...\n";

    cout << "How many numbers to add to the singly linked list? ";
    cin >> listCount;
    for (int i = 0; i < listCount; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> value;
        myList.push_back(value);
    }
    cout << "Linked List contents: ";
    myList.print();

    cout << "\nCreating the stack...\n";

    // Input for stack
    int stackCount;
    cout << "\nHow many numbers to add to the stack? ";
    cin >> stackCount;
    for (int i = 0; i < stackCount; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> value;
        s.push(value);
    }
    cout << "Stack contents: ";
    {
        Stack temp = s;
        vector<int> stackVals;
        while (!temp.isEmpty()) {
            stackVals.push_back(temp.top());
            temp.pop();
        }
        for (auto it = stackVals.rbegin(); it != stackVals.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    bool running = true;
    while (running) {
        menu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to add to front: ";
            cin >> value;
            myList.push_front(value);
            break;
        case 2:
            cout << "Enter value to add to back: ";
            cin >> value;
            myList.push_back(value);
            break;
        case 3:
            myList.pop_front();
            break;
        case 4:
            myList.pop_back();
            break;
        case 5:
            cout << "Enter index to insert at: ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> value;
            myList.insert(index, value);
            break;
        case 6:
            cout << "Enter index to remove: ";
            cin >> index;
            myList.remove(index);
            break;
        case 7:
            cout << "Enter value to find: ";
            cin >> value;
            {
                size_t idx = myList.find(value);
                if (idx != static_cast<size_t>(-1))
                    cout << "Value found at index: " << idx << endl;
                else
                    cout << "Value not found.\n";
            }
            break;
        case 8:
            myList.print();
            break;
        case 9:
            cout << "Enter value to push to stack: ";
            cin >> value;
            s.push(value);
            break;
        case 10:
            s.pop();
            break;
        case 11:
            cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
            break;
        case 12:
            try {
                cout << "Top of stack: " << s.top() << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        case 13:
            cout << "Average of stack: " << s.average() << endl;
            break;
        case 14:
            cout << "Stack contents: ";
            // Print stack contents
            {
                Stack temp = s;
                vector<int> stackVals;
                while (!temp.isEmpty()) {
                    stackVals.push_back(temp.top());
                    temp.pop();
                }
                for (auto it = stackVals.rbegin(); it != stackVals.rend(); ++it)
                    cout << *it << " ";
                cout << endl;
            }
            break;
        case 15:
            running = false;
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
// End of file Main.cpp