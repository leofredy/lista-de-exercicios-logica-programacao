#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;

#define NUM_MAX_ALUNOS 10

struct Aluno {
	int id;
	float nota;
	int posicao;
};

struct Turma {
	Aluno listaAlunos[NUM_MAX_ALUNOS];
	int tamanho;
};

Turma *criaTurma() {
	Turma *turma = new Turma;
	turma->tamanho = 0;
	
	return turma;
}

void gerarListaRandomica(Turma *turma){
	if (turma->tamanho < NUM_MAX_ALUNOS){
		for(int index = turma->tamanho; index < NUM_MAX_ALUNOS; index++){
			turma->listaAlunos[index].id = rand()%10;
			turma->listaAlunos[index].nota = rand()%10; 
			turma->listaAlunos[index].posicao = index;
			turma->tamanho++;
		}
	} else {
		cout << "[ERROR] - ARRAY CHEIO!!" << endl; 
	}
}

void inserirDado(Turma *turma, int idAluno, int notaAluno) {
	if (turma->tamanho < NUM_MAX_ALUNOS) {
		turma->listaAlunos[turma->tamanho].id = idAluno;
		turma->listaAlunos[turma->tamanho].nota = notaAluno;
		turma->listaAlunos[turma->tamanho].posicao = turma->tamanho;
		turma->tamanho++;
	} else {
		cout << "[ERROR] - ARRAY CHEIO!!" << endl;
	}
}

void imprimirLista(Turma *turma, int index) {
	if (index < turma->tamanho) {
		cout << "[" << turma->listaAlunos[index].posicao << "] ";
		cout << turma->listaAlunos[index].id;
		cout << " - ";
		imprimirLista(turma, index + 1);
	}
	cout << endl;
}

void insertionSort(Turma *turma, int indexInicio, int indexAnterior, int indexAtual) {	
	if (indexInicio < turma->tamanho) {
		if (turma->listaAlunos[indexAtual].id < turma->listaAlunos[indexAnterior].id && indexAnterior >= 0) {
			int idMenor = turma->listaAlunos[indexAtual].id;
			
			turma->listaAlunos[indexAtual].id = turma->listaAlunos[indexAnterior].id;
			turma->listaAlunos[indexAnterior].id = idMenor;
			
			indexAnterior--;
			indexAtual--;
		} else {
			indexInicio++;
			indexAtual = indexInicio;
			indexAnterior = indexInicio - 1;
		}
		
		insertionSort(turma, indexInicio, indexAnterior, indexAtual);
	}
}

void bubbleSort(Turma *turma, int primeiraPosicao, int segundaPosicao, int tamanhoLista) {
	if (tamanhoLista - 1 >= 0) {
		if (segundaPosicao < tamanhoLista) {
			if (turma->listaAlunos[segundaPosicao].id < turma->listaAlunos[primeiraPosicao].id) {
				int idMenor = turma->listaAlunos[segundaPosicao].id;
				turma->listaAlunos[segundaPosicao].id = turma->listaAlunos[primeiraPosicao].id;
				turma->listaAlunos[primeiraPosicao].id = idMenor;
			}
			primeiraPosicao++;
			segundaPosicao++;
		} else {
			primeiraPosicao = 0;
			segundaPosicao = 1;
			tamanhoLista--;
		}
		
		bubbleSort(turma, primeiraPosicao, segundaPosicao, tamanhoLista);
	}
}

main() {
	bool continuar = true;
	int opcao;
	
	Turma *turma = criaTurma();
	
	do {
		cout << "[1] GERAR ARRAY RANDOMICO" << endl;
		cout << "[2] INSERIR DADOS"         << endl;
		cout << "[3] ORDENAR COM BUBBLE"    << endl;
		cout << "[4] ORDENAR INSERTSORT"    << endl;
		cout << "[5] IMPRIMIR LISTA"        << endl;
		cout << "[6] RESETAR ARRAY"         << endl;
		cout << "[0] SAIR"                  << endl;
		cin >> opcao;
		
		switch(opcao) {
			case 1: 
				cout << "** GERANDO RANDOMICO **" << endl;
				gerarListaRandomica(turma);
				break;
			case 2: 
				system("cls");
				cout << "** INSERINDO DADOS **" << endl;
				
				int idAluno;
				float notaAluno;
				
				cout << "Digite o id do aluno: ";
				cin >> idAluno;
				cout << endl << "Digite a nota do aluno: ";
				cin >> notaAluno;
				cout << endl;
				
				
				inserirDado(turma, idAluno, notaAluno);
				break;
			case 3:
				cout << "** ORDENANDO COM BUBBLE **" << endl;
				bubbleSort(turma, 0, 1, turma->tamanho);
				break;
			case 4:
				cout << "** ORDENANDO INSERTSORT  **" << endl;
				insertionSort(turma, 1, 0, 1);
				break;
			case 5:
				cout << "** IMPRMINDO LISTA **" << endl;
				imprimirLista(turma, 0);
				break;
			case 6:
				cout << "** RESENTANDO ARRAY **" << endl;
				turma->tamanho = 0;
				break;
			default:
				cout << "** SAINDO... **" << endl;
				continuar = false;
				break;
		}
		system("pause");
		system("cls");
	} while(continuar);
}
