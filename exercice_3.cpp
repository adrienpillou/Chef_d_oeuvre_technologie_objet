#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int f(int n)
{
	if(n>100) return(n-10); 
	else return (f(f(n+11)));
}

int main(int argc, char** argv)
{
	int n;
	cout << "Entrez un n : "<<endl;
	cin >> n;
	cout <<"f(n) = "<<f(n);
	return 0;
}

