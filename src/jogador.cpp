#include "../includes/jogador.h"
#include "../includes/dado.h"
#include <vector>


Jogador::Jogador(std::string nome_){
nome = nome_;
somarDados=0;
status = true;
}

Jogador::Jogador(){
}

Jogador::~Jogador(){

}

std::string Jogador::getNome(){
	return nome;
}

int Jogador::getSomarDados(){
	return somarDados;
}

bool Jogador::getStatus(){
	return status;
}
void Jogador::setStatus(bool status_){
	status = status_;
}
//ao jogar dado
void Jogador::jogar(int QuantDados_){

	//estancia quantidade de dados recebida
	std::vector<Dado> v(QuantDados_);
	int aux, soma = 0;
	
	for(int i=0; i < (int) v.size(); i++){
		aux = v[i].getValor();
		std::cout<< "Dado "<<i+1<<": "<< aux <<std::endl;
		soma+=aux;
		aux=0;
	}
	std::cout<< "\n"<<nome << " nessa rodada você fez -----> "<< soma << " <----- pontos\n";
	somarDados+=soma;
	std::cout<< "Total: " << somarDados<<"\n"<<std::endl;
	
	
	
}
