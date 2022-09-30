/*
Projeto Dominó
Dom-FBG

Grupo: João Victor Espanholi, Rodrigo Poinha, Gustavo Leite, Diogo Napolis

O objetivo do projeto é desenvolver um programa em C que permite ao usuário jogar o 
“jogo de dominó” com regras simples (sem ser o jogo fechado). 
O jogo poderá ser jogado entre dois oponentes reais (pessoas) 
ou entre um jogador real e o computador 
*/


void IniciaMenu();

void gerarpeca();

void embaralharpecas();

void IniciarJogo(struct statusPecas pecas[28]);

void Jogada();

int recuperarJogo();

int salvarJogo();

void jogcomputador();

void continuarjogoBOT();
