#include <bits/stdc++.h>
#include "btree.h"
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

int matchCount(string s)
{
    stringstream ss(s);
    string word;
    int count = 0;
    while (ss >> word)
    {
        if (search(bTreeNode, word))
            count++;
    }
    return count;
}

void decrypt()
{
    start;
    cout << "Cipher text: ";
    string cipherText;
    cin.ignore();
    getline(cin, cipherText);

    cout << "DO you have key(y/n)? ";
    string userInput;
    getline(cin, userInput);
    if (userInput == "y")
    {
        int key;
        cout << "Key: ";
        cin >> key;
        key = 26 - key;

        string plainText = shift(cipherText, key);

        cout << "Plain text: " << plainText << endl;
        end;
    }
    else
    {
        int currMax = matchCount(cipherText), currKey = 0;
        for (int key = 1; key < 26; key++)
        {

            string plainText = shift(cipherText, key);
            int count = matchCount(plainText);
            if (count > currMax)
            {
                currMax = count;
                currKey = key;
            }
        }
        cout << shift(cipherText, currKey);
        cout << endl;
    }
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
    createDict();
    help();
    while (true)
    {
        cout<<"USER";
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
            closeDict();
            exit();
            return 0;
        }
        else
        {
            error();
        }
    }
}