#include <stdio.h>
#define SIZE 5

//Sintaxe do typedef
/*
typedef [tipo ou struct] nomeNovoTipo;
typedef int novoInt;
novoInt numero;
*/

//Criando tipos a partir de estruturas de dados
/*
//Sintaxe do struct
struct nome{
	[campos]
	tipo nomeDoCampo;
}

struct SNovo{
	int numero;
	char sexo;
}
typedef struct SNovo TNovo;
*/
//Criando um estrutura e tipo numa única instrução
typedef struct SNovo{ 
	int numero; 
	char sexo;
} TNovo;

//struct SNovo aluno;
TNovo aluno;

int main(int argc, char **argv)
{
	scanf("%d",&aluno.numero);
	printf("Numero lido: %d",aluno.numero);

	return 0;
}

