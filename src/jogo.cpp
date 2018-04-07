#include "../includes/jogo.h"
#include <algorithm>
#include <iostream>

//construtores
Jogo::Jogo(){
	
}
Jogo::Jogo(int valorMax_, int numerosJogadores_, int quantDados_){
	valorMax = valorMax_;
	numerosJogadores = numerosJogadores_;
	quantDados =  quantDados_;
	ganhou = false;
}

//destutor
Jogo::~Jogo(){}



int Jogo::getQuantDados(){	 /*pega quantidade de dados no jogo */
		return quantDados;
	}
void Jogo::setQuantDados(int quantDados_){	 /*insere  quantidade de dados no jogo */
		quantDados = quantDados_;
	}

int Jogo::getValorMax(){ 	/*pega valor maximo de N*/
		return valorMax;
	}
void Jogo::setValorMax(int valorMax_){	/*seta valor maximo de N*/
		valorMax = valorMax_;
	}

int Jogo::getNumerosJogadores(){ 
		return numerosJogadores;
	}
void Jogo::setNumerosJogadores(int numerosJogadores_){
		numerosJogadores = numerosJogadores_;
	}

bool Jogo::isSomaLess(const Jogador * j1,const Jogador * j2){ /*auxiliar do paramento do metodo sort (begin, end, bool)*/
	return j1->somarDados < j2->somarDados;
}

//Método responsável por adicionar jogadores
void Jogo::addJogador(Jogador* jogador_){

	jogadores.push_back(jogador_);
}

//Obter o vetor de jogadores
std::vector<Jogador*> Jogo::getJogadores(){
	return jogadores;
}



void Jogo::menu(){
	
	int num_jogadores=0,num_dados=0,valor_maximo=0, cjog=0;
	Jogo n; /*declara um jogo */

	int op;
	do{
		system("clear");
		std::cout << "******************JOGO DE DADOS********************" << std::endl;
		std::cout << " ------- >> selecione a opcao desejada <<-------- \n" << std::endl;
		std::cout << "| (1) configurar regras do jogo"; if(num_jogadores!=0)std::cout << "   -> ok" <<std::endl; else std::cout << "   -> *" <<std::endl;
		std::cout << "| (2) adicionar jogadores"; if(cjog!=0)std::cout << "   -> ok" <<std::endl; else std::cout << "   -> *" <<std::endl;
		std::cout << "| (3) iniciar"; if(cjog!=0 && num_jogadores!=0)std::cout << "   -> selecione para iniciar" <<std::endl; else std::cout << "   -> *" <<std::endl;
		std::cout << "| (0) para sair" << std::endl;
		std::cout << "\n***************************************************" << std::endl;

		std::cout << "Digite a opcao: ";
		std::cin >> op;
		

		switch(op) {

			case 0:
				std::cout << "fim! ate breve... :D " << std::endl;
				break;

			case 1:
			
			//recebe as configuracoes do jogo
			if(num_jogadores==0){
				std::cout << "Digite quantidade de jogadores que irar participar: " << std::endl;
				std::cin >> num_jogadores;
				std::cout << "Digite quantidade de dados: " << std::endl;
				std::cin >> num_dados;
				std::cout << "Digite valor do objetivo (valor limite): " << std::endl;
				std::cin >> valor_maximo;
			}
			break;

			case 2:
				//instancia o jogo
				if(num_jogadores >= 2 && cjog==0){

					//-> Jogo::Jogo(int N(limiar), int num de jogadores, int num de dados)
					n = Jogo(valor_maximo,num_jogadores,num_dados);
					n.addJogadores(); /*povoar vetor com os jogadores*/
					cjog++;
				}
			break;

			case 3:
				if(cjog!=0 && num_jogadores!=0){
				//iniciar jogo
				n.run();
				op=0;
				}
			break;
			
			
			default:
				std::cout << "opcao invalida " << std::endl;
			
		}	

	}while(op);

}


