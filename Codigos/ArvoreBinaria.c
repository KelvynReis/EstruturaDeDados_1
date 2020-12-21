#include <stdio.h>
#include <stdlib.h>

// arvore binaria de busca para encontrar numeros repetidos em um arquivo de entrada em que cada 
// numero se encontra  numa linha separa

typedef struct nodetype{
	int info;
	struct nodetype *left;
	struct nodetype *right;
} *nodeptr; // tipo da struct

int main(){
	

	nodeptr *ptree;
	nodeptr p, q;
	
	int number;
	
	scanf("%d",& number);
	ptree = maketree(number);
	
	while( scanf("%d",&number) != EOF){
		
		p = q = ptree;
		
		while( number != p->info && q != NULL){
			p = q;
			if(number < p->info)
				q = p->left;
			else
			 q = p->right;
		}
		
		if(number == p->info)
			printf("\n %d esta repetido: ", number);
		else if(number < p->info)
			setleft(p, number); // setleft(p,x) define um nó com o conteudo (number) "x" como fiho esquerdo de node(p)
		else
			setright(p,number);  // setright(p,x) para criar um filho direito de node(p) com o conteúdo "x" (number)
	}
	
	return 0;
}

