#include <string>
#include <iostream>

using namespace std;

template <class T>
class stack
{
private:
    int size;
    T tab[200];
public:
    stack()
    {
        size = 0;
    }

    void push(T elem)
    {
        tab[size] = elem;
        size++;
    }

    void pop()
    {
        size--;
    }

    T    top()
    {
        return tab[size-1];
    }
};

int main()
{
    int choice;
    stack<int>    sint;
    stack<string> sstr;

    while (true)
    {
        cout << endl;
        cout << "1.Push int item" << endl;
        cout << "2.Push string item" << endl;
        cout << "3.Pop int item" << endl;
        cout << "4.Pop string item" << endl;
        cout << "5.Top int item" << endl;
        cout << "6.Top string item" << endl;
        cout << "0.Exit" << endl << endl;
        cout << "> ";

        cin >> choice;

        if (choice == 1)
        {
            int item;

            cout << "Give item." << endl;
            cout << "> ";
            cin >> item;

            sint.push(item);
        }
        else if (choice == 2)
        {
            string item;

            cout << "Give item." << endl;
            cout << "> ";
            cin >> item;

            sstr.push(item);
        }
        else if (choice == 3)
        {
            sint.pop();
            cout << "Done." << endl;
        }
        else if (choice == 4)
        {
            sstr.pop();
            cout << "Done." << endl;
        }
        else if (choice == 5)
        {
            cout << "Item on top: " << sint.top() << endl;
        }
        else if (choice == 6)
        {
            cout << "Item on top: " << sstr.top() << endl;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}
