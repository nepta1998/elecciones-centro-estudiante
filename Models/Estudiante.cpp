#include "Estudiante.h"

Estudiante::Estudiante(){};
Estudiante::Estudiante(string cedula, string nombre, string carrera,
                       string semestre) {
  this->cedula = cedula;
  this->nombre = nombre;
  this->carrera = carrera;
  this->semestre = semestre;
};
void Estudiante::setCedula(string cedula) { this->cedula = cedula; };
string Estudiante::getCedula() { return this->cedula; };
void Estudiante::setNombre(string nombre) { this->nombre = nombre; };
string Estudiante::getNombre() { return this->nombre; };
void Estudiante::setCarrera(string carrera) { this->carrera = carrera; };
string Estudiante::getCarrera() { return this->carrera; };
void Estudiante::setSemestre(string semestre) { this->semestre = semestre; };
string Estudiante::getSemestre() { return this->semestre; };
// metodos de pila
bool Estudiante::BuscarVoto(Voto voto) {
  Pila<Voto> pilaAux;
  Voto va;
  while (!this->pilaVotos.Vacia()) {
    this->pilaVotos.Remover(va);
    pilaAux.Insertar(va);
    if (va.getCargo() == voto.getCargo()) {
      while (!pilaAux.Vacia()) {
        pilaAux.Remover(va);
        this->pilaVotos.Insertar(va);
      }
      return true;
    }
  }
  return false;
};
bool Estudiante::InsertarVoto(Voto voto) {
  if (!this->BuscarVoto(voto)) {
    this->pilaVotos.Insertar(voto);
    return true;
  }
  return false;
};

Pila<Voto> Estudiante::getPilaVotos() const { return this->pilaVotos; };
