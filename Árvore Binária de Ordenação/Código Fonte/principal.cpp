#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include "ArvoreOrdenacao.h"

/**
 * @author Pedro Botelho
 * @date 11-07-2019 
 * 
 */

using namespace std;

int main(){
    //variáveis de controle
    int control, tamanho_vetor;
    string elementos_arquivo;

    //entrada e saída
    ifstream entrada;
    ofstream saida;

    entrada.open("vetores.txt");
    saida.open("ordenados.txt");

    //enquanto o arquivo de entrada estiver aberto
    while(entrada.is_open()){
        //passe a primeira linha a variavel String
        entrada >> elementos_arquivo;
        //converta pra int e use-a de tamanho pro vetor
        tamanho_vetor = stoi(elementos_arquivo);
        //continue se não for 0
        if(tamanho_vetor != 0){
            //passe todos os elementos do arquivo pra esse vetor
            int elementos[tamanho_vetor];
            for(control = 0; control < tamanho_vetor; control++){
                entrada >> elementos_arquivo;
                int valor = stoi(elementos_arquivo);
                elementos[control] = valor;
            }
            //cria a árvore e retorna para um nó raiz, para poder acessa-la
            NoArvore *raiz = criarArvore(elementos, tamanho_vetor);
            //tamanho final do vetor
            int n = pow(2, alturaArvore(tamanho_vetor) - 1);
            //enquanto n não for 0 faça
            while(n > 0){
                //se o valor na raiz for diferente do maior elemento passe-o para a saida
                if(valorNo(raiz) != (maiorElemento(elementos, tamanho_vetor) + 1))
                    saida << valorNo(raiz) << " "; 
                //chame a função para percorrer a arvore e atribuir emax a emin
                percorreArvore(raiz, eMin(raiz), maiorElemento(elementos, tamanho_vetor) + 1);     
                n--;
            }
            saida << endl;
            //libere a arvore
            liberaArvore(raiz);       
        }
        else{
            entrada.close();
        }
    }
    //feche o arquivo de saida e vá simbora!
    saida.close();
    return 0;
}