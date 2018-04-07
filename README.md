#JOGO DE DADOS
#AUTORIA: David Franklin e Eliaquin dos santos
#DISCIPLINA: LINGUAGEM DE PROGRAMACAO 1
#PROFESSOR: SILVIO SAMPAIO
#UFRN

Compilação:
	Para compilar basta chamar no terminal o comando "make";
	Para remover os arquivos criados pelo processo de copilaçao, basta chamar no terminal o comando "make clean".

Objetivo:
Esse programa trata-se de um jogo de dados hipotético, no qual cada jogador (de vários) deve lançar dois ou mais dados em sua vez. 
A soma dos valores dos dados deve ser acumulada para cada jogador. O objetivo é ficar o mais próximo e abaixo do valor N a ser 
estabelecido como configuração geral do jogo e visível a todos os jogadores. 
* Ao obter um valor agregado superior a N, o jogador é considerado excluído da partida.
* A cada vez de jogar, o jogador pode optar por jogar os dados ou parar (e não jogar mais na rodada). 
* Uma partida é finalizada quando: 
	(1) resta apenas um jogador, uma vez que os outros foram excluídos; 
	(2) quando não há mais jogadores a jogar, ou seja, todos os jogadores “ativos” decidiram parar, ou; 
	(3) quando um dos jogadores atinge exatamente o valor N. Vence a rodada o jogador que permanecer na rodada (ou seja, não for excluído) e obtiver o
	número de pontos agregados mais próximo de N. 
Ao final de cada rodada, o programa deverá listar os pontos agregados obtidos por cada jogar e declarar o campeão da partida.
