//
// Created by emanuel on 12/2/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "playlist.h"
#include "funcoes_part1.h"

bool Tocar(PL playlist, int *atual){

    if(playlist->first == NULL){

        printf("Ainda não foi adicionada nenhuma musica!!!\n");
        return false;

    }

    if(*atual == -1){

        (*atual)++;
        return true;

    }

    return true;
}

bool Pausar(PL playlist){

    if(playlist->size == -1){
        printf("Playlist vazia!");
        getchar();
        return false;
    }

    return false;
}

int Parar(PL playlist){

    if(playlist->size == -1) {
        printf("Playlist vazia!");
        getchar();
    }

    return -1;
}

int Avancar_musica(PL playlist, int *atual){

    if(playlist->size == -1) {
        printf("Playlist vazia!");
        getchar();

        return -1;
    }

    if(*atual == playlist->size) return 0;

    return (*atual) + 1;

}

int Retroceder_musica(PL playlist, int *atual){

    if(playlist->size == -1) {
        printf("Playlist vazia!");
        getchar();

        return -1;
    }

    if(*atual == 0) return playlist->size;

    return (*atual) - 1;

}




