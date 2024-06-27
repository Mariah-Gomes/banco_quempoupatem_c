#define MAX_CLIENTES 100
#define MAX_OPERACOES 100

typedef struct {
  char nome_cliente[50];
  long cpf_cliente;
  char tipo_de_conta[10];
  int valor_inicial_conta;
  int senha_cliente;
  char tipo_de_cartao[50];
  int melhor_data_de_vencimento;
  char operacoes[MAX_OPERACOES][100];
  int total_operacoes;
} cliente;