/*
Projeto Dominó
Dom-FBG

Grupo: João Victor Espanholi, Rodrigo Poinha, Gustavo Leite, Diogo Napolis

O objetivo do projeto é desenvolver um programa em C que permite ao usuário jogar o
“jogo de dominó” com regras simples (sem ser o jogo fechado).
O jogo poderá ser jogado entre dois oponentes reais (pessoas)
ou entre um jogador real e o computador
*/
#include "Dom_FBG_View.h"
#include <stdio.h>
#include <iostream>
int MenuGeral() {

//declaramos a variavel opc como forma de escolher a forma para que o programa prossiga
	int opc;

	printf("\n========================================= ");
	printf("\nDigite sua escolha: ");
	printf("\n 1 -Iniciar jogo (2 jogadores) \n 2 -Iniciar jogo (contra o computador) \n 3 -Retornar ao jogo interrompido \n 4 -Regras gerais do Jogo \n 5 -Salvar o jogo \n 6 -Recuperar o jogo salvo \n 0 -Sair \n");
	printf("\n========================================= ");

	scanf("%d", &opc);

	return(opc);
}

//funcao para imprimir as regras do jogo
void RegrasDomino(){

	printf("Para jogar domino sao necessarias 28 pedras retangulares. \n");
	printf("Cada pedra esta dividida em 2 espaços iguais em que aparece um numero de 0 ate 6.\n");
	printf("As pedras abrangem todas as combinacoes possiveis com estes numeros.\n");
	printf("O objetivo do jogo e colocar todas as suas pedras na mesa antes dos adversarios e marcar pontos.\n");
	printf("O jogador que tiver menos pecas vence.\n");

}

//impressão do cabeçalho do menu do dominó
void Cabecalho(){

	printf("               DOMINO FBG PUC SP            \n");
	printf("	,---------,   ,---------,   ,---------,\n");
	printf("	| '   '.' |   |  .' ' ' |   |  .  ''' |\n");
	printf("	|_'___'_'_|   |_'___'_'_|   |_____'''_|\n");

}
//apresentação das peças
void apresentaPeca(char jogador){

	int k;
	int i=1;

	printf("\t pecas jogador (%c):", jogador);

	for(k = 0; k <=28 ; k++)
	{
		if(pecas[k].status == jogador)
		{

			printf("%d.[%d|%d]  \n\n",i,pecas[k].Lado1, pecas[k].Lado2);
			i++;
		}

	}

}
//submenu para jogadas individuais
int MenuJG(int test, int extE, int extD){
	char opc;
	int ext;

	printf("\nDigite sua escolha: \n J - Jogar \n C - Comprar   \n P - Passar \n S - Sair (interrorper o jogo) \n");

	scanf("%s", &opc);

	if(opc == 'j'  || opc == 'J')
	{
		ext = 1;
	}
	if(opc == 'c' || opc == 'C')
	{
		ext =2;
	}
	if(opc == 's' || opc == 'S')
	{
		ext =3;
	}
	if(opc =='p' || opc == 'P')
	{
		ext =4;
	}
	if(opc != 'j' && opc!= 'J' && opc != 'c' && opc != 'C' && opc != 'p' && opc != 'P' && opc != 's' && opc != 'S')
	{
		ext = 5;
	}
	return ext;

}
//função para saber qual jogador possui a maior peça
/*void maiorP(){

	printf("MAIOR PECA:[%d/%d] -> ",aux.Lado1,aux.Lado2);

}*/
//peças do jogador 1
void pecasJ1(){

	printf("Jogador 1  \n");

}
//peças do jogador 2
void pecasJ2(){

	printf("Jogador 2  \n");

}

//função para observar a forma da mesa
void layoutMesa(){
	printf("=");
}
//função para imprimir MESA
void Mesa(){

	printf("MESA\n");

}

void NewLine(){

	printf("\n");

}

/*void J1turn(){

	printf("--------VEZ DO JOGADOR 1--------\n\n");

}

void J2turn(){

	printf("--------VEZ DO JOGADOR 2--------\n\n");

}*/

