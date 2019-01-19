/*EXERCICE 6 DU CHEF D'OEUVRE TECHNOLOGIE OBJET*/
/*Programme réalisé par Adrien Pillou*/

using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 
void DeplacerDisque(int, char, char, char);
 
int main()
{
    int num;
    do{
    	cout<<"Entrez le nombre de disque : ";
    	cin>>num;
	}while(num==0);
    cout<<"\nDeplacements necessaire a la resolution du probleme :\n";
    DeplacerDisque(num, 'A', 'C', 'B');
    return 0;
}

void DeplacerDisque(int num, char tourOrigine, char tourDestination, char tourIntermediaire)
{
	if (num == 1)
    {
        cout<<"\nDeplacement du disque 1 de la tour "<< tourOrigine << " vers la tour "<< tourDestination;
        return;
    }
    DeplacerDisque(num - 1, tourOrigine, tourIntermediaire, tourDestination);
    cout<<"\nDeplacement du disque "<< num <<" de la tour "<< tourOrigine <<" vers la tour "<<tourDestination;
    DeplacerDisque(num - 1, tourIntermediaire, tourDestination, tourOrigine);
}
