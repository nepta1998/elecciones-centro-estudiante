#include "Mesa.h"

Mesa::Mesa(){};
Mesa::Mesa(string terminalCedula, string nombreEncargado) {
  this->terminalCedula = terminalCedula;
  this->nombreEncargado = nombreEncargado;
};
// getters and setters
void Mesa::setTerminalCedula(string terminalCedula) {
  this->terminalCedula = terminalCedula;
};
string Mesa::getTerminalCedula() { return this->terminalCedula; };
void Mesa::setNombreEncargado(string nombreEncargado) {
  this->nombreEncargado = nombreEncargado;
};
string Mesa::getNombreEncargado() { return this->nombreEncargado; };
// metodos lista
void Mesa::InsertarEstudiante(Estudiante estudiante) {
  this->ListaEstudiantes.InsComienzo(estudiante);
};
typedef nodo<Estudiante> *Apunt;
bool Mesa::RemoverEstudianteByCedula(string cedula) {
  Apunt primero = this->ListaEstudiantes.ObtPrimero();
  Estudiante primerEstudiante = this->ListaEstudiantes.ObtInfo(primero);
  if (primerEstudiante.getCedula() == cedula) {
    Apunt apunt = primero;
    Apunt prox = this->ListaEstudiantes.ObtProx(primero);
    this->ListaEstudiantes.AsigPrimero(prox);
    delete apunt;
    return true;
  }
  Apunt recorrer = primero;
  while (this->ListaEstudiantes.ObtProx(recorrer) != NULL) {
    Apunt prox = this->ListaEstudiantes.ObtProx(recorrer);
    Estudiante estudiante = this->ListaEstudiantes.ObtInfo(recorrer);
    if (estudiante.getCedula() == cedula) {
      Apunt apunt = prox;
      prox = this->ListaEstudiantes.ObtProx(prox);
      this->ListaEstudiantes.AsigProx(recorrer, prox);
      delete apunt;
      return true;
    }
    recorrer = prox;
  }
  return false;
};

Lista<Estudiante> Mesa::getEstudiantes() const {
  return this->ListaEstudiantes;
};
