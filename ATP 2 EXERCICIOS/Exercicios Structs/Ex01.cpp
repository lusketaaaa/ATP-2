#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TF 30
#define TFV 5

struct TpPessoa
{
	char Nome[TF];
	char Endereco[TF];
	char Telefone[TF];
};

void OrdenarPorNome(TpPessoa Pessoas[TF],int TLV)
{
	if(TLV == 0)
		return;
	for(int x = 0; x < TLV - 1; x++)
	{
		for(int y = 0; y < TLV - x - 1; y++) {
			if(stricmp(Pessoas[y].Nome, Pessoas[y + 1].Nome) > 0)
			{
				TpPessoa PessoaTemporaria = Pessoas[y];
				Pessoas[y] = Pessoas[y + 1];
				Pessoas[y + 1] = PessoaTemporaria;
			}
		}
	}
}

void CadastrarPessoa(TpPessoa Pessoas[TF],int &TLV)
{
	if(TLV >= TFV)
	{
		printf("Vetor cheio\n");
		return;	
	}


	printf("# # # CADASTRO # # #\n");
	while(TFV > TLV)
	{
		printf("Digite o nome: ");

		fgets(Pessoas[TLV].Nome, TF, stdin);
		printf("Digite o Endereco: ");

		fgets(Pessoas[TLV].Endereco, TF, stdin);
		printf("Digite o telefone (XX XXXXX-XXXX): ");

		fgets(Pessoas[TLV].Telefone, TF, stdin);
		TLV++;
	}
	OrdenarPorNome(Pessoas,TLV);
}

void Relatorio(TpPessoa Pessoas[TF], int TLV)
{

	printf("# # # RELATORIO # # #\n");
	for(int i = 0; i < TLV; i++) {
		printf("Pessoa [%d]:\n", i+1);
		printf("Nome: %s ", Pessoas[i].Nome);
		printf("Endereco: %s ", Pessoas[i].Endereco);
		printf("Telefone: %s ", Pessoas[i].Telefone);
	}
}

int main(void) 
{
	int TLV = 0;
	TpPessoa Pessoas[TF];
	CadastrarPessoa(Pessoas, TLV);
	Relatorio(Pessoas, TLV);
	
	return 0;
}
