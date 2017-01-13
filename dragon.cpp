#include "dragon.hh"
#include <cstdlib>

using namespace std;
/*Les points de vie et d'attaque de Smaug sont ainsi fait pour que le joueur ne puisse quasiment jamais gagner sans Excalibur*/
Dragon :: Dragon():Combat(), _charge(1), _dist(0),_pos(0){

                this->_adv.set_nom("Smaug");
	        this->_adv.set_atk(20);
		this->_adv.set_hp(130);     
}

/*Méthode principale, deux déroulements de combat possible avec ou sans Excalibur*/
void Dragon:: affrontement(Heros& h){
	sleep(2);
     srand(time(NULL));
     cout<<"\n\n\n\n\nC'est l'affrontement final !! ";
     sleep(1);
     cout<<"Vous vous dressez devant le dragon Smaug ";
	if(h.get_atk()>30){
		cout<<"avec la terrible Excalibur entre vos mains !!\n";
			sleep(2);
			cout<<"En garde c'est la dernière épreuve !!\n\n\n";
	        action2(h);
	        sleep(2); 
	}  
	else{
		if(h.get_compagnon().get_hp()<=0){
			cout<<"sans Excalibur et sans Lancelot pour vous épauler ...\n";
			sleep(2);
			cout<<"En garde c'est la dernière épreuve !!\n\n\n";
			action(h);
	                sleep(2);
		}
		else{
			cout<<"sans Excalibur mais avec Lancelot à vos cotés.\n";
			sleep(2);
			cout<<"En garde c'est la dernière épreuve !!\n\n\n";
	                action(h);
	                sleep(2); 
	    }
	}
}       
/*Différents cas de figures pour le tour du joueur*/

