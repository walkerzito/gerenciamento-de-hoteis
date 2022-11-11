#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  scanf("%s %s %s", &h->nome, h->localizacao, h->avaliacao);
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
