#include <iostream>
#include<iomanip>
#include <string>
#include <cstring>
#include <windows.h>
#include <ctype.h>

using namespace std;

int main() {

    int validator, tamanho_palavra, letras, numero_tentativas = 0, letras_acertadas = 0, chances = 5;
    string palavra, secreta, tentadas;
    char tentativa[1];
    bool acerto = false;
    bool verifica_tentativa=false;
    int i;

    cout << "--------------- JOGO DA FORCA ---------------" << endl << "\n\nDigite a palavra a ser adivinhada: ";

    cin >> palavra;

    cout << "\nIniciando em 3..." << endl;
    Sleep(1*1000);

    cout << "\nIniciando em 2..." << endl;
    Sleep(1*1000);

    cout << "\nIniciando em 1..." << endl;
    Sleep(1*1000);

    system("cls");

    tamanho_palavra = palavra.size();


    for (i=0;i<tamanho_palavra;i++)
        secreta[i]='_';                 //preenche uma string com o _ para mostrar ao usu�rio de acordo com o tamanho da palavra secreta

    while ((chances>0)&&(letras_acertadas<tamanho_palavra)){
        cout << "Chances restantes: " << chances <<endl;

        cout << "Palavra Secreta: ";

        for (i=0;i<tamanho_palavra;i++){
            cout << secreta[i] << " ";
        }

        do {
         cout << "\n\nDigite a letra: ";
         cin >> tentativa[0];
         numero_tentativas++;
         tentadas[numero_tentativas] = tentativa[0];
         verifica_tentativa = false;

         for(i=0;i<numero_tentativas;i++){   //loop para evitar que o usu�rio repita letras

            if(tentadas[i]==tentativa[0]){
                verifica_tentativa = true;
                cout << "\nLetra ja tentada, por favor, escolha outra!\n-------------------------------------";
                numero_tentativas--;
                }
         }

         } while((!((tentativa[0] >= 65 && tentativa[0] <= 90)|| (tentativa[0] >= 97 && tentativa[0] <= 122)))
                 ||verifica_tentativa==true); //verifica se a tentativa � v�lida, caso n�o, repete o loop at� isso acontecer

         for(i=0;i<tamanho_palavra;i++){
            if(palavra[i]==tentativa[0]){
                acerto=true;
                secreta[i]=tentativa[0];
                letras_acertadas++;
            }
         }

         if(!acerto){
                chances--;
            }

         acerto=false;
         system("cls");

         if(letras_acertadas==tamanho_palavra){
            cout << "Parabens, voce venceu! :D\n\n";
         }

         if(chances==0){
            cout << "Voce perdeu :/" << endl;
         }
    }
}
