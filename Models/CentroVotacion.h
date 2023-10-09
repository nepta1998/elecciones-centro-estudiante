#ifndef CENTRO_VOTACION_H
#define CENTRO_VOTACION_H

#include "../Libs/Cola/Cola.cpp"
#include "Mesa.cpp"

class CentroVotacion {

  typedef nodo<Mesa> *ApuntM;
  typedef nodo<Estudiante> *ApuntE;

private:
  Lista<Mesa> listaMesas;
  Cola<Estudiante> colaEstudiante;

public:
  CentroVotacion();
  bool InsertarEstudiante(Estudiante e);

  // metodos mesa
  bool InsertarMesa(Mesa mesa);
  bool RemoverMesa(string terminalCedula);
  nodo<Mesa> *BuscarMesa(string terminalCedula);
  // metodos estudiante mesa
  nodo<Estudiante> *BuscarEstudianteMesa(string cedula);
  bool EliminarEstudianteMesa(string cedula);
  bool InsertarEstudianteMesa(Estudiante estudiante);
  // metodos estudiante cola
  bool InsertarEstudianteCola(string cedula);
  nodo<Estudiante> *BuscarEstudianteCola(string cedula);
  void RemoverEstudianteCola(string cedula);
  Estudiante ProcesarCola();
};

#endif // CENTRO_VOTACION_H
