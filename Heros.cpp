#include "Heros.hh"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Heros :: Heros():Personnage(){

		_hp+=5;
        cout << "\nEntrez votre nom " << endl;
        getline(cin,_nom);
        _compagnon = Compagnon();        
}


void Heros :: statut(ostream& flux) const
{
       if ( _hp <= 0 )
          flux <<  _nom << " est mort " << endl;
      else
       	flux << _nom << "\nHP = " << _hp << "\nAtk = " << _atk << "\n\n" << _compagnon << endl;
}


