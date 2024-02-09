#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela() {
    system("CLS");
}

string retornaPalavraAleatoria() {
    //Vetor com palavras disponíveis
    string palavras[3] = {"Abacaxi", "Manga", "Morango"};

    //Imprime ou 0 ou 1 ou 2
    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra) {
    //Auxiliar contadora
    int cont = 0;
    string palavraComMascara;

    //Aplica a máscara
    while(cont < tamanhoDaPalavra) {
        palavraComMascara += "_";
        cont ++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes) {

        //Status do jogo
        cout << "Palavra: " << palavraComMascara << " | Tamanho da palavra: " << tamanhoDaPalavra;
        cout << "\nTentativas Restantes: " << tentativasRestantes;
}

void jogarSozinho() {

    //Palavra a ser adivinhada
    string palavra = retornaPalavraAleatoria();

    //Tamanho da palavra
    int tamanhoDaPalavra = palavra.size();

    //Palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    int tentativas = 0, maximoDeTentativas = 5;
    char letra;

    while(maximoDeTentativas - tentativas > 0) {

        limpaTela();

        //Exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas);

        //Palpite
        cout << "\nDigite uma letra: ";
        cin >> letra;

        //Aumenta uma tentativa realizada
        tentativas++;
    }

    cout << "A palavra secreta eh " << palavra << " | Tamanho da palavra: " << tamanhoDaPalavra;
    cout << "\nMascara: " << palavraComMascara;
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
