#pragma once
#include <iostream>
#include "defi.hh"
#include <unistd.h>



class Coeur: public Defi{
/*_option décide du texte affiché en fin de partie dans certains cas*/
protected:
	std::string _choix;
	int _option;
	
public:
	Coeur();
	void action(Heros& h);
	void ultimatum1( Heros& h);
	void ultimatum2( Heros& h);
	int get_option(){return _option;};
	
};
