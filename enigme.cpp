#include "enigme.hh"
#include <cstdlib>


using namespace std;

/*Nous avons utilisé des vecteurs pour les énigmes et les réponses correspondantes aux mêmes indices.*/
Enigme::Enigme() : Defi(){
	
	_question.push_back("Sans moi Paris serait pris, je fais trois fois le tour du Canada. Qui suis-je?");
	_question.push_back("Que fait un cheval au supermacher?");
	_question.push_back("Qu'est ce qui réflechit sans réflechir?");
	_reponse.push_back("a");
	_reponse.push_back("course");
	_reponse.push_back("miroir");
}
/*Mise en place de l'épreuve*/
void Enigme:: initialisation(){
	sleep(2);
     cout<<"\n\n\n\n\nVous arrivez maintenant à l'épreuve d'intelligence où vous attend Merlin.\n";
	sleep(2);
	cout<<"Il vous posera une énigme, si vous la résolvez il vous donnera une potion fortifiante.\n";
	sleep(2);
	cout<<"Vous aurez 3 tentatives. (attention à l'orthographe, toutes les réponses sont en minuscules, au singulier et sans déterminant.) \n\n\n\n";
	sleep(2);
	cout<<"Voici l'énigme : ";
	sleep(3);
}
/*La saisie au clavier du joueur est comparé aux réponses, en cas de réussite il gagne 20hp pour lui et son compagnon.
**L'échec de cet épreuve n'est pas éliminatoire*/
void Enigme::action(Heros& h){
     initialisation();
	srand(time(NULL));
	int i = rand()%3,j=0;
	string aux="0";	
	while(j<3){
		cout<<_question[i]<<endl;
		getline(cin,aux);	
		if(aux == _reponse[i]){
			_reussite =true;
			cout<< "Bonne réponse, Merlin vous donne sa potion fortifiante.\n"<<endl;
			h.set_hp(h.get_hp()+20);
			if(h.get_compagnon().get_hp()>0){
				h.get_compagnon().set_hp(h.get_compagnon().get_hp()+20);
				cout<<"Vous et Lancelot gagnez 20 points de vie !\n";
			}
			else
				cout<<"Vous gagnez 20 points de vie ! \n";
			break;
		}
		else{
			_reussite = false;
			if(j>=2)
				cout<<"Mauvaise réponse c'est terminé, Merlin range sa potion magique.\n"<<endl;
			else
				cout<<"Mauvaise réponse essayez encore !\n\n\n"<<endl;
		}
		j++;
	}
	cout<<"Vous continuez votre quête dans le donjon.\n\n";
}

	
