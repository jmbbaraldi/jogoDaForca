#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>
#include <cctype>

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

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem) {

        //Status do jogo
        cout << mensagem;
        cout << "\nPalavra: " << palavraComMascara << " | Tamanho da palavra: " << tamanhoDaPalavra;
        cout << "\nTentativas Restantes: " << tentativasRestantes;

        //Exibe as letras arriscadas
        int i;
        cout << "\nLetras arriscadas: ";
        for (i = 0; i < letrasJaArriscadas.size(); i++) {
            cout << letrasJaArriscadas[i] << ", ";
        }

}

int jogarSozinho() {

    //Palavra a ser adivinhada
    string palavra = retornaPalavraAleatoria();

    //Tamanho da palavra
    int tamanhoDaPalavra = palavra.size();

    //Palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    ///Variáveis Gerais
    int tentativas = 0, maximoDeTentativas = 10;        //Número de tentativas
    int i = 0;                                          //Auxiliar de laços de repetição
    char letra;                                         //Letra arriscada pelo usuário
    int opcao;                                          //Opções finais
    string letrasJaArriscadas;                          //Acumula as tentativas do jogador
    string mensagem = "Bem-vindo ao jogo";              //Feedback do jogador
    string palavraArriscada;                            //Tentativa de arriscar a palavra completa
    bool jaDigitouLetra = false, acertouLetra = false;  //Auxiliar para saber se a letra foi ja foi digitada

    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0) {

        limpaTela();

        //Exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);

        //Palpite
        cout << "\nDigite uma letra (Ou digite 1 para arriscar a palavra): ";
        cin >> letra;

        //Permite o usuário arriscar a palavra inteira
        if(letra == '1') {
            cout << "\nSeu palpite(Palavra exata): ";
            cin >> palavraArriscada;
            if (palavraArriscada == palavra) {
                palavraComMascara = palavraArriscada;
            }
            else {
                tentativas = maximoDeTentativas;
            }
        }

        //Percorre as letras já arriscadas
        for(i = 0; i < tentativas; i++) {
            if(letrasJaArriscadas[i] == letra) {
                mensagem = "Essa letra ja foi digitada!";
                //Atualiza o booleano
                jaDigitouLetra = true;
            }
        }

        if(jaDigitouLetra == false) {
            letrasJaArriscadas += letra;

            //Percorre a palavra e se a letra existir muda a palavra com máscara
            for(i = 0; i < tamanhoDaPalavra; i++) {
                //Se a letra existir
                if(palavra[i] == letra || palavra[i] == toupper(letra) || palavra[i] == tolower(letra)) {
                    //Faz a letra aparecer na palavra com máscara
                    palavraComMascara[i] = palavra[i];

                    acertouLetra = true;
                }
            }

            if(acertouLetra == false) {
                mensagem = "Voce errou uma letra!";
            }
            else {
                mensagem = "Voce acertou uma letra!";
            }

            //Aumenta uma tentativa realizada
            tentativas++;
        }

        //Reinicia variáveis auxiliares
        jaDigitouLetra = false;
        acertouLetra = false;

    }


    if(palavra == palavraComMascara) {
        //Vitória
        limpaTela();
        cout << "Parabens! Voce acertou a palavra";
        cout << "\nDeseja reiniciar? ";
        cout << "\n1 - Sim";
        cout << "\n2 - Nao\n";
        cin >> opcao;
        return opcao;
    }
    else {
        //Derrota
        limpaTela();
        cout << "O numero de tentativas se esgotou!";
        cout << "\nDeseja reiniciar? ";
        cout << "\n1 - Sim";
        cout << "\n2 - Nao\n";
        cin >> opcao;
        return opcao;
    }
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
            if(jogarSozinho() == 1) {
                menuInicial();
            }

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
