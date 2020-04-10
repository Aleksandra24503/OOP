#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool is_password_ok(string password)
{
    int T[26] = {0};
    for (int i = 0; i < password.length(); i++)
    {
        if ('a' > password[i] || password[i] > 'z')
            return false;
        T[password[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (T[i] != 1)
            return false;
    return true;
}

string generate_password()
{
    srand(time(NULL));

    string A = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++)
        swap(A[i], A[rand()%(i+1)]);

    return A;
}

string krypto(string text, string pass)
{
    string answer = "";

    for (int i = 0; i < text.length(); i++)
        if ('a' <= text[i] && text[i] <= 'z')
            answer.push_back(pass[text[i]-'a']);
        else if ('A' <= text[i] && text[i] <= 'Z')
            answer.push_back(pass[text[i]-'A']);
        else
            answer.push_back(text[i]);

    return answer;
}

int main()
{
    while(true)
    {
        string text;
        string pass;
        string cipher;

        cout << "Enter text: ";
        getline(cin, text);
        cout << "Enter password: ";
        getline(cin, pass);

        cout << "Text: '" << text << "'" << endl;
        cout << "Pass: '" << pass << "'" << endl;

        if (is_password_ok(pass))
            cout << "Password ok" << endl;
        else
        {
            cout << "Wrong password" << endl;
            pass = generate_password();
            cout << "New Pass: '" << pass << "'" << endl;
        }

        cipher = krypto(text, pass);

        cout << "Cipher: '" << cipher << "'" << endl;
        cout << endl;
    }
    return 0;
}
