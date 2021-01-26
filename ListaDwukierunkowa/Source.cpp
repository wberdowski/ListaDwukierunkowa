#include <iostream>

using namespace std;

struct Lista
{
	Lista* gora;
	int wartosc;
	Lista* dol;
};

void dodaj(Lista** lista, int wartosc) {
	Lista* temp = *lista;
	if (*lista) {
		Lista* temp2 = new Lista;
		temp2->wartosc = wartosc;
		while (temp->dol) {
			temp = temp->dol;
		}
		temp2->gora = temp;
		temp2->dol = 0;
		temp->dol = temp2;
	}
	else {
		*lista = new Lista;
		(*lista)->wartosc = wartosc;
		(*lista)->gora = NULL;
		(*lista)->dol = NULL;
	}
}

void wypisz(Lista* s) {
	if (s) {
		do {
			cout << s->wartosc << "->";
			s = s->dol;
		} while (s);
	}
}

void uzupelnij(Lista* lista1, Lista** lista2) {
	int lastValue = 0;

	if (lista1 && lista2) {
		do {
			int wartosc = lista1->wartosc;

			for (int i = lastValue + 1; i < wartosc; i++) {
				dodaj(lista2, i);
			}

			lastValue = wartosc;
			lista1 = lista1->dol;
		} while (lista1);
	}
}

void zwolnijPamiec(Lista** lista) {
	Lista* temp;
	while (*lista) {
		temp = (*lista)->dol;
		delete (*lista);
		*lista = temp;
	}
}

int main() {
	Lista* listaWej = 0;
	Lista* listaWyj = 0;
	int nWej = 0;
	int wartosc = 0;

	cout << "Podaj liczbe wprowadzanych elementow: ";
	cin >> nWej;

	for (int i = 0; i < nWej; i++) {
		cout << "Podaj element listy: ";
		cin >> wartosc;
		dodaj(&listaWej, wartosc);
	}

	cout << "Lista wejsciowa: " << endl;
	wypisz(listaWej);

	uzupelnij(listaWej, &listaWyj);

	cout << endl << "Lista wyjsciowa: " << endl;
	wypisz(listaWyj);

	zwolnijPamiec(&listaWej);
	zwolnijPamiec(&listaWyj);

	return 0;
}