/*void pecasEscrito(){

	 printf("PECAS:  ");

}*/

//função imprime a possibilidade de demonstrar se o lado que o jogador escolhe para jogar é impossível
void MsgErro(){

	printf("A jogada nao pode ser efetuada pelo lado escolhido.\n");

}
//função imprime a possibilidade de verificar se a opção escolhida é valida
void opcErro(){

	printf("A opcao escolhida esta invalida neste lado da mesa\n");

}
//função imprime a possibilidade de checar se a numeração da peça esta errada
void nmrErro(){

	printf("Esta peca possui a numeracao errada");

}
//função imprime a possibilidade de saber se é possível comprar mais peças
void impBuy(){

	printf("Nao ha mais pecas para comprar");

}
//função imprime a possibilidade de pesquisar para passar a vez do jogador
void nextJ(){

	printf("TURNO DO PROXIMO JOGADOR");

}
//função imprime a possibilidade de notar se ainda ha pecas para serem compradas ou jogadas
void Nturno(){

	printf("Ainda ha possibilidade de comprar ou jogar pecas\n");

}
//função imprime a possibilidade de reparar se a opção dada é invalida
void opcInval(){

	printf("Esta opcao esta invalida!");

}
//função imprime a possibilidade de ver se a partida não possui mais jogadas, fechando a partida
void partidaOver(){

	printf("A partida ficou fechada por nao possuir mais jogadas\n");

}
//função imprime a possibilidade de verificar a quantidae de pontos
void countPontos(){

	printf("De acordo com a contagem de pontos\n");

}
//função imprime a possibilidade de decidir o jogador 1 como vencendor
void J1Venceu(){

	    printf("----------------------------------------\n");
        printf("             ___________\n");
        printf("            '._==_==_=_.'\n");
        printf("            .-|       |-.\n");
        printf("           | (|:.jog  |) |\n");
        printf("            '-|:. 1   |-'\n");
        printf("               ::.    /\n");
        printf("               '::. .'\n");
        printf("                 ) (\n");
        printf("               _.' '._\n");
        printf("\n-------------------------------------\n");
        printf("|       Parabens voce venceu          |\n");
        printf("|              JOGADOR 1              |\n");
        printf("-------------------------------------\n");
        system("pause");

}
//função imprime a possibilidade de decidir o jogador 2 como vencendor
void J2Venceu(){

	    printf("----------------------------------------\n");
        printf("             ___________\n");
        printf("            '._==_==_=_.'\n");
        printf("            .-|       |-.\n");
        printf("           | (|:.jog  |) |\n");
        printf("            '-|:. 2   |-'\n");
        printf("               ::.    /\n");
        printf("               '::. .'\n");
        printf("                 ) (\n");
        printf("               _.' '._\n");
        printf("\n-------------------------------------\n");
        printf("|        Parabens voce venceu            |\n");
        printf("|              JOGADOR 2                 |\n");
        printf("-------------------------------------\n");
        system("pause");

}
//função imprime a possibilidade de quebrar o jogo
void breakGame(){

	printf("Jogo interrompido\n");

}
//função imprime a possibilidade de um empate
void drawGame(){

	printf("O jogo empatou pois os jogadores tem o mesmo numero de pecas e somatorias\n");

}
//função imprime a troca de turno entre jogadores
void AltVez(struct statusPecas pecas[28], char jogador ){

	int i, nwh;
	nwh = 1;
	if(jogador=='1')
	{
		printf("--------VEZ DO JOGADOR 1--------\n\n");
	}
	else
	{
		printf("--------VEZ DO JOGADOR 2--------\n\n");
	}
	printf("PECAS: ");
	for(i = 0; i < 28; i++)
	{
		if(pecas[i].status == jogador)
		{
			printf("%d.[%d|%d]  ",nwh , pecas[i].Lado1, pecas[i].Lado2);
			nwh++;
		}
	}
	printf("\n");

}


