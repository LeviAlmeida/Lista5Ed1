#include <stdio.h>
#include <stdlib.h>

//Levi Almeida da Silva


struct cliente{
	char nome[30];
	int cpf;
};

struct fila{						//Duas cabe�as.
	struct newNode* inicio;
	struct newNode* final;
};

struct newNode{
	struct cliente dados;
	struct newNode *prox;
};

typedef struct fila Fila;			//Apelido das duas cabe�as.
typedef struct  newNode Elem;		//Apelido a um n� qualquer ou de uma "cabe�a auxiliar".



			//M�todos auxiliares
//Informa o tamanho da Fila
int tamanho_fila(Fila* fi){
	if(fi == NULL){
		return 0;
	}
	int cont = 0;
	Elem* no = fi->inicio;			//�o precisa ser ponteiro. Ponteiro � o conteudo da cabe�a, e fi->inicio � tamb�m um dos conte�dos da cabe�a.
	while(no != NULL){				//Enquanto a cabe�a inicial auxiliar ainda n�o � o �ltimo elemento da fila fa�a:
		cont++;
		no = no->prox;
	}
	return cont;
}


//verificar se a fila est� vazia
int fila_vazia(Fila* fi){
	if(fi == NULL){
		return 1;
	}
	if(fi->inicio == NULL){
		return 1;
	}
	return 0;
}


//imprimi a fila
void Imprimir_fila(fila* fi){
	if(fi == NULL){
		return;
	}
	Elem* aux = fi->inicio;
	int i = 0;
	while(aux != NULL){
		printf("Nome do cliente %d: %s\n", (i+1), aux->dados.nome);
		i++;
		aux = aux->prox;
	}
}



			//M�todos da lista de exerc�cios
//Cria uma Fila vazia
Fila* Criar_fila_vazia(){
	Fila* fi = (Fila*) malloc(sizeof(Fila));			//Aloca espa�o para um as cabe�as.
	if(fi != NULL){
		fi->final = NULL;
		fi->inicio = NULL;
	}
	return fi;
}

//Insere um elemento no final da fila (FIFO = first in, first out)
int Inserir_um_elemento_em_qualquer_na_fila(Fila* fi, struct cliente c){
	if(fi == NULL){
		return 0;
	}
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = c;
	no->prox = NULL;									//Caracterizando ser o �ltimo elemento.
	if(fi->final == NULL){								//Caracterizando uma lista vazia. J� que o fi->final aponta para o �ltimo elemento
		fi->inicio = no;								//inicio aponta para o no, porque ele � o primeiro e ultimo.
	} else{
		fi->final->prox = no;							//o pr�ximo do �ltimo aponta para nulo.
	}
	fi->final = no;										//a caba�e final ponta para o �ltimo elemento(no).
	return 1;
}

//Remove um elemento de uma pilha (FIFO = first in, first out)
//Levi
int Remover_um_elemento_da_fila(Fila* fi){
	if(fi == NULL){
		return 0;
	}
	if(fi->inicio == NULL){								//indicador de fila vazia.
		return 0;
	}
	Elem *no = fi->inicio;
	fi->inicio = fi->inicio->prox;
	int cpfRemovido = no->dados.cpf;
	if(fi->inicio == NULL){								//se a lista ficou vazia
		fi->final = NULL;
	}
	free(no);
	return cpfRemovido;
}

//Delata uma Fila
void Deletar_fila(Fila* fi){
	if(fi != NULL){
		Elem* no;
		while(fi->inicio != NULL){						//Basta criar uma cabe�a inicial auxiliar e percorrer, deletando um a um. Depois deleta as duas cabe�as.
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}


			//Main
int main(){
	struct cliente ana = {"ana", 100};
	struct cliente bia = {"bia", 101};
	struct cliente isa = {"isa", 102};
	struct cliente lar = {"lar", 103};
	struct cliente Levi = {"Lev", 104};


	Fila *fi = Criar_fila_vazia();
	printf("-----------------------------------------\n");
	printf("-----	-----	Inserir	-----	-----\n");
	Inserir_um_elemento_em_qualquer_na_fila(fi, ana);
	Imprimir_fila(fi);
	printf("-----------------------------------------\n");
	printf("-----	-----	Inserir	-----	-----\n");
	Inserir_um_elemento_em_qualquer_na_fila(fi, bia);
	Imprimir_fila(fi);
	printf("-----------------------------------------\n");
	printf("-----	-----	Inserir	-----	-----\n");
	Inserir_um_elemento_em_qualquer_na_fila(fi, isa);
	Imprimir_fila(fi);
	printf("-----------------------------------------\n");
	printf("-----	-----	Remover	-----	-----\n");
	int x = Remover_um_elemento_da_fila(fi);
	printf("Cpf Removido: %d\n", x);
	Imprimir_fila(fi);

}
