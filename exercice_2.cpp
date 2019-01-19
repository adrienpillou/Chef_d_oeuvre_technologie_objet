/*EXERCICE 2 DU CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

using namespace std;
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

#define Nmin 26
#define Nmaj 26
#define Nnombres 10
#define Naccentues 23
#define Nautres 1

// Caractères à implémenter : ü é â ä à ç ê ë è ï î ô û ù

int main(void) {// Histogramme des caractères d'un texte saisi
int effectif[Nmin+Nmaj+Nnombres+Naccentues+Nautres];
int total = 0;
int c; // initialisation
for(int i = 0; i < Nmin+Nmaj+Nnombres+Naccentues+Nautres;i++) effectif[i]=0;
while ((c=getchar())!='\n')
{
	//if ((char)c =='n')continue;
	//cout<<c<<endl;
	total++;
	if (c >='a' && c <='z') effectif[c-'a']++;
	else if (c >='A' && c <='Z') effectif[c-'A'+Nmin]++;
	else if (c >='0' && c <='9') effectif[c-'0'+Nmin+Nmaj]++;
	else if(c >=129 && c <=151)effectif[c-129+Nmin+Nmaj+Nnombres]++;
	else effectif[Nmin+Nmaj+Nnombres+Naccentues]++;
}
cout << "\nNombre total de caracteres saisis : " << total << endl;
cout << "Tableau des effectifs " << endl; // Affichage intermédiaire
for(int i = 0; i < Nmin;i++) printf("%c : %d\n",i+'a',effectif[i]);
for(int i = 0; i < Nmaj;i++) printf("%c : %d\n",i+'A',effectif[i+Nmin]);
for(int i = 0; i < Nnombres;i++) printf("%c : %d\n",i+'0',effectif[i+Nmin+Nmaj]);
for(int i = 0; i < Naccentues;i++){
	if((i>=0 && i<=4) or (i>=6 && i<=11)or (i==18) or(i>=21 && i<=22)){//Exclusion des caractères non-désirés
		printf("%c : %d\n",i+129,effectif[i+Nmin+Nmaj+Nnombres]);
	}
} 
printf("Autres: %d\n\n",effectif[Nmin+Nmaj+Nnombres+Naccentues]);

// Impression de l'histogramme
float pourcentage=0, tpour=0;
for(int i = 0; i < Nmin;i++)
{
	cout << (char)(i+'a') << " :" ; pourcentage=(float)(effectif[i])/total; tpour+=pourcentage;
	for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
	cout << " " << pourcentage*100 << "%" << endl;
}
for(int i = 0; i < Nmaj;i++)
{
	cout << (char)(i+'A') << " :" ;
	pourcentage=(float)(effectif[i+Nmin])/total;
	tpour+=pourcentage;
	for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
	cout << " " << pourcentage*100 << "%" << endl;
}
for(int i = 0; i < Nnombres;i++)
{
	cout << (char)(i+'0') << " :" ;
	pourcentage=(float)(effectif[i+Nmin+Nmaj])/total; tpour+=pourcentage;
	for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
	cout << " " << pourcentage*100 << "%" << endl;
}
for(int i = 0; i < Naccentues;i++)
{
	if((i>=0 && i<=4) or (i>=6 && i<=11)or (i==18) or(i>=21 && i<=22)){//Exclusion des caractères non-désirés
		cout << (char)(i+129) << " :" ;
		pourcentage=(float)(effectif[i+Nmin+Nmaj+Nnombres])/total; tpour+=pourcentage;
		for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
		cout << " " << pourcentage*100 << "%" << endl;
	}
}
cout <<"Autres :";
pourcentage=(float)(effectif[Nmin+Nmaj+Nnombres+Naccentues])/total; tpour+=pourcentage;
for(int j = 0; j < (int)(pourcentage*100);j++) cout << "*";
cout << " " << pourcentage*100 << "%" << endl;
cout << "\n" << tpour*100 << " % des caracteres saisis ont ete traites." << endl;
system("PAUSE");
return(EXIT_SUCCESS);
}