//função imprime a possibilidade de analisar as peças jogadas
void DominoJG(struct statusMesa mesa[28], int i){

	printf("[%d/%d] ",statusMesa[i].Lado1, mesa[i].Lado2);

}
//função destinada a escolher a peça do jogador
int OpcPeca(int nwh){

{
	int opc;
	printf("Escolha a peca para jogar (0 para desistir): ");
	scanf("%d",&opc);
	return opc;
}

}

//função destinada a escolher o lado das pecas
int EDLado(int lado){

	char pc;
	int saida;


	printf("Escolha o lado da Mesa: Esquerdo/Direito (E/D): ");
	scanf("%s",&pc);

	if(pc == 'e'|| pc == 'E' )
	{
		saida = 1;
	}
	if(pc == 'd'|| pc == 'D' )
	{
		saida = 2;
	}
	if(pc != 'e' && pc != 'E' && pc != 'd' && pc != 'D' )
	{
		saida = 3;
	}

	return saida;

}

void quit(){

	printf("Obrigado por jogar, ate a proxima\n");
}

void soon(){

	printf("Em breve\n");
}

void Inval(){
	printf("Opcao invalida!!");
}

void Gravacao(){
	printf("gravacao\n");
}

void Leitura(){
	printf("leitura\n");
}

void Jgsav(){
	printf("O jogo foi salvo\n");
}

void NJgsav(){
	printf("Nao foi possivel salvar o jogo\n");
}

void Jgrec(){
	printf("O jogo foi recuperado\n");
}

void NJgrec(){
	printf("Nao foi possivel recuperar o jogo\n");
}

void ErrabrP(){
	printf("O arquivo ARQPecas não pode ser aberto para \n");
}

void ErrgravP(){
	printf("Erro no arquivo ARQPecas: ");
}

void ErrabrQ(){
	printf("O arquivo ARQMesa não pode ser aberto para \n");
}

void ErrgravQ(){
	printf("Erro no arquivo ARQMesa: ");
}

void ErrabrJ(){
	printf("O arquivo ARQJog não pode ser aberto para \n");
}

void ErrgravJ(){
	printf("Erro no arquivo ARQJog: ");
}

void ErrabrMP(){
	printf("O arquivo ARQmesaP não pode ser aberto para \n");
}

void ErrgravMP(){
	printf("Erro no arquivo ARQmesaP: ");
}

void ErrabrTM(){
	printf("O arquivo ARQTmesa não pode ser aberto para \n");
}

void ErrgravTM(){
	printf("Erro no arquivo ARQTmesa: ");
}

void Errabrcompr(){
	printf("O arquivo ARQcompr não pode ser aberto para \n");
}

void Errgravcompr(){
	printf("Erro no arquivo ARQcompr: ");
}

void Errabrempt(){
	printf("O arquivo ARQempate não pode ser aberto para \n");
}

void Errgravempt(){
	printf("Erro no arquivo ARQempate: ");
}

void naohajogo()
{
	printf("Nao ha jogo para ser continuado");
}

void erro1ARQempate()
{
	printf("O arquivo ARQempate não pode ser aberto para gravação\n");
}

void erro2ARQempate()
{
	printf("Erro na gravacaodo arquivo ARQempate");
}

// mensagens de recuperacao
void erro1recARQmesaP()
{
	printf("O arquivo ARQmesaP não pode ser aberto para leitura\n");
}

void erro2recARQmesaP()
{
	printf("Erro na leitura do arquivo ARQmesaP");
}

void pecajogadabot()
{
	printf("Peca jogada pelo bot\n");
}

void pecacompradabot()
{
	printf("Peca comprada pelo bot\n");
}

void vezpassadabot()
{
	printf("Vez passada pelo bot\n");
}

void erro1recARQempate()
{
	printf("O arquivo ARQempate não pode ser aberto para leitura\n");
}

void erro2recARQempate()
{
	printf("Erro na leitura do arquivo ARQempate");
}
