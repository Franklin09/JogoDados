#ifndef JOGADOR_G
#define JOGADOR_G
#include <string>

class Jogador{

private:
	std::string nome;
	bool status;	

public:
	int somarDados;


	Jogador();
	Jogador(std::string nome_);
	~Jogador();

	std::string getNome();

	int getSomarDados();

	bool getStatus();
	void setStatus(bool status_);
	
	void jogar(int QuantDados_);

};


#endif
