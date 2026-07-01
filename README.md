# Árvore Binária de Alunos

Projeto desenvolvido em C++ para a disciplina de Estrutura de Dados.

O objetivo é cadastrar alunos utilizando uma Árvore Binária de Busca (ABB), organizando os registros pelo nome completo do aluno.

## Funcionalidades

- Inserir aluno
- Buscar aluno pelo nome
- Exibir alunos em ordem alfabética
- Mostrar a quantidade total de alunos cadastrados
- Calcular a altura da árvore
- Liberar a memória utilizada ao encerrar o programa

## Dados cadastrados

Cada aluno possui:

- Matrícula
- Nome completo
- Curso

## Estrutura utilizada

A estrutura usada foi uma Árvore Binária de Busca.

Cada nó da árvore guarda um aluno e possui dois ponteiros:

- `esquerda`
- `direita`

No código, isso aparece na estrutura `No`:

```cpp
struct No {
    Aluno aluno;
    No* esquerda;
    No* direita;
};
```

A árvore é organizada pelo nome do aluno:

- nomes menores alfabeticamente ficam à esquerda;
- nomes maiores alfabeticamente ficam à direita.

Essa regra aparece na função de inserção:

```cpp
if (aluno.nome < raiz->aluno.nome) {
    raiz->esquerda = inserir(raiz->esquerda, aluno);
}
else if (aluno.nome > raiz->aluno.nome) {
    raiz->direita = inserir(raiz->direita, aluno);
}
```

## Ordem alfabética

Para exibir os alunos em ordem alfabética, foi usado o percurso em ordem:

```text
esquerda -> raiz -> direita
```

Como os nomes menores ficam à esquerda e os maiores ficam à direita, esse percurso mostra os alunos já ordenados, sem usar vetor ou função pronta de ordenação.

## Como compilar

Com o `g++` instalado, execute:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o alunos.exe -static
```

## Como executar

No Windows PowerShell:

```powershell
.\alunos.exe
```

## Menu do programa

```text
1 - Inserir aluno
2 - Buscar aluno
3 - Exibir alunos em ordem alfabética
4 - Exibir quantidade e altura da árvore
0 - Sair
```

## Arquivos do projeto

- `main.cpp`: código-fonte principal
- `RELATORIO.md`: relatório da atividade
- `.vscode/tasks.json`: tarefa para compilar pelo VS Code

## Autor

Lucas Pinheiro
