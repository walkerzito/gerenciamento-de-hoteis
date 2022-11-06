#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.c"

int main() {
    Lista l;
    l.inicio = NULL;

    int op = menu();

    while (op != 19) {

        if (op == 1) { 
            Hotel h;
            printf("\n");
            printf("Insira os dados do hotel(Nome, localizacao e avaliacao)\n");
            lerCadastro(&h);
            inserirInicio(&l, h);
        }

        else if (op == 3) {
            printf("\n");
            printf("Mostrando lista de Clientes...\n");
            mostrar(l);
        }
    }
}