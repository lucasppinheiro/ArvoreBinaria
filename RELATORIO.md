# Sistema de cadastro de alunos com Árvore Binária de Busca

## Estrutura escolhida

Foi utilizada uma Árvore Binária de Busca (ABB), tendo o nome completo do aluno como chave. Cada nó armazena matrícula, nome, curso e dois ponteiros: um para o filho esquerdo e outro para o filho direito. Nomes alfabeticamente menores ficam à esquerda; nomes maiores ficam à direita. Nomes repetidos não são aceitos, porque o nome é a chave definida pelo enunciado.

Foram utilizados ponteiros tradicionais. Ao encerrar o programa, uma função percorre a árvore e libera a memória de todos os nós.

## Operações implementadas

- **Inserção:** percorre a árvore comparando o nome até encontrar uma posição vazia.
- **Busca:** compara o nome procurado com o nó atual e segue somente pela subárvore que pode conter o aluno.
- **Listagem alfabética:** usa o percurso em ordem (esquerda, raiz, direita), sem vetor nem método pronto de ordenação.
- **Quantidade:** é calculada por uma função recursiva que conta todos os nós da árvore.
- **Altura:** é calculada recursivamente. A árvore vazia tem altura 0 e uma árvore apenas com a raiz tem altura 1.

Em uma ABB razoavelmente equilibrada, inserção e busca têm custo médio O(log n). No pior caso, quando os nomes são inseridos já ordenados, a árvore pode ficar semelhante a uma lista e essas operações passam a O(n). A listagem visita todos os nós e custa O(n).

## Execução

Compilação com g++:

```text
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o alunos
```

Depois, execute `alunos.exe` no Windows. O menu permite cadastrar, buscar, listar e consultar as informações da árvore.