/**Smaug est au sol et le compagnon est en vie, 5 choix de jeu possibles*/
void Dragon::choix(Heros& h){
				string choix = "0";
				cout<<_adv<<endl;
				cout<<h<<endl<<"Que voulez vous faire ?"<<endl;
				while(choix !="a"&&choix!="b"&&choix!="c"&&choix!="d"&&choix!="e"){
					cout<<"a : attaquer à deux  b : vous soigner(50hp max)  c : soigner Lancelot(50hp max)  d : Anticiper un coup de griffe  e : Anticiper un souffle"<<endl;
					getline(cin,choix); 
				}
				if(choix=="a"){
					this->attaque(h.get_atk()+h.get_compagnon().get_atk(),this->_adv);
					cout<<this->_adv.get_nom()<<" perd "<<h.get_atk()+h.get_compagnon().get_atk()<<" points de vie.\n";
					if(this->_adv.get_hp()<=0)
						cout<<"Vous achevez "<<this->_adv.get_nom()<<" !\n";
					_pos=0;
				} 
				else if(choix== "b"){ 					
					this->heal(h.get_compagnon().get_soin(), h);
					cout<<"Vous gagnez "<<h.get_compagnon().get_soin()<<" points de vie.\n";
					_pos=0;
				}
				else if(choix== "c"){ 
						this->heal(h.get_compagnon().get_soin(), h.get_compagnon());
						cout<<"Lancelot gagne "<<h.get_compagnon().get_soin()<<" points de vie.\n";
						_pos=0;
				}
				else if(choix== "d"){
						_pos=1;
						cout<<"Vous vous tenez prêt à parer ses griffes.\n";
				}
				else if(choix== "e"){  
						_pos=2;
						cout<<"Vous vous tenez prêt à parer son souffle infernal.\n";
				}					
				choix ="0";
}
/*Smaug est dans le ciel et le compagnon est en vie, 4 choix de jeu possibles*/
void Dragon::choix2(Heros& h){
        string choix = "0";
        cout<<_adv<<endl;
	   cout<<h<<endl;
        cout<<"Smaug est dans le ciel, que voulez vous faire ?\n";
        while(choix !="a"&&choix!="b"&&choix!="c"&&choix!="d"){
			cout<<"a : vous soigner(50 hp max)  b : soigner Lancelot(50 hp max)  c : Anticiper un coup de griffe  d : Anticiper un souffle "<<endl;
			getline(cin,choix); 
		}	
	   if(choix=="a"){					
			this->heal(h.get_compagnon().get_soin(), h);
			cout<<"Vous gagnez "<<h.get_compagnon().get_soin()<<" points de vie.\n";
			_pos=0;
		}
		else if(choix=="b"){
			this->heal(h.get_compagnon().get_soin(), h.get_compagnon());
			cout<<"Lancelot gagne "<<h.get_compagnon().get_soin()<<" points de vie.\n";
			_pos=0;
		}
		else if(choix== "c"){ 
			_pos=1;
			cout<<"Vous vous tenez prêt à parer ses griffes.\n";
		}
		else if(choix== "c"){ 
			_pos=2;
			cout<<"Vous vous tenez prêt à parer son souffle infernal.\n";
		}					
        sleep(2); 
}
/*Smaug est dans le ciel le compagnon est mort, 2 choix de jeu possibles*/
void Dragon::choix3(Heros& h){
        string choix = "0";
        cout<<_adv<<endl;
	   cout<<h<<endl;
        cout<<"Smaug est dans le ciel, que voulez vous faire ?\n";
        while(choix !="a"&&choix!="b"){
			cout<<"a : Anticiper un coup de griffe  b : Anticiper un souffle "<<endl;
			getline(cin,choix); 
		}	
	   if(choix=="a"){
			_pos=1;
			cout<<"Vous vous tenez prêt à parer ses griffes.\n";
		}
		else if(choix=="b"){
			_pos=2;
			cout<<"Vous vous tenez prêt à parer son souffle infernal.\n";
		}					
        sleep(2); 
}
/*Smaug est au sol le compagnon est mort, 3 choix de jeu possibles*/
void Dragon::atk_heros(Heros& h){
		string choix = "0";
		cout<<_adv<<endl;
		cout<<h<<endl<<"Que voulez vous faire ?"<<endl;
		while(choix !="a"&&choix!="b"&&choix!="c"){
			cout<<"a : attaquer  b : Anticiper un coup de griffe  c : Anticiper un souffle "<<endl;
			getline(cin,choix); 
		}
		if(choix=="a"){
			_pos=0;
			this->attaque(h.get_atk(),this->_adv); 		
			cout<<"Vous attaquez.\n"<<endl;
			cout<<this->_adv.get_nom()<<" perd "<<h.get_atk()<<" points de vie.\n";
			if(this->_adv.get_hp()<=0)
				cout<<"Vous achevez "<<this->_adv.get_nom()<<" !\n";
		}
		else if(choix== "b"){
			_pos=1;
			cout<<"Vous vous tenez prêt à parer ses griffes.\n";
		}
		else if(choix== "c"){  
			_pos=2;
			cout<<"Vous vous tenez prêt à parer son souffle infernal.\n";
		}					
}
/*Différents cas de figure pour le tour de Smaug*/

