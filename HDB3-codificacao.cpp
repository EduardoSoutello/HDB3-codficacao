#include <iostream>
#include <conio.h>
#include<stdio.h>

char sinal[23] = {'0','1','0','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','1','0','0','0','0'};// inserir vetor manual para transfomar em vetor codificado HDB3
char exemplo[23] = {}; // vetor de comparacao
char polaridade = 'n'; // expressa a polaridade da linha de transmissão
int i;
int k = 2; // conta a quantidade de violacoes


int main()
{
	for (i = 0; i < 23; i++) {
		//scanf_s(" %c%*c", &sinal);
		exemplo[i] = sinal[i]; // copia o vetor de sinal de entrada
	}
	for (i = 0; i < 23; i++) {
		if (sinal[i] == '1') { //trata os bits de sinal
			if (polaridade == 'p') { //verifica a polaridade e insere o sinal "-" representativo e altera a polaridade
				sinal[i] = '-';
				k++;
				polaridade = 'n';
			}
			else { //verifica a polaridade e insere o sinal "+" representativo e altera a polaridade
				sinal[i] = '+';
				k++;
				polaridade = 'p';
			}
		}
		if (sinal[i] == '0' & sinal[i + 1] == '0' & sinal[i + 2] == '0' & sinal[i + 3] == '0') { //enconrta sequencia de 0,0,0,0 (4 zeros) para que sejam tratadas
			if ((polaridade == 'p') & (k % 2 == 0)) {
				sinal[i] = 'b';
				sinal[i + 3] = 'v';
				polaridade = 'n';
			}
			else if ((polaridade == 'p') & (k % 2 == 1)) {
				sinal[i] = '0';
				sinal[i + 3] = 'V';
				k++;
			}
			else if ((polaridade == 'n') & (k % 2 == 0)) {
				sinal[i] = 'B';
				sinal[i + 3] = 'V';
				polaridade = 'p';
			}
			else if ((polaridade == 'n') & (k % 2 == 1)) {
				sinal[i] = '0';
				sinal[i + 3] = 'v';
				k++;
			}
		}
	}
	for (i = 0; 1 < 23; i++) {
	printf("Codigo HDB3 - Atividade Pratica \n")
	}

	for (i = 0; i < 23; i++) { // imprime a copia do sinal de entrda para facilitar a comparação com o sinal tratado
		printf("%c ", exemplo[i]);
	}
	printf("\n");
	for (i = 0; i < 23; i++) { //imprime o sinal tratado com o codificdor HDB3
		printf("%c ", sinal[i]);
	}

}

