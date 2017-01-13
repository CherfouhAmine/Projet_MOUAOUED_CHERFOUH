#pragma once
#include <iostream>
#include "defi.hh"




class Combat : public Defi{

	protected:
		Adversaire _adv;

	public:
		Combat();	
		void action(Heros&);
		void atk_heros(Heros& h);
		void choix(Heros& h);
		void atk_adv(Heros& h);
		void eval(Heros& h);
		void resultat();
		void attaque(int a, Personnage& cible);
		void heal(int b, Personnage& cible);
		Adversaire& get_adv(){ return _adv;};
};
		


