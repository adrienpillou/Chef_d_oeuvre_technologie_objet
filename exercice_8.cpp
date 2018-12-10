using namespace std;
#include <iostream>
#include <stdlib.h>

void AfficherMessage(char* msg);

class Reels
{ 
	float Reel;
	friend class Complexes operator +(Reels, class Complexes);// class nécessaire ici
	friend Complexes operator +(Complexes, Reels);
	public:
	Reels(float);	
	/*Reels(float i=0) {
		Reel=i;
	}*/
	void affiche(char * chaine) {
		cout<< chaine << " : " << Reel << endl;
	}
	
	void entree(){
		AfficherMessage("Entrez une valeur : ");
		float valeur;
		cin>>valeur;
		Reel=valeur;
	}
};

Reels::Reels(float valeur=0){
	Reel=valeur;
}

class Complexes
{
	float Reel, Imaginaire;
	friend Complexes operator +(Complexes, Complexes);
	friend Complexes operator +( Reels, Complexes);
	friend Complexes operator +(Complexes, Reels);
	public :
	Complexes(float, float);
	//Complexes(float re=0,float im=0) { Reel=re; Imaginaire=im; }
	void affiche(char * chaine) {cout << chaine << Reel << " : " << Imaginaire << endl;}
	
	void entree(){
		float r,i;
		AfficherMessage("Partie Reelle : ");
		cin>>r;
		AfficherMessage("Partie Imaginaire : ");
		cin>>i;
		Reel=r;
		Imaginaire=i;
	}
};

Complexes::Complexes(float valeurReel=0, float valeurImaginaire=0){
	Reel = valeurReel;
	Imaginaire = valeurImaginaire;
}

Complexes operator +(Complexes z1, Complexes z2)
{
	Complexes aux;
	aux.Reel=z1.Reel+z2.Reel; 
	aux.Imaginaire=z1.Imaginaire+z2.Imaginaire;
	return aux;
}

Complexes operator +(Reels x, Complexes z)
{
	Complexes aux;
	aux.Reel=x.Reel+z.Reel;
	aux.Imaginaire=z.Imaginaire;
	return aux;
}

Complexes operator +(Complexes z, Reels x)
{
	Complexes aux;
	aux.Reel=x.Reel+z.Reel; 
	aux.Imaginaire=z.Imaginaire ;
	return aux;
}

int main()
{
	Complexes z1(2,3), z2(3,4); // Instanciation par appel de constructeur (Defaut)
	Reels r(0.55);
	r.affiche("r ");
	//z1.entree();
	//z2.entree();
	z1.affiche("z1 ");
	z2.affiche("z2 ");
	(z2+z1).affiche("z2+z1 ");
	Reels x(5); x.affiche("x ");
	(x+z1).affiche("x+z1 ");
	(z1+x).affiche("z1+x ");
	system("PAUSE");
	return(EXIT_SUCCESS);
}

void AfficherMessage(char* msg){
	cout<< msg <<endl;
}

