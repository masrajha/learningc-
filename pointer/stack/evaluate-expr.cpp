/**
    evaluate-expr.cpp
    Purpose: Evaluate and convert expression string to infix form expression.
    @author Didik Kurniawan
    @version 0.1 5/12/2018

    compile using c++11. ex: g++ -std=c++11 evaluate-expr.cpp
*/
#include <iostream>
#include <string>
#include <algorithm> // std::find
#include <vector>    // std::vector
#include <string.h>

using namespace std;
/**
    checking is a character is within in a string

    @param array character
    @param length array
    @param character
    @return true if a character within an array
*/
bool in_array(char mychar[], int n, char x)
{
    char *p;
    p = std::find(mychar, mychar + n, x);
    if (p != mychar + n)
        return true;
    else
        return false;
}
/**
    checking is a string is a number

    @param array character as string
    @return true if string is number
*/
bool is_number(string str)
{
    char *cstr = new char[str.length() + 1];
    char *e;
    strcpy(cstr, str.c_str());
    double number = strtod(cstr, &e);
    return (*e == '\0');
}
/**
    convert string epression to infix formexpression

    @param array character as string
    @return string vector each operator and operand 

    ex input: -200(14-76)+((27-122)2*-19/55-2229)9
    vector output print by space in between:
    -200 * ( 14 - 76 ) + ( ( 27 - 122 ) * 2 * -19 / 55 - 2229 ) * 9

*/
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
        {
            if (buff == "")
            {
                // if (!infix.empty() && infix.back() == ")")
                if (infix.empty()){
                    buff += n;
                }
                else if (infix.back() == ")")
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
        }
        else if (in_array(kurung, strlen(kurung), n))
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

        else if (in_array(operand, strlen(operand), n))
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