//#define _CRT_SECURE_NO_WARNINGS
//#include<stdlib.h>
//#include<string.h>
//#include<stdio.h>
//
//struct Carte {
//	int nrPagini;
//	float pret;
//	char* denumire;
//};
//typedef struct Carte Carte;
//
//struct Heap {
//	int lungime;
//	Carte* vector;
//	int nrCarti;
//};
//typedef struct Heap Heap;
//
//Carte citireCarteDinFiser(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Carte c1;
//	aux = strtok(buffer, sep);
//	c1.nrPagini = atoi(aux);
//	c1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	c1.denumire = malloc(strlen(aux) + 1);
//	strcpy(c1.denumire, aux);
//
//	return c1;
//}
//
//void afisareCarte(Carte c) {
//	printf("No pages: %d\n", c.nrPagini);
//	printf("Pret: %.2f\n", c.pret);
//	printf("Denumire: %s\n\n", c.denumire);
//}
//
//Heap initializareHeap(int lungime) {
//	Heap heap;
//	heap.lungime = lungime;
//	heap.nrCarti = 0;
//	heap.vector = (Carte*)malloc(sizeof(Carte) * lungime);
//	return heap;
//}
//
//void filtrareHeap(Heap heap, int pozNod) {
//	int pozSt = pozNod * 2 + 1;
//	int pozDr = pozNod * 2 + 2;
//	int pozMax = pozNod;
//	if (pozDr < heap.nrCarti && heap.vector[pozMax].pret < heap.vector[pozDr].pret) {
//		pozMax = pozDr;
//	}
//	if (pozSt < heap.nrCarti && heap.vector[pozMax].pret < heap.vector[pozSt].pret) {
//		pozMax = pozSt;
//	}
//	if (pozMax != pozNod) {
//		Carte aux = heap.vector[pozMax];
//		heap.vector[pozMax] = heap.vector[pozNod];
//		heap.vector[pozNod] = aux;
//		if (pozMax <= (heap.nrCarti - 2) / 2) {
//			filtrareHeap(heap, pozMax);
//		}
//	}
//}
//
//Heap citireHeapDinFiser(const char* numeFiser) {
//	FILE* file = fopen(numeFiser, "r");
//	Heap heap = initializareHeap(3);
//	while (!feof(file)) {
//		heap.vector[heap.nrCarti++] = citireCarteDinFiser(file);
//	}
//	fclose(file);
//	for (int i = (heap.nrCarti - 2) / 2; i >= 0; i--) {
//		filtrareHeap(heap, i);
//	}
//	return heap;
//}
//void afisareHeap(Heap heap) {
//	for (int i = 0; i < heap.nrCarti; i++) {
//		afisareCarte(heap.vector[i]);
//	}
//}
//
//void dezalocareHeap(Heap* heap) {
//	for (int i = 0; i < heap->lungime; i++) {
//		if (heap->vector[i].denumire != NULL) {
//			free(heap->vector[i].denumire);
//		}
//	}
//	free(heap->vector);
//	heap->vector = NULL;
//	heap->nrCarti = 0;
//	heap->lungime = 0;
//}
//
//Carte extragereCarte(Heap* heap) {
//	if (heap->nrCarti != 0) {
//		Carte aux = heap->vector[0];
//		heap->vector[0] = heap->vector[heap->nrCarti - 1];
//		heap->vector[heap->nrCarti - 1] = aux;
//		{
//			heap->nrCarti--;
//			for (int i = (heap->nrCarti - 2) / 2; i >= 0; i--) {
//				filtrareHeap(*heap, i);
//			}
//		}
//		return aux;
//	}
//
//}
//
//int main() {
//	Heap heap = citireHeapDinFiser("carti.txt");
//	afisareHeap(heap);
//	printf("Crate extrasa deoarece are cel mai mare nr de pagini: \n");
//	afisareCarte(extragereCarte(&heap));
//	dezalocareHeap(&heap);
//
//	return 0;
//}