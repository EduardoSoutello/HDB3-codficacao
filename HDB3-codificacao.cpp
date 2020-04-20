#include <iostream>
#include <conio.h>
#include<stdio.h>

char sinal[23] = {'0','1','0','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','1','0','0','0','0'};
char exemplo[23] = {};
char polaridade = 'n';
int i;
int k = 2;


int main()
{
	for (i = 0; i < 23; i++) {
		//scanf_s(" %c%*c", &sinal);
		exemplo[i] = sinal[i];
	}
	for (i = 0; i < 23; i++) {
		if (sinal[i] == '1') {
			if (polaridade == 'p') {
				sinal[i] = '-';
				k++;
				polaridade = 'n';
			}
			else {
				sinal[i] = '+';
				k++;
				polaridade = 'p';
			}
		}
		if (sinal[i] == '0' & sinal[i + 1] == '0' & sinal[i + 2] == '0' & sinal[i + 3] == '0') {
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
	for (i = 0; i < 23; i++) {
		printf("%c ", exemplo[i]);
	}
	printf("\n");
	for (i = 0; i < 23; i++) {
		printf("%c ", sinal[i]);
	}

}

