#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hotel.h"

struct hotel{
    int id;
    char nome[100];
    char localizacao[100];
    char avaliacao[100];
};

struct no{
    Hotel cadastro;
    struct no *prox;
};

struct lista {
    struct no * inicio;
};

//Função para ler o cadastro
void lerCadastro(Hotel *h) {
  scanf("%d %s %s %s", &h->id, &h->nome[0], &h->localizacao[0], &h->avaliacao[0]);
  return;
}

//Função para cadastrar hotel
void adicionar(Lista *l, Hotel cadastro){
    struct no * novo = (struct no*) malloc (sizeof(struct no));
    novo->cadastro = cadastro;
    novo->prox = l->inicio;
    l->inicio = novo;
}

//Função para mostrar a lista de hoteis
void mostrar(Lista l){
    struct no * p;
    for (p = l.inicio; p != NULL; p = p->prox) {
        printf("%d %s %s %s\n", p->cadastro.id, p->cadastro.nome, p->cadastro.localizacao, p->cadastro.avaliacao);
    }
}

//Função para pesquisar hosteis na lista
struct no * pesquisar (Lista lista, int h) {
    struct no* pi;
    for (pi = lista.inicio; pi != NULL && pi->cadastro.id != h; pi = pi->prox);
    return pi;
}

//Função para deletar hotel da lista
void deletar (Lista *plista) {
    if (plista->inicio == NULL) {
        printf("Nao foi possivel deletar, a lista esta vazia...\n");
    }
    else {
        struct no* p = plista->inicio;
        plista->inicio = p->prox;
        free(p);
    }
}

//Função para alterar cadastro de hoteis
void alterar(Lista *plista, int h, char nome[], char localizacao[], char avaliacao[]) {
    struct no *pi = pesquisar(*plista, h);
    if(pi == NULL){
        printf("O hotel nao pode ser alterado!\n");
    }
    else{
        strcpy(pi->cadastro.nome, nome);
        strcpy(pi->cadastro.localizacao, localizacao);
        strcpy(pi->cadastro.avaliacao, avaliacao);
    }
}