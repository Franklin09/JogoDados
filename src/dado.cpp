#include "../includes/dado.h"

//construtor 
Dado::Dado():rd(), gen(rd()), dis(1, VALOR_MAX){
d_valor =0;
}
//destroi dado
Dado::~Dado(){}

//retorna um valor de 1 a 6
int Dado::getValor(){
	d_valor = std::round(dis(gen));
	return d_valor;
}