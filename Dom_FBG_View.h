/*
Projeto Dominó
Dom-FBG

Grupo: João Victor Espanholi, Rodrigo Poinha, Gustavo Leite, Diogo Napolis

O objetivo do projeto é desenvolver um programa em C que permite ao usuário jogar o 
“jogo de dominó” com regras simples (sem ser o jogo fechado). 
O jogo poderá ser jogado entre dois oponentes reais (pessoas) 
ou entre um jogador real e o computador 
*/

int MenuGeral();

int MenuJG(int test);

void Cabecalho();

void RegrasDomino();

void apresentaPeca(char jogador);

void pecasJ1();

void pecasJ2();

void layoutMesa();

void Mesa();

void MsgErro();

void opcErro();

void nmrErro();

void impBuy();

void nextJ();

void Nturno();

void opcInval();

void partidaOver();

void countPontos();

void J1Venceu();

void J2Venceu();

void breakGame();

void drawGame();

void AltVez(struct statusPecas pecas[28] , char jogador);

void DominoJG(struct statusMesa mesa[28], int i);

int OpcPeca(int nwh);

int EDLado(int lado);

void NewLine();

void quit();

void soon();

void Inval();

void Gravacao();

void Leitura();

void Jgsav();

void NJgsav();

void Jgrec();

void NJgrec();

void ErrabrP();

void ErrgravP();

void ErrabrQ();

void ErrgravQ();

void ErrabrJ();

void ErrgravJ();

void ErrabrMP();

void ErrgravMP();

void ErrabrTM();

void ErrgravTM();

void Errabrcompr();

void Errgravcompr();

void Errabrempt();

void Errgravempt();

void naohajogo();

void pecajogadabot();

void pecacompradabot();

void vezpassadabot();

void erro1recARQempate();

void erro2recARQempate();