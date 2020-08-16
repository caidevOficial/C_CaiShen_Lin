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

//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../Controller.h"
#include "../modifyController/modifyController.h"
#include "../registerController/registerController.h"

#include "../../Entity_Remitos/Entity_Remito.h"
#include "../../Entity_Remitos/Getters/Getters.h"

#include "../../Entity_Clientes/Entity_Customers.h"
#include "../../Entity_Clientes/Getters_Customer/Getters.h"

#include "../../Entity_Pagos/Entity_Pago.h"
#include "../../Entity_Pagos/Getters/Getters.h"

#include "../../LinkedList.h"
#include "../../Validate/caidevValidate.h"

/**
 * @brief  Shows and remove the entity remito from the list.
 * @param  this List of the entities.
 * @param  thisRem Entity to be deleted.
 * @param  index index of the entity.
 * @return 1 for success, 0 for error.
 */
static int showAndDeleteRemito(LinkedList *this, Remitos *thisRem, int index){
	int success = 0;
	int confirm;
	Entity_Remito_Show(thisRem);
	getNumberInt(&confirm,
	"\n\n    [Message]: Dar de baja el remito [no se podra recuperar]?"
	"\n    [1] Dar de baja Remito."
	"\n    [2] Cancelar."
	"\n    [Message]: Ingrese opcion: ",
	"    [Message]: Error, escoja opciones [1-2]: ", 1, 2, 3);

	switch (confirm) {
		case 1:
			ll_remove(this, index); // borro el empleado
			Entity_Remito_delete(thisRem);// borro el auxiliar de la funcion
			success = 1;
			break;
		case 2:
			success = 0;
			break;
		default:
			break;
	}

	return success;
}

int controller_removeRemito(LinkedList *this) {
	Remitos *pRemito;

	int sucess = 0;
	int index;
	int idRemito;
	int maxID;

	obtainID(&maxID, "Remitos_LastID.txt");
	if (this != NULL) {

		lookForIndexRem(this, &index, &idRemito, &maxID);
		if (index != -1) {
			pRemito = ll_get(this, index); // obtengo el elemento del indice.
			showAndDeleteRemito(this, pRemito, index); // Muestro el remito y lo borro o no.
		}
	}
	return sucess;
}

/**
 * @brief  Shows and remove the entity pagos from the list.
 * @param  this List of the entities.
 * @param  thisPayment Entity to be deleted.
 * @param  index index of the entity.
 * @return 1 for success, 0 for error.
 */
static int showAndDeletePayment(LinkedList *this, Pagos *thisPayment, int index){
	int success = 0;
	int confirm;
	Entity_Pago_Show(thisPayment);
	getNumberInt(&confirm,
	"\n\n    [Message]: Dar de baja el Pago [no se podra recuperar]?"
	"\n    [1] Dar de baja Pago."
	"\n    [2] Cancelar."
	"\n    [Message]: Ingrese opcion: ",
	"    [Message]: Error, escoja opciones [1-2]: ", 1, 2, 3);

	switch (confirm) {
		case 1:
			ll_remove(this, index); // borro el empleado
			Entity_Pago_delete(thisPayment);// borro el auxiliar de la funcion
			success = 1;
			break;
		case 2:
			success = 0;
			break;
		default:
			break;
		}

	return success;
}

int controller_removePago(LinkedList *this) {
	Pagos *pPago;

	int sucess = 0;
	int index;
	int idPago;
	int maxID;

	obtainID(&maxID, "Pagos_LastID.txt");
	if (this != NULL) {
		lookForIndexPayment(this, &index, &idPago, &maxID);

		if (index != -1) {
			pPago = ll_get(this, index); // obtengo el elemento del indice
			showAndDeletePayment(this, pPago,index);
		}
	}
	return sucess;
}

/**
 * @brief  Shows and remove the entity customer from the list.
 * @param  this List of the entities.
 * @param  thisCustomer Entity to be deleted.
 * @param  index index of the entity.
 * @return 1 for success, 0 for error.
 */
static int showAndDeleteCustomer(LinkedList *this, eCliente *thisCustomer, int index){
	int success = 0;
	int confirmOption;

	Entity_Customer_Show(thisCustomer);
	getNumberInt(&confirmOption,
	"\n\n    [Message]: Dar de baja el cliente? [no se podra recuperar]"
	"\n    [1] Dar de baja Remito."
	"\n    [2] Cancelar."
	"\n    [Message]: Ingrese opcion: ",
	"    [Message]: Error, escoja opciones [1-2]: ", 1, 2, 3);

	switch (confirmOption) {
		case 1: /* Confirma baja */
			ll_remove(this, index); // borro el empleado
			Entity_Customer_delete(thisCustomer);// borro el auxiliar de la funcion
			success = 1;
			break;
		case 2: /* Cancela baja */
			success = 0;
			break;
		default:
			break;
		}

	return success;
}

int controller_removeCliente(LinkedList *this) {
	eCliente *pCliente;

	int sucess = 0;
	int index;
	int idCliente;
	int maxID;

	obtainID(&maxID, "Clientes_LastID.txt");
	if (this != NULL) {
		lookForIndexCustomer(this, &index, &idCliente, &maxID);

		if (index != -1) {
			pCliente = ll_get(this, index); // obtengo el elemento del indice
			showAndDeleteCustomer(this, pCliente, index);
		}
	}
	return sucess;
}