void Jogo::run(){

	//variaveis necesssaria para a logica do jogo
	std::string opcao = " ";
	int rodada = 0;
	int passou=0;
	int auxpass=0;
	int quantAtivo=getNumerosJogadores();
	system("clear");

	
	//iniciando as rodadas
	while (!ganhou){
		
		rodada++;
		passou=0;
		std::cout << "--------------- RODADA " << rodada << " -------------------" << std::endl;
			for(int i=0; i < numerosJogadores; i++){

				//jogador com status true esta no jogo
				if(jogadores[i]->getStatus() && ganhou==false){

					std::cout << jogadores[i]->getNome() << " Seus pontos: " << jogadores[i]->getSomarDados() << "\n" << std::endl ;
					if(rodada>1){
						std::cout << jogadores[i]->getNome() << " deseja jogar essa rodada? s -> sim n -> nao (s/n): ";
						std::cin >> opcao;
						}

					//opcao s joga ou joga a primeira rodada para todos
					if(opcao=="s" || rodada==1){
						//lanca os dados
						jogadores[i]->jogar(quantDados);
						passou=0;
						auxpass=rodada;
						//verifica se o jogador atingiu exatamente valor N (regra 3)
						if(jogadores[i]->getSomarDados() == valorMax){
							ganhou=true;
							for(int c=0; c < numerosJogadores; c++){
								//seta tds false. jogadores restante 
								if(i!=c)
								jogadores[c]->setStatus(false);
								}

						}//endiff
						//verifica se a soma ao lancar ultrapassou o valor max
						if(jogadores[i]->getSomarDados() > valorMax){	
							jogadores[i]->setStatus(false);
							std::cout << jogadores[i]->getNome() << " vc perdeu! *.* passou de "<< valorMax << " Seus pontos\n"<<std::endl;
							quantAtivo--;
							//verifica se resta 1 e declara vencedor (regra 1)
							int f=numerosJogadores;
							for(int c=0; c < numerosJogadores; c++){
								if(jogadores[c]->getStatus()==false)
								f--;
								if(f==1) ganhou=true;
							}
	
						}//endif
					}else{
							//passa a vez, caso tds passem, declarar o vencedor o mais proximo de N (regra 2)
							std::cout << jogadores[i]->getNome() << " passou a jogada! \n"<< std::endl;
							passou++;

							//se quantidade jogador ativo passar a vez, e verifica se e na mesma rodada
							if(passou==quantAtivo && auxpass!=rodada){
								ganhou=true;
								//ordena o vetor pela soma dos dados
								std::sort(jogadores.begin(),jogadores.end(),isSomaLess);

								//percorre o vetor aonde esta os ativos e seta tds false
								for(int c=0; c < numerosJogadores; c++){
									jogadores[c]->setStatus(false);
								}
								//achar o mais proximo a N. declara vencedor
								for(int c=numerosJogadores-1; c >= 0; c--){
									if(jogadores[c]->getSomarDados() < valorMax){
										jogadores[c]->setStatus(true);
										c=-1; //ou break :D
									}
								}
							}
							
					}
		
				}//endif
			}//endfor
	
	}//enwhile
	
//imprimir resultados
imprimirVencedor(jogadores);
imprimirPerdedores(jogadores);

std::cout << "--------------------------- FIM DO JOGO -------------------------" << std::endl;

}



void Jogo::imprimirVencedor(std::vector < Jogador * > j_){
		//imprimi o vencedor  (true = vencedor)
		for(int i=0; i < numerosJogadores; i++){
			if(j_[i]->getStatus() && ganhou==true){
				std::cout << "\n######################### VENCEDOR ############################"<< std::endl;
				std::cout << "\n----------------> " << j_[i]->getNome() << " vc GANHOU com " << j_[i]->getSomarDados()<< " pontos! < ----------------" << std::endl;
				std::cout << "\n-> Objetivo mais próximo ou igual e abaixo do valor "<<valorMax<<"\n-> "<<numerosJogadores<<" jogadores participou,\n-> "<<quantDados<< " dados lancado por jogador"<< std::endl;
				std::cout << "###############################################################\n" << std::endl;
			}
		}

}



void Jogo::imprimirPerdedores(std::vector < Jogador * > j_){
		//imprimi tds o resto false = perdedores
		for(int i=0; i < numerosJogadores; i++){
			if(j_[i]->getStatus()==false && ganhou==true){
				
				std::cout << j_[i]->getNome() << " vc perdeu, fez " << j_[i]->getSomarDados()<< " pontos!" << std::endl;
			}
		}

}


void Jogo::addJogadores(){
	//povoa o vetor
	for(int i=0; i < numerosJogadores; i++){
		//entrar com nome dos jogadores
		std::string n;
		std::cout << "Digite o nome do jogador "<< i+1 <<":";
		std::cin>>n;
		//estancia os jogadores
		addJogador(new Jogador(n));
		
	}
}

