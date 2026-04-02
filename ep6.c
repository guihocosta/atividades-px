#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    int pontos;
} Time;

Time* init_team(int id, char* nome, int pontos) {
    Time* t = (Time*)malloc(sizeof(Time));
    if (t == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    t->id = id;
    strcpy(t->nome, nome);
    t->pontos = pontos;
    return t;
}

int main() {
    int id, pontos;
    char nome[50];

    printf("Qual o ID do Time? ");
    scanf("%d", &id);
    printf("Qual o Nome do Time? ");
    scanf(" %49[^\n]", nome);
    printf("Qual a quantidade de pontos do Time? ");
    scanf("%d", &pontos);

    Time *t1 = init_team(id, nome, pontos);
    if (t1 == NULL) return 1;

    FILE *arquivo = fopen("time.txt", "w");
    if (arquivo == NULL) {
        free(t1);
        return 1;
    }
    fprintf(arquivo, "%d\n%s\n%d\n", t1->id, t1->nome, t1->pontos);
    fclose(arquivo);

    free(t1);
    t1 = NULL;

    arquivo = fopen("time.txt", "r");
    if (arquivo == NULL) {
        return 1;
    }

    Time *t2 = (Time*)malloc(sizeof(Time));
    if (t2 == NULL) {
        fclose(arquivo);
        return 1;
    }

    if (fscanf(arquivo, "%d\n %49[^\n]\n%d", &t2->id, t2->nome, &t2->pontos) == 3) {
        printf("ID: %d\n", t2->id);
        printf("Nome: %s\n", t2->nome);
        printf("Pontos: %d\n", t2->pontos);
    }

    fclose(arquivo);
    free(t2);

    return 0;
}
