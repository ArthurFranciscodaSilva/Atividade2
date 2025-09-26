#include <stdio.h>
#include <string.h>


int main() {
    char nome[30]; // para armazenar o nome do cliente
    char pedido[100][50]; // até 100 itens, cada um com até 50 caracteres
    char buffer[50];  // para armazenar entrada do usuário
    float precos[100]; // para armazenar os preços dos itens, já convertidos para float
    int qtd_itens = 0; // para armazenar a quantidade de itens no pedido, em números inteiros
    float total = 0.0f; // para armazenar o total do pedido, em float
    int opcao;  // para armazenar a opção do menu, em números inteiros
    
    printf("Bem vindo ao restaurante Mucho Gusto\n");
    printf("Por favor, digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; // remove \n

    printf("Aguarde um momento %s, enquanto localizo sua reserva confira nosso menu!\n\n", nome);

// laço do para o menu principal
    do {
        printf("1 - Entradas\n");
        printf("2 - Pratos principais\n");
        printf("3 - Sobremesas\n");
        printf("4 - Bebidas\n");
        printf("5 - Remover item do pedido\n");
        printf("6 - Visualizar pedido atual\n");
        printf("7 - Sair\n");
        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &opcao);
        
    fgets(buffer, sizeof(buffer), stdin);  // fgets par ler a string, chamando o buffer, que é o que usuário digitou e foi armazenado na variável buffer

// tenta converter para número (checagem para ver se o usuario digitou um numero)
    if (sscanf(buffer, "%d", &opcao) != 1) {   
    }


// checagem se o numero está dentro do intervalo válido    
    if (opcao < 1 || opcao > 7) {
        printf("Opcao invalida, (opcoes validas 1 ao 7)\n\n");
        continue; // volta para o menu
    }
    
    

    // esse if é a condição para a opção 1, caso o usuário escolha 1 no menu principal, será exibido na interface o menu de entradas
    // dentro dele também temos um laço de repetição do-while, que exibe o menu de entradas até o usuário escolher a opção de voltar ao menu anterior
    // dentro do laço, temos uma série de if-else para cada opção do menu, que serve para adicionar cada item quando o usuário escolhe. 
    if (opcao == 1) {
        int entrada;
        char buffer[50]; // para capturar a entrada como string

        do {
            printf("\n--- Entradas ---\n");
            printf("1 - Salada Caesar (R$12.00)\n");
            printf("2 - Caldinho de feijao (R$10.00)\n");
            printf("3 - Pastel de queijo gouda (R$8.00)\n");
            printf("4 - Carne de onca (R$15.00)\n");
            printf("5 - Voltar ao menu anterior\n");
            printf("Digite sua escolha: ");

        // lê entrada como string
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Erro ao ler entrada.\n");
                continue; // volta para o início do laço
            }

        // tenta converter para número
            if (sscanf(buffer, "%d", &entrada) != 1) {
                printf("Voce nao digitou um numero valido. Tente novamente.\n");
                continue;
            }

        // valida se está dentro do intervalo 1–5
            if (entrada < 1 || entrada > 5) {
                printf("Opcao invalida. Digite um numero entre 1 e 5.\n");
                continue;
            }

        // só cai aqui se for número válido entre 1 e 5
            if (entrada == 1) {
                strcpy(pedido[qtd_itens], "Salada Caesar");
                precos[qtd_itens] = 12.00f;
                qtd_itens++;
                total += 12.00f;
            } else if (entrada == 2) {
                strcpy(pedido[qtd_itens], "Caldinho de feijao");
                precos[qtd_itens] = 10.00f;
                qtd_itens++;
                total += 10.00f;
            } else if (entrada == 3) {
                strcpy(pedido[qtd_itens], "Pastel de queijo gouda");
                precos[qtd_itens] = 8.00f;
                qtd_itens++;
                total += 8.00f;
            } else if (entrada == 4) {
                strcpy(pedido[qtd_itens], "Carne de onca");
                precos[qtd_itens] = 15.00f;
                qtd_itens++;
                total += 15.00f;
            }

        } while (entrada != 5); // só sai quando o usuário digita 5
    }




    // condição para a opção 2, caso o usuário escolha 2 no menu principal, será exibido na interface o menu de pratos principais
    // dentro dele também temos um laço de repetição do-while, que exibe o menu de pratos principais até o usuário escolher a opção de voltar ao menu anterior
    // dentro do laço, temos uma série de if-else para cada opção do menu



        else if (opcao == 2) {
            int entrada;
            char buffer[50]; // para capturar a entrada como string

            do {
                printf("\n--- Pratos principais ---\n");
                printf("1 - Risoto de camarao (R$25.00)\n");
                printf("2 - Escondidinho de carne seca (R$22.00)\n");
                printf("3 - Carbonara (R$20.00)\n");
                printf("4 - Yakissoba (R$18.00)\n");
                printf("5 - Voltar ao menu anterior\n");
                printf("Digite sua escolha: ");
                
                // lê entrada como string
                if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                    printf("Erro ao ler entrada.\n");
                    continue; // volta para o início do laço
                }

        // tenta converter para número
                if (sscanf(buffer, "%d", &entrada) != 1) {
                    printf("Voce nao digitou um numero valido. Tente novamente.\n");
                    continue;
                }

        // valida se está dentro do intervalo 1–5
                if (entrada < 1 || entrada > 5) {
                    printf("Opcao invalida. Digite um numero entre 1 e 5.\n");
                    continue;
                }    

                if (entrada == 1) {
                    strcpy(pedido[qtd_itens], "Risoto de camarao");
                    precos[qtd_itens] = 25.00f;
                    qtd_itens++;
                    total += 25.00f;
                } else if (entrada == 2) {
                    strcpy(pedido[qtd_itens], "Escondidinho de carne seca");
                    precos[qtd_itens] = 22.00f;
                    qtd_itens++;
                    total += 22.00f;
                } else if (entrada == 3) {
                    strcpy(pedido[qtd_itens], "Carbonara");
                    precos[qtd_itens] = 20.00f;
                    qtd_itens++;
                    total += 20.00f;
                } else if (entrada == 4) {
                    strcpy(pedido[qtd_itens], "Yakissoba");
                    precos[qtd_itens] = 18.00f;
                    qtd_itens++;
                    total += 18.00f;
                }
            } while (entrada != 5);
        }



    // condição para a opção 3, caso o usuário escolha 3 no menu principal, será exibido na interface o menu de sobremesas
    // dentro dele também temos um laço de repetição do-while, que exibe o menu de sobremesas até o usuário escolher a opção de voltar ao menu anterior
    // dentro do laço, temos uma série de if-else para cada opção do menu




        else if (opcao == 3) {
        int entrada;
        char buffer[50];

        do {
            printf("\n--- Sobremesas ---\n");
            printf("1 - Petit Gateau (R$12.00)\n");
            printf("2 - Sorvete de cafe (R$9.00)\n");
            printf("3 - Mousse de chocolate (R$10.00)\n");
            printf("4 - Pudim de leite (R$8.00)\n");
            printf("5 - Voltar ao menu anterior\n");
            printf("Digite sua escolha: ");

        // lê entrada como string
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Erro ao ler entrada.\n");
                continue;
            }

        // tenta converter para número
            if (sscanf(buffer, "%d", &entrada) != 1) {
                printf("Voce nao digitou um numero valido. Tente novamente.\n");
                continue;
            }

        // valida intervalo
            if (entrada < 1 || entrada > 5) {
                printf("Opcao invalida. Digite um numero entre 1 e 5.\n");
                continue;
            }

        // adiciona ao pedido
            if (entrada == 1) {
                strcpy(pedido[qtd_itens], "Petit Gateau");
                precos[qtd_itens] = 12.00f;
                qtd_itens++;
                total += 12.00f;
            } else if (entrada == 2) {
                strcpy(pedido[qtd_itens], "Sorvete de cafe");
                precos[qtd_itens] = 9.00f;
                qtd_itens++;
                total += 9.00f;
            } else if (entrada == 3) {
                strcpy(pedido[qtd_itens], "Mousse de chocolate");
                precos[qtd_itens] = 10.00f;
                qtd_itens++;
                total += 10.00f;
            } else if (entrada == 4) {
                strcpy(pedido[qtd_itens], "Pudim de leite");
                precos[qtd_itens] = 8.00f;
                qtd_itens++;
                total += 8.00f;
            }

        } while (entrada != 5); // só sai quando o usuário digita 5
}



        // condição para a opção 4, caso o usuário escolha 4 no menu principal, será exibido na interface o menu de bebidas
        // dentro dele também temos um laço de repetição do-while, que exibe o menu de bebidas até o usuário escolher a opção de voltar ao menu anterior
        // dentro do laço, temos uma série de if-else para cada opção do menu


        else if (opcao == 4) {
        int entrada;
        char buffer[50];

        do {
            printf("\n--- Bebidas ---\n");
            printf("1 - Refrigerantes\n");
            printf("2 - Sucos naturais\n");
            printf("3 - Cervejas\n");
            printf("4 - Vinhos\n");
            printf("5 - Voltar ao menu anterior\n");
            printf("Digite sua escolha: ");

        // lê entrada como string
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Erro ao ler entrada.\n");
                continue;
            }

        // tenta converter para número
            if (sscanf(buffer, "%d", &entrada) != 1) {
                printf("Voce nao digitou um numero valido. Tente novamente.\n");
                continue;
            }

        // valida intervalo
            if (entrada < 1 || entrada > 5) {
                printf("Opcao invalida. Digite um numero entre 1 e 5.\n");
                continue;
            }

        // SUBMENU: Refrigerantes
            if (entrada == 1) {
                int refri;
                do {
                    printf("\n--- Refrigerantes ---\n");
                    printf("1 - Coca-cola (R$6.00)\n");
                    printf("2 - Guarana Antarctica (R$5.50)\n");
                    printf("3 - Fanta Laranja (R$5.50)\n");
                    printf("4 - Sprite (R$5.50)\n");
                    printf("5 - Voltar\n");
                    printf("Digite sua escolha: ");

                    if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
                    if (sscanf(buffer, "%d", &refri) != 1 || refri < 1 || refri > 5) {
                        printf("Opcao invalida. Digite um numero entre 1 e 5.\n");
                        continue;
                    }

                    if (refri == 1) { strcpy(pedido[qtd_itens], "Coca-cola"); precos[qtd_itens] = 6.00f; qtd_itens++; total += 6.00f; }
                    else if (refri == 2) { strcpy(pedido[qtd_itens], "Guarana Antarctica"); precos[qtd_itens] = 5.50f; qtd_itens++; total += 5.50f; }
                    else if (refri == 3) { strcpy(pedido[qtd_itens], "Fanta Laranja"); precos[qtd_itens] = 5.50f; qtd_itens++; total += 5.50f; }
                    else if (refri == 4) { strcpy(pedido[qtd_itens], "Sprite"); precos[qtd_itens] = 5.50f; qtd_itens++; total += 5.50f; }

                } while (refri != 5);
            }

        // SUBMENU: Sucos naturais
            else if (entrada == 2) {
                int suco;
                do {
                    printf("\n--- Sucos Naturais ---\n");
                    printf("1 - Laranja (R$7.00)\n");
                    printf("2 - Abacaxi (R$7.00)\n");
                    printf("3 - Maracuja (R$7.00)\n");
                    printf("4 - Limao (R$7.00)\n");
                    printf("5 - Voltar\n");
                    printf("Digite sua escolha: ");

                    if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
                    if (sscanf(buffer, "%d", &suco) != 1 || suco < 1 || suco > 5) {
                        printf("Opcao invalida. Digite um numero entre 1 e 5.\n");
                        continue;
                    }

                    if (suco == 1) { strcpy(pedido[qtd_itens], "Suco de Laranja"); precos[qtd_itens] = 7.00f; qtd_itens++; total += 7.00f; }
                    else if (suco == 2) { strcpy(pedido[qtd_itens], "Suco de Abacaxi"); precos[qtd_itens] = 7.00f; qtd_itens++; total += 7.00f; }
                    else if (suco == 3) { strcpy(pedido[qtd_itens], "Suco de Maracuja"); precos[qtd_itens] = 7.00f; qtd_itens++; total += 7.00f; }
                    else if (suco == 4) { strcpy(pedido[qtd_itens], "Suco de Limao"); precos[qtd_itens] = 7.00f; qtd_itens++; total += 7.00f; }

                } while (suco != 5);
            }

        // SUBMENU: Cervejas
            else if (entrada == 3) {
                int cerveja;
                do {
                    printf("\n--- Cervejas ---\n");
                    printf("1 - Heineken (R$12.00)\n");
                    printf("2 - Budweiser (R$10.00)\n");
                    printf("3 - Stella Artois (R$11.00)\n");
                    printf("4 - Eisenbahn (R$14.00)\n");
                    printf("5 - Voltar\n");
                    printf("Digite sua escolha: ");

                    if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
                    if (sscanf(buffer, "%d", &cerveja) != 1 || cerveja < 1 || cerveja > 5) {
                        printf("Opcao invalida. Digite um numero entre 1 e 5.\n");
                        continue;
                    }

                    if (cerveja == 1) { strcpy(pedido[qtd_itens], "Heineken"); precos[qtd_itens] = 12.00f; qtd_itens++; total += 12.00f; }
                    else if (cerveja == 2) { strcpy(pedido[qtd_itens], "Budweiser"); precos[qtd_itens] = 10.00f; qtd_itens++; total += 10.00f; }
                    else if (cerveja == 3) { strcpy(pedido[qtd_itens], "Stella Artois"); precos[qtd_itens] = 11.00f; qtd_itens++; total += 11.00f; }
                    else if (cerveja == 4) { strcpy(pedido[qtd_itens], "Eisenbahn"); precos[qtd_itens] = 14.00f; qtd_itens++; total += 14.00f; }

                } while (cerveja != 5);
            }

        // SUBMENU: Vinhos
            else if (entrada == 4) {
                int vinho;
                do {
                    printf("\n--- Vinhos ---\n");
                    printf("1 - Tinto (R$30.00)\n");
                    printf("2 - Branco (R$28.00)\n");
                    printf("3 - Rose (R$26.00)\n");
                    printf("4 - Espumante (R$35.00)\n");
                    printf("5 - Voltar\n");
                    printf("Digite sua escolha: ");

                    if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
                    if (sscanf(buffer, "%d", &vinho) != 1 || vinho < 1 || vinho > 5) {
                        printf("Opcao invalida. Digite um numero entre 1 e 5.\n");
                        continue;
                    }

                    if (vinho == 1) { strcpy(pedido[qtd_itens], "Vinho Tinto"); precos[qtd_itens] = 30.00f; qtd_itens++; total += 30.00f; }
                    else if (vinho == 2) { strcpy(pedido[qtd_itens], "Vinho Branco"); precos[qtd_itens] = 28.00f; qtd_itens++; total += 28.00f; }
                    else if (vinho == 3) { strcpy(pedido[qtd_itens], "Vinho Rose"); precos[qtd_itens] = 26.00f; qtd_itens++; total += 26.00f; }
                    else if (vinho == 4) { strcpy(pedido[qtd_itens], "Espumante"); precos[qtd_itens] = 35.00f; qtd_itens++; total += 35.00f; }

                } while (vinho != 5);
            }

        } while (entrada != 5);
}

        

    // condição para a opção 5, que permite ao usuário remover um item do pedido
    // se não houver itens no pedido, uma mensagem será exibida
    // caso contrário, o pedido atual será exibido e o usuário poderá escolher qual item remover
    // após a remoção, o total será atualizado    




        else if (opcao == 5) {
            if (qtd_itens == 0) {
                printf("\nNenhum item para remover.\n");
            } else {
                printf("\n--- Itens do pedido ---\n");
                for (int i = 0; i < qtd_itens; i++) {
                    printf("%d - %s (R$%.2f)\n", i+1, pedido[i], precos[i]);
                }
                int remover;
                printf("Digite o numero do item que deseja remover: ");
                scanf("%d", &remover);
                if (remover > 0 && remover <= qtd_itens) {
                    total -= precos[remover-1];
                    for (int i = remover-1; i < qtd_itens-1; i++) {
                        strcpy(pedido[i], pedido[i+1]);
                        precos[i] = precos[i+1];
                    }
                    qtd_itens--;
                    printf("Item removido com sucesso!\n");
                } else {
                    printf("Opcao invalida.\n");
                }
            }
        }

        // condição para a opção 6, que exibe o pedido atual do usuário
        // se não houver itens no pedido, uma mensagem será exibida
        // caso contrário, todos os itens do pedido serão listados junto com o total até o momento




        else if (opcao == 6) {
            printf("\n--- Pedido atual ---\n");
            if (qtd_itens == 0) {
                printf("Nenhum item escolhido.\n");
            } else {
                for (int i = 0; i < qtd_itens; i++) {
                    printf("%d - %s (R$%.2f)\n", i+1, pedido[i], precos[i]);
                }
                printf("\n Total ate agora: R$%.2f\n\n", total);
            } // fecha o else do pedido atual
            
    } // fecha o if das opções do menu principal        
    }while (opcao != 7);  // fecha o do principal



    // aqui é o fechamento do pedido, exibindo todos os itens escolhidos e o total final
    // o usuário então escolhe a forma de pagamento, que pode ser crédito ou débito
    // uma mensagem de confirmação é exibida após a escolha do pagamento
    // finalmente, uma mensagem de agradecimento é exibida ao usuário

    printf("\n--- Fechamento da conta ---\n");
    printf("Itens pedidos:\n");
    for (int i = 0; i < qtd_itens; i++) {
        printf("%d - %s (R$%.2f)\n", i+1, pedido[i], precos[i]);
    }
    printf("Total final: R$%.2f\n\n", total);

    // aqui nós pedimos a forma de pagamento
    int pagamento;
    do {
        printf("Escolha a forma de pagamento:\n");
        printf("1 - Credito\n");
        printf("2 - Debito\n");
        printf("Digite sua escolha: ");
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;


        //tenta converter para número e valida intervalo, para garantir que o usuário digite uma opção válida
        if (sscanf(buffer, "%d", &pagamento) != 1 || pagamento < 1 || pagamento > 2) {
            printf("Opcao invalida. Digite 1 para Credito ou 2 para Debito.\n");
            pagamento = 0; // força repetir o laço
            continue;
        }

        // pagamento válido, aqui simula o processamento do pagamento
        if (pagamento == 1) {
            printf("Pagamento no credito realizado com sucesso!\n");
        } else if (pagamento == 2) {
            printf("Pagamento no debito realizado com sucesso!\n");
        }

    } while (pagamento != 1 && pagamento != 2);

    printf("Agradecemos pela preferencia! Volte sempre!, %s!\n", nome);
    return 0;
}
