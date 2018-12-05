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

	void Saisie() // méthode de saisie
	{
		cout << "Valeur entiere a saisir : " ;
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
	
	void Multiplication(Entier A, Entier B){
		valeur =A.valeur*B.valeur;
	}
	
	void Div(Entier A, Entier B){// /!\ div par 0
		if(B.valeur != 0){
			valeur=A.valeur/B.valeur;
		}else{
			AfficherMessage("Erreur : Division par 0 !");
			valeur=0;
		}
	}
	
	void Modulo(Entier A, Entier B){
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
	
	void Saisie() // méthode de saisie
	{
		cout << "Valeur Reel a saisir : " ;
		cin >> valeur;
	}
	
	void Affichage(char * chaine) // méthode d'affichage
	{
		cout << chaine << valeur << endl;
	}
	
	void Addition(Reel A, Reel B) // méthode d'addition
	{
		valeur=A.valeur+B.valeur;
	}
	
	void Multiplication(Reel A, Reel B){
		valeur =A.valeur*B.valeur;
		
	}
	
	void Div(Reel A, Reel B){
		if(B.valeur!=0)valeur=A.valeur/B.valeur;
		else AfficherMessage("Erreur : Division par 0 !");	
	}
	
	void Modulo(Reel A, Reel B){
		if(B.valeur!=0)valeur=(int)A.valeur%(int)B.valeur;
		else AfficherMessage("Erreur : Division par 0 !");	
	}
};//Fin de la classe des Reel

class Complexe
{
	float Reel; // Reel est un attribut privé par défaut
	float Im;// Im est un attribut privé par défaut
	public :
	// méthodes externes amicales
	friend void Permut(Complexe &, Complexe &);
	friend float module(Complexe);
	
	void Saisie(char * chaine) // méthode de saisie
	{
		cout << chaine << "Partie reelle a saisir : " ;
		cin >> Reel;
		cout << chaine << "Partie imaginaire a saisir : " ;
		cin >> Im;
	}
	
	void Affichage(char * chaine) // méthode d'affichage
	{
		cout << chaine << " : " << Reel << "\t" << Im << endl;
	}
	
	void Addition(Complexe A, Complexe B) // méthode d'addition
	{
		Reel=A.Reel+B.Reel;
		Im=A.Im+B.Im;
	}
	void Conjugue(void) {
		Im=-Im;
	}
	void Multiplication(Complexe A, Complexe B)
	{
		Reel=A.Reel*B.Reel-A.Im*B.Im;
		Im=A.Reel*B.Im+A.Im*B.Reel;
	}
	
	void Division(Complexe A, Complexe B)
	{
		Complexe aux;
		B.Conjugue();
		aux.Multiplication(A,B);
		//aux.division(aux, Module(B)*Module(B));
		*this=aux; // similaire à : Reel=aux.Reel; Im=aux.Im;
	}
	
	float Module(Complexe A){
		return sqrt((A.Reel*A.Reel)+(A.Im*A.Im));
	}
};//Fin de la classe des Complexe



int main()
{
	Complexe A,B,C;
	A.Saisie("A ");
	A.Affichage("A = ");
	B.Saisie("B ");
	C.Addition(A,B);
	C.Affichage("somme : ");
	C.Multiplication(A,B);
	C.Affichage("multiplication : ");
	C.Division(A,B);
	C.Affichage("division : ");
	//C.Modulo(A,B);
	//C.Affichage("modulo : ");
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
	Entier aux;
	aux.valeur=i.valeur;
	i.valeur=j.valeur;
	j.valeur=aux.valeur;
}

void Permut(Complexe &i, Complexe &j)
{
	Entier aux;
	aux.valeur=i.valeur;
	i.valeur=j.valeur;
	j.valeur=aux.valeur;
}

void AfficherMessage(char* message){
	cout<< message <<endl;	
}
