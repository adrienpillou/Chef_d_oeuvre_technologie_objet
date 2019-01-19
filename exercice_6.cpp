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
        printf("\nDeplacement du disque 1 de la tour %c vers la tour %c", tourOrigine, tourDestination);
        return;
    }
    DeplacerDisque(num - 1, tourOrigine, tourIntermediaire, tourDestination);
    printf("\nDeplacement du disque %d de la tour %c vers la tour %c", num, tourOrigine, tourDestination);
    DeplacerDisque(num - 1, tourIntermediaire, tourDestination, tourOrigine);
}
