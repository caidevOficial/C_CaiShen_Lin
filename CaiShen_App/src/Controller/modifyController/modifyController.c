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
 *
 * Version     : Beta 3.3.0 [Beta v3.3.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

//#include <stdio.h> // windows
#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../registerController/registerController.h"
#include "../../Controller/Controller.h"

#include "../../Entity_Clientes/Entity_Customers.h"
#include "../../Entity_Clientes/Getters_Customer/Getters.h"
#include "../../Entity_Clientes/Setters_Customer/Setters.h"

#include "../../Entity_Pagos/Entity_Pago.h"
#include "../../Entity_Pagos/Getters/Getters.h"
#include "../../Entity_Pagos/Setters/Setters.h"

#include "../../Entity_Remitos/Entity_Remito.h"
#include "../../Entity_Remitos/Getters/Getters.h"
#include "../../Entity_Remitos/Setters/Setters.h"

#include "../../LinkedList.h"
#include "../../FuncionPrincipal/MainApp.h"
#include "../../MenuPrincipal/MainMenu.h"
#include "../../Validate/caidevValidate.h"

int controller_editPagos(LinkedList *this) {
	Pagos *pPagos;
	int sucess = 0;
	int idPago;
	int maxID;
	int index;
	float montoPago;

	char pathIDPago[128] = "Pagos_LastID.txt";
	char selectedOption = 'y';

	system("clear"); // linux
	if (this != NULL) {
		obtainID(&maxID,pathIDPago);
		/* Muestro lista de pagos y pido el ID */
		controller_ListObjectPagos(this);
		getNumberInt(&idPago,
		"    [MESSAGE]: Ingresa el ID del Pago a modificar: ",
		"    [ERROR]: ID incorrecto, por favor reingresalo.\n",	1, (maxID - 1), 5);

		/* Busco que exista el ID */
		index = Entity_Pago_SearchForId(this, idPago);

		if (index == -1) {
			printf("\n    [ERROR]: El Pago ID: %d  no existe.\n",idPago);
		} else {
			pPagos = ll_get(this, index);
			//system("cls"); // windows
			system("clear"); // linux

			do {
				Entity_Pago_Show(pPagos);
				switch (modifyRemitosOrPagos()) {
				case 1: /* MONTO PAGO */
					//system("cls"); // windows
					system("clear"); // linux
					Entity_Pago_Show(pPagos);
					if (getNumberFloat(&montoPago,
						"    [MESSAGE]: Ingreses nuevo monto del pago [1-20000]: ",
						"    [ERROR]: Monto incorrecto, reingresalo.\n", 1, 20000, 5)) {
						Entity_Pagos_setMontoPago(pPagos, montoPago);
						Entity_Pago_Show(pPagos); // muestro los datos actualizados
						printf("    [SUCCESS]: Monto actualizado con exito! \n");
						sucess = 1;
					}
					break;

				case 2: /* SALIR */
					printf("\n    [WARNING!] Cancelando operacion.\n");
					selectedOption = 'n';
					sucess = 0;
					break;
				default:
					printf("    [ERROR]: Opcion invalida, escoja [1-5]\n");
					break;
				}

				simulatePause(); // linux
				system("clear"); // linux
			} while (selectedOption == 'y');
		}
	}
	return sucess;
}


int controller_editRemitos(LinkedList *this) {
	Remitos *pRemito;
	int sucess = 0;
	int idRemito;
	int maxID;
	int index;
	float montoRemito;

	char pathIDRemito[128] = "Remitos_LastID.txt";
	char selectedOption = 'y';

	system("clear"); // linux
	if (this != NULL) {
		obtainID(&maxID,pathIDRemito);
		/* Muestro lista de pagos y pido el ID */
		controller_ListObjectRemitos(this);
		getNumberInt(&idRemito,
		"    [MESSAGE]: Ingresa el ID del Pago a modificar: ",
		"    [ERROR]: ID incorrecto, por favor reingresalo.\n",	1, (maxID - 1), 5);

		/* Busco que exista el ID */
		index = Entity_Remito_SearchForId(this, idRemito);

		if (index == -1) {
			printf("\n    [ERROR]: El Pago ID: %d  no existe.\n",idRemito);
		} else {
			pRemito = ll_get(this, index);
			//system("cls"); // windows
			system("clear"); // linux

			do {
				Entity_Remito_Show(pRemito);
				switch (modifyRemitosOrPagos()) {
				case 1: /* MONTO REMITO */
					//system("cls"); // windows
					system("clear"); // linux
					Entity_Remito_Show(pRemito);
					if (getNumberFloat(&montoRemito,
						"    [MESSAGE]: Ingreses nuevo monto del remito [1-20000]: ",
						"    [ERROR]: Monto incorrecto, reingresalo.\n", 1, 20000, 5)) {
						Entity_Remitos_setMontoRemito(pRemito, montoRemito);
						Entity_Remito_Show(pRemito); // muestro los datos actualizados
						printf("    [SUCCESS]: Remito actualizado con exito! \n");
						sucess = 1;
					}
					break;

				case 2: /* SALIR */
					printf("\n    [WARNING!] Cancelando operacion.\n");
					selectedOption = 'n';
					sucess = 0;
					break;
				default:
					printf("    [ERROR]: Opcion invalida, escoja [1-5]\n");
					break;
				}

				simulatePause(); // linux
				system("clear"); // linux
			} while (selectedOption == 'y');
		}
	}
	return sucess;
}
