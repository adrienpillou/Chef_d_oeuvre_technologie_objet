using namespace std ;
#include <iostream>
#include <stdlib.h>

class Entiers
{
	unsigned int valeur; // valeur est un attribut priv� par d�faut
	public :
	// m�thode externe amicale
	friend void permut(Entiers &, Entiers &);
	void saisie() // m�thode de saisie
	{
		cout << "Valeur entiere a saisir : " ;
		cin >> valeur;
	}
	
	void affichage(char * chaine) // m�thode d'affichage
	{
		cout << chaine << valeur << endl;
	}
	
	void addition(Entiers A, Entiers B) // m�thode d'addition
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
	float valeur; // valeur est un attribut priv� par d�faut
	public :
	// m�thode externe amicale
	friend void permut(Reels &, Reels &);
	void saisie() // m�thode de saisie
	{
		cout << "Valeur Reel a saisir : " ;
		cin >> valeur;
	}
	
	void affichage(char * chaine) // m�thode d'affichage
	{
		cout << chaine << valeur << endl;
	}
	
	void addition(Reels A, Reels B) // m�thode d'addition
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
	float Reel; // Reel est un attribut priv� par d�faut
	float Im;
	public :
	// m�thodes externes amicales
	friend void permut(Complexes &, Complexes &);
	friend float module(Complexes);
	
	void saisie(char * chaine) // m�thode de saisie
	{
		cout << chaine << "Partie r�elle � saisir : " ;
		cin >> Reel;
		cout << chaine << "Partie imaginaire � saisir : " ;
		cin >> Im;
	}
	
	void affichage(char * chaine) // m�thode d'affichage
	{
		cout << chaine << " : " << Reel << "\t" << Im << endl;
	}
	
	void addition(Complexes A, Complexes B) // m�thode d'addition
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
		*this=aux; // similaire � : Reel=aux.Reel; Im=aux.Im;
	}
};//Fin de la classe des complexes

//Prototypes des fonctions de permutation pour les diff�rents types de variables
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
	A.affichage("conjugu�");
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

