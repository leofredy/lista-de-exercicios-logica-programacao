#include <iostream>

using namespace std;

#define MAX 4

struct Alunos {
	int id;
	string nome;
};

struct Turma {
	Alunos alunos[MAX];
	int tamanho;
};

bool listaCheia(Turma *lista) {
	bool estaCheia = false;
	
	if (lista->tamanho == MAX) {
		estaCheia = true;
	}
	
	return estaCheia;
}

int pegaPosicaoAluno(Turma *lista, int idAluno) {
	int posicaoAluno = -1;
	
	for (int count = 0; count < lista->tamanho; count++) {
		if (lista->alunos[count].id == idAluno) {
			posicaoAluno = count;
		}
	}
	
	return posicaoAluno;
}

bool alunoExiste(Turma *lista, int idAluno) {
	bool existe = false;
	
	if (pegaPosicaoAluno(lista, idAluno) > -1) {
		existe = true;
	}
	
	return existe;
}

void criarLista(Turma *lista) {
	lista->tamanho = 0;
}

void esvaziarLista(Turma *lista) {
	lista->tamanho = 0;
}

void exibirLista(Turma *lista) {
	for (int count = 0; count < lista->tamanho; count++) {
		cout << "Posicao na lista: " << count << endl;
		cout << "ID do aluno: " << lista->alunos[count].id << endl;
		cout << "Nome do aluno: " << lista->alunos[count].nome << endl;
	}
}

void inserirAluno(Turma *lista, int idAluno, string nomeAluno) {
	if (!listaCheia(lista)) {	
		if (!alunoExiste(lista, idAluno)) {
			int tamanho = lista->tamanho;
		
			lista->alunos[tamanho].id = idAluno;
			lista->alunos[tamanho].nome = nomeAluno;
			lista->tamanho++;
		} else {
			cout << "Aluno já cadastrado!!" << endl;
		}
		
	} else {
		cout << "Lista já esta cheia!!" << endl;
	}
}

void removeAluno(Turma *lista, int idAluno) {
	int posicaoAluno = pegaPosicaoAluno(lista, idAluno);
	
	if (posicaoAluno > -1) {
		for (int count = posicaoAluno; (count + 1) < lista->tamanho; count++) {
			lista->alunos[count].id = lista->alunos[count + 1].id;
			lista->alunos[count].nome = lista->alunos[count + 1].nome;
		}
		
		lista->tamanho--;
	} else {
		cout << "Aluno não existe!!" << endl;
	}
}

void inserirAlunoOrdenado(Turma *lista, int idAluno, string nomeAluno) {
	if (!listaCheia(lista)) {
		if (!alunoExiste(lista, idAluno)) {
			int index = 0;
			for (index = 0; index < lista->tamanho && lista->alunos[index].id < idAluno; index++) {
				
			}
			
			for (int count = lista->tamanho - 1; count >= index; count--) {
				lista->alunos[count + 1].id = lista->alunos[count].id;
				lista->alunos[count + 1].nome = lista->alunos[count].nome;
			}
			
			lista->alunos[index].id = idAluno;
			lista->alunos[index].nome = nomeAluno;
			
			lista->tamanho++;
		} else {
			cout << "Aluno já existe!" << endl;
		}
	} else {
		cout << "Lista já esta cheia!" << endl;
	}
}

main() {
	bool continuar = true;
	int operacao, idAluno;
	
	Turma turma;
	string nomeAluno;
	
	criarLista(&turma);
	
	do {
		
		cout << "---- Escolha uma operacao ----" << endl;
		cout << "(1) - Exibir lista" << endl;
		cout << "(2) - Inserir" << endl;
		cout << "(3) - Remover" << endl;
		cout << "(4) - Inserir aluno ordenado" << endl;
		cout << "(5) - Exibir posicao" << endl;
		cout << "(6) - Esvaziar" << endl;
		cout << "(0) - Sair" << endl;
		cin >> operacao;
		
		switch (operacao) {
			case 1: 
				cout << "** EXIBINDO LISTA **" << endl;
				exibirLista(&turma);
				break;
			
			case 2: 
				cout << "** INSERINDO ALUNO **" << endl;
				
				cout << "ID do aluno: ";
				cin >> idAluno;
				cout << endl << "Nome do aluno: ";
				cin >> nomeAluno;
				
				inserirAluno(&turma, idAluno, nomeAluno);
				
				break;
				
			case 3: 
				cout << "** REMOVENDO ALUNO **" << endl;
				
				cout << "ID do aluno: ";
				cin >> idAluno;
				cout << endl;
				
				removeAluno(&turma, idAluno);
				
				break;
			
			case 4: 
				cout << "** INSERIR ALUNO ORDENADO **" << endl;
				
				cout << "ID do aluno: ";
				cin >> idAluno;
				cout << endl << "Nome do aluno: ";
				cin >> nomeAluno; 
				cout << endl;
				
				inserirAlunoOrdenado(&turma, idAluno, nomeAluno);
				
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
