#include <iostream>
#include <malloc.h>

using namespace std;

struct Numero {
	int valor;
	Numero *proximo;
};
struct Pilha {
	Numero *topo;
};

Pilha* criaPilha() {
	Pilha *pilha;
	pilha = new Pilha;
	pilha->topo = NULL;
	
	return pilha;
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
void remover(Pilha *pilha) {
	Numero *topoAntigo = pilha->topo;
	pilha->topo = pilha->topo->proximo;
	free(topoAntigo);
}
void imprimir(Pilha *pilha, Numero *proximo) {
	if (proximo) {
		cout << "Valor: " << proximo->valor << endl;
		
		imprimir(pilha, proximo->proximo);
	}
}

main() {
	Pilha *pilha = criaPilha();
	
	inserir(pilha, 1);
	inserir(pilha, 2);
	inserir(pilha, 3);
	imprimir(pilha, pilha->topo);
	system("pause");
	cout << "Removendo..." << endl;
	remover(pilha);
	imprimir(pilha, pilha->topo);
}
