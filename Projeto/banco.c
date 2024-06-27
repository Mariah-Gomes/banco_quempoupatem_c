#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// Função para acessar o menu cada vez que o programa rodar
void menu() {
  printf("MENU:\n");
  printf("1 - Novo Cliente\n");
  printf("2 - Apaga Cliente\n");
  printf("3 - Débito\n");
  printf("4 - Deposito\n");
  printf("5 - Extrato\n");
  printf("6 - Transferencia Entre Contas\n");
  printf("7 - Cartoes\n");
  printf("8 - Sair\n");
}

// Função para acessar o primeiro item do menu que seria cadastrar um cliente
void novo_cliente(cliente clientes[], int *total_clientes) {
  // Solicitando os dados do cliente e armazenando no struct criado
  printf("Digite o nome do cliente:\n");
  scanf("%s", clientes[*total_clientes].nome_cliente);
  printf("Digite o cpf do cliente:\n");
  scanf("%ld", &clientes[*total_clientes].cpf_cliente);
  printf("Digite o tipo de conta do cliente:\n");
  scanf("%s", clientes[*total_clientes].tipo_de_conta);
  printf("Digite o valor da conta:\n");
  scanf("%d", &clientes[*total_clientes].valor_inicial_conta);
  printf("Digite a senha do cliente:\n");
  scanf("%d", &clientes[*total_clientes].senha_cliente);
  // Armazenando os clientes criados em uma array
  (*total_clientes)++;
  printf("Cliente cadastrado com sucesso!\n");
}

// Função para acessar o segundo item do menu que seria apagar um cliente
void apaga_cliente(cliente clientes[], int *total_clientes) {
  int total;
  long cpf_cliente;
  // Solicitando os dados do cliente e armazenando no struct criado
  printf("Digite o cpf do cliente:\n");
  scanf("%ld", &cpf_cliente);
  // Analisando a posição do cliente
  for (int i = 0; i < total; i++) {
    if (clientes[i].cpf_cliente == cpf_cliente) {
      int indice_cliente = i;
      // Salvando um cliente em cima do outro
      for (int i = indice_cliente; i < (*total_clientes) - 1; i++) {
        clientes[i] = clientes[i + 1];
      }
    }
  }
  // Zerando o ultimo cliente para apagar ele
  memset(&clientes[(*total_clientes) - 1], 0, sizeof(cliente));
  (*total_clientes)--;
  printf("Cliente removido!\n");
}

// Função para acessar o debito item do menu que seria debitar da conta de um
// cliente
void debito(cliente clientes[], int total_clientes) {
  long cpf_cliente;
  int valor;
  int senha_cliente;
  int total;
  // Solicitando os dados do cliente
  printf("Digite o cpf do cliente:\n");
  scanf("%ld", &cpf_cliente);
  printf("Digite a senha do cliente:\n");
  scanf("%d", &senha_cliente);
  int posicao;
  //  Analisando a posição do cliente
  for (int i = 0; i < total_clientes; i++) {
    int posicao = i;
    // Selecionando o cliente na posição determinada que deseja atualizar o
    // valor
    if (clientes[posicao].cpf_cliente == cpf_cliente) {
      if (clientes[posicao].senha_cliente == senha_cliente) {
        printf("Digite o valor que vai ser debitado:\n");
        scanf("%d", &valor);
        // Alterando o valor da conta do cliente
        clientes[posicao].valor_inicial_conta =
            clientes[posicao].valor_inicial_conta - valor;
        printf("Debito realizado!\n");
        // Adicionando as operações do cliente no extrato
        sprintf(clientes[posicao].operacoes[clientes[posicao].total_operacoes],
                "Débito: %d", valor);
        clientes[posicao].total_operacoes++;
      }
    }
  }
}

