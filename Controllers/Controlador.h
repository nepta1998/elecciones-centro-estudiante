#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../Models/CentroVotacion.h"
#include "../Views/VCentroVotacion.h"

class Controlador {
private:
  CentroVotacion centroE;
  Estudiante estudiante; // pila
  Voto voto;

public:
  Controlador();

  // Menu Methods
  void Menu();
  void OpcionBahia();
  void OpcionVehiculo();
  void OpcionAyuda();
  void OpcionSalir();

  // Bahia Methods
  void CargarDosBahias();
  void CargarBahias();
  void IncluirBahia();
  void ConsultarBahia();
  void ModificarBahia();
  void EliminarBahia();

  // Vehicle Methods
  void AddCarToQueue();
  void ConsultarVehiculo();
  void ProcessVehicleInQueue();
  void EliminarVehiculo();
};

#endif // DATA_STRUCTURES_PROJECT_UCLA_DCYT_CONTROLADOR_H
