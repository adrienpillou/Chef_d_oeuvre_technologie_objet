/*EXERCICE 5 CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>

struct Complexe{
	float Re;
	float Im;
};

void Saisie(int*, char*);
void Affiche(int, char*);
int Addition(int, int);
int Multiplication(int, int);
int Division(int, int);

void Saisie(float*, char*);
void Affiche(float, char*);
float Addition(float, float);
float Multipilcation(float, float);
float Division(float, float);

void Saisie(Complexe*, char*);
void Affiche(Complexe, char*);
Complexe Addition(Complexe, Complexe);
Complexe Multiplication(Complexe, Complexe);
Complexe Division(Complexe, Complexe);



int main()
{
	
	int choix=0;
	bool peutContinuer = false;
	
	while(!peutContinuer){
		//Menu
		cout<<"1. Nombres entiers"<<endl;
		cout<<"2. Nombres reels"<<endl;
		cout<<"3. Nombres complexe"<<endl;
		Saisie(&choix,"Choisissez le mode : " );
		switch(choix){
			case 1:
				//Nombres entiers :
				cout<<"\n*** NOMBRES ENTIERS ***"<<endl;
				int entier1, entier2;
				Saisie(&entier1, "Veuillez entrer le premier entier : ");
				Saisie(&entier2, "Veuillez entrer le second entier : ");
				Affiche(entier1, "Valeur du premier entier: ");
				Affiche(entier2, "Valeur du second entier: ");
				Affiche(Addition(entier1, entier2), "Resultat de l'addition : ");
				Affiche(Multiplication(entier1, entier2), "Resultat de la multiplication : ");
				Affiche(Division(entier1, entier2), "Resultat de la division : ");
				peutContinuer=true;
			break;
			
			case 2:
				//Nombres reels :
				cout<<"\n*** NOMBRES REELS ***"<<endl;
				float reel1, reel2;
				Saisie(&reel1, "Veuillez entrer le premier reel : ");
				Saisie(&reel2, "Veuillez entrer le second reel : ");
				Affiche(reel1, "Valeur du premier reel : ");
				Affiche(reel2, "Valeur du second reel : ");
				Affiche(Addition(reel1, reel2),"Resultat de l'addition : ");
				Affiche(Multiplication(reel1, reel2),"Resultat de la multiplication : ");
				Affiche(Division(reel1, reel2),"Resultat de la division : ");
				peutContinuer=true;
			break;
			
			case 3:
				//Nombres complexes :
				cout<<"\n*** NOMBRES COMPLEXES ***"<<endl;
				Complexe comp1,comp2;
				/*Saisie(&comp1.Re, "Veuillez entrer la partie reel du premier nombre : ");
				Saisie(&comp1.Im, "Veuillez entrer la partie imaginaire du premier nombre : ");
				Saisie(&comp2.Re, "Veuillez entrer la partie reel du second nombre : ");
				Saisie(&comp2.Im, "Veuillez entrer la partie imaginaire du second nombre : ");*/
				Saisie(&comp1,"Veuillez entrer la partie reel puis imaginaire du premier nombre complexe : ");
				Saisie(&comp2,"Veuillez entrer la partie reel puis imaginaire du second nombre complexe : ");
				Affiche(comp1, "Valeur du premier nombre complexe : ");
				Affiche(comp2, "Valeur du second nombre complexe : ");
				Affiche(Addition(comp1, comp2), "Resultat de l'addition des deux complexes : ");
				Affiche(Multiplication(comp1, comp2), "Resultat de la multiplication des deux complexes : ");
				Affiche(Division(comp1, comp2), "Resultat de la division des deux complexes : ");
				peutContinuer=true;
			break;
			
			default:
				cout<< "Choix incorrect !\n" <<endl;
			break;
		}
	}
	return 0;
}

#pragma region INT
void Saisie(int* nombre, char* message){
	cout << message;
	cin >> *nombre;
}

void Affiche(int nombre, char* message){
	cout << message << nombre << endl;
}

int Addition(int a, int b){
	return a+b;
}

int Multiplication(int a, int b){
	return a*b;
}

int Division(int a, int b){
	return a/b;
}
#pragma endregion INT


#pragma region FLOAT
void Saisie(float* nombre, char* message){
	cout << message;
	cin >> *nombre;
}

void Affiche(float nombre, char* message){
	cout << message << nombre <<endl;
}

float Addition(float a, float b){
	return a+b;
}

float Multiplication(float a, float b){
	return a*b;
}

float Division(float a, float b){
	return a/b;
}
#pragma endregion FLOAT


#pragma region COMPLEXE
void Saisie(Complexe* nombre, char* message){
	cout << message;
	cin >> (*nombre).Im;
	cin >> (*nombre).Re;
}

void Affiche(Complexe nombre, char* message){
	if(nombre.Im<0) cout << message << nombre.Re << nombre.Im << "i" <<endl;
	else cout << message << nombre.Re << '+' << nombre.Im << "i" <<endl;
}

Complexe Addition(Complexe a, Complexe b){
	Complexe res;
	res.Re = a.Re+b.Re;
	res.Im = a.Im+b.Im;
	return res;
}

Complexe Multiplication(Complexe a, Complexe b){
	Complexe res;
	res.Re = a.Re*b.Re - a.Im*b.Im;
	res.Im = a.Re*b.Im + a.Im*b.Re;
	return res;
}

Complexe Division(Complexe a, Complexe b){
	Complexe res;
	Complexe complement, num, denum;
	complement.Re=b.Re;
	complement.Im=-b.Im;
	num = Multiplication(a, complement);
	denum = Multiplication(b, complement);
	res.Re = Division(num.Re, denum.Re);
	res.Im = Division(num.Im, denum.Re);
	return res;
}
#pragma endregion COMPLEXE





