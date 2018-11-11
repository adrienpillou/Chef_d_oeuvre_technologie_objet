/*EXERCICE 2 CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

#include <stdlib.h>
using namespace std;
#include <iostream>
#include <stdio.h>
#define Nmin 26
#define Nmaj 26
#define Nnombres 10
#define Nautres 1

int main(void) {// Histogramme des caractères d'un texte saisi
	int effectif[Nmin+Nmaj+Nnombres+Nautres];
	int total = 0;
	int c; // initialisation
	
	for(int i = 0; i < Nmin+Nmaj+Nnombres+Nautres;i++) 
		effectif[i]=0;
	while ((c=getchar())!=EOF){
		if ((char)c =='\n') continue;
		total++;
		if (c >='a' && c <='z') effectif[c-'a']++;
		else if (c >='A' && c <='Z') effectif[c-'A'+Nmin]++;
		else if (c >='0' && c <='9') effectif[c-'0'+Nmin+Nmaj]++;
		else effectif[Nmin+Nmaj+Nnombres]++;
	}
	cout << "Nombre total de caractères saisis " << total << endl;
	cout << "Tableau des effectifs " << endl; // Affichage intermédiaire
	for(int i = 0; i < Nmin;i++)
		printf("%c : %d\n",i+'a',effectif[i]);
	for(int i = 0; i < Nmaj;i++)
		printf("%c : %d\n",i+'A',effectif[i+Nmin]);
	for(int i = 0; i < Nnombres;i++)
		printf("%c : %d\n",i+'0',effectif[i+Nmin+Nmaj]);
	printf("autres: %d\n",effectif[Nmin+Nmaj+Nnombres]);
	float pourcentage=0, tpour=0; // Impression de l'histogramme
	for(int i = 0; i < Nmin;i++){
		cout << (char)(i+'a') << " :" ; pourcentage=(float)(effectif[i])/total; tpour+=pourcentage;
		for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
		cout << " " << pourcentage*100 << "%" << endl;
	}
	for(int i = 0; i < Nmaj;i++){
		cout << (char)(i+'A') << " :" ;pourcentage=(float)(effectif[i+Nmin])/total;
		tpour+=pourcentage;
		for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
		cout << " " << pourcentage*100 << "%" << endl;
	}
	for(int i = 0; i < Nnombres;i++){
		cout << (char)(i+'0') << " :" ;
		pourcentage=(float)(effectif[i+Nmin+Nmaj])/total; tpour+=pourcentage;
		for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
		cout << " " << pourcentage*100 << "%" << endl;
	}
	cout <<"Autres :";
	pourcentage=(float)(effectif[Nmin+Nmaj+Nnombres])/total; tpour+=pourcentage;
	for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
	cout << " " << pourcentage*100 << "%" << endl;
	cout << tpour*100 << " % des caractères saisis ont été traités." << endl;
	system("PAUSE");
	return(EXIT_SUCCESS);
}
