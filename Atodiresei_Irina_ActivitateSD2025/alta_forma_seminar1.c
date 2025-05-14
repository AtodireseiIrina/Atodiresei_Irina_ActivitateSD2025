//#include<stdio.h>
//#include<stdlib.h>
//
//struct Elev
//{
//	int idElev;
//	int nrMaterii;
//	float* note;
//	char* numeElev;
//	int nrOptionale;
//};
//
//struct Elev initializare(int idElev, int nrMaterii, float* note, char* numeElev, int nrOptionale)
//{
//	struct Elev e;
//	e.idElev = idElev;
//	e.nrMaterii = nrMaterii;
//	e.note = (float*)malloc(nrMaterii*sizeof(float));
//	for (int i = 0; i < nrMaterii; i++)
//	{
//		e.note[i] = note[i];
//	}
//	e.numeElev = (char*)malloc(strlen(numeElev) + 1);
//	strcpy_s(e.numeElev, strlen(numeElev) + 1, numeElev);
//	e.nrOptionale = nrOptionale;
//	return e;
//}
//
//
//
//void afisare(struct Elev e)
//{
//
//	printf("\n Id elev: %d\n Nr materii: %d\n Nume elev: %s\n Nr de optionale alese sunt: %d\n Notele sunt: \n ", e.idElev, e.nrMaterii, e.numeElev,e.nrOptionale);
//	for (int i = 0; i < e.nrMaterii; i++)
//	{
//		printf("\n%.2f\n", e.note[i]);
//	}
//
//}
//
//void modificare_nrOptionale(struct Elev* e, int nrNou)
//{
//	if (nrNou > 0 && nrNou<5)
//	{
//		e->nrOptionale = nrNou;
//	}
//}
//
//void dezalocare(struct Elev* e)
//{
//	free(e->note);
//	e->note = NULL;
//
//	free(e->numeElev);
//	e->numeElev = NULL;
//}
//
//
//int main()
//{
//	float note[] = { 10,9.7 };
//	struct Elev e1 = initializare(1, 2, note, "ionel",3);
//	afisare(e1);
//	modificare_nrOptionale(&e1,4);
//	afisare(e1);
//
//	dezalocare(&e1);
//
//}