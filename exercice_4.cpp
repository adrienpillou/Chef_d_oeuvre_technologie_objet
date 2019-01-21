/*EXERCICE 4 DU CHEF D'OEUVRE TECHNOLOGIE OBJET*/
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
	
	//Demande du rayon de la sphère :
	cout<< "Entrez le rayon r (m) de votre sphere : ";
	cin>>m_Rayon;
	
	//Affichage du résultat :
	cout<< "\nVotre sphere a un Volume de "<<Volume(m_Rayon)<<" m^3" <<endl;
	system("pause");
	return(0);
}

float Volume(float rayon)//Calcul et retourne le volume de la sphère
{
	float volume;
	volume = Surface(rayon)*(rayon/3);
	return volume;
}

float Surface(float rayon)//Calcul et retourne la surface de la sphère
{
	float surface;
	surface = 2*rayon*Circonference(rayon);
	return surface;
}

float Circonference(float rayon)//Calcul et retourne la circonference de la sphère
{
	float circonference;
	circonference = 2*pi*rayon;
	return circonference;
}
