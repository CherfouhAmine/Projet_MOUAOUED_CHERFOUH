#pragma once
#include <iostream>





class Personnage {
	
protected:
	int _hp;
	int _atk;
	std::string _nom;
public:
	virtual void statut(std::ostream& flux)const = 0;
	Personnage():_hp(25),_atk(10),_nom("Lancelot"){};
	void set_hp(int hp){_hp=hp;};
	void set_atk(int atk){_atk=atk;};
	void set_nom(std::string nom){_nom=nom;};
	int get_hp(){return _hp;};
	int get_atk(){return _atk;};
	std::string get_nom(){return  _nom;};
};

	
