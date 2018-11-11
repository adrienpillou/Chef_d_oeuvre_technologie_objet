/*EXERCICE 4 CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926535

float Volume(float rayon);
float Surface(float rayon);
float Circonference(float rayon);

int main()
{
	float m_Rayon;
	//Demande du rayon de la sphere :
	cout<< "Entrez le rayon de votre sphere : ";
	cin>>m_Rayon;
	//Affichage des résultats :
	cout<< "Votre sphere a un circonference de "<<Circonference(m_Rayon)<<" unites cubiques" <<endl;
	cout<< "Votre sphere a un surface de "<<Surface(m_Rayon)<<" unites cubiques" <<endl;
	cout<< "Votre sphere a un volume de "<<Volume(m_Rayon)<<" unites cubiques" <<endl;
	return(0);
}

float Volume(float rayon)//Calcul du volume de la sphere
{
	float volume;
	volume = Surface(rayon)*(rayon/3);
	return volume;
}

float Surface(float rayon)//Calcul de la surface de la sphere
{
	float surface;
	surface = 2*rayon*Circonference(rayon);
	return surface;
}

float Circonference(float rayon)//Calcul de la circonference de la sphere
{
	float circonference;
	circonference = 2*pi*rayon;
	return circonference;
}





