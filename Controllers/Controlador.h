#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../Models/CentroVotacion.cpp"
#include "../Views/VCentroVotacion.cpp"

class Controlador {
  typedef nodo<Mesa> *ApuntM;
  typedef nodo<Estudiante> *ApuntE;

private:
  CentroVotacion centroV;
  Mesa mesa;
  Estudiante estudiante; // pila
  Voto voto;
  VCentroVotacion vctrV;

public:
  Controlador();

  // Menu Methods
  void Menu();
  void OpcionMesa();
  void OpcionEstudianteMesa();
  void OpcionEstudianteCola();
  void OpcionAyuda();
  void OpcionSalir();

  // Mesa metodos
  void InsertarMesa();
  // void IncluirBahia();
  void ConsultarMesa();
  void ModificarMesa();
  void EliminarMesa();

  // Estudiante Mesa
  void InsertarEstudianteMesa();
  // void IncluirBahia();
  void ConsultarEstudianteMesa();
  void ModificarEstudianteMesa();
  void EliminarEstudianteMesa();

  // Estudiante Cola metodos
  void InsertarEstudianteCola();
  void ConsultarEstudianteCola();
  void ProcessEstudianteCola();
  void EliminarEstudianteCola();
};

#endif // DATA_STRUCTURES_PROJECT_UCLA_DCYT_CONTROLADOR_H
