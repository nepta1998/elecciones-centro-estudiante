#include "Controlador.h"
Controlador::Controlador() {}
void Controlador::Menu() {
  int opc;
  VGeneral vg;
  // vg.Pausa();
  do {
    vg.Limpiar();
    vg.ImprimirLineasBlanco(2);
    vg.Limpiar();
    vg.ImprimirEncabezado("\n      Proyecto Programación No Numérica 1\n",
                          "      =======  ===============");
    vg.ImprimirEncabezado("\n      Elecciones Centro de Estudiante  \n",
                          "      =======  ===============");
    vg.ImprimirEncabezado("\n      M E N U  DE O P C I O N E S\n",
                          "      =======  ===============");
    vg.ImprimirMensaje("   1. Mesas.\n");
    vg.ImprimirMensaje("   2. Estudiante Mesas.\n");
    vg.ImprimirMensaje("   3. Estudiante Cola.\n");
    vg.ImprimirMensaje("   4. Reportes.\n");
    vg.ImprimirMensaje("   5. Salir.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
    switch (opc) {
    case 1:
      this->OpcionMesa();
      break;
    case 2:
      this->OpcionEstudianteMesa();
      break;
    case 3:
      OpcionEstudianteCola();
      break;
    case 4:
      OpcionReportes();
      break;
    case 5:
      cout << "opcion 5";
      OpcionSalir();
    }
  } while (opc != 5);
}

void Controlador::OpcionMesa() {
  int opc;
  VGeneral vg;
  // vg.Pausa();
  do {
    vg.Limpiar();
    vg.ImprimirLineasBlanco(2);
    vg.Limpiar();
    vg.ImprimirEncabezado("\n      M E N U  M E S A\n",
                          "      =======  ===============");
    vg.ImprimirMensaje("   1. Consultar mesa.\n");
    vg.ImprimirMensaje("   2. Agregar Mesa.\n");
    vg.ImprimirMensaje("   3. Eliminar  Mesa.\n");
    vg.ImprimirMensaje("   4. Volver al menú anterior.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-4): ", 1, 4);
    switch (opc) {
    case 1:
      this->ConsultarMesa();
      break;
    case 2:
      this->InsertarMesa();
      break;
    case 3:
      this->EliminarMesa();
      break;
    case 4:
      Menu();
      break;
    }
  } while (opc != 4);
}
void Controlador::OpcionEstudianteMesa() {
  int opc;
  VGeneral vg;
  // vg.Pausa();
  do {
    vg.Limpiar();
    vg.ImprimirLineasBlanco(2);
    vg.Limpiar();
    vg.ImprimirEncabezado("\n      M E N U  E S T U D I A N T E  M E S A\n",
                          "      =======  ===============");
    vg.ImprimirMensaje("   1. Consultar estudiante en la mesa.\n");
    vg.ImprimirMensaje("   2. Agregar estudiante a la mesa.\n");
    vg.ImprimirMensaje("   3. Eliminar  estudiante de la mesa.\n");
    vg.ImprimirMensaje("   4. Volver al menú anterior.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-4): ", 1, 4);
    switch (opc) {
    case 1:
      this->ConsultarEstudianteMesa();
      break;
    case 2:
      this->InsertarEstudianteMesa();
      break;
    case 3:
      this->EliminarEstudianteMesa();
      break;
    case 4:
      Menu();
      break;
    }
  } while (opc != 4);
}
void Controlador::OpcionEstudianteCola() {
  int opc;
  VGeneral vg;
  // vg.Pausa();
  do {
    vg.Limpiar();
    vg.ImprimirLineasBlanco(2);
    vg.Limpiar();
    vg.ImprimirEncabezado("\n      M E N U  E S T U D I A N T E  C O L A\n",
                          "      =======  ===============");
    vg.ImprimirMensaje("   1. Consultar estudiante en la cola.\n");
    vg.ImprimirMensaje("   2. Agregar estudiante a la cola.\n");
    vg.ImprimirMensaje("   3. Eliminar  estudiante de la cola.\n");
    vg.ImprimirMensaje("   4. Procesar  estudiante de la cola.\n");
    vg.ImprimirMensaje("   5. Procesar Estudiante.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
    switch (opc) {
    case 1:
      this->ConsultarEstudianteCola();
      break;
    case 2:
      this->InsertarEstudianteCola();
      break;
    case 3:
      this->EliminarEstudianteCola();
      break;
    case 4:
      this->ProcesarEstudianteCola();
      break;
    case 5:
      Menu();
      break;
    }
  } while (opc != 5);
}
// Opcion reportes
void Controlador::OpcionReportes() {
  int opc;
  VGeneral vg;
  // vg.Pausa();
  do {
    vg.Limpiar();
    vg.ImprimirLineasBlanco(2);
    vg.Limpiar();
    vg.ImprimirEncabezado("\n      M E N U  E S T U D I A N T E  C O L A\n",
                          "      =======  ===============");
    vg.ImprimirMensaje("   1. Estudiantes que votaron en una mesa.\n");
    vg.ImprimirMensaje("   2. Votos de un Estudiante.\n");
    vg.ImprimirMensaje("   3. Cantidad de votos por cargo.\n");
    vg.ImprimirMensaje("   4. Volver al menú anterior.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-4): ", 1, 4);
    switch (opc) {
    case 1:
      this->EstudiantesMesa();
      break;
    case 2:
      this->VotosEstudiante();
      break;
    case 3:
      this->CantidadVotosCargo();
      break;
    case 4:
      Menu();
      break;
    }
  } while (opc != 4);
}
void Controlador::OpcionSalir() {
  VGeneral vg;
  int opc =
      vg.LeerValidarNro("   ¿Está seguro que desea salir? 1.Si 2.No ", 1, 2);
  if (opc == 1)
    vg.Pausa();
  else
    Menu();
}

// Consultar mesa por terminal de cedula
void Controlador::ConsultarMesa() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
  int terminalCedula = vc.LeerValidarNro(
      " Ingrese el terminal de cedula de la mesa (0-9): ", 0, 9);

  ApuntM apM = this->centroV.BuscarMesa(to_string(terminalCedula).back(),
                                        this->centroV.getListaMesas());
  if (apM != NULL) {
    Mesa m = this->centroV.getListaMesas()->ObtInfo(apM);
    vc.ImprimirMensaje("\n MESA \n");
    vc.ImprimirChar("Terminal de cedula de la mesa es: ",
                    m.getTerminalCedula());
    vc.ImprimirMensaje(". \n");
    vc.Pausa();
    return;
  }
  vc.ImprimirMensaje("\n No hay Mesa con ese terminal cedula.\n");
  vc.Pausa();
}

// Consultar estudiante mesa
void Controlador::ConsultarEstudianteMesa() {
  VCentroVotacion vc = this->vctrV;
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  ApuntM apM =
      this->centroV.BuscarMesa(cedula.back(), this->centroV.getListaMesas());
  if (apM == NULL) {
    vc.ImprimirMensaje("\n No hay Mesa con ese terminal cedula.\n");
    vc.Pausa();
    return;
  }
  ApuntE apE = this->centroV.BuscarEstudianteMesa(cedula, apM);
  if (apE != NULL) {
    mesa = this->centroV.getListaMesas()->ObtInfo(apM);
    estudiante = mesa.getEstudiantes().ObtInfo(apE);
    Pila<Voto> pilaVotos = estudiante.getPilaVotos();
    vc.ImprimirMensaje("\n Estudiante");
    vc.ImprimirString("Cedula: ", estudiante.getCedula());
    vc.ImprimirMensaje(". \n");
    vc.ImprimirString("Nombre: ", estudiante.getNombre());
    vc.ImprimirMensaje(". \n");
    vc.ImprimirString("Carrera: ", estudiante.getCarrera());
    vc.ImprimirMensaje(". \n");
    vc.ImprimirString("Semestre: ", estudiante.getSemestre());
    vc.ImprimirMensaje("\n Votos");
    while (!pilaVotos.Vacia()) {
      pilaVotos.Remover(voto);
      vc.ImprimirMensaje(voto.getCargo() + '\n');
    }
    return;
  }
  vc.ImprimirMensaje("\n El estudiante no esta asignado a la mesa.\n");
  vc.Pausa();
}

// Consultar estudiante cola
void Controlador::ConsultarEstudianteCola() {
  VCentroVotacion vc = this->vctrV;
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  Cola<Estudiante> CEst = this->centroV.getColaEstudiantes();
  while (!CEst.Vacia()) {
    CEst.Remover(estudiante);
    if (estudiante.getCedula() == cedula) {
      vc.ImprimirMensaje("\n Estudiante");
      vc.ImprimirString("Cedula: ", estudiante.getCedula());
      vc.ImprimirMensaje(". \n");
      vc.ImprimirString("Nombre: ", estudiante.getNombre());
      vc.ImprimirMensaje(". \n");
      vc.ImprimirString("Carrera: ", estudiante.getCarrera());
      vc.ImprimirMensaje(". \n");
      vc.ImprimirString("Semestre: ", estudiante.getSemestre());
      return;
    }
  }
}

// Insertar mesa
void Controlador::InsertarMesa() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
  int terminalCedula = vc.LeerValidarNro(
      " Ingrese el terminal de cedula de la mesa (0-9): ", 0, 9);

  char terminalCedulaS = to_string(terminalCedula).back();
  ApuntM apM =
      this->centroV.BuscarMesa(terminalCedulaS, this->centroV.getListaMesas());
  if (apM == NULL) {
    mesa.setTerminalCedula(terminalCedulaS);
    if (this->centroV.InsertarMesa(mesa)) {
      vc.ImprimirMensaje("\n La mesa fue agregada correctamente ");
    } else
      vc.ImprimirMensaje("\n Ocurrio un error al momento de agregar la mesa ");
    vc.Pausa();
    return;
  }
  vc.ImprimirMensaje("\n La mesa el terminal de cedula " +
                     to_string(terminalCedulaS) + " ya esta creada.\n");
  vc.Pausa();
}

