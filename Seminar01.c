#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int nrLocuri;
	char* marca;
	float capacitateC;
	char normaPoluare;
};

struct Masina initializare(int id, int nrLocuri, const char* marca, float capaciatateC, char normaPoluare)
{
	//initializare structura 
	struct Masina m;
	m.id = id;
	m.nrLocuri = nrLocuri;
	m.capacitateC = capaciatateC;
	m.normaPoluare = normaPoluare;
	//aloc memorie cu malloc pt char*
	m.marca = (char*)malloc(strlen(marca) + 1);
	strcpy_s(m.marca, strlen(marca) + 1, marca);
	//m.marca destinatia, marca sursa
	//
	return m;
}

void afisare(struct Masina m)
{
	//afisarea tuturor atributelor.
	printf("\n Id masina: %d\n Nr locuri: %d\n Capacitate: %f\n Marca: %s\n Euro: %c\n", m.id, m.nrLocuri, m.capacitateC, m.marca, m.normaPoluare);
	//printf fct cu nr varibil de parametrii, primul carac este oblig un sir de caractere

}

void modifica_NrLocuri(struct Masina* m, int nrNou)
{
	//modificarea unui atribut
	//in limbajul C nu exista referinta!
	if (nrNou > 0)
	{
		m->nrLocuri = nrNou;
		//prin sageata defrentiem 
	}

}

void dezalocare(struct Masina* m)
{
	//dezalocare campuri alocate dinamic
	//trb intitalizat cu null pt ca pastreaza o adresa de memorie goala
	free(m->marca);
	m->marca = NULL;
}

int main() {
	struct Masina masina = initializare(1, 5, "Dacia", 1.5, '4'); //"4" asa este sir de caractere si voi avea si carac terminator si va ocupa 2 octeti
	//dif dintre o metoda si o functi este pointerul this
	afisare(masina);
	modifica_NrLocuri(&masina, 6); //aici prin & fac referentiere
	afisare(masina);
	dezalocare(&masina);
	afisare(masina);

	//printf("%d", sizeof(struct Masina*));
	return 0;
}