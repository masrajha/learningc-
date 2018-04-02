#include <iostream>

using namespace std;
double average(int*, int);
int main()
{
    int n=9, m=4;
    int *pn,*pm;
    pn = &n;
    pm = &m;
    cout<<"n :"<<n<<endl;
    cout<<"&n :"<<&n<<endl;
    cout<<"pn :"<<pn<<endl;
    cout<<"*pn :"<<*pn<<endl;
    cout<<"&pn :"<<&pn<<endl;
    *pn=15;
    cout<<"n :"<<n<<endl;

    int **ppn;
    ppn = &pn;
    cout<<"ppn :"<<ppn<<endl;
    cout<<"*ppn :"<<*ppn<<endl;
    cout<<"**ppn :"<<**ppn<<endl;

    int hasil = *pm * **ppn;
    cout<<"hasil "<<hasil<<endl;

    int data[] = {5,2,9,1,3,8,8,4};
    cout<<"data :"<<data<<" "<<&data[0]<<endl;
    pn = data;
    cout<<"pn :"<<pn<<" *pn :"<<*pn<<endl;
    for (int i=0;i<8;i++){
        cout<<pn+i<<" -> "<<*(pn+i)<<endl;
    }
    cout<<"Rata-rata : "<<average(data,8)<<endl;

    int A[]={5,4,2,1};
    int B[]={6,2,1};
    int na = sizeof(A)/sizeof(int);
    int nb = sizeof(B)/sizeof(int);
    int *pArray[]={A,B};
    int i=0;
    int *ptr;
    cout<<"-----------ARRAY A-------------"<<endl;
    while(i<na){
        
        cout<<"A["<<i<<"]"<<" ->  *(*pArray+"<<i<<") = "<<*(*pArray+i)<<endl;
        i++;
    }
    cout<<"------------------------"<<endl;
    i=0;
    cout<<"----------ARRAY B--------------"<<endl;
    while(i<nb){
        
        cout<<"B["<<i<<"]"<<" ->  *(*(pArray+1)+"<<i<<") = "<<*(*(pArray+1)+i)<<endl;
        i++;
    }
    cout<<"------------------------"<<endl;
    // cout<<(*pArray+i)<<" -> "<<*(*(pArray+1)+2)<<endl;
    return 0;
}
double average(int *A, int n){
    int sum=0;
    for (int i=0;i<n;i++)
        sum+= *(A+i);
    return ((double) sum)/n;
}




