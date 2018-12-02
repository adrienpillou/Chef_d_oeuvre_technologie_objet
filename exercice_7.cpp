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

class Reels
{
	float valeur; // valeur est un attribut privé par défaut
	public :
	// méthode externe amicale
	friend void permut(Reels &, Reels &);
	void saisie() // méthode de saisie
	{
		cout << "Valeur Reel a saisir : " ;
		cin >> valeur;
	}
	
	void affichage(char * chaine) // méthode d'affichage
	{
		cout << chaine << valeur << endl;
	}
	
	void addition(Reels A, Reels B) // méthode d'addition
	{
		valeur=A.valeur+B.valeur;
	}
	
	void mult(Reels A, Reels B){
		valeur =A.valeur*B.valeur;
		
	}
	
	void div(Reels A, Reels B){		
		valeur=A.valeur/B.valeur;
	}
	
	void modulo(Reels A, Reels B){
		valeur=A.valeur%B.valeur;
	}
};//Fin de la classe des Reels

class Complexes
{
	float Reel; // Reel est un attribut privé par défaut
	float Im;
	public :
	// méthodes externes amicales
	friend void permut(Complexes &, Complexes &);
	friend float module(Complexes);
	
	void saisie(char * chaine) // méthode de saisie
	{
		cout << chaine << "Partie réelle à saisir : " ;
		cin >> Reel;
		cout << chaine << "Partie imaginaire à saisir : " ;
		cin >> Im;
	}
	
	void affichage(char * chaine) // méthode d'affichage
	{
		cout << chaine << " : " << Reel << "\t" << Im << endl;
	}
	
	void addition(Complexes A, Complexes B) // méthode d'addition
	{
		Reel=A.Reel+B.Reel;
		Im=A.Im+B.Im;
	}
	void conjugue(void) {
		Im=-Im;
	}
	void multiplication(Complexes A, Complexes B)
	{
		Reel=A.Reel*B.Reel-A.Im*B.Im;
		Im=A.Reel*B.Im+A.Im*B.Reel;
	}
	
	void division(Complexes A, Complexes B)
	{
		Complexes aux;
		B.conjugue();
		aux.multiplication(A,B);
		aux.division(aux,module(B)*module(B));
		*this=aux; // similaire à : Reel=aux.Reel; Im=aux.Im;
	}
};//Fin de la classe des complexes

//Prototypes des fonctions de permutation pour les différents types de variables
void permut(Entiers &i, Entiers &j);
void permut(Reels &i, Reels &j);
void permut(Complexes &i, Complexes &j);

int main()
{
	Complexes A,B,C;
	A.saisie("A ");
	A.affichage("A");
	cout << "module(A)=" << module(A) << endl;
	A.conjugue();
	A.affichage("conjugué");
	A.division(A, module(A));
	A.affichage("A/module(A) = ");
	B.saisie("B ");
	C.addition(A,B);
	C.affichage("somme ");
	permut(B,C);
	B.affichage("B");
	C.affichage("C");
	A.saisie("A ");
	A.affichage("A");
	B.saisie("B ");
	C.multiplication(A,B);
	C.affichage("produit ");
	C.division(A,B);
	C.affichage("A/B = ");
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

void permut(Reels &i, Reels &j)
{
	Entiers aux;
	aux.valeur=i.valeur;
	i.valeur=j.valeur;
	j.valeur=aux.valeur;
}

void permut(Complexes &i, Complexes &j)
{
	Entiers aux;
	aux.valeur=i.valeur;
	i.valeur=j.valeur;
	j.valeur=aux.valeur;
}

