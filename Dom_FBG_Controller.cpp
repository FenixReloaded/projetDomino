/*
Projeto Dominó
Dom-FBG

Grupo: João Victor Espanholi, Rodrigo Poinha, Gustavo Leite, Diogo Napolis

O objetivo do projeto é desenvolver um programa em C que permite ao usuário jogar o 
“jogo de dominó” com regras simples (sem ser o jogo fechado). 
O jogo poderá ser jogado entre dois oponentes reais (pessoas) 
ou entre um jogador real e o computador 
*/

#include "Dom_FBG_Controller.h"
#include "Dom_FBG_View.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void gerarpeca(){ 
	
	
	int i, j, k=0;
	
	  for (i=0; i<=6; i++)
    {
        for (j=i; j<=6; j++)
        {	
        	//acumulamos o valor dos lados e os associamos aos mesmos
            pecas[k].Lado1 = i;
            pecas[k].Lado2 = j;
            k++;
        }
	}	
}

// nessa função intercalamos todos os valores agregados das peças
// e intercalamos a função gerarpeca para aproveita-lá

void embaralharpecas(){
	
	//declarações
	
    int i, k;
	struct statusPecas aux;
	//a função gerar pecas foi chamada aqui para que o cálculo de valores das peças seja efetuado
	//e possamos embaralhar o dominó
	gerarpeca();
	
	//aqui cabe usarmos a biblioteca que nos permite "randomizar" um número
	srand(time(NULL));
	
	
	//por fim desta função, criamos laços de loop para que
	//o computador efetue uma lógica que evite repetição de numeros
	//aleatorios e não tenhamos peças iguais no dominó
	for (i=0; i<28; i++)
	{
		k=rand()%28;
		aux=pecas[i];
		pecas[i]=pecas[k];
		pecas[k]=aux;	
	}


    
}


void IniciaMenu()
{
	int op;
	int ext;
	do{
	op=MenuGeral();
	
	switch (op){
	case 1: 	
		bora = 1;
		IniciarJogo(pecas);
		Jogada();
	break;

	case 2: 
		bora = 2;
        jogcomputador();
	break;

	case 3:
		if (bora == 1)
            {
                Jogada();
            }
            if (bora == 2)
            {
                continuarjogoBOT();
            }
            if (bora != 1 && bora != 2)
            {
                naohajogo();
            }
	break;
	
	case 4:
		RegrasDomino();
	break;
	
	case 5: 	
	ext = salvarJogo();
        	if(ext==0)
        	{
        		Jgsav();
			}
			else
			{
				NJgsav();
			}
            break;
        case 6:
        	recuperarJogo();
        	if(ext==0)
        	{
        		Jgrec();
			}
			else
			{
				NJgrec();
			}
            break;

	case 0:
		quit();
	break;
	
		
	default: 
		void Inval();
		
		}
	}while(op!=0);
}


void IniciarJogo(struct statusPecas pecas[28]){
	
	int i, k,x,loc,sum,sum2,fn,N,side, t1;
    int esc;
    int t;
    
	
	//declarações de valores para variavel auxiliar
	aux.status = ' ';
	aux.Lado1 = 0; aux.Lado2 = 1;
	buy=13;
    mp=1;
    side=0;
    draw=0;
    tm =5;
	
	//utilizamos um cursor para percorrer o vetor como um todo
	
	for(i = 0; i <28; i++)
	{	
		pecas[i].status = ' ';	
	}
	
	embaralharpecas();
	
	
	//utilizamos um cursor para percorrer o vetor até certo ponto
	//representando as peças do jogador 1 e no for abaixo o mesmo é feito
	//porém para o jogador 2
	
	for(i = 0; i <= 6; i++)
	{	
		pecas[i].status = '1';	
	}
	
	for(i = 7; i <= 13; i++)
	{	
		pecas[i].status = '2';	
	}
	
	
	
	
	//a primeiro momento testamos a equivalencia dos lados para que, por exemplo
	//o jogo comece com a peça 6|6 ou 5|5, etc.
	for(i=0; i<=13; i++)
	{
		if(pecas[i].Lado1 == pecas[i].Lado2)
		{	
		  if(aux.Lado1 <= pecas[i].Lado1)
		  {
		  	aux = pecas[i];
		  	u = i;
		}
		//caso não haja peça alguma igual dentre os jogadores, teremos que começar pela maior soma
		//e por consequencia, verificar qual possui o maior valor em seus lados caso tenham peças com soma igual
		else{

            if(aux.Lado1 + aux.Lado2 <= pecas[i].Lado1 + pecas[i].Lado2)
              {
                  if(aux.Lado1 || aux.Lado2 > pecas[i].Lado1 || pecas[i].Lado2 )
                  {
                    aux = pecas[i];
                    u = i;
                  }
              }

			}
		}
	}

tm  = tm +7;
    
    if(pecas[u].status == '1')
    {
        pecasJ1();
       
    }
    else
    {
        pecasJ2();
        
    }
    mesa[0].Lado1 = aux.Lado1;
    mesa[0].Lado2 = aux.Lado2;
    
}

