/*EXERCICE 7 DU CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

using namespace std ;
#include <iostream>
#include <stdlib.h>
#include <math.h>

void AfficherMessage(char*);

class Entier
{
	unsigned int valeur; // valeur est un attribut privé par défaut
	public :
	friend void Permut(Entier &, Entier &);// méthode externe amicale

	void Saisie(char *chaine) // méthode de saisie
	{
		cout << "Valeur entiere de "<< chaine <<" a saisir : " ;
		cin >> valeur;
	}
	
	void Affichage(char * chaine) // méthode d'affichage
	{
		cout << chaine << valeur << endl;
	}
	
	void Addition(Entier A, Entier B) // méthode d'addition
	{
		valeur=A.valeur+B.valeur;
	}
	
	void Multiplication(Entier A, Entier B)// méthode de multiplication
	{
		valeur =A.valeur*B.valeur;
	}
	
	void Division(Entier A, Entier B)// méthode de division
	{
		if(B.valeur != 0){
			valeur=A.valeur/B.valeur;
		}else{
			AfficherMessage("Erreur : Division par 0 !");
			valeur=0;
		}
	}
	
	void Modulo(Entier A, Entier B)// méthode modulo
	{
		if(B.valeur!=0)valeur=A.valeur%B.valeur;
		else{
			AfficherMessage("Erreur : Division par 0 !");
			valeur=0;
		}
	}
};// Fin de la classe Entier

class Reel
{
	float valeur; // valeur est un attribut privé par défaut
	public :
	// méthode externe amicale
	friend void Permut(Reel &, Reel &);
	
	void Saisie(char *chaine) // méthode de saisie
	{
		cout << "Valeur Reelle de "<< chaine <<" a saisir : " ;
		cin >> valeur;
	}
	
	void Affichage(char * chaine)
	{
		cout << chaine << valeur << endl;
	}
	
	void Addition(Reel A, Reel B)
	{
		valeur=A.valeur+B.valeur;
	}
	
	void Multiplication(Reel A, Reel B){
		valeur =A.valeur*B.valeur;
		
	}
	
	void Division(Reel A, Reel B){
		if(B.valeur!=0)valeur=A.valeur/B.valeur;
		else {
			AfficherMessage("Erreur : Division par 0 !");	
			valeur=0;
		}
	}
	
	void Modulo(Reel A, Reel B){
		if(B.valeur!=0){
			valeur=(int)A.valeur%(int)B.valeur;
		}
		else{
			AfficherMessage("Erreur : Division par 0 !");
			valeur=0;	
		} 
	}
};//Fin de la classe Reel

class Complexe
{
	float Reel; // Reel est un attribut privé par défaut
	float Im;// Im est un attribut privé par défaut
	public :
	// méthodes externes amicales
	friend void Permut(Complexe &, Complexe &);
	friend float Module(Complexe);
	
	void Saisie(char *chaine)
	{
		cout << "Partie reelle de "<< chaine <<" a saisir : " ;
		cin >> Reel;
		cout << "Partie imaginaire de "<< chaine <<" a saisir : " ;
		cin >> Im;
	}
	
	void Affichage(char * chaine)
	{
		char signe;
		signe='+';
		if(Im<0)signe='-';
		cout << chaine << Reel << signe <<abs(Im) <<"i"<< endl;
	}
	
	void Addition(Complexe A, Complexe B)
	{
		Reel=A.Reel+B.Reel;
		Im=A.Im+B.Im;
	}
	
	void Conjugue(void) 
	{
		Im=-Im;
	}
	
	void Multiplication(Complexe A, Complexe B)
	{
		Reel = A.Reel * B.Reel - A.Im * B.Im;
		Im = A.Reel * B.Im + A.Im * B.Reel;
	}
	
	void Division (Complexe A, float x) 
	{
		Reel=A.Reel/x;
		Im=A.Im/x;
	}
	
	void Division(Complexe A, Complexe B)
	{
		Complexe aux;
		B.Conjugue();
		aux.Multiplication(A,B);
		if(Module(B)!=0){
			aux.Division(aux, Module(B)*Module(B));
			*this=aux; // similaire à : Reel=aux.Reel; Im=aux.Im;
		}
		else{
			AfficherMessage("Erreur : Division par 0 !");
			Reel=0;
			Im=0;
		} 
	}
};//Fin de la classe Complexe

int main()
{
	Reel A,B,C;
	/*A.Saisie("A");
	A.Affichage("A = ");
	cout << "module(A) = " << Module(A) << endl;
	A.Conjugue();
	A.Affichage("conjugue(A) = ");
	A.Division(A, Module(A));
	A.Affichage("A/module(A) = ");
	B.Saisie("B");
	C.Addition(A,B);
	C.Affichage("somme = ");
	Permut(B,C);
	B.Affichage("B = ");
	C.Affichage("C = ");*/
	A.Saisie("A");
	A.Affichage("A = ");
	B.Saisie("B");
	B.Affichage("B = ");
	C.Multiplication(A,B);
	C.Affichage("A*B = ");
	C.Division(A,B);
	C.Affichage("A/B = ");
	system("PAUSE");
	return(EXIT_SUCCESS);
}

void Permut(Entier &i, Entier &j)
{
	Entier aux;
	aux.valeur=i.valeur;
	i.valeur=j.valeur;
	j.valeur=aux.valeur;
}

void Permut(Reel &i, Reel &j)
{
	Reel aux;
	aux.valeur=i.valeur;
	i.valeur=j.valeur;
	j.valeur=aux.valeur;
}

void Permut(Complexe &i, Complexe &j)
{
	Complexe aux;
	aux.Im=j.Im;
	aux.Reel=j.Reel;
	j.Reel=i.Reel;
	j.Im=i.Im;
	i.Im=aux.Im;
	i.Reel=aux.Reel;
}

float Module(Complexe A){
	return sqrt(pow(A.Reel,2)+pow(A.Im,2));
}
	
void AfficherMessage(char* message){
	cout<< message <<endl;	
}
