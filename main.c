#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto stock[MAX_PRODUTOS];
int totalProdutos = 0;
int i;

// FunÃ§Ãµes
void adicionarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite maximo de produtos atingido!\n");
        return;
    }

    Produto novo;
    novo.id = totalProdutos + 1;

    printf("Nome do produto: ");
    scanf(" %[^\n]", novo.nome);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    printf("Preco (por unidade): ");
    scanf("%f", &novo.preco);

    stock[totalProdutos] = novo;
    totalProdutos++;

    printf("Produto adicionado com sucesso!\n\n");
}

void listarProdutos() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n\n");
        return;
    }

    printf("\n--- LISTA DE PRODUTOS ---\n");
    for (i = 0; i < totalProdutos; i++) {
        Produto p = stock[i];
        printf("ID: %d | Nome: %s | Qtd: %d | PreÃ§o: %.2f\n",
               p.id, p.nome, p.quantidade, p.preco);
    }
    printf("\n");
}

void atualizarQuantidade() {
    int id, novaQtd;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    if (id < 1 || id > totalProdutos) {
        printf("Produto nÃ£o encontrado!\n\n");
        return;
    }

    printf("Nova quantidade: ");
    scanf("%d", &novaQtd);

    stock[id - 1].quantidade = novaQtd;

    printf("Quantidade atualizada com sucesso!\n\n");
}

void removerProduto() {
    int id;
    printf("Digite o ID do produto a remover: ");
    scanf("%d", &id);

    if (id < 1 || id > totalProdutos) {
        printf("Produto nÃ£o encontrado!\n\n");
        return;
    }

    for (i = id - 1; i < totalProdutos - 1; i++) {
        stock[i] = stock[i + 1];
        stock[i].id = i + 1;
    }
    totalProdutos--;

    printf("Produto removido com sucesso!\n\n");
}

void menu() {
    printf("=== SISTEMA DE GESTAO DE STOCK ===\n");
    printf("1. Adicionar produto\n");
    printf("2. Listar produtos\n");
    printf("3. Atualizar quantidade\n");
    printf("4. Remover produto\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                atualizarQuantidade();
                break;
            case 4:
                removerProduto();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}