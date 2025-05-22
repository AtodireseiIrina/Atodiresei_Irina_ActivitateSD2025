//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct {
//    int id;
//    char* adresa;
//    int anConstructie;
//    float suprafata;
//} Imobiliar;
//
//Imobiliar citireImobiliar() {
//    Imobiliar i;
//    char buffer[100];
//
//    printf("ID: ");
//    scanf("%d", &i.id);
//    getchar();
//
//    printf("Adresa: ");
//    fgets(buffer, 100, stdin);
//    buffer[strcspn(buffer, "\n")] = '\0';
//    i.adresa = (char*)malloc(strlen(buffer) + 1);
//    strcpy(i.adresa, buffer);
//
//    printf("An constructie: ");
//    scanf("%d", &i.anConstructie);
//
//    printf("Suprafata: ");
//    scanf("%f", &i.suprafata);
//
//    return i;
//}
//
//void afisareImobiliar(Imobiliar i) {
//    printf("ID: %d\n", i.id);
//    printf("Adresa: %s\n", i.adresa);
//    printf("An constructie: %d\n", i.anConstructie);
//    printf("Suprafata: %.2f mp\n", i.suprafata);
//    printf("\n");
//}
//
//float mediaSuprafata(Imobiliar i) {
//    return i.suprafata;
//}
//
//void modificaAdresa(Imobiliar* i, const char* nouaAdresa) {
//    free(i->adresa);
//    i->adresa = (char*)malloc(strlen(nouaAdresa) + 1);
//    strcpy(i->adresa, nouaAdresa);
//}
//
//void dezalocare(Imobiliar* i) {
//    if (i->adresa) {
//        free(i->adresa);
//        i->adresa = NULL;
//    }
//}
//
//int main() {
//    Imobiliar i1 = citireImobiliar();
//    afisareImobiliar(i1);
//
//    printf("Suprafata medie: %.2f\n", mediaSuprafata(i1));
//
//    modificaAdresa(&i1, "Str. Noua nr. 100");
//    printf("Dupa modificarea adresei:\n");
//    afisareImobiliar(i1);
//
//    dezalocare(&i1);
//    return 0;
//}
