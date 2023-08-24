#include <stdio.h>
#include <string.h>
#include <time.h>


struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
    struct tm dataAdmissao;
};

void darAumento(struct Funcionario *funcionario, float percentualAumento) {
    if (percentualAumento > 0) {
        float aumento = (percentualAumento / 100.0) * funcionario->salario;
        funcionario->salario += aumento;
        printf("%s recebeu um aumento de %.2f%% e agora tem um salario de %.2f\n",
               funcionario->nome, percentualAumento, funcionario->salario);
    } else {
        printf("Percentual de aumento inválido.\n");
    }
}

int calcularTempoNaEmpresa(struct Funcionario funcionario) {
    time_t agora;
    time(&agora);
    struct tm *dataAtual = localtime(&agora);

    int anos = dataAtual->tm_year - funcionario.dataAdmissao.tm_year;
    int meses = dataAtual->tm_mon - funcionario.dataAdmissao.tm_mon;

    if (meses < 0) {
        anos--;
        meses += 12;
    }

    return anos;
}

int main() {
    struct Funcionario funcionario1;

   
    strcpy(funcionario1.nome, "Joao");
    strcpy(funcionario1.cargo, "Analista");
    funcionario1.salario = 5000.0;
    funcionario1.dataAdmissao.tm_year = 120;
    funcionario1.dataAdmissao.tm_mon = 0;   
    funcionario1.dataAdmissao.tm_mday = 1;  

    darAumento(&funcionario1, 10.0); 

    int anosNaEmpresa = calcularTempoNaEmpresa(funcionario1);
    printf("%s esta na empresa ha %d anos.\n", funcionario1.nome, anosNaEmpresa);

    return 0;
}
