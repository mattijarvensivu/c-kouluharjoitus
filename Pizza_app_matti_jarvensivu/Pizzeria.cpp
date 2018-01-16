#include "Pizzeria.h"



Pizzeria::Pizzeria(string a, string b){
		this->nimi=a;
		this->osoite=b;
		
	}
		string Pizzeria::Getnimi()
		{
		return nimi;
		}
		string Pizzeria ::Getosoite()
		{
			return osoite;
		}
		vector<Pizza*> Pizzeria::GetPizza(){
			return Pizzat;
		}

		
		void Pizzeria::SetPizza(Pizza* a){
			Pizzat.push_back(a);
		}