/* 
 compile using c++11. ex: g++ -std=c++11 evaluate-expr.cpp
*/
#include <iostream>
#include <string>
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
bool is_number(string str)
{
    char *cstr = new char[str.length() + 1];
    char *e;
    strcpy(cstr, str.c_str());
    double number = strtod(cstr, &e);
    return (*e == '\0');
}
vector<string> exprtoinfix(string expr)
{
    char operand[] = "0123456789.";
    char operat[] = "+/*\%";
    char minus = '-';
    char kurung[] = "()";
    string legal{""};
    legal.append("0123456789.");
    legal.append("+/*\%");
    legal.append("-() ");
    // puts(legal.c_str());
    char *cstr = new char[legal.length() + 1];
    strcpy(cstr, legal.c_str());

    for (int i = 0; i < expr.length(); i++)
    {
        if (!in_array(cstr, strlen(cstr), expr.at(i)))
        {
            cerr << "Error expression in " << expr.at(i);
            exit(-1);
        }
    }
    if (in_array(operat, strlen(operat), expr.at(0)))
    {
        cerr << "Error: First character of expression is operator " << expr.at(0);
        exit(-1);
    }
    string buff{""};
    vector<string> infix;

    for (auto n : expr)
    {
        if (n == ' ')
            continue;
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
                if (n == '(' && is_number(buff))
                    infix.push_back("*");
                buff = "";
                string opr{""};
                opr += n;
                infix.push_back(opr);
            }

        if (in_array(operand, strlen(operand), n))
        {
            if (!infix.empty())
                if (buff == "" && infix.back() == ")")
                    infix.push_back("*");

            buff += n;
        }
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
    return infix;
}

int main()
{
    string expr;
    vector<string> infix;
    cout << "Masukan ekspresi aritmatika, lalu tekan ENTER\n";
    getline(cin, expr);
    infix = exprtoinfix(expr);
    for (auto n : infix)
        cout << n << " ";
    // cout << is_number("2.");
    return 0;
}