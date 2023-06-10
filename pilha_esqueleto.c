#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
    int valor;
    struct no *proximo;
};

typedef struct pilha Pilha;

struct pilha{
    struct no *ini;
    struct no *fim;
    int tam;
};

void inicializar_pilha(Pilha *pilha);

void inserir_no_fim(Pilha *pilha, int num);

No* remover_no_topo(Pilha *pilha);

void imprimir_pilha(Pilha *pilha);

void inicializar_pilha(Pilha *pilha){
    pilha->ini=NULL;
    pilha->fim=NULL;
    pilha->tam=0;
}

void inserir_no_fim(Pilha *pilha, int num){
    No *novo_no=(No*)malloc(sizeof(No));
    if(novo_no){
        novo_no->valor=num;
        if(pilha->ini == NULL){
            pilha->ini=novo_no;
            pilha->fim=novo_no;
            novo_no->proximo=NULL;
            pilha->tam++;
        }
        else{
            pilha->fim->proximo=novo_no;
            pilha->fim=novo_no;
            novo_no->proximo=NULL;
            pilha->tam++;
        }
    }
}

No* remover_no_topo(Pilha *pilha){
    No *aux, *remover=NULL;
    if(pilha->ini){
        if(pilha->ini == pilha->fim){
            remover=pilha->ini;
            pilha->ini=NULL;
            pilha->fim=NULL;
            pilha->tam--;
        }
        else{
            aux=pilha->ini;
            do{
                if(pilha->fim == aux->proximo){
                    remover=aux->proximo;
                    aux->proximo=remover->proximo;
                    pilha->fim=aux;
                }
                aux=aux->proximo;
            }while(aux != NULL);
            pilha->tam--;     
        }
    }
    return remover;
}

void imprimir_pilha(Pilha *pilha){
    No *aux;
    aux=pilha->ini;
    printf("\n\tPilha tam %d: \n",pilha->tam);
    printf("\n\tTopo da Pilha: %d\n\n",pilha->fim->valor);
    if(pilha->ini){
        int tam=0,i=0;
        tam=pilha->tam;
        int *vet=(int*)malloc(tam*sizeof(int));
        aux=pilha->ini;
        do{
            vet[i]=aux->valor;
            aux=aux->proximo;
            i++;
        }while(aux != NULL);
        for(i=tam-1;i>=0;i--){
            printf("\t       %d\n",vet[i]);
        }
        printf("\n\tInicio da Pilha: %d\n",pilha->ini->valor);
    }
    else{
        printf("A pilha esta vazia\n");
    }
    printf("\n\n");
}