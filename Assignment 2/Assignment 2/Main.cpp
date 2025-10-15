// Zajkub Vang

#include "Headers.h"

using namespace std;

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
    cout << "  9. Show size\n";
    cout << "------------------------------\n";
    cout << "Stack Operations:\n";
    cout << " 10. Push number\n";
    cout << " 11. Pop number\n";
    cout << " 12. Check if empty\n";
    cout << " 13. Show top\n";
    cout << " 14. Show average\n";
    cout << " 15. Print stack\n";
    cout << "------------------------------\n";
    cout << " 16. Exit\n";
    cout << "==============================\n";
    cout << "Choose an option: ";
}

// Function to throw an error if input is not an integer
int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Input is not an integer.");
        }
        return value;
    }
}

int main()
{
    LinkedList myList;
    Stack s;

    int listCount, value, index;

    cout << "Creating the singly linked list...\n\n";

    try {
        listCount = getIntInput("How many numbers to add to the singly linked list? ");
        for (int i = 0; i < listCount; ++i) {
            value = getIntInput("Enter number " + to_string(i + 1) + ": ");
            myList.push_back(value);
        }
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    cout << "Linked List contents: ";
    myList.print();

    cout << "\nCreating the stack...\n";

    int stackCount;
    try {
        stackCount = getIntInput("\nHow many numbers to add to the stack? ");
        for (int i = 0; i < stackCount; ++i) {
            value = getIntInput("Enter number " + to_string(i + 1) + ": ");
            s.push(value);
        }
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
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
        try {
            choice = getIntInput("");
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            continue;
        }
        switch (choice) {
        case 1:
            try {
                value = getIntInput("Enter value to add to front: ");
                myList.push_front(value);
                cout << "Updated Linked List: ";
                myList.print();
            } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        case 2:
            try {
                value = getIntInput("Enter value to add to back: ");
                myList.push_back(value);
                cout << "Updated Linked List: ";
                myList.print();
            } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        case 3:
            myList.pop_front();
            cout << "Front popped.\n";
            cout << "Updated Linked List: ";
            myList.print();
            break;
        case 4:
            myList.pop_back();
            cout << "Back popped.\n";
            cout << "Updated Linked List: ";
            myList.print();
            break;
        case 5:
            try {
                index = getIntInput("Enter index to insert at: ");
                value = getIntInput("Enter value to insert: ");
                myList.insert(index, value);
                cout << "Updated Linked List: ";
                myList.print();
            } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        case 6:
            try {
                index = getIntInput("Enter index to remove: ");
                myList.remove(index);
                cout << "Updated Linked List: ";
                myList.print();
            } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        case 7:
            try {
                value = getIntInput("Enter value to find: ");
                size_t idx = myList.find(value);
                if (idx != static_cast<size_t>(-1))
                    cout << "Value found at index: " << idx << endl;
                else
                    cout << "Value not found.\n";
            } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        case 8:
            myList.print();
            break;
        case 9:
            cout << "Linked list size: " << myList.size() << endl;
            break;
        case 10:
            try {
                value = getIntInput("Enter value to push to stack: ");
                s.push(value);
                cout << "Updated Stack: ";
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
            } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        case 11:
            s.pop();
            cout << "Top popped in stack.\n";
            cout << "Updated Stack: ";
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
        case 12:
            cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
            break;
        case 13:
            try {
                cout << "Top of stack: " << s.top() << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        case 14:
            cout << "Average of stack: " << s.average() << endl;
            break;
        case 15:
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
            break;
        case 16:
            running = false;
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
// End of file Main.cpp