#include "Controlador.h"
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
    vg.ImprimirEncabezado("\n      M E N U  O P C I O N E S\n",
                          "      =======  ===============");
    vg.ImprimirMensaje("   1. Bahía.\n");
    vg.ImprimirMensaje("   2. Vehículo.\n");
    vg.ImprimirMensaje("   3. Reportes.\n");
    vg.ImprimirMensaje("   4. Ayuda.\n");
    vg.ImprimirMensaje("   5. Salir.\n");
    opc = vg.LeerValidarNro("   Seleccione su opción (1-5): ", 1, 5);
    switch (opc) {
    case 1:
      cout << "opcion 1";
      break;
    case 2:
      cout << "opcion 2";
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
    }
  } while (opc != 5);
}
