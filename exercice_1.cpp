/*EXERCICE 1 DU CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/
using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define EULER 2.71828182

int factorielle(int n);//Prototype de la fonction factorielle

int main()
{
	double seuil, m_euler, somme=0, valeur;
	int n=0;
	int iter_max;
	
	cout << "Saisir le seuil de convergence du calcul: ";
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
		cout<<"iteration " <<n<<" : "<<valeur <<endl;
	}
	cout<<"\n";
	m_euler = somme;
	cout <<"Seuil de convergence : "<< seuil <<" Cout (nombre d'iterations) : "<< n << endl;
	cout <<"Valeur approchee de euler = "<< m_euler << " Precision: " << fabs(EULER-m_euler) << endl;
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


