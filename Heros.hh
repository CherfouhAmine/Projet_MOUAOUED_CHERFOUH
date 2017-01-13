#pragma once
#include "personnage.hh"
#include "compagnon.hh"


class Heros : public Personnage {
        private :
        
        Compagnon _compagnon ;
        
        public : 
        
        Heros();
        void statut(std :: ostream& flux) const;
        int get_com_hp(){return _compagnon.get_hp();};
        Compagnon& get_compagnon(){return _compagnon;};
};
