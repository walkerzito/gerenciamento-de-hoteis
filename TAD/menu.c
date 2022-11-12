#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hotel.c"

int menu () {
    printf("\n");
    printf("BP HOTEIS\n");
    printf("1- Adicionar hotel\n");
    printf("2- Remover hotel\n");
    printf("3- Listar hoteis\n");
    printf("4- Buscar hotel\n");
    printf("5- Editar cadastro\n");
    printf("6- Consultar quarto disponiveis em dado hotel\n");
    printf("7- Consultar quantitativo de quartos por hoteis\n");
    printf("8- Sair\n");

    printf("Digite a sua opcao: ");

    int op;

    scanf("%d", &op);

    return op;
}

//Funcao principal
int main() {
    Lista lista;
    lista.inicio = NULL;

    int op = menu();

    while (op != 8) {
        
        if (op == 1) { 
            Beep(1000,500);
            Hotel c;
            printf("\n");
            printf("Insira os dados do hotel (Nome, Localizacao e Avaliacao):\n");
            lerCadastro(&c);
            inserirInicio(&lista, c);
        }

        else if (op == 2) {
            Beep(1000,500);
            deletarInicio(&lista);
        }

        else if (op == 3) {
            Beep(1000,500);
            printf("\n");
            printf("Mostrando lista de hoteis...\n");
            mostrar(lista);
        }

        else if (op == 4) {
            int h;
            printf("Informe o hotel que deseja encontrar: ");
             scanf("%d", &h);
             struct no * p = pesquisar(lista, h);
             if (p != NULL) {
                 printf("Hotel encontrado!\n");
                 printf("%s %s %s\n", &p->cadastro.nome[0], &p->cadastro.localizacao[0], &p->cadastro.avaliacao[0]);
             }
             else {
                 printf("Hotel nao encontrado...\n");
             }
         }
         
        op = menu();
    }
    return 0;
    }