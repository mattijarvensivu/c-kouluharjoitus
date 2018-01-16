using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Pizzeria.h"
#include "Pizza.h"
#include "raaka_aine.h"
#include <fstream>
	


	

int main(){
	int Menu();

	
	int imputhinta, pizzavalinta,valinta;	
	int menu=10;
	vector<Pizzeria>kaikkipitseriat;
	vector<Pizza>kaikkipitsat;
	vector<Raaka_aine>kaikkiraaka_aineet;
	string imputosoite,imputnimi;//apumuuttujat

	while(menu!=0){
		menu = Menu();        //menu
	switch(menu){
		
	case 1://Pizzerian lisäys
		
		{
	cout<<"Syötä nimi\n";
	cin.clear();
	cin.ignore();
	getline(cin,imputnimi);
	cout<<"Syötä Osoite\n";
	getline(cin,imputosoite);
	
	Pizzeria abu(imputnimi,imputosoite);

	kaikkipitseriat.push_back(abu);
	
	break;
		}
			case 2: { //pizzan lisäys

		cout<<"Syötä nimi\n";
	cin.clear();
	cin.ignore();
	getline(cin,imputnimi);
	cout<<"Syötä Hinta euroina\n";
	cin>>imputhinta;
	
	Pizza jokupitsa(imputnimi,imputhinta);

	kaikkipitsat.push_back(jokupitsa);
	
	break;
			}  
			case 3:{//Raaka-aineen lisäys

	cout<<"Syötä raaka-aineen nimi\n";
	cin.clear();
	cin.ignore();
	getline(cin,imputnimi);
	
	Raaka_aine abu(imputnimi);

	kaikkiraaka_aineet.push_back(abu);

				   break;
				   }

	case 4://Pizzerioiden tulostus
		{
			cout<<"PIZZERIAT:\n";
			for(int i=0;i<kaikkipitseriat.size();i++)
			{
	cout<<"Pizzerian nimi: "<<kaikkipitseriat[i].Getnimi()<<endl;

	cout<<"Pizzerian osoite: "<<kaikkipitseriat[i].Getosoite()<<endl;
	cout<<"=====================================\n";
		}
			break;
		   }

	case 5:{
		cout<<"PIZZAT:\n";
		for(int i=0;i<kaikkipitsat.size();i++){
			cout<<"Pizzan nimi: "<<kaikkipitsat[i].Getpizzanimi()<<endl;

			cout<<"Pizzan Hinta: "<<kaikkipitsat[i].Getpizzahinta()<<" Euroa"<<endl;

			cout<<"==============================\n";
		   }
		break;

		   }	

	case 6:{
		cout<<"RAAKA-AINEET:\n";
			for(int i=0;i<kaikkiraaka_aineet.size();i++)
			{
	cout<<"Raaka-aineen nimi: "<<kaikkiraaka_aineet[i].Getnimi()<<endl;
	cout<<"=====================================\n";
		}

		   
		   break;
		   }


	case 7:{
		cout<<"Mihin Pitseriaan haluat lisätä?\n\n";
		   cout<<"PIZZERIAT:\n";
			for(int i=0;i<kaikkipitseriat.size();i++)
			{
	cout<<i+1<<"."<<"Pizzerian nimi: "<<kaikkipitseriat[i].Getnimi()<<endl;
	cout<<"Pizzerian osoite: "<<kaikkipitseriat[i].Getosoite()<<endl;

	cout<<"=====================================\n";
	}
	cin>>valinta;
	valinta=valinta-1;
	cout<<"Valittu Pitseria: "<<kaikkipitseriat[valinta].Getnimi()<<endl;
	cout<<"Mitkä Pitsat?\n"; // näytetään pizzat
			cout<<"PIZZAT:\n";
		for(int i=0;i<kaikkipitsat.size();i++){
			cout<<i+1<<"."<<"Pizzan nimi: "<<kaikkipitsat[i].Getpizzanimi()<<endl;
			cout<<"Pizzan Hinta: "<<kaikkipitsat[i].Getpizzahinta()<<" Euroa"<<endl;

			cout<<"==============================\n";
			}

			cin>>pizzavalinta;
			pizzavalinta=pizzavalinta-1;
			cout<<"Valittu Pizza: "<<kaikkipitsat[pizzavalinta].Getpizzanimi()<<endl;

			kaikkipitseriat[valinta].SetPizza(&kaikkipitsat[pizzavalinta]); //laitetaan pitserian osoitin vektori osoittamaan pizzaan (SetPizza) 
			
		   break;
		   }

	case 8:{
		   cout<<"Mihin pizzaan haluat lisätä?\n";//valitaan mihin pitsaan tallenetaan raaka-aine
			cout<<"PIZZAT:\n";
		for(int i=0;i<kaikkipitsat.size();i++){
			cout<<i+1<<"."<<"Pizzan nimi: "<<kaikkipitsat[i].Getpizzanimi()<<endl;

			cout<<"Pizzan Hinta: "<<kaikkipitsat[i].Getpizzahinta()<<" Euroa"<<endl;

			cout<<"==============================\n";
			}

			cin>>valinta;
			valinta=valinta-1;
			cout<<"Valittu Pizza: "<<kaikkipitsat[valinta].Getpizzanimi()<<endl;
			cout<<"Mitkä raaka-aineet?\n";
			cout<<"RAAKA-AINEET:\n";
		for(int i=0;i<kaikkiraaka_aineet.size();i++){ //valitaan haluttu raaka-aine
			cout<<i+1<<"."<<"Raaka-aineen nimi: "<<kaikkiraaka_aineet[i].Getnimi()<<endl;
			

			cout<<"==============================\n";
			}
		cin>>pizzavalinta;
		pizzavalinta=pizzavalinta-1;
			kaikkipitsat[valinta].Setraaka_aine(&kaikkiraaka_aineet[pizzavalinta]);
		   break;
		   }

	case 9:{
		cout<<"Minkä Pitserian pizzat Haluat tulostaa?\n\n";     //valitaan pitseria
		   cout<<"PIZZERIAT:\n";
			for(int i=0;i<kaikkipitseriat.size();i++)
			{
	cout<<i+1<<"."<<"Pizzerian nimi: "<<kaikkipitseriat[i].Getnimi()<<endl;

	cout<<"Pizzerian osoite: "<<kaikkipitseriat[i].Getosoite()<<endl;
	cout<<"=====================================\n";
			}
			cin>>valinta;  //pitserian valinta
			valinta=valinta-1;//Käyttäjäystävällisyyden vuoksi jotta ei olisi 0.Kebab house (huom cout<<i+1<<"Pizzerian nimi")
			for(int i=0;i<kaikkipitseriat[valinta].GetPizza().size();i++){//katsoo halutun pitserian pizza osoitin taulukon koon

				cout<<"Pitsan nimi: "<<kaikkipitseriat[valinta].GetPizza()[i]->Getpizzanimi()<<endl; // katsoo minkä pitserian osoitintaulukko ja mihin pizzaan ne osoittaa ja katsotaan kyseisen olion nimi ja osoite   
				cout<<"Pitsan hinta: "<<kaikkipitseriat[valinta].GetPizza()[i]->Getpizzahinta()<<" Euroa"<<endl;
			}
		   break;
		   }

	case 10:{

				cout<<"Minkä Pizzan raaka-aineet haluat tulostaa?\n\n";
		   cout<<"PIZZAT:\n";
			for(int i=0;i<kaikkipitsat.size();i++)
			{
	cout<<i+1<<"."<<"Pizzan nimi: "<<kaikkipitsat[i].Getpizzanimi()<<endl;

	cout<<"Pizzan Hinta: "<<kaikkipitsat[i].Getpizzahinta()<<endl;
	cout<<"=====================================\n";
			}
			cin>>valinta;
			valinta=valinta-1;
			for(int i=0;i<kaikkipitsat[valinta].Getpizza_raaka_aine().size();i++){

				cout<<"Raaka-aineen nimi: "<< kaikkipitsat[valinta].Getpizza_raaka_aine()[i]->Getnimi()<<endl;//pitsan raaka-aine osoitin taulukosta katsotaan mihin osoittaa 
				
			}
			break;
			}
	case 11:{
		cout<<"Mitä pitseriaa haetaan?"<<endl;
		
		cin.clear();
	cin.ignore();
	getline(cin,imputnimi);
	
	
	for(int i=0;i<kaikkipitseriat.size();i++){
		
		if(kaikkipitseriat[i].Getnimi()==imputnimi){
			cout<<"Pizzeria löytyi!\n";
			cout<<kaikkipitseriat[i].Getnimi()<<endl;
			cout<<kaikkipitseriat[i].Getosoite()<<endl;
		}
	
	}
			break;
			}
	case 12:{
			cout<<"Haettava pizza?\n";
	cin.clear();
	cin.ignore();
	getline(cin,imputnimi);
	for(int i=0;i<kaikkipitseriat.size();i++){
		for(int j=0;j<kaikkipitseriat[i].GetPizza().size();j++){

			if(imputnimi==kaikkipitseriat[i].GetPizza()[j]->Getpizzanimi()){
			cout<<"Pizzeria löytyi, jossa myydään pizzaasi!\n";
			cout<<kaikkipitseriat[i].Getnimi()<<endl;
			cout<<kaikkipitseriat[i].Getosoite()<<endl;
			cout<<"=================================\n";
			} 
				
			}
	
	}

			break;
			}

	}

}
}
int Menu()
{

int valintatemp=0;
	cout<<"=======================\n";
	cout<<"=======MENU============\n";
	cout<<"1.Lisää Pitseria\n";
	cout<<"2.Lisää Pitsa\n";
	cout<<"3.Lisää raaka-aine\n";
	cout<<"4.Tulosta Pitseriat\n";
	cout<<"5.Tulosta Pitsat\n";
	cout<<"6.Tulosta Raaka-aineet\n";
	cout<<"7.Lisää Pitserioihin Pitsoja\n";
	cout<<"8.Lisää Pizzoihin raaka-aineita\n";
	cout<<"9.Tulosta Pitserian Pizzat\n";
	cout<<"10.Tulosta Pizzan raaka-aineet\n";
	cout<<"11.Hae Pitserioita nimen perusteella\n";
	cout<<"12. Hae Pitseriota pizzan perusteella\n";
	cout<<"0.Lopeta\n";
	cout<<"=======================\n";
	cout<<"=======================\n";
	cin>>valintatemp;

	return valintatemp;
}



			