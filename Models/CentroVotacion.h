#ifndef CENTRO_VOTACION_H
#define CENTRO_VOTACION_H

#include "../Libs/Cola/Cola.h"
#include "Estudiante.h"
#include "Mesa.h"

class CentroVotacion {
private:
  Lista<Mesa> listaMesas;
  Cola<Estudiante> colaEstudiante;

public:
  CentroVotacion();
};

#endif // CENTRO_VOTACION_H
