/*EXERCICE 3 DU CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme r�alis� par Adrien Pillou*/

using namespace std;
#include <iostream>

int f(int n);

int main(int argc, char** argv)
{
	int n;
	cout << "Entrez n : "<<endl;
	cin >> n;
	cout <<"f(n) = "<<f(n)<<endl;
	system("pause");
	return 0;
}

int f(int n)
{
	if(n>100) return(n-10); 
	else return (f(f(n+11)));
}
