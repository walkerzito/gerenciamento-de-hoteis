#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hotel.h"

struct hotel{
    int quartos;
    int id;
    char nome[100];
    char localizacao[100];
    char avaliacao[100];
};

struct no{
    Hotel cadastro;
    struct no *prox;
};

struct lista{
    struct no * inicio;
};

//Função para ler o cadastro
void lerCadastro(Hotel *h){
  scanf("%d %s %s %d %s", &h->id, &h->nome[0], &h->localizacao[0], &h->quartos, &h->avaliacao[0]);
}

//Função para cadastrar hotel
void adicionar(Lista *l, Hotel cadastro){
    struct no * novo = (struct no*) malloc (sizeof(struct no));
    novo->cadastro = cadastro;
    novo->prox = l->inicio;
    l->inicio = novo;

        FILE *arq = fopen("GerenciamentoDeHoteis.txt", "a");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fprintf(arq, "ID: %d \n Nome: %s\n Quartos: %d \n Localização: %s \n Avaliação: %s", cadastro.id, cadastro.nome, cadastro.quartos, cadastro.localizacao, cadastro.avaliacao);

    fclose(arq);

}

//Função para mostrar a lista de hoteis
void mostrar(Lista l){
    struct no * p;
    for (p = l.inicio; p != NULL; p = p->prox) {
        printf("%d %s %s %s\n", p->cadastro.id, p->cadastro.nome);
    }
}

//Função para pesquisar hosteis na lista
struct no * pesquisar(Lista lista, int h){
    struct no* pi;
    for (pi = lista.inicio; pi != NULL && pi->cadastro.id != h; pi = pi->prox);
    return pi;
}

//Função para deletar hotel da lista
void deletarID(Lista *lista, int id){

    Hotel cadastro;

    if(lista->inicio == NULL){
        printf("Nao e possivel deletar, a lista esta vazia...\n");
    }
    else if (lista->inicio->cadastro.id == id) {
        struct no* pi = lista->inicio;
        lista->inicio = pi->prox;
        free(pi);
    }
    else if (lista->inicio->prox == NULL){
        if(lista->inicio->cadastro.id != id){
            printf("Nao e possivel deletar, o registro nao existe...\n");
        }
    }
    else{
        struct no * pa;
        struct no * pi;
        for (pi = lista->inicio; pi != NULL && pi->cadastro.id != id; pi = pi->prox) {
            pa = pi;
        }

        FILE *arquivo = fopen("GerenciamentoDeHoteis.txt", "a+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");

    }

    FILE *arquivoTemp = fopen("GerenciamentoDeHoteis.txt", "w");
    if (arquivoTemp == NULL) {
        printf("Erro ao abrir o arquivo");

    }

    fprintf(arquivoTemp, "ID: %d \n Nome: %s\n Localização: %s\n Avaliação: %s", pi->cadastro.id, pi->cadastro.nome, pi->cadastro.localizacao, pi->cadastro.avaliacao);

    fclose(arquivo);
    fclose(arquivoTemp);

        if (pi == NULL){
            printf("Nao e possivel deletar, o registro nao existe...\n");
        }
        else{
            pa->prox = pi->prox;
            free(pi);
            
}
    }
    
        }


//Função para alterar cadastro de hoteis
void alterar(Lista *plista, int h, char nome[], char localizacao[], char avaliacao[]){
    struct no *pi = pesquisar(*plista, h);
    if(pi == NULL){
        printf("O hotel nao pode ser alterado!\n");
    }
    else{
        strcpy(pi->cadastro.nome, nome);
        strcpy(pi->cadastro.localizacao, localizacao);
        strcpy(pi->cadastro.avaliacao, avaliacao);
    }

    FILE *arquivo = fopen("GerenciamentoDeHoteis.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");

    }

    FILE *arquivoTemp = fopen("GerenciamentoDeHoteis.txt", "w");
    if (arquivoTemp == NULL) {
        printf("Erro ao abrir o arquivo");

    }

    fprintf(arquivoTemp, "ID: %d \n Nome: %s\n Localização: %s\n Avaliação: %s", pi->cadastro.id, pi->cadastro.nome, pi->cadastro.localizacao, pi->cadastro.avaliacao);

    fclose(arquivo);
    fclose(arquivoTemp);
}
    
    //Função para consultar quantitativo de quarto por hoteis
void quant(Lista l){
    struct no * p;
    for (p = l.inicio; p != NULL; p = p->prox) {
        printf("%d", p->cadastro.quartos);
    }
}
