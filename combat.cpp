#include "combat.hh"
#include <unistd.h>
#include <cstdlib>


using namespace std;



Combat::Combat():Defi(),_adv(){}


void Combat::attaque(int a, Personnage& cible){

	cible.set_hp(cible.get_hp()-a);
}


void Combat::heal(int b, Personnage& cible){
	if(cible.get_hp()+b>50)
	        cible.set_hp(50);
	else
	        cible.set_hp(cible.get_hp()+b);
}	
/*Attaque automatique lorsque le compagnon n'est plus là*/
void Combat::atk_heros(Heros& h){
					cout<<_adv<<endl;;
					cout<<h<<endl;
					this->attaque(h.get_atk(),this->_adv); 		
					cout<<"Vous attaquez.\n"<<endl;
					cout<<this->_adv.get_nom()<<" perd "<<h.get_atk()<<" points de vie.\n";
					if(this->_adv.get_hp()<=0)
						cout<<"Vous achevez "<<this->_adv.get_nom()<<" !\n"; 
}
/*Evaluation du statut de fin de combat après victoire, monter la vie à 30 ou 50 en fonction de la réussite de l'enigme ou non au préalable*/
void Combat::eval(Heros& h){
		if(h.get_compagnon().get_hp()<=0){
			cout<<"Vous ramassez une potion qui soigne vos blessures sur le cadavre de "<<this->_adv.get_nom()<<".\n";
			if(h.get_hp()<=30)
				h.set_hp(30);
			else
				h.set_hp(50);
		}
		else{
			cout<<"Vous ramassez une potion qui soigne vos blessures et celles de Lancelot sur le cadavre de "<<this->_adv.get_nom()<<".\n";
			if(h.get_hp()<=30)
				h.set_hp(30);
			else
				h.set_hp(50);
			if(h.get_compagnon().get_hp()<=25)
				h.get_compagnon().set_hp(25);
			else
				h.get_compagnon().set_hp(45);
		}
		sleep(2);
		cout<<"Vous avez prouvé votre force en remportant cette épreuve vous pouvez continuer votre quête.\n";
}
/*Choix du joueur entre attaquer ou soigner*/
void Combat::choix(Heros& h){
				string choix="0";
				cout<<_adv<<endl;
				cout<<h<<endl<<"Que voulez vous faire ?"<<endl;
				while(choix !="a"&&choix!="b"&& choix!="c"){
					cout<<"a : attaquer à deux  b : vous soigner(50 hp max)  c : soigner Lancelot(50 hp max)"<<endl;
					getline(cin,choix); 
				}
			
				if(choix=="a"){
					this->attaque(h.get_atk()+h.get_compagnon().get_atk(),this->_adv);
					cout<<this->_adv.get_nom()<<" perd "<<h.get_atk()+h.get_compagnon().get_atk()<<" points de vie.\n";
					if(this->_adv.get_hp()<=0)
						cout<<"Vous achevez "<<this->_adv.get_nom()<<" !\n"; 
				}
				else if(choix=="b"){
					this->heal(h.get_compagnon().get_soin(), h);
					cout<<"Vous gagnez "<<h.get_compagnon().get_soin()<<" points de vie.\n";					
				}
				else{
					this->heal(h.get_compagnon().get_soin(), h.get_compagnon());
					cout<<"Lancelot gagne "<<h.get_compagnon().get_soin()<<" points de vie.\n";
				choix ="0";
				}

}
/*Attaque de l'adversaire de manière aléatoire sur le joueur ou son compagnon*/
void Combat ::atk_adv(Heros& h){
			srand(time(NULL));
			int aux= rand()%2;
			cout<<"C'est le tour de l'adversaire."<<endl;
			if(h.get_compagnon().get_hp()<=0){
				cout<<"Il vous attaque, vous perdez "<<this->_adv.get_atk()<<" points de vie."<<endl;
				this->attaque(_adv.get_atk(),h);
				sleep(1);
			}
			else{
				if(aux==1){
					cout<<"Il attaque Lancelot.";
					this->attaque(_adv.get_atk(),h.get_compagnon());
					if(h.get_compagnon().get_hp()<=0)
						cout<<", Lancelot péri sous les coups de "<<this->_adv.get_nom()<<" !\n";
					else
						cout<<", Lancelot perd "<<this->_adv.get_atk()<<" points de vie.\n";
					sleep(1);
				}
				else{
					cout<<"Il vous attaque, vous perdez "<<this->_adv.get_atk()<<" points de vie."<<endl;
					this->attaque(_adv.get_atk(),h);
					sleep(1);
				}
			}
}
/*Evaluation de la vicoire ou défaite, en cas de défaite c'est un Game Over*/
void Combat::resultat(){
        if(_adv.get_hp()<=0){
		cout<<"Vous remportez la bataille !"<<endl;
		_reussite = true;
	}
	else{
		cout<<"Vous êtes mort, ici s'achève votre quête.\nLes espoirs placés en vous meurent avec vous, le royaume de Bretagne n'a toujours pas trouvé son roi ....\n\n\nGAME OVER : Retentez votre chance une autre fois !"<<endl;
		_reussite = false;
		exit(0);
	} 
}
/*Combat au tour par tour, le joueur débute toujours*/	
void Combat::action(Heros& h){
	sleep(2);
	int tour =0;
	cout<<"\n\n\n\n\nVous arrivez maintenant à l'épreuve de force. Un terrible guerrier prénnomé "<<this->_adv.get_nom()<<" va vous affronter dans un combat à mort.\n";
	sleep(3);
	if(h.get_compagnon().get_hp()<=0)
		cout<<"Malheuresement Lancelot n'est plus là pour vous épauler.\n";
	else
		cout<<"Heureusement vous pouvez compter sur Lancelot votre fidèle compagnon.\n";
	sleep(2);
	cout<<"En garde le combat va commencer !!\n\n\n\n\n\n\n\n\n";
	while(_adv.get_hp()>0 && h.get_hp()>0){
		if(tour%2==0){
			if(h.get_compagnon().get_hp()<=0){
			atk_heros(h);
			}
			else
				choix(h);
		}
		else
			atk_adv(h);
		tour++;
		cout<<endl<<endl<<endl;
		sleep(1);
	}
	resultat();
	if(_reussite == true)
	        eval(h);
}

	
