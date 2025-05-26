//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct Produs {
//	int id;
//	char* denumire;
//	float pret;
//};
//typedef struct Produs Produs;
//typedef struct Nod Nod;
//struct Nod {
//	Nod* st;
//	Nod* dr;
//	Produs info;
//};
//
//Produs citireProdusDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	Produs p1;
//	char* aux;
//	aux = strtok(buffer, sep);
//	p1.id = atoi(aux);
//	aux = strtok(NULL, sep);
//	p1.denumire = malloc(strlen(aux) + 1);
//	strcpy(p1.denumire, aux);
//	p1.pret = atof(strtok(NULL, sep));
//
//	return p1;
//}
//
//void afisareProdus(Produs p) {
//	printf("id: %d\n", p.id);
//	printf("denumire: %s\n", p.denumire);
//	printf("pret: %.2f\n\n", p.pret);
//}
//
//int inaltimeArbore(Nod* radacina) {
//	if (radacina != NULL) {
//		int st = inaltimeArbore(radacina->st);
//		int dr = inaltimeArbore(radacina->dr);
//		int max = 0;
//		if (max < st) {
//			max = st;
//		}
//		if (max < dr) {
//			max = dr;
//		}
//		return max + 1;
//	}
//	else return 0;
//}
//
//void rotireStanga(Nod** radacina) {
//	Nod* nou;
//	nou = (*radacina)->dr;
//	(*radacina)->dr = nou->st;
//	nou->st = *radacina;
//	*radacina = nou;
//}
//
//void rotireDreapta(Nod** radacina) {
//	Nod* nou;
//	nou = (*radacina)->st;
//	(*radacina)->st = nou->dr;
//	nou->dr = (*radacina);
//	(*radacina) = nou;
//}
//int gradEchilibru(Nod* radacina) {
//	if (radacina != NULL) {
//		return inaltimeArbore(radacina->st) - inaltimeArbore(radacina->dr);
//	}
//	else return 0;
//}
//
//void adaugareProdusInArboreEchilibrat(Nod** radacina, Produs produsNou) {
//	if ((*radacina) != NULL) {
//		if ((*radacina)->info.id > produsNou.id) {
//			adaugareProdusInArboreEchilibrat(&((*radacina)->st), produsNou);
//		}
//		else {
//			adaugareProdusInArboreEchilibrat(&((*radacina)->dr), produsNou);
//		}
//		int grad = gradEchilibru(*radacina);
//		if (grad == 2) {
//			if (gradEchilibru((*radacina)->st) == 1) {
//				rotireDreapta(radacina);
//			}
//			else {
//				rotireStanga(&((*radacina)->st));
//				rotireDreapta(radacina);
//			}
//		}
//		else if (grad == -2) {
//			if (gradEchilibru((*radacina)->dr) == 1) {
//				rotireDreapta(&((*radacina)->dr));
//			}
//			rotireStanga(radacina);
//		}
//	}
//	else {
//		(*radacina) = (Nod*)malloc(sizeof(Nod));
//		(*radacina)->info = produsNou;
//		(*radacina)->info.denumire = (char*)malloc(strlen(produsNou.denumire) + 1);
//		strcpy((*radacina)->info.denumire, produsNou.denumire);
//		(*radacina)->st = NULL;
//		(*radacina)->dr = NULL;
//	}
//}
//Nod* citireArboreEchilibratDinFiser(const char* numeFisier) {
//	FILE* file = fopen(numeFisier, "r");
//	Nod* radacina = NULL;
//	while (!feof(file)) {
//		Produs p = citireProdusDinFisier(file);
//		adaugareProdusInArboreEchilibrat(&radacina, p);
//		free(p.denumire);
//	}
//	fclose(file);
//	return radacina;
//}
//
//void afisareInOerdine(Nod* radacina) {
//	if (radacina != NULL) {
//		afisareInOerdine(radacina->st);
//		afisareProdus(radacina->info);
//		afisareInOerdine(radacina->dr);
//	}
//}
//
//void dezalocareArbore(Nod** radacina) {
//	if ((*radacina) != NULL) {
//		dezalocareArbore(&(*radacina)->st);
//		dezalocareArbore(&(*radacina)->dr);
//		free((*radacina)->info.denumire);
//		free((*radacina));
//		(*radacina) = NULL;
//	}
//}
//
//Produs getProdusByID(Nod* radacina, int id) {
//	Produs p;
//	p.id = -1;
//	if (radacina->info.id > id) {
//		return getProdusByID(radacina->st, id);
//	}
//	else if (radacina->info.id < id) {
//		return getProdusByID(radacina->dr, id);
//	}
//	else {
//		p = radacina->info;
//		p.denumire = (char*)malloc(strlen(radacina->info.denumire) + 1);
//		strcpy(p.denumire, radacina->info.denumire);
//		return p;
//	}
//
//}
//
//int main()
//{
//	Nod* arbore = citireArboreEchilibratDinFiser("produse.txt");
//	afisareInOerdine(arbore);
//	printf("Produsul cu id 3 este: \n\n");
//	afisareProdus(getProdusByID(arbore, 3));
//
//	dezalocareArbore(&arbore);
//	return 0;
//}