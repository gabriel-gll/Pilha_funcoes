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

int main(){
    Pilha *pilha=(Pilha*)malloc(sizeof(Pilha));
    int n=0,num=0;
    No *removido=NULL;
    inicializar_pilha(pilha);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir no topo da Pilha\n\t2 - Remover no topo da Pilha\n\t3 - Imprimir\n");
        scanf("%d",&n);

        switch(n){
            case 0:
                printf("Essa e a saida do programa\n");
                break;
            case 1:
                printf("Insercao no topo da Pilha, digite o valor: \n");
                scanf("%d",&num);
                inserir_no_fim(pilha,num);
                break;
            case 2:
                removido=remover_no_topo(pilha);
                if(removido != NULL){
                    printf("Foi removido o elemento com o valor %d\n",removido->valor);
                }
                break;
            case 3:
                imprimir_pilha(pilha);
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(n != 0);
    return 0;
}

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
            printf("\t       | %d |\n",vet[i]);
        }
        printf("\n\tInicio da Pilha: %3d\n",pilha->ini->valor);
    }
    else{
        printf("A pilha esta vazia\n");
    }
    printf("\n\n");
}