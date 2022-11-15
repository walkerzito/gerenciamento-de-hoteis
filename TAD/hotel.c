#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hotel.h"
// #include "quarto.h"

struct hotel{
    // Quarto *quarto;
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
void lerCadastro(Hotel *h){
  scanf("%d %s %s %s", &h->id, &h->nome[0], &h->localizacao[0], &h->avaliacao[0]);
  return;
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
    fprintf(arq, "ID: %d \n Nome: %s\n Localização: %s\n Avaliação: %s", cadastro.id, cadastro.nome, cadastro.localizacao, cadastro.avaliacao);

    fclose(arq);
    
    return cadastro;
}

//Função para mostrar a lista de hoteis
void mostrar(Lista l){
    struct no * p;
    for (p = l.inicio; p != NULL; p = p->prox) {
        printf("%d %s %s %s\n", p->cadastro.id, p->cadastro.nome, p->cadastro.localizacao, p->cadastro.avaliacao);
    }
}

//Função para pesquisar hosteis na lista
struct no * pesquisar(Lista lista, int h){
    struct no* pi;
    for (pi = lista.inicio; pi != NULL && pi->cadastro.id != h; pi = pi->prox);
    return pi;
}

//Função para deletar hotel da lista
void deletarID(Lista *lista, int id) {
    //Inicio == NULL
    if (lista->inicio == NULL) {
        printf("Nao e possivel deletar, a lista esta vazia...\n");
    }
    //Nó se encontra no ínicio
    else if (lista->inicio->cadastro.id == id) {
        struct no* pi = lista->inicio;
        lista->inicio = pi->prox;
        free(pi);
    }
    //Lista tem um único nó, registro não existe
    else if (lista->inicio->prox == NULL) {
        if (lista->inicio->cadastro.id != id) {
            printf("Nao e possivel deletar, o registro nao existe...\n");
        }
    }
    //Lista tem vários nós, registro existe
    //Lista tem vários nós, registro não existe
    else {
        struct no * pa;
        struct no * pi;
        for (pi = lista->inicio; pi != NULL && pi->cadastro.id != id; pi = pi->prox) {
            pa = pi;
        }
        if (pi == NULL) {
            printf("Nao e possivel deletar, o registro nao existe...\n");
        }
        else {
            pa->prox = pi->prox;
            free(pi);
        }
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

    FILE *arquivo = fopen("GerenciamentoDeHoteis.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    FILE *arquivoTemp = fopen("GerenciamentoDeHoteis.txt", "w");
    if (arquivoTemp == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivoTemp, "ID: %d \n Nome: %s\n Localização: %s\n Avaliação: %s", pi->cadastro.id, pi->cadastro.nome, pi->cadastro.localizacao, pi->cadastro.avaliacao);

    fclose(arquivo);
    fclose(arquivoTemp);
}

//Funcão para consultar disponibilidade de quartos em dado hotel
void disp(Lista *l, int h){
    struct no *pi = pesquisar(*l, h);
    if(pi == NULL){
        printf("O hotel nao pode ser encontrado!\n");
    }
    else{

    }
}

//Funcão para consultar quantitativo de quartos por hoteis
void quant(Lista *l, int h){

}