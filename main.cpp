#include <bits/stdc++.h>
using namespace std;
#define start cout << "-------------------------------" << endl;
#define end cout << "-------------------------------" << endl \
                 << endl;

string shift(string text, int key)
{
    string shiftedText = "";
    for (char &c : text)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            int x = tolower(c) - 'a';
            x += key;
            x %= 26;


            if (isupper(c))
            {
                shiftedText += 'A' + x;
            }
            else
            {
                shiftedText += 'a' + x;
            }
        }
        else
        {
            shiftedText += c;
        }
    }

    return shiftedText;
}

void encrypt()
{
    start;
    cout << "Plain text: ";
    string plainText;
    cin.ignore();
    getline(cin, plainText);

    srand(time(0));
    int key = 1 + rand() % 25;

    string cipherText = shift(plainText, key);

    cout << "Key: " << key << endl;
    cout << "Cipher text: " << shift(plainText, key) << endl;
    end;
}

void decrypt()
{
    start;
    cout << "Cipher text: ";
    string cipherText;
    cin.ignore();
    getline(cin, cipherText);

    int key;
    cout << "Key: ";
    cin >> key;
    key = 26 - key;

    string plainText = shift(cipherText, key);

    cout << "Plain text: " << plainText << endl;
    end;
}

void help()
{
    start;
    cout << "1.HELP" << endl;
    cout << "2.ENCRYPT" << endl;
    cout << "3.DECRYPT" << endl;
    cout << "4.EXIT" << endl;
    end;
}

void error()
{
    start;
    cout << "Enter between 1-4:" << endl;
    help();
    end;
}

void exit()
{
    start;
    cout << "           **EXIT**            " << endl;
    end;
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