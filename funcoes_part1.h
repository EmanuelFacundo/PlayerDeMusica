//
// Created by emanuel on 12/2/2018.
//

#ifndef UNTITLED2_FUNCOES_PART1_H
#define UNTITLED2_FUNCOES_PART1_H

//UNTITLED2_FUNCOES_PART1_H

#include <stdbool.h>
#include "playlist.h"

bool Tocar(PL playlist, int* atual);

bool Pausar(PL playlist);

int Parar(PL playlist);

int Avancar_musica(PL playlist, int *atual);

int Retroceder_musica(PL playlist, int *atual);

#endif