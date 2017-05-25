#include <stdio.h>
#include <stdlib.h>

//Levi Almeida da Silva


struct cliente{
	char nome[30];
	int cpf;
};

struct newNode{
	struct newNode *ant;
	struct cliente dados;
	struct newNode *prox;
};
typedef struct newNode* Lista;		//Apelido da cabe�a.
typedef struct  newNode Elem;		//Apelido a um n� qualquer ou de uma "cabe�a auxiliar".




			//M�todos auxiliares
//Informa o tamanho da lista
int tamanho_lista(Lista* li){
	if(li == NULL){
		return 0;
	}
	int cont = 0;
	Elem*no = *li;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}

//Verifica se a lista est� vazia
int lista_vazia(Lista *li){
	if(li == NULL){
		return 1;
	}
	if(*li == NULL){
		return 1;
	}
	return 0;
}

//Insere no inicio da lista duplamente encadeada
int insere_lista_inicio(Lista *li, struct cliente c){
	if(li == NULL){
		return 0;
	}
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = c;
	no->prox = (*li);
	no->ant = NULL;
	if(*li != NULL){
		(*li)->ant = no;
	}
	*li = no;
	return 1;
}


//Insere no final da lista duplamente encadeada
int insere_lista_final(Lista* li, struct cliente c){
	if(li == NULL){
		return 0;
	}
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = c;
	no->prox = NULL;
	if((*li) == NULL){				//lista vazia: insere no inicio
		no->ant = NULL;
		*li = no;
	}else{
		Elem *aux = *li;
		while(aux->prox != NULL){	//percorre at� o final da lista(que ser� o ex-final)
			aux = aux->prox;
		}
		aux->prox = no;
		no->ant = aux;
	}
	return 1;
}

//Insere no meio da lista
int insere_lista_meio(Lista* li, struct cliente c, int pos){
	if(li == NULL){
		return 0;
	}
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) {
		return 0;
	}
	no->dados = c;
	if(lista_vazia(li)){
		no->ant = NULL;
		*li = no;
		return 1;
	}else{
	int cont1 = 0;
	int cont2 = 0;
	Elem* auxAnt = *li;
	Elem* auxPost = *li;
	while(cont1 != (pos-1)){
		auxAnt = auxAnt->prox;
		cont1++;
	}
	while(cont2 != (pos)){
		auxPost	= auxPost->prox;
		cont2++;
	}
	auxAnt->prox = no;
	no->ant = auxAnt;
	no->prox = auxPost;
	auxPost->ant = no;
	}
	return 1;
}




			//M�todos da lista de exerc�cios
//Cria uma lista duplamente encadeada.
Lista*	Criar lista vazia(){
	Lista* li = (Lista*) malloc (sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}
	return li;
}

//Insere um cliente em ma posi��o qualquer da lista.
int Inserir_um_elemento_em_qualquer_posicao_da_lista(Lista* li, struct cliente c, int pos){
	int x = tamanho_lista(li);
	if (pos == 0 || pos > x){
		insere_lista_inicio(li,c);
	}
	if (0 < pos && pos < x){
		insere_lista_meio(li,c,pos);
	}
	if (pos == x){
		insere_lista_final(li,c);
	}
}


//Retorna a posi��o de um elemento na lista duplamente encadeada.
int Buscar_a_posicao_de_um_elemento_na_lista(Lista* li, struct cliente c){
	if(li == NULL){
		return -1;
	}
	Elem *no = *li;
	int cont = 0;
	while(no != NULL && no->dados.cpf != c.cpf){						//no != NULL e no->prox != NULL tem quase o mesmo significado.
		cont++;
		no = no->prox;
	}
	if(no == NULL){
		return -1;
	}else{
		return cont;
	}
}




//Imprime todos os elementos da lista
void Imprimir_todos_os_elementos_da_lista(lista* li){
	if(li == NULL){
		return;
	}
	Elem* aux = *li;
	int i = 0;
	while(no != NULL){
		printf("Nome do cliente %d: %s\n", (i+1), aux->dados.nome);
		i++;
		aux = aux->prox;
	}
}

//Deleta uma lista duplamente encadeada
void Deletar_lista(Lista *li){
	if(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}




			//Main
int main(){


}

