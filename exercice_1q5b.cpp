using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define EULER 2.71828182

const int iter_max = 100000 ; // Variable globale

int main()
{
	double seuil = 1; // Seuil de convergence
	int pas = 10;
	void euler(double);
	for (int i =1 ; i < 16 ; i++) // Boucle de calcul pour un seuil donné
	{
		seuil = seuil/pas ;
		cout << endl << "Seuil de convergence : " << seuil << endl;
		euler(seuil) ;
	}
	system("PAUSE");
	return(EXIT_SUCCESS);
}

void euler(double seuil)
{
	int factorielle(int); // La fonction carre retourne un int, 1 argument int
	double somme, valeur;
	int n = 0; // Initialisation de la boucle de calcul
	valeur=1./factorielle(n);
	while ((valeur > seuil) && (n < iter_max )) // Boucle de calcul
	// Nombre d'itérations inconnu à priori donc borné par le maximum autorisé
	{
		somme+=valeur;
		n=n+1;
		valeur=1./factorielle(n);
	}
	double euler = somme;
	cout << " Valeur approchee de euler = " << euler << endl;
	cout <<" Cout (nombre d'iterations) : "<< n <<" Precision : " << fabs(EULER-euler)<< endl;
}

int factorielle(int n){//Fonction de calcul de la factorielle de n
	int i=1, res=1;
	for(i=1 ; i<=n ; i++){
			res*=i;
	}
	return res;
}
