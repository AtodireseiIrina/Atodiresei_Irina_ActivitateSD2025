//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct Rata
//{
//	int id;
//	char* culoare;
//	float pret;
//};
//typedef struct Rata Rata;
//typedef struct Nod Nod;
//struct Nod {
//	Nod* st;
//	Nod* dr;
//	Rata info;
//};
//
//Rata citireRataDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	Rata r1;
//	char* aux;
//	aux = strtok(buffer, sep);
//	r1.id = atoi(aux);
//	aux = strtok(NULL, sep);
//	r1.culoare = malloc(strlen(aux) + 1);
//	strcpy(r1.culoare, aux);
//	r1.pret = atof(strtok(NULL, sep));
//
//	return r1;
//}
//
//void afisareRata(Rata r) {
//	printf("id: %d\n", r.id);
//	printf("culoare: %s\n", r.culoare);
//	printf("pret: %.2f\n\n", r.pret);
//}
//
//void adugareRataInArbore(Nod** radacina, Rata rataNoua) {
//	if ((*radacina) != NULL) {
//		if ((*radacina)->info.pret > rataNoua.pret) {
//			adugareRataInArbore(&((*radacina)->st), rataNoua);
//		}
//		else if ((*radacina)->info.pret < rataNoua.pret) {
//			adugareRataInArbore(&((*radacina)->dr), rataNoua);
//		}
//		else {
//			(*radacina)->info.id = rataNoua.id;
//			(*radacina)->info.culoare = (char*)malloc(strlen(rataNoua.culoare) + 1);
//			strcpy((*radacina)->info.culoare, rataNoua.culoare);
//			(*radacina)->info.pret = rataNoua.pret;
//		}
//
//
//	}
//	else
//	{
//		(*radacina) = malloc(sizeof(Nod));
//		(*radacina)->info = rataNoua;
//		(*radacina)->info.culoare = (char*)malloc(strlen(rataNoua.culoare) + 1);
//		strcpy((*radacina)->info.culoare, rataNoua.culoare);
//		(*radacina)->dr = NULL;
//		(*radacina)->st = NULL;
//	}
//
//}
//
//Nod* citireArboreDinFIsier(const char* numeFisier) {
//	FILE* file = fopen(numeFisier, "r");
//	Nod* radacina = NULL;
//	while (!feof(file)) {
//		Rata r = citireRataDinFisier(file);
//		adugareRataInArbore(&radacina, r);
//		free(r.culoare);
//	}
//	fclose(file);
//	return radacina;
//}
//
//void afisarePostOrdine(Nod* radacina) {
//	if (radacina != NULL) {
//		afisarePostOrdine(radacina->st);
//		afisarePostOrdine(radacina->dr);
//		afisareRata(radacina->info);
//	}
//}
//
//void dezalocareArbore(Nod** radcina) {
//	if ((*radcina) != NULL) {
//		dezalocareArbore(&(*radcina)->st);
//		dezalocareArbore(&(*radcina)->dr);
//		free((*radcina)->info.culoare);
//		free((*radcina));
//		(*radcina) = NULL;
//	}
//}
//
//Rata getRataByID(Nod* radacina, int id) {
//	Rata r;
//	r.id = -1;
//	if (radacina->info.id > id) {
//		return getRataByID(radacina->st, id);
//	}
//	if (radacina->info.id < id) {
//		return getRataByID(radacina->dr, id);
//	}
//	else {
//		r = radacina->info;
//		r.culoare = (char*)malloc(strlen(radacina->info.culoare) + 1);
//		strcpy(r.culoare, radacina->info.culoare);
//		return r;
//	}
//
//}
//int nrNoduri(Nod* radacina) {
//	if (radacina != NULL) {
//		return 1 + nrNoduri(radacina->st) + nrNoduri(radacina->dr);
//	}
//	else return 0;
//}
//
//
//float pretRataDupaCuloare(Nod* radacina, const char* culoare) {
//	float pret = 0;
//	if (radacina == NULL) {
//		return 0;
//	}
//	if (strcmp(radacina->info.culoare, culoare) == 0) {
//		pret += radacina->info.pret;
//	}
//
//	pret += pretRataDupaCuloare(radacina->st, culoare);
//	pret += pretRataDupaCuloare(radacina->dr, culoare);
//	return pret;
//}
//
//int main()
//{
//	Nod* arbore = citireArboreDinFIsier("rate.txt");
//	afisarePostOrdine(arbore);
//	printf("nr noduri: %d\n\n", nrNoduri(arbore));
//	printf("Rata cu id ul 2 este: \n");
//	afisareRata(getRataByID(arbore, 2));
//	printf("Pret rata verde: %.2f\n\n", pretRataDupaCuloare(arbore, "verde"));
//
//	dezalocareArbore(&arbore);
//	return 0;
//}