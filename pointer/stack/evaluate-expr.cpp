/* 
 compile using c++11. ex: g++ -std=c++11 evaluate-expr.cpp
*/
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
    string expr;
    char operand[] = "0123456789";
    char operat[] = "+/*\%";
    char minus = '-';
    char kurung[] = "()";
    string legal{""};
    legal.append("0123456789");
    legal.append("+/*\%");
    legal.append("-()");
    // puts(legal.c_str());
    char *cstr = new char[legal.length() + 1];
    strcpy(cstr, legal.c_str());
    cout << "Masukan ekspresi aritmatika, lalu tekan ENTER \n";
    getline(cin, expr);

    for (int i = 0; i < expr.length(); i++)
    {
        if (!in_array(cstr, strlen(cstr), expr.at(i)))
        {
            cerr << "Error expression in " << expr.at(i);
            return -1;
        }
    }
    if (in_array(operat, strlen(operat), expr.at(0)))
    {
        cerr << "Error: First character of expression is operator " << expr.at(0);
        return -1;
    }

    // infix[0] = expr.at(0);
    // for (int i = 1; i < expr.length(); i++)
    // {
    //     // cout << expr.at(i) << endl;
    //     if (in_array(operand, strlen(operand), expr.at(i)))
    //     {
    //         cout << expr.at(i) << " operand" << endl;
    //         infix += expr.at(i);
    //     }
    string buff{""};
    vector<string> infix;

    for (auto n : expr)
    {
        if (n == minus)
            if (buff == "")
            {
                if (infix.back() == ")")
                {
                    string opr{""};
                    opr += n;
                    infix.push_back(opr);
                }
                else
                    buff += n;
            }
            else
            {
                infix.push_back(buff);
                buff = "";
                string opr{""};
                opr += n;
                infix.push_back(opr);
            }
        if (in_array(kurung, strlen(kurung), n))
            if (buff == "")
            {
                string opr{""};
                opr += n;
                infix.push_back(opr);
            }
            else
            {
                infix.push_back(buff);
                buff = "";
                string opr{""};
                opr += n;
                infix.push_back(opr);
            }

        if (in_array(operand, strlen(operand), n))
            buff += n;
        else if (in_array(operat, strlen(operat), n) && buff != "")
        {
            infix.push_back(buff);
            buff = "";
            string opr{""};
            opr += n;
            infix.push_back(opr);
        }
        else if (in_array(operat, strlen(operat), n) && buff == "" && infix.back() == ")")
        {
            string opr{""};
            opr += n;
            infix.push_back(opr);
        }
    }
    if (buff != "")
        infix.push_back(buff);

    for (auto n : infix)
        cout << n << " ";
    return 0;
}