#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    ifstream html;
    html.open("index.html", ios::in);

    if (html)
    {
        int errCount = 0;
        bool isOpen = false;
        char ch;

        do 
        {
            html.get(ch);
            cout << ch;

            if (ch == '<' && !isOpen)
            {
                isOpen = true;
            }
            else if (ch == '>' && isOpen)
            {
                isOpen = false;
            }
            else if (ch == '>' && !isOpen)
            {
                errCount++;
            }
            else if (ch == '<' && isOpen)
            {
                errCount++;
            }
        }while (html);

        errCount--;
        cout << "\nErrors: " << errCount << endl;
        html.close();
    }
    else
    {
        cout << "Could not open the file" << endl;
    }

    return 0;
}