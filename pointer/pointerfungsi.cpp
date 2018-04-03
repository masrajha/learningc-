#include <iostream>
using namespace std;
int add(int, int);
int dif(int, int);
int div(int, int);
int mul(int, int);
int execute(int (*) (int, int),int,int);

int main()
{
    int (*myFunc)(int, int);
    int (*myFuncs[])(int, int) = {add, dif, div, mul};
    for (int i=0;i<4;i++){
        cout << execute (*myFuncs[i],9, 3)<<endl;
    }
    
    // cout<<"eksekusi "<<execute(add,4,3);
    return 0;
}
int add(int a, int b)
{
    return a + b;
}
int dif(int a, int b)
{
    return a - b;
}
int div(int a, int b)
{
    if (b != 0)
        return a / b;
    return 0;
}
int mul(int a, int b)
{
    return a * b;
}

int execute(int (*Func)(int a, int b),int c,int d){
     return (*Func)(c,d);
}