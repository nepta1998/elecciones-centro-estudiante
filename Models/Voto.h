#ifndef VOTO_H
#define VOTO_H

#include <string>
using namespace std;

class Voto {

private:
  string cargo;

public:
  Voto();
  Voto(string cargo);
  string getCargo();
  void setCargo(string cargo);
};

#endif // VOTO_H
