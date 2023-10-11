#include "Controlador.h"
Controlador::Controlador() { this->Inicializar(); }
void Controlador::Inicializar() {
  Mesa m1 = Mesa('1');
  Mesa m2 = Mesa('2');
  Mesa m3 = Mesa('3');

  Estudiante e1 = Estudiante("111", "pedro", "informatica", "semestre 1");
  Estudiante e2 = Estudiante("222", "manuel", "sistemas", "semestre 1");
  Estudiante e3 = Estudiante("333", "jose", "informatica", "semestre 4");

  this->centroV.getListaMesas()->InsComienzo(m1);
  this->centroV.getListaMesas()->InsComienzo(m2);
  this->centroV.getListaMesas()->InsComienzo(m3);

  ApuntM apM = this->centroV.BuscarMesa('1', this->centroV.getListaMesas());
  Mesa *m1p = this->centroV.getListaMesas()->ObtInfo(apM);
  m1p->InsertarEstudiante(e1);
  apM = this->centroV.BuscarMesa('2', this->centroV.getListaMesas());
  Mesa *m2p = this->centroV.getListaMesas()->ObtInfo(apM);
  m2p->InsertarEstudiante(e2);
  apM = this->centroV.BuscarMesa('3', this->centroV.getListaMesas());
  Mesa *m3p = this->centroV.getListaMesas()->ObtInfo(apM);
  m3p->InsertarEstudiante(e3);
}
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
    vg.ImprimirMensaje("   1. Consultar Mesas.\n");
    vg.ImprimirMensaje("   2. Agregar Mesa.\n");
    vg.ImprimirMensaje("   3. Eliminar  Mesa.\n");
    vg.ImprimirMensaje("   4. Volver al menú anterior.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-4): ", 1, 4);
    switch (opc) {
    case 1:
      this->ConsultarMesas();
      break;
    case 2:
      this->InsertarMesa();
      break;
    case 3:
      this->EliminarMesa();
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
    vg.ImprimirMensaje("   1. Consultar estudiantes registrados a la mesa.\n");
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
    vg.ImprimirMensaje("   1. Consultar cola de estudiantes.\n");
    vg.ImprimirMensaje("   2. Agregar estudiante a la cola.\n");
    vg.ImprimirMensaje("   3. Eliminar  estudiante de la cola.\n");
    vg.ImprimirMensaje("   4. Procesar  estudiante (votar).\n");
    vg.ImprimirMensaje("   5. Volver al menú anterior.\n");
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
    vg.ImprimirEncabezado("\n         M E N U  E S T U D I A N T E  C O L A\n",
                          "   ==========  ===============");
    vg.ImprimirMensaje(
        "   1. Estudiantes que votaron y no votaron en una mesa.\n");
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
    }
  } while (opc != 4);
}
void Controlador::OpcionSalir() {
  VGeneral vg;
  vg.Limpiar();
  int opc = vg.LeerValidarNro("¿Está seguro que desea salir? 1.Si 2.No ", 1, 2);
  if (opc == 1) {
    vg.Pausa();
  } else
    Menu();
}

// Consultar mesa por terminal de cedula
void Controlador::ConsultarMesas() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();

  Lista<Mesa> *lm = this->centroV.getListaMesas();
  ApuntM apM = lm->ObtPrimero();
  vc.ImprimirEncabezado("\n   M E S A S\n", "  =======  ===============");
  if (apM == NULL)
    vc.ImprimirMensaje("\n No Disponible.\n");
  while (apM != NULL) {

    Mesa *m = lm->ObtInfo(apM);
    vc.ImprimirChar(" Mesa ", m->getTerminalCedula());
    vc.ImprimirMensaje("\n");
    apM = lm->ObtProx(apM);
  }
  vc.Pausa();
}

