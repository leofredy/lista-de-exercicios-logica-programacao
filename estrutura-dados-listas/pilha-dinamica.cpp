#include <iostream>
using namespace std;

struct Numero {
	int valor;
	Numero *proximo;
};
struct Pilha {
	Numero *topo;
};

void criaPilha(Pilha *pilha) {
	pilha->topo = NULL;
}

Numero* criaElemento() {
	Numero *Elemento;
	
	Elemento = new Numero;
	return Elemento;
}
void inserir(Pilha *pilha, int valor) {
	Numero *Elemento = criaElemento();
	Elemento->valor = valor;
	Elemento->proximo = pilha->topo;
	pilha->topo = Elemento;
}
void imprimir(Pilha *pilha, Numero *proximo) {
	if (proximo) {
		cout << "Valor: " << proximo->valor << endl;
		
		imprimir(pilha, proximo->proximo);
	}
}

main() {
	Pilha pilha;
	criaPilha(&pilha);
	inserir(&pilha, 1);
	inserir(&pilha, 2);
	inserir(&pilha, 3);
	imprimir(&pilha, pilha.topo);
}