// Insertar estudiante a la mesa
void Controlador::InsertarEstudianteMesa() {
  VCentroVotacion vc = this->vctrV;
  Estudiante est;
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  char terminalCedula = cedula.back();
  ApuntM apM =
      this->centroV.BuscarMesa(terminalCedula, this->centroV.getListaMesas());
  if (apM == NULL) {
    vc.ImprimirMensaje("\n No hay Mesa con ese terminal cedula no es posible "
                       "agregar al estudiante.\n");
    vc.Pausa();
    return;
  }
  if (this->centroV.BuscarEstudianteMesa(cedula, apM) == NULL) {

    string nombre = vc.LeerString(" Ingrese el nombre del estudiante: ");
    string carrera = vc.LeerString(" Ingrese la carrera del estudiante: ");
    string semestre = vc.LeerString(" Ingrese el semestre del estudiante: ");
    est.setCedula(cedula);
    est.setNombre(nombre);
    est.setCarrera(carrera);
    est.setSemestre(semestre);
    if (this->centroV.InsertarEstudianteMesa(est, apM)) {
      vc.ImprimirMensaje("\n El estudiante fue agregado correctamente ");
    } else
      vc.ImprimirMensaje(
          "\n Ocurrio un error al momento de agregar el estudiante ");
    vc.Pausa();
    return;
  }
  vc.ImprimirMensaje("\n El estudiante ya fue agregado anteriormente.\n");
  vc.Pausa();
}