void Jogada(){

	int i, k,x,loc,sum,sum2,fn,N,side, t1;
    int esc;
    int t;
	
    //associamos a mesa inicial às extremidades para que as jogadas possam partir desta
    extE = mesa[0].Lado1;
    extD = mesa[mp-1].Lado2;

    if(pecas[u].status=='1')
    {
        jogador='2';
    }
    else
    {
        jogador='1';
    }
    
    //como as peças estão associadas diretamente aos status,as peças que forem jogadas devem ser atribuidas à mesa
    pecas[u].status = 'm';

    do
    {
        i=0;

        do
        {
            layoutMesa();
            i++;
        }
        while(tm-1 != i);

        i=0;
        NewLine();
        Mesa();
        do
        {

            DominoJG(mesa, i);
            i++;
        }
        while(i<mp);
        NewLine();

        i=0;
        do
        {
            layoutMesa();
            i++;
        }
        while(tm-1 != i);

        i=0;
        NewLine();
 		NewLine();  	
        AltVez(pecas, jogador);


		t1 = MenuJG(t1, extE, extD);

        sum=0;
        switch (t1)
        {
        case 1:
        	
        	loc = OpcPeca(loc);

            if(loc==0)
            {
                break;
            }
			else
            for(i=0; i<27; i++)
            {
                if(pecas[i].status==jogador)
                {
                    sum++;
                }
                if(sum==loc)
                {
                	
                	//caso o lado das pecas seja igual a uma das extremidades, então a jogada poderá ser executada
                	
                    if(pecas[i].Lado1 == extE || pecas[i].Lado1 ==extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                    {
                       
                        draw=0;
                        if((((pecas[i].Lado1 == extE ||  pecas[i].Lado1 ==extD ) && (pecas[i].Lado2==extE || pecas[i].Lado2==extD))&& pecas[i].Lado1 != pecas[i].Lado2)|| extE == extD)
                        {
                        	
                        	
							
                            side = EDLado(side);
							
							//consequentemente testamos a viabilidade de inverter as peças
                            if(side==1)
                            {
                                if(pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                {

                                    for(N=mp; N>=0; N--)
                                    {
                                        mesa[N].Lado1 = mesa[N-1].Lado1;
                                        mesa[N].Lado2 = mesa[N-1].Lado2;
                                    }
                                    if(pecas[i].Lado1==extE)
                                    {
                                        mesa[0].Lado1 = pecas[i].Lado2 ;
                                        mesa[0].Lado2 = pecas[i].Lado1;
                                        mp++;
                                        extE=mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if(jogador=='1')
                                        {
                                            jogador='2';
                                        }
                                        else 
                                        {
                                            jogador='1';
                                        }
                                        tm = tm+6;
                                        break;
                                    }
                                    else if(pecas[i].Lado2==extE)
                                    {
                                        mesa[0].Lado1 = pecas[i].Lado1;
                                        mesa[0].Lado2 = pecas[i].Lado2;
                                        mp++;
                                        extE=mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if(jogador=='1')
                                        {
                                            jogador='2';
                                        }
                                        else
                                        {
                                            jogador='1';
                                        }
                                        tm = tm+6;
                                        break;
                                    }
                                    else
                                    {
                                	MsgErro();
                                    }

                                }
                                
                            }
                            if(side==2 )
                            {

                                if(pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                {
                                    if(pecas[i].Lado1 == extD)
                                    {
                                        mesa[mp].Lado1=pecas[i].Lado1;
                                        mesa[mp].Lado2=pecas[i].Lado2;
                                        extD=mesa[mp].Lado2;
                                        mp++;
                                        pecas[i].status = 'm';
                                        if(jogador=='1')
                                        {
                                            jogador='2';
                                        }
                                        else
                                        {
                                            jogador='1';
                                        }
                                        tm = tm+6;
                                        break;
                                        
                                    }
                                    else if(pecas[i].Lado2 == extD)
                                    {
                                        mesa[mp].Lado1=pecas[i].Lado2;
                                        mesa[mp].Lado2=pecas[i].Lado1;
                                        extD=mesa[mp].Lado2;
                                        mp++;
                                        pecas[i].status = 'm';
                                        if(jogador=='1')
                                        {
                                            jogador='2';
                                        }
                                        else
                                        {
                                            jogador='1';
                                        }
                                        tm = tm+6;
                                        break;
                                    }
								    else MsgErro();
                                    }
                            }
                            if(side == 3)
                            {
                                
                                
                                    opcErro();
                            }
                            
                         
                        }
                        else
                        {
                            if(pecas[i].Lado1==extE)
                            {
                                for(N=mp; N>=0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N-1].Lado1;
                                    mesa[N].Lado2 = mesa[N-1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado2 ;
                                mesa[0].Lado2 = pecas[i].Lado1;
                                mp++;
                                extE=mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if(jogador=='1')
                                {
                                    jogador='2';
                                }
                                else
                                {
                                    jogador='1';
                                }
                                tm = tm+6;
                                break;
                            }
                            else if(pecas[i].Lado2==extE)
                            {
                                for(N=mp; N>=0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N-1].Lado1;
                                    mesa[N].Lado2 = mesa[N-1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado1;
                                mesa[0].Lado2 = pecas[i].Lado2;
                                mp++;
                                extE=mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if(jogador=='1')
                                {
                                    jogador='2';
                                }
                                else
                                {
                                    jogador='1';
                                }
                                tm = tm+6;
                                break;
                            }
                            else if(pecas[i].Lado1 == extD)
                            {
                                mesa[mp].Lado1=pecas[i].Lado1;
                                mesa[mp].Lado2=pecas[i].Lado2;
                                extD=mesa[mp].Lado2;
                                mp++;
                                pecas[i].status = 'm';
                                if(jogador=='1')
                                {
                                    jogador='2';
                                }
                                else
                                {
                                    jogador='1';
                                }
                                tm = tm+6;
                                break;
                            }
                            else if(pecas[i].Lado2 == extD)
                            {
                                mesa[mp].Lado1=pecas[i].Lado2;
                                mesa[mp].Lado2=pecas[i].Lado1;
                                extD=mesa[mp].Lado2;
                                mp++;
                                pecas[i].status = 'm';
                                if(jogador=='1')
                                {
                                    jogador='2';
                                }
                                else
                                {
                                    jogador='1';
                                }
                                tm = tm+6;
                               break;
                            }


                        }

                    }
                    else
                    {
                        nmrErro();
                        NewLine();
                        break;
                    }


                }
            }
            if(sum<loc)
              {
                 opcInval();	
                 NewLine();
			  }
            
			
            break;

        case 2:
        
        //se o numero de compras atingir o valor máximo de peças o programa deve impossibilitar as próximas compras do jogador
            if(buy==27)
            {

                impBuy();
            }
            else
            {


                buy++;
                pecas[buy].status=jogador;


            }


            break;
        case 4:
        
        //verificamos se a passagem de turno pode ser feita ou se há necessidade de declarar empate
            sum=0;
            if(buy==27 )
            {
                for(i=0; i<27; i++)
                {

                    if(pecas[i].status == jogador)
                    {
                        if(pecas[i].Lado1 == extE || pecas[i].Lado1 ==extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            sum++;
                        }
                    }
                }
                if( sum == 0)
                {
                    nextJ();
                    draw++;
                    if(jogador=='1')
                    {
                        jogador='2';
                    }
                    else
                    {
                        jogador='1';
                    }

                }
                else
                {
                    Nturno();
                }
            }
            else
            {
            	NewLine();
                Nturno();
                
            }
            break;


        case 3:
        

            fn=3;
            t1 = 3;
            break;

        default:

            opcInval();
            break;

        }
		NewLine();
		
        sum=0;
        sum2=0;

        if(draw == 2)
        {
            for(i=0; i<27; i++)
            {
                if(pecas[i].status=='1')
                {
                    sum++;
                }
                if(pecas[i].status=='2')
                {
                    sum2++;
                }
            }
            if(sum<sum2)
            {
                fn=1;
                t1 = 3;
                partidaOver();
                countPontos();
            }
            if(sum2<sum)
            {
                fn=2;
                t1 = 3;
                partidaOver();
                countPontos();
            }
            if(sum==sum2)
            {
                sum=0;
                sum2=0;

                for(i=0; i<27; i++)
                {
                    if(pecas[i].status=='1')
                    {
                        sum = sum + pecas[i].Lado1;
                        sum = sum + pecas[i].Lado2;
                    }
                    if(pecas[i].status=='2')
                    {
                        sum2 = sum2 + pecas[i].Lado1;
                        sum2 = sum2 + pecas[i].Lado2;
                    }
                }
                if(sum<sum2)
                {
                    fn=1;
                    t1 = 3;
                    partidaOver();
                    countPontos();
                }
                if(sum2<sum)
                {
                    fn=2;
                    t1 = 3;
                    partidaOver();
                    countPontos();
                }
                if(sum==sum2)
                {
                    fn=4;
                    t1 = 3;
                    partidaOver();
                    countPontos();
                }

            }
        }

        sum=0;
        sum2=0;
        
        //caso o jogo empate, devemos somar as peças e verificar por pontuação quem foi o vencedor
        
        for(i=0; i<28; i++)
        {
            if (pecas[i].status =='1')
            {
                sum++;
            }
            if(pecas[i].status == '2')
            {
                sum2++;
            }
        }

        if(sum==0 && buy==27)
        {
            fn=1;
            t1 = 3;
        }
        if(sum2==0 && buy==27)
        {
            fn=2;
            t1 = 3;
        }
    }
    while (t1 != 3 );

    if(fn==1)
    {
       J1Venceu();
    }
    if(fn==2)
    {
    	J2Venceu();
    }
    if(fn==3)
    {
        breakGame();
    }
    if(fn==4)
    {
        drawGame();
    }
}


//nesta função é realizado o salvamento do jogo, para isso são criados,respectivamente, as partições de salvamento
//para garantir o funcionamento do programa, buscamos testar também as diversas ocorrências possíveis
int salvarJogo()
{
    
	int i;
	
    
	FILE *fp;
	if( (fp= fopen("ARQPecas", "w")) == NULL)      
	{
		ErrabrP();
		Gravacao();
		return 1;   
	}

	
		for(i = 0; i < 28; i++)
		{
			if(fwrite(&pecas[i], sizeof(struct statusPecas), 1, fp)  != 1)
			{
				ErrgravP();
				Gravacao();
				break;
			}
		}
	
	fclose(fp);
	
	
	if( (fp= fopen("ARQMesa", "w")) == NULL)      
	{
		ErrabrQ();
		Gravacao();
		return 1;   
	}
	
	for(i = 0; i < mp; i++)
		{
			if(fwrite(&mesa[i], sizeof(struct statusMesa), 1, fp)  != 1)
			{
				ErrgravQ();
				break;
			}
		}
	
	fclose(fp);
	
	
	if( (fp= fopen("ARQJog", "w")) == NULL)      
	{
		ErrabrJ();
		Gravacao();
		return 1;   
	}
	
	if(fwrite(&jogador, sizeof(jogador), 1, fp)  != 1)
	{
		ErrgravJ();
		Gravacao();
        return 1;
	}
		
	fclose(fp);
	
	
	if( (fp= fopen("ARQmesaP", "w")) == NULL)      
	{
		ErrabrMP();
		Gravacao();
		return 1;   
	}

	if(fwrite(&mp, sizeof(mp), 1, fp)  != 1)
	{
		ErrgravMP();
		Gravacao();
        return 1;
	}
		
	fclose(fp);
	
	
	if( (fp= fopen("ARQTmesa", "w")) == NULL)      
	{
		ErrabrTM();
		Gravacao();
		return 1;   
	}

	if(fwrite(&tm, sizeof(tm), 1, fp)  != 1)
	{
		ErrgravTM();
		Gravacao();
        return 1;
	}
	
	fclose(fp);
	
	
	if( (fp= fopen("ARQTcompr", "w")) == NULL)     
	{
		Errabrcompr();
		Gravacao();
		return 1;   
	}

	if(fwrite(&buy, sizeof(buy), 1, fp)  != 1)
	{
		Errgravcompr();
		Gravacao();
        return 1;
	}
	fclose(fp);
	
	
	if( (fp= fopen("ARQempate", "w")) == NULL)     
	{
		Errabrempt();
		Gravacao();
		return 1;   
	}

	if(fwrite(&draw, sizeof(draw), 1, fp)  != 1)
	{
		Errgravempt();
		Gravacao();
        return 1;
	}
	fclose(fp);
	
	if ((fp = fopen("ARQbora", "w")) == NULL)
    {
        erro1ARQempate();
        return 1;
    }

    if (fwrite(&bora, sizeof(bora), 1, fp) != 1)
    {
        erro2ARQempate();
        return 1;
    }
    fclose(fp);

    return 0;
}


void jogcomputador()
{
int i, k, u, x, loc, sum, sum2, fn, N, side, t1;
    int esc, bill;
    char test;
    int extD, extE;

    aux.status = ' ';
    aux.Lado1 = 0;
    aux.Lado2 = 1;
    buy = 13;
    mp = 1;
    side = 0;
    draw = 0;
    tm = 5;
    for (i = 0; i < 28; i++)
    {
        pecas[i].status = ' ';
    }

    embaralharpecas();

    // loop para determinar pecas do jogador 1
    for (i = 0; i <= 6; i++)
    {
        pecas[i].status = '1';
    }
    // loop para determinar pecas do jogador 2
    for (i = 7; i <= 13; i++)
    {
        pecas[i].status = '2';
    }

    // loop para descobrir qual jogador ira comecar o jogo
    for (i = 0; i <= 13; i++)
    {
        if (pecas[i].Lado1 == pecas[i].Lado2)
        {
            if (aux.Lado1 <= pecas[i].Lado1)
            {
                aux = pecas[i];
                u = i;
            }
            else
            {

                if (aux.Lado1 + aux.Lado2 <= pecas[i].Lado1 + pecas[i].Lado2)
                {
                    if (aux.Lado1 || aux.Lado2 > pecas[i].Lado1 || pecas[i].Lado2)
                    {
                        aux = pecas[i];
                        u = i;
                    }
                }
            }
        }
    }
    tm = tm + 7;
    if (pecas[u].status == '1')
    {
        pecasJ1();
    }
    else
    {
        pecasJ2();
    }
    NewLine();
    mesa[0].Lado1 = aux.Lado1;
    mesa[0].Lado2 = aux.Lado2;
    extE = mesa[0].Lado1;
    extD = mesa[0].Lado2;

    if (pecas[u].status == '1')
    {
        jogador = '2';
    }
    else
    {
        jogador = '1';
    }
    pecas[u].status = 'm';

    do
    {
        if (jogador == '1')
        {
            i = 0;

            do
            {
                layoutMesa();
                i++;
            } while (tm - 1 != i);

            i = 0;
            NewLine();
            Mesa();
            do
            {

                DominoJG(mesa, i);
                i++;
            } while (i < mp);
            NewLine();

            i = 0;
            do
            {
                layoutMesa();
                i++;
            } while (tm - 1 != i);

            i = 0;
            NewLine();
            NewLine();

            AltVez(pecas, jogador);

            // menu jogador
            t1 = MenuJG(t1, extE, extD);

            sum = 0;
            switch (t1)
            {
            case 1:

                loc = OpcPeca(loc);

                if (loc == 0)
                {
                    break;
                }
                else
                    for (i = 0; i <= 27; i++)
                    {
                        if (pecas[i].status == jogador)
                        {
                            sum++;
                        }
                        if (sum == loc)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                
                                draw = 0;
                                if ((((pecas[i].Lado1 == extE || pecas[i].Lado1 == extD) && (pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)) && pecas[i].Lado1 != pecas[i].Lado2) || extE == extD)
                                {

                                    side = EDLado(side);

                                    if (side == 1)
                                    {
                                        if (pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                        {

                                            for (N = mp; N >= 0; N--)
                                            {
                                                mesa[N].Lado1 = mesa[N - 1].Lado1;
                                                mesa[N].Lado2 = mesa[N - 1].Lado2;
                                            }
                                            if (pecas[i].Lado1 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado2;
                                                mesa[0].Lado2 = pecas[i].Lado1;
                                                mp++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (jogador == '1')
                                                {
                                                    jogador = '2';
                                                }
                                                else
                                                {
                                                    jogador = '1';
                                                }
                                                tm = tm + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado1;
                                                mesa[0].Lado2 = pecas[i].Lado2;
                                                mp++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (jogador == '1')
                                                {
                                                    jogador = '2';
                                                }
                                                else
                                                {
                                                    jogador = '1';
                                                }
                                                tm = tm + 6;
                                                break;
                                            }
                                            else
                                            {
                                                MsgErro();
                                            }
                                        }
                                    }
                                    if (side == 2)
                                    {

                                        if (pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                        {
                                            if (pecas[i].Lado1 == extD)
                                            {
                                                mesa[mp].Lado1 = pecas[i].Lado1;
                                                mesa[mp].Lado2 = pecas[i].Lado2;
                                                extD = mesa[mp].Lado2;
                                                mp++;
                                                pecas[i].status = 'm';
                                                if (jogador == '1')
                                                {
                                                    jogador = '2';
                                                }
                                                else
                                                {
                                                    jogador = '1';
                                                }
                                                tm = tm + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extD)
                                            {
                                                mesa[mp].Lado1 = pecas[i].Lado2;
                                                mesa[mp].Lado2 = pecas[i].Lado1;
                                                extD = mesa[mp].Lado2;
                                                mp++;
                                                pecas[i].status = 'm';
                                                if (jogador == '1')
                                                {
                                                    jogador = '2';
                                                }
                                                else
                                                {
                                                    jogador = '1';
                                                }
                                                tm = tm + 6;
                                                break;
                                            }
                                            else
                                                MsgErro();
                                        }
                                    }
                                    if (side == 3)
                                    {

                                        opcErro();
                                    }
                                }
                                else
                                {
                                    if (pecas[i].Lado1 == extE)
                                    {
                                        for (N = mp; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado2;
                                        mesa[0].Lado2 = pecas[i].Lado1;
                                        mp++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (jogador == '1')
                                        {
                                            jogador = '2';
                                        }
                                        else
                                        {
                                            jogador = '1';
                                        }
                                        tm = tm + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extE)
                                    {
                                        for (N = mp; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado1;
                                        mesa[0].Lado2 = pecas[i].Lado2;
                                        mp++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (jogador == '1')
                                        {
                                            jogador = '2';
                                        }
                                        else
                                        {
                                            jogador = '1';
                                        }
                                        tm = tm + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado1 == extD)
                                    {
                                        mesa[mp].Lado1 = pecas[i].Lado1;
                                        mesa[mp].Lado2 = pecas[i].Lado2;
                                        extD = mesa[mp].Lado2;
                                        mp++;
                                        pecas[i].status = 'm';
                                        if (jogador == '1')
                                        {
                                            jogador = '2';
                                        }
                                        else
                                        {
                                            jogador = '1';
                                        }
                                        tm = tm + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extD)
                                    {
                                        mesa[mp].Lado1 = pecas[i].Lado2;
                                        mesa[mp].Lado2 = pecas[i].Lado1;
                                        extD = mesa[mp].Lado2;
                                        mp++;
                                        pecas[i].status = 'm';
                                        if (jogador == '1')
                                        {
                                            jogador = '2';
                                        }
                                        else
                                        {
                                            jogador = '1';
                                        }
                                        tm = tm + 6;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                nmrErro();
                        		NewLine();
                                break;
                            }
                        }
                    }
                if (sum < loc)
                {
                opcInval();	
                 NewLine();
                }

                break;

            case 2:

                if (buy == 27)
                {

                    impBuy();
                }
                else
                {

                    buy++;
                    pecas[buy].status = jogador;
                }

                break;
            case 4:

                sum = 0;
                if (buy == 27)
                {
                    for (i = 0; i < 27; i++)
                    {

                        if (pecas[i].status == jogador)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 0)
                    {
                        nextJ();
                        draw++;
                        if (jogador == '1')
                        {
                            jogador = '2';
                        }
                        else
                        {
                            jogador = '1';
                        }
                    }
                    else
                    {
                        Nturno();
                    }
                }
                else
                {
                    NewLine();
                	Nturno();
                }
                break;

            case 3:

                fn = 3;
                t1 = 3;
                break;

            default:

                opcInval();
                break;
            }
            NewLine();

            sum = 0;
            sum2 = 0;

            if (draw == 2)
            {
                for (i = 0; i < 27; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        sum++;
                    }
                    if (pecas[i].status == '2')
                    {
                        sum2++;
                    }
                }
                if (sum < sum2)
                {
                    fn = 1;
                    t1 = 3;
                    partidaOver();
               		countPontos();
                }
                if (sum2 < sum)
                {
                    fn = 2;
                    t1 = 3;
                    partidaOver();
                	countPontos();
                }
                if (sum == sum2)
                {
                    sum = 0;
                    sum2 = 0;

                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            sum = sum + pecas[i].Lado1;
                            sum = sum + pecas[i].Lado2;
                        }
                        if (pecas[i].status == '2')
                        {
                            sum2 = sum2 + pecas[i].Lado1;
                            sum2 = sum2 + pecas[i].Lado2;
                        }
                    }
                    if (sum < sum2)
                    {
                        fn = 1;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                    if (sum2 < sum)
                    {
                        fn = 2;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                    if (sum == sum2)
                    {
                        fn = 4;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                }
            }

            sum = 0;
            sum2 = 0;

            // loop para descborir quem ganhara o jogo em caso de empate
            for (i = 0; i < 28; i++)
            {
                if (pecas[i].status == '1')
                {
                    sum++;
                }
                if (pecas[i].status == '2')
                {
                    sum2++;
                }
            }

            if (sum == 0 && buy == 27)
            {
                fn = 1;
                t1 = 3;
            }
            if (sum2 == 0 && buy == 27)
            {
                fn = 2;
                t1 = 3;
            }
        }

        if (jogador == '2' && t1 != 3)
        {

            do
            {
                bill = 0;
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '2')
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            bill = 1;
                            draw = 0;
                            pecajogadabot();
                            if (pecas[i].Lado1 == extE)
                            {
                                for (N = mp; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado2;
                                mesa[0].Lado2 = pecas[i].Lado1;
                                mp++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (jogador == '1')
                                {
                                    jogador = '2';
                                }
                                else
                                {
                                    jogador = '1';
                                }
                                tm = tm + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extE)
                            {
                                for (N = mp; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado1;
                                mesa[0].Lado2 = pecas[i].Lado2;
                                mp++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (jogador == '1')
                                {
                                    jogador = '2';
                                }
                                else
                                {
                                    jogador = '1';
                                }
                                tm = tm + 6;
                                break;
                            }
                            else if (pecas[i].Lado1 == extD)
                            {
                                mesa[mp].Lado1 = pecas[i].Lado1;
                                mesa[mp].Lado2 = pecas[i].Lado2;
                                extD = mesa[mp].Lado2;
                                mp++;
                                pecas[i].status = 'm';
                                if (jogador == '1')
                                {
                                    jogador = '2';
                                }
                                else
                                {
                                    jogador = '1';
                                }
                                tm = tm + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extD)
                            {
                                mesa[mp].Lado1 = pecas[i].Lado2;
                                mesa[mp].Lado2 = pecas[i].Lado1;
                                extD = mesa[mp].Lado2;
                                mp++;
                                pecas[i].status = 'm';
                                if (jogador == '1')
                                {
                                    jogador = '2';
                                }
                                else
                                {
                                    jogador = '1';
                                }
                                tm = tm + 6;
                                break;
                            }
                        }
                    }
                }
                if (bill == 0)
                {
                    if (buy == 27)
                    {
                        bill = 0;
                    }
                    else
                    {
                        buy++;
                        bill = 1;
                        pecacompradabot();
                        pecas[buy].status = jogador;
                    }
                }
                if (bill == 0)
                {
                    jogador = '1';
                    draw++;
                    vezpassadabot();
                }

                sum = 0;
                sum2 = 0;

                if (draw == 2)
                {
                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            sum++;
                        }
                        if (pecas[i].status == '2')
                        {
                            sum2++;
                        }
                    }
                    if (sum < sum2)
                    {
                        fn = 1;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                    if (sum2 < sum)
                    {
                        fn = 2;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                    if (sum == sum2)
                    {
                        sum = 0;
                        sum2 = 0;

                        for (i = 0; i < 27; i++)
                        {
                            if (pecas[i].status == '1')
                            {
                                sum = sum + pecas[i].Lado1;
                                sum = sum + pecas[i].Lado2;
                            }
                            if (pecas[i].status == '2')
                            {
                                sum2 = sum2 + pecas[i].Lado1;
                                sum2 = sum2 + pecas[i].Lado2;
                            }
                        }
                        if (sum < sum2)
                        {
                            fn = 1;
                            t1 = 3;
                            partidaOver();
                			countPontos();
                        }
                        if (sum2 < sum)
                        {
                            fn = 2;
                            t1 = 3;
	                        partidaOver();
                			countPontos();
                        }
                        if (sum == sum2)
                        {
                            fn = 4;
                            t1 = 3;
                            partidaOver();
                			countPontos();
                        }
                    }
                }

                sum = 0;
                sum2 = 0;

                // loop para descborir quem ganhara o jogo em caso de empate
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        sum++;
                    }
                    if (pecas[i].status == '2')
                    {
                        sum2++;
                    }
                }

                if (sum == 0 && buy == 27)
                {
                    fn = 1;
                    t1 = 3;
                }
                if (sum2 == 0 && buy == 27)
                {
                    fn = 2;
                    t1 = 3;
                }

            } while (jogador != '1');
        }

    } while (t1 != 3);

     if(fn==1)
    {
       J1Venceu();
    }
    if(fn==2)
    {
    	J2Venceu();
    }
    if(fn==3)
    {
        breakGame();
    }
    if(fn==4)
    {
        drawGame();
    }
}

//declaramos tal função para que, após o jogo ser salvo, ele possa ser restaurado pelo programa durante a execução do jogo
//para garantir o funcionamento do programa, buscamos testar também as diversas ocorrências possíveis
int recuperarJogo()
{
	int i;
	
	FILE *fp;
	
	if( (fp= fopen("ARQmesaP", "r")) == NULL)      
	{
		ErrabrMP();
		Leitura();
		return 1;   
	}
	
	if(fread(&mp, sizeof(mp), 1, fp)  != 1)
		{
			ErrgravMP();
			Leitura();
			return 1;
		}
	fclose(fp);
	
	if( (fp= fopen("ARQPecas", "r")) == NULL)      
			{
				ErrabrP();
				Leitura();
				return 1;   
			}
			
	for(i = 0; i < 28; i++)
	{
		if(fread(&pecas[i], sizeof(struct statusPecas), 1, fp)  != 1)
		{
			ErrgravP();
			Leitura();
			return 1 ;
		}
	}
	fclose(fp);
	
	
	
	if( (fp= fopen("ARQMesa", "r")) == NULL)      
			{
				ErrabrQ();
				Leitura();
				return 1;   
			}
			
	for(i = 0; i < mp; i++)
	{
		if(fread(&mesa[i], sizeof(struct statusMesa), 1, fp)  != 1)
		{
			ErrgravQ();
			Leitura();
			break;
		}
	}
	fclose(fp);
	
	
	if( (fp= fopen("ARQJog", "r")) == NULL)      
	{
		ErrabrJ();
		Leitura();
		return 1;   
	}
	if(fread(&jogador, sizeof(jogador), 1, fp)  != 1)
		{
			ErrabrJ();
			Leitura();
			return 1;
		}
	fclose(fp);
	
	
	
	if( (fp= fopen("ARQTmesa", "r")) == NULL)      
	{
		ErrabrTM();
		Leitura();
		return 1;   
	}
	if(fread(&tm, sizeof(tm), 1, fp)  != 1)
		{
			ErrgravTM();
			Leitura();
			return 1;
		}
	fclose(fp);
	
	if( (fp= fopen("ARQTcompr", "r")) == NULL)      
	{
		Errabrcompr();
		Leitura();
		return 1;   
	}
	if(fread(&buy, sizeof(buy), 1, fp)  != 1)
		{
			Errgravcompr();
			Leitura();
			return 1;
		}
	fclose(fp);
	
	if( (fp= fopen("ARQempate", "r")) == NULL)      
	{
		Errabrempt();
		Leitura();
		return 1;   
	}
	if(fread(&draw, sizeof(draw), 1, fp)  != 1)
		{
			Errgravempt();
			Leitura();
			return 1;
		}
	fclose(fp);
	
	if ((fp = fopen("ARQbora", "r")) == NULL)
    {
        erro1recARQempate();
        return 1;
    }
    if (fread(&bora, sizeof(bora), 1, fp) != 1)
    {
        erro2recARQempate();
        return 1;
    }
    fclose(fp);

	
	
	
	return 0;
}

void continuarjogoBOT(){
	int i, k, u, x, loc, sum, sum2, fn, N, side, t1;
    int esc, bill;
    char test;
    int extD, extE;


	extE = mesa[0].Lado1;
    extD = mesa[mp].Lado2;
	do
    {
        if (jogador == '1')
        {
            i = 0;

            do
            {
                layoutMesa();
                i++;
            } while (tm - 1 != i);

            i = 0;
            NewLine();
            Mesa();
            do
            {

                DominoJG(mesa, i);
                i++;
            } while (i < mp);
            NewLine();

            i = 0;
            do
            {
                layoutMesa();
                i++;
            } while (tm - 1 != i);

            i = 0;
            NewLine();
            NewLine();

            AltVez(pecas, jogador);

            // menu jogador
            t1 = MenuJG(t1, extE, extD);

            sum = 0;
            switch (t1)
            {
            case 1:

                loc = OpcPeca(loc);

                if (loc == 0)
                {
                    break;
                }
                else
                    for (i = 0; i <= 27; i++)
                    {
                        if (pecas[i].status == jogador)
                        {
                            sum++;
                        }
                        if (sum == loc)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                
                                draw = 0;
                                if ((((pecas[i].Lado1 == extE || pecas[i].Lado1 == extD) && (pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)) && pecas[i].Lado1 != pecas[i].Lado2) || extE == extD)
                                {

                                    side = EDLado(side);

                                    if (side == 1)
                                    {
                                        if (pecas[i].Lado1 == extE || pecas[i].Lado2 == extE)
                                        {

                                            for (N = mp; N >= 0; N--)
                                            {
                                                mesa[N].Lado1 = mesa[N - 1].Lado1;
                                                mesa[N].Lado2 = mesa[N - 1].Lado2;
                                            }
                                            if (pecas[i].Lado1 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado2;
                                                mesa[0].Lado2 = pecas[i].Lado1;
                                                mp++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (jogador == '1')
                                                {
                                                    jogador = '2';
                                                }
                                                else
                                                {
                                                    jogador = '1';
                                                }
                                                tm = tm + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extE)
                                            {
                                                mesa[0].Lado1 = pecas[i].Lado1;
                                                mesa[0].Lado2 = pecas[i].Lado2;
                                                mp++;
                                                extE = mesa[0].Lado1;
                                                pecas[i].status = 'm';
                                                if (jogador == '1')
                                                {
                                                    jogador = '2';
                                                }
                                                else
                                                {
                                                    jogador = '1';
                                                }
                                                tm = tm + 6;
                                                break;
                                            }
                                            else
                                            {
                                                MsgErro();
                                            }
                                        }
                                    }
                                    if (side == 2)
                                    {

                                        if (pecas[i].Lado1 == extD || pecas[i].Lado2 == extD)
                                        {
                                            if (pecas[i].Lado1 == extD)
                                            {
                                                mesa[mp].Lado1 = pecas[i].Lado1;
                                                mesa[mp].Lado2 = pecas[i].Lado2;
                                                extD = mesa[mp].Lado2;
                                                mp++;
                                                pecas[i].status = 'm';
                                                if (jogador == '1')
                                                {
                                                    jogador = '2';
                                                }
                                                else
                                                {
                                                    jogador = '1';
                                                }
                                                tm = tm + 6;
                                                break;
                                            }
                                            else if (pecas[i].Lado2 == extD)
                                            {
                                                mesa[mp].Lado1 = pecas[i].Lado2;
                                                mesa[mp].Lado2 = pecas[i].Lado1;
                                                extD = mesa[mp].Lado2;
                                                mp++;
                                                pecas[i].status = 'm';
                                                if (jogador == '1')
                                                {
                                                    jogador = '2';
                                                }
                                                else
                                                {
                                                    jogador = '1';
                                                }
                                                tm = tm + 6;
                                                break;
                                            }
                                            else
                                                MsgErro();
                                        }
                                    }
                                    if (side == 3)
                                    {

                                        opcErro();
                                    }
                                }
                                else
                                {
                                    if (pecas[i].Lado1 == extE)
                                    {
                                        for (N = mp; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado2;
                                        mesa[0].Lado2 = pecas[i].Lado1;
                                        mp++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (jogador == '1')
                                        {
                                            jogador = '2';
                                        }
                                        else
                                        {
                                            jogador = '1';
                                        }
                                        tm = tm + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extE)
                                    {
                                        for (N = mp; N >= 0; N--)
                                        {
                                            mesa[N].Lado1 = mesa[N - 1].Lado1;
                                            mesa[N].Lado2 = mesa[N - 1].Lado2;
                                        }
                                        mesa[0].Lado1 = pecas[i].Lado1;
                                        mesa[0].Lado2 = pecas[i].Lado2;
                                        mp++;
                                        extE = mesa[0].Lado1;
                                        pecas[i].status = 'm';
                                        if (jogador == '1')
                                        {
                                            jogador = '2';
                                        }
                                        else
                                        {
                                            jogador = '1';
                                        }
                                        tm = tm + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado1 == extD)
                                    {
                                        mesa[mp].Lado1 = pecas[i].Lado1;
                                        mesa[mp].Lado2 = pecas[i].Lado2;
                                        extD = mesa[mp].Lado2;
                                        mp++;
                                        pecas[i].status = 'm';
                                        if (jogador == '1')
                                        {
                                            jogador = '2';
                                        }
                                        else
                                        {
                                            jogador = '1';
                                        }
                                        tm = tm + 6;
                                        break;
                                    }
                                    else if (pecas[i].Lado2 == extD)
                                    {
                                        mesa[mp].Lado1 = pecas[i].Lado2;
                                        mesa[mp].Lado2 = pecas[i].Lado1;
                                        extD = mesa[mp].Lado2;
                                        mp++;
                                        pecas[i].status = 'm';
                                        if (jogador == '1')
                                        {
                                            jogador = '2';
                                        }
                                        else
                                        {
                                            jogador = '1';
                                        }
                                        tm = tm + 6;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                nmrErro();
                        		NewLine();
                                break;
                            }
                        }
                    }
                if (sum < loc)
                {
                opcInval();	
                 NewLine();
                }

                break;

            case 2:

                if (buy == 27)
                {

                    impBuy();
                }
                else
                {

                    buy++;
                    pecas[buy].status = jogador;
                }

                break;
            case 4:

                sum = 0;
                if (buy == 27)
                {
                    for (i = 0; i < 27; i++)
                    {

                        if (pecas[i].status == jogador)
                        {
                            if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum == 0)
                    {
                        nextJ();
                        draw++;
                        if (jogador == '1')
                        {
                            jogador = '2';
                        }
                        else
                        {
                            jogador = '1';
                        }
                    }
                    else
                    {
                        Nturno();
                    }
                }
                else
                {
                    NewLine();
                	Nturno();
                }
                break;

            case 3:

                fn = 3;
                t1 = 3;
                break;

            default:

                opcInval();
                break;
            }
            NewLine();

            sum = 0;
            sum2 = 0;

            if (draw == 2)
            {
                for (i = 0; i < 27; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        sum++;
                    }
                    if (pecas[i].status == '2')
                    {
                        sum2++;
                    }
                }
                if (sum < sum2)
                {
                    fn = 1;
                    t1 = 3;
                    partidaOver();
               		countPontos();
                }
                if (sum2 < sum)
                {
                    fn = 2;
                    t1 = 3;
                    partidaOver();
                	countPontos();
                }
                if (sum == sum2)
                {
                    sum = 0;
                    sum2 = 0;

                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            sum = sum + pecas[i].Lado1;
                            sum = sum + pecas[i].Lado2;
                        }
                        if (pecas[i].status == '2')
                        {
                            sum2 = sum2 + pecas[i].Lado1;
                            sum2 = sum2 + pecas[i].Lado2;
                        }
                    }
                    if (sum < sum2)
                    {
                        fn = 1;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                    if (sum2 < sum)
                    {
                        fn = 2;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                    if (sum == sum2)
                    {
                        fn = 4;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                }
            }

            sum = 0;
            sum2 = 0;

            // loop para descborir quem ganhara o jogo em caso de empate
            for (i = 0; i < 28; i++)
            {
                if (pecas[i].status == '1')
                {
                    sum++;
                }
                if (pecas[i].status == '2')
                {
                    sum2++;
                }
            }

            if (sum == 0 && buy == 27)
            {
                fn = 1;
                t1 = 3;
            }
            if (sum2 == 0 && buy == 27)
            {
                fn = 2;
                t1 = 3;
            }
        }

        if (jogador == '2' && t1 != 3)
        {

            do
            {
                bill = 0;
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '2')
                    {
                        if (pecas[i].Lado1 == extE || pecas[i].Lado1 == extD || pecas[i].Lado2 == extE || pecas[i].Lado2 == extD)
                        {
                            bill = 1;
                            draw = 0;
                            pecajogadabot();
                            if (pecas[i].Lado1 == extE)
                            {
                                for (N = mp; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado2;
                                mesa[0].Lado2 = pecas[i].Lado1;
                                mp++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (jogador == '1')
                                {
                                    jogador = '2';
                                }
                                else
                                {
                                    jogador = '1';
                                }
                                tm = tm + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extE)
                            {
                                for (N = mp; N >= 0; N--)
                                {
                                    mesa[N].Lado1 = mesa[N - 1].Lado1;
                                    mesa[N].Lado2 = mesa[N - 1].Lado2;
                                }
                                mesa[0].Lado1 = pecas[i].Lado1;
                                mesa[0].Lado2 = pecas[i].Lado2;
                                mp++;
                                extE = mesa[0].Lado1;
                                pecas[i].status = 'm';
                                if (jogador == '1')
                                {
                                    jogador = '2';
                                }
                                else
                                {
                                    jogador = '1';
                                }
                                tm = tm + 6;
                                break;
                            }
                            else if (pecas[i].Lado1 == extD)
                            {
                                mesa[mp].Lado1 = pecas[i].Lado1;
                                mesa[mp].Lado2 = pecas[i].Lado2;
                                extD = mesa[mp].Lado2;
                                mp++;
                                pecas[i].status = 'm';
                                if (jogador == '1')
                                {
                                    jogador = '2';
                                }
                                else
                                {
                                    jogador = '1';
                                }
                                tm = tm + 6;
                                break;
                            }
                            else if (pecas[i].Lado2 == extD)
                            {
                                mesa[mp].Lado1 = pecas[i].Lado2;
                                mesa[mp].Lado2 = pecas[i].Lado1;
                                extD = mesa[mp].Lado2;
                                mp++;
                                pecas[i].status = 'm';
                                if (jogador == '1')
                                {
                                    jogador = '2';
                                }
                                else
                                {
                                    jogador = '1';
                                }
                                tm = tm + 6;
                                break;
                            }
                        }
                    }
                }
                if (bill == 0)
                {
                    if (buy == 27)
                    {
                        bill = 0;
                    }
                    else
                    {
                        buy++;
                        bill = 1;
                        pecacompradabot();
                        pecas[buy].status = jogador;
                    }
                }
                if (bill == 0)
                {
                    jogador = '1';
                    draw++;
                    vezpassadabot();
                }

                sum = 0;
                sum2 = 0;

                if (draw == 2)
                {
                    for (i = 0; i < 27; i++)
                    {
                        if (pecas[i].status == '1')
                        {
                            sum++;
                        }
                        if (pecas[i].status == '2')
                        {
                            sum2++;
                        }
                    }
                    if (sum < sum2)
                    {
                        fn = 1;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                    if (sum2 < sum)
                    {
                        fn = 2;
                        t1 = 3;
                        partidaOver();
                		countPontos();
                    }
                    if (sum == sum2)
                    {
                        sum = 0;
                        sum2 = 0;

                        for (i = 0; i < 27; i++)
                        {
                            if (pecas[i].status == '1')
                            {
                                sum = sum + pecas[i].Lado1;
                                sum = sum + pecas[i].Lado2;
                            }
                            if (pecas[i].status == '2')
                            {
                                sum2 = sum2 + pecas[i].Lado1;
                                sum2 = sum2 + pecas[i].Lado2;
                            }
                        }
                        if (sum < sum2)
                        {
                            fn = 1;
                            t1 = 3;
                            partidaOver();
                			countPontos();
                        }
                        if (sum2 < sum)
                        {
                            fn = 2;
                            t1 = 3;
	                        partidaOver();
                			countPontos();
                        }
                        if (sum == sum2)
                        {
                            fn = 4;
                            t1 = 3;
                            partidaOver();
                			countPontos();
                        }
                    }
                }

                sum = 0;
                sum2 = 0;

                // loop para descborir quem ganhara o jogo em caso de empate
                for (i = 0; i < 28; i++)
                {
                    if (pecas[i].status == '1')
                    {
                        sum++;
                    }
                    if (pecas[i].status == '2')
                    {
                        sum2++;
                    }
                }

                if (sum == 0 && buy == 27)
                {
                    fn = 1;
                    t1 = 3;
                }
                if (sum2 == 0 && buy == 27)
                {
                    fn = 2;
                    t1 = 3;
                }

            } while (jogador != '1');
        }

    } while (t1 != 3);

     if(fn==1)
    {
       J1Venceu();
    }
    if(fn==2)
    {
    	J2Venceu();
    }
    if(fn==3)
    {
        breakGame();
    }
    if(fn==4)
    {
        drawGame();
    }
}

