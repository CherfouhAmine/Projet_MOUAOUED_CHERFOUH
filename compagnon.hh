#pragma once
#include "personnage.hh"


class Compagnon : public Personnage{
/*Seul le compagnon peut soigner*/	
protected:
	int _soin;
	
public:
	Compagnon();
	void statut(std::ostream& flux)const;
	int get_soin(){return _soin;};
	

};

std::ostream &operator<<(std::ostream& out, Personnage const& c);
