#include "Pizza.h"
	 Pizza::Pizza(){};

	 Pizza::Pizza(string a, int b){
		this->nimi=a;
		this->hinta=b;
	 }
	 string Pizza::Getpizzanimi(){
	 return nimi;
	 }
	 int Pizza::Getpizzahinta(){
	 return hinta;
	 }
	 void Pizza::Setraaka_aine(Raaka_aine* a){
		 pizza_raaka_aineet.push_back(a);
	 }
	 vector<Raaka_aine*> Pizza::Getpizza_raaka_aine(){
		 return pizza_raaka_aineet;
	 }