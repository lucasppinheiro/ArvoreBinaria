#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

// Estrutura com os dados pedidos no enunciado.
struct Aluno {
    int matricula;
    string nome;
    string curso;
};

// Cada nó da árvore guarda um aluno e aponta para dois lados.
struct No {
    Aluno aluno;
    No* esquerda;
    No* direita;
};

// Insere um aluno na Árvore Binária de Busca.
No* inserir(No* raiz, Aluno aluno) {
    // Se a posição está vazia, criamos um novo nó.
    if (raiz == NULL) {
        No* novo = new No;
        novo->aluno = aluno;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    // Se o nome é menor, o aluno vai para a subárvore esquerda.
    if (aluno.nome < raiz->aluno.nome) {
        raiz->esquerda = inserir(raiz->esquerda, aluno);
    }
    // Se o nome é maior, o aluno vai para a subárvore direita.
    else if (aluno.nome > raiz->aluno.nome) {
        raiz->direita = inserir(raiz->direita, aluno);
    }
    // Se o nome é igual, não cadastramos repetido.
    else {
        cout << "Já existe um aluno com esse nome.\n";
    }

    return raiz;
}

// Busca um aluno pelo nome.
No* buscar(No* raiz, string nome) {
    // Se chegou em NULL, o aluno não foi encontrado.
    if (raiz == NULL) {
        return NULL;
    }

    // Se o nome do nó atual é o procurado, retornamos esse nó.
    if (raiz->aluno.nome == nome) {
        return raiz;
    }

    // Decide se continua procurando pela esquerda ou pela direita.
    if (nome < raiz->aluno.nome) {
        return buscar(raiz->esquerda, nome);
    } else {
        return buscar(raiz->direita, nome);
    }
}

// Exibe os alunos em ordem alfabética.
void exibirEmOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    // Percurso em ordem: esquerda, raiz e direita.
    exibirEmOrdem(raiz->esquerda);

    cout << raiz->aluno.nome
         << " - Matrícula: " << raiz->aluno.matricula
         << " - Curso: " << raiz->aluno.curso << endl;

    exibirEmOrdem(raiz->direita);
}

// Conta quantos alunos existem na árvore.
int contarAlunos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int alunosEsquerda = contarAlunos(raiz->esquerda);
    int alunosDireita = contarAlunos(raiz->direita);

    return 1 + alunosEsquerda + alunosDireita;
}

// Calcula a altura da árvore.
int calcularAltura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int alturaEsquerda = calcularAltura(raiz->esquerda);
    int alturaDireita = calcularAltura(raiz->direita);

    return 1 + max(alturaEsquerda, alturaDireita);
}

// Libera a memória usada pela árvore antes de fechar o programa.
void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    delete raiz;
}

int main() {
    // Estas linhas ajudam o terminal do Windows a mostrar acentos corretamente.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    No* raiz = NULL;
    int opcao;

    do {
        cout << "\n--- CADASTRO DE ALUNOS ---\n";
        cout << "1 - Inserir aluno\n";
        cout << "2 - Buscar aluno\n";
        cout << "3 - Exibir alunos em ordem alfabética\n";
        cout << "4 - Exibir quantidade e altura da árvore\n";
        cout << "0 - Sair\n";
        cout << "Opção: ";
        cin >> opcao;
        cin.ignore(); // Limpa o Enter antes de usar getline.

        if (opcao == 1) {
            Aluno aluno;

            cout << "Matrícula: ";
            cin >> aluno.matricula;
            cin.ignore(); // Limpa o Enter antes de ler o nome.

            cout << "Nome completo: ";
            getline(cin, aluno.nome);

            cout << "Curso: ";
            getline(cin, aluno.curso);

            raiz = inserir(raiz, aluno);
        }
        else if (opcao == 2) {
            string nome;


            cout << "Nome do aluno: ";
            getline(cin, nome);

            No* encontrado = buscar(raiz, nome);

            if (encontrado != NULL) {
                cout << "Aluno encontrado:\n";
                cout << "Matrícula: " << encontrado->aluno.matricula << endl;
                cout << "Nome: " << encontrado->aluno.nome << endl;
                cout << "Curso: " << encontrado->aluno.curso << endl;
            } else {
                cout << "Aluno não encontrado.\n";
            }
        }
        else if (opcao == 3) {
            if (raiz == NULL) {
                cout << "Nenhum aluno cadastrado.\n";
            } else {
                exibirEmOrdem(raiz);
            }
        }
        else if (opcao == 4) {
            cout << "Quantidade de alunos: " << contarAlunos(raiz) << endl;
            cout << "Altura da árvore: " << calcularAltura(raiz) << endl;
        }
        else if (opcao != 0) {
            cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    liberarArvore(raiz);

    return 0;
}
