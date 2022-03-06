#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;

};


void limpaTela(){
    system("CLS");
}

int retornaTamanho(pessoa *ponteiroEncadeada){
    if(ponteiroEncadeada->nome == ""){
            return 0;
}
    int tamanho = 0;

    pessoa *p = ponteiroEncadeada;

    while(p != NULL){

        p = p->proximo;
        tamanho++;
    }

    return tamanho;
}

void imprimeEncadeada(pessoa *ponteiroEncadeada){
     pessoa *p = ponteiroEncadeada;

     while(p != NULL){

         cout <<p->nome << "," << p->rg << "\n";

        p = p->proximo;
    }
}

void addComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;

    if(ponteiroEncadeada->nome == ""){
        novoValor->proximo = NULL;
    }else{
        novoValor->proximo = ponteiroEncadeada;
    }

    ponteiroEncadeada = novoValor;

}

void addFimEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeada;

     while(p != NULL){

        if(p->proximo == NULL){

            p->proximo = novoValor;
            return;
        }

        p = p->proximo;
    }

}

void addPosicaoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg, int posicao){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeada;

    int cont = 0;

    while(cont <= posicao){

        if(cont == posicao -1){

            pessoa *aux = new pessoa;

            aux->proximo = p->proximo;

            p->proximo = novoValor;

            novoValor->proximo = aux->proximo;

            free(aux);
        }

        p = p->proximo;

        cont ++;


    }


}

void removeIncioEncadeada(pessoa *&ponteiroEncadeada){

    if(ponteiroEncadeada->proximo == NULL){

        pessoa *novoValor = new pessoa;
        novoValor->nome = "";
        novoValor->rg = 0;
        novoValor->proximo = NULL;

        ponteiroEncadeada = novoValor;

    }else{

        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }

}

void removeFimEncadeada(pessoa *&ponteiroEncadeada){

    pessoa *p = new pessoa;
    pessoa *aux = new pessoa;

    p = ponteiroEncadeada;

    while(p->proximo != NULL){

        aux = p;
        p = p->proximo;

    }

    aux->proximo = NULL;

}

void removePosicaoEncadeada(pessoa *&ponteiroEncadeada, int posicao){

    pessoa *p = ponteiroEncadeada;

    int cont = 0;

    while(cont <= posicao){

        if(cont == posicao -1){

            pessoa *aux = new pessoa;
            aux = p->proximo;

            p->proximo = aux->proximo;

            free(aux);

        }

        p = p->proximo;

        cont ++;

    }


}

string retornaNomeEncadeada(pessoa *&ponteiroEncadeada, int rg){

    string nome = "Nao encontrado";

    pessoa *p = ponteiroEncadeada;

    while(p != NULL){

            if(p->rg == rg){

                nome = p->nome;
                return nome;

            }

            p = p->proximo;

    }

    return nome;

}



int main(){

    //variaveis
    int funcaoDesejada = 1;

    pessoa *ponteiroEncadeada = new pessoa;
    ponteiroEncadeada->nome = "";
    ponteiroEncadeada->rg = 0;
    ponteiroEncadeada->proximo = NULL;

    /*pessoa *novoPrimeiroValor = new pessoa;
    novoPrimeiroValor->nome = "renan";
    novoPrimeiroValor->rg = 1234;
    novoPrimeiroValor->proximo = NULL;

    ponteiroEncadeada = novoPrimeiroValor;

    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "paulao";
    novoSegundoValor->rg = 4321;
    novoSegundoValor->proximo = NULL;


    novoPrimeiroValor->proximo = novoSegundoValor;*/



    while(funcaoDesejada < 9 && funcaoDesejada > 0){


    //mostrar o menu

    cout << "Operacoes \n";
    cout << " 1 - Insercao de um node no inicio da lista. \n";
    cout << " 2 - Insercao de um node no fim da lista. \n";
    cout << " 3 - Insercao de um node na posicao N. \n";
    cout << " 4 - Retirar  um node no inicio da lista. \n";
    cout << " 5 - Retirar  um node no fim da lista. \n";
    cout << " 6 - Retirar  um node na posicao N. \n";
    cout << " 7 - Procurar um node com o campo RG. \n";
    cout << " 8 - Imprimir a lista. \n";
    cout << " 9 - Sair do sistema";
    cout << "\nEscolha um numero e pressione ENTER: \n";
    cout <<"\n\nTamanho Atual:" << retornaTamanho(ponteiroEncadeada) << "\n";


    if(retornaTamanho(ponteiroEncadeada) == 0){
        cout << "Lista Vazia";
        }else{
            imprimeEncadeada(ponteiroEncadeada);
        }


    //ler o que o usuario digitouo
    cin >> funcaoDesejada;

    limpaTela();

    string nome;
    int rg, posicao;

    //chama funcao desejada
    switch(funcaoDesejada){
        case 1:
            cout << "Funcao escolhida: 1 - Insercao de um node no inicio da lista";

            cout << "\nDigite o nome: ";
            cin >> nome;
            cout << "Digite o RG: ";
            cin >> rg;

            addComecoEncadeada(ponteiroEncadeada, nome, rg);

            break;
        case 2:
            cout << "Funcao escolhida: 2 - Insercao de um node no fim da lista.";

            cout << "\nDigite o nome: ";
            cin >> nome;
            cout << "Digite o RG: ";
            cin >> rg;

            if(retornaTamanho(ponteiroEncadeada) == 0){
                    addComecoEncadeada(ponteiroEncadeada, nome, rg);
                }else{
                    addFimEncadeada(ponteiroEncadeada, nome, rg);
                }

            break;
        case 3:
            cout << "Funcao escolhida: 3 - Insercao de um node na posicao N.";

            cout << "\nDigite a  Posicao: ";
            cin >> posicao;
            cout << "\nDigite o nome: ";
            cin >> nome;
            cout << "Digite o RG: ";
            cin >> rg;

            if(posicao == 0){

                    addComecoEncadeada(ponteiroEncadeada, nome, rg);

                }else if(posicao == retornaTamanho(ponteiroEncadeada)-1){

                    addFimEncadeada(ponteiroEncadeada, nome, rg);

                }else{

                    addPosicaoEncadeada(ponteiroEncadeada, nome, rg, posicao);

                }

            break;
        case 4:
            cout << "Funcao escolhida: 4 - Retirar  um node no inicio da lista";

            removeIncioEncadeada(ponteiroEncadeada);

            break;
        case 5:
            cout << "Funcao escolhida: 5 - Retirar  um node no fim da lista.";

             if(retornaTamanho(ponteiroEncadeada) == 1){
                    removeIncioEncadeada(ponteiroEncadeada);
            }else{
                    removeFimEncadeada(ponteiroEncadeada);
                }

            break;
        case 6:
            cout << "Funcao escolhida: 6 - Retirar  um node na posicao N";

            cout << "\nDigite a  Posicao: ";
            cin >> posicao;

            if(posicao == 0){
                removeIncioEncadeada(ponteiroEncadeada);

            }else if(posicao == retornaTamanho(ponteiroEncadeada) -1){
                removeFimEncadeada(ponteiroEncadeada);

            }else{

                removePosicaoEncadeada(ponteiroEncadeada, posicao);

            }

            break;
        case 7:
            cout << "Funcao escolhida: 7 - Procurar um node com o campo RG.";

            cout << "\nDigite o RG: ";
            cin >> rg;

            cout <<"\nO nome do RG " << rg << " eh:" << retornaNomeEncadeada(ponteiroEncadeada, rg) << "\n";

            break;
        case 8:
            cout << "Funcao escolhida: 8";
            break;

    }

}

    return 0;
}
