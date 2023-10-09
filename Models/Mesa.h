#ifndef MESA_H
#define MESA_H

#include "../Libs/Lista/Lista.cpp"
#include "Estudiante.h"

class Mesa {
private:
  string terminalCedula;
  string nombreEncargado;
  Lista<Estudiante> ListaEstudiantes;

public:
  Mesa();
  Mesa(string terminalCedula, string nombreEncargado);
  // getters and setters
  void setTerminalCedula(string terminalCedula);
  string getTerminalCedula();
  void setNombreEncargado(string nombreEncargado);
  string getNombreEncargado();
  // metodos lista
  void InsertarEstudiante(Estudiante estudiante);
  bool RemoverEstudianteByCedula(string cedula);

  Lista<Estudiante> getEstudiantes() const;
};

#endif // MESA_H
