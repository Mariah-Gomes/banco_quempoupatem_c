// Arquivo para definir as funções utilizadas
#include "struct.h"
void menu();
void novo_cliente(cliente clientes[], int *total_clientes);
void apaga_cliente(cliente clientes[], int *total_clientes);
void debito(cliente clientes[], int total_clientes);
void deposito(cliente clientes[], int total_clientes);
void extrato();
void transferencia(cliente clientes[], int total_clientes);
void cartao(cliente clientes[], int *total_clientes);
void listar_clientes(cliente clientes[], int total_clientes);