/**Smaug est au sol avec son souffle chargé*/
void Dragon:: atk_drag1(Heros& h){
        int i= rand()%3;
        if(i==0){
                cout<<"Smaug prépare son souffle ravageur !! \n";
                if(_pos==2)
                	cout<<"Vous vous abrtitez derrière un rocher il ne vous touche pas !\n";
                else{
                	this->_adv.set_atk(30);
                	atk_adv(h);
                }
                _charge = 0;  
                sleep(2);      	                        
        }
        else if(i==1){
                cout<<"Smaug prépare ses griffes acérées  !! \n";
                if(_pos==1)
                	cout<<"Vous esquivez le coup de griffe du dragon !\n";
                else{
                	this->_adv.set_atk(20);
                	atk_adv(h);
                }
                sleep(2);
        }
        else if(i==2){
                cout<<"Smaug prend son envol. \n";
                _dist=1;
                sleep(2);
        }
}
/*Smaug est au sol sans son souffle chargé*/
void Dragon:: atk_drag2(Heros& h){
        int i= rand()%3;
        if(i==0){
                cout<<"Smaug recharche ses flammes. \n";
                _charge=1;
                sleep(2);
        }
        else if(i==1){
                cout<<"Smaug prépare ses griffes acérées  !! \n";
                if(_pos==1)
                	cout<<"Vous esquivez le coup de griffe du dragon !\n";
                else{
                	this->_adv.set_atk(20);
                	atk_adv(h);
                }
                sleep(2);
        }
        else if(i==2){
                cout<<"Smaug prend son envol et recharge ses flammes.\n";
                _charge=1;
                _dist=1;
                sleep(2);
        }
}
/*Smaug est dans le ciel sans son souffle chargé*/
void Dragon:: atk_drag3(Heros& h){
        int i= rand()%2;
        if(i==0){
                cout<<"Smaug recharche ses flammes. \n";
                _charge=1;
                sleep(2);
        }
        else if(i==1){
                cout<<"Smaug redescend au sol et recharge ses flammes.\n";
                _charge=1;
                _dist=0;
                sleep(2);
        }
}
/*Smaug est dans le ciel avec son souffle chargé*/
void Dragon:: atk_drag4(Heros& h){
        int i= rand()%2;
        if(i==0){
                cout<<"Smaug prépare son souffle ravageur !! \n";
                if(_pos==2)
                	cout<<"Vous vous abrtitez derrière un rocher il ne vous touche pas !\n";
                else{
                	this->_adv.set_atk(30);
                	atk_adv(h);
                }
                _charge = 0;
                sleep(2);
        }
        else if(i==1){
                cout<<"Smaug redescend au sol. \n";
                _dist=0;
                sleep(2);
        }
}
/*Combat sans Excalibur, le joueur ne peut pas toucher Smaug dans le ciel*/        	
void Dragon:: action(Heros& h){       
        int  tour =0;    
        while(this->_adv.get_hp()>0 && h.get_hp()>0){
		if(tour%2==0){
		        if(_dist==0){
		                if(h.get_compagnon().get_hp()<=0)
			                atk_heros(h);
			        else
				        choix(h);
			}
			else{
			       if(h.get_compagnon().get_hp()<=0)
			                choix3(h);
			       else
			               choix2(h);
			}
	        }
        	else{
        	        cout<<endl<<endl;
        	        if(_dist==0 && _charge==1)
        	                atk_drag1(h);
        	        else if(_dist==0 && _charge==0)
        	                atk_drag2(h);
        	        else if(_dist==1 && _charge==0)
        	                atk_drag3(h);
        	        else if(_dist==1 && _charge==1)
        	                atk_drag4(h);
        	        cout<<endl<<endl;
        	     }
            tour++;
       }       
      resultat();
}       	       
/*Combat avec Excalibur, le joueur peut atteindre Smaug même dans le ciel*/        	                        
void Dragon:: action2(Heros& h){ 

	int  tour =0;
	
	while(this->_adv.get_hp()>0 && h.get_hp()>0){
		if(tour%2==0){
			if(_dist==0)
				atk_heros(h);
			else{
				cout<<"Smaug est dans le ciel mais la magie d'Excalibur vous permet de l'atteindre.\n";
				h.set_atk(h.get_atk()/2);
				atk_heros(h);
				h.set_atk(h.get_atk()*2);
			}
		}
		else{
		     cout<<endl<<endl;
			if(_dist==0 && _charge==1)
        	                atk_drag1(h);
        	        else if(_dist==0 && _charge==0)
        	                atk_drag2(h);
        	        else if(_dist==1 && _charge==0)
        	                atk_drag3(h);
        	        else if(_dist==1 && _charge==1)
        	                atk_drag4(h);
        	        cout<<endl<<endl;
        	     }
            tour++;
       }       
      resultat();
      if(_reussite == true)
		cout<<"Le terrible Smaug n'est plus, vous sortez victorieux de ces épreuves avec panache.\n\n\n";
	sleep(3);
}       	       
