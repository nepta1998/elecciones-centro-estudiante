#include "CentroVotacion.h"

CentroVotacion::CentroVotacion(){};

// metodos lista
bool CentroVotacion::InsertarMesa(Mesa mesa) {
  return this->listaMesas.InsComienzo(mesa);
};
bool CentroVotacion::RemoverMesa(char terminalCedula) {
  ApuntM primero = this->listaMesas.ObtPrimero();
  Mesa* PrimeraMesa = this->listaMesas.ObtInfo(primero);
  if (PrimeraMesa->getTerminalCedula() == terminalCedula) {
    ApuntM apunt = primero;
    ApuntM prox = this->listaMesas.ObtProx(primero);
    this->listaMesas.AsigPrimero(prox);
    delete apunt;
    return true;
  }
  ApuntM recorrer = primero;
  while (this->listaMesas.ObtProx(recorrer) != NULL) {
    ApuntM prox = this->listaMesas.ObtProx(recorrer);
    Mesa* mesa = this->listaMesas.ObtInfo(prox);
    if (mesa->getTerminalCedula() == terminalCedula) {
      ApuntM apunt = prox;
      prox = this->listaMesas.ObtProx(prox);
      this->listaMesas.AsigProx(recorrer, prox);
      delete apunt;
      return true;
    }
    recorrer = prox;
  }
  return false;
};
Lista<Mesa> *CentroVotacion::getListaMesas() { return &this->listaMesas; }
nodo<Mesa> *CentroVotacion::BuscarMesa(char terminalCedula, Lista<Mesa> *lm) {
  ApuntM ap = lm->ObtPrimero();
  while (ap != NULL) {
    Mesa* m = lm->ObtInfo(ap);
    if (m->getTerminalCedula() == terminalCedula) {
      return ap;
    }
    ap = lm->ObtProx(ap);
  }
  return ap;
};

nodo<Estudiante> *CentroVotacion::BuscarEstudianteMesa(string cedula,
                                                       nodo<Mesa> *apMesa) {
  char terminalCedula = cedula.back();
  Mesa* mesa = this->listaMesas.ObtInfo(apMesa);
  ApuntE apEst = mesa->BuscarEstudianteByCedula(cedula, mesa->getEstudiantes());
  if (apEst != NULL) {
    return apEst;
  }
  return apEst;
};

bool CentroVotacion::EliminarEstudianteMesa(string cedula) {
  char terminalCedula = cedula.back();
  ApuntM apMesa = this->BuscarMesa(terminalCedula, &this->listaMesas);
  ApuntE apEst = NULL;
  if (apMesa != NULL) {
    Mesa* mesa = this->listaMesas.ObtInfo(apMesa);
    ApuntE apEst = mesa->BuscarEstudianteByCedula(cedula, mesa->getEstudiantes());
    if (apEst != NULL) {
      Estudiante* est = mesa->getEstudiantes()->ObtInfo(apEst);
      return mesa->RemoverEstudianteByCedula(est->getCedula());
    }
  }
  return false;
};

bool CentroVotacion::InsertarEstudianteMesa(Estudiante estudiante,
                                            nodo<Mesa> *apMesa) {
  char terminalCedula = estudiante.getCedula().back();
  Mesa* mesa = this->listaMesas.ObtInfo(apMesa);
  string ced = estudiante.getCedula();
  ApuntE apEst = mesa->BuscarEstudianteByCedula(
      ced, mesa->getEstudiantes());
  if (apEst == NULL) {
    mesa->InsertarEstudiante(estudiante);
    this->listaMesas.AsigInfo(apMesa, *mesa);
    return true;
  }
  return false;
};

bool CentroVotacion::InsertarEstudianteCola(string cedula) {
  char terminalCedula = cedula.back();
  ApuntM apMesa = this->BuscarMesa(terminalCedula, &this->listaMesas);
  ApuntE apEst = NULL;
  if (apMesa != NULL) {
    Mesa* mesa = this->listaMesas.ObtInfo(apMesa);
    ApuntE apEst = mesa->BuscarEstudianteByCedula(cedula, mesa->getEstudiantes());
    if (apEst != NULL) {
      Estudiante* est = mesa->getEstudiantes()->ObtInfo(apEst);
      if (!this->EstaEstudianteEnCola(cedula)) {
        return this->colaEstudiantes.Insertar(*est);
      }
    }
  }
  return false;
};
bool CentroVotacion::EstaEstudianteEnCola(string cedula) {
  Estudiante est;
  Cola<Estudiante> Cest;
  bool estaEnCola = false;
  while (!this->colaEstudiantes.Vacia()) {
    this->colaEstudiantes.Remover(est);
    if (!(est.getCedula() == cedula)) {
      estaEnCola = true;
    }
    Cest.Insertar(est);
  }
  this->colaEstudiantes = Cest;
  return estaEnCola;
};
bool CentroVotacion::RemoverEstudianteCola(string cedula) {
  Estudiante est;
  Cola<Estudiante> Cest;
  bool eliminado = true;
  while (!this->colaEstudiantes.Vacia()) {
    this->colaEstudiantes.Remover(est);
    if (!(est.getCedula() == cedula)) {
      Cest.Insertar(est);
    }
  }
  this->colaEstudiantes = Cest;
  return eliminado;
}
Estudiante CentroVotacion::ProcesarCola() {
  Estudiante est;
  if (!this->colaEstudiantes.Vacia()) {
    this->colaEstudiantes.Remover(est);
    return est;
  }
  return est;
}

Cola<Estudiante> CentroVotacion::getColaEstudiantes() {
  return this->colaEstudiantes;
}
