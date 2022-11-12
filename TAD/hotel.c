#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hotel.h"

struct hotel{
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

void lerCadastro(Hotel *h) {
  scanf("%s %s %s", &h->nome[0], &h->localizacao[0], &h->avaliacao[0]);
  return;
}

void inserirInicio(Lista *l, Hotel cadastro){
    struct no * novo = (struct no*) malloc (sizeof(struct no));
    novo->cadastro = cadastro;
    novo->prox = l->inicio;
    l->inicio = novo;
}

void mostrar(Lista l){
    struct no * p;
    for (p = l.inicio; p != NULL; p = p->prox) {
        printf("%s %s %s\n", p->cadastro.nome, p->cadastro.localizacao, p->cadastro.avaliacao);
    }
}

 struct no * pesquisar (Lista lista, int n) {
     struct no* p;
     for (p = lista.inicio; p != NULL && p->cadastro.nome != n; p = p->prox);
     return p;
 }

void deletarInicio (Lista *plista) {
    if (plista->inicio == NULL) {
        printf("Nao foi possivel deletar, a lista esta vazia...\n");
    }
    else {
        struct no* p = plista->inicio;
        plista->inicio = p->prox;
        free(p);
    }
}