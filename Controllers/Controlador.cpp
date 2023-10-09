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
    vg.ImprimirMensaje("   5. Ayuda.\n");
    vg.ImprimirMensaje("   6. Salir.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-6): ", 1, 6);
    switch (opc) {
    case 1:
      this->OpcionMesa();
      break;
    case 2:
      cout << "opcion 2";
      this->OpcionEstudianteMesa();
      break;
    case 3:
      // OpcionReportes();

      cout << "opcion 3";
      break;
    case 4:
      cout << "opcion 4";
      // OpcionAyuda();
      break;
    case 5:
      cout << "opcion 5";
      // OpcionSalir();
    case 6:
      cout << "opcion 5";
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
    vg.ImprimirMensaje("   3. Modificar Mesa.\n");
    vg.ImprimirMensaje("   4. Eliminar  Mesa.\n");
    vg.ImprimirMensaje("   5. Volver al menú anterior.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
    switch (opc) {
    case 1:
      this->ConsultarMesa();
      break;
    case 2:
      this->InsertarMesa();
      break;
    case 3:
      // this->ModificarMesa();
      break;
    case 4:
      // this->EliminarMesa();
      break;
    case 5:
      Menu();
      break;
    }
  } while (opc != 5);
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
    vg.ImprimirMensaje("   3. Modificar estudiante en la mesa.\n");
    vg.ImprimirMensaje("   4. Eliminar  estudiante de la mesa.\n");
    vg.ImprimirMensaje("   5. Volver al menú anterior.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
    switch (opc) {
    case 1:
      this->ConsultarEstudianteMesa();
      break;
    case 2:
      this->InsertarEstudianteMesa();
      break;
    case 3:
      // this->ModificarMesa();
      break;
    case 4:
      // this->EliminarMesa();
      break;
    case 5:
      Menu();
      break;
    }
  } while (opc != 5);
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
    vg.ImprimirMensaje("   4. Volver al menú anterior.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
    switch (opc) {
    case 1:
      this->ConsultarEstudianteCola();
      break;
    case 2:
      this->InsertarEstudianteCola();
      break;
    case 3:
      // this->EliminarEstudianteCola();
      break;
    case 4:
      Menu();
      break;
    }
  } while (opc != 4);
}
void Controlador::OpcionAyuda() {}
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

  ApuntM apM = this->centroV.BuscarMesa(to_string(terminalCedula));
  if (apM != NULL) {
    Mesa m = this->centroV.getListaMesas().ObtInfo(apM);
    vc.ImprimirMensaje("\n MESA");
    vc.ImprimirString("Terminal de cedula de la mesa es: ",
                      m.getTerminalCedula());
    vc.ImprimirMensaje(". \n");
    vc.ImprimirString("Nombre del encargado de la mesa es: ",
                      m.getNombreEncargado());
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
  ApuntM apM = this->centroV.BuscarMesa(string(cedula.back(), 1));
  if (apM == NULL) {
    vc.ImprimirMensaje("\n No hay Mesa con ese terminal cedula.\n");
    vc.Pausa();
    return;
  }
  ApuntE apE = this->centroV.BuscarEstudianteMesa(cedula);
  if (apE != NULL) {
    mesa = this->centroV.getListaMesas().ObtInfo(apM);
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

  string terminalCedulaS = to_string(terminalCedula);
  ApuntM apM = this->centroV.BuscarMesa(terminalCedulaS);
  if (apM == NULL) {
    string ne = vc.LeerString("Ingrese el nombre del encargado: ");
    mesa.setTerminalCedula(terminalCedulaS);
    mesa.setNombreEncargado(ne);
    if (this->centroV.InsertarMesa(mesa)) {
      vc.ImprimirMensaje("\n La mesa fue agregada correctamente ");
    } else
      vc.ImprimirMensaje("\n Ocurrio un error al momento de agregar la mesa ");
    vc.Pausa();
    return;
  }
  vc.ImprimirMensaje("\n La mesa el terminal de cedula " + terminalCedulaS +
                     " ya esta creada.\n");
  vc.Pausa();
}

// Insertar estudiante a la mesa
void Controlador::InsertarEstudianteMesa() {
  VCentroVotacion vc = this->vctrV;
  string cedula = vc.LeerString(" Ingrese la cedula del estudiante: ");
  string terminalCedula = string(cedula.back(), 1);
  ApuntM apM = this->centroV.BuscarMesa(terminalCedula);
  if (apM == NULL) {
    vc.ImprimirMensaje("\n No hay Mesa con ese terminal cedula no es posible "
                       "agregar al estudiante.\n");
    vc.Pausa();
    return;
  }
  ApuntE apE = this->centroV.BuscarEstudianteMesa(cedula);
  if (apE == NULL) {

    string nombre = vc.LeerString(" Ingrese el nombre del estudiante: ");
    string carrera = vc.LeerString(" Ingrese la carrera del estudiante: ");
    string semestre = vc.LeerString(" Ingrese el semestre del estudiante: ");
    estudiante.setCedula(cedula);
    estudiante.setNombre(nombre);
    estudiante.setCarrera(carrera);
    estudiante.setSemestre(semestre);
    if (this->centroV.InsertarEstudianteMesa(estudiante)) {
      vc.ImprimirMensaje("\n El estudiante fue agregada correctamente ");
    } else
      vc.ImprimirMensaje(
          "\n Ocurrio un error al momento de agregar el estudiante ");
    return;
  }
  vc.ImprimirMensaje("\n El estudiante ya fue agregado anteriormente.\n");
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
