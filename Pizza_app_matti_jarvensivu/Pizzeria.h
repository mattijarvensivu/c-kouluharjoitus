#ifndef PIZZERIA_H
#define PIZZERIA_H
#include <vector>
#include "Pizza.h"
using namespace std;
class Pizzeria

{
	private:
		string nimi;
		string osoite;
		vector<Pizza*>Pizzat;

	public:
		Pizzeria();
		Pizzeria(string, string);
		string Getnimi();
		string Getosoite();
		vector<Pizza*> GetPizza();
		void SetPizza(Pizza*);
	};
#endif