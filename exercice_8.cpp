/*EXERCICE 8 DU CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <math.h>

void AfficherMessage(char* msg);

#pragma region CLASSES ET CONSTRUCTEURS
class Entiers
{ 
	friend class Complexes operator +(Entiers, class Complexes);// class nécessaire ici
	friend Complexes operator +(Complexes, Entiers);
	
	public:
	int entier;	
	Entiers(int);
	void Affiche(char * chaine) {
		cout<< chaine << entier << endl;
	}
	
	void Entree(){
		AfficherMessage("Entrez une valeur : ");
		int valeur;
		cin>>valeur;
		entier=valeur;
	}
};

Entiers::Entiers(int valeur=0){
	entier=valeur;
}

class Reels
{ 
	friend class Complexes operator +(Reels, class Complexes);
	friend Complexes operator +(Complexes, Reels);
	public:
	float reel;
	Reels(float);
	void Affiche(char * chaine) {
		cout<< chaine << reel << endl;
	}
	
	void Entree(){
		AfficherMessage("Entrez une valeur : ");
		float valeur;
		cin>>valeur;
		reel=valeur;
	}
};

Reels::Reels(float valeur=0){
	reel=valeur;
}

class Complexes
{
	friend Complexes operator +(Complexes, Complexes);
	friend Complexes operator *(Complexes, Complexes);
	friend Complexes operator /(Complexes, Complexes);
	friend Complexes operator +(Reels, Complexes);
	friend Complexes operator *(Reels, Complexes);
	friend Complexes operator /(Reels, Complexes);
	friend Complexes operator +(Complexes, Reels);
	friend Complexes operator *(Complexes, Reels);
	friend Complexes operator /(Complexes, Reels);
	public :
	float reel, imaginaire;
	Complexes(float, float);
	
	void Affiche(char * chaine) {
	cout << chaine << reel << imaginaire << endl;
	}
	
	void Entree(){
		float r,i;
		AfficherMessage("Partie Reelle : ");
		cin>>r;
		AfficherMessage("Partie Imaginaire : ");
		cin>>i;
		reel=r;
		imaginaire=i;
	}
	
	float Module(){
		float module;
		module=sqrt(pow(reel,2)+pow(imaginaire,2));
		return module;
	}
};

Complexes::Complexes(float re=0, float im=0){
	reel = re;
	imaginaire = im;
}
#pragma endregion CLASSES ET CONSTRUCTEURS

#pragma region OPERATEURS
Entiers operator +(Entiers n1, Entiers n2)
{
	return n1.entier+n2.entier;
}
Entiers operator *(Entiers n1, Entiers n2)
{
	return n1.entier*n2.entier;
}
Entiers operator /(Entiers n1, Entiers n2)
{
	if(n2.entier!=0)return n1.entier/n2.entier;
	else{
		AfficherMessage("Erreur : division par zero !");
		return 0;
	} 
}

Reels operator +(Reels r1, Reels r2)
{
	return r1.reel+r2.reel;
}
Reels operator *(Reels r1, Reels r2)
{
	return r1.reel*r2.reel;
}
Reels operator /(Reels r1, Reels r2)
{
	if(r2.reel!=0)return r1.reel/r2.reel;
	else{
		AfficherMessage("Erreur : division par zero !");
		return 0;
	}
}


Complexes operator +(Complexes z1, Complexes z2)
{
	Complexes aux;
	aux.reel=z1.reel+z2.reel; 
	aux.imaginaire=z1.imaginaire+z2.imaginaire;
	return aux;
}
Complexes operator *(Complexes z1, Complexes z2)
{
	Complexes aux;
	aux.reel = z1.reel * z2.reel - z1.imaginaire * z2.imaginaire;
	aux.imaginaire = z1.reel * z2.imaginaire + z1.imaginaire * z2.reel;
	return aux;
}
Complexes operator /(Complexes z1, Complexes z2)
{
	Complexes aux;
	Complexes complement, num, denum;
	if(z2.imaginaire==0 && z2.reel==0){
		AfficherMessage("Erreur : division par 0 !\n");
		aux.imaginaire=0;
		aux.reel=0;
		return aux;
	}
	complement.reel=z2.reel;
	complement.imaginaire=-z2.imaginaire;

	num=z2*complement;
	denum=z1*complement;
	aux.reel=num.reel/denum.reel;
	aux.imaginaire=num.imaginaire/denum.reel;
	return aux;
}

Complexes operator +(Reels x, Complexes z)
{
	Complexes aux;
	aux.reel=x.reel+z.reel;
	aux.imaginaire=z.imaginaire;
	return aux;
}
Complexes operator *(Reels x, Complexes z)
{
	Complexes aux;
	aux.reel=z.reel*x.reel;
	aux.imaginaire=z.imaginaire*x.reel;
	return aux;
}
Complexes operator /(Reels x, Complexes z)
{
	Complexes aux;
	aux.reel=z.reel/x.reel;
	aux.imaginaire=z.imaginaire/x.reel;
	return aux;
}

Complexes operator +(Complexes z, Reels x)
{
	Complexes aux;
	aux.reel=x.reel+z.reel; 
	aux.imaginaire=z.imaginaire ;
	return aux;
}
Complexes operator *(Complexes z, Reels x)
{
	Complexes aux;
	aux.reel=z.reel*x.reel;
	aux.imaginaire=z.imaginaire*x.reel;
	return aux;
}
Complexes operator /(Complexes z, Reels x)
{
	Complexes aux;
	aux.reel=z.reel/x.reel;
	aux.imaginaire=z.imaginaire/x.reel;
	return aux;
}

Complexes operator +(Entiers x, Complexes z)
{
	Complexes aux;
	aux.reel=x.entier+z.reel;
	aux.imaginaire=z.imaginaire;
	return aux;
}
Complexes operator *(Entiers x, Complexes z)
{
	Complexes aux;
	aux.reel=z.reel*x.entier;
	aux.imaginaire=z.imaginaire*x.entier;
	return aux;
}
Complexes operator /(Entiers x, Complexes z)
{
	Complexes aux;
	aux.reel=z.reel/x.entier;
	aux.imaginaire=z.imaginaire/x.entier;
	return aux;
}

Complexes operator +(Complexes z, Entiers x)
{
	Complexes aux;
	aux.reel=x.entier+z.reel; 
	aux.imaginaire=z.imaginaire ;
	return aux;
}
Complexes operator *(Complexes z, Entiers x)
{
	Complexes aux;
	aux.reel=z.reel*x.entier;
	aux.imaginaire=z.imaginaire*x.entier;
	return aux;
}
Complexes operator /(Complexes z, Entiers x)
{
	Complexes aux;
	aux.reel=z.reel/x.entier;
	aux.imaginaire=z.imaginaire/x.entier;
	return aux;
}

bool operator <(Entiers a, Entiers b){
	return (a.entier<b.entier)?true:false;
}
bool operator >(Entiers a, Entiers b){
	return (a.entier>b.entier)?true:false;
}

bool operator <(Reels a, Reels b){
	return(a.reel<b.reel)?true:false;
}
bool operator >(Reels a, Reels b){
	return(a.reel>b.reel)?true:false;
}

bool operator <(Complexes a, Complexes b){
	return(a.Module()<b.Module())?true:false;
}
bool operator >(Complexes a, Complexes b){
	return(a.Module()>b.Module())?true:false;
}
#pragma endregion OPERATEURS

int main()
{
	Entiers a(32), b(64);
	a.Affiche("a = ");
	b.Affiche("b = ");
	if(a<b)AfficherMessage("A est plus petit que B");
	system("PAUSE");
	return(EXIT_SUCCESS);
}

void AfficherMessage(char* msg){
	cout<< msg <<endl;
}
