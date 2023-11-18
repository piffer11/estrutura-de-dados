#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/*define duas estruturas: Roupa, Cliente e fornecedor. Cada uma representa um tipo de dado que 
pode ser utilizado para armazenar informações sobre roupas e clientes, respectivamente.*/
typedef struct {
    char descricao[50];
    char tipo[30];
    char tamanho[10];
    float preco;
    char marca[30];
    char cor[20];
} Roupa;

typedef struct {
    char nome[50];
    int idade;
    char email[50];
    char telefone[15];
    char endereco[100];
    char uf[3];
} Cliente;

typedef struct {
    char nome[50];
    char enderecoEletronico[50];
    char email[50];
    char telefone[15];
    char endereco[100];
    char uf[3];
} Fornecedor;

/*Essa parte do código declara as funções que serão utilizadas posteriormente no programa. 
Cada função tem uma responsabilidade específica, como listar roupas, listar clientes, 
listar clientes de um estado específico, ordenar roupas por preço e ordenar clientes por nome.*/
void listarRoupas(Roupa roupas[], int n);
void listarClientes(Cliente clientes[], int n);
void listarFornecedores(Fornecedor fornecedores[], int n);
void listarClientesEstado(Cliente clientes[], int n, char estado[]);
void ordenarRoupasPorPreco(Roupa roupas[], int n);
void ordenarClientesPorNome(Cliente clientes[], int n);
void ordenarFornecedoresPorNome(Fornecedor fornecedores[], int n);

