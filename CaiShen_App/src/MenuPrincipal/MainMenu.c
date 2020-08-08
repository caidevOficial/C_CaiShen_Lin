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
					"    [Message]: Bienvenido \n"
			"    _______________________________________________________________\n"
			"    [Menu]\n"
					"    [0] Mostrar directorio.\n"
					"    [1] Cargar Cliente.\n"
					"    [2] Listar Clientes.\n"
					"    [3] Baja Cliente.\n"
					"    [4] Cargar Remito.\n"
					"    [5] Listar remito por cliente.\n"
					"    [6] Baja Remito.\n"
					"    [7] Listar Estado de Cuentas.\n"
					"    [8] .\n"
					"    [9] .\n"
					"    [10] Salir.\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [0-8]:  ",
			"    [Message]: Opcion incorrecta.\n", 0, 10, 5);

	return option;
}
