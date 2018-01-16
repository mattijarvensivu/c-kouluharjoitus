#ifndef PIZZA_H
#define PIZZA_H
#include <vector>
#include "raaka_aine.h"
using namespace std;
class Pizza{
	 private:
		 string nimi;
		 int hinta;
		 vector<Raaka_aine*>pizza_raaka_aineet;
	 public:
		 Pizza();
		 Pizza(string, int);
		 string Getpizzanimi();
		 int Getpizzahinta();
		 vector<Raaka_aine*> Getpizza_raaka_aine();
		 void Setraaka_aine(Raaka_aine*);
		 
		
		
			 
		};
#endif