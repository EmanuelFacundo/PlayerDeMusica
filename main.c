//
// Created by emanuel on 12/2/2018.
//

#include "Bibliotecas.h"

int main(){

    setlocale(LC_ALL,"portuguese"); //para correção de caracteres.

    char op;
    int atual = -1;
    int* P_atual = &atual;
    bool estado = false;

    PL playlist;
    playlist = playlist_new();

    playlist->size = -1;

    do {

        op = '0';

        Mostrar_playlist(playlist, P_atual, estado);
        printf("\t\tPlayer de Música\n");
        printf("\ta. Tocar            \tf. Estado atual\n");
        printf("\tb. Pausar           \tg. Inserir música\n");
        printf("\tc. Parar            \th. Remover música\n");
        printf("\td. Avançar música   \ti. Mostar playlist\n");
        printf("\te. Retroceder música\tj. Encerrar\n");
        scanf(" %c", &op);
        getchar();

        switch(op){
            case 'a': {

                estado = Tocar(playlist, P_atual);

                break;
            }
            case 'b': {

                estado = Pausar(playlist);

                break;
            }
            case 'c': {

                (*P_atual) = Parar(playlist);
                estado = false;

                break;
            }
            case 'd': {

                (*P_atual) = Avancar_musica(playlist, P_atual);

                break;
            }
            case 'e': {

                (*P_atual) = Retroceder_musica(playlist, P_atual);

                break;
            }
            case 'f': {

                Estado_atual(playlist, estado, P_atual);

                break;
            }
            case 'g': {

                Inserir_musica(playlist, P_atual, playlist->size, estado);

                break;
            }
            case 'h': {

                Remover_musica(playlist, estado, P_atual);

                break;
            }
            case 'i': {

                Mostrar_playlist(playlist, P_atual, estado);

                break;
            }
            case 'j': {

                printf("Volte Sempre!!!\n");
                getchar();

                break;
            }
            default: {

                printf("Opção não existente, tente novamente.\n");

            }

        }

    }while(op != 'j');


    return 0;
}