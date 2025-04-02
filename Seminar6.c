#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

//creare structura pentru un nod dintr-o lista simplu inlantuita
struct Nod
{
	Masina info;
	struct Nod* urm;
};
typedef struct Nod Nod;

//creare structura pentru tabela de dispersie
// aceasta este un vector de liste
struct HashTable {
	int dim;
	Nod** v; //un vector de pointeri la nod
};
typedef struct HashTable HashTable;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(Nod* v) {
	while (v) {
		afisareMasina(v->info);
		v = v->urm;
	}

}

void adaugaMasinaInLista(Nod* v, Masina masinaNoua) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->urm = NULL;
	while (v->urm) {
		v = v->urm;
	}
	v->urm = nou;
}


HashTable initializareHashTable(int dimensiune) {
	HashTable ht;
	ht.dim = dimensiune;
	ht.v = (Nod**)malloc(sizeof(Nod*)*dimensiune);
	for (int i = 0; i < dimensiune; i++) {
		ht.v[i] = NULL;
	}
	return ht;
}

int calculeazaHash(const char* nume, int dimensiune) {
	// este calculat hash-ul in functie de dimensiunea tabelei si un atribut al masinii
	//calc cum vreau eu hash dar trb sa fie in dim data
	int s = 0;
	if (dimensiune == 0)return 0;
	for (int i = 0; i < strlen(nume); i++) {
		s += nume[i];
	}
	return s % dimensiune;

}

void inserareMasinaInTabela(HashTable hash, Masina masina) {

	int poz = calculeazaHash(masina.numeSofer,hash.dim);
	if (hash.v[poz] == NULL) {
		//nu avem coliziune
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->info = masina;
		nou->urm = NULL;
		hash.v[poz] = nou;
	}
	else {
		//avem coliziune
		adaugaMasinaInLista(hash.v[poz], masina);
	}


	//este folosit mecanismul CHAINING
	//este determinata pozitia si se realizeaza inserarea pe pozitia respectiva
}

HashTable citireMasiniDinFisier(const char* numeFisier, int dimensiune) {
	FILE* file = fopen(numeFisier, "r");
	HashTable ht = initializareHashTable(dimensiune);
	while (!feof(file)) {
		inserareMasinaInTabela(ht, citireMasinaDinFisier(file));
	}
	fclose(file);
	return ht;
}

void afisareTabelaDeMasini(HashTable ht) {
	for (int i = 0; i < ht.dim; i++) {
		printf("\nClusterul: %d\n", i + 1);
		afisareListaMasini(ht.v[i]);
	}


	//sunt afisate toate masinile cu evidentierea clusterelor realizate
}

void dezalocareTabelaDeMasini(HashTable *ht) {
	//sunt dezalocate toate masinile din tabela de dispersie
}

float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
	//calculeaza pretul mediu al masinilor din fiecare cluster.
	//trebuie sa returnam un vector cu valorile medii per cluster.
	//lungimea vectorului este data de numarul de clustere care contin masini
	return NULL;
}

Masina getMasinaDupaCheie(HashTable ht,const char* nume) {
	Masina m;
	int hash = calculeazaHash(nume, ht.dim);
	if (ht.v[hash]) {
		Nod* p = ht.v[hash];
		while (p && strcmp(nume, p->info.numeSofer) != 0) {
			p = p->urm;
		}

		if (p) {
			m = p->info;
			m.model = malloc(strlen(p->info.model) + 1);
			strcpy_s(m.model, strlen(p->info.model) + 1, p->info.model);

			m.numeSofer = malloc(strlen(p->info.numeSofer) + 1);
			strcpy_s(m.numeSofer, strlen(p->info.numeSofer) + 1, p->info.numeSofer);
		}
	}

	//cauta masina dupa valoarea atributului cheie folosit in calcularea hash-ului
	//trebuie sa modificam numele functiei 
	return m;
}

int main() {

	HashTable ht = citireMasiniDinFisier("masini.txt", 5);
	afisareTabelaDeMasini(ht);
	return 0;
}