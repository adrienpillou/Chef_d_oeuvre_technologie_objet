using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define EULER 2.71828182

int factorielle(int n);//Prototype de la fonction factorielle

int main()
{
	double seuil, euler, somme, valeur;
	int iter_max, n;
	cout << "Saisir le seuil de convergence du calcul : ";
	cin >> seuil;
	valeur=1./factorielle(n);
	cout << "Nombre maximum d'iterations acceptable : ";
	cin >> iter_max ;
	cout<<"\n";
	while ((valeur > seuil) && (n < iter_max )){ // Boucle de calcul
		// Nombre d'itérations inconnu à priori donc borné par le maximum autorisé
		somme+=valeur;
		n++;
		valeur=1./factorielle(n);
		cout<<"iteration " << n <<" : "<< somme <<endl;
	}
	cout<<"\n";
	euler = somme;
	cout <<"Seuil de convergence : "<< seuil <<" Cout (nombre d'iterations) : "<< n << endl;
	cout <<"Valeur approchee de euler = "<< euler << " Precision : " << fabs(EULER-euler) << endl;
	system("PAUSE");
	return(EXIT_SUCCESS);
}

int factorielle(int n){//Fonction de calcul de la factorielle de n
	int i=1, res=1;
	for(i=1 ; i<=n ; i++){
			res*=i;
	}
	return res;
}


