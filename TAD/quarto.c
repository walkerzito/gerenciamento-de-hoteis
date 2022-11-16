#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hotel.h"
#include "quarto.h"

struct quarto{
    char tipo[100];
    float preco;
    int disp;
};

struct no2{
    Quarto cadastro2;
    struct no2 *prox;
};

struct lista2 {
    struct no2 * inicio;
};


void lerCadastro2(Quarto *q){
  scanf("%s %f %d", &q->tipo, &q->preco, &q->disp);
  return;
}

void adicionar2(Lista2 *l, Quarto cadastro2){
    struct no2 * novo = (struct no2*) malloc (sizeof(struct no2));
    novo->cadastro2 = cadastro2;
    novo->prox = l->inicio;
    l->inicio = novo;

        FILE *arq2 = fopen("Quartos.txt", "a");
    if(arq2 == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fprintf(arq2, "Tipo: %d \n Preco: %s\n Disponibilidade: %s", cadastro2.tipo, cadastro2.preco, cadastro2.disp);

    fclose(arq2);
    
    return cadastro2;
}