#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

float calcularTotalCompra(struct Produto produtos[], int indices[], int quantidades[], int numItens) {
    float total = 0.0;

    for (int i = 0; i < numItens; i++) {
        int indice = indices[i];
        int quantidade = quantidades[i];

        if (indice >= 0 && indice < numItens && quantidade > 0) {
            if (produtos[indice].quantidadeEstoque >= quantidade) {
                total += produtos[indice].preco * quantidade;
                produtos[indice].quantidadeEstoque -= quantidade;
                printf("Produto: %s, Quantidade: %d, Preço Unitário: %.2f, Total: %.2f\n",
                       produtos[indice].nome, quantidade, produtos[indice].preco, produtos[indice].preco * quantidade);
            } else {
                printf("Estoque insuficiente para o produto: %s\n", produtos[indice].nome);
            }
        } else {
            printf("Índice ou quantidade inválidos para o produto.\n");
        }
    }

    return total;
}

int main() {
    struct Produto produtos[3];

    strcpy(produtos[0].nome, "Produto A");
    produtos[0].preco = 10.0;
    produtos[0].quantidadeEstoque = 20;

    strcpy(produtos[1].nome, "Produto B");
    produtos[1].preco = 15.0;
    produtos[1].quantidadeEstoque = 15;

    strcpy(produtos[2].nome, "Produto C");
    produtos[2].preco = 5.0;
    produtos[2].quantidadeEstoque = 30;

    int numItens;
    printf("Quantos itens você deseja comprar? ");
    scanf("%d", &numItens);

    int indices[numItens];
    int quantidades[numItens];

    printf("Digite o número e quantidade de cada item que deseja comprar:\n");

    for (int i = 0; i < numItens; i++) {
        printf("Item %d (0 a %d):\n", i + 1, numItens - 1);
        scanf("%d", &indices[i]);
        printf("Quantidade: ");
        scanf("%d", &quantidades[i]);
    }

    float totalCompra = calcularTotalCompra(produtos, indices, quantidades, numItens);

    printf("Total da compra: %.2f\n", totalCompra);

    return 0;
}
