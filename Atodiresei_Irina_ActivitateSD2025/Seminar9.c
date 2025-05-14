//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//    int id;
//    int nrUsi;
//    float pret;
//    char* model;
//    char* numeSofer;
//    unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//typedef struct nod nod;
//
////creare structura pentru un nod dintr-un arbore binar de cautare
//struct nod {
//    Masina info;
//    nod* dr;
//    nod* st;
//};
//
//Masina citireMasinaDinFisier(FILE* file) {
//    char buffer[100];
//    char sep[3] = ",\n";
//    fgets(buffer, 100, file);
//    char* aux;
//    Masina m1;
//    aux = strtok(buffer, sep);
//    m1.id = atoi(aux);
//    m1.nrUsi = atoi(strtok(NULL, sep));
//    m1.pret = atof(strtok(NULL, sep));
//    aux = strtok(NULL, sep);
//    m1.model = malloc(strlen(aux) + 1);
//    strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//    aux = strtok(NULL, sep);
//    m1.numeSofer = malloc(strlen(aux) + 1);
//    strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//    m1.serie = *strtok(NULL, sep);
//    return m1;
//}
//
//void afisareMasina(Masina masina) {
//    printf("Id: %d\n", masina.id);
//    printf("Nr. usi : %d\n", masina.nrUsi);
//    printf("Pret: %.2f\n", masina.pret);
//    printf("Model: %s\n", masina.model);
//    printf("Nume sofer: %s\n", masina.numeSofer);
//    printf("Serie: %c\n\n", masina.serie);
//}
//
//void adaugaMasinaInArbore(nod** radacina, Masina masinaNoua) {
//    if (!(*radacina)) {
//        nod* nou = (nod*)malloc(sizeof(nod));
//        nou->info = masinaNoua;
//        (*radacina) = nou;
//        nou->st = NULL;
//        nou->dr = NULL;
//    }
//    else {
//        if ((*radacina)->info.id > masinaNoua.id) {
//            adaugaMasinaInArbore(&(*radacina)->st, masinaNoua);
//        }
//        else if ((*radacina)->info.id < masinaNoua.id) {
//            adaugaMasinaInArbore(&(*radacina)->dr, masinaNoua);
//        }
//    }
//}
//
//nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//    FILE* f = fopen(numeFisier, "r");
//    if (!f) {
//        printf("Eroare la deschiderea fisierului.\n");
//        return NULL;
//    }
//    nod* arbore = NULL;
//    while (!feof(f)) {
//        adaugaMasinaInArbore(&arbore, citireMasinaDinFisier(f));
//    }
//    fclose(f);
//    return arbore;
//}
//
//void afisareINOrdine(nod* radacina) {
//    if (radacina) {
//        afisareINOrdine(radacina->st);
//        afisareMasina(radacina->info);
//        afisareINOrdine(radacina->dr);
//    }
//}
//
//void afisarePREOrdine(nod* radacina) {
//    if (radacina) {
//        afisareMasina(radacina->info);
//        afisarePREOrdine(radacina->st);
//        afisarePREOrdine(radacina->dr);
//    }
//}
//
//void afisarePOSTOrdine(nod* radacina) {
//    if (radacina) {
//        afisarePOSTOrdine(radacina->st);
//        afisarePOSTOrdine(radacina->dr);
//        afisareMasina(radacina->info);
//    }
//}
//
//void afisareMasiniDinArbore(nod* radacina) {
//    printf("INORDINE:\n");
//    afisareINOrdine(radacina);
//    printf("PREORDINE:\n");
//    afisarePREOrdine(radacina);
//    printf("POSTORDINE:\n");
//    afisarePOSTOrdine(radacina);
//}
//
//void dezalocareArboreDeMasini(nod** arbore) {
//    if (*arbore) {
//        dezalocareArboreDeMasini(&(*arbore)->st);
//        dezalocareArboreDeMasini(&(*arbore)->dr);
//        free((*arbore)->info.model);
//        free((*arbore)->info.numeSofer);
//        free(*arbore);
//        *arbore = NULL;
//    }
//}
//
//Masina getMasinaByID(nod* arbore, int id) {
//    Masina m;
//    m.id = -1;
//    m.nrUsi = 0;
//    m.pret = 0;
//    m.model = NULL;
//    m.numeSofer = NULL;
//    m.serie = 0;
//
//    if (arbore) {
//        if (arbore->info.id < id) {
//            return getMasinaByID(arbore->dr, id);
//        }
//        else if (arbore->info.id > id) {
//            return getMasinaByID(arbore->st, id);
//        }
//        else {
//            return arbore->info;
//        }
//    }
//
//    return m;
//}
//
//int determinaNumarNoduri(nod* radacina) {
//    if (radacina == NULL) {
//        return 0;
//    }
//    return 1 + determinaNumarNoduri(radacina->st) + determinaNumarNoduri(radacina->dr);
//}
//
//int calculeazaInaltimeArbore(nod* radacina) {
//    if (radacina == NULL) {
//        return 0;
//    }
//    int hSt = calculeazaInaltimeArbore(radacina->st);
//    int hDr = calculeazaInaltimeArbore(radacina->dr);
//    return 1 + (hSt > hDr ? hSt : hDr);
//}
//
//float calculeazaPretTotal(nod* arbore) {
//    if (arbore == NULL) {
//        return 0;
//    }
//    float sumast = calculeazaPretTotal(arbore->st);
//    float sumadr = calculeazaPretTotal(arbore->dr);
//    return arbore->info.pret + sumast + sumadr;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(nod* arbore, const char* numeSofer) {
//    if (arbore == NULL) {
//        return 0;
//    }
//    float suma = 0;
//    if (strcmp(arbore->info.numeSofer, numeSofer) == 0) {
//        suma = arbore->info.pret;
//    }
//    return suma + calculeazaPretulMasinilorUnuiSofer(arbore->st, numeSofer) +
//        calculeazaPretulMasinilorUnuiSofer(arbore->dr, numeSofer);
//}
//
//int main() {
//    nod* radacina = NULL;
//    radacina = citireArboreDeMasiniDinFisier("masini.txt");
//
//    afisareINOrdine(radacina);
//
//    Masina m = getMasinaByID(radacina, 5);
//    if (m.model != NULL) {
//        printf("\nMasina cu ID 5:\n");
//        afisareMasina(m);
//    }
//    else {
//        printf("\nMasina cu ID 5 nu a fost gasita.\n");
//    }
//
//    float pret = calculeazaPretTotal(radacina);
//    printf("\nPret total masini: %.2f\n", pret);
//
//    int nrNoduri = determinaNumarNoduri(radacina);
//    printf("Numar total noduri: %d\n", nrNoduri);
//
//    int inaltime = calculeazaInaltimeArbore(radacina);
//    printf("Inaltime arbore: %d\n", inaltime);
//
//    float pretSofer = calculeazaPretulMasinilorUnuiSofer(radacina, "Ion");
//    printf("Pret total masini ale soferului Ion: %.2f\n", pretSofer);
//
//    dezalocareArboreDeMasini(&radacina);
//
//    return 0;
//}
