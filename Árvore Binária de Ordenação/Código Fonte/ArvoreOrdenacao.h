#ifndef ARVORE_ORDENACAO_H
#define ARVORE_ORDENACAO_H

/**
 * @author Pedro Botelho
 * @date 11-07-2019 
 * 
 */

/* Estrutura do nó da árvore */
struct NoArvore;

/* Cria as folhas de uma arvore cheia */
NoArvore* criarArvore(int *elementos, int quantidade);

/* Percorre a árvore e ordena os elementos */
NoArvore* percorreArvore(NoArvore* raiz, int e_min, int e_max);

/* Libera a memória alocada dos nós e apaga o nó raiz */
NoArvore* liberaArvore(NoArvore* raiz);

/* Diz qual o valor numérico de um certo nó */
int valorNo(NoArvore *no);

/* Calcula a altura da árvore cheia */
int alturaArvore(int tamanho);

/* Diz qual o maior elemento de um vetor de inteiros */
int maiorElemento(int *elementos, int quant);

/* Menor valor da arvore */
int eMin(NoArvore *raiz);

#endif