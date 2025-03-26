//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//typedef struct Nod Nod;
//
////creare structura pentru un nod dintr-o lista simplu inlantuita
//struct Nod {
//	Masina info;
//	Nod* urm;
//};
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
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
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareListaMasini(Nod* cap) {
//
//	while (cap)
//	{
//		afisareMasina(cap->info); 
//		cap= cap->urm;
//	}
//	//afiseaza toate elemente de tip masina din lista simplu inlantuita
//	//prin apelarea functiei afisareMasina()
//}
//
//void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua; //daca masinaNoua o vom dezaloca sau nu facem shallow copy sau nu
//	nou->urm = NULL;
//
//	if ((*cap) == NULL) {
//		*cap = nou;
//	}
//	else {
//		Nod* p = *cap;
//		while (p->urm)
//		{
//			p = p->urm;
//			//aici NU facem legatura catre nodul urmator, abia dupa ce term de parcurs
//		}
//		p->urm = nou;
//	}
//	//adauga la final in lista primita o noua masina pe care o primim ca parametru
//}
//
//void adaugaLaInceputInLista(Nod** cap, Masina masinaNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod)); //creeam nou nod
//	nou->info = masinaNoua; //copiem informatia
//	nou->urm = *cap;//modificam cap sa pointeze catre  cap
//	*cap = nou;
//	//adauga la inceputul listei o noua masina pe care o primim ca parametru
//}
//
//Nod* citireListaMasiniDinFisier(const char* numeFisier) {
//
//	FILE* f = fopen(numeFisier,"r");
//	Nod* lista = NULL;
//	while (!feof(f)) {
//		adaugaLaInceputInLista(&lista, citireMasinaDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	//ATENTIE - la final inchidem fisierul/stream-ul
//}
//
//void dezalocareListaMasini(Nod** cap) {
//	while ((*cap)!=NULL)
//	{
//		Nod* aux=( *cap);
//		*cap = (*cap)->urm;
//		free(aux->info.numeSofer);
//		free(aux->info.model);
//		free(aux);
//	}
//	//sunt dezalocate toate masinile si lista de elemente
//}
//
//float calculeazaPretMediu(Nod* lista) {
//
//	if (!lista) return 0;
//	int count = 0; //cate elem avem in lista
//	float sum = 0; //pt suma elem
//	while (lista) {
//		sum += lista->info.pret;
//		count++;
//		lista = lista->urm;
//	}
//
//	return sum / count;
//}
//
//void stergeMasiniDinSeria(/*lista masini*/ char serieCautata) {
//	//sterge toate masinile din lista care au seria primita ca parametru.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//}
//
//float calculeazaPretulMasinilorUnuiSofer(Nod* lista, const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	float sum = 0;
//	while (lista) {
//		if (strcmp(numeSofer, lista->info.numeSofer) == 0) {
//			sum += lista->info.pret;
//		}
//		lista = lista->urm;
//	}
//	return sum;
//}
////functia care mi cauta masina cea mai scumpa si returneaza modelul
//char* getCeaMaiScumpaMasina(Nod* lista) {
//	float pretulMax=0;
//	char* modelScump=NULL;
//	while (lista) {
//		if (lista->info.pret > pretulMax) {
//			pretulMax = lista->info.pret;
//			modelScump = lista->info.model;
//		}
//		lista = lista->urm;
//	}
//	if (pretulMax>0) {
//		char* nou = malloc(strlen(modelScump) + 1);
//		strcpy_s(nou, strlen(modelScump) + 1, modelScump);
//		return nou;
//	}
//	return NULL;
//}
//
//int main() {
//	Nod* cap = NULL;
//	cap=citireListaMasiniDinFisier("masini.txt");
//	afisareListaMasini(cap);
//
//	printf("%f\n",calculeazaPretMediu(cap));
//	printf("%f\n\n", calculeazaPretulMasinilorUnuiSofer(cap,"Ionescu"));
//
//	printf("%s", getCeaMaiScumpaMasina(cap));
//
//	dezalocareListaMasini(&cap);
//	return 0;
//}