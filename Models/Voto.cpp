#include "Voto.h"

Voto::Voto() {}
Voto::Voto(string cargo) { this->cargo = cargo; }

string Voto::getCargo() { return this->cargo; }
void Voto::setCargo(string cargo) { this->cargo = cargo; }