// Consultar estudiante mesa
void Controlador::ConsultarEstudianteMesa() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
  int terminalCedula = vc.LeerValidarNro(
      " Ingrese el terminal de cedula de la mesa (0-9): ", 0, 9);

  char terminalCedulaS = to_string(terminalCedula).back();
  ApuntM apM =
      this->centroV.BuscarMesa(terminalCedulaS, this->centroV.getListaMesas());
  if (apM == NULL) {
    vc.ImprimirMensaje("\n No hay Mesa con ese terminal cedula.\n");
    vc.Pausa();
    return;
  }
  vc.ImprimirEncabezado("\n  E S T U D I A N T E S \n",
                        "  =======  ===============");

  Mesa *m = this->centroV.getListaMesas()->ObtInfo(apM);
  ApuntE apE = m->getEstudiantes()->ObtPrimero();
  if (apE == NULL) {
    vc.ImprimirMensaje("\n No hay estudiantes registrados a la mesa.\n");
    vc.ImprimirLineasBlanco(2);
  }
  while (apE != NULL) {
    Estudiante *est = m->getEstudiantes()->ObtInfo(apE);
    vc.ImprimirLineasBlanco(2);
    vc.ImprimirString(" Cedula: ", est->getCedula());
    vc.ImprimirMensaje("\n");
    vc.ImprimirString(" Nombre: ", est->getNombre());
    vc.ImprimirMensaje("\n");
    vc.ImprimirString(" Carrera: ", est->getCarrera());
    vc.ImprimirMensaje("\n");
    vc.ImprimirString(" Semestre: ", est->getSemestre());
    vc.ImprimirMensaje("\n");
    apE = m->getEstudiantes()->ObtProx(apE);
  }
  vc.Pausa();
}

// Consultar estudiante cola
void Controlador::ConsultarEstudianteCola() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
  Cola<Estudiante> *CEst = this->centroV.getColaEstudiantes();
  Cola<Estudiante> aux;
  vc.ImprimirEncabezado("\n  E S T U D I A N T E S \n",
                        "  =======  ===============");

  if (CEst->Vacia()) {
    vc.ImprimirLineasBlanco(2);
    vc.ImprimirMensaje("\n No hay estudiantes en la cola ");
    vc.ImprimirLineasBlanco(2);
  }
  while (!CEst->Vacia()) {
    Estudiante es;
    CEst->Remover(es);
    aux.Insertar(es);
    vc.ImprimirLineasBlanco(2);
    vc.ImprimirString("Cedula: ", es.getCedula());
    vc.ImprimirMensaje("\n");
    vc.ImprimirString("Nombre: ", es.getNombre());
    vc.ImprimirMensaje("\n");
    vc.ImprimirString("Carrera: ", es.getCarrera());
    vc.ImprimirMensaje("\n");
    vc.ImprimirString("Semestre: ", es.getSemestre());
    vc.ImprimirMensaje("\n");
  }
  while (!aux.Vacia()) {
    Estudiante es;
    aux.Remover(es);
    CEst->Insertar(es);
  }
  vc.ImprimirLineasBlanco(2);
  vc.Pausa();
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
  vc.ImprimirMensaje("\n La mesa con el terminal de cedula " +
                     to_string(terminalCedula) + " ya esta creada.\n");
  vc.Pausa();
}

// Insertar estudiante a la mesa
void Controlador::InsertarEstudianteMesa() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
  Estudiante est;
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  string ced = cedula;
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
    est.setCedula(ced);
    est.setNombre(nombre);
    est.setCarrera(carrera);
    est.setSemestre(semestre);

    Mesa *m = this->centroV.getListaMesas()->ObtInfo(apM);
    if (m->InsertarEstudiante(est)) {
      // this->centroV.getListaMesas()->AsigInfo(apM, m);
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
  vc.Limpiar();
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  if (this->centroV.InsertarEstudianteCola(cedula))
    vc.ImprimirMensaje(
        "\n El estudiante fue agregado correctamente a la cola.\n");
  else
    vc.ImprimirMensaje(
        "\n El estudiante no esta registrado a ninguna mesa o ya "
        "fue agregado anteriormente a la cola.\n");
  vc.Pausa();
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
  vc.Limpiar();
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
  vc.Limpiar();
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  if (this->centroV.RemoverEstudianteCola(cedula))
    vc.ImprimirMensaje("\n El estudiante fue eliminado correctamente.\n");
  else
    vc.ImprimirMensaje("\n El estudiante no se encuentra en la cola \n");
  vc.Pausa();
}

