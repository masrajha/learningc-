#include <iostream>
#include <stdio.h>
#include <algorithm> // std::find
#include <vector>    // std::vector
#include <string.h>

using namespace std;
bool in_array(char mychar[], int n, char x)
{
    char *p;
    p = std::find(mychar, mychar + n, x);
    if (p != mychar + n)
        return true;
    else
        return false;
}

int main()
{
    int c;
    char operand[] = "0123456789";
    char operat[] = "+-/*%";

    puts("Masukan ekspresi aritmatika, lalu tekan ENTER ");
    do
    {
        c = getchar();
        if (in_array(operand, strlen(operand), c))
            cout << (char)c << " operand" << endl;
        if (in_array(operat, strlen(operat), c))
            cout << (char)c << " operator" << endl;
        if (c == '(')
            cout << (char)c << " left parenthesis" << endl;
        if (c == ')')
            cout << (char)c << " right parenthesis" << endl;
    } while (c != '\n');
    return 0;
}