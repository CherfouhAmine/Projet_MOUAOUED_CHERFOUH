#pragma once
#include "personnage.hh"


class Adversaire : public Personnage{
	
protected:
	
public:
	Adversaire();
	void statut(std::ostream& flux)const;	
};


