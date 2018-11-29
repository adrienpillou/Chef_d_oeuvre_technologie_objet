using namespace std ;
#include <iostream>
#include <stdlib.h>

class Entiers
{
	unsigned int valeur; // valeur est un attribut privé par défaut
	public :
	// méthode externe amicale
	friend void permut(Entiers &, Entiers &);
	
	void saisie() // méthode de saisie
	{
		cout << "Valeur entiere a saisir : " ;
		cin >> valeur;
	}
	
	void affichage(char * chaine) // méthode d'affichage
	{
		cout << chaine << valeur << endl;
	}
	
	void addition(Entiers A, Entiers B) // méthode d'addition
	{
		valeur=A.valeur+B.valeur;
	}
	
	void mult(Entiers A, Entiers B){
		valeur =A.valeur*B.valeur;
		
	}
	
	void div(Entiers A, Entiers B){		
		valeur=A.valeur/B.valeur;
	}
	
	void modulo(Entiers A, Entiers B){
		valeur=A.valeur%B.valeur;
	}
}; // Fin de la classe Entiers

void permut(Entiers &i, Entiers &j);

int main()
{
	Entiers A,B,C;
	A.saisie();
	//A.affichage("A");
	B.saisie();
	//C.addition(A,B);
	//C.affichage("somme :");
	//permut(B,C);
	//B.affichage("B");
	C.mult(A,B);
	C.affichage("C : ");
	system("PAUSE");
	return(EXIT_SUCCESS);
}

void permut(Entiers &i, Entiers &j)
{
	Entiers aux;
	aux.valeur=i.valeur;
	i.valeur=j.valeur;
	j.valeur=aux.valeur;
}



