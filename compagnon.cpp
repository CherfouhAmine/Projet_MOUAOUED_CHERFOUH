#include "compagnon.hh"




Compagnon::Compagnon():Personnage(),_soin(10){
	
}


void Compagnon::statut(std::ostream& flux)const{

	if(_hp<=0)
		flux<<std::endl;
	else	
		flux<<"Lancelot vous suit\nHp = "<<_hp<<"\nAtk = "<<_atk<<"\nSoin = "<<_soin<<std::endl;
}
	
std::ostream& operator<<(std::ostream& out, Personnage const& c){
	
	c.statut(out);
	return out;
	
}

