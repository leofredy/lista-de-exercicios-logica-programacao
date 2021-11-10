#include <iostream>

using namespace std;

struct Aluno {
	int id;
	float nota;
	Aluno *proximoAluno;
};

struct Turma {
	Aluno *inicioLista;
};


Turma *criaTurmaVazia() {
	Turma *turma = new Turma;
	turma->inicioLista = NULL;
	
	return turma;
}

Aluno *criaAluno() {
	Aluno *aluno = new Aluno;
	
	return aluno;
}

void inserirAlunoOrdenado(Turma *turma, int idAluno, float notaAluno) {
	Aluno *novoAluno = criaAluno();
	novoAluno->id = idAluno;
	novoAluno->nota = notaAluno;
	
	if (turma->inicioLista) {
		Aluno *anteriorAluno;
		
		if (turma->inicioLista->id > idAluno) {
			novoAluno->proximoAluno = turma->inicioLista;
			turma->inicioLista = novoAluno;
		} else {
			for(anteriorAluno = turma->inicioLista; anteriorAluno->proximoAluno && anteriorAluno->id < idAluno; anteriorAluno = anteriorAluno->proximoAluno) {
			}

			anteriorAluno->proximoAluno = novoAluno;
			novoAluno->proximoAluno = NULL;
		}
	} else {
		turma->inicioLista = novoAluno;
		novoAluno->proximoAluno = NULL;
	}
}

void imprimirAlunos(Aluno *aluno) {
	if (aluno) {
		cout << "[ID]: " << aluno->id << endl;
		cout << "[NOTA]: " << aluno->nota << endl;
		imprimirAlunos(aluno->proximoAluno);
	}
}

int pegaTamanhoDaLista(Turma *turma, Aluno *inicio, Aluno *fim) {
	int count = 0;
	for (Aluno *aluno = inicio; aluno != fim; aluno = aluno->proximoAluno) {
		count++;
	}
	
	return count;
}

Aluno *pesquisaBinaria(Turma *turma, int idAluno, Aluno *inicio, Aluno *fim) {
	
}

main() {
	bool continuar = true;
	int opcao;
	Turma *turma = criaTurmaVazia();
	
	do {
		cout << "[1] Para inserir um elemento a lista" << endl;
		cout << "[3] Para imprimir lista de aluno" << endl;
		cout << "[0] Para sair do programa" << endl;
		cin >> opcao;
		
		switch(opcao) {
			case 1:
				system("cls");
				cout << "** INSERIR ALUNO **" << endl << endl;
				int id;
				float nota;
				
				cout << "Digite o id do aluno: ";
				cin >> id;
				cout << endl << "Digite a nota do aluno: ";
				cin >> nota;
				inserirAlunoOrdenado(turma, id, nota);
				
				break;
			case 2: 
				cout << "Tamanho da lista: " << pegaTamanhoDaLista() << endl;
				
			case 3:
				system("cls");
				cout << "** IMPRIMINDO ALUNOS **" << endl << endl;
				
				imprimirAlunos(turma->inicioLista);
				
				break;
			
			case 0: 
				cout << "** SAINDO... **" << endl << endl;
				continuar = false;
				break;
		}
		
		system("pause");
		system("cls");
	} while(continuar);
}
