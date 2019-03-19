//
// Created by emanuel on 12/2/2018.
//

#ifndef UNTITLED2_PALYLIST_H
#define UNTITLED2_PALYLIST_H

//UNTITLED2_PALYLIST_H

typedef struct playlist *PL;

typedef struct playlist_node *PLNode;

struct playlist_node{

    char musica[11];
    PLNode next;

};

struct playlist{

    PLNode first;
    int size;

};


PLNode Music_new(char *value);

void delete_music(PLNode music);

PL playlist_new();

#endif