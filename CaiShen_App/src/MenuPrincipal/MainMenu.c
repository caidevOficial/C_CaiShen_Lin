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
					"    [0] Mostrar directorio. [FUNCIONA]\n"
					"    [1] Cargar Cliente. [FUNCIONA]\n"
					"    [2] Listar Clientes. [FUNCIONA]\n"
					"    [3] Baja Cliente. [SIN CODEAR]\n"
					"    ----------------------------------\n"
					"    [4] Cargar Remito. [FUNCIONA]\n"
					"    [5] Listar remitos. [FUNCIONA]\n"
					"    [6] Baja Remito. [FUNCIONA]\n"
					"    ----------------------------------\n"
					"    [7] Listar Estado de Cuentas. [ARREGLAR]\n"
					"    [8] Guardar Cambios. [SIN CODEAR]\n"
					"    [9] . [SIN CODEAR]\n"
					"    [10] Salir.\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [0-8]:  ",
			"    [Message]: Opcion incorrecta.\n", 0, 10, 5);

	return option;
}
