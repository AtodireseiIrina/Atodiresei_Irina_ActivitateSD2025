#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structura Imobiliar
typedef struct {
    int id;
    char* adresa;
    int anConstructie;
    float suprafata;
} Imobiliar;

void afisareImobiliar(Imobiliar i) {
    printf("ID: %d  adresa: %s  an: %d  suprafata: %.2f \n",
        i.id, i.adresa, i.anConstructie, i.suprafata);
}

void afisareVectorImobiliare(Imobiliar* vector, int nr) {
    for (int i = 0; i < nr; i++) {
        afisareImobiliar(vector[i]);
    }
}

void adaugaImobiliarInVector(Imobiliar** vector, int* nr, Imobiliar nou) {
    *vector = (Imobiliar*)realloc(*vector, (*nr + 1) * sizeof(Imobiliar));
    (*vector)[*nr] = nou;
    (*vector)[*nr].adresa = strdup(nou.adresa);
    (*nr)++;
}

Imobiliar citireImobiliarFisier(FILE* f) {
    Imobiliar i;
    char buffer[100];
    fgets(buffer, 100, f);
    char* token = strtok(buffer, ",\n");
    i.id = atoi(token);
    token = strtok(NULL, ",\n");
    i.adresa = (char*)malloc(strlen(token) + 1);
    strcpy(i.adresa, token);
    token = strtok(NULL, ",\n");
    i.anConstructie = atoi(token);
    token = strtok(NULL, ",\n");
    i.suprafata = atof(token);
    return i;
}

Imobiliar* citireVectorImobiliareFisier(const char* numeFisier, int* nrImobile) {
    FILE* f = fopen(numeFisier, "r");
    if (!f) {
        printf("Eroare la deschiderea fisierului.\n");
        *nrImobile = 0;
        return NULL;
    }

    Imobiliar* vector = NULL;
    *nrImobile = 0;

    while (!feof(f)) {
        Imobiliar i = citireImobiliarFisier(f);
        if (i.adresa != NULL && strlen(i.adresa) > 0) {
            adaugaImobiliarInVector(&vector, nrImobile, i);
        }
        free(i.adresa); 
    }

    fclose(f);
    return vector;
}

void dezalocareVectorImobiliare(Imobiliar** vector, int* nr) {
    for (int i = 0; i < *nr; i++) {
        free((*vector)[i].adresa);
    }
    free(*vector);
    *vector = NULL;
    *nr = 0;
}

int main() {
    int nrImobile = 0;
    Imobiliar* vector = citireVectorImobiliareFisier("imobile.txt", &nrImobile);

    printf("Imobile citite din fisier:\n");
    afisareVectorImobiliare(vector, nrImobile);

    dezalocareVectorImobiliare(&vector, &nrImobile);
    return 0;
}
