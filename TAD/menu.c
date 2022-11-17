#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "hotel.c"
#include "quarto.h"

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
            printf("Insira os dados do hotel (ID, Nome, Localizacao e Avaliacao):\n");
            lerCadastro(&c);
            adicionar(&lista, c);
        }

        else if (op == 2) {
            int id;
            printf("Informe o registro que deseja excluir: ");
            scanf("%d", &id);
            deletarID(&lista, id);
        }

        else if (op == 3) {
            Beep(1000,500);
            printf("\n");
            printf("Mostrando lista de hoteis...\n");
            mostrar(lista);
        }

        else if (op == 4) {
            Beep(1000,500);
            int h=0;
            printf("Informe o ID do hotel que deseja encontrar: ");
             scanf("%d", &h);
             struct no * pi = pesquisar(lista, h);
             if (pi != NULL) {
                 printf("Hotel encontrado!\n");
                 printf("%d %s %s %s\n", pi->cadastro.id, &pi->cadastro.nome, &pi->cadastro.localizacao, &pi->cadastro.avaliacao);
             }
             else {
                 printf("Hotel nao encontrado...\n");
             }
         }
         
         else if(op == 5) {
            Beep(1000,500);
            int h;
            char nome[100];
            char localizacao[100];
            char avaliacao[100];
            Hotel *cadastro;

            printf("Digite o ID do hotel: ");
            scanf("%d", &h);
            printf("Digite o novo nome do hotel: ");
            scanf("%s", nome);
            printf("Digite a nova localizacao do hotel: ");
            scanf("%s", localizacao);
            printf("Digite a nova avaliacao do hotel: ");
            scanf("%s", avaliacao);
            alterar(&lista, h, nome, localizacao, avaliacao);
        }
         
        op = menu();
    }
    return 0;
    }