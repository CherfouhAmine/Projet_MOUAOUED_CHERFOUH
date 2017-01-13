#pragma once
#include <iostream>
#include <vector>
#include "defi.hh"
#include <unistd.h>


class Enigme : public Defi{

	protected:
	std::vector<std::string> _question;
	std::vector<std::string> _reponse;
	
	public:
	Enigme();
	void action(Heros&);
	void initialisation();

};
	
	
	
