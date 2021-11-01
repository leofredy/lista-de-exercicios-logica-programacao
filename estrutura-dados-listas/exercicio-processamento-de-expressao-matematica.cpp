#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct ExpressoesMatematicas {
	string valor;
	ExpressoesMatematicas *proximaExpressao;
};

struct FilaExpressao {
	ExpressoesMatematicas *inicioFila;
};

struct PilhaExpressao {
	ExpressoesMatematicas *topoPilha;
};

PilhaExpressao* criaPilha() {
	PilhaExpressao *pilha;
	pilha = new PilhaExpressao;
	pilha->topoPilha = NULL;
	
	return pilha;
}

FilaExpressao *criaFila() {
	FilaExpressao *fila = new FilaExpressao;
	fila->inicioFila = NULL;
	
	return fila;
}

ExpressoesMatematicas *criaExpressao() {
	ExpressoesMatematicas *expressao = new ExpressoesMatematicas;
	
	return expressao;
}
bool ehSimbolo(string valor) {
	bool valido = false;
	if (valor == "+" || valor == "-" || valor == "*" || valor == "/"){
		valido = true;
	}
	
	return valido;
}
bool procedencia(string valor) {
	bool valido = false;
	if (valor == "*" || valor == "/") {
		valido = true;
	}
	
	return valido;
}
bool filaVazia(FilaExpressao *fila) {
	bool ehVazia = true;
	
	if (fila->inicioFila) {
		ehVazia = false;
	}
	
	return ehVazia;
}
ExpressoesMatematicas *pegaUltimoFila(FilaExpressao *fila) {
	ExpressoesMatematicas* proximo;
	for (proximo = fila->inicioFila; proximo->proximaExpressao; proximo = proximo->proximaExpressao) {
	}
	
	return proximo;
}
void enfileirar(FilaExpressao *fila, string valor) {
	if (filaVazia(fila)) {
		if (!ehSimbolo(valor)) {
			ExpressoesMatematicas *expressao = criaExpressao();
			expressao->valor = valor;
			
			expressao->proximaExpressao = fila->inicioFila;
			fila->inicioFila = expressao;
		} else {
			cout << "Erro ao enfileirar: a primeira expressão deve ser um número" << endl;
		}
	} else {
		ExpressoesMatematicas *finalFila = pegaUltimoFila(fila);
		if (ehSimbolo(valor) && !ehSimbolo(finalFila->valor) || !ehSimbolo(valor) && ehSimbolo(finalFila->valor)) {
			ExpressoesMatematicas *expressao = criaExpressao();
			expressao->valor = valor;
			
			ExpressoesMatematicas *ultimoFila = pegaUltimoFila(fila);
			ultimoFila->proximaExpressao = expressao;
			expressao->proximaExpressao = NULL;
		} else {
			cout << "Erro ao enfileirar: ";
			if (ehSimbolo(valor)) {
				cout << "o ultimo valor é um simbolo e agora você deve inserir um numero" << endl;
			} else {
				cout << "o ultimo valor é um numero e agora você deve inserir um simbolo" << endl;
			}
		}
	}	
}
void desinfileirar(FilaExpressao *fila) {
	if (fila->inicioFila) {
		if (fila->inicioFila->proximaExpressao) {
			fila->inicioFila = fila->inicioFila->proximaExpressao;
		} else {
			fila->inicioFila = NULL;
		}
	} else {
		cout << "Erro ao desinfileirar: a fila já esta vazia" << endl;
	}
}
void inserirPilha(PilhaExpressao *pilha, string valor) {
	ExpressoesMatematicas *expressao = criaExpressao();
	expressao->valor = valor;
	expressao->proximaExpressao = pilha->topoPilha;
	pilha->topoPilha = expressao;
}
void removerPilha(PilhaExpressao *pilha) {
	ExpressoesMatematicas *topoAntigo = pilha->topoPilha;
	if (pilha->topoPilha->proximaExpressao) {
		pilha->topoPilha = pilha->topoPilha->proximaExpressao;
	} else {
		pilha->topoPilha = NULL;
	}
}
void imprimirFila(FilaExpressao *fila, ExpressoesMatematicas *proximo) {
	if (proximo) {
		cout << "Valor: " << proximo->valor << endl;
		imprimirFila(fila, proximo->proximaExpressao);
	}
}
void imprimirPilha(PilhaExpressao *pilha, ExpressoesMatematicas *proximo) {
	if (proximo) {
		cout << "Valor: " << proximo->valor << endl;
		imprimirPilha(pilha, proximo->proximaExpressao);
	}
}
void calcular(FilaExpressao *fila) {
	if (!filaVazia(fila)) {
		ExpressoesMatematicas *expressaoFinalFila = pegaUltimoFila(fila);
		if (!ehSimbolo(expressaoFinalFila->valor) && !ehSimbolo(fila->inicioFila->valor)) {
			
			PilhaExpressao *PilhaNumero = criaPilha();
			PilhaExpressao *PilhaSimbolo = criaPilha();
			ExpressoesMatematicas *proximo;
			
			do {
				ExpressoesMatematicas *expressaoAtual = fila->inicioFila;
				desinfileirar(fila);
				
				if (ehSimbolo(expressaoAtual->valor)) {
					if (procedencia(expressaoAtual->valor)) {
						ExpressoesMatematicas *expressaoProxima = fila->inicioFila;
						ExpressoesMatematicas *ultimoNumeroNaPilha = PilhaNumero->topoPilha;
						desinfileirar(fila);
						removerPilha(PilhaNumero);
						
						float numeroNaPilha = stof(ultimoNumeroNaPilha->valor);
						float numeroNaFila = stof(expressaoProxima->valor);
						float resultado;
						
						if (expressaoAtual->valor == "*") {
							resultado = numeroNaPilha * numeroNaFila;
						} else {
							resultado = numeroNaPilha / numeroNaFila;
						}
						
						string valorResultado = to_string(resultado);
						
						inserirPilha(PilhaNumero, valorResultado);
					} else {
						inserirPilha(PilhaSimbolo, expressaoAtual->valor);
					}
				} else {
					inserirPilha(PilhaNumero, expressaoAtual->valor);
				}
			} while(fila->inicioFila);
			
			do {
				ExpressoesMatematicas *topoPilhaNumero = PilhaNumero->topoPilha;
				
				removerPilha(PilhaNumero);
				
				float numeroTopo = stof(topoPilhaNumero->valor);
				float resultado;
				
				if (PilhaNumero->topoPilha) {
					ExpressoesMatematicas *depoisTopoPilhaNumeros = PilhaNumero->topoPilha;
					ExpressoesMatematicas *topoPilhaSimbolos = PilhaSimbolo->topoPilha;
					
					removerPilha(PilhaNumero);
					removerPilha(PilhaSimbolo);
					
					float numeroDepoisTopo = stof(depoisTopoPilhaNumeros->valor);
					
					if (topoPilhaSimbolos->valor == "+") {
						resultado = numeroDepoisTopo + numeroTopo;
					} else {
						resultado = numeroDepoisTopo - numeroTopo;
					}
					
					inserirPilha(PilhaNumero, to_string(resultado));
				} else {
					inserirPilha(PilhaNumero, topoPilhaNumero->valor);
				}	
			} while(PilhaSimbolo->topoPilha);
			
			cout << "O resultado é: " << PilhaNumero->topoPilha->valor << endl;
			
		} else {
			if (ehSimbolo(expressaoFinalFila->valor)) {
				cout << "Erro ao calcular: a ultima expressão inserida é um simbolo, insira mais um número" << endl;
			} else {
				cout << "Erro ao calcular: a primeira expressão inserida é um simbolo, remova mais um número" << endl;
			}
		}
	} else {
		cout << "Erro ao calcular: a fila esta vazia" << endl;
	}
}

