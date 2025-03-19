//#include<stdlib.h>
//#include<stdio.h>
//
//struct Avion {
//	int cod;
//	char* denumire;
//	int nrLocuri;
//	float* tarife;
//
//};
//
//struct Avion citireAtribute()
//{
//	struct Avion a;
//	char buffer[100];
//	printf("Introduceti codul avionului: \n");
//	scanf_s("%d", &a.cod);
//
//	printf("\n Introduceti denumirea avionului: ");
//	scanf_s("%s", buffer, sizeof(buffer));
//	a.denumire = (char*)malloc(strlen(buffer) + 1);
//	strcpy_s(a.denumire, strlen(buffer) + 1, buffer);
//
//	printf("\nIntroduceti nr de locuri: ");
//	scanf_s("%d", &a.nrLocuri);
//
//	printf("\nUrmeaza sa introduceti tarifele pt fiecare loc:\n");
//	a.tarife = (float*)malloc(sizeof(float) * a.nrLocuri);
//	for (int i = 0; i < a.nrLocuri; i++) {
//		if (a.nrLocuri > 0) {
//			printf("\nIntroduceti tariful pt locul %d: \n", i + 1);
//			scanf_s("%f", &a.tarife[i]);
//		}
//	}
//
//	return a;
//}
////functie care returneaza cel mai mare tarif a unui loc
//void maxTarif(struct Avion a) {
//	float maxim = 0;
//	if (a.nrLocuri > 0) {
//		for (int i = 0; i < a.nrLocuri; i++) {
//			if (a.tarife[i] > maxim) {
//				maxim = a.tarife[i];
//			}
//		}
//	}
//	if (maxim > 0)printf("\n Cel mai mare tarif a unui loc este: %f.\n", maxim);
//}
//
//
//void modificaCod(struct Avion* a, int codNou) {
//	a->cod = codNou;
//
//}
//
//void afisare(struct Avion a) {
//	printf("\n codul este %d: \n", a.cod);
//	printf("\n denumirea avionului este %s \n", a.denumire);
//	printf("\n nr de locuri este: %d\n", a.nrLocuri);
//	printf("\n tarifele pt locuri sunt: \n");
//	for (int i = 0; i < a.nrLocuri; i++) {
//		printf("\n tariful pt locul %d este %f", i, a.tarife[i]);
//	}
//}
//void afisareVector(struct Avion* vector, int nrAvioane) {
//	for (int i = 0; i < nrAvioane; i++) {
//		afisare(vector[i]);
//	}
//}
//void dezalocare(struct Avion** vector, int* nrAvioane) {
//	for (int i = 0; i < *nrAvioane; i++) {
//		free((*vector)[i].denumire);
//		free((*vector)[i].tarife);
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrAvioane = 0;
//}
//
////copiaza avioane cu nr de locuri multe
//void copiazaAvioaneCuLocuriMulte(struct Avion* vector, int nrAvioane, int prag, struct Avion** vectorNou, int* dimensiune) {
//	*dimensiune = 0;
//	for (int i = 0; i < nrAvioane; i++) {
//		if (prag < vector[i].nrLocuri)
//			(*dimensiune)++;
//	}
//	if ((*dimensiune) > 0) {
//		(vectorNou) = (struct Avion*)malloc(sizeof(struct Avion) * (*dimensiune));
//	}
//	int j = 0;
//	for (int i = 0; i < nrAvioane; i++) {
//		if (prag < vector[i].nrLocuri) {
//			(*vectorNou)[j] = vector[i];
//			(*vectorNou)[j].denumire = malloc(strlen(vector[i].denumire) + 1);
//			strcpy_s((*vectorNou)[j].denumire, strlen(vector[i].denumire) + 1, vector[i].denumire);
//
//			(*vectorNou)[j].tarife = (float*)malloc(sizeof(float) * vector[i].nrLocuri);
//			for (int k = 0; k < vector[i].nrLocuri; k++) {
//				(*vectorNou)[j].tarife[k] = vector[i].tarife[k];
//			}
//
//			j++;
//		}
//	}
//}
//
////CONCATENARE 2 VECTORI
//void concateneazaVectori(struct Avion* vector1, int nrAvioane1, struct Avion* vector2, int nrAvioane2, struct Avion** vectorNou, int* nrNou) {
//	*nrNou = nrAvioane1 + nrAvioane2;
//
//	vectorNou = (struct Avion*)malloc(sizeof(struct Avion) * (*nrNou));
//
//	for (int i = 0; i < nrAvioane1; i++) {
//		(*vectorNou)[i] = vector1[i];
//		(*vectorNou)[i].denumire = malloc(strlen(vector1[i].denumire) + 1);
//		strcpy_s((*vectorNou)[i].denumire, strlen(vector1[i].denumire) + 1, vector1[i].denumire);
//
//		(*vectorNou)[i].tarife = (float*)malloc(sizeof(float) * vector1[i].nrLocuri);
//		for (int k = 0; k < vector1[i].nrLocuri; k++) {
//			(*vectorNou)[i].tarife[k] = vector1[i].tarife[k];
//		}
//	}
//
//	for (int i = 0; i < nrAvioane2; i++) {
//		(*vectorNou)[nrAvioane1 + i] = vector2[i];
//		int lenDenumire1 = strlen(vector2[i].denumire);
//		int lenDenumire2 = strlen((*vectorNou)[nrAvioane1 + i].denumire);
//		(*vectorNou)[nrAvioane1 + i].denumire = (char)malloc(lenDenumire1 + lenDenumire2 + 2);
//
//		strcpy_s((*vectorNou)[nrAvioane1 + i].denumire, lenDenumire1 + 1, vector2[i].denumire);
//		strcat_s((*vectorNou)[nrAvioane1 + i].denumire, lenDenumire1 + lenDenumire2 + 2, " ");
//		strcat_s((*vectorNou)[nrAvioane1 + i].denumire, lenDenumire1 + lenDenumire2 + 2, (*vectorNou)[nrAvioane1 + i].denumire);
//
//		(*vectorNou)[nrAvioane1 + i].tarife = (float*)malloc(sizeof(float) * vector2[i].nrLocuri);
//		for (int k = 0; k < vector2[i].nrLocuri; k++) {
//			(*vectorNou)[nrAvioane1 + i].tarife[k] = vector2[i].tarife[k];
//		}
//	}
//}
//
//
//
//int main()
//{
//	//struct Avion* avioane = NULL;
//	//int nrAvioane = 5;
//	//avioane = (struct Avion*)malloc(sizeof(struct Avion)*nrAvioane);
//	//printf("\ncitire atribute pt avionul 1: \n");
//	//avioane[0] = citireAtribute();
//	//printf("\ncitire atribute pt avionul 2: \n");
//	//avioane[1] = citireAtribute();
//	//printf("\ncitire atribute pt avionul 3: \n");
//	//avioane[2] = citireAtribute();
//	//printf("\ncitire atribute pt avionul 4: \n");
//	//avioane[3] = citireAtribute();
//	//printf("\ncitire atribute pt avionul 5: \n");
//	//avioane[4] = citireAtribute();
//	//afisareVector(avioane, nrAvioane);
//
//	//int nrNou;
//	//struct Avion* vectorNou = NULL;
//
//	//printf("\nAfisare avioane cu multe locuri: \n");
//	//copiazaAvioaneCuLocuriMulte(avioane, nrAvioane, 4, &vectorNou, &nrNou);
//	//afisareVector(vectorNou, nrNou);
//	//dezalocare(&vectorNou, &nrNou);
//
//	struct Avion* avioane1 = NULL;
//	struct Avion* avioane2 = NULL;
//	int nrAvioane1 = 1; // 1 avion pentru primul set
//	int nrAvioane2 = 1; // 1 avion pentru al doilea set
//
//	avioane1 = (struct Avion*)malloc(sizeof(struct Avion) * nrAvioane1);
//	avioane2 = (struct Avion*)malloc(sizeof(struct Avion) * nrAvioane2);
//
//
//	printf("\nCitire atribute pentru avionul 1 din primul vector: \n");
//	avioane1[0] = citireAtribute();
//
//	printf("\nCitire atribute pentru avionul 1 din al doilea vector: \n");
//	avioane2[0] = citireAtribute();
//
//	struct Avion* vectorNou = NULL;
//	int nrNou;
//	concateneazaVectori(avioane1, nrAvioane1, avioane2, nrAvioane2, &vectorNou, &nrNou);
//
//	printf("\nAfisare vector concatenat:\n");
//	afisareVector(vectorNou, nrNou);
//
//	dezalocare(&vectorNou, &nrNou);
//	dezalocare(&avioane1, &nrAvioane1);
//	dezalocare(&avioane2, &nrAvioane2);
//
//	return 0;
//}