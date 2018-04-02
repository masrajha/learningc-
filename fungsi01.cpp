#include <iostream>
#include <ctype.h>

double hitungPajak(double);
void cetak();
int max(int, int);
double max(double,double);

using namespace std;
int main(){
	char c;
	int p=10,q=5;
	double r=2.3,s=6.7;
	float t=4.8f;
	c='a';
	cout<<c<<endl;
	cout<<(int) c<<endl;
	cout<<(char)toupper(c)<<endl;
	cout<<hitungPajak(6000);
	cetak();
	cout<<max(p,q)<<endl;
	cout<<max(p * 1.,s)<<endl;
	cout<<t;
	return 0;
	
}

double hitungPajak(double income){
	if (income<5000) return 0;
	
	double pajak=income*0.01;
	return pajak;
}
void cetak(){
	cout<<"ilkom Unila\n";
}
int max(int a, int b){
	cout<<" Int \n";
	if (a>b) return a;
	return b;
}
double max(double a, double b){
	cout<<" double \n";
	if (a>b) return a;
	return b;
}