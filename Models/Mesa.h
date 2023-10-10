#ifndef MESA_H
#define MESA_H

#include "../Libs/Lista/Lista.cpp"
#include "Estudiante.cpp"

class Mesa {

private:
  typedef nodo<Estudiante> *Apunt;
  char terminalCedula;
  Lista<Estudiante> ListaEstudiantes;

public:
  Mesa();
  Mesa(char terminalCedula);
  // getters and setters
  void setTerminalCedula(char terminalCedula);
  char getTerminalCedula();
  // metodos lista
  bool InsertarEstudiante(Estudiante estudiante);
  bool RemoverEstudianteByCedula(string cedula);
  Apunt BuscarEstudianteByCedula(string cedula, Lista<Estudiante> *lm);

  Lista<Estudiante>* getEstudiantes();
};

#endif // MESA_H
