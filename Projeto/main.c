#include "banco.h"
#include <stdio.h>
#include <strings.h>

int main() {
  // Lendo o arquivo dos clientes salvos
  cliente clientes[MAX_CLIENTES];
  int total_clientes = 0;
  FILE *f = fopen("clientes", "rb");
  if (f != NULL) {
    fread(clientes, sizeof(cliente), MAX_CLIENTES, f);
    fclose(f);
  }
  // Lendo o arquivo co o total de clientes salvos
  f = fopen("total", "rb");
  if (f != NULL) {
    fread(&total_clientes, sizeof(int), 1, f);
    fclose(f);
  }
  // Loop para rodar o menu até o usuário desejar sair
  while (1) {
    menu();
    int opcao;
    printf("Digite a opcao que deseja para acessar o menu:\n");
    scanf("%d", &opcao);
    if (opcao == 1) {
      novo_cliente(clientes, &total_clientes);
    } else if (opcao == 2) {
      apaga_cliente(clientes, &total_clientes);
    } else if (opcao == 3) {
      debito(clientes, total_clientes);
    } else if (opcao == 4) {
      deposito(clientes, total_clientes);
    } else if (opcao == 5) {
      extrato(clientes, total_clientes);
    } else if (opcao == 6) {
      transferencia(clientes, total_clientes);
    } else if (opcao == 7) {
      cartao(clientes, &total_clientes);
    } else if (opcao == 8) {
      break;
    // } else if (opcao == 9) {
    //   listar_clientes(clientes, total_clientes);
    } else {
      printf("Operacao Invalida\n");
    }
  }
  // Escrevendo no arquivo para salvar os clientes
  f = fopen("clientes", "wb");
  fwrite(clientes, sizeof(cliente), 100, f);
  fclose(f);
  // Escrevendo no arquivo o total de clientes salvos
  f = fopen("total", "wb");
  fwrite(&total_clientes, sizeof(int), 1, f);
  fclose(f);
  return 0;
}
