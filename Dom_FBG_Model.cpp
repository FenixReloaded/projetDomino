/*
Projeto Dominó
Dom-FBG

Grupo: João Victor Espanholi, Rodrigo Poinha, Gustavo Leite, Diogo Napolis

O objetivo do projeto é desenvolver um programa em C que permite ao usuário jogar o 
“jogo de dominó” com regras simples (sem ser o jogo fechado). 
O jogo poderá ser jogado entre dois oponentes reais (pessoas) 
ou entre um jogador real e o computador 
*/

//recorremos a um struct para simplificar o armazenamento das informações das peças
//assim, criamos uma classe específica à elas

struct statusPecas{

    char status;
    int Lado1;
    int Lado2;
    
    
    
}pecas[28], aux;

struct statusMesa{
	
	int Lado1;
	int Lado2;	
	
	
	
	
}mesa[28];


int u;

char jogador;

int extD,extE;

int mp;

int tm;

int buy;

int draw;

int bora;