#include "ArvoreOrdenacao.h"
#include <queue>
#include <iostream>
#include <math.h>

/**
 * @author Pedro Botelho
 * @date 11-07-2019 
 * 
 */

using namespace std;

struct NoArvore{
    int chave;
    NoArvore *esq;
    NoArvore *dir;
};

NoArvore* criarArvore(int *elementos, int quantidade){
    //novo tamanho do vetor
    int n = pow(2, alturaArvore(quantidade) - 1);
    int *folhas = new int[n];
    //atribuindo valores ao novo vetor
    for(int i = 0; i < n; i++){
        if(i < quantidade){
            folhas[i] = elementos[i];
        }
        //se sobrar espaços, coloque um "coringa"
        else if(i >= quantidade){
            folhas[i] = maiorElemento(elementos, quantidade) + 1;
        } 
    }
    //cria folhas e as enfileira
    queue<NoArvore*> fila;
    for(int i = 0; i < n; i++){
        NoArvore *aux = new NoArvore;
        aux->chave = folhas[i];
        aux->dir = NULL;
        aux->esq = NULL;
        fila.push(aux);
    }
    NoArvore *paizin = new NoArvore;
    //cria arvore a partir de uma fila
    //a medida que os nos vão sendo ligados, a fila vai perdendo os "filhos" e ganhando o "pai"
    //desse modo, uma hora o tamanho vai ser um
    while(fila.size() != 1){
        NoArvore *aux = new NoArvore;
        NoArvore *pai = new NoArvore;
        NoArvore *aux02 = new NoArvore;
        aux = fila.front();
        fila.pop();
        aux02 = fila.front();
        fila.pop();
        pai->chave = min(aux->chave, aux02->chave);
        pai->esq = aux;
        pai->dir = aux02;
        fila.push(pai);
        paizin = pai;
    }
    return paizin;
}

//percorre arvore e substitui e_min por e_max
NoArvore* percorreArvore(NoArvore* raiz, int e_min, int e_max){
    //percorre até chegar nas folhas e atribui o menor valor dos filhos ao pai
    if((raiz->esq != NULL) && (raiz->dir != NULL)){
        raiz->esq = percorreArvore(raiz->esq, e_min, e_max);
        raiz->dir = percorreArvore(raiz->dir, e_min, e_max);
        raiz->chave = min(raiz->esq->chave, raiz->dir->chave);
    }
    //atribua emax a emin
    else{
        if(raiz->chave == e_min){
            raiz->chave = e_max;
        }
    }
    return raiz;
}

NoArvore* liberaArvore(NoArvore* raiz){
    //se a raiz não for vazia
    if (raiz != NULL){
        //percorra até chegar nas folhas e a delete
        raiz->esq = liberaArvore(raiz->esq);
        raiz->dir = liberaArvore(raiz->dir);
        delete raiz;
    }
    return NULL;
}

/* =============================================================================== */

int maiorElemento(int *elementos, int quant){
    int valor = 0;
    if(quant == 1)
        valor = elementos[0];
    else{
        valor = maiorElemento(elementos, quant - 1);
        if(valor < elementos[quant - 1])
            valor = elementos[quant - 1];
    }
    return valor;
}

int valorNo(NoArvore *no){
    return no->chave;
}

int alturaArvore(int tamanho){
    return ceil(log2(tamanho)) + 1;
}

int eMin(NoArvore *raiz){
    return raiz->chave;
}