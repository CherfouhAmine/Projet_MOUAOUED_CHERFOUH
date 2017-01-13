#include "Heros.hh"
#include "coeur.hh"
#include "enigme.hh"
#include "combat.hh"
#include "dragon.hh"
#include "adversaire.hh"
#include <iostream>
#include <map>
#include <cstdlib>
#include<fstream>

using namespace std;

int main(){
	ifstream file("intro1.txt");
	string s;
	while( getline(file,s)){
     	cout<<s<<endl;
     	sleep(2);
     }
     file.close();
	Heros perso ;
	cout<<"OUI !  C'est alors qu'un valeureux héros prénommé "+perso.get_nom()+" ";
	file.open("intro2.txt");
	while( getline(file,s)){
     	cout<<s<<endl;
     	sleep(2);
     }
     file.close();  
	int aux,i=0,tab[3]={0};
	Enigme e;
	Combat c;
	Coeur o;
	Dragon d;
	map<int,Defi *> m;
	m[0]=&e;
	m[1]=&c;
	m[2]=&o;
	srand(time(NULL));
	while(i<3){
		aux=rand()%3;
		if(tab[aux]==0){
			tab[aux]=1;
			m[aux]->action(perso);
			i++;
		}
	}
	cout<<endl<<endl<<endl;
	file.open("regles.txt");
	while( getline(file,s)){
     	cout<<s<<endl;
     	sleep(2);
     }
     file.close();
     while(s!="oui"){
     	cout<<"C'est compris ? Entrez 'oui' lorsque vous êtes prêt.\n";
     	getline(cin,s);
     }
     d.affrontement(perso);
     if(o.get_reussite()==true&&d.get_reussite()==true)
		cout<<"Tout le peuple de Bretagne attend fièrement son nouveau roi "+perso.get_nom()+" !\nVous avez prouvé à tout le monde votre valeur et pourrez donc occuper dignement le trône de Camelot.\n\nFELICITATIONS VOUS GAGNEZ LE JEU !!"<<endl;
     else if(d.get_reussite()==true&&o.get_reussite()==false){
		if(o.get_option()==1)
	        	cout<<"Cependant le peuple va subir une famine sans précédent à cause de votre soif de pouvoir.\nIl ne veut pas d'un roi tel que vous, vous finirez donc votre vie dans un sombre cachot.\n\nGAME OVER \n"<<endl;
		else if(o.get_option()==2)
			cout<<"Cependant le peuple a eu vent du sort que vous avez réservé à votre compagnon.\nVous avez tué Lancelot, vous finirez donc votre vie dans un sombre cachot.\n\nGAME OVER \n"<<endl;
	}	
   return 0;
}
