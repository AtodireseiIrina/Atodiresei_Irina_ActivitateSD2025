//#include<stdio.h>
//#include<stdlib.h>
//
//struct Carte
//{
//	int id;
//	int pagini;
//	char* titlu;
//	float pret;
//	char serie;
//};
//struct Carte initializare(int id, int pagini, const char* titlu, float pret, char serie) {
//	struct Carte c;
//	c.id = id;
//	c.pagini = pagini;
//	c.titlu = (char*)malloc(strlen(titlu) + 1);
//	strcpy_s(c.titlu, strlen(titlu) + 1, titlu);
//	c.pret = pret;
//	c.serie = serie;
//	return c;
//}
//void afisareCarte(struct Carte c) {
//	printf("\n Cartea %s cu id-ul %d, seria %c, are %d pagini pretul %3.2f lei.\n ", c.titlu, c.id, c.serie, c.pagini, c.pret);
//}
//
//void afisareVectorDeCarti(struct Carte* vector, int nrCarti) {
//	for (int i = 0; i < nrCarti; i++) {
//		afisareCarte(vector[i]);
//	}
//}
//
//struct Carte* initializarePrimeleNCarti(struct Carte* vector, int nrCarti, int nrNou) {
//	struct Carte* vectorNou = NULL;
//	vectorNou = (struct Carte*)malloc(sizeof(struct Carte) * nrNou);
//	for (int i = 0; i < nrNou; i++) {
//		vectorNou[i] = vector[i];
//		vectorNou[i].titlu = (char*)malloc(strlen(vector[i].titlu) + 1);
//		strcpy_s(vectorNou[i].titlu, strlen(vector[i].titlu) + 1, vector[i].titlu);
//	}
//
//	return vectorNou;
//
//}
//
//void dezalocare(struct Carte** vector, int* nrCarti) {
//	for (int i = 0; i < (*nrCarti); i++) {
//		free((*vector)[i].titlu);
//	}
//	free(*vector);
//	(*vector) = NULL;
//	(*nrCarti) = 0;
//}
//
//void copiazaCartiScumpe(struct Carte* vector, char nrElemente, float pretMinim, struct Carte** vectorNou, int* dimensiune) {
//	*dimensiune = 0;
//	for (int i = 0; i < nrElemente; i++) {
//		if (vector[i].pret >= pretMinim) {
//			(*dimensiune)++;
//		}
//
//	}
//	if ((*vectorNou) != NULL) {
//		free(*vectorNou);
//	}
//	int k = 0;
//	*vectorNou = (struct Carte*)malloc(sizeof(struct Carte) * (*dimensiune));
//	for (int i = 0; i < nrElemente; i++) {
//		if (vector[i].pret >= pretMinim) {
//			(*vectorNou)[k] = vector[i];
//			(*vectorNou)[k].titlu = (char*)malloc(strlen(vector[i].titlu) + 1);
//			strcpy_s((*vectorNou)[k].titlu, strlen(vector[i].titlu) + 1, vector[i].titlu);
//			k++;
//		}
//	}
//
//}
//
//struct Carte getPrimaCarteByTitlu(struct Carte* vector, int nrElemente, const char* titlu) {
//	struct Carte c;
//	for (int i = 0; i < nrElemente; i++) {
//		if (strcmp(vector[i].titlu, titlu) == 0) {
//			c = vector[i];
//			c.titlu = (char*)malloc(strlen(vector[i].titlu) + 1);
//			strcpy_s(c.titlu, strlen(vector[i].titlu) + 1, vector[i].titlu);
//		}
//	}
//
//	return c;
//}
//
//int main()
//{
//	/*struct Carte c = initializare(1, 120, "Viata", 50.50, 'A');
//	afisareCarte(c);*/
//
//	struct Carte* carti = NULL;
//	int nrCarti = 3;
//	carti = (struct Carte*)malloc(sizeof(struct Carte) * nrCarti);
//	carti[0] = initializare(1, 120, "Viata", 50.50, 'A');
//	carti[1] = initializare(2, 1220, "Viata volum2", 70.50, 'A');
//	carti[2] = initializare(3, 220, "Viata final", 30.50, 'A');
//	afisareVectorDeCarti(carti, nrCarti);
//
//	struct Carte* primeleCarti = NULL;
//	int nrNou = 2;
//	primeleCarti = initializarePrimeleNCarti(carti, nrCarti, nrNou);
//	printf("\n Afisam primele carti: \n");
//	afisareVectorDeCarti(primeleCarti, nrNou);
//
//	dezalocare(&primeleCarti, &nrNou);
//
//	//coiere carti scumpe:
//	struct Carte* cartiScumpe = NULL;
//	int cartiS = 0;
//	copiazaCartiScumpe(carti, nrCarti, 50, &cartiScumpe, &cartiS);
//	printf("\n\n Afisam carti scumpe: \n");
//	afisareVectorDeCarti(cartiScumpe, cartiS);
//
//	struct Carte c1 = getPrimaCarteByTitlu(carti, nrCarti, "Viata");
//	printf("\nAfisam cartea dupa un titlu dat: \n");
//	afisareCarte(c1);
//	dezalocare(&cartiScumpe, &cartiS);
//
//
//}