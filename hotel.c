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

void lerCadastro(Hotel *c) {
  scanf("%s %s %s", &c->nome, c->localizacao, c->avaliacao);
  return;
}

void inserirInicio (Lista *l, Hotel cadastro) {
    struct no * novo = (struct no*) malloc (sizeof(struct no));
    novo->cadastro = cadastro;
    novo->prox = l->inicio;
    l->inicio = novo;
}

void mostrar (Lista l) {
    struct no * p;
    for (p = l.inicio; p != NULL; p = p->prox) {
        printf("%s %s %s\n", p->cadastro.nome, p->cadastro.localizacao, p->cadastro.avaliacao);
    }
}

int menu () {
    printf("\n");
    printf("MENU INICIAL\n");
    printf("1- Adicionar hotel\n");
    printf("2- Remover hotel\n");
    printf("3- Listar Hoteis cadastrados\n");
    printf("4- Buscar Hotel\n");
    printf("5- Editar cadastro\n");
    printf("6- Consultar quartos disponiveis em um dado hotel\n");
    printf("7- Consultar quantitativo de quartos por hoteis\n");
    printf("8- Sair\n");

    printf("Digite a sua opcao: ");

    int op;

    scanf("%d", &op);

    return op;
}