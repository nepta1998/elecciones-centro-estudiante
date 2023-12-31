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
  
  // inicializar datos
  void Inicializar();
  // Menu Methods
  void Menu();
  void OpcionMesa();
  void OpcionEstudianteMesa();
  void OpcionEstudianteCola();
  void OpcionReportes();
  void OpcionSalir();

  // Mesa metodos
  void InsertarMesa();
  void ConsultarMesas();
  void EliminarMesa();

  // Estudiante Mesa
  void InsertarEstudianteMesa();
  void ConsultarEstudianteMesa();
  void EliminarEstudianteMesa();

  // Estudiante Cola metodos
  void InsertarEstudianteCola();
  void ConsultarEstudianteCola();
  void ProcesarEstudianteCola();
  void EliminarEstudianteCola();

  // reportes
  void EstudiantesMesa();
  void VotosEstudiante();
  void CantidadVotosCargo();

};

#endif // DATA_STRUCTURES_PROJECT_UCLA_DCYT_CONTROLADOR_H
