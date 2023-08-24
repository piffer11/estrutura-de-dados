#include <stdio.h>
#include <string.h>

struct ContaBancaria {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Deposito de %.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor de deposito invalido.\n");
    }
}

void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor de saque invalido ou saldo insuficiente.\n");
    }
}

float verificarSaldo(struct ContaBancaria conta) {
    return conta.saldo;
}

int main() {
    struct ContaBancaria minhaConta;

    strcpy(minhaConta.nomeTitular, "Joao Silva");
    minhaConta.numeroConta = 12345;
    minhaConta.saldo = 1000.0;

    depositar(&minhaConta, 500.0);
    sacar(&minhaConta, 200.0);
    float saldoAtual = verificarSaldo(minhaConta);
    printf("Saldo atual da conta de %s: %.2f\n", minhaConta.nomeTitular, saldoAtual);

    return 0;
}
