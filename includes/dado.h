#ifndef DADO_G
#define DADO_G
#define VALOR_MAX 6

#include <random>
#include <iostream>


class Dado{

	//Atributos
	
private:
	int d_valor;
	std::random_device 				rd; 
	std::default_random_engine 		gen; 
	std::uniform_int_distribution<> dis;
	
public:
	Dado();
	~Dado();

	int getValor();
	
};

#endif
