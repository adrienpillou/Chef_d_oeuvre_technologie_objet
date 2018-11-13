using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define EULER 2.71828

int Factorielle(int n);//Prototype de la fonction factorielle

int main()
{
	double seuil, m_euler, somme=0, valeur;
	int n=1;
	int iter_max;
	
	cout << "Saisir le seuil de convergence du calcul: ";
	cin >> seuil;
	valeur=1./Factorielle(n);
	cout << "Nombre maximum d'iterations acceptable : ";
	cin >> iter_max ;
	cout<<"\n";
	while ((valeur > seuil) && (n < iter_max )){ // Boucle de calcul
		// Nombre d'itérations inconnu à priori donc borné par le maximum autorisé
		somme+=valeur;
		n++;
		valeur=1./Factorielle(n);
		cout<<"iteration " <<n<<" : "<<valeur <<endl;
	}
	cout<<"\n";
	//m_euler = sqrt(6*somme);
	m_euler = 1+somme;
	cout <<"Seuil de convergence : "<< seuil <<" Cout (nombre d'iterations) : "<< n << endl;
	cout <<"Valeur approchee de euler = "<< m_euler << " Precision: " << fabs(EULER-m_euler) << endl;
	system("PAUSE");
	return(EXIT_SUCCESS);
}

int Factorielle(int n){//Fonction de calcul de la factorielle de n
		int i=1, res=1;
		for(i=1 ; i<=n ; i++){
				res*=i;
		}
		return res;
}
