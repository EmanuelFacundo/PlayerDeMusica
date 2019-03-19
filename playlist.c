//
// Created by emanuel on 12/2/2018.
//
#include <stdlib.h>
#include <string.h>

#include "playlist.h"

void delete_all_musics(PLNode music){
    if(music != NULL){
        delete_all_musics(music->next);
        free(music);
    }
}

void delete_music(PLNode music) {
    free(music);
}

PLNode Music_new(char *value) {

    PLNode music = (PLNode)malloc(sizeof(struct playlist_node));

    strcpy(music->musica, value);
    music->next = NULL;

    return music;
}

PL playlist_new(){

    PL new = malloc(sizeof(struct playlist));

    new->first = NULL;

    return new;
}







