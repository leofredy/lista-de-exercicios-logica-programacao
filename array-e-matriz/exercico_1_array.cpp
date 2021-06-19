#include <locale.h>
#include <iostream>

using namespace std;

int quantidadeNumeroPares(int lista_numeros[], int tamanho) {
	int quantidadePares;
	
	for (int index = 0; index < tamanho; index++) {
		if (lista_numeros[index] % 2 == 0) {
			quantidadePares++;
		}
	}
	
	return quantidadePares;
}

void imprimeNumeros(int lista_numeros[], int tamanho) {
		
	for (int index = 0; index < tamanho; index++) {
		cout << lista_numeros[index];
		if (index != tamanho - 1) {
			cout << ", ";
		}
	}
	
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int lista_numeros[6], quantidadePares, quantidadeImpares;
	int indexPar = 0;
	int indexImpar = 0;
	const int tamanho = 6;
	
	cout << "Digite 6 números inteiros" << endl;
	
	//Recebe os números
	for (int index = 0; index < 6; index++) {
		cin >> lista_numeros[index];
	}
	
	quantidadePares = quantidadeNumeroPares(lista_numeros, tamanho);
	quantidadeImpares = tamanho - quantidadePares;
	
	int lista_numeros_pares[quantidadePares];
	int lista_numeros_impares[quantidadeImpares];
	


	for (int index = 0; index < 6; index++) {
		if (lista_numeros[index] % 2 == 0) {
			lista_numeros_pares[indexPar] = lista_numeros[index];
			indexPar++;
		} else {
			lista_numeros_impares[indexImpar] = lista_numeros[index];
			indexImpar++;
		}
	}
	cout << "Quantidade de número pares: " << quantidadePares << endl;
	cout << "Quantidade de número impares: " << quantidadeImpares << endl;
	
	
	cout << "Números pares: " << endl;
	imprimeNumeros(lista_numeros_pares, quantidadePares);
	
	cout << "Números impares: " << endl;
	imprimeNumeros(lista_numeros_impares, quantidadeImpares);
	
	return 0;
}
