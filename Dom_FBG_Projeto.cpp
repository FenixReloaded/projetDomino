/*
Projeto Dominó
Dom-FBG

Grupo: João Victor Espanholi, Rodrigo Poinha, Gustavo Leite, Diogo Napolis

O objetivo do projeto é desenvolver um programa em C que permite ao usuário jogar o 
“jogo de dominó” com regras simples (sem ser o jogo fechado). 
O jogo poderá ser jogado entre dois oponentes reais (pessoas) 
ou entre um jogador real e o computador 
*/

#include "Dom_FBG_Model.cpp"
#include "Dom_FBG_Controller.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	
	Cabecalho();
	IniciaMenu();
	
	//só intercalamos esta função pois chamamos umas as outras 
	//em funções diferentes ao longo de outros arquivos
	
	
}