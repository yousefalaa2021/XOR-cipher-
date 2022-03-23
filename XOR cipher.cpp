#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <sstream>
#include <cstdlib>
using namespace std;
int hexadecimalToDecimal(string decrypted)
{
    int len = decrypted.size();

    // Initializing base value to 1, i.e 16^0
    int base = 1;

    int dec_val = 0;

    // Extracting characters as digits from last character
    for (int i = len - 1; i >= 0; i--)
    {
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value.
        if (decrypted[i] >= '0' && decrypted[i] <= '9')
        {
            dec_val += (decrypted[i] - 48) * base;

            // incrementing base by power
            base = base * 16;
        }

        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (decrypted[i] >= 'A' && decrypted[i] <= 'F')
        {
            dec_val += (decrypted[i] - 55) * base;

            // incrementing base by power
            base = base * 16;
        }
        else if (decrypted[i] >= 'a' && decrypted[i] <= 'f')
        {
            dec_val += (decrypted[i] - 87) * base;

            // incrementing base by power
            base = base * 16;
        }
    }

    return dec_val;
}

int main()
{

    
    string text, encrypted, decrypted = "00", n;
    char key, turn, hexa(0);
    int pr, decision, j = 0;
    turn = 'y';
    while (turn == 'y')
    {
        cout << "Welcome to  XOR Cipher program\n";
        cout << "What do you want to do:\n"
            << "1- Cipher a message\n2 - Decipher a message\n3 - End\n";
        cin >> decision;
        if (decision == 1)
        {
            encrypted = "";
            cout << "Enter the text: " << endl;
            cin.ignore();
            getline(cin, text);
            cout << "Enter the key: " << endl;
            cin >> key;
            for (int i = 0;i < text.length();i++)
            {
                pr = (toupper(text[i])) ^ (toupper(key));
                if (pr < 10)
                {
                    cout << 0;
                }
                if (pr == 0)
                {
                    encrypted += " ";
                }
                else
                {
                    encrypted += char(pr);
                }

                cout << hex << int(pr);


            }
            cout << endl;
            cout << encrypted << endl;

        }
        else if (decision == 2)
        {
            cout << "Enter the Encrypted message: " << endl;
            cin.ignore();
            getline(cin, text);
            cout << "Enter the key: " << endl;
            cin >> key;
            for (int i = 0;i < text.length();i++)
            {
                if (i % 2 == 0 && i != 0)
                {
                    j = 0;
                    decrypted[j] = text[i];
                    j++;
                }
                else
                {
                    decrypted[j] = text[i];
                    j++;
                }
                if (j == 2)
                {
                    cout << char(hexadecimalToDecimal(decrypted) ^ key);
                }
            }
            cout << endl;
        }
        cout << "Do you want to calcualte again [Y/N]: ";
        cin >> turn;
        if (tolower(turn) != 'y')
        {
            cout << "Thank you for choosing the XOR cipher !";
        }

    }
    

    
    

}