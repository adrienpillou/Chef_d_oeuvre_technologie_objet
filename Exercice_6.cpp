/*EXERCICE 6 CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

//https://www.geogebra.org/m/nd9fTdHh

using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>

struct disque{
	int taille;
};

void Afficher(char* msg,bool fin);
void AfficherTour(disque *tour);
void RemplirTourOrigine();

void Recapituler();
void DeplacerDisque(disque *cible, disque *tourArrivee);
void AjouterDisque(disque cible, disque *tourArrivee);
void SupprimerDisque(disque *cible);
#define n 3

disque tourOrigine[n];//tableau de disque
disque tourIntermediaire[n];//tableau de disque
disque tourDestination[n];//tableau de disque


int main()
{
	RemplirTourOrigine();
	Recapituler();
	//DeplacerDisque(&tourOrigine[n-1], tourDestination);
	//Recapituler();

	system("PAUSE");
	return 0;
}

void Recapituler(){
	Afficher("Tour de depart :",true);
	AfficherTour(tourOrigine);
	Afficher("\nTour intermediaire :",true);
	AfficherTour(tourIntermediaire);
	Afficher("\nTour de destination :",true);
	AfficherTour(tourDestination);
	Afficher("\n",true);
}

void DeplacerDisque(disque *cible, disque *tourArrivee){
	AjouterDisque(*cible, tourArrivee);
	SupprimerDisque(cible);
}

void AjouterDisque(disque cible, disque *tourArrivee){
	int i;
	for(i=n-1;i>=0;i--){
		if(tourArrivee[i].taille>0){//Au-dessus d'un disque existant
			tourArrivee[i+1]=cible;
			return;
		}else if(i==0 && tourArrivee[i].taille==0){//tout en bas de la pile
			tourArrivee[i]=cible;
			return;
		}
	}
}

void SupprimerDisque(disque *cible){
	(*cible).taille=0;
}

void RemplirTourOrigine(){
	for(int i=0;i<n;i++){
		tourOrigine[i].taille=n-i;
	}
}

void AfficherTour(disque *tour){
	char buffer[2];
	for(int i=0;i<n;i++){
		itoa(tour[i].taille,buffer,10);
		Afficher(buffer,false);
	}
}

void Afficher(char* msg,bool fin){
	if(fin)cout<< msg <<endl;
	else cout<< msg;
}
