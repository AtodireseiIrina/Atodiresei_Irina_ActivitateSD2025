//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
////in loc sa scriu struct StructuraMasina voi scrie Masina fiinca am definit un alias
//
//void afisareMasina(Masina masina) {
//	printf("%d.Masina are %d usi, un pret %6.2f si este modelul %s. Numele soferului este %s iar seria masinii este %c.\n",
//		masina.id, masina.nrUsi, masina.pret, masina.model, masina.numeSofer, masina.serie);
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//	for (int i = 0; i < nrMasini; i++) {
//
//		afisareMasina(masini[i]);
//	}
//}
//
//void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
//	Masina* aux = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
//	for (int i = 0; i < (*nrMasini); i++) {
//		aux[i] = (*masini)[i];
//	}
//	aux[*nrMasini] = masinaNoua;
//	(*nrMasini)++;
//	//daca vreau sa nu sterg acest obiect fac shallow copy
//	//dac vreau sa sterg trb sa fac deep copy
//	free(*masini);
//	(*masini) = aux;
//}
//
//Masina citireMasinaFisier(FILE* file) {
//	//functia citeste o masina dintr-un strceam deja deschis
//	//masina citita este returnata;
//	char buffer[100];
//	char sep[3] = ", \n"; //trb pus 3 fiindca am 2 separatoare:carac terminator si \n
//	char* aux;
//	fgets(buffer, 100, file);
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	//am folosit o functie care tansf din codul ASCII in int
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	//ASCII in float
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	FILE* file = fopen(numeFisier, "r"); //r-read, w-write, w+-scriere si adaugare
//	Masina* masini = NULL;
//
//	do
//	{
//		adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(file));
//
//	} while (!feof(file));
//	fclose(file);
//	return masini;
//
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//	//este dezalocat intreg vectorul de masini
//	for (int i = 0; i < *nrMasini; i++)
//	{
//		free((*vector)[i].model);
//		free((*vector)[i].numeSofer);
//
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrMasini = 0;
//
//}
////functie care sa faca pretul mediu al masinilor cu 3 usi
//float mediePretDupaNrUsi(Masina* vector, int nrMasini, int nrUsi) {
//	float suma = 0;
//	int index = 0;
//	for (int i = 0; i < nrMasini; i++) {
//		if (vector[i].nrUsi == nrUsi) {
//			suma += vector[i].pret;
//			index++;
//		}
//	}
//	if (index > 0) {
//		return suma / index;
//	}
//	return 0;
//}
//
//int main() {
//
//	Masina* masini = NULL;
//	int nrMasini = 0;
//	masini = citireVectorMasiniFisier("masini.txt", &nrMasini);
//	afisareVectorMasini(masini, nrMasini);
//	float medie = mediePretDupaNrUsi(masini, nrMasini, 5);
//	printf("media masinilor este:\n", medie);
//	dezalocareVectorMasini(&masini, &nrMasini);
//	return 0;
//}