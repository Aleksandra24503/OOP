#include <iostream>
#include <exception>
#include <string>

using namespace std;

#define MAX_STACK_SIZE 1000

template<class T>
class Stack
{
private:
    int size;
    T tab[MAX_STACK_SIZE];
public:
    Stack()
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
        if (size == 0) throw "empty stack";
        size--;
    }

    T top()
    {
        if (size == 0) throw "empty stack";
        return tab[size-1];
    }

    bool isempty()
    {
        return (size == 0);
    }
};

int fromString(const string &line, int &it)
{
    int answer = 0;

    while ('0' <= line[it] && line[it] <= '9')
    {
        answer = answer * 10 + (line[it] - '0');
        it++;
    }

    return answer;
}

int skipWS(const string &line, int &it)
{
    while (line[it] == ' ' || line[it] == '\t') it++;
}

int priority(char c)
{
    if (c == '+') return 1;
    if (c == '-') return 1;
    if (c == '*') return 2;
    if (c == '/') return 2;
    return -1;
}

string toONP(const string &line)
{
    int it = 0;
    string answer;
    Stack<char> sop;

    skipWS(line, it);
    while (line[it] != '\0')
    {
        if ('0' <= line[it] && line[it] <= '9')
        {
            while ('0' <= line[it] && line[it] <= '9')
                answer.push_back(line[it++]);
            answer.push_back(' ');
        }
        else if (line[it] == '(')
        {
            sop.push('(');
            it++;
        }
        else if (line[it] == ')')
        {
            if (sop.isempty()) throw "Wrong bracket";
            while(sop.top() != '(')
            {
                answer.push_back(sop.top());
                answer.push_back(' ');
                sop.pop();
                if (sop.isempty()) throw "Wrong bracket";
            }
            sop.pop();
            it++;
        }
        else
        {
            int p = priority(line[it]);

            if (p == -1) throw "Unknown operator";
            while (!sop.isempty() && p <= priority(sop.top()) )
            {
                answer.push_back(sop.top());
                answer.push_back(' ');
                sop.pop();
            }
            sop.push(line[it]);

            it++;
        }

        skipWS(line, it);
    }

    while (!sop.isempty())
    {
        if (sop.top() == '(') throw "Wrong bracket";
        answer.push_back(sop.top());
        answer.push_back(' ');
        sop.pop();
    }

    return answer;
}

int calculate(const string &line)
{
    int it = 0;
    Stack<int> S;

    skipWS(line, it);
    while (line[it] != '\0')
    {
        if ('0' <= line[it] && line[it] <= '9')
        {
            int number = fromString(line, it);
            S.push(number);
        }
        else
        {
            if (S.isempty()) throw "Incorrect RPN";
            int n1 = S.top();
            S.pop();
            if (S.isempty()) throw "Incorrect RPN";
            int n2 = S.top();
            S.pop();

            if (line[it] == '+')
                S.push(n2 + n1);
            else if (line[it] == '-')
                S.push(n2 - n1);
            else if (line[it] == '*')
                S.push(n2 * n1);
            else if (line[it] == '/')
                S.push(n2 / n1);
            else throw "Unknown operator";

            it++;
        }

        skipWS(line, it);
    }

    if (S.isempty()) throw "Incorrect RPN";
    int answer = S.top();
    S.pop();
    if (!S.isempty()) throw "Incorrect RPN";
    return answer;
}

int main()
{
    string line ,onp;

    while (true)
    {
        int it = 0;

        cout << "> ";
        getline(cin, line);

        try
        {
            onp = toONP(line);
            cout << "< " << onp << endl;
            cout << "< " << calculate(onp) << endl;
        }
        catch (const char* c)
        {
            cout << "< Error: " << c << endl;
        }
    }
}
