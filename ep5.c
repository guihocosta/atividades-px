#include <stdio.h>
#include <string.h>

int split_text(char *text, char *part1, char *part2) {
    int i = 0;
    int j = 0;

    while (text[i] != ' ' && text[i] != ' '){
        part1[i] = text[i];
        i++;
    }
    part1[i] = '\0';

    if (text[i] == '\0')
        return 0;
    
    i++;

    while (text[i] != '\0'){
        part2[j] = text[i];
        i++;
        j++;
    }
    part2[j] = '\0';
    return 1;
}

int main() {
    char text[] = "Bom dia";
    char part1[20], part2[20];

    if (split_text(text, part1, part2)) {
        printf("Parte 1: %s\nParte 2: %s\n", part1, part2);
    }
    return 0;
}