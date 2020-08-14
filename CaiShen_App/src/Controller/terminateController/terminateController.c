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

//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../Controller.h"
#include "../registerController/registerController.h"

#include "../../Entity_Remitos/Entity_Remito.h"
#include "../../Entity_Remitos/Getters/Getters.h"

#include "../../Entity_Clientes/Entity_Customers.h"
#include "../../Entity_Clientes/Getters_Customer/Getters.h"

#include "../../Entity_Pagos/Entity_Pago.h"
#include "../../Entity_Pagos/Getters/Getters.h"

#include "../../LinkedList.h"
#include "../../Validate/caidevValidate.h"

int controller_removeRemito(LinkedList *this) {
	Remitos *pRemito;

	int sucess = 0;
	int index;
	int idRemito;
	int obtainedID;
	int confirmOption;
	int maxID;

	obtainID(&maxID, "Remitos_LastID.txt");
	if (this != NULL) {
		//controller_ListKnightZodiac(this); // imprimo lista
		controller_ListObjectRemitos(this);
		getNumberInt(&idRemito,
		"    [Message]: Ingrese ID a dar de baja\n    [De la Lista]: ", //pido el ID a borrar
		"    [Message]: ID incorrecto, reingrese. ", 1,(maxID - 1), 5);

		index = Entity_Remito_SearchForId(this, idRemito);// busco el indice de la ID

		pRemito = ll_get(this, index); // obtengo el elemento del indice
		Entity_Remitos_getID(pRemito, &obtainedID);// obtengo la id del indice
		//KnightZodiac_getID(pRemito, &obtainedID);

		if (obtainedID == idRemito) {
			//showKnightZodiac(pRemito); // muestro al Remito seleccionado
			Entity_Remito_Show(pRemito);
			//controller_ListObjectRemitos(pRemito);
			getNumberInt(&confirmOption,
			"\n\n    [Message]: Dar de baja el remito [no se podra recuperar]?"
			"\n    [1] Dar de baja Remito."
			"\n    [2] Cancelar."
			"\n    [Message]: Ingrese opcion: ",
			"    [Message]: Error, escoja opciones [1-2]: ", 1, 2, 3);

			switch (confirmOption) {
			case 1:
				ll_remove(this, index); // borro el empleado
				Entity_Remito_delete(pRemito);// borro el auxiliar de la funcion
				sucess = 1;
				break;
			case 2:
				sucess = 0;
				break;
			default:
				break;
			}
		}
	}
	return sucess;
}


int controller_removePago(LinkedList *this) {
	Pagos *pPago;

	int sucess = 0;
	int index;
	int idPago;
	int obtainedID;
	int confirmOption;
	int maxID;

	obtainID(&maxID, "Pagos_LastID.txt");
	if (this != NULL) {
		//controller_ListKnightZodiac(this); // imprimo lista
		controller_ListObjectPagos(this);
		getNumberInt(&idPago,
		"    [Message]: Ingrese ID a dar de baja\n    [De la Lista]: ", //pido el ID a borrar
		"    [Message]: ID incorrecto, reingrese. ", 1,(maxID - 1), 5);

		index = Entity_Pago_SearchForId(this, idPago);// busco el indice de la ID

		pPago = ll_get(this, index); // obtengo el elemento del indice
		Entity_Pagos_getID(pPago, &obtainedID);// obtengo la id del indice
		//KnightZodiac_getID(pPago, &obtainedID);

		if (obtainedID == idPago) {
			//showKnightZodiac(pPago); // muestro al Pago seleccionado
			Entity_Pago_Show(pPago);
			//controller_ListObjectPagos(pPago);
			getNumberInt(&confirmOption,
			"\n\n    [Message]: Dar de baja el Pago [no se podra recuperar]?"
			"\n    [1] Dar de baja Pago."
			"\n    [2] Cancelar."
			"\n    [Message]: Ingrese opcion: ",
			"    [Message]: Error, escoja opciones [1-2]: ", 1, 2, 3);

			switch (confirmOption) {
			case 1:
				ll_remove(this, index); // borro el empleado
				Entity_Pago_delete(pPago);// borro el auxiliar de la funcion
				sucess = 1;
				break;
			case 2:
				sucess = 0;
				break;
			default:
				break;
			}
		}
	}
	return sucess;
}

int controller_removeCliente(LinkedList *this) {
	eCliente *pCliente;

	int sucess = 0;
	int index;
	int idCliente;
	int obtainedID;
	int confirmOption;
	int maxID;

	obtainID(&maxID, "Clientes_LastID.txt");
	if (this != NULL) {
		controller_ListObjectClientes(this);
		getNumberInt(&idCliente,
		"    [Message]: Ingrese ID a dar de baja\n    [De la Lista]: ", //pido el ID a borrar
		"    [Message]: ID incorrecto, reingrese. ", 1,(maxID - 1), 5);

		index = Entity_Customer_SearchForId(this, idCliente);// busco el indice de la ID

		pCliente = ll_get(this, index); // obtengo el elemento del indice
		Entity_Customer_getID(pCliente, &obtainedID);// obtengo la id del indice

		if (obtainedID == idCliente) {
			Entity_Customer_Show(pCliente);
			getNumberInt(&confirmOption,
			"\n\n    [Message]: Dar de baja el cliente? [no se podra recuperar]"
			"\n    [1] Dar de baja Remito."
			"\n    [2] Cancelar."
			"\n    [Message]: Ingrese opcion: ",
			"    [Message]: Error, escoja opciones [1-2]: ", 1, 2, 3);

			switch (confirmOption) {
			case 1: /* Confirma baja */
				ll_remove(this, index); // borro el empleado
				Entity_Customer_delete(pCliente);// borro el auxiliar de la funcion
				sucess = 1;
				break;
			case 2: /* Cancela baja */
				sucess = 0;
				break;
			default:
				break;
			}
		}
	}
	return sucess;
}
