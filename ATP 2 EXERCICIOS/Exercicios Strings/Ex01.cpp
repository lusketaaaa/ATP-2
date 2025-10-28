#include <stdio.h>
#include <string.h>

int RetornaTamanhoString(char string[21])
{
	return strlen(string);
}
int main(void)
{
	char string[21];
	printf("Digite uma frase de ate 20 caractes e retornarei o tamanho: \n");
	gets(string);
	int tamanho = RetornaTamanhoString(string);
	printf("%d caracteres!\n", tamanho);
	
	return 0;
}
