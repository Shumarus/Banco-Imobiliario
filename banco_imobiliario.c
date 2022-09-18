#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//-----Declaração das structs-----

typedef struct {
	float saldo;
	int conjPropriedade[18];
	int conjEmpresas[6];
	char posicao[3];
} Jogador;

typedef struct {
	char cor[20];
	int dono;
	float valorDeCompra;
	float valorDoAluguelPadrao;
	float valorDoAluguelPorCasa;
	float valorConstrucao;
	int nConstrucoes;
} TituloDePropriedade;

typedef struct{
	int id;
	int dono;
	float valorDeCompra;
	float valorGastoLucro;	
} TituloDeEmpresa;

typedef struct{
	char nome[3];
	TituloDePropriedade propriedade;
	TituloDeEmpresa empresa;
} CasaDoTabuleiro;

typedef struct{
	float cartas[36];
} Noticias;

typedef struct{
	CasaDoTabuleiro casas[36];
	Noticias pilha;
} Tabuleiro;
//---------------------------------


//-------------Declaração das funções----------------
void ImprimeTabu ();
int jogarDados (int dados);
//---------------------------------------------------


//---------------Função Principal--------------------
int main(){
	
	int num;
	int n;
	int dados, cartas;
	int i, j;
	int a, b, c, d, e, f, g, h, k;
	int somaprop=0, somaemp=0, somatit=0;
	int aux_prop;
	char nome[50];
	int l=0, m=0, busca=1;
	
//----------Declarando as variáveis das structs------------
	Jogador jogador;
    Tabuleiro tabuleiro;
//---------------------------------------------------------

//-----------Atribuindo valores para as casas do tabuleiro-------------

    tabuleiro.casas[0].nome[0]='I';
    tabuleiro.casas[0].nome[1]='\0';
    tabuleiro.casas[0].empresa.id= 0;
    tabuleiro.casas[0].empresa.dono= 2;          //Quando empresa.dono=0, não possui dono. Quando empresa.dono=1, o jogador é o dono. Quando empresa.dono=2, não é uma empresa.
    tabuleiro.casas[0].empresa.valorDeCompra=0;
    tabuleiro.casas[0].empresa.valorGastoLucro=0;
    tabuleiro.casas[0].propriedade.cor[0]= 'B';
    tabuleiro.casas[0].propriedade.cor[1]= 'r';
    tabuleiro.casas[0].propriedade.cor[2]= 'a';
    tabuleiro.casas[0].propriedade.cor[3]= 'n';
    tabuleiro.casas[0].propriedade.cor[4]= 'c';
    tabuleiro.casas[0].propriedade.cor[5]= 'o';
    tabuleiro.casas[0].propriedade.cor[6]= '\0';
    tabuleiro.casas[0].propriedade.dono= 3;       //Quando propriedade.dono=0, não possui dono. Quando propriedade.dono=1, possui proprietário que não é o jogador. Quando propriedade.dono=2, o jogador é o dono. Quando propriedade.dono=3, não é propriedade.
    tabuleiro.casas[0].propriedade.valorDeCompra= 0;
    tabuleiro.casas[0].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[0].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[0].propriedade.valorConstrucao= 0;
    tabuleiro.casas[0].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[1].nome[0]='P';
    tabuleiro.casas[1].nome[1]='\0';
    tabuleiro.casas[1].empresa.id= 0;
    tabuleiro.casas[1].empresa.dono= 2;
    tabuleiro.casas[1].empresa.valorDeCompra=0;
    tabuleiro.casas[1].empresa.valorGastoLucro=0;
    tabuleiro.casas[1].propriedade.cor[0]= 'V';
    tabuleiro.casas[1].propriedade.cor[1]= 'e';
    tabuleiro.casas[1].propriedade.cor[2]= 'r';
    tabuleiro.casas[1].propriedade.cor[3]= 'd';
    tabuleiro.casas[1].propriedade.cor[4]= 'e';
    tabuleiro.casas[1].propriedade.cor[5]= '\0';
    tabuleiro.casas[1].propriedade.dono= 0;
    tabuleiro.casas[1].propriedade.valorDeCompra= 100;
    tabuleiro.casas[1].propriedade.valorDoAluguelPadrao= 60;
    tabuleiro.casas[1].propriedade.valorDoAluguelPorCasa= 30;
    tabuleiro.casas[1].propriedade.valorConstrucao= 100;
    tabuleiro.casas[1].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[2].nome[0]='N';
    tabuleiro.casas[2].nome[1]='\0';
    tabuleiro.casas[2].empresa.id= 0;
    tabuleiro.casas[2].empresa.dono= 2;
    tabuleiro.casas[2].empresa.valorDeCompra=0;
    tabuleiro.casas[2].empresa.valorGastoLucro=0;
    tabuleiro.casas[2].propriedade.cor[0]= 'L';
    tabuleiro.casas[2].propriedade.cor[1]= 'a';
    tabuleiro.casas[2].propriedade.cor[2]= 'r';
    tabuleiro.casas[2].propriedade.cor[3]= 'a';
    tabuleiro.casas[2].propriedade.cor[4]= 'n';
    tabuleiro.casas[2].propriedade.cor[5]= 'j';
    tabuleiro.casas[2].propriedade.cor[6]= 'a';
    tabuleiro.casas[2].propriedade.cor[7]= ' ';
    tabuleiro.casas[2].propriedade.cor[8]= 'c';
    tabuleiro.casas[2].propriedade.cor[9]= 'l';
    tabuleiro.casas[2].propriedade.cor[10]= 'a';
    tabuleiro.casas[2].propriedade.cor[11]= 'r';
    tabuleiro.casas[2].propriedade.cor[12]= 'o';
    tabuleiro.casas[2].propriedade.cor[13]= '\0';
    tabuleiro.casas[2].propriedade.dono= 3;
    tabuleiro.casas[2].propriedade.valorDeCompra= 0;
    tabuleiro.casas[2].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[2].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[2].propriedade.valorConstrucao= 0;
    tabuleiro.casas[2].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[3].nome[0]='E';
    tabuleiro.casas[3].nome[1]='\0';
    tabuleiro.casas[3].empresa.id= 1;
    tabuleiro.casas[3].empresa.dono= 0;
    tabuleiro.casas[3].empresa.valorDeCompra= 2000;
    tabuleiro.casas[3].empresa.valorGastoLucro= 50;
    tabuleiro.casas[3].propriedade.cor[0]= 'C';
    tabuleiro.casas[3].propriedade.cor[1]= 'i';
    tabuleiro.casas[3].propriedade.cor[2]= 'n';
    tabuleiro.casas[3].propriedade.cor[3]= 'z';
    tabuleiro.casas[3].propriedade.cor[4]= 'a';
    tabuleiro.casas[3].propriedade.cor[5]= '\0';
    tabuleiro.casas[3].propriedade.dono= 3;
    tabuleiro.casas[3].propriedade.valorDeCompra= 0;
    tabuleiro.casas[3].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[3].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[3].propriedade.valorConstrucao= 0;
    tabuleiro.casas[3].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[4].nome[0]='P';
    tabuleiro.casas[4].nome[1]='\0';
    tabuleiro.casas[4].empresa.id= 0;
    tabuleiro.casas[4].empresa.dono= 2; 
    tabuleiro.casas[4].empresa.valorDeCompra=0;
    tabuleiro.casas[4].empresa.valorGastoLucro=0;
    tabuleiro.casas[4].propriedade.cor[0]= 'V';
    tabuleiro.casas[4].propriedade.cor[1]= 'e';
    tabuleiro.casas[4].propriedade.cor[2]= 'r';
    tabuleiro.casas[4].propriedade.cor[3]= 'd';
    tabuleiro.casas[4].propriedade.cor[4]= 'e';
    tabuleiro.casas[4].propriedade.cor[5]= '\0';
    tabuleiro.casas[4].propriedade.dono= 1;
    tabuleiro.casas[4].propriedade.valorDeCompra= 75;
    tabuleiro.casas[4].propriedade.valorDoAluguelPadrao= 20;
    tabuleiro.casas[4].propriedade.valorDoAluguelPorCasa= 10;
    tabuleiro.casas[4].propriedade.valorConstrucao= 50;
    tabuleiro.casas[4].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[5].nome[0]='N';
    tabuleiro.casas[5].nome[1]='\0';
    tabuleiro.casas[5].empresa.id= 0;
    tabuleiro.casas[5].empresa.dono= 2;
    tabuleiro.casas[5].empresa.valorDeCompra=0;
    tabuleiro.casas[5].empresa.valorGastoLucro=0;
    tabuleiro.casas[5].propriedade.cor[0]= 'L';
    tabuleiro.casas[5].propriedade.cor[1]= 'a';
    tabuleiro.casas[5].propriedade.cor[2]= 'r';
    tabuleiro.casas[5].propriedade.cor[3]= 'a';
    tabuleiro.casas[5].propriedade.cor[4]= 'n';
    tabuleiro.casas[5].propriedade.cor[5]= 'j';
    tabuleiro.casas[5].propriedade.cor[6]= 'a';
    tabuleiro.casas[5].propriedade.cor[7]= ' ';
    tabuleiro.casas[5].propriedade.cor[8]= 'c';
    tabuleiro.casas[5].propriedade.cor[9]= 'l';
    tabuleiro.casas[5].propriedade.cor[10]= 'a';
    tabuleiro.casas[5].propriedade.cor[11]= 'r';
    tabuleiro.casas[5].propriedade.cor[12]= 'o';
    tabuleiro.casas[5].propriedade.cor[13]= '\0';
    tabuleiro.casas[5].propriedade.dono= 3;
    tabuleiro.casas[5].propriedade.valorDeCompra= 0;
    tabuleiro.casas[5].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[5].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[5].propriedade.valorConstrucao= 0;
    tabuleiro.casas[5].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[6].nome[0]='P';
    tabuleiro.casas[6].nome[1]='\0';
    tabuleiro.casas[6].empresa.id= 0;
    tabuleiro.casas[6].empresa.dono= 2;
    tabuleiro.casas[6].empresa.valorDeCompra=0;
    tabuleiro.casas[6].empresa.valorGastoLucro=0;
    tabuleiro.casas[6].propriedade.cor[0]= 'V';
    tabuleiro.casas[6].propriedade.cor[1]= 'e';
    tabuleiro.casas[6].propriedade.cor[2]= 'r';
    tabuleiro.casas[6].propriedade.cor[3]= 'm';
    tabuleiro.casas[6].propriedade.cor[4]= 'e';
    tabuleiro.casas[6].propriedade.cor[5]= 'l';
    tabuleiro.casas[6].propriedade.cor[6]= 'h';
    tabuleiro.casas[6].propriedade.cor[7]= 'o';
    tabuleiro.casas[6].propriedade.cor[8]= '\0';
    tabuleiro.casas[6].propriedade.dono= 0;
    tabuleiro.casas[6].propriedade.valorDeCompra= 240;
    tabuleiro.casas[6].propriedade.valorDoAluguelPadrao= 20;
    tabuleiro.casas[6].propriedade.valorDoAluguelPorCasa= 100;
    tabuleiro.casas[6].propriedade.valorConstrucao= 150;
    tabuleiro.casas[6].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[7].nome[0]='E';
    tabuleiro.casas[7].nome[1]='\0';
    tabuleiro.casas[7].empresa.id= 2;
    tabuleiro.casas[7].empresa.dono= 0;
    tabuleiro.casas[7].empresa.valorDeCompra= 2000;
    tabuleiro.casas[7].empresa.valorGastoLucro= 50;
    tabuleiro.casas[7].propriedade.cor[0]= 'C';
    tabuleiro.casas[7].propriedade.cor[1]= 'i';
    tabuleiro.casas[7].propriedade.cor[2]= 'n';
    tabuleiro.casas[7].propriedade.cor[3]= 'z';
    tabuleiro.casas[7].propriedade.cor[4]= 'a';
    tabuleiro.casas[7].propriedade.cor[5]= '\0';
    tabuleiro.casas[7].propriedade.dono= 3;
    tabuleiro.casas[7].propriedade.valorDeCompra= 0;
    tabuleiro.casas[7].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[7].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[7].propriedade.valorConstrucao= 0;
    tabuleiro.casas[7].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[8].nome[0]='P';
    tabuleiro.casas[8].nome[1]='\0';
    tabuleiro.casas[8].empresa.id=0;
    tabuleiro.casas[8].empresa.dono= 2;
    tabuleiro.casas[8].empresa.valorDeCompra=0;
    tabuleiro.casas[8].empresa.valorGastoLucro=0;
    tabuleiro.casas[8].propriedade.cor[0]= 'V';
    tabuleiro.casas[8].propriedade.cor[1]= 'e';
    tabuleiro.casas[8].propriedade.cor[2]= 'r';
    tabuleiro.casas[8].propriedade.cor[3]= 'm';
    tabuleiro.casas[8].propriedade.cor[4]= 'e';
    tabuleiro.casas[8].propriedade.cor[5]= 'l';
    tabuleiro.casas[8].propriedade.cor[6]= 'h';
    tabuleiro.casas[8].propriedade.cor[7]= 'o';
    tabuleiro.casas[8].propriedade.cor[8]= '\0';
    tabuleiro.casas[8].propriedade.dono= 1;
    tabuleiro.casas[8].propriedade.valorDeCompra= 220;
    tabuleiro.casas[8].propriedade.valorDoAluguelPadrao= 180;
    tabuleiro.casas[8].propriedade.valorDoAluguelPorCasa= 90;
    tabuleiro.casas[8].propriedade.valorConstrucao= 150;
    tabuleiro.casas[8].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[9].nome[0]='D';
    tabuleiro.casas[9].nome[1]='V';
    tabuleiro.casas[9].nome[2]='\0';
    tabuleiro.casas[9].empresa.id= 0;
    tabuleiro.casas[9].empresa.dono= 2;
    tabuleiro.casas[9].empresa.valorDeCompra=0;
    tabuleiro.casas[9].empresa.valorGastoLucro=0;
    tabuleiro.casas[9].propriedade.cor[0]= 'B';
    tabuleiro.casas[9].propriedade.cor[1]= 'r';
    tabuleiro.casas[9].propriedade.cor[2]= 'a';
    tabuleiro.casas[9].propriedade.cor[3]= 'n';
    tabuleiro.casas[9].propriedade.cor[4]= 'c';
    tabuleiro.casas[9].propriedade.cor[5]= 'o';
    tabuleiro.casas[9].propriedade.cor[6]= '\0';
    tabuleiro.casas[9].propriedade.dono= 3;
    tabuleiro.casas[9].propriedade.valorDeCompra= 0;
    tabuleiro.casas[9].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[9].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[9].propriedade.valorConstrucao= 0;
    tabuleiro.casas[9].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[10].nome[0]='N';
    tabuleiro.casas[10].nome[1]='\0';
    tabuleiro.casas[10].empresa.id= 0;
    tabuleiro.casas[10].empresa.dono= 2;
    tabuleiro.casas[10].empresa.valorDeCompra=0;
    tabuleiro.casas[10].empresa.valorGastoLucro=0;
    tabuleiro.casas[10].propriedade.cor[0]= 'L';
    tabuleiro.casas[10].propriedade.cor[1]= 'a';
    tabuleiro.casas[10].propriedade.cor[2]= 'r';
    tabuleiro.casas[10].propriedade.cor[3]= 'a';
    tabuleiro.casas[10].propriedade.cor[4]= 'n';
    tabuleiro.casas[10].propriedade.cor[5]= 'j';
    tabuleiro.casas[10].propriedade.cor[6]= 'a';
    tabuleiro.casas[10].propriedade.cor[7]= ' ';
    tabuleiro.casas[10].propriedade.cor[8]= 'c';
    tabuleiro.casas[10].propriedade.cor[9]= 'l';
    tabuleiro.casas[10].propriedade.cor[10]= 'a';
    tabuleiro.casas[10].propriedade.cor[11]= 'r';
    tabuleiro.casas[10].propriedade.cor[12]= 'o';
    tabuleiro.casas[10].propriedade.cor[13]= '\0';
    tabuleiro.casas[10].propriedade.dono= 3;
    tabuleiro.casas[10].propriedade.valorDeCompra= 0;
    tabuleiro.casas[10].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[10].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[10].propriedade.valorConstrucao= 0;
    tabuleiro.casas[10].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[11].nome[0]='P';
    tabuleiro.casas[11].nome[1]='\0';
    tabuleiro.casas[11].empresa.id= 0;
    tabuleiro.casas[11].empresa.dono= 2;
    tabuleiro.casas[11].empresa.valorDeCompra=0;
    tabuleiro.casas[11].empresa.valorGastoLucro=0;
    tabuleiro.casas[11].propriedade.cor[0]= 'A';
    tabuleiro.casas[11].propriedade.cor[1]= 'z';
    tabuleiro.casas[11].propriedade.cor[2]= 'u';
    tabuleiro.casas[11].propriedade.cor[3]= 'l';
    tabuleiro.casas[11].propriedade.cor[4]= '\0';
    tabuleiro.casas[11].propriedade.dono= 1;
    tabuleiro.casas[11].propriedade.valorDeCompra= 180;
    tabuleiro.casas[11].propriedade.valorDoAluguelPadrao= 14;
    tabuleiro.casas[11].propriedade.valorDoAluguelPorCasa= 70;
    tabuleiro.casas[11].propriedade.valorConstrucao= 100;
    tabuleiro.casas[11].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[12].nome[0]='E';
    tabuleiro.casas[12].nome[1]='\0';
	tabuleiro.casas[12].empresa.id= 3;
	tabuleiro.casas[12].empresa.dono= 0;
	tabuleiro.casas[12].empresa.valorDeCompra= 2000;
	tabuleiro.casas[12].empresa.valorGastoLucro= 50;
	tabuleiro.casas[12].propriedade.cor[0]= 'C';
	tabuleiro.casas[12].propriedade.cor[1]= 'i';
	tabuleiro.casas[12].propriedade.cor[2]= 'n';
	tabuleiro.casas[12].propriedade.cor[3]= 'z';
	tabuleiro.casas[12].propriedade.cor[4]= 'a';
	tabuleiro.casas[12].propriedade.cor[5]= '\0';
	tabuleiro.casas[12].propriedade.dono=3;
	tabuleiro.casas[12].propriedade.valorDeCompra= 0;
	tabuleiro.casas[12].propriedade.valorDoAluguelPadrao= 0;
	tabuleiro.casas[12].propriedade.valorDoAluguelPorCasa= 0;
	tabuleiro.casas[12].propriedade.valorConstrucao= 0;
	tabuleiro.casas[12].propriedade.nConstrucoes= 0;

	tabuleiro.casas[13].nome[0]='P';
	tabuleiro.casas[13].nome[1]='\0';
    tabuleiro.casas[13].empresa.id= 0;
    tabuleiro.casas[13].empresa.dono= 2;
    tabuleiro.casas[13].empresa.valorDeCompra=0;
    tabuleiro.casas[13].empresa.valorGastoLucro=0;
    tabuleiro.casas[13].propriedade.cor[0]= 'A';
    tabuleiro.casas[13].propriedade.cor[1]= 'z';
    tabuleiro.casas[13].propriedade.cor[2]= 'u';
    tabuleiro.casas[13].propriedade.cor[3]= 'l';
    tabuleiro.casas[13].propriedade.cor[4]= '\0';
    tabuleiro.casas[13].propriedade.dono= 0;
    tabuleiro.casas[13].propriedade.valorDeCompra= 200;
    tabuleiro.casas[13].propriedade.valorDoAluguelPadrao= 16;
    tabuleiro.casas[13].propriedade.valorDoAluguelPorCasa= 80;
    tabuleiro.casas[13].propriedade.valorConstrucao= 100;
    tabuleiro.casas[13].propriedade.nConstrucoes=0;
    
    tabuleiro.casas[14].nome[0]='C';
    tabuleiro.casas[14].nome[1]='C';
    tabuleiro.casas[14].nome[2]='\0';
    tabuleiro.casas[14].empresa.id= 0;
    tabuleiro.casas[14].empresa.dono= 2;
    tabuleiro.casas[14].empresa.valorDeCompra=0;
    tabuleiro.casas[14].empresa.valorGastoLucro=0;
    tabuleiro.casas[14].propriedade.cor[0]= 'V';
    tabuleiro.casas[14].propriedade.cor[1]= 'e';
    tabuleiro.casas[14].propriedade.cor[2]= 'r';
    tabuleiro.casas[14].propriedade.cor[3]= 'd';
    tabuleiro.casas[14].propriedade.cor[4]= 'e';
    tabuleiro.casas[14].propriedade.cor[5]= ' ';
    tabuleiro.casas[14].propriedade.cor[6]= 'e';
    tabuleiro.casas[14].propriedade.cor[7]= 's';
    tabuleiro.casas[14].propriedade.cor[8]= 'c';
    tabuleiro.casas[14].propriedade.cor[9]= 'u';
    tabuleiro.casas[14].propriedade.cor[10]= 'r';
    tabuleiro.casas[14].propriedade.cor[11]= 'o';
    tabuleiro.casas[14].propriedade.cor[12]= '\0';
    tabuleiro.casas[14].propriedade.dono= 3;
    tabuleiro.casas[14].propriedade.valorDeCompra= 0;
    tabuleiro.casas[14].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[14].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[14].propriedade.valorConstrucao= 0;
    tabuleiro.casas[14].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[15].nome[0]='P';
    tabuleiro.casas[15].nome[1]='\0';
    tabuleiro.casas[15].empresa.id= 0;
    tabuleiro.casas[15].empresa.dono= 2;
    tabuleiro.casas[15].empresa.valorDeCompra=0;
    tabuleiro.casas[15].empresa.valorGastoLucro=0;
    tabuleiro.casas[15].propriedade.cor[0]= 'R';
    tabuleiro.casas[15].propriedade.cor[1]= 'o';
    tabuleiro.casas[15].propriedade.cor[2]= 's';
    tabuleiro.casas[15].propriedade.cor[3]= 'a';
    tabuleiro.casas[15].propriedade.cor[4]= '\0';
    tabuleiro.casas[15].propriedade.dono= 0;
    tabuleiro.casas[15].propriedade.valorDeCompra= 400;
    tabuleiro.casas[15].propriedade.valorDoAluguelPadrao= 350;
    tabuleiro.casas[15].propriedade.valorDoAluguelPorCasa= 175;
    tabuleiro.casas[15].propriedade.valorConstrucao= 200;
    tabuleiro.casas[15].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[16].nome[0]='P';
    tabuleiro.casas[16].nome[1]='\0';
    tabuleiro.casas[16].empresa.id= 0;
    tabuleiro.casas[16].empresa.dono= 2;
    tabuleiro.casas[16].empresa.valorDeCompra=0;
    tabuleiro.casas[16].empresa.valorGastoLucro=0;
    tabuleiro.casas[16].propriedade.cor[0]= 'R';
    tabuleiro.casas[16].propriedade.cor[1]= 'o';
    tabuleiro.casas[16].propriedade.cor[2]= 's';
    tabuleiro.casas[16].propriedade.cor[3]= 'a';
    tabuleiro.casas[16].propriedade.cor[4]= '\0';
    tabuleiro.casas[16].propriedade.dono= 1;
    tabuleiro.casas[16].propriedade.valorDeCompra= 350;
    tabuleiro.casas[16].propriedade.valorDoAluguelPadrao= 100;
    tabuleiro.casas[16].propriedade.valorDoAluguelPorCasa= 200;
    tabuleiro.casas[16].propriedade.valorConstrucao= 200;
    tabuleiro.casas[16].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[17].nome[0]='P';
    tabuleiro.casas[17].nome[1]='\0';
    tabuleiro.casas[17].empresa.id= 0;
    tabuleiro.casas[17].empresa.dono= 2;
    tabuleiro.casas[17].empresa.valorDeCompra=0;
    tabuleiro.casas[17].empresa.valorGastoLucro=0;
    tabuleiro.casas[17].propriedade.cor[0]= 'R';
    tabuleiro.casas[17].propriedade.cor[1]= 'o';
    tabuleiro.casas[17].propriedade.cor[2]= 'x';
    tabuleiro.casas[17].propriedade.cor[3]= 'o';
    tabuleiro.casas[17].propriedade.cor[4]= '\0';
    tabuleiro.casas[17].propriedade.dono= 0;
    tabuleiro.casas[17].propriedade.valorDeCompra= 120;
    tabuleiro.casas[17].propriedade.valorDoAluguelPadrao= 60;
    tabuleiro.casas[17].propriedade.valorDoAluguelPorCasa= 30;
    tabuleiro.casas[17].propriedade.valorConstrucao= 50;
    tabuleiro.casas[17].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[18].nome[0]='F';
    tabuleiro.casas[18].nome[1]='\0';
    tabuleiro.casas[18].empresa.id= 0;
    tabuleiro.casas[18].empresa.dono= 2;
    tabuleiro.casas[18].empresa.valorDeCompra=0;
    tabuleiro.casas[18].empresa.valorGastoLucro=0;
    tabuleiro.casas[18].propriedade.cor[0]= 'B';
    tabuleiro.casas[18].propriedade.cor[1]= 'r';
    tabuleiro.casas[18].propriedade.cor[2]= 'a';
    tabuleiro.casas[18].propriedade.cor[3]= 'n';
    tabuleiro.casas[18].propriedade.cor[4]= 'c';
    tabuleiro.casas[18].propriedade.cor[5]= 'o';
    tabuleiro.casas[18].propriedade.cor[6]= '\0';
    tabuleiro.casas[18].propriedade.dono= 3;
    tabuleiro.casas[18].propriedade.valorDeCompra= 0;
    tabuleiro.casas[18].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[18].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[18].propriedade.valorConstrucao= 0;
    tabuleiro.casas[18].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[19].nome[0]='P';
    tabuleiro.casas[19].nome[1]='\0';
    tabuleiro.casas[19].empresa.id= 0;
    tabuleiro.casas[19].empresa.dono= 2;
    tabuleiro.casas[19].empresa.valorDeCompra=0;
    tabuleiro.casas[19].empresa.valorGastoLucro=0;
    tabuleiro.casas[19].propriedade.cor[0]= 'R';
    tabuleiro.casas[19].propriedade.cor[1]= 'o';
    tabuleiro.casas[19].propriedade.cor[2]= 'x';
    tabuleiro.casas[19].propriedade.cor[3]= 'o';
    tabuleiro.casas[19].propriedade.cor[4]= '\0';
    tabuleiro.casas[19].propriedade.dono= 1;
    tabuleiro.casas[19].propriedade.valorDeCompra= 100;
    tabuleiro.casas[19].propriedade.valorDoAluguelPadrao= 80;
    tabuleiro.casas[19].propriedade.valorDoAluguelPorCasa= 40;
    tabuleiro.casas[19].propriedade.valorConstrucao= 50;
    tabuleiro.casas[19].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[20].nome[0]='E';
    tabuleiro.casas[20].nome[1]='\0';
    tabuleiro.casas[20].empresa.id= 4;
    tabuleiro.casas[20].empresa.dono= 0;
    tabuleiro.casas[20].empresa.valorDeCompra= 2000;
    tabuleiro.casas[20].empresa.valorGastoLucro= 50;
    tabuleiro.casas[20].propriedade.cor[0]= 'C';
	tabuleiro.casas[20].propriedade.cor[1]= 'i';
	tabuleiro.casas[20].propriedade.cor[2]= 'n';
	tabuleiro.casas[20].propriedade.cor[3]= 'z';
	tabuleiro.casas[20].propriedade.cor[4]= 'a';
	tabuleiro.casas[20].propriedade.cor[5]= '\0';
    tabuleiro.casas[20].propriedade.dono= 3;
    tabuleiro.casas[20].propriedade.valorDeCompra= 0;
    tabuleiro.casas[20].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[20].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[20].propriedade.valorConstrucao= 0;
    tabuleiro.casas[20].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[21].nome[0]='C';
    tabuleiro.casas[21].nome[1]='L';
    tabuleiro.casas[21].nome[2]='\0';
    tabuleiro.casas[21].empresa.id= 0;
    tabuleiro.casas[21].empresa.dono= 2;
    tabuleiro.casas[21].empresa.valorDeCompra=0;
    tabuleiro.casas[21].empresa.valorGastoLucro=0;
    tabuleiro.casas[21].propriedade.cor[0]= 'V';
    tabuleiro.casas[21].propriedade.cor[1]= 'e';
    tabuleiro.casas[21].propriedade.cor[2]= 'r';
    tabuleiro.casas[21].propriedade.cor[3]= 'd';
    tabuleiro.casas[21].propriedade.cor[4]= 'e';
    tabuleiro.casas[21].propriedade.cor[5]= ' ';
    tabuleiro.casas[21].propriedade.cor[6]= 'e';
    tabuleiro.casas[21].propriedade.cor[7]= 's';
    tabuleiro.casas[21].propriedade.cor[8]= 'c';
    tabuleiro.casas[21].propriedade.cor[9]= 'u';
    tabuleiro.casas[21].propriedade.cor[10]= 'r';
    tabuleiro.casas[21].propriedade.cor[11]= 'o';
    tabuleiro.casas[21].propriedade.cor[12]= '\0';
    tabuleiro.casas[21].propriedade.dono= 3;
    tabuleiro.casas[21].propriedade.valorDeCompra= 0;
    tabuleiro.casas[21].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[21].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[21].propriedade.valorConstrucao= 0;
    tabuleiro.casas[21].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[22].nome[0]='N';
    tabuleiro.casas[22].nome[1]='\0';
    tabuleiro.casas[22].empresa.id= 0;
    tabuleiro.casas[22].empresa.dono= 2;
    tabuleiro.casas[22].empresa.valorDeCompra=0;
    tabuleiro.casas[22].empresa.valorGastoLucro=0;
    tabuleiro.casas[22].propriedade.cor[0]= 'L';
    tabuleiro.casas[22].propriedade.cor[1]= 'a';
    tabuleiro.casas[22].propriedade.cor[2]= 'r';
    tabuleiro.casas[22].propriedade.cor[3]= 'a';
    tabuleiro.casas[22].propriedade.cor[4]= 'n';
    tabuleiro.casas[22].propriedade.cor[5]= 'j';
    tabuleiro.casas[22].propriedade.cor[6]= 'a';
    tabuleiro.casas[22].propriedade.cor[7]= ' ';
    tabuleiro.casas[22].propriedade.cor[8]= 'c';
    tabuleiro.casas[22].propriedade.cor[9]= 'l';
    tabuleiro.casas[22].propriedade.cor[10]= 'a';
    tabuleiro.casas[22].propriedade.cor[11]= 'r';
    tabuleiro.casas[22].propriedade.cor[12]= 'o';
    tabuleiro.casas[22].propriedade.cor[13]= '\0';
    tabuleiro.casas[22].propriedade.dono= 3;
    tabuleiro.casas[22].propriedade.valorDeCompra= 0;
    tabuleiro.casas[22].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[22].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[22].propriedade.valorConstrucao= 0;
    tabuleiro.casas[22].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[23].nome[0]='P';
    tabuleiro.casas[23].nome[1]='\0';
    tabuleiro.casas[23].empresa.id= 0;
    tabuleiro.casas[23].empresa.dono= 2;
    tabuleiro.casas[23].empresa.valorDeCompra=0;
    tabuleiro.casas[23].empresa.valorGastoLucro=0;
    tabuleiro.casas[23].propriedade.cor[0]= 'R';
    tabuleiro.casas[23].propriedade.cor[1]= 'o';
    tabuleiro.casas[23].propriedade.cor[2]= 's';
    tabuleiro.casas[23].propriedade.cor[3]= 'a';
    tabuleiro.casas[23].propriedade.cor[4]= ' ';
    tabuleiro.casas[23].propriedade.cor[5]= 'c';
    tabuleiro.casas[23].propriedade.cor[6]= 'l';
    tabuleiro.casas[23].propriedade.cor[7]= 'a';
    tabuleiro.casas[23].propriedade.cor[8]= 'r';
    tabuleiro.casas[23].propriedade.cor[9]= 'o';
    tabuleiro.casas[23].propriedade.cor[10]= '\0';
    tabuleiro.casas[23].propriedade.dono= 1;
    tabuleiro.casas[23].propriedade.valorDeCompra= 320;
    tabuleiro.casas[23].propriedade.valorDoAluguelPadrao= 200;
    tabuleiro.casas[23].propriedade.valorDoAluguelPorCasa= 150;
    tabuleiro.casas[23].propriedade.valorConstrucao= 200;
    tabuleiro.casas[23].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[24].nome[0]='P';
    tabuleiro.casas[24].nome[1]='\0';
    tabuleiro.casas[24].empresa.id= 0;
    tabuleiro.casas[24].empresa.dono= 2;
    tabuleiro.casas[24].empresa.valorDeCompra=0;
    tabuleiro.casas[24].empresa.valorGastoLucro=0;
    tabuleiro.casas[24].propriedade.cor[0]= 'R';
    tabuleiro.casas[24].propriedade.cor[1]= 'o';
    tabuleiro.casas[24].propriedade.cor[2]= 's';
    tabuleiro.casas[24].propriedade.cor[3]= 'a';
    tabuleiro.casas[24].propriedade.cor[4]= ' ';
    tabuleiro.casas[24].propriedade.cor[5]= 'c';
    tabuleiro.casas[24].propriedade.cor[6]= 'l';
    tabuleiro.casas[24].propriedade.cor[7]= 'a';
    tabuleiro.casas[24].propriedade.cor[8]= 'r';
    tabuleiro.casas[24].propriedade.cor[9]= 'o';
    tabuleiro.casas[24].propriedade.cor[10]= '\0';
    tabuleiro.casas[24].propriedade.dono= 0;
    tabuleiro.casas[24].propriedade.valorDeCompra= 140;
    tabuleiro.casas[24].propriedade.valorDoAluguelPadrao= 100;
    tabuleiro.casas[24].propriedade.valorDoAluguelPorCasa= 50;
    tabuleiro.casas[24].propriedade.valorConstrucao= 100;
    tabuleiro.casas[24].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[25].nome[0]='P';
    tabuleiro.casas[25].nome[1]='\0';
    tabuleiro.casas[25].empresa.id= 0;
    tabuleiro.casas[25].empresa.dono= 2;
    tabuleiro.casas[25].empresa.valorDeCompra=0;
    tabuleiro.casas[25].empresa.valorGastoLucro=0;
    tabuleiro.casas[25].propriedade.cor[0]= 'R';
    tabuleiro.casas[25].propriedade.cor[1]= 'o';
    tabuleiro.casas[25].propriedade.cor[2]= 's';
    tabuleiro.casas[25].propriedade.cor[3]= 'a';
    tabuleiro.casas[25].propriedade.cor[4]= ' ';
    tabuleiro.casas[25].propriedade.cor[5]= 'c';
    tabuleiro.casas[25].propriedade.cor[6]= 'l';
    tabuleiro.casas[25].propriedade.cor[7]= 'a';
    tabuleiro.casas[25].propriedade.cor[8]= 'r';
    tabuleiro.casas[25].propriedade.cor[9]= 'o';
    tabuleiro.casas[25].propriedade.cor[10]= '\0';
    tabuleiro.casas[25].propriedade.dono= 0;
    tabuleiro.casas[25].propriedade.valorDeCompra= 160;
    tabuleiro.casas[25].propriedade.valorDoAluguelPadrao= 120;
    tabuleiro.casas[25].propriedade.valorDoAluguelPorCasa= 60;
    tabuleiro.casas[25].propriedade.valorConstrucao= 100;
    tabuleiro.casas[25].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[26].nome[0]='E';
    tabuleiro.casas[26].nome[1]='\0';
    tabuleiro.casas[26].empresa.id= 5;
    tabuleiro.casas[26].empresa.dono= 0;
    tabuleiro.casas[26].empresa.valorDeCompra= 2000;
    tabuleiro.casas[26].empresa.valorGastoLucro= 50;
    tabuleiro.casas[26].propriedade.cor[0]= 'C';
    tabuleiro.casas[26].propriedade.cor[1]= 'i';
    tabuleiro.casas[26].propriedade.cor[2]= 'n';
    tabuleiro.casas[26].propriedade.cor[3]= 'z';
    tabuleiro.casas[26].propriedade.cor[4]= 'a';
    tabuleiro.casas[26].propriedade.cor[5]= '\0';
    tabuleiro.casas[26].propriedade.dono= 3;
    tabuleiro.casas[26].propriedade.valorDeCompra= 0;
    tabuleiro.casas[26].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[26].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[26].propriedade.valorConstrucao= 0;
    tabuleiro.casas[26].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[27].nome[0]='C';
    tabuleiro.casas[27].nome[1]='\0';
    tabuleiro.casas[27].empresa.id= 0;
    tabuleiro.casas[27].empresa.dono= 2;
    tabuleiro.casas[27].empresa.valorDeCompra=0;
    tabuleiro.casas[27].empresa.valorGastoLucro=0;
    tabuleiro.casas[27].propriedade.cor[0]= 'B';
    tabuleiro.casas[27].propriedade.cor[1]= 'r';
    tabuleiro.casas[27].propriedade.cor[2]= 'a';
    tabuleiro.casas[27].propriedade.cor[3]= 'n';
    tabuleiro.casas[27].propriedade.cor[4]= 'c';
    tabuleiro.casas[27].propriedade.cor[5]= 'o';
    tabuleiro.casas[27].propriedade.cor[6]= '\0';
    tabuleiro.casas[27].propriedade.dono= 3;
    tabuleiro.casas[27].propriedade.valorDeCompra= 0;
    tabuleiro.casas[27].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[27].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[27].propriedade.valorConstrucao= 0;
    tabuleiro.casas[27].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[28].nome[0]='P';
    tabuleiro.casas[28].nome[1]='\0';
    tabuleiro.casas[28].empresa.id= 0;
    tabuleiro.casas[28].empresa.dono= 2;
    tabuleiro.casas[28].empresa.valorDeCompra=0;
    tabuleiro.casas[28].empresa.valorGastoLucro=0;
    tabuleiro.casas[28].propriedade.cor[0]= 'L';
    tabuleiro.casas[28].propriedade.cor[1]= 'a';
    tabuleiro.casas[28].propriedade.cor[2]= 'r';
    tabuleiro.casas[28].propriedade.cor[3]= 'a';
    tabuleiro.casas[28].propriedade.cor[4]= 'n';
    tabuleiro.casas[28].propriedade.cor[5]= 'j';
    tabuleiro.casas[28].propriedade.cor[6]= 'a';
    tabuleiro.casas[28].propriedade.cor[7]= '\0';
    tabuleiro.casas[28].propriedade.dono= 0;
    tabuleiro.casas[28].propriedade.valorDeCompra= 320; 
    tabuleiro.casas[28].propriedade.valorDoAluguelPadrao= 280;
    tabuleiro.casas[28].propriedade.valorDoAluguelPorCasa= 150;
    tabuleiro.casas[28].propriedade.valorConstrucao= 200;
    tabuleiro.casas[28].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[29].nome[0]='N';
    tabuleiro.casas[29].nome[1]='\0';
    tabuleiro.casas[29].empresa.id= 0;
    tabuleiro.casas[29].empresa.dono= 2;
    tabuleiro.casas[29].empresa.valorDeCompra=0;
    tabuleiro.casas[29].empresa.valorGastoLucro=0;
    tabuleiro.casas[29].propriedade.cor[0]= 'L';
    tabuleiro.casas[29].propriedade.cor[1]= 'a';
    tabuleiro.casas[29].propriedade.cor[2]= 'r';
    tabuleiro.casas[29].propriedade.cor[3]= 'a';
    tabuleiro.casas[29].propriedade.cor[4]= 'n';
    tabuleiro.casas[29].propriedade.cor[5]= 'j';
    tabuleiro.casas[29].propriedade.cor[6]= 'a';
    tabuleiro.casas[29].propriedade.cor[7]= ' ';
    tabuleiro.casas[29].propriedade.cor[7]= 'c';
    tabuleiro.casas[29].propriedade.cor[8]= 'l';
    tabuleiro.casas[29].propriedade.cor[9]= 'a';
    tabuleiro.casas[29].propriedade.cor[10]= 'r';
    tabuleiro.casas[29].propriedade.cor[11]= 'o';
    tabuleiro.casas[29].propriedade.cor[12]= '\0';
    tabuleiro.casas[29].propriedade.dono= 3;
    tabuleiro.casas[29].propriedade.valorDeCompra= 0;
    tabuleiro.casas[29].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[29].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[29].propriedade.valorConstrucao= 0;
    tabuleiro.casas[29].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[30].nome[0]='P';
    tabuleiro.casas[30].nome[1]='\0';
    tabuleiro.casas[30].empresa.id= 0;
    tabuleiro.casas[30].empresa.dono= 2;
    tabuleiro.casas[30].empresa.valorDeCompra=0;
    tabuleiro.casas[30].empresa.valorGastoLucro=0;
    tabuleiro.casas[30].propriedade.cor[0]= 'L';
    tabuleiro.casas[30].propriedade.cor[1]= 'a';
    tabuleiro.casas[30].propriedade.cor[2]= 'r';
    tabuleiro.casas[30].propriedade.cor[3]= 'a';
    tabuleiro.casas[30].propriedade.cor[4]= 'n';
    tabuleiro.casas[30].propriedade.cor[5]= 'j';
    tabuleiro.casas[30].propriedade.cor[6]= 'a';
    tabuleiro.casas[30].propriedade.cor[7]= '\0';
    tabuleiro.casas[30].propriedade.dono= 1;
    tabuleiro.casas[30].propriedade.valorDeCompra= 300;
    tabuleiro.casas[30].propriedade.valorDoAluguelPadrao= 260;
    tabuleiro.casas[30].propriedade.valorDoAluguelPorCasa= 130;
    tabuleiro.casas[30].propriedade.valorConstrucao= 200;
    tabuleiro.casas[30].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[31].nome[0]='P';
    tabuleiro.casas[31].nome[1]='\0';
    tabuleiro.casas[31].empresa.id= 0;
    tabuleiro.casas[31].empresa.dono= 2;
    tabuleiro.casas[31].empresa.valorDeCompra=0;
    tabuleiro.casas[31].empresa.valorGastoLucro=0;
    tabuleiro.casas[31].propriedade.cor[0]= 'L';
    tabuleiro.casas[31].propriedade.cor[1]= 'a';
    tabuleiro.casas[31].propriedade.cor[2]= 'r';
    tabuleiro.casas[31].propriedade.cor[3]= 'a';
    tabuleiro.casas[31].propriedade.cor[4]= 'n';
    tabuleiro.casas[31].propriedade.cor[5]= 'j';
    tabuleiro.casas[31].propriedade.cor[6]= 'a';
    tabuleiro.casas[31].propriedade.cor[7]= '\0';
    tabuleiro.casas[31].propriedade.dono= 0;
    tabuleiro.casas[31].propriedade.valorDeCompra= 300;
    tabuleiro.casas[31].propriedade.valorDoAluguelPadrao= 260;
    tabuleiro.casas[31].propriedade.valorDoAluguelPorCasa= 130;
    tabuleiro.casas[31].propriedade.valorConstrucao= 200;
    tabuleiro.casas[31].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[32].nome[0]='P';
    tabuleiro.casas[32].nome[1]='\0';
    tabuleiro.casas[32].empresa.id= 0;
    tabuleiro.casas[32].empresa.dono= 2;
    tabuleiro.casas[32].empresa.valorDeCompra=0;
    tabuleiro.casas[32].empresa.valorGastoLucro=0;
    tabuleiro.casas[32].propriedade.cor[0]= 'A';
    tabuleiro.casas[32].propriedade.cor[1]= 'm';
    tabuleiro.casas[32].propriedade.cor[2]= 'a';
    tabuleiro.casas[32].propriedade.cor[3]= 'r';
    tabuleiro.casas[32].propriedade.cor[4]= 'e';
    tabuleiro.casas[32].propriedade.cor[5]= 'l';
    tabuleiro.casas[32].propriedade.cor[6]= 'o';
    tabuleiro.casas[32].propriedade.cor[7]= '\0';
    tabuleiro.casas[32].propriedade.dono= 0;
    tabuleiro.casas[32].propriedade.valorDeCompra= 260;
    tabuleiro.casas[32].propriedade.valorDoAluguelPadrao= 130;
    tabuleiro.casas[32].propriedade.valorDoAluguelPorCasa= 110;
    tabuleiro.casas[32].propriedade.valorConstrucao= 150;
    tabuleiro.casas[32].propriedade.nConstrucoes=0;
    
    tabuleiro.casas[33].nome[0]='E';
    tabuleiro.casas[33].nome[1]='\0';
    tabuleiro.casas[33].empresa.id= 6;
    tabuleiro.casas[33].empresa.dono= 0;
    tabuleiro.casas[33].empresa.valorDeCompra= 2000;
    tabuleiro.casas[33].empresa.valorGastoLucro= 50;
    tabuleiro.casas[33].propriedade.cor[0]= 'C';
    tabuleiro.casas[33].propriedade.cor[1]= 'i';
    tabuleiro.casas[33].propriedade.cor[2]= 'n';
    tabuleiro.casas[33].propriedade.cor[3]= 'z';
    tabuleiro.casas[33].propriedade.cor[4]= 'a';
    tabuleiro.casas[33].propriedade.cor[5]= '\0';
    tabuleiro.casas[33].propriedade.dono= 3;
    tabuleiro.casas[33].propriedade.valorDeCompra= 0;
    tabuleiro.casas[33].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[33].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[33].propriedade.valorConstrucao= 0;
    tabuleiro.casas[33].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[34].nome[0]='P';
    tabuleiro.casas[34].nome[1]='\0';
    tabuleiro.casas[34].empresa.id= 0;
    tabuleiro.casas[34].empresa.dono= 2;
    tabuleiro.casas[34].empresa.valorDeCompra=0;
    tabuleiro.casas[34].empresa.valorGastoLucro=0;
    tabuleiro.casas[34].propriedade.cor[0]= 'A';
    tabuleiro.casas[34].propriedade.cor[1]= 'm';
    tabuleiro.casas[34].propriedade.cor[2]= 'a';
    tabuleiro.casas[34].propriedade.cor[3]= 'r';
    tabuleiro.casas[34].propriedade.cor[4]= 'e';
    tabuleiro.casas[34].propriedade.cor[5]= 'l';
    tabuleiro.casas[34].propriedade.cor[6]= 'o';
    tabuleiro.casas[34].propriedade.cor[7]= '\0';
    tabuleiro.casas[34].propriedade.dono= 0;
    tabuleiro.casas[34].propriedade.valorDeCompra= 260;
    tabuleiro.casas[34].propriedade.valorDoAluguelPadrao= 130;
    tabuleiro.casas[34].propriedade.valorDoAluguelPorCasa= 110;
    tabuleiro.casas[34].propriedade.valorConstrucao= 150;
    tabuleiro.casas[34].propriedade.nConstrucoes= 0;
    
    tabuleiro.casas[35].nome[0]='N';
    tabuleiro.casas[35].nome[1]='\0';
    tabuleiro.casas[35].empresa.id= 0;
    tabuleiro.casas[35].empresa.dono= 2;
    tabuleiro.casas[35].empresa.valorDeCompra=0;
    tabuleiro.casas[35].empresa.valorGastoLucro=0;
    tabuleiro.casas[35].propriedade.cor[0]= 'L';
    tabuleiro.casas[35].propriedade.cor[1]= 'a';
    tabuleiro.casas[35].propriedade.cor[2]= 'r';
    tabuleiro.casas[35].propriedade.cor[3]= 'a';
    tabuleiro.casas[35].propriedade.cor[4]= 'n';
    tabuleiro.casas[35].propriedade.cor[5]= 'j';
    tabuleiro.casas[35].propriedade.cor[6]= 'a';
    tabuleiro.casas[35].propriedade.cor[7]= ' ';
    tabuleiro.casas[35].propriedade.cor[8]= 'c';
    tabuleiro.casas[35].propriedade.cor[9]= 'l';
    tabuleiro.casas[35].propriedade.cor[10]= 'a';
    tabuleiro.casas[35].propriedade.cor[11]= 'r';
    tabuleiro.casas[35].propriedade.cor[12]= 'o';
    tabuleiro.casas[35].propriedade.cor[13]= '\0';
    tabuleiro.casas[35].propriedade.dono= 3;
    tabuleiro.casas[35].propriedade.valorDeCompra= 0;
    tabuleiro.casas[35].propriedade.valorDoAluguelPadrao= 0;
    tabuleiro.casas[35].propriedade.valorDoAluguelPorCasa= 0;
    tabuleiro.casas[35].propriedade.valorConstrucao= 0;
    tabuleiro.casas[35].propriedade.nConstrucoes= 0;
//--------------------------------------------------------------------

//--------Declarando valores para cartas de sorte/revés---------------    
    tabuleiro.pilha.cartas[0]= -200;
    tabuleiro.pilha.cartas[1]= 50;
    tabuleiro.pilha.cartas[2]= -50;
    tabuleiro.pilha.cartas[3]= 50;
    tabuleiro.pilha.cartas[4]= 200;
    tabuleiro.pilha.cartas[5]= 100;
    tabuleiro.pilha.cartas[6]= -20;
    tabuleiro.pilha.cartas[7]= -20;
    tabuleiro.pilha.cartas[8]= 10;
    tabuleiro.pilha.cartas[9]= -50;
    tabuleiro.pilha.cartas[10]= 75;
    tabuleiro.pilha.cartas[11]= 100;
    tabuleiro.pilha.cartas[12]= -45;
    tabuleiro.pilha.cartas[13]= 75;
    tabuleiro.pilha.cartas[14]= 20;
    tabuleiro.pilha.cartas[15]= 60;
    tabuleiro.pilha.cartas[16]= -20;
    tabuleiro.pilha.cartas[17]= 150;
    tabuleiro.pilha.cartas[18]= 25;
    tabuleiro.pilha.cartas[19]= 30;
    tabuleiro.pilha.cartas[20]= -22;
    tabuleiro.pilha.cartas[21]= -30;
    tabuleiro.pilha.cartas[22]= -90;
    tabuleiro.pilha.cartas[23]= 100;
    tabuleiro.pilha.cartas[24]= 80;
    tabuleiro.pilha.cartas[25]= 30;
    tabuleiro.pilha.cartas[26]= -40;
    tabuleiro.pilha.cartas[27]= -60;
    tabuleiro.pilha.cartas[28]= 100;
    tabuleiro.pilha.cartas[29]= -200;
    tabuleiro.pilha.cartas[30]= 50;
    tabuleiro.pilha.cartas[31]= -50;
    tabuleiro.pilha.cartas[32]= 50;
    tabuleiro.pilha.cartas[33]= 200;
    tabuleiro.pilha.cartas[34]= 100;
    tabuleiro.pilha.cartas[35]= -20;
//-----------------------------------------------
    

	do{                                             //Loop para o início do programa, caso o jogador decida ver as informações do jogo
	
//------------Tela inicial do jogo---------------
	printf ("\n\n### BANCO IMOBILIARIO ###\n");
	
	printf ("\n1- Iniciar o jogo");
	printf ("\n2- Sobre o jogo");
	printf ("\n3- Sair\n");
	
	printf ("\nDigite uma opcao: ");
	scanf ("%d", &num);
//------------------------------------------------

	switch(num){
		case 1:

            ImprimeTabu();  //Chamada da função ImprimeTabu


//------Declaração do saldo, posição e titulos iniciais do jogador---------
            	jogador.saldo=2558.00;
            	jogador.posicao[0]= 'I';
            	jogador.posicao[1]='\0';
            	
            	 for(i=0;i<18;i++){
            	 	jogador.conjPropriedade[i]=0;
            	 	somaprop=somaprop+jogador.conjPropriedade[i];
				 }
				 
				 for(j=0;j<6;j++){
				 	jogador.conjEmpresas[j]=0;
				 	somaemp=somaemp+jogador.conjEmpresas[j];
				 }

                somatit=somaemp+somaprop;
//--------------------------------------------------------------------------


//-----------------Imprimindo informações do jogador na tela-------------
	             printf("\nSaldo: %2.f\n", jogador.saldo);
	             printf("Titulos: %d\n", somatit);
	             printf("Posicao: %s\n", jogador.posicao);
//-----------------------------------------------------------------------
	             
   do{  //Início do loop do jogo
   
   			//-----------Fim do jogo-------------------------------
			    if(somatit==24){  //Caso o jogador possua todas as propriedades e empresas
			    printf("\n\n\n\n\n\n\n\n\n\n\nVoce se tornou um MILIONARIO!!");
			    printf("\nSaldo: %2.f\n", jogador.saldo);
	            printf("Titulos: %d\n", somatit);
	            
	            printf("\nDigite seu nome: ");
				scanf("%s", nome);
				 
				printf("\nNome: %s", nome);
				printf("\nSaldo Final: %2.f\n", jogador.saldo);
				
				system("pause");
				return 0;
				}
				
				for(k=0;k<36;k++){
				  if(tabuleiro.casas[k].propriedade.dono==2){
				  	aux_prop=aux_prop+tabuleiro.casas[k].propriedade.valorDeCompra;  //Fazendo a soma do valor de compra de todas as propriedades que o jogador possui
				  }
				}
				if(jogador.saldo+aux_prop<=0){  //caso o valor de compra de todas as propriedades do jogador não for o suficiente para tirar ele da falência
					printf("\n\n\n\n\n\n\n\nVocê Faliu!!");
			    printf("\nSaldo: %2.f\n", jogador.saldo);
	            printf("Titulos: %d\n", somatit);
	            
	            printf("\nDigite seu nome: ");
				scanf("%s", nome);
				 
				printf("\nNome: %s", nome);
				printf("\nSaldo Final: %2.f\n", jogador.saldo);
				
				system ("pause");
				return 0;
				}
			//--------------------------------------------------------
	             
	    printf("\n1- Movimentar\n2- Negociar uma propriedade\n3- Vender uma propriedade\n4- Sair\n\nOpcao: ");
	     scanf("%d", &n);
	       
		   switch(n){
   	        case 1:  //Caso o jogador decisa se movimentar pelo tabuleiro
   	        	
   	        dados=jogarDados(dados);  //Chamada da função jogarDados
   	         printf("\nDados: %d\n\n", dados);

		    strcpy(jogador.posicao,tabuleiro.casas[a+dados].nome);  //Copia o nome da casa do tabuleiro que seja a inicial+o núemro tirado nos dados para a posicao do jogador
			    printf("Posicao: %s\n\n", jogador.posicao);
			    
			    		    a=a+dados;  //Acrescenta o número dos dados na posição do jogador
							
							ImprimeTabu();  //Chamada da função ImprimeTabu 
							
            //--------------Caso o jogador caia na casa do camburão-----------	
			      if(strcmp(jogador.posicao,tabuleiro.casas[27].nome)==0){
	             	strcpy(jogador.posicao,tabuleiro.casas[9].nome);  //A posição dele passa a ser a posição da Detenção/Visita
	             	 jogador.saldo=jogador.saldo-200-500;  //O jogador paga a fiança e perde o salário
	             	 a=27+18;  //A posição cresce em 18, dá a volta no tabuleiro e para em DV
				 }
			//----------------------------------------------------------------
			
			//-------------Caso o Jogador caia na casa Detenção/Visita---------
				  if(strcmp(jogador.posicao,tabuleiro.casas[9].nome)==0){
				  	printf("\nMomento de descanso\n");
				  }
			//-----------------------------------------------------------------
				  
			//-------------Caso o Jogador caia na casa Feriado-----------------
				  if(strcmp(jogador.posicao,tabuleiro.casas[18].nome)==0){
				  	printf("\nMomento de descanso\n");
				  }
			//-----------------------------------------------------------------
			
			
			//------------Caso o Jogador caia na casa Construtora--------------
				  if(strcmp(jogador.posicao,tabuleiro.casas[14].nome)==0){
			       for(f=0;f<36;f++){
			       	if(tabuleiro.casas[f].propriedade.dono==2){  //O jogador precisa ser o dono da propriedade (linha 977) e ser dono de todas as propriedades da mesma cor (linha 978) (Linhas como exemplo)
			       	   if(strcmp(tabuleiro.casas[f].propriedade.cor,tabuleiro.casas[1].propriedade.cor)==0 && tabuleiro.casas[1].propriedade.dono==2 && tabuleiro.casas[4].propriedade.dono==2){
			    printf("\n %s Casa %d\n",tabuleiro.casas[f].nome, f+1);
            	printf("Cor: %s\n",tabuleiro.casas[f].propriedade.cor);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[f].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[f].propriedade.nConstrucoes);
						  }
						  
					if(strcmp(tabuleiro.casas[f].propriedade.cor,tabuleiro.casas[6].propriedade.cor)==0 && tabuleiro.casas[6].propriedade.dono==2 && tabuleiro.casas[8].propriedade.dono==2){
			    printf("\n %s Casa %d\n",tabuleiro.casas[f].nome, f+1);
            	printf("Cor: %s\n",tabuleiro.casas[f].propriedade.cor);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[f].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[f].propriedade.nConstrucoes);
						  }
						  
					if(strcmp(tabuleiro.casas[f].propriedade.cor,tabuleiro.casas[11].propriedade.cor)==0 && tabuleiro.casas[11].propriedade.dono==2 && tabuleiro.casas[13].propriedade.dono==2){
			    printf("\n %s Casa %d\n",tabuleiro.casas[f].nome, f+1);
            	printf("Cor: %s\n",tabuleiro.casas[f].propriedade.cor);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[f].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[f].propriedade.nConstrucoes);
						  }
						  
					if(strcmp(tabuleiro.casas[f].propriedade.cor,tabuleiro.casas[15].propriedade.cor)==0 && tabuleiro.casas[15].propriedade.dono==2 && tabuleiro.casas[16].propriedade.dono==2){
			    printf("\n %s Casa %d\n",tabuleiro.casas[f].nome, f+1);
            	printf("Cor: %s\n",tabuleiro.casas[f].propriedade.cor);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[f].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[f].propriedade.nConstrucoes);
						  }
						  
					if(strcmp(tabuleiro.casas[f].propriedade.cor,tabuleiro.casas[17].propriedade.cor)==0 && tabuleiro.casas[17].propriedade.dono==2 && tabuleiro.casas[19].propriedade.dono==2){
			    printf("\n %s Casa %d\n",tabuleiro.casas[f].nome, f+1);
            	printf("Cor: %s\n",tabuleiro.casas[f].propriedade.cor);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[f].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[f].propriedade.nConstrucoes);
						  }
						  
					if(strcmp(tabuleiro.casas[f].propriedade.cor,tabuleiro.casas[23].propriedade.cor)==0 && tabuleiro.casas[23].propriedade.dono==2 && tabuleiro.casas[24].propriedade.dono==2 && tabuleiro.casas[25].propriedade.dono==2){
			    printf("\n %s Casa %d\n",tabuleiro.casas[f].nome, f+1);
            	printf("Cor: %s\n",tabuleiro.casas[f].propriedade.cor);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[f].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[f].propriedade.nConstrucoes);
						  }
						  
					if(strcmp(tabuleiro.casas[f].propriedade.cor,tabuleiro.casas[28].propriedade.cor)==0 && tabuleiro.casas[28].propriedade.dono==2 && tabuleiro.casas[30].propriedade.dono==2 && tabuleiro.casas[31].propriedade.dono==2){
			    printf("\n %s Casa %d\n",tabuleiro.casas[f].nome, f+1);
            	printf("Cor: %s\n",tabuleiro.casas[f].propriedade.cor);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[f].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[f].propriedade.nConstrucoes);
						  }
						  
					if(strcmp(tabuleiro.casas[f].propriedade.cor,tabuleiro.casas[32].propriedade.cor)==0 && tabuleiro.casas[32].propriedade.dono==2 && tabuleiro.casas[34].propriedade.dono==2){
			    printf("\n %s Casa %d\n",tabuleiro.casas[f].nome, f+1);
            	printf("Cor: %s\n",tabuleiro.casas[f].propriedade.cor);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[f].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[f].propriedade.nConstrucoes);
						  }
					   printf("\n\nEm qual propriedade construir: ");  //Caso os dois requisitos sejam cumpridos, saber em que propriedade vai ser construida
					    scanf("%d", &g);
					    
					   jogador.saldo=jogador.saldo-tabuleiro.casas[g-1].propriedade.valorConstrucao; //Diminuir do saldo do jogador o preço da construção, dependendo da propriedade escolhida para construção
					   tabuleiro.casas[g-1].propriedade.nConstrucoes=tabuleiro.casas[g-1].propriedade.nConstrucoes+1; //Acrescentar uma construção à propriedade
				   } 
				   else{ printf("\nNao possui propriedades para construcao\n");break;}  //Caso não possua propriedades que cumpram os dois requisitos
				   }
				   
				  }
	        //------------------------------------------------------------
	        
	        
			//---------------Caso caia na casa Construção Livre-----------------
				  if(strcmp(jogador.posicao,tabuleiro.casas[21].nome)==0){
				  for(b=0;b<36;b++){
				 if(tabuleiro.casas[b].propriedade.dono!=2 && tabuleiro.casas[b].propriedade.dono!=3){  //Listar propriedades que não sejam do jogador
            	printf("\n %s Casa %d\n",tabuleiro.casas[b].nome, b+1);
            	printf("Cor: %s\n",tabuleiro.casas[b].propriedade.cor);
                printf("Valor de Compra: %2.f\n",tabuleiro.casas[b].propriedade.valorDeCompra);
                printf("Valor do Aluguel: %2.f\n",tabuleiro.casas[b].propriedade.valorDoAluguelPadrao);
                printf("Valor do Aluguel por Casa: %2.f\n",tabuleiro.casas[b].propriedade.valorDoAluguelPorCasa);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[b].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[b].propriedade.nConstrucoes);}}
			
			printf("Qual a propriedade a ser comprada: ");  //Escolher propriedade a ser comprada
			 scanf("%d", &c);
				  	
		    somatit=somatit+1;  //Acrescentar aos títulos de posse do jogador
            jogador.saldo=jogador.saldo-tabuleiro.casas[c-1].propriedade.valorDeCompra;  //Diminuir do saldo do jogador o valor de compra da propriedade escolhida
				
	               tabuleiro.casas[c-1].propriedade.dono=2;}  //Atribuir a propriedade ao jogador
			//--------------------------------------------------------------------
			
			//----------------Caso caia em uma Propriedade-----------------
			if(strcmp(jogador.posicao,tabuleiro.casas[1].nome)==0){
				if(tabuleiro.casas[a].propriedade.dono==0){  //Caso a propriedade não possuia um dono
					printf("\n1- Pagar Aluguel\n2-Comprar\n\nOpcao: "); //O jogador tem 2 possibilidades, comprar ou pagar o aluguel
					 scanf("%d", &d);
					  
					  switch(d){
					  	case 1:  //Caso ele escolha pagar o aluguel
					  		if(tabuleiro.casas[a].propriedade.nConstrucoes==0){
					  		 jogador.saldo=jogador.saldo-tabuleiro.casas[a].propriedade.valorDoAluguelPadrao;}  //Retira do saldo do jogador o preço do aluguel da propriedade que não possui construções
					  
					        if(tabuleiro.casas[a].propriedade.nConstrucoes==1){
					         jogador.saldo=jogador.saldo-(tabuleiro.casas[a].propriedade.valorDoAluguelPadrao+tabuleiro.casas[a].propriedade.valorDoAluguelPorCasa); //Retira do saldo o valor do aluguel para uma casa
							}
							
							if(tabuleiro.casas[a].propriedade.nConstrucoes==2){
					         jogador.saldo=jogador.saldo-(tabuleiro.casas[a].propriedade.valorDoAluguelPadrao+(tabuleiro.casas[a].propriedade.valorDoAluguelPorCasa*2));  //Retira o valor para hotel
							}
							
							if(tabuleiro.casas[a].propriedade.nConstrucoes==3){
					         jogador.saldo=jogador.saldo-(tabuleiro.casas[a].propriedade.valorDoAluguelPadrao+(tabuleiro.casas[1].propriedade.valorDoAluguelPorCasa*3));  //Retira o valor para shopping
							}
							
							break;
							
						case 2:  //Caso ele escolha comprar a propriedade
							jogador.saldo=jogador.saldo-tabuleiro.casas[a].propriedade.valorDeCompra;  //Retirar do saldo o preço de compra da propriedade
							somatit=somatit+1;  //Acrescentar um título ao jogador
							tabuleiro.casas[a].propriedade.dono=2;  //Atribuir a propriedade ao jogador
				}}
				
				  if(tabuleiro.casas[a].propriedade.dono==1){  //Caso a propriedade possua um dono que não seja o jogador
				  	jogador.saldo=jogador.saldo-tabuleiro.casas[1].propriedade.valorDoAluguelPadrao;  //Pagar o valor do aluguel
				  }
				  
				  if(tabuleiro.casas[a].propriedade.dono==2){  //Caso o jogador seja o dono da propriedade
				  	 if(strcmp(tabuleiro.casas[a].propriedade.cor,tabuleiro.casas[1].propriedade.cor)==0 && tabuleiro.casas[1].propriedade.dono==2 && tabuleiro.casas[4].propriedade.dono==2){  //Caso ele possua todas as propriedades da mesma cor
			    printf("\n1-Construir\n2-Fazer Nada\nOpcao: "); //Pode escolher construir na propriedade ou fazer nada
			     scanf("%d", &h);
			     
			        switch(h){
			        	case 1:  //Caso ele escolha construir na propriedade
			        		jogador.saldo=jogador.saldo-tabuleiro.casas[a-1].propriedade.valorConstrucao;  //Retirar do saldo o valor da construção
					   tabuleiro.casas[a-1].propriedade.nConstrucoes=tabuleiro.casas[a-1].propriedade.nConstrucoes+1; break;  //Acrescentar uma construção à propriedade
					   
					    case 2:
					    	break;
					}}
					
					 if(strcmp(tabuleiro.casas[a].propriedade.cor,tabuleiro.casas[6].propriedade.cor)==0 && tabuleiro.casas[6].propriedade.dono==2 && tabuleiro.casas[8].propriedade.dono==2){
			    printf("\n1-Construir\n2-Fazer Nada\nOpcao: ");
			     scanf("%d", &h);
			     
			        switch(h){
			        	case 1:
			        		jogador.saldo=jogador.saldo-tabuleiro.casas[a-1].propriedade.valorConstrucao;
					   tabuleiro.casas[a-1].propriedade.nConstrucoes=tabuleiro.casas[a-1].propriedade.nConstrucoes+1; break;
					   
					    case 2:
					    	break;
					}}
						  
					 if(strcmp(tabuleiro.casas[a].propriedade.cor,tabuleiro.casas[11].propriedade.cor)==0 && tabuleiro.casas[11].propriedade.dono==2 && tabuleiro.casas[13].propriedade.dono==2){
			    printf("\n1-Construir\n2-Fazer Nada\nOpcao: ");
			     scanf("%d", &h);
			     
			        switch(h){
			        	case 1:
			        		jogador.saldo=jogador.saldo-tabuleiro.casas[a-1].propriedade.valorConstrucao;
					   tabuleiro.casas[a-1].propriedade.nConstrucoes=tabuleiro.casas[a-1].propriedade.nConstrucoes+1; break;
					   
					    case 2:
					    	break;
					}}	  
					
					 if(strcmp(tabuleiro.casas[a].propriedade.cor,tabuleiro.casas[15].propriedade.cor)==0 && tabuleiro.casas[15].propriedade.dono==2 && tabuleiro.casas[16].propriedade.dono==2){
			    printf("\n1-Construir\n2-Fazer Nada\nOpcao: ");
			     scanf("%d", &h);
			     
			        switch(h){
			        	case 1:
			        		jogador.saldo=jogador.saldo-tabuleiro.casas[a-1].propriedade.valorConstrucao;
					   tabuleiro.casas[a-1].propriedade.nConstrucoes=tabuleiro.casas[a-1].propriedade.nConstrucoes+1; break;
					   
					    case 2:
					    	break;
					}}
					
					 if(strcmp(tabuleiro.casas[a].propriedade.cor,tabuleiro.casas[17].propriedade.cor)==0 && tabuleiro.casas[17].propriedade.dono==2 && tabuleiro.casas[19].propriedade.dono==2){
			    printf("\n1-Construir\n2-Fazer Nada\nOpcao: ");
			     scanf("%d", &h);
			     
			        switch(h){
			        	case 1:
			        		jogador.saldo=jogador.saldo-tabuleiro.casas[a-1].propriedade.valorConstrucao;
					   tabuleiro.casas[a-1].propriedade.nConstrucoes=tabuleiro.casas[a-1].propriedade.nConstrucoes+1; break;
					   
					    case 2:
					    	break;
					}}
					
					 if(strcmp(tabuleiro.casas[a].propriedade.cor,tabuleiro.casas[23].propriedade.cor)==0 && tabuleiro.casas[23].propriedade.dono==2 && tabuleiro.casas[24].propriedade.dono==2 && tabuleiro.casas[25].propriedade.dono==2){
			    printf("\n1-Construir\n2-Fazer Nada\nOpcao: ");
			     scanf("%d", &h);
			     
			        switch(h){
			        	case 1:
			        		jogador.saldo=jogador.saldo-tabuleiro.casas[a-1].propriedade.valorConstrucao;
					   tabuleiro.casas[a-1].propriedade.nConstrucoes=tabuleiro.casas[a-1].propriedade.nConstrucoes+1; break;
					   
					    case 2:
					    	break;
					}}
					
					 if(strcmp(tabuleiro.casas[a].propriedade.cor,tabuleiro.casas[28].propriedade.cor)==0 && tabuleiro.casas[28].propriedade.dono==2 && tabuleiro.casas[30].propriedade.dono==2 && tabuleiro.casas[31].propriedade.dono==2){
			    printf("\n1-Construir\n2-Fazer Nada\nOpcao: ");
			     scanf("%d", &h);
			     
			        switch(h){
			        	case 1:
			        		jogador.saldo=jogador.saldo-tabuleiro.casas[a-1].propriedade.valorConstrucao;
					   tabuleiro.casas[a-1].propriedade.nConstrucoes=tabuleiro.casas[a-1].propriedade.nConstrucoes+1; break;
					   
					    case 2:
					    	break;
					}}
					
					 if(strcmp(tabuleiro.casas[a].propriedade.cor,tabuleiro.casas[32].propriedade.cor)==0 && tabuleiro.casas[32].propriedade.dono==2 && tabuleiro.casas[34].propriedade.dono==2){
			    printf("\n1-Construir\n2-Fazer Nada\nOpcao: ");
			     scanf("%d", &h);
			     
			        switch(h){
			        	case 1:
			        		jogador.saldo=jogador.saldo-tabuleiro.casas[a-1].propriedade.valorConstrucao;
					   tabuleiro.casas[a-1].propriedade.nConstrucoes=tabuleiro.casas[a-1].propriedade.nConstrucoes+1; break;
					   
					    case 2:
					    	break;
					}}

					   }
				  	
				  } 			
		    //---------------------------------------------------------------------------------------------------
				
				
			//-----------------------Caso caia em uma Empresa----------------------------------------------------
				if(strcmp(jogador.posicao,tabuleiro.casas[33].nome)==0){
					if(tabuleiro.casas[a].empresa.dono==0){  //Caso não possua dono
						printf("\n1- Pagar Gasto\n2- Comprar\nOpcao: ");
						 scanf("%d", &e);
						switch(e){
							case 1:  //Caso escolha pagar o Gasto da empresa
								jogador.saldo=jogador.saldo-(tabuleiro.casas[a].empresa.valorGastoLucro*dados); break;  //Retirar do saldo do jogador o valor do gasto multiplicado pelo número que ele tirou nos dados
								
							case 2:  //Caso escolha a compra da empresa
								jogador.saldo=jogador.saldo-(tabuleiro.casas[a].empresa.valorDeCompra);  //Retirar do saldo o preço de compra da Empresa
								tabuleiro.casas[a].empresa.dono=1;  //Atribuir a empresa ao jogador
								somatit=somatit+1; break;  //Acrescentar um no número de títulos de posse do jogador
						}	
					}
					
					if(tabuleiro.casas[a].empresa.dono==1){  //Caso o jogador seja o dono da empresa
						jogador.saldo=jogador.saldo+(tabuleiro.casas[a].empresa.valorGastoLucro*dados);  //O saldo do jogador vai aumentar a quantida de lucro multiplicada pelo número que tirou nos dados
					}
					
				}
			//------------------------------------------------------------------------------------------------		
				
			//--------------------------Caso caia nas Noticias---------------------------------
				if(strcmp(jogador.posicao,tabuleiro.casas[35].nome)==0){
					srand(time(NULL));
					cartas= rand()%35;  //Retirar uma carta da pilha aleatoriamente
					
					printf("\n\nCarta: %d", cartas);
					printf("\nValor: %2.f\n", tabuleiro.pilha.cartas[cartas]);
					jogador.saldo=jogador.saldo+tabuleiro.pilha.cartas[cartas];  //Retirar ou acrescentar o valor que tirou na sorte/revés
				}
			//-------------------------------------------------------------------------------
				
			//-----------Loop do tabuleiro----------------
				if(a+dados>=36){  //Caso o número do dado ultrapasse a quantidade de casas do tabuleiro
					jogador.saldo=jogador.saldo+500;  //Acrescentar o salário do jogador
					 a=(a+dados)%36;  //A casa agora vai ser o resto da posição do jogador mais os dados em uma divisão por 36
				}
			//--------------------------------------------
				
			//----------Imprimindo na tela as informações do jogador-------------------------				
				 printf("\nSaldo: %2.f\n", jogador.saldo);
	             printf("Titulos: %d\n", somatit);
	             printf("Posicao: %s\n", jogador.posicao); break;
			//-------------------------------------------------------------------------------
						    
   	        case 2:  //Caso o jogador decida negociar uma propriedade
        for(b=0;b<36;b++){  //Imprimir as propriedades
            	if(tabuleiro.casas[b].propriedade.dono==1){  //Para propriedades que possuam um dono que não seja o jogador
            	printf("\n %s Casa %d\n",tabuleiro.casas[b].nome, b+1);
            	printf("Cor: %s\n",tabuleiro.casas[b].propriedade.cor);
                printf("Valor de Compra: %2.f\n",tabuleiro.casas[b].propriedade.valorDeCompra);
                printf("Valor do Aluguel: %2.f\n",tabuleiro.casas[b].propriedade.valorDoAluguelPadrao);
                printf("Valor do Aluguel por Casa: %2.f\n",tabuleiro.casas[b].propriedade.valorDoAluguelPorCasa);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[b].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[b].propriedade.nConstrucoes);
			}
			}
			
			
			printf("Qual a propriedade a ser negociada: ");
			 scanf("%d", &c);
			 
			 if(tabuleiro.casas[c-1].propriedade.dono!=1){
			 	printf("\nNegociacao invalida\n"); break;
			 }
			 
		else{
			int dado1, dado2;  //Jogar os dados
	   	     srand(time(NULL));
   	 	     dado1= rand()%6+1;
	         dado2= rand()%6+1;
	         
	         if(dado1==dado2){  //Caso o número dos dados seja igual, jogar novamente
	         srand(time(NULL));
   	 	     dado1= rand()%6+1;
	         dado2= rand()%6+1;
			 } else{			 
	         printf("Dado do Jogador: %d\nDado do Proprietario: %d\n\n", dado1,dado2);}  //Imprimir os valores tirados
			
			if(dado1>dado2){  //Caso o dado do jogador seja maior
				
           somatit=somatit+1;  //Acrescentar um título ao jogador
           jogador.saldo=jogador.saldo-((tabuleiro.casas[c-1].propriedade.valorDeCompra*80)/100);  //Retirar do saldo do jogador o valor de compra 20% mais barato
				
				printf("\nSaldo: %2.f\n", jogador.saldo);
	            printf("Titulos: %d\n", somatit);
	            printf("Posicao: %s\n", jogador.posicao);
	            
	        tabuleiro.casas[c-1].propriedade.dono=2;  //Atribuir a propriedade ao jogador 
			}  else{
				printf("A negociacao falhou!\n\n");  //Caso o dado do proprietário seja maior
			}break;}
   	 	
   	        case 3:  //Caso o jogador queira vender uma propriedade
   	        	
   	        	if(somatit>0){
   	        	for(b=0;b<36;b++){  //Imprimir as propriedades
            	if(tabuleiro.casas[b].propriedade.dono==2){  //Que o jogador possua
            	printf("\n %s Casa %d\n",tabuleiro.casas[b].nome, b+1);
                printf("Valor de Compra: %2.f\n",tabuleiro.casas[b].propriedade.valorDeCompra);
                printf("Valor do Aluguel: %2.f\n",tabuleiro.casas[b].propriedade.valorDoAluguelPadrao);
                printf("Valor do Aluguel por Casa: %2.f\n",tabuleiro.casas[b].propriedade.valorDoAluguelPorCasa);
                printf("Valor para Construcao: %2.f\n",tabuleiro.casas[b].propriedade.valorConstrucao);
                printf("Construcoes: %d\n\n",tabuleiro.casas[b].propriedade.nConstrucoes);
			}}
			
						printf("Qual a propriedade a ser vendida: ");
						 scanf("%d", &c);
						 
			somatit=somatit-1;  //Remover o título do jogador
           jogador.saldo=jogador.saldo+tabuleiro.casas[c-1].propriedade.valorDeCompra;  //Acrescentar ao saldo do jogador o valor de compra da propriedade
				
				printf("\nSaldo: %2.f\n", jogador.saldo);
	            printf("Titulos: %d\n", somatit);
	            printf("Posicao: %s\n", jogador.posicao);
	            
	        tabuleiro.casas[c-1].propriedade.dono=0;break;}  //Retirar o jogador como dono da propriedade
   	 	
			else{ printf("\nNao possui propriedades para vender\n");break; //Caso o jogador não possua propriedades para vender
			}
			
   	        case 4:  //Caso o jogador queira sair do jogo
   	        printf ("\nSaindo do jogo...\t\n");
   	     	 system("pause");
   	 	     return 0;

   	 	     
   }} while (n!=4); break; //Fim do loop do jogo
   		
		case 2 :  //Imprimir informaçoes sobre o jogo na tela
			printf ("\nObjetivo: Conquistar a fortuna e o maior numero de propriedades.\n\nMovimentacao pelo tabuleiro: Dados vao ser jogados e o jogador avanca pelo tabuleiro."); 
			printf ("\n\n\tTABULEIRO\t");
			printf ("\nInicio: Onde o jogador comeca o jogo. Cada vez que passar pelo inicio, o jogador recebe um salario de 500 creditos.\n");
			printf ("\nPropriedades: Caso possua um proprietario, o jogador deve pagar um aluguel.\nCaso nao possua um proprietario, o jogador tem a possibilidade de comprar a propriedade.\n");
			printf ("Se o jogador possuir todas as propriedades da mesma cor, pode construir uma casa.\n");
			printf ("\nEmpresa: Se o jogador cair na casa 'empresa', tem a possibilidade de comprar, ou pagar o  gasto.\nO gasto e o valor de 50 creditos multiplicado pelo numero dos dados.\n");
			printf ("Caso o jogador seja o dono da empresa, ele recebe um lucro seguindo a mesma logica do gasto.\n");
			printf ("\nNoticia: O jogador recebe uma carta de sorte ou reves, tirada aleatoriamente de uma pilha de 36 cartas.\n");
			printf ("\nCamburao: O jogador vai ser levado para a casa Detencao/Visita e pagara a fianca de 200 creditos.\n");
			printf ("\nDetencao/Visita: Nada acontece, um momento de descanso.\n");
			printf ("\nFeriado: Nada acontece, momento de descanso\n");
			printf ("\nConstrutora: Caso o jogador possua todas as propriedades de uma cor, ele pode construir em uma delas.\n");
			printf ("\nCompra livre: Compra qualquer propriedade do jogo, que nao possua um proprietario.\n");
			printf("\n");
			printf("\nOpcao de Negociar: O jogador pode negociar propriedades que ja tenham um dono, em qualquer momento do jogo.\nDois dados sao jogados, caso o jogador tire o maior numero, ele compra a propriedade com o valor 20%% mais barato\n");
			printf ("Caso o proprietario tire o numero mais alto, o jogador perde a negociacao.\n");
			printf ("\nOpcao de Vender propriedade: O jogador pode vender qualquer uma de suas propriedades, em qualquer momento do jogo.\n");
	 break; 
			
		case 3 :  //Sair do jogo
			printf ("\nSaindo do jogo...\t"); break;
} }while(num!=3);  // Fim do loop para caso o jogador queira ver as informações do jogo

	return 0;
}
//-----------------------------------Fim da função principal------------------------------------


//------------------Funções------------------------------
void ImprimeTabu (){  //Função que imprime o tabuleiro na tela
	
	printf ("\n\t### TABULEIRO ###\t\n\n");
			
				char tabu[80]= {"I P N E P N P E P DV N P E P CC P P P F P E CL N P P P E P C P N P P P E P N"};
				                	printf("%s\n", tabu);
	
}


int jogarDados (int dados){  //Função que joga os dados para movimentação do jogador no tabuleiro
	
	int dado1, dado2;
	
	   	     srand(time(NULL));
   	 	     dado1= rand()%6+1;
	         dado2= rand()%6+1;
	         dados=dado1+dado2;
	
	return (dados);
	
}
//------------------------------------------------------------
