typedef struct hotel Hotel;
typedef struct lista Lista;
void lerCadastro(Hotel *h);
void adicionar(Lista *l, Hotel cadastro);
void mostrar(Lista l);
void deletarID(Lista *plista, int id);
struct no * pesquisar (Lista lista, int h);
void alterar(Lista *plista, int h, char nome[], char localizacao[], char avaliacao[]);