/*EXERCICE 3 DU CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

using namespace std;
#include <iostream>

int f(int n);

int main(int argc, char** argv)
{
	int n;
	cout << "Entrez n : "<<endl;
	/*for(int n=64;n<=128;n++){
		cout <<"f("<< n <<") = "<<f(n)<<endl;
	}*/
	cin >> n;
	cout <<"f(n) = "<<f(n)<<endl;
	system("pause");
	return 0;
}

int f(int n)
{
	if(n>100) return(n-10); 
	else{
		cout<<n+11<<endl;
		return (f(f(n+11)));
	} 
}
