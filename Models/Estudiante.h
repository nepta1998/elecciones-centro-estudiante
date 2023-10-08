#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "../Libs/Pila/Pila.cpp"
#include "Voto.h"
#include <string>
using namespace std;

class Estudiante {

private:
  string cedula;
  string nombre;
  string carrera;
  string semestre;
  Pila<Voto> pilaVotos;

public:
  Estudiante();
  Estudiante(string cedula, string nombre, string carrera, string semestre);
  string getCedula();
  void setCedula(string cedula);
  string getNombre();
  void setNombre(string nombre);
  string getCarrera();
  void setCarrera(string carrera);
  string getSemestre();
  void setSemestre(string semestre);
  // pila methods
  void InsertarVoto(Voto voto);
  void RemoverVoto(Voto &voto);

  Pila<Voto> getPilaVotos() const;
};

#endif // ESTUDIANTE_H
