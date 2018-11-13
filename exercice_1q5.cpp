using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265
const int iter_max = 100000 ; // Variable globale
//Prototypes
void pi(double);
void euler(double);

int main(){ 
	double seuil = 1; // Seuil de convergence
	int pas = 10;
	
	for (int i =1 ; i < 15 ; i++){ // Boucle de calcul pour un seuil donné
		seuil = seuil/pas ;
		cout << endl << "Seuil de convergence : " << seuil << endl;
		pi(seuil) ;
	}
	system("PAUSE"); 
	return(EXIT_SUCCESS);
}
	
void pi(double seuil){
	int carre(int); // La fonction carre retourne un int, 1 argument int
	double somme=0, valeur;
	int n = 1; // Initialisation de la boucle de calcul
	valeur=1./carre(n);
		while ((valeur > seuil) && (n < iter_max )){ // Boucle de calcul
			// Nombre d'itérations inconnu à priori donc borné par le maximum autorisé
			somme+=valeur;
			n=n+1;
			valeur=1./carre(n);
		}
	double pi = sqrt(6*somme);
	cout << " Valeur approchée de pi = " << pi << endl;
	cout <<" Coût (nombre d'itérations) : "<< n <<" Précision: " << fabs(PI-pi)<< endl;
}