// procesar estudiante cola

void Controlador::ProcesarEstudianteCola() {
  VCentroVotacion vc = this->vctrV;
  Estudiante est = this->centroV.ProcesarCola();
  if (est.getCedula().empty()) {
    vc.Limpiar();
    vc.ImprimirMensaje("No hay estudiantes en la cola\n");
    vc.ImprimirLineasBlanco(1);
    vc.Pausa();
    return;
  }
  char terminalCedula = est.getCedula().back();
  ApuntM apM =
      this->centroV.BuscarMesa(terminalCedula, this->centroV.getListaMesas());
  ApuntE epE = this->centroV.BuscarEstudianteMesa(est.getCedula(), apM);
  Mesa *m = this->centroV.getListaMesas()->ObtInfo(apM);
  Estudiante *es = m->getEstudiantes()->ObtInfo(epE);

  int opc;
  int cargo;

  do {
    vc.Limpiar();

    vc.ImprimirEncabezado("\n      E S T U D I A N T E\n",
                          "      =======  ===============");
    vc.ImprimirString("Cedula del estudiante: ", est.getCedula());
    vc.ImprimirLineasBlanco(1);
    vc.ImprimirString("nombre del estudiante: ", est.getNombre());
    vc.ImprimirLineasBlanco(2);
    vc.ImprimirEncabezado("\n      V O T A C I O N\n",
                          "      =======  ===============");
    vc.ImprimirMensaje("   1. Presidente.\n");
    vc.ImprimirMensaje("   2. Secretario.\n");
    vc.ImprimirMensaje("   3. Vice presidente.\n");
    vc.ImprimirMensaje("   4. Vocal A.\n");
    cargo = vc.LeerValidarNro("   Seleccione su opción (1-4): ", 1, 4);
    Voto v;
    bool insert;
    switch (cargo) {
    case 1:
      v.setCargo("presidente");
      insert = es->InsertarVoto(v);
      break;
    case 2:
      v.setCargo("secretario");
      insert = es->InsertarVoto(v);
      break;
    case 3:
      v.setCargo("vice presidente");
      insert = es->InsertarVoto(v);
      break;
    case 4:
      v.setCargo("vocal A");
      insert = es->InsertarVoto(v);
      break;
    }
    if (!insert) {
      vc.ImprimirMensaje("Anteriormente se realizo el voto por ese cargo\n");
      vc.Pausa();
      vc.Limpiar();
    }
    opc = vc.LeerChar("Desea agregar otro voto (s/n): ");
    // clean buffer input
    string temp;
    getline(cin, temp);

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

  vc.ImprimirEncabezado("\n                   M E S A " +
                            to_string(terminalCedula) + "\n",
                        "        #################################");
  int count = 0;
  if (apM != NULL) {
    Mesa *m = this->centroV.getListaMesas()->ObtInfo(apM);
    Lista<Estudiante> *le = m->getEstudiantes();
    ApuntE apE = le->ObtPrimero();
    vc.ImprimirEncabezado(
        "\n   E S T U D I A N T E S  Q U E  V O T A R O N\n",
        "   ========================= ============================");
    while (apE != NULL) {
      Estudiante *est = le->ObtInfo(apE);
      if (!est->getPilaVotos()->Vacia()) {
        count++;

        vc.ImprimirString("Cedula: ", est->getCedula());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Nombre: ", est->getNombre());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Carrera: ", est->getCarrera());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Semestre: ", est->getSemestre());
        vc.ImprimirLineasBlanco(2);
      }
      apE = le->ObtProx(apE);
    }
    string str = string(m->getTerminalCedula(), 1);
    vc.ImprimirMensaje("Cantidad de estudiantes que votaron" + str + ": " +
                       to_string(count));
    vc.ImprimirLineasBlanco(2);
    vc.ImprimirEncabezado(
        "\n   E S T U D I A N T E S  Q U E  N O  V O T A R O N\n",
        "   ========================= ============================");
    apE = le->ObtPrimero();
    count = 0;
    while (apE != NULL) {
      Estudiante *est = le->ObtInfo(apE);
      if (est->getPilaVotos()->Vacia()) {
        count++;

        vc.ImprimirString("Cedula: ", est->getCedula());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Nombre: ", est->getNombre());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Carrera: ", est->getCarrera());
        vc.ImprimirMensaje(". \n");
        vc.ImprimirString("Semestre: ", est->getSemestre());
        vc.ImprimirLineasBlanco(2);
      }
      apE = le->ObtProx(apE);
    }
    str = string(m->getTerminalCedula(), 1);
    vc.ImprimirMensaje("Cantidad de estudiantes que no votaron " +
                       to_string(count));
  } else
    vc.ImprimirMensaje("\n La mesa no existe.\n");
  vc.ImprimirLineasBlanco(2);
  vc.Pausa();
};
void Controlador::VotosEstudiante() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
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
    Mesa *mes = this->centroV.getListaMesas()->ObtInfo(apM);
    Estudiante *est = mes->getEstudiantes()->ObtInfo(apE);
    Pila<Voto> *pilaVotos = est->getPilaVotos();
    Pila<Voto> aux;
    vc.ImprimirEncabezado("\n          V O T O S\n",
                          "   =========  ===============");
    if (pilaVotos->Vacia()) {
      vc.ImprimirMensaje("El estudiante no tiene votos");
    } else
      while (!pilaVotos->Vacia()) {
        pilaVotos->Remover(voto);
        aux.Insertar(voto);
        vc.ImprimirMensaje("   " + voto.getCargo() + '\n');
      }
    while (!aux.Vacia()) {
      aux.Remover(voto);
      pilaVotos->Insertar(voto);
    }
  } else
    vc.ImprimirMensaje("\n El estudiante no esta asignado a la mesa.\n");
  vc.ImprimirLineasBlanco(2);
  vc.Pausa();
};
void Controlador::CantidadVotosCargo() {
  VCentroVotacion vc = this->vctrV;
  vc.Limpiar();
  int count1 = 0;
  int count2 = 0;
  int count3 = 0;
  int count4 = 0;

  ApuntM apM = this->centroV.getListaMesas()->ObtPrimero();
  while (apM != NULL) {
    Mesa *m = this->centroV.getListaMesas()->ObtInfo(apM);
    Lista<Estudiante> *le = m->getEstudiantes();
    ApuntE apE = le->ObtPrimero();
    while (apE != NULL) {
      Estudiante *est = le->ObtInfo(apE);
      Voto vo;
      Pila<Voto> aux;
      Pila<Voto> *votos = est->getPilaVotos();
      while (!votos->Vacia()) {
        votos->Remover(vo);
        aux.Insertar(vo);
        if (vo.getCargo() == "presidente") {
          count1++;
          continue;
        }
        if (vo.getCargo() == "secretario") {
          count2++;
          continue;
        }
        if (vo.getCargo() == "vice presidente") {
          count3++;
          continue;
        }
        if (vo.getCargo() == "vocal A") {
          count4++;
          continue;
        }
      }
      while (!aux.Vacia()) {
        aux.Remover(vo);
        votos->Insertar(vo);
      }
      apE = le->ObtProx(apE);
    }
    apM = this->centroV.getListaMesas()->ObtProx(apM);
  }
  vc.ImprimirEncabezado("\n    V O T O S   P O R  C A R G O\n",
                        "    =======  ===============");
  vc.ImprimirMensaje("Cantidad de votos para el cargo presidente: " +
                     to_string(count1));
  vc.ImprimirMensaje("\n");
  vc.ImprimirMensaje("Cantidad de votos para el cargo secretario: " +
                     to_string(count2));
  vc.ImprimirMensaje("\n");
  vc.ImprimirMensaje("Cantidad de votos para el cargo vice presidente: " +
                     to_string(count3));
  vc.ImprimirMensaje("\n");
  vc.ImprimirMensaje("Cantidad de votos para el cargo vocal A: " +
                     to_string(count4));
  vc.ImprimirMensaje("\n");
  vc.Pausa();
};
