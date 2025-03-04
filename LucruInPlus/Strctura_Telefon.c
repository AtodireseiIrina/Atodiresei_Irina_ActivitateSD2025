#include<stdio.h>
#include<stdlib.h>

struct Telefon {
	int id;
	int RAM;
	char* producator;
	float pret;
	char serie;
	//pt char este un singur caracter
};
//const char* pt a nu fi modificata acea info de la acea adresa !!

struct Telefon initializare(int id, int ram, const char* producator, float pret, char serie)
{
	struct Telefon t;
	t.id = id;
	t.RAM = ram;
	t.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
	strcpy_s(t.producator, strlen(producator) + 1, producator);
	t.pret = pret;
	t.serie = serie;
	return t;
}


void afisare(struct Telefon t)
{
	if (t.producator != NULL)
		printf("%d. Telfonul %s seria %c are %d GB RAM si costa %5.2f RON. \n", t.id, t.producator, t.serie, t.RAM, t.pret);
	else
		printf("%d. Telfonul seria %c are %d GB RAM si costa %5.2f RON. \n", t.id, t.serie, t.RAM, t.pret);
}

//trb transmis prin pointer
//transmiterea param Telefon t s-a fct prin adresa
void modificaPret(struct Telefon* t, float noulPret)
{
	if (noulPret > 0)
	{
		//(*t).pret = noulPret;
		t->pret = noulPret;

		//mai sus il deferentiez fiindca modific direct in stiva functiei main
	}
}

//si aici e transmis prin pointer fiindca fac o modificare
void dezalocare(struct Telefon* t)
{
	if (t->producator != NULL)
	{
		free(t->producator);
		t->producator = NULL;
	}

}

int main() {
	struct Telefon t;
	t = initializare(1, 256, "Samsung", 2000.5, 'A');
	afisare(t);

	//aici pun & pt ca trasnmit o adresa
	modificaPret(&t, 1000);
	afisare(t);

	dezalocare(&t);
	afisare(t);

	return 0;
}