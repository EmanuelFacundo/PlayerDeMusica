//
// Created by emanuel on 12/2/2018.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "playlist.h"


//void Mostrar_playlist(PL playlist, int* Atual, bool estado);

void Estado_atual(PL playlist, bool flag, int* musica){

    if(playlist->size == -1){
        printf("Playlist vazia!");
        getchar();
        return;
    }
    PLNode musica_atual = playlist->first;

    if(flag == false){
        if(*musica == -1){
            printf("No momento nenhuma musica estar tocando e nem pausada\n");
            return;
        }

        for(int i = 0;i < *musica; i++){
            musica_atual = musica_atual->next;
        }

        printf("->%s (Pausada)\n", musica_atual->musica);
        getchar();

    }else{
        for (int j = 0; j < *musica; ++j) {
            musica_atual = musica_atual->next;
        }

        printf("->%s (Tocando)\n", musica_atual->musica);
        getchar();
    }

}

void Mostrar_playlist(PL playlist, int* Atual, bool estado){

    if(playlist->size == -1){

        printf("-> Playlist vazia!\n\n");

        return;
    }

    printf("\n-> Playlist Abaixo!\n\n");    

    PLNode music = playlist->first;

    int i = 1;

    while(music != NULL){
        if(*Atual == i - 1){
            if(estado == true)
                printf("%i - %s(Música Atual 'Tocando')\n", i, music->musica);
            else
                printf("%i - %s(Música Atual 'Pausada')\n", i, music->musica);
        }else{
            printf("%i - %s\n", i,music->musica);
        }
        music = music->next;
        i++;
    }

    printf("\n");

}

void Inserir_musica(PL playlist, int* musicas, int size, bool estado) {

    int op = 0;
    PLNode musica = playlist->first;

    if (size == -1) {

        char new_mus[11];

        printf("Qual é a primeira música a ser inserida na playlist?(são aceitas músicas de até 10 caracteres)\n");
        scanf(" %[^\n]s", new_mus);

        PLNode new_music = Music_new(new_mus);
        playlist->first = new_music;

        playlist->size++;

    } else {
        Mostrar_playlist(playlist, musicas, estado);

        printf("Apôs qual musica você deseja inserir a nova musica?(0 para inserir no começo)\n");
        scanf("%d", &op);

        if (op > size + 2) {
            printf("\nOpção invalida!!!\n");
            getchar();
        } else if (op == 0) {

            char new_mus[11];

            printf("Qual é a nova música?(são aceitas músicas de até 10 caracteres)\n");
            scanf(" %[^\n]s", new_mus);

            PLNode new_musica = Music_new(new_mus);

            new_musica->next = musica;
            playlist->first = new_musica;

            playlist->size++;

        } else if (op == size - 1) {

            char new_mus[11];

            printf("Qual é a nova música?(são aceitas músicas de até 10 caracteres)\n");
            scanf(" %[^\n]s", new_mus);

            while (musica->next != NULL) {
                musica = musica->next;
            }

            PLNode new_musica = Music_new(new_mus);

            musica->next = new_musica;

            playlist->size++;
        } else {
            int i = 0;
            while (i < op - 1 && musica != NULL) {
                i++;
                musica = musica->next;
            }

            char new_mus[11];

            printf("Qual é a nova música?(são aceitas músicas de até 10 caracteres)\n");
            scanf(" %[^\n]s", new_mus);

            if (musica != NULL) {

                PLNode new_musica = Music_new(new_mus);

                new_musica->next = musica->next;
                musica->next = new_musica;
            }

            playlist->size++;
        }

    }
}

void Remover_musica(PL playlist, bool estado, int* Atual){

    int escolha = 0;

    if(playlist->size == -1){
        printf("Playlist vazia!\n");
        getchar();
        return;
    }

    PLNode ant_music = playlist->first;

    Mostrar_playlist(playlist, Atual, estado);

    printf("Qual musica você deseja excluir?\n");
    scanf("%d", &escolha);

    if(escolha == 1){

        playlist->first = ant_music->next;
        delete_music(ant_music);
        playlist->size--;

    }else if(escolha == playlist->size + 1){

        while(ant_music->next->next != NULL){
            ant_music = ant_music->next;
        }

        PLNode rip_music = ant_music->next->next;
        ant_music->next = NULL;
        delete_music(rip_music);

        playlist->size--;

    }else if(escolha > playlist->size + 1){

        printf("Opção invalida!!!\n");
        getchar();

    }else{
        int i = 0;

        while(i < escolha - 2 && ant_music != NULL){
            i++;
            ant_music = ant_music->next;
        }

        if(ant_music != NULL){
            PLNode rip_music = ant_music->next;
            ant_music->next = ant_music->next->next;
            delete_music(rip_music);
        }

        playlist->size--;

    }
}