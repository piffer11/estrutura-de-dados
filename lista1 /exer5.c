#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100

typedef struct {
    char titulo[50];
    char autor[50];
    int ano_publicacao;
} Livro;

Livro lista_livros[MAX_LIVROS];
int num_livros = 0;

void adicionar_livro(char *titulo, char *autor, int ano_publicacao) {
    if (num_livros >= MAX_LIVROS) {
        printf("Erro: lista de livros cheia\n");
        return;
    }
    strcpy(lista_livros[num_livros].titulo, titulo);
    strcpy(lista_livros[num_livros].autor, autor);
    lista_livros[num_livros].ano_publicacao = ano_publicacao;
    num_livros++;
}

void listar_livros() {
    printf("Lista de Livros:\n");
    for (int i = 0; i < num_livros; i++) {
        printf("%s por %s, publicado em %d\n", lista_livros[i].titulo, lista_livros[i].autor, lista_livros[i].ano_publicacao);
    }
}

void buscar_livro(char *autor) {
    printf("Livros por %s:\n", autor);
    for (int i = 0; i < num_livros; i++) {
        if (strcmp(lista_livros[i].autor, autor) == 0) {
            printf("%s, publicado em %d\n", lista_livros[i].titulo, lista_livros[i].ano_publicacao);
        }
    }
}

int main() {
    adicionar_livro("Dom Casmurro", "Machado de Assis", 1899);
    adicionar_livro("Memorias Postumas de Bras Cubas", "Machado de Assis", 1881);
    listar_livros();
    buscar_livro("Machado de Assis");
    return 0;
}
