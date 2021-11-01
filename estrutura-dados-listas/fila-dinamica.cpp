#include <iostream>

using namespace std;

struct Numero {
	int valor;
	Numero *proximo;
};
struct Fila {
	Numero *inicioFila;
};

Fila *criaFila() {
	Fila *fila = new Fila;
	fila->inicioFila = NULL;
	
	return fila;
}
Numero *criaNumero() {
	Numero *numero = new Numero;
	
	return numero;
}
Numero *pegaUltimoFila(Fila *fila) {
	Numero* proximo;
	for (proximo = fila->inicioFila; proximo->proximo; proximo = proximo->proximo) {
	}
	
	return proximo;
}
void inserir(Fila *fila, int valor) {
	Numero *numero = criaNumero();
	numero->valor = valor;
	
	
	if (!fila->inicioFila) {
		numero->proximo = fila->inicioFila;
		fila->inicioFila = numero;
	} else {
		Numero *ultimoFila = pegaUltimoFila(fila);
		cout << "Ultimo da fila: " << ultimoFila->valor << endl;
		ultimoFila->proximo = numero;
		numero->proximo = NULL;
	}
}

void imprimir(Fila *fila, Numero *proximo) {
	if (proximo) {
		cout << "Valor: " << proximo->valor << endl;
		imprimir(fila, proximo->proximo);
	}
}
void remover(Fila *fila) {
	if (fila->inicioFila) {
		if (fila->inicioFila->proximo) {
			fila->inicioFila = fila->inicioFila->proximo;
		} else {
			fila->inicioFila = NULL;
		}
	} else {
		cout << "Fila vazia!!" << endl;
	}
}
main() {
	Fila *fila = criaFila();
	inserir(fila, 1);
	inserir(fila, 2);
	inserir(fila, 3);
	inserir(fila, 4);
	imprimir(fila, fila->inicioFila);
	system("pause");
	cout << "Removendo da fila" << endl << endl;
	remover(fila);
	imprimir(fila, fila->inicioFila);
	cout << "Removendo da fila" << endl << endl;
	remover(fila);
	imprimir(fila, fila->inicioFila);
	cout << "Removendo da fila" << endl << endl;
	remover(fila);
	imprimir(fila, fila->inicioFila);
	cout << "Removendo da fila" << endl << endl;
	remover(fila);
	imprimir(fila, fila->inicioFila);
	cout << "Removendo da fila" << endl << endl;
	remover(fila);
	imprimir(fila, fila->inicioFila);
}
