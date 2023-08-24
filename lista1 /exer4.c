#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

Contato lista_contatos[MAX_CONTATOS];
int num_contatos = 0;

void adicionar_contato(char *nome, char *telefone) {
    if (num_contatos >= MAX_CONTATOS) {
        printf("Erro: lista de contatos cheia\n");
        return;
    }
    strcpy(lista_contatos[num_contatos].nome, nome);
    strcpy(lista_contatos[num_contatos].telefone, telefone);
    num_contatos++;
}

void listar_contatos() {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < num_contatos; i++) {
        printf("%s: %s\n", lista_contatos[i].nome, lista_contatos[i].telefone);
    }
}

void buscar_contato(char *nome) {
    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(lista_contatos[i].nome, nome) == 0) {
            printf("%s: %s\n", lista_contatos[i].nome, lista_contatos[i].telefone);
            return;
        }
    }
    printf("Contato nao encontrado\n");
}

int main() {
    adicionar_contato("Joao", "123-456-7890");
    adicionar_contato("Maria", "234-567-8901");
    listar_contatos();
    buscar_contato("Joao");
    buscar_contato("Pedro");
    return 0;
}
