#ifndef JOGO_H
#define JOGO_H
#include "../includes/jogador.h"
#include <vector>

class Jogo{
private:
	int valorMax; /*valor da limiar*/
	int numerosJogadores; /*numeros de jogadores*/
	int quantDados; /*quantidade de dados*/
	std::vector < Jogador * > jogadores; /*vetor ptr jogador*/
	bool ganhou;

public:
	Jogo();
	Jogo(const int valorMax_,const int numerosJogadores_,const int quantDados_);
	~Jogo();

	int getQuantDados();
	void setQuantDados(int quantDados_);

	int getValorMax();
	void setValorMax(int valorMax_);

	int getNumerosJogadores();
	void setNumerosJogadores(int numerosJogadores_);

	static bool isSomaLess(const Jogador * j1,const Jogador * j2); /*auxiliar da funcao sort*/
	
	void addJogador(Jogador* jogador_);	/*add ao vetor um jogador */
	std::vector<Jogador*> getJogadores(); /*retorna o vetor de jogadores*/

	void addJogadores(); /*povoar o vetor jogadores com a quantidade de jogador recebida*/

	void imprimirVencedor(std::vector < Jogador * > j_);

	void imprimirPerdedores(std::vector < Jogador * > j_);
	
	static void menu();

	void run();
	
	

};


#endif
