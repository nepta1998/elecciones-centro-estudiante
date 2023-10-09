#ifndef CENTRO_VOTACION_H
#define CENTRO_VOTACION_H

#include "../Libs/Cola/Cola.cpp"
#include "Mesa.cpp"

class CentroVotacion {

  typedef nodo<Mesa> *ApuntM;
  typedef nodo<Estudiante> *ApuntE;

private:
  Lista<Mesa> listaMesas;
  Cola<Estudiante> colaEstudiantes;

public:
  CentroVotacion();
  bool InsertarEstudiante(Estudiante e);

  // metodos mesa
  bool InsertarMesa(Mesa mesa);
  bool RemoverMesa(char terminalCedula);
  nodo<Mesa> *BuscarMesa(char terminalCedula);
  Lista<Mesa> getListaMesas();
  // metodos estudiante mesa
  nodo<Estudiante> *BuscarEstudianteMesa(string cedula);
  bool EliminarEstudianteMesa(string cedula);
  bool InsertarEstudianteMesa(Estudiante estudiante);
  // metodos estudiante cola
  bool InsertarEstudianteCola(string cedula);
  bool EstaEstudianteEnCola(string cedula);
  bool RemoverEstudianteCola(string cedula);
  Estudiante ProcesarCola();
  Cola<Estudiante> getColaEstudiantes();
};

#endif // CENTRO_VOTACION_H