int main() {
    // Registrar 3 roupas, 3 clientes e 3 fornecedores
    Roupa roupas[] = {
        {"Camiseta", "Manga Curta", "M", 29.99, "MarcaA", "Azul"},
        {"Calça Jeans", "Jeans", "36", 79.99, "MarcaB", "Azul"},
        {"Vestido", "Curto", "P", 49.99, "MarcaC", "Vermelho"}
    };

    Cliente clientes[] = {
        {"Cliente1", 25, "cliente1@email.com", "123456789", "Endereco1", "SP"},
        {"Cliente2", 30, "cliente2@email.com", "987654321", "Endereco2", "RJ"},
        {"Cliente3", 22, "cliente3@email.com", "111222333", "Endereco3", "MG"}
    };

     Fornecedor fornecedores[] = {
        {"Fornecedor1", "enderecoEletronico1", "fornecedor1@email.com", "111111111", "Endereco4", "SP"},
        {"Fornecedor2", "enderecoEletronico2", "fornecedor2@email.com", "222222222", "Endereco5", "RJ"},
        {"Fornecedor3", "enderecoEletronico3", "fornecedor3@email.com", "333333333", "Endereco6", "MG"}
    };

    /*Dentro de um loop do-while, o programa exibe um menu para o usuário com várias opções. 
    A escolha do usuário é lida usando scanf e, em seguida, entra em um bloco switch para 
    executar o código correspondente à escolha feita.*/
    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1. Listar todas as roupas\n");
        printf("2. Listar todos os clientes\n");
        printf("3. Listar os clientes de um determinado estado\n");
        printf("4. Listar todas as roupas em ordem crescente de preço\n");
        printf("5. Listar todos os clientes em ordem crescente de nome\n");
        printf("6. Listar todos os fornecedores\n");
        printf("7. Listar os fornecedores em ordem crescente de nome\n");
        printf("0. Sair\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &escolha);

        /*Nessa estrutura switch, o código executa diferentes blocos de código com base
        na escolha do usuário. Para cada opção, uma função específica é chamada. As opções
        incluem listar roupas, listar clientes, listar clientes de um estado específico, 
        ordenar roupas por preço, ordenar clientes por nome e sair do programa.*/
        switch (escolha) {
            case 1:
                listarRoupas(roupas, sizeof(roupas) / sizeof(roupas[0]));
                break;
            case 2:
                listarClientes(clientes, sizeof(clientes) / sizeof(clientes[0]));
                break;
            case 3:
                {
                    char estado[3];
                    printf("Digite o estado: ");
                    scanf("%s", estado);
                    listarClientesEstado(clientes, sizeof(clientes) / sizeof(clientes[0]), estado);
                }
                break;
            case 4:
                ordenarRoupasPorPreco(roupas, sizeof(roupas) / sizeof(roupas[0]));
                listarRoupas(roupas, sizeof(roupas) / sizeof(roupas[0]));
                break;
            case 5:
                ordenarClientesPorNome(clientes, sizeof(clientes) / sizeof(clientes[0]));
                listarClientes(clientes, sizeof(clientes) / sizeof(clientes[0]));
                break;
            case 6:
                listarFornecedores(fornecedores, sizeof(fornecedores) / sizeof(fornecedores[0]));
                break;
            case 7:
                ordenarFornecedoresPorNome(fornecedores, sizeof(fornecedores) / sizeof(fornecedores[0]));
                listarFornecedores(fornecedores, sizeof(fornecedores) / sizeof(fornecedores[0]));
                break;
            case 0:
                printf("Encerrando o programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (escolha != 0);
    printf("Encerrando o programa. Até mais!\n");
    getchar();  // Aguarda uma tecla antes de encerrar

    return 0;
}



// Implementação das funções
/*A função listarRoupas é responsável por exibir as informações de todas as roupas presentes no array de roupas*/
void listarRoupas(Roupa roupas[], int n) {
    printf("\nLista de Roupas:\n");
    // Inicia um loop for que percorre todas as roupas no array.
    for (int i = 0; i < n; i++) {
        printf("Descrição: %s\n", roupas[i].descricao);
        printf("Tipo: %s\n", roupas[i].tipo);
        printf("Tamanho: %s\n", roupas[i].tamanho);
        printf("Preço: R$%.2f\n", roupas[i].preco);
        printf("Marca: %s\n", roupas[i].marca);
        printf("Cor: %s\n\n", roupas[i].cor);
    }
}
/*A função listarClientes tem como objetivo exibir as informações de todos os clientes presentes no array de clientes.*/
void listarClientes(Cliente clientes[], int n) {
    printf("\nLista de Clientes:\n");
    // Inicia um loop for que percorre todos os clientes no array.
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("E-mail: %s\n", clientes[i].email);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Endereço: %s\n", clientes[i].endereco);
        printf("UF: %s\n\n", clientes[i].uf);
    }
}

/*A função listarFornecedores é responsável por exibir na tela as informações dos
 fornecedores armazenadas em um array de estruturas do tipo Fornecedor.*/
void listarFornecedores(Fornecedor fornecedores[], int n) {
    printf("\nLista de Fornecedores:\n");
    // Inicia um loop for que percorre todos os fornecedores no array.
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", fornecedores[i].nome);
        printf("Endereço Eletrônico: %s\n", fornecedores[i].enderecoEletronico);
        printf("E-mail: %s\n", fornecedores[i].email);
        printf("Telefone: %s\n", fornecedores[i].telefone);
        printf("Endereço: %s\n", fornecedores[i].endereco);
        printf("UF: %s\n\n", fornecedores[i].uf);
    }
}

/*A função listarClientesEstado tem como objetivo exibir as informações dos clientes que pertencem a um estado específico.*/
void listarClientesEstado(Cliente clientes[], int n, char estado[]) {
    printf("\nClientes do estado %s:\n", estado);
    // Inicia um loop for que percorre todos os clientes no array.
    for (int i = 0; i < n; i++) {
        /*Verifica se o estado do cliente na posição i é igual ao estado especificado. 
        strcmp compara duas strings e retorna 0 se forem iguais.*/
        if (strcmp(clientes[i].uf, estado) == 0) {
            printf("Nome: %s\n", clientes[i].nome);
            printf("E-mail: %s\n", clientes[i].email);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Endereço: %s\n", clientes[i].endereco);
            printf("UF: %s\n\n", clientes[i].uf);
        }
    }
}

/*A função ordenarRoupasPorPreco tem como objetivo ordenar o array de roupas com base no preço em ordem crescente. 
Ela utiliza o algoritmo de ordenação conhecido como Bubble Sort para realizar essa tarefa. */
void ordenarRoupasPorPreco(Roupa roupas[], int n) {
    // O primeiro loop for percorre todo o array de roupas.
    for (int i = 0; i < n - 1; i++) {
        /*O segundo loop for compara elementos adjacentes e os troca se estiverem fora de ordem. 
        O n - i - 1 é usado porque, após cada iteração do loop externo, o maior elemento já está no lugar correto.*/
        for (int j = 0; j < n - i - 1; j++) {
            //Compara os preços de duas roupas adjacentes.
            if (roupas[j].preco > roupas[j + 1].preco) {
                // Troca se a condição do passo 4 for verdadeira, ocorre a troca das posições das roupas no array.
                //Usa uma variável temporária (temp) para armazenar temporariamente a roupa na posição j.
                Roupa temp = roupas[j];
                //Move a roupa na posição j + 1 para a posição j.
                roupas[j] = roupas[j + 1];
                //Move a roupa armazenada em temp para a posição j + 1.
                roupas[j + 1] = temp;
            }
        }
    }
}

/*A função ordenarClientesPorNome tem como objetivo ordenar o array de clientes em ordem
alfabética crescente com base nos nomes dos clientes. Ela utiliza o algoritmo de ordenação
conhecido como Bubble Sort para realizar essa tarefa. */
/*Define a função chamada ordenarClientesPorNome que recebe um array de clientes (Cliente clientes[])
 e o número total de clientes no array (int n).*/
void ordenarClientesPorNome(Cliente clientes[], int n) {
    // O primeiro loop for percorre todo o array de clientes.
    for (int i = 0; i < n - 1; i++) {
        /*O segundo loop for compara elementos adjacentes e os troca se estiverem fora de ordem. 
        O n - i - 1 é usado porque, após cada iteração do loop externo, o maior elemento já está no lugar correto.*/
        for (int j = 0; j < n - i - 1; j++) {
            /*Compara os nomes de dois clientes adjacentes usando a função strcmp. Se o resultado for maior que zero,
            significa que o nome na posição j é maior (em ordem alfabética) do que o nome na posição j + 1.*/
            if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
                // Troca se a condição do passo 4 for verdadeira, ocorre a troca das posições dos clientes no array.
                //Usa uma variável temporária (temp) para armazenar temporariamente o cliente na posição j
                Cliente temp = clientes[j];
                //Move o cliente na posição j + 1 para a posição j.
                clientes[j] = clientes[j + 1];
                //Move o cliente armazenado em temp para a posição j + 1.
                clientes[j + 1] = temp;
            }
        }
    }
}

