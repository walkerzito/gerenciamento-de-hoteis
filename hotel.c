#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hotel{
    char nome[100];
    char localizacao[100];
    char avaliacao[100];
}Hotel;

struct no{
    Hotel cadastro;
    struct no *prox;
};

typedef struct lista {
    struct no * inicio;
}Lista;

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

// struct no * pesquisar (Lista lista, int n) {
//     struct no* p;
//     for (p = lista.inicio; p != NULL && p->cadastro.nome != n; p = p->prox);
//     return p;
// }

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

int menu () {
    printf("\n");
    printf("MENU INICIAL\n");
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

//Fun��o principal
int main() {
    Lista lista;
    lista.inicio = NULL;

    int op = menu();

    while (op != 8) {

        if (op == 1) { 
            Hotel c;
            printf("\n");
            printf("Insira os dados do hotel (Nome, Localizacao e Avaliacao):\n");
            lerCadastro(&c);
            inserirInicio(&lista, c);
        }

        else if (op == 2) {
            deletarInicio(&lista);
        }

        else if (op == 3) {
            printf("\n");
            printf("Mostrando lista de hoteis...\n");
            mostrar(lista);
        }

        // else if (op == 4) {
        //     int h;
        //     printf("Informe o hotel que deseja encontrar: ");
        //     scanf("%d", &h);
        //     struct no * p = pesquisar(lista, h);
        //     if (p != NULL) {
        //         printf("Hotel encontrado!\n");
        //         printf("%s %s %s\n", &p->cadastro.nome[0], &p->cadastro.localizacao[0], &p->cadastro.avaliacao[0]);
        //     }
        //     else {
        //         printf("Hotel nao encontrado...\n");
        //     }
        // }
        op = menu();
    }
    return 0;
    }