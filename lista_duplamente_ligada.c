#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

struct No {
    int info;
    struct No* anterior;
    struct No* proximo;
};

struct ListaDupla {
    struct No* inicio;
    struct No* fim;
    int tamanho;
};

struct ListaDupla* criar() {
    struct ListaDupla* nova_lista = (struct ListaDupla*) malloc(sizeof(struct ListaDupla));
    if (nova_lista != NULL) {
        nova_lista->inicio = NULL;
        nova_lista->fim = NULL;
        nova_lista->tamanho = 0;
    }
    return nova_lista;
}

bool vazia(struct ListaDupla* li) {
    assert(li != NULL);     
    if (li->inicio == NULL) {
        return true;
    } else {
        return false;
    }
}

void inserir (struct ListaDupla* li, int pos, int item) {
    assert(li != NULL);
    assert(pos >= 0 && pos <= li->tamanho);

    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    novo_no->info = item;
    if (pos == 0) {
        novo_no->anterior = NULL;
        novo_no->proximo = li->inicio;
        li->inicio = novo_no; 
        if (li->fim == NULL) {
            li->fim = novo_no;
        } 
    } else if (pos == li->tamanho) { 
        novo_no->anterior = li->fim;
        novo_no->proximo = NULL;
	li->fim->proximo = novo_no;
        li->fim = novo_no;    
    } else {
       struct No* aux = li->inicio;
       for(int i = 0; i < pos - 1; i++) {
           aux = aux->proximo;
       }
       novo_no->anterior = aux;
       novo_no->proximo = aux->proximo;
       aux->proximo = novo_no;
    }
    li->tamanho++; 
}

void imprimir(struct ListaDupla* li) {
    assert(li != NULL);
    printf("\nLista: ");
    struct No* aux = li->inicio;
    while(aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->proximo;
    }
 }

int tamanho(struct ListaDupla* li) {
   assert(li != NULL);
   return li->tamanho;
}

int obter(struct ListaDupla* li, int pos) {
   assert(li != NULL);
   assert(pos >= 0 && pos < li->tamanho);
   struct No* aux;

   if (pos == 0) {
      aux = li->inicio;
   } else if (pos == li->tamanho - 1) {
      aux = li->fim;
   } else {
      aux = li->inicio;
      for(int i = 0; i < pos; i++) {
         aux = aux->proximo;
      }
   }
   return aux->info; 
}

int remover(struct ListaDupla* li, int pos) {
   assert(vazia(li) == false);
   assert(pos >= 0 && pos < li->tamanho);
   struct No* aux = NULL;

   if (pos == 0) {
       aux = li->inicio; 
       li->inicio = aux->proximo;
       if (li->inicio == NULL) {
           li->fim = NULL;
       } else {
           li->inicio->anterior = NULL;        
       }
   } else if (pos == li->tamanho - 1) {
       aux = li->fim;
       li->fim = aux->anterior;
       li->fim->proximo = NULL;        
   } else {
       struct No* ant = NULL;
       aux = li->inicio;
   
       for(int i = 0; i < pos; i++) {
            ant = aux;
            aux = aux->proximo;
       }

       ant->proximo = aux->proximo;
       aux->proximo->anterior = ant;    
    }

   int elemento = aux->info;
   li->tamanho--;
   free(aux);
   return elemento;
}

void liberar(struct ListaDupla* li) {
   while(vazia(li) == false) {
      remover(li, 0);
   }
   free(li);
}


int main() {
   struct ListaDupla* minha_lista = criar(); 
   inserir(minha_lista, 0, 5);      
   inserir(minha_lista, 0, 3);   
   inserir(minha_lista, 2, 6);   
   inserir(minha_lista, 1, 4);   
   return 0;
}
