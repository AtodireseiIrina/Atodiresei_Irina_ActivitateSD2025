//#include<stdlib.h>
//#include<stdio.h>
//
//struct Avion {
//	int cod;
//	char* denumire;
//	int nrLocuri;
//	float* tarife;
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
//
//int main()
//{
//	struct Avion avion1 = citireAtribute();
//	maxTarif(avion1);
//	modificaCod(&avion1, 234);
//	printf("Codul nou al avionului este: %d\n", avion1.cod);
//	afisare(avion1);
//}