#include "coeur.hh"


using namespace std;

Coeur:: Coeur():Defi(),_choix("0"){}
/*Cas où le compagnon est décédé, prendre Excalibur pour passer son attaque à 50 mais échouer le défi
**ou continuer son chemin et réussir l'épreuve */
void Coeur::ultimatum1( Heros& h){
		
		_option=1;
		cout<<"Elle souhaite l'énergie vitale des champs de Bretagne !!\n\n";
		sleep(2);
		while(_choix !="a" && _choix !="b"){
			cout<<"Alors que décidez vous ? Le combat contre Smaug s'annonce rude ...\nExcalibur vous permettrait d'atteindre Smaug dans le ciel.\n\n\na : Prendre Excalibur et sacrifier les récoltes  b : Continuer votre chemin\n\n"<<endl;
			getline(cin, _choix);
		}
		if(_choix=="a"){
			h.set_atk(50);
			_reussite = false;
			cout<<"Vous avez décidé de prendre Excalibur et de continuer votre quête.\n";
			sleep(1);
			cout<<"Un immense pouvoir est désormais entre vos mains ....\n";
		}
		if(_choix=="b"){
			_reussite=true;
			cout<<"Vous décidez de continuer votre quête sans pénaliser votre peuple.\n";
		}
	}
/*Cas où le compagnon est décédé, prendre Excalibur pour passer son attaque à 50, cela tue le compagnon, mais échouer le défi
**ou continuer son chemin et réussir l'épreuve */
void Coeur::ultimatum2( Heros& h){
		
		_option=2;
		cout<<"Elle vous demande la vie de Lancelot en échange !!\n\n";
		sleep(2);
		while(_choix !="a" && _choix !="b"){
			cout<<"Alors que décidez vous ? Le combat contre Smaug s'annonce rude ...\nExcalibur vous permettrait d'atteindre Smaug dans le ciel\n\n\na : Prendre Excalibur et sacrifier Lancelot  b : Continuer votre chemin avec votre compagnon\n\n";
			getline(cin,_choix);
		}
		if(_choix=="a"){
			h.set_atk(50);
			h.get_compagnon().set_hp(0);
			_reussite = false;
			cout<<"Vous avez décidé de prendre Excalibur et de continuer votre quête en sacrifiant Lancelot...\n";
			sleep(1);
			cout<<"Un immense pouvoir est désormais entre vos mains ....\n";
		}
		if(_choix=="b"){
			_reussite=true;
			cout<<"Vous décidez de continuer votre quête avec votre compagnon."<<endl;
		}
	}
/*Vérification de l'état du compagnon pour lancer le bon ultimatum
**Prendre Excalibur provoque l'échec de l'épreuve et finalement celle du jeu même si on gagne le défi final.
**Cependant sans Excalibur le défi final est quasi impossible, c'est un "piège à con"*/
void Coeur::action( Heros& h){

	sleep(2);
	cout<<"\n\n\n\n\nVous arrivez dans le laboratoire de la fée Morgane.";
	sleep(1);
	cout<<" Elle a en sa possession Excalibur l'épée magique !\n";
	sleep(2);
	cout<< "Elle vous propose de vous la donner à une condition ...\n";
	sleep(2);
	if(h.get_com_hp() <=0){
		ultimatum1(h);
	}
	else{
		ultimatum2(h);
	}
}
		
		
		
