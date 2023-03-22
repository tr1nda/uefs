#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Paciente {
	char nome[30];		// Sem validação
	int  prioridade;

	struct Paciente *proximo;
};

typedef struct Paciente *Paciente;

void
adicione(Paciente *primeiro_paciente)
{
	Paciente old_paciente  = NULL, ptr = *primeiro_paciente;
	Paciente novo_paciente = malloc(sizeof(struct Paciente));

	printf("Digite o nome do novo paciente: ");
	scanf("%s", novo_paciente->nome);
	
	printf("Digite a prioridade: ");
	scanf("%d", &novo_paciente->prioridade);

	for (;
		ptr != NULL && ptr->prioridade >= novo_paciente->prioridade;
		old_paciente = ptr, ptr = ptr->proximo) ;
	
	if (old_paciente == NULL)
		*primeiro_paciente = novo_paciente;
	else
		old_paciente->proximo = novo_paciente;

	novo_paciente->proximo = ptr;
}

void
atenda(Paciente *primeiro_paciente)
{
	Paciente old_primeiro_paciente = *primeiro_paciente;

	*primeiro_paciente = (*primeiro_paciente)->proximo;

	free(old_primeiro_paciente);
}

void
imprima(Paciente *primeiro_paciente)
{
	for (Paciente ptr = *primeiro_paciente; ptr != NULL; ptr = ptr->proximo) {
		puts("###################");
	
		printf("Nome: %s\n", ptr->nome);
		printf("Prioridade: %d\n", ptr->prioridade);

		puts("###################");
	}
}

int
main(int argc, char *argv[])
{
	char opcao = '\0';
	bool pare  = false;
	
	Paciente old_primeiro_paciente = NULL; 
	Paciente primeiro_paciente     = NULL;

	do {
		puts("1 → Adicionar");
		puts("2 → Atender");
		puts("3 → Imprimir");
		
		printf("O que você deseja fazer: ");
		scanf(" %c", &opcao);

		switch (opcao) {
			case '1':
				adicione(&primeiro_paciente);
				break;
			case '2':
				atenda(&primeiro_paciente);
				break;
			case '3':
				imprima(&primeiro_paciente);
				break;
		}

		printf("Deseja continuar: ");
		scanf(" %c", &opcao);

		pare = opcao == 'n';
	} while (!pare);

	while (primeiro_paciente != NULL) {
		old_primeiro_paciente = primeiro_paciente;
		primeiro_paciente = primeiro_paciente->proximo;
		free(old_primeiro_paciente);
	}

	return 0;
}