// Insertar estudiante a la cola
void Controlador::InsertarEstudianteCola() {
  VCentroVotacion vc = this->vctrV;
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  if (this->centroV.InsertarEstudianteCola(cedula))
    vc.ImprimirMensaje(
        "\n El estudiante fue agregado correctamente a la cola.\n");
  else
    vc.ImprimirMensaje("\n El estudiante no esta registro a ninguna mesa o ya "
                       "fue agregado anteriormente a la cola.\n");
}

// eliminar mesa

void Controlador::EliminarMesa() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
  int terminalCedula = vc.LeerValidarNro(
      " Ingrese el terminal de cedula de la mesa (0-9): ", 0, 9);
  char terminalCedulaS = to_string(terminalCedula).back();
  ApuntM apM = this->centroV.BuscarMesa(to_string(terminalCedula).back(),
                                        this->centroV.getListaMesas());
  if (apM != NULL) {
    if (this->centroV.RemoverMesa(terminalCedulaS)) {
      vc.ImprimirMensaje("La mesa se elimino correctamente ");
    } else
      vc.ImprimirMensaje("La mesa no se pudo eliminar");
    vc.Pausa();
    return;
  }
  vc.ImprimirMensaje("\n No hay Mesa con ese terminal cedula.\n");
  vc.Pausa();
}

// eliminar estudiante mesa

void Controlador::EliminarEstudianteMesa() {
  VCentroVotacion vc = this->vctrV;
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  char terminalCedula = cedula.back();
  ApuntM apM =
      this->centroV.BuscarMesa(terminalCedula, this->centroV.getListaMesas());
  if (apM == NULL) {
    vc.ImprimirMensaje("\n No hay Mesa con ese terminal cedula no es posible "
                       "eliminar al estudiante.\n");
    vc.Pausa();
    return;
  }
  ApuntE apE = this->centroV.BuscarEstudianteMesa(cedula, apM);
  if (apE != NULL) {
    if (this->centroV.EliminarEstudianteMesa(cedula)) {
      vc.ImprimirMensaje("\n El estudiante fue eliminado correctamente ");
    } else
      vc.ImprimirMensaje(
          "\n Ocurrio un error al momento de eliminar el estudiante ");
    vc.Pausa();
    return;
  }
  vc.ImprimirMensaje("\n El estudiante no esta registrado en la mesa.\n");
}

// eliminar estudiante cola

void Controlador::EliminarEstudianteCola() {

  VCentroVotacion vc = this->vctrV;
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  if (this->centroV.RemoverEstudianteCola(cedula))
    vc.ImprimirMensaje("\n El estudiante fue eliminado correctamente.\n");
  else
    vc.ImprimirMensaje("\n El estudiante no se encuentra en la cola \n");
}

// procesar estudiante cola

