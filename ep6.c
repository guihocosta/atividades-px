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
        return NULL;
    }
    t->id = id;
    strcpy(t->nome, nome);
    t->pontos = pontos;
    return t;
}

void write_file(FILE *arquivo, Time *t){
    fprintf(arquivo, "%d\n%s\n%d\n", t->id, t->nome, t->pontos);
}

Time* read_file(FILE *arquivo) {
    int id, pontos;
    char nome[50];
    
    fscanf(arquivo, "%d %49[^\n] %d", &id, nome, &pontos);
    return init_team(id, nome, pontos);

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
    
    write_file(arquivo, t1);
    fclose(arquivo);

    free(t1);

    arquivo = fopen("time.txt", "r");
    if (arquivo == NULL) {
        return 1;
    }

    Time *t2 = read_file(arquivo);
    if (t2 == NULL) return 1;

    printf("ID: %d; Nome: %s; Pontos: %d", t2->id, t2->nome, t2->pontos);

    fclose(arquivo);
    free(t2);

    return 0;
}
