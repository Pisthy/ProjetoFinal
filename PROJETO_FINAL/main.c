#include "funcoesNo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct TreeNode* root = NULL;

    int opcao, inserirValue, removeValue, searchValue;

    while (opcao != 6) {
        printf("1- INSERIR VALOR\n");
        printf("2- REMOVER VALORES DA ARVORE\n");
        printf("3- REALIZAR BUSCA POR VALOR\n");
        printf("4- PERCORRER A ARVORE EM ORDEM\n");
        printf("5- RETORNA VALOR MINIMO E MAXIMO\n");
        printf("6- SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                printf("INFORME O VALOR QUE DESEJA ADICIONAR NA ARVORE: ");
                scanf("%d", &inserirValue);
                root = insert(root, inserirValue);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                printf("INFORME O VALOR QUE DESEJA REMOVER: ");
                scanf("%d", &removeValue);
                if (search(root, removeValue)) {
                    printf("%d ESTA PRESENTE NA LISTA\n", removeValue);
                } else {
                    printf("%d NAO ESTA PRESENTE NA LISTA\n", removeValue);
                }
                root = deleteNode(root, removeValue);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                printf("INFORME O VALOR QUE DESEJA BUSCAR: ");
                scanf("%d", &searchValue);
                if (search(root, searchValue)) {
                    printf("%d VERDADEIRO, ESTA NA LISTA\n", searchValue);
                } else {
                    printf("%d FALSO, NAO ESTA NA LISTA\n", searchValue);
                }
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                printf("ARVORE INORDER: ");
                inorderTraversal(root);
                printf("\n");
                printf("ARVORE PREORDER: ");
                preorderTraversal(root);
                printf ("\n");
                printf("ARVORE POSTORDER: ");
                postorderTraversal(root);
                printf ("\n");
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                int min = minValue(root);
                int max = maxValue(root);
                printf("Valor mínimo na ABB: %d\n", min);
                printf("Valor máximo na ABB: %d\n", max);
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                printf ("SAINDO...\n");
                system("pause");
                system("cls");
                break;           
            
            default:
                printf("OPCAO ERRADA, SERA RETORNADO AO MENU PRINCIPAL\n");
                break;
        }
    }
    freeTree(root);

   

    return 0;
}
