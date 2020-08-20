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
 * Author		: FacuFalcone.
 * Type			: ACCOUNT_MANAGER_CAISHEN.
 * SO			: [Linux]
 * Version		: Beta 1.0.0 [Beta v1.0.0]
 * ============================================================================
 */

#include <stdio_ext.h> // linux
#include <stdlib.h>

#include "../Validate/caidevValidate.h"

int menu() {
	int option;
	printf("    \n"
	"    [Message]: Bienvenido a CaiShen_App [Gestor de clientes]\n"
	"    __________________________________________________________\n"
	"    [Menu]\n"
	"    [0] Mostrar Directorio.\n"
	"    [1] Seccion Clientes.\n"
	"    [2] Seccion Remitos.\n"
	"    [3] Seccion Pagos.\n"
	"    [4] Estado de Cuentas.\n"
	"    [5] Salir.\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [0-5]:  ",
	"    [ERROR]: Opcion incorrecta.\n", 0, 5, 5);

	return option;
}

int menuClientes() {
	int option;
	printf("    \n"
	"    [Message]: CaiShen_App [Gestor de clientes]\n"
	"    [SUB_MENU]: CLIENTES.\n"
	"    __________________________________________________________\n"
	"    [Menu]\n"
	"    [1] Cargar Cliente.\n"
	"    [2] Listar Clientes.\n"
	"    [3] Modificar Cliente.\n"
	"    [4] Baja Cliente.\n"
	"    [5] Volver.\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [1-5]:  ",
	"    [ERROR]: Opcion incorrecta.\n", 1, 5, 5);

	return option;
}

int menuRemitos() {
	int option;
	printf("    \n"
	"    [Message]: CaiShen_App [Gestor de clientes]\n"
	"    [SUB_MENU]: REMITOS.\n"
	"    __________________________________________________________\n"
	"    [Menu]\n"
	"    [1] Cargar Remito.\n"
	"    [2] Listar Remitos.\n"
	"    [3] Modificar Remito.\n"
	"    [4] Baja Remito.\n"
	"    [5] Volver.\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [1-5]:  ",
	"    [ERROR]: Opcion incorrecta.\n", 1, 5, 5);

	return option;
}

int menuPagos() {
	int option;
	printf("    \n"
	"    [Message]: CaiShen_App [Gestor de clientes]\n"
	"    [SUB_MENU]: PAGOS.\n"
	"    __________________________________________________________\n"
	"    [Menu]\n"
	"    [1] Cargar Pago.\n"
	"    [2] Listar Pagos.\n"
	"    [3] Modificar Pago.\n"
	"    [4] Baja Pago.\n"
	"    [5] Volver.\n");
	getNumberInt(&option, "    [Message]: Escoje una opcion [1-5]:  ",
	"    [ERROR]: Opcion incorrecta.\n", 1, 5, 5);

	return option;
}

int modifyCustomers() {
	int optionChoosen;
	printf("\n\n    [Message] MODIFICAR CLIENTES:"
			"\n    [1] Modificar Razon Social."
			"\n    [2] Modificar Contacto."
			"\n    [3] Modificar Ciudad."
			"\n    [4] Modificar Telefono."
			"\n    [5] Modificar Calle."
			"\n    [6] Modificar Altura."
			"\n    [7] Cancelar y volver."
			"\n    Opcion:");
	getNumberInt(&optionChoosen, " Opcion elegida [1-7]: ",
	"Error, opcion incorrecta.", 1, 7, 5);
	return optionChoosen;
}

int modifyRemitosOrPagos() {
	int optionChoosen;
	printf("\n\n    [Message] MODIFICAR:"
			"\n    [1] Modificar Monto."
			"\n    [2] Cancelar."
			"\n    Opcion:");
	getNumberInt(&optionChoosen, " Opcion elegida [1-2]: ",
	"Error, opcion incorrecta.", 1, 2, 5);
	return optionChoosen;
}
