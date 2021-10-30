#include <iostream>

using namespace std;

#define MAX 10


struct Pilha {
	int topo;
	int lista_elementos[MAX];
};


void criaPilhaVazia(Pilha *pilha) {
	pilha->topo = -1;
}

int pegaTopo(Pilha *pilha) {
	return pilha->topo;
}
int inserir(Pilha *pilha, int numero) {
	pilha->topo++;
	int novoTopo = pilha->topo;
	
	pilha->lista_elementos[novoTopo] = numero;
}
void remove(Pilha *pilha) {
	pilha->topo--;
} 
void imprimePilha(Pilha *pilha) {
	for (int index = 0; index <= pilha->topo; index++) {
		cout << "Posição [" << index << "]: " << pilha->lista_elementos[index] << endl;
	}
} 

main() {
	bool continuar = true;
	int operacao;
	Pilha pilha;
	
	criaPilhaVazia(&pilha);
	
	do {
		cout << "[0] Para sair" << endl;
		cout << "[1] Para inserir" << endl;
		cout << "[2] Para imprimir Pilha" << endl;
		cout << "[3] Para remover na Pilha" << endl;
		cin >> operacao;
		
		switch (operacao) {
			case 0: 
				continuar = false;
				break;
			case 1: 
				int numero;
				cout << "Digite um número para inserir: ";
				cin >> numero;
				
				inserir(&pilha, numero);
				break;
			case 2:
				imprimePilha(&pilha);
				break;
			case 3: 
				remove(&pilha);
				break;
		}
		system("pause");
		system("cls");
	} while (continuar);
}

