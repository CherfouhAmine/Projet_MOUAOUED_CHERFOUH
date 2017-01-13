#include "adversaire.hh"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Adversaire :: Adversaire():Personnage(){
		
		_nom="Hunt";
		_atk+=5;
		_hp+=25;

}

/*Affichage des informations de l'ennemis*/

void Adversaire :: statut(ostream& flux) const
{
         if ( _hp <= 0 )
        {
               flux <<  _nom << " est mort " << endl;
                
        }
        else
       	flux << _nom << "\nHP = " << _hp<< endl;
}
