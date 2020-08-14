/*
 * ============================================================================
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 * ============================================================================
 * Type: Recuperatorio segundo parcial - Laboratorio 1.
 * Version     : Beta 1.1.2 [Beta v1.1.2] - FacuFalcone_ABM_Pandemia_[Linux]
 * ============================================================================
 */

#include <stdio_ext.h> // linux
#include <stdlib.h>

#include "../Validate/caidevValidate.h"

int menu() {
	int option;
	printf("    \n"
	"    [Message]: Bienvenido a CaiShen_App [Gestor de clientes]\n"
	"    _______________________________________________________________\n"
	"    [Menu]\n"
	"    [0] Mostrar Directorio. [OK]\n"
	"    [1] Seccion Clientes. [OK]\n"
	"    [2] Seccion Remitos. [OK]\n"
	"    [3] Seccion Pagos. [OK]\n"
	"    [4] Seccion Cuentas. [OK]\n"
	"    [5] Salir. [OK]\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [0-5]:  ",
	"    [Message]: Opcion incorrecta.\n", 0, 5, 5);

	return option;
}


int menuClientes() {
	int option;
	printf("    \n"
	"    [Message]: Bienvenido a CaiShen_App [Gestor de clientes]\n"
	"    _______________________________________________________________\n"
	"    [Menu]\n"
	"    [1] Cargar Cliente. [OK]\n"
	"    [2] Listar Clientes. [OK]\n"
	"    [3] Modificar Cliente. [SIN CODEAR]\n"
	"    [4] Baja Cliente. [OK]\n"
	"    [5] Volver. [OK]\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [1-5]:  ",
	"    [Message]: Opcion incorrecta.\n", 1, 5, 5);

	return option;
}

int menuRemitos() {
	int option;
	printf("    \n"
	"    [Message]: Bienvenido a CaiShen_App [Gestor de clientes]\n"
	"    _______________________________________________________________\n"
	"    [Menu]\n"
	"    [1] Cargar Remito. [OK]\n"
	"    [2] Listar Remitos. [OK]\n"
	"    [3] Modificar Remito. [SIN CODEAR]\n"
	"    [4] Baja Remito. [OK]\n"
	"    [5] Volver. [OK]\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [1-5]:  ",
	"    [Message]: Opcion incorrecta.\n", 1, 5, 5);

	return option;
}

int menuPagos() {
	int option;
	printf("    \n"
	"    [Message]: Bienvenido a CaiShen_App [Gestor de clientes]\n"
	"    _______________________________________________________________\n"
	"    [Menu]\n"
	"    [1] Cargar Pago.\n"
	"    [2] Listar Pagos.\n"
	"    [3] Modificar Pago.\n"
	"    [4] Baja Pago.\n"
	"    [5] Volver. [OK]\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [1-5]:  ",
	"    [Message]: Opcion incorrecta.\n", 1, 5, 5);

	return option;
}