/*A função ordenarFornecedoresPorNome é responsável por ordenar um array de fornecedores com base no
campo nome de cada fornecedor. A ordenação é feita usando o algoritmo de ordenação conhecido como 
Bubble Sort, que compara elementos adjacentes e os troca se estiverem na ordem errada.*/
void ordenarFornecedoresPorNome(Fornecedor fornecedores[], int n) {
    // Este loop percorre todo o array de fornecedores.
    for (int i = 0; i < n - 1; i++) {
        /*Este loop compara elementos adjacentes e os troca se estiverem fora de ordem. 
        À medida que o loop externo avança, os maiores elementos "borbulham" para o final do array.*/
        for (int j = 0; j < n - i - 1; j++) {
            /*A função strcmp compara duas strings. Se o resultado for maior que zero, significa que
            a string em fornecedores[j].nome é maior do que a string em fornecedores[j + 1].nome, 
            indicando que a troca é necessária.*/
            if (strcmp(fornecedores[j].nome, fornecedores[j + 1].nome) > 0) {
                //As estruturas Fornecedor em fornecedores[j] e fornecedores[j + 1] são trocadas para reorganizar os elementos do array.
                Fornecedor temp = fornecedores[j];
                fornecedores[j] = fornecedores[j + 1];
                fornecedores[j + 1] = temp;
            }
 }
}
}