main() {
	int operacao;
	bool continuar = true;
	string expressao;
	PilhaExpressao *PilhaNumero, *PilhaSimbolo;
	FilaExpressao *FilaExpressao;
	
	FilaExpressao = criaFila();
	
	setlocale(LC_ALL,"Portuguese");
	
	do {
		cout << "---- Escolha uma operacao ----" << endl;
		cout << "(1) - Inserir expressao" << endl;
		cout << "(2) - Remover expressao" << endl;
		cout << "(3) - Calcular" << endl;
		cout << "(4) - Imprimir" << endl;
		cout << "(0) - Sair" << endl;
		cin >> operacao;
		
		switch (operacao) {
			case 1: 
				cout << "** INSERIR EXPRESSAO **" << endl;
				cout << "Digite uma expressão matematica: ";
				cin >> expressao;
				
				enfileirar(FilaExpressao, expressao);
				imprimirFila(FilaExpressao, FilaExpressao->inicioFila);
				
				break;
			case 2: 
				cout << "** REMOVENDO EXPRESSAO **" << endl;
				
				desinfileirar(FilaExpressao);
				
				break;
			case 3:
				cout << "** CALCULANDO EXPRESSAO **" << endl;
				calcular(FilaExpressao);
				
				break;
			case 4:
				cout << "** IMPRIMINDO FILA **" << endl;
				
				imprimirFila(FilaExpressao, FilaExpressao->inicioFila);
				
				break;
			case 0:
				continuar = false;
				cout << "Saindo..." << endl;
				break;
		}
		
		system("pause");
		system("cls");
		
	} while(continuar);
}

