#pragma once
#include <iostream>
#include "Heros.hh"
#include "adversaire.hh"



class Defi{
/*Chaque défi est réussi ou non*/	
protected:
	bool _reussite;
	
	
public:
	Defi():_reussite(false){};
	virtual void action(Heros& h)=0;
	bool get_reussite(){return _reussite;};
	
};
