#include <stdio.h> // Biblioteca padrao de entrada e saida
#include <string.h> //biblioteca para manipulacao de strings
#include <stdlib.h> // Biblioteca que inclui funcoes de conversão e alocação de memoria
#include <ctype.h> // Biblioteca para funcoes de manipulação de caracteres

#define semana 1      // função define quantidade de semanas ficticias (ex: 1 semana = 7 dias)
#define dias_da_semana 7      // funcao define dias na semana
#define qtd_pracas 4       // funcao define quantidade de praças de pedagio

// Função para ler float com validacao (tarifas)
float lerFloat(const char *mensagem) {   // Aqui a funcao le um numero float com validacao, assegurando que a entrada seja um numero valido.(TRATATIVA DE ERRO)
    char buffer[100];
    float valor;
    int valido = 0;

    while (!valido) {   // aqui o loop continua ate que um numero valido seja inserido
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {   
            printf("Erro na leitura. Tente novamente.\n");
            continue;
        }

        // remover quebra de linha
        buffer[strcspn(buffer, "\n")] = '\0';

        // aqui checa-se caracteres validos (ddgitos, ponto decimal e espaço)
        int i, temNumero = 0, erro = 0;
        for (i = 0; buffer[i] != '\0'; i++) {
            if (!(isdigit((unsigned char)buffer[i]) || buffer[i] == '.' || buffer[i] == ' ')) {
                erro = 1;
                break;
            }
            if (isdigit((unsigned char)buffer[i])) temNumero = 1; // aqui chamamos a funcao isdigit para verificar se ha pelo menos um digito
        }

        if (erro || !temNumero) {
            printf("Voce nao digitou um numero. (Permitidos somente numeros e pontos)\n");
            continue;
        }

        // aqui tentamos converter a string para float, para ver se e um numero valido
        if (sscanf(buffer, "%f", &valor) != 1) {
            printf("Voce nao digitou um numero valido.\n");
            continue;
        }

        valido = 1; // numero valido
    }

    return valor;
}

// Função para ler int com validação, para ler a quantidade de carros
int lerInt(const char *mensagem) {
    char buffer[100];
    int valor;
    int valido = 0;

    while (!valido) { // aqui o loop continua até que um numero valido seja inserido
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura. Tente novamente.\n");
            continue;
        }

        // remover quebra de linha
        buffer[strcspn(buffer, "\n")] = '\0';

        // checar se todos os caracteres são digitos, para isso usamos a função isdigit
        int i, erro = 0, temNumero = 0;
        for (i = 0; buffer[i] != '\0'; i++) {
            if (!isdigit((unsigned char)buffer[i])) {
                erro = 1;
                break;
            }
            temNumero = 1;
        }

        if (erro || !temNumero) {
            printf("Voce nao digitou um numero inteiro valido. (Permitidos somente numeros inteiros)\n");
            continue;
        }

        // tenta converter a string para int
        if (sscanf(buffer, "%d", &valor) != 1) {
            printf("Voce nao digitou um numero valido.\n");
            continue;
        }

        valido = 1;
    }

    return valor;
}


// Aqui começamos o programa principal, declarando variaveis e matrizes necessarias para armazenar os dados.
int main() {
    char nome[30];
    int cars[semana][dias_da_semana][qtd_pracas]; // semana, dia, praça
    float tarifa[qtd_pracas]; // tarifa por praça
    int i, j, k; // variaveis de controle para loops
    int total_carros_dia[semana][dias_da_semana] = {0}; // total de carros por dia
    float arrecadacao_dia[semana][dias_da_semana] = {0.0}; // arrecadacao por dia
    int total_carros_semana[semana] = {0}; // total de carros por semana
    float arrecadacao_semana[semana] = {0.0}; // arrecadacao por semana

    int total_geral_carros = 0; // total geral de carros
    float arrecadacao_geral = 0.0; // arrecadacao geral

    printf("---- Sistema de pedagio / semana  ----\n\n");
    printf("Digite seu nome: "); // Aqui pedimos o nome do usuario
    fgets(nome, sizeof(nome), stdin); // Aqui lemos o nome com fgets, que e mais seguro que scanf
    nome[strcspn(nome, "\n")] = 0; // remove \n

    printf("Bem vindo %s\n\n", nome); // exibimos o nome do usuario e uma mensagem de saudacao


    // Definir tarifas por praça, aqui usamos o for para iterar sobre cada praça e solicitar a tarifa correspondente.
    for (k = 0; k < qtd_pracas; k++) {
        char mensagem[50];
        sprintf(mensagem, "Digite a tarifa da praca %d (R$): ", k+1);
        tarifa[k] = lerFloat(mensagem);
    }

    // Entrada de dados: carros por semana/dia/praça
    for (i = 0; i < semana; i++) {
        printf("\n>>> Semana %d\n", i+1);
        for (j = 0; j < dias_da_semana; j++) {
            printf("  Dia %d:\n", j+1);
            for (k = 0; k < qtd_pracas; k++) {
                char mensagem[50];
                sprintf(mensagem, "    Carros na praca %d: ", k+1);
                cars[i][j][k] = lerInt(mensagem);

                total_carros_dia[i][j] += cars[i][j][k];
                arrecadacao_dia[i][j] += cars[i][j][k] * tarifa[k];
            }
            total_carros_semana[i] += total_carros_dia[i][j];
            arrecadacao_semana[i] += arrecadacao_dia[i][j];
            total_geral_carros += total_carros_dia[i][j];
            arrecadacao_geral += arrecadacao_dia[i][j];
        }
    }

    // Aqui usamos uma formula simples para calcular a media diaria de arrecadacao.
    float media_diaria = arrecadacao_geral / (semana * dias_da_semana);

    // Aqui começamos a gerar os relatorios, começando pelo relatorio diario.
    printf("\n---- Relatorio / diario ----\n");
    printf("\n Colaborador: %s.\n", nome);
    printf("Semana - Dia - Carros - Arrecadacao (R$) - Classificacao\n");
    printf("______________________________________________________________\n");
    for (i = 0; i < semana; i++) {
        for (j = 0; j < dias_da_semana; j++) {
            const char *classificacao = (arrecadacao_dia[i][j] > media_diaria) ? "DIA DE PICO" : "DIA NORMAL";
            printf("%6d | %3d | %6d | %16.2f | %s\n",
                   i+1, j+1, total_carros_dia[i][j], arrecadacao_dia[i][j], classificacao);
        }
    }

    // Aqui geramos o relatorio semanal, resumindo os dados por semana.
    printf("\n---- Relatorio / semana ----\n");
    printf("\n Colaborador: %s.\n", nome);
    printf("Semana - Total Carros - Arrecadacao (R$)\n");
    printf("________________________________________\n");
    for (i = 0; i < semana; i++) {
        printf("%6d | %12d | %15.2f\n", i+1, total_carros_semana[i], arrecadacao_semana[i]);
    }

    // Totais gerais
    printf("\n---- Relatorio Total ----\n");
    printf("\n Colaborador: %s.\n", nome);
    printf("Periodo analisado: %d semanas (%d dias)\n", semana, semana*dias_da_semana);
    printf("Total de carros: %d\n", total_geral_carros);
    printf("Arrecadacao total: R$%.2f\n", arrecadacao_geral);
    printf("Media diaria de arrecadacao: R$%.2f\n", media_diaria);

    printf("\nPrograma encerrado.\n");
    return 0;
}
