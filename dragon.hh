#pragma once
#include <iostream>
#include "combat.hh"
#include "adversaire.hh"
#include <unistd.h>


class Dragon : public Combat{

protected:
        int _charge;
        int _dist ;
        int _pos;
public:
	Dragon();
	void action(Heros&);	
	void action2(Heros&);
	void affrontement(Heros&);
	void choix2(Heros& h);
	void choix3(Heros& h);
	void atk_heros(Heros& h);
	void choix(Heros& h);
	void atk_drag1(Heros& h);
	void atk_drag2(Heros& h);
	void atk_drag3(Heros& h);
	void atk_drag4(Heros& h);
};
