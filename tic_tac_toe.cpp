#include<iostream>
#include<string>
#include<stdlib.h>
#include<limits>
#define TAM 3

//corrigir o lance das letras e numeros acima de 8

using namespace std;

void jogo();
void popular(char tabuleiro[TAM][TAM]);
void exibe_tabu(char tabuleiro[TAM][TAM]);
void exibe_guia();
int ver_pos(char tabuleiro[TAM][TAM], int, int usados[9], char, string *, int);
int conferir(char tabuleiro[TAM][TAM],bool * winner);
void limpa_tela();
void menu_inicial();

int main(){

    menu_inicial();

}

void limpa_tela(){

    system("CLS");

}

void menu_inicial(){

    int opcao;
    do{
  
        limpa_tela();

        cout << "\nBem vindo ao Jogo da Velha!";
        cout << "\n[1] Jogar";
        cout << "\n[2] Sobre";
        cout << "\n[3] Sair";
        cout << "\n\nEscolha uma opcao e aperte Enter\n";

        cin >> opcao;

        switch(opcao){

            case 1:

                jogo();
                
                break;

            case 2:

                cout << "\nJogo criado por Kevin em 2022\n\n";
                
                system("pause");

                break;

            case 3:


                cout << "\nSaindo!!!";

                break;

            default:

                cout << "Escolha Inválida";

                exit(EXIT_FAILURE);
                break;
        }
    }while(opcao < 3);
}

//1 = X venceu, 2 = O venceu, 0 = Nada Aconteceu
int conferir(char tabuleiro[TAM][TAM], bool * winner){
 
        int linha, coluna;

        int who = 0;
        //Confere linhas
        for(linha = 0; linha < 3; linha++){

            if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){

                who = 1;

                *winner = true;

            }else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){

                who = 2;

                *winner = true;

            }

        }
 
        //Confere Colunas
        for(coluna = 0; coluna < 3; coluna++){

            if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                
                who = 1;

                *winner = true;

            }else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){

                who = 2;
                
                *winner = true;
            }

        }
 
        //Diagonal Principal
        if(tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
 
            if(tabuleiro[0][0] == 'X'){

               who = 1;
                
                *winner = true;

            }else{

               who = 2;

               *winner = true;

            }

        }
 
        //Diagonal Secundária
        if(tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
 
            if(tabuleiro[0][2] == 'X'){

                who = 1;

                *winner = true;

            }else{

               who = 2;

               *winner = true;

            }

        }
 
        return who;
}

void exibe_tabu(char tabuleiro[TAM][TAM]){

    int linha, coluna;
    
    cout << "\n\n";
    for(linha = 0; linha < TAM; linha++){

        for(coluna = 0; coluna < TAM; coluna ++){

            cout << "[" << tabuleiro[linha][coluna] << "] ";
        }

        cout << "\n";

    }

}

void exibe_guia(){

    int guia[9];

    int i;
    for(i = 0; i < 9; i++){

        guia[i] = i;

    }

    for(i = 0; i < 3; i++){

        cout << "[" << guia[i] << "] ";

    }
    cout << "\n";
    for(i = 3; i < 6; i++){

        cout << "[" << guia[i] << "] ";

    }
    cout << "\n";
    for(i = 6; i < 9; i++){

        cout << "[" << guia[i] << "] ";

    }
    cout << "\n";

}
void popular(char tabuleiro[TAM][TAM]){

    int linha, coluna;

    for(linha = 0; linha < TAM; linha++){

        for(coluna = 0; coluna < TAM; coluna ++){

            tabuleiro[linha][coluna] = ' ';

        }

    } 

}

int ver_pos(char tabuleiro[TAM][TAM], int pos, int usados[9], char player, string * mensagem, int tentados){
    
    int tents = tentados;
    bool usado = false;

    for(int i = 0; i < 9; i++){
       
        if(pos == usados[i]){

            usado = true;

        }

    }

    if(usado == false){
        switch (pos){
            case 0:

                tabuleiro[0][0] = player;

                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[0] = 0;

                tents++;

            break;
            case 1:

                tabuleiro[0][1] = player;

                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[1] = 1;

                tents++;

            break;
            case 2:

                tabuleiro[0][2] = player;

                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[2] = 2;

                tents++;

            break;
            case 3:

                tabuleiro[1][0] = player;

                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[3] = 3;

                tents++;

            break;
            case 4:

                tabuleiro[1][1] = player;

                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[4] = 4;

                tents++;

            break;
            case 5:

                tabuleiro[1][2] = player;

                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[5] = 5;

                tents++;

            break;
            case 6:

                tabuleiro[2][0] = player;

                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[6] = 6;

                tents++;

            break;
            case 7:

                tabuleiro[2][1] = player;
             
                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[7] = 7;

                tents++;

            break;
            case 8:

                tabuleiro[2][2] = player;

                *mensagem = "\nSua jogada foi posicionada.\n";

                usados[8] = 8;

                tents++;

            break;
            default:

            *mensagem = "\nPosicao fora dos limites!!!\n";
            break;
        }

    }else{

        *mensagem = "\nEsta posicao ja foi usada!!!";

    }

    return tents;


}
void jogo(){

    cout << "\n\n";
    string jogador = "Jogador 1";
    string mensagem = "Jogo Comecado!!!";
    bool winner = false;
    char tabuleiro[TAM][TAM];
    int posicao, usados[9];
    for(int u = 0; u < 9; u++){
        usados[u] = -1;
    }
    int p1 = 1, p2 = 2;
    int player = p1;
    popular(tabuleiro);
    char marca;
    int who, escolha, tentados = 0;

    do{

        if(player == p1){

            marca = 'X';

        }else{

            marca = 'O';

        }
        exibe_tabu(tabuleiro);

        exibe_guia();
        
        do{
        
            cout << "\n" << jogador << "\ndigite uma posicao:\n";

            cin >> posicao; 

            while (cin.fail()) { 
                
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
                cout << "Por favor, digite uma posicao valida :\n";
                cin >> posicao; 
            }

        }while(posicao < 0 || posicao > 8);
        //
        tentados = ver_pos(tabuleiro, posicao, usados, marca, &mensagem, tentados);

        who = conferir(tabuleiro, &winner);

        if(player % 2 == 0){

            player = p1;
            jogador = "jogador 1, eh a sua vez.\n";
        }else{

            player = p2;
            jogador = "jogador 2, eh a sua vez.\n";

        }
        
    }while(winner == false && tentados < 9);

    mensagem = "\nDeseja jogar outra partida?\n[1]Sim\n[2]Nao\n\n";

    limpa_tela();

    exibe_tabu(tabuleiro);
    
    if(who == 1){
        
        cout << "\n\nParabens player 1, voce ganhou a partida!!";

    }else if(who == 2){

        cout << "\n\nParabens player 2, voce ganhou a partida!!";

    }else{

        cout <<"\n\nEmpate!!!";

    }

    cout << mensagem;

    cin >> escolha;

    if(escolha == 1){

        jogo();

    }else{

        cout << "\n\nAte mais...\n";

    }

}