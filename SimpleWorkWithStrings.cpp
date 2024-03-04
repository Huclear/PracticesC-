// SimpleWorkWithStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
void removeVowels(string* str_to_edit);
void removeConsonants(string* str_to_edit);
int main()
{
    string str;
    int operationNum;
    cout << "Input any sequence of any characters without any space, enter or tab\n";
    cin >> str;

    while (true)
    {
        cout << "Your string - " << str << endl;
        cout << "\nThere are a few operations you can execute with your string:" << endl << "1 - Reverse your word(or else you inputted)\n2 - Remove all vowels\n3 - Remove all consonants" <<
            "\n4 - Shuffle you word\n5 - Re-enter sequence\n6 - Stop executing" << endl << "Choose the operation: ";
        cin >> operationNum;
        switch (operationNum)
        {
        case 1:
            reverse(str.begin(), str.end());
            break;
        case 2:
            removeVowels(&str);
            break;
        case 3:
            removeConsonants(&str);
        case 4:
            random_shuffle(str.begin(), str.end());
            break;
        case 5:
            cout << "\nInput any sequence of any characters without any space, enter or tab\n";
            cin >> str;
            break;
        case 6:
            return 0;
        default:
            cout << "Incorrect number of operation";
            return 0;
        }
    }
}

void removeVowels(string* str_to_edit) {
    char vowels[] = { "aeiouywWYAEIOU" };
    int amount = 0, pos = 0;
    for (char ch : vowels)
    {
        if (ch != '\0') {
            amount = str_to_edit->find(ch, 0);
            while (amount > 0)
            {
                pos = str_to_edit->find_first_of(ch);
                str_to_edit->replace(pos, 1, "");
                amount = str_to_edit->find(ch, 0);
            }
        }

    }
}
void removeConsonants(string* str_to_edit) {
    char consonants[] = { "qrtpsdfghjklzxcvbnmQRTPSDFGHJKLZXCVBNM" };
    int amount = 0, pos = 0;
    for (char ch : consonants)
    {
        if (ch != '\0')
        {
            amount = str_to_edit->find(ch, 0);
            while (amount > 0)
            {
                pos = str_to_edit->find_first_of(ch);
                str_to_edit->replace(pos, 1, "");
                amount = str_to_edit->find(ch, 0);
            }
        }

    }
}