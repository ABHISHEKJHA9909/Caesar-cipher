#include <bits/stdc++.h>
using namespace std;

char shift(char c, int key)
{
    int x = tolower(c) - 'a';
    x += key;
    x %= 26;

    if (isupper(c))
    {
        c = 'A' + x;
    }
    else                                                    
    {
        c = 'a' + x;
    }

    return c;
}

void encrypt()
{
    cout << "-------------------------------" << endl;

    cout << "Plain text: ";
    string plainText;
    cin.ignore();
    getline(cin, plainText);

    srand(time(0));
    int key = 1 + rand() % 25;

    string cipherText = "";
    for (char &c : plainText)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            cipherText += shift(c, key);
        }
        else
        {
            cipherText += c;
        }
    }

    cout << "Key: " << key << endl;
    cout << "Cipher text: " << cipherText << endl;
    cout << "-------------------------------" << endl
         << endl;
}

void decrypt()
{
    cout << "-------------------------------" << endl;

    cout << "Cipher text: ";
    string cipherText;
    cin.ignore();
    getline(cin, cipherText);

    int key;
    cout << "Key: ";
    cin >> key;
    key = 26 - key;

    string plainText;
    for (char c : cipherText)
    {
        if ((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z'))
        {
            plainText += shift(c, key);
        }
        else
        {
            plainText += c;
        }
    }

    cout << "Plain text: " << plainText << endl;
    cout << "-------------------------------" << endl
         << endl;
}

void help()
{
    cout << "-------------------------------" << endl;
    cout << "1.HELP" << endl;
    cout << "2.ENCRYPT" << endl;
    cout << "3.DECRYPT" << endl;
    cout << "4.EXIT" << endl;
    cout << "-------------------------------" << endl
         << endl;
}

void error()
{
    cout << "-------------------------------" << endl;
    cout << "Enter between 1-4:" << endl;
    help();
}

void exit()
{
    cout << "-------------------------------" << endl;
    cout << "           **EXIT**            " << endl;
    cout << "-------------------------------" << endl
         << endl;
}
int main()
{
    help();
    while (true)
    {
        string userInput;
        cin >> userInput;
        if (userInput == "1" || userInput == "help")
        {
            help();
        }
        else if (userInput == "2")
        {
            encrypt();
        }
        else if (userInput == "3")
        {
            decrypt();
        }
        else if (userInput == "4")
        {
            exit();
            return 0;
        }
        else
        {
            error();
        }
    }
}