#ifndef MESA_H
#define MESA_H

#include "../Libs/Lista/Lista.cpp"
#include "Estudiante.h"

class Mesa {
private:
  int numeroMesa;
  string nombreEncargado;
  Lista<Estudiante> ListaEstudiantes;

public:
  Mesa();
  Mesa(int numeroMesa, string nombreEncargado);
  // getters and setters
  void setNumerMesa(int numeroMesa);
  int getNumeroMesa();
  void setNombreEncargado(string nombreEncargado);
  string getNombreEncargado();
  // metodos lista
  void InsertarEstudiante(Estudiante estudiante);
  bool RemoverEstudianteByCedula(string cedula);

  Lista<Estudiante> getEstudiantes() const;
};

#endif // MESA_H
