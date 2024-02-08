#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela() {
    system("CLS");
}

void jogarSozinho() {
    //Vetor com palavras disponíveis
    string palavras[3] = {"Abacaxi", "Manga", "Morango"};

    //Imprime ou 0 ou 1 ou 2
    int indiceAleatorio = rand() % 3;

    cout << indiceAleatorio;
}

void menuInicial() {
    int opcao = 0;

    while(opcao < 1 || opcao > 3) {
        limpaTela();
        cout << "Bem-vindo ao Jogo da Forca";
        cout << "\n1- Jogar";
        cout << "\n2- Sobre";
        cout << "\n3- Sair";
        cout << "\nEscolha uma opcao e tecle Enter: ";
        cin >> opcao;

        switch(opcao) {
        case 1:
            //Inicia o jogo
            cout << "Jogo iniciado\n";
            jogarSozinho();

            break;

        case 2:
            //Informações do jogo
            cout << "Informacoes do jogo: ";
            break;

        case 3:
            //Saiu
            cout << "Ate mais!";
            break;
        }
    }
}

int main() {
    //Gera números aleatórios
    srand( (unsigned)time(NULL));

    menuInicial();

    return 0;
}
