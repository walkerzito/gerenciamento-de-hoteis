typedef struct hotel Hotel;
typedef struct lista Lista;
void lerCadastro(Hotel *h);
void inserirInicio(Lista *l, Hotel cadastro);
void mostrar(Lista l);
void deletarInicio (Lista *plista);
struct no * pesquisar (Lista lista, int h);
void alterar(Lista *plista, int h, char nome[]);