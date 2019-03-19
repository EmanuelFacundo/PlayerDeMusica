//
// Created by emanuel on 12/2/2018.
//

#ifndef UNTITLED2_FUNCOES_PART2_H
#define UNTITLED2_FUNCOES_PART2_H

//UNTITLED2_FUNCOES_PART2_H
#include <stdbool.h>

#include "playlist.h"

void Estado_atual(PL playlistool, bool flag, int* musica);

void Inserir_musica(PL playlist, int* musicas, int size, bool estado);

void Remover_musica(PL playlist, bool estado, int* Atual);

void Mostrar_playlist(PL playlist, int* Atual, bool estado);

#endif