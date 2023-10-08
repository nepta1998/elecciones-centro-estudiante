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
void Estudiante::InsertarVoto(Voto voto) { this->pilaVotos.Insertar(voto); };
void Estudiante::RemoverVoto(Voto &voto) { this->pilaVotos.Remover(voto); };
