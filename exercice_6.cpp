/*EXERCICE 6 CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

//https://www.geogebra.org/m/nd9fTdHh

using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
const int n=3;

struct disque{
	int taille;
	disque *tour;
};

void Afficher(char* msg,bool fin);
void AfficherTour(disque *tour);
void RemplirTourOrigine();

void Recapituler();
void DeplacerDisque(disque *cible, disque *tourArrivee);
void AjouterDisque(disque cible, disque *tourArrivee);
void SupprimerDisque(disque *cible);

void Hanoi(disque *n, disque *source, disque *destination, disque *aux);

disque tourOrigine[n];//tableau de disque
disque tourIntermediaire[n];//tableau de disque
disque tourDestination[n];//tableau de disque


int main()
{
	RemplirTourOrigine();
	//DeplacerDisque(&tourOrigine[n-1], tourDestination);
	Hanoi(&tourOrigine[n-1],tourOrigine,tourDestination,tourIntermediaire);
	system("PAUSE");
	return 0;
}

void Hanoi(disque *cible, disque *source, disque *destination, disque *aux){
/*START
Procedure Hanoi(disk, source, dest, aux)
   IF disk == 1, THEN
      move disk from source to dest             
   ELSE
      Hanoi(disk - 1, source, aux, dest)     // Step 1
      move disk from source to dest          // Step 2
      Hanoi(disk - 1, aux, dest, source)     // Step 3
   END IF
END Procedure
STOP*/
	Recapituler();
	if((*cible).taille == 1){
		DeplacerDisque(cible,destination);
	}else{
		//Hanoi(,);
		DeplacerDisque(cible,destination);
		//Hanoi(,);
	}
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
