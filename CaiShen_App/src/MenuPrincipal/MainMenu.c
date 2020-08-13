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
	"    [0] Mostrar directorio. [OK]\n"
	"    [1] Cargar Cliente. [OK]\n"
	"    [2] Listar Clientes. [OK]\n"
	"    [3] Modificar Cliente. [SIN CODEAR]\n"
	"    [4] Baja Cliente. [OK]\n"
	"    ----------------------------------\n"
	"    [5] Cargar Remito. [OK]\n"
	"    [6] Listar Remitos. [OK]\n"
	"    [7] Modificar Remito. [SIN CODEAR]\n"
	"    [8] Baja Remito. [OK]\n"
	"    ----------------------------------\n"
	"    [9] Listar Estado de Cuentas. [ARREGLAR]\n"
	"    [10] Guardar Cambios. [SIN CODEAR]\n"
	"    [11] . [SIN CODEAR]\n"
	"    [12] Salir. [OK]\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [0-12]:  ",
	"    [Message]: Opcion incorrecta.\n", 0, 12, 5);

	return option;
}
