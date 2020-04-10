#include <iostream>

using namespace std;

class account
{
public:
    account();
    ~account();
};

account::account()
{
    cout << "Constructor" << endl;
}

account::~account()
{
    cout << "Destructor" << endl;
}

int main()
{
    account* acc = new account;

    delete acc;

    return 0;
}