void Controlador::ProcesarEstudianteCola() {
  VCentroVotacion vc = this->vctrV;
  Estudiante est = this->centroV.ProcesarCola();
  char terminalCedula = est.getCedula().back();
  ApuntM apM =
      this->centroV.BuscarMesa(terminalCedula, this->centroV.getListaMesas());
  ApuntE epE = this->centroV.BuscarEstudianteMesa(est.getCedula(), apM);
  Mesa m = this->centroV.getListaMesas()->ObtInfo(apM);
  est = m.getEstudiantes().ObtInfo(epE);

  int opc;
  int cargo;

  do {
    vc.ImprimirEncabezado("\n      V O T A C I O N\n",
                          "      =======  ===============");
    vc.ImprimirMensaje("   1. Presidente.\n");
    vc.ImprimirMensaje("   2. Secretario.\n");
    vc.ImprimirMensaje("   3. Vice presidente.\n");
    vc.ImprimirMensaje("   4. Vocal A.\n");
    cargo = vc.LeerValidarNro("   Seleccione su opción (1-4): ", 1, 4);
    Voto voto;
    bool insert;
    switch (cargo) {
    case 1:
      voto.setCargo("presidente");
      insert = est.InsertarVoto(voto);
      break;
    case 2:
      voto.setCargo("secretario");
      insert = est.InsertarVoto(voto);
      break;
    case 3:
      voto.setCargo("vice presidente");
      insert = est.InsertarVoto(voto);
      break;
    case 4:
      voto.setCargo("vocal A");
      insert = est.InsertarVoto(voto);
      break;
    }
    if (!insert) {
      vc.ImprimirMensaje("Anteriormente se realizo el voto por ese cargo\n");
      vc.Pausa();
    }
    opc = vc.LeerChar("Desea agregar otro voto: ");
  } while (opc == 's');
}

// reportes

void Controlador::EstudiantesMesa() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
  int terminalCedula = vc.LeerValidarNro(
      " Ingrese el terminal de cedula de la mesa (0-9): ", 0, 9);
  char terminalCedulaS = to_string(terminalCedula).back();
  ApuntM apM = this->centroV.BuscarMesa(to_string(terminalCedula).back(),
                                        this->centroV.getListaMesas());
  int count = 0;
  if (apM != NULL) {
    Mesa m = this->centroV.getListaMesas()->ObtInfo(apM);
    Lista<Estudiante> le = m.getEstudiantes();
    ApuntE apE = le.ObtPrimero();
    while (apE != NULL) {
      Estudiante est = le.ObtInfo(apE);
      if (!est.getPilaVotos().Vacia()) {
        count++;
        vc.ImprimirString("Cedula: ", est.getCedula());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Nombre: ", est.getNombre());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Carrera: ", est.getCarrera());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Semestre: ", est.getSemestre());
        vc.ImprimirLineasBlanco(2);
      }
      apE = le.ObtProx(apE);
    }
    vc.ImprimirMensaje("Cantidad de estudiantes que votaron en la mesa" +
                       to_string(m.getTerminalCedula()) + ": " +
                       to_string(count));
    vc.Pausa();
  }
  vc.ImprimirMensaje("\n La mesa no existe.\n");
  vc.Pausa();
};
void Controlador::VotosEstudiante() { ConsultarEstudianteMesa(); };
void Controlador::CantidadVotosCargo() {
  VCentroVotacion vc = this->vctrV;
  Voto v;
  int cargo;
  int count = 0;
  vc.ImprimirMensaje("   1. Presidente.\n");
  vc.ImprimirMensaje("   2. Secretario.\n");
  vc.ImprimirMensaje("   3. Vice presidente.\n");
  vc.ImprimirMensaje("   4. Vocal A.\n");
  cargo = vc.LeerValidarNro("   Seleccione el cargo (1-4): ", 1, 4);
  switch (cargo) {
  case 1:
    v.setCargo("presidente");
    break;
  case 2:
    v.setCargo("secretario");
    break;
  case 3:
    v.setCargo("vice presidente");
    break;
  case 4:
    v.setCargo("vocal A");
    break;
  }

  ApuntM apM = this->centroV.getListaMesas()->ObtPrimero();
  while (apM != NULL) {
    Mesa m = this->centroV.getListaMesas()->ObtInfo(apM);
    Lista<Estudiante> le = m.getEstudiantes();
    ApuntE apE = le.ObtPrimero();
    while (apE != NULL) {
      Estudiante est = le.ObtInfo(apE);

      if (est.BuscarVoto(v)) {
        count++;
      }
    }
    apM = this->centroV.getListaMesas()->ObtProx(apM);
  }
  vc.ImprimirMensaje("Cantidad de votos para el cargo " + v.getCargo() + ": " +
                     to_string(count));
};
