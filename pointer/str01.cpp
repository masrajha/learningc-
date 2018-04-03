#include <iostream>
using namespace std;
int main(){
    char str1[]={'i','l','k','o','m','\0'};
    char str2[50];
    cin>>str2>>str1;

    // char *str3 ="fmipa";
    // int A[]={3,2,6,9,1};
    // cout<<str1<<" "<<str2<<" "<<str3;
    cout<<str2<<endl;
    cout<<"---------------\n";

    for (int i=0;*(str2+i)!='\0';i++){
        cout<<*(str2+i)<<endl;
    }

    return 0;
}