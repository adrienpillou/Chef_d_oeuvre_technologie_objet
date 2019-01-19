using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265

int main()
{
	int carre(int); // La fonction carre retourne un int, 1 argument int
	double seuil;
	cout << "Saisir le seuil de convergence du calcul : ";
	cin >> seuil;
	double somme, valeur; 
	int n=1;
	valeur=1./carre(n);
	cout << "Nombre maximum d'iterations acceptable : ";
	int iter_max; cin >> iter_max;
	while ((valeur > seuil) && (n < iter_max )) // Boucle de calcul
	// Nombre d'it�rations inconnu � priori donc born� par le maximum autoris�
	{
		somme+=valeur;
		n=n+1;
		valeur=1./carre(n);
	}
	double pi = sqrt(6*somme);
	cout << "Seuil de convergence : " << seuil << " Co�t (nombre d'iterations) : " << n << endl;
	cout <<"Valeur approchee de pi = " << pi << " Precision : " << fabs(3.14159265-pi)<< endl;
	system("PAUSE");
	return(EXIT_SUCCESS);
}

int carre(int p) // Fonction de calcul du carr� d'un nombre fourni en argument (ici p)
{
	return (p*p);
}
