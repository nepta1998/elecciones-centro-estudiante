#include "Mesa.h"

Mesa::Mesa(){};
Mesa::Mesa(char terminalCedula) {
  this->terminalCedula = terminalCedula;
};
// getters and setters
void Mesa::setTerminalCedula(char terminalCedula) {
  this->terminalCedula = terminalCedula;
};
char Mesa::getTerminalCedula() { return this->terminalCedula; };
// metodos lista
bool Mesa::InsertarEstudiante(Estudiante estudiante) {
  return this->ListaEstudiantes.InsComienzo(estudiante);
};
bool Mesa::RemoverEstudianteByCedula(string cedula) {
  Apunt primero = this->ListaEstudiantes.ObtPrimero();
  Estudiante* primerEstudiante = this->ListaEstudiantes.ObtInfo(primero);
  if (primerEstudiante->getCedula() == cedula) {
    Apunt apunt = primero;
    Apunt prox = this->ListaEstudiantes.ObtProx(primero);
    this->ListaEstudiantes.AsigPrimero(prox);
    delete apunt;
    return true;
  }
  Apunt recorrer = primero;
  while (this->ListaEstudiantes.ObtProx(recorrer) != NULL) {
    Apunt prox = this->ListaEstudiantes.ObtProx(recorrer);
    Estudiante* estudiante = this->ListaEstudiantes.ObtInfo(recorrer);
    if (estudiante->getCedula() == cedula) {
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

nodo<Estudiante> *Mesa::BuscarEstudianteByCedula(string cedula, Lista<Estudiante> *lm) {
  Apunt ap = lm->ObtPrimero();
  while (ap != NULL) {
    Estudiante* estudiante = this->ListaEstudiantes.ObtInfo(ap);
    if (estudiante->getCedula() == cedula) {
      return ap;
    }
    ap = this->ListaEstudiantes.ObtProx(ap);
  }
  return ap;
};

Lista<Estudiante>* Mesa::getEstudiantes(){
  return &this->ListaEstudiantes;
};
