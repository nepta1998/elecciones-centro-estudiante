#include "CentroVotacion.h"

CentroVotacion::CentroVotacion(){};

// metodos lista
bool CentroVotacion::InsertarMesa(Mesa mesa) {
  return this->listaMesas.InsComienzo(mesa);
};
bool CentroVotacion::RemoverMesa(string terminalCedula) {
  ApuntM primero = this->listaMesas.ObtPrimero();
  Mesa PrimeraMesa = this->listaMesas.ObtInfo(primero);
  if (PrimeraMesa.getTerminalCedula() == terminalCedula) {
    ApuntM apunt = primero;
    ApuntM prox = this->listaMesas.ObtProx(primero);
    this->listaMesas.AsigPrimero(prox);
    delete apunt;
    return true;
  }
  ApuntM recorrer = primero;
  while (this->listaMesas.ObtProx(recorrer) != NULL) {
    ApuntM prox = this->listaMesas.ObtProx(recorrer);
    Mesa mesa = this->listaMesas.ObtInfo(recorrer);
    if (mesa.getTerminalCedula() == terminalCedula) {
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
Lista<Mesa> CentroVotacion::getListaMesas() { return this->listaMesas; }

nodo<Mesa> *CentroVotacion::BuscarMesa(string terminalCedula) {
  Lista<Mesa> ls = this->listaMesas;
  ApuntM ap = this->listaMesas.ObtPrimero();
  while (ap != NULL) {
    Mesa me = this->listaMesas.ObtInfo(ap);
    if (me.getTerminalCedula() == terminalCedula) {
      return ap;
    }
    ap = this->listaMesas.ObtProx(ap);
  }
  return ap;
};

nodo<Estudiante> *CentroVotacion::BuscarEstudianteMesa(string cedula) {
  string terminalCedula = string(cedula.back(), 1);
  ApuntM apMesa = this->BuscarMesa(terminalCedula);
  ApuntE apEst = NULL;
  if (apMesa != NULL) {
    Mesa mesa = this->listaMesas.ObtInfo(apMesa);
    ApuntE apEst = mesa.BuscarEstudianteByCedula(cedula);
    if (apEst != NULL) {
      return apEst;
    }
  }
  return apEst;
};

bool CentroVotacion::EliminarEstudianteMesa(string cedula) {
  string terminalCedula = string(cedula.back(), 1);
  ApuntM apMesa = this->BuscarMesa(terminalCedula);
  ApuntE apEst = NULL;
  if (apMesa != NULL) {
    Mesa mesa = this->listaMesas.ObtInfo(apMesa);
    ApuntE apEst = mesa.BuscarEstudianteByCedula(cedula);
    if (apEst != NULL) {
      Estudiante est = mesa.getEstudiantes().ObtInfo(apEst);
      return mesa.RemoverEstudianteByCedula(est.getCedula());
    }
  }
  return false;
};

bool CentroVotacion::InsertarEstudianteMesa(Estudiante estudiante) {
  string terminalCedula = string(estudiante.getCedula(), 1);
  ApuntM apMesa = this->BuscarMesa(terminalCedula);
  ApuntE apEst = NULL;
  if (apMesa != NULL) {
    Mesa mesa = this->listaMesas.ObtInfo(apMesa);
    ApuntE apEst = mesa.BuscarEstudianteByCedula(estudiante.getCedula());
    if (apEst == NULL) {
      return mesa.InsertarEstudiante(estudiante);
    }
  }
  return false;
};

bool CentroVotacion::InsertarEstudianteCola(string cedula) {
  string terminalCedula = string(cedula.back(), 1);
  ApuntM apMesa = this->BuscarMesa(terminalCedula);
  ApuntE apEst = NULL;
  if (apMesa != NULL) {
    Mesa mesa = this->listaMesas.ObtInfo(apMesa);
    ApuntE apEst = mesa.BuscarEstudianteByCedula(cedula);
    if (apEst != NULL) {
      Estudiante est = mesa.getEstudiantes().ObtInfo(apEst);
      if (!this->EstaEstudianteEnCola(cedula)) {
        return this->colaEstudiantes.Insertar(est);
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
void CentroVotacion::RemoverEstudianteCola(string cedula) {
  Estudiante est;
  Cola<Estudiante> Cest;
  while (!this->colaEstudiantes.Vacia()) {
    this->colaEstudiantes.Remover(est);
    if (!(est.getCedula() == cedula)) {
      Cest.Insertar(est);
    }
  }
  this->colaEstudiantes = Cest;
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