// Função para acessar o deposito item do menu que seria debitar da conta de
// um cliente
void deposito(cliente clientes[], int total_clientes) {
  int total;
  long cpf_cliente;
  int valor;
  // Solicitando os dados do cliente
  printf("Digite o cpf do cliente:\n");
  scanf("%ld", &cpf_cliente);
  int posicao;
  //  Analisando a posição do cliente
  for (int i = 0; i < total_clientes; i++) {
    int posicao = i;
    // Selecionando o cliente na posição determinada que deseja atualizar o
    // valor
    if (clientes[posicao].cpf_cliente == cpf_cliente) {
      printf("Digite o valor que vai ser depositado:\n");
      scanf("%d", &valor);
      // Alterando o valor da conta do cliente
      clientes[posicao].valor_inicial_conta =
          clientes[posicao].valor_inicial_conta + valor;
      printf("Deposito realizado com sucesso!\n");
      // Adicionando as operações do cliente no extrato
      sprintf(clientes[posicao].operacoes[clientes[posicao].total_operacoes],
              "Deposito: %d", valor);
      clientes[posicao].total_operacoes++;
    }
  }
}
void extrato(cliente clientes[], int total_clientes) {
  long cpf_cliente;
  int senha_cliente;
  // Solicitando os dados do cliente
  printf("Digite o cpf do cliente:\n");
  scanf("%ld", &cpf_cliente);
  printf("Digite a senha do cliente:\n");
  scanf("%d", &senha_cliente);
  //  Analisando a posição do cliente
  int posicao;
  for (int i = 0; i < total_clientes; i++) {
    int posicao = i;
    // Selecionando o cliente na posição determinada que deseja atualizar o
    // valor
    if (clientes[posicao].cpf_cliente == cpf_cliente) {
      if (clientes[posicao].senha_cliente == senha_cliente) {
        for (int i = 0; i < clientes[posicao].total_operacoes; i++) {
          // Imprimindo o extrato
          printf("%s\n", clientes[posicao].operacoes[i]);
        }
      }
    }
  }
}
void transferencia(cliente clientes[], int total_clientes) {
  long cpf_cliente_origem;
  int senha_cliente;
  long cpf_cliente_destino;
  int valor;
  // Solicitando os dados do cliente
  printf("Digite o cpf do cliente de origem:\n");
  scanf("%ld", &cpf_cliente_origem);
  printf("Digite a senha do cliente de origem:\n");
  scanf("%d", &senha_cliente);
  printf("Digite o cpf do cliente de origem:\n");
  scanf("%ld", &cpf_cliente_destino);
  printf("Digite o valor que sera retirado da conta:\n");
  scanf("%d", &valor);
  int posicao;
  //  Analisando a posição do cliente
  for (int i = 0; i < total_clientes; i++) {
    int posicao_origem = i;
    // Selecionando o cliente na posição determinada que deseja atualizar o
    // valor
    if (clientes[posicao_origem].cpf_cliente == cpf_cliente_origem) {
      if (clientes[posicao_origem].senha_cliente == senha_cliente) {
        // Alterando o valor da conta do cliente
        clientes[posicao_origem].valor_inicial_conta =
            clientes[posicao_origem].valor_inicial_conta - valor;
        // Adicionando as operações do cliente no extrato
        sprintf(clientes[posicao].operacoes[clientes[posicao].total_operacoes],
                "Valor que retirou da transição: %d", valor);
      }
    }
  }
  //  Analisando a posição do cliente
  for (int i = 0; i < total_clientes; i++) {
    int posicao_destino = i;
    // Selecionando o cliente na posição determinada que deseja atualizar o
    // valor
    if (clientes[posicao_destino].cpf_cliente == cpf_cliente_destino) {
      // Alterando o valor da conta do cliente
      clientes[posicao_destino].valor_inicial_conta =
          clientes[posicao_destino].valor_inicial_conta + valor;
      // Adicionando as operações do cliente no extrato
      sprintf(clientes[posicao].operacoes[clientes[posicao].total_operacoes],
              "Valor que recebeu da transição: %d", valor);
      clientes[posicao_destino].total_operacoes++;
    }
  }
  printf("Transferência realizado com sucesso!\n");
}

// Função para acessar o sétimo item do menu que seria cadastrar um cartão
void cartao(cliente clientes[], int *total_clientes) {
  // Solicitando os dados do cliente e armazenando no struct criado
  printf("Digite o tipo de cartao que deseja adquirir:\n");
  scanf("%s", clientes[*total_clientes].tipo_de_cartao);
  printf("Digite o cpf do cliente:\n");
  scanf("%ld", &clientes[*total_clientes].cpf_cliente);
  printf("Digite a melhor data de vencimento do cartao:\n");
  scanf("%d", &clientes[*total_clientes].melhor_data_de_vencimento);
  char elementos[50];
  // Salvando em arquivo binário, mas de uma maneira que o usuário consiga
  // entender o arquivo
  FILE *f = fopen("cartoes.bin", "ab");
  sprintf(elementos, "%s; %ld; %d;\n", clientes[*total_clientes].tipo_de_cartao,
          clientes[*total_clientes].cpf_cliente,
          clientes[*total_clientes].melhor_data_de_vencimento);
  fwrite(elementos, sizeof(char), strlen(elementos), f);
  elementos[strcspn(elementos, "\n")] = '\0';
  fclose(f);
  printf("Cartão cadastrado com sucesso\n");
}

// void listar_clientes(cliente clientes[], int total_clientes) {

//   // Listando todos os clientes existentes com todas suas informações.
//   printf("Clientes:\n");
//   for (int i = 0; i < total_clientes; i++) {
//     printf("Cliente %d:\n", i + 1);
//     printf("Razao Social: %s\n", clientes[i].nome_cliente);
//     printf("CNPJ: %ld\n", clientes[i].cpf_cliente);
//     printf("Tipo de conta: %s\n", clientes[i].tipo_de_conta);
//     printf("Valor inicial da conta: %d\n", clientes[i].valor_inicial_conta);
//     printf("Senha: %d\n", clientes[i].senha_cliente);
//     printf("\n");
//   }
// }
