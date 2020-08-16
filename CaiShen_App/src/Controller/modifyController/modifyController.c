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

/**
 * @brief  Look for a index of the entity.
 * @param  this list of Entities.
 * @param  index The index of the entity. (could be -1)
 * @param  idPayOut The Id of the payOut.
 * @param  maxIDPayOut The id Max of the all payOut registereds.
 */
void lookForIndexPayment(LinkedList * this, int *index, int *idPayOut, int *maxIDPayOut){

	/* Muestro lista de pagos y pido el ID */
	controller_ListObjectPagos(this);
	getNumberInt(idPayOut,
	"    [MESSAGE]: Ingresa el ID del Pago: ",
	"    [ERROR]: ID incorrecto, por favor reingresalo.\n",	1, (*maxIDPayOut - 1), 5);

	/* Busco que exista el ID */
	*index = Entity_Pago_SearchForId(this, *idPayOut);
}

/**
 * @brief 	Changes the payment amount of the entity.
 * @param  this Entity to change the payment.
 * @return 1 if success, 0 for error.
 */
static int changePayment(Pagos *this){
	int success = 0;
	float payment;
	//system("cls"); // windows
	system("clear"); // linux
	Entity_Pago_Show(this);
	if (getNumberFloat(&payment,
		"    [MESSAGE]: Ingreses nuevo monto del pago [1-20000]: ",
		"    [ERROR]: Monto incorrecto, reingresalo.\n", 1, 20000, 5)) {
		Entity_Pagos_setMontoPago(this, payment);
		Entity_Pago_Show(this); // muestro los datos actualizados
		printf("    [SUCCESS]: Monto actualizado con exito! \n");
		success = 1;
	}
	return success;
}

/**
 * @brief  Modify the amount of payOut or cacell the operation.
 * @param  this Entity to be modified.
 * @param  answer Pointer to cancel the operation.
 * @return return 1 for success, 0 for error.
 */
static int pagosEditSwitch(Pagos *this, char *answer){
	int success = 0;

	do {
		Entity_Pago_Show(this);
		switch (modifyRemitosOrPagos()) {
		case 1: /* MONTO PAGO */
			if(changePayment(this)){
				success = 1;
			}
			break;
		case 2: /* SALIR */
			printf("\n    [WARNING!] Cancelando operacion.\n");
			*answer = 'n';
			success = 0;
			break;
		default:
			printf("    [ERROR]: Opcion invalida, escoja [1-5]\n");
			break;
		}

		simulatePause(); // linux
		system("clear"); // linux
	} while (*answer == 'y');
	return success;
}

int controller_editPagos(LinkedList *this) {
	Pagos *pPagos;
	int success = 0;
	int idPago;
	int maxID;
	int index;

	char pathIDPago[128] = "Pagos_LastID.txt";
	char selectedOption = 'y';

	system("clear"); // linux
	if (this != NULL) {
		obtainID(&maxID,pathIDPago);
		lookForIndexPayment(this, &index, &idPago, &maxID);

		if (index == -1) {
			printf("\n    [ERROR]: El Pago ID: %d  no existe.\n",idPago);
		} else {
			pPagos = ll_get(this, index);
			//system("cls"); // windows
			system("clear"); // linux
			pagosEditSwitch(pPagos, &selectedOption);
		}
	}
	return success;
}

/**
 * @brief  Look for a index of the entity.
 * @param  this List of Entities.
 * @param  index The index of the entity. (could be -1)
 * @param  idRem The Id of the payOut.
 * @param  maxIDRem The id Max of the all payOut registereds.
 */
void lookForIndexRem(LinkedList *this, int *index, int *idRem, int *maxIDRem){
	/* Muestro lista de pagos y pido el ID */
	controller_ListObjectRemitos(this);
	getNumberInt(idRem,
	"    [MESSAGE]: Ingresa el ID del Remito: ",
	"    [ERROR]: ID incorrecto, por favor reingresalo.\n",	1, (*maxIDRem - 1), 5);

	/* Busco que exista el ID */
	*index = Entity_Remito_SearchForId(this, *idRem);
}

/**
 * @brief  Edit the amount of the entity remito.
 * @param  this Entity to be edited.
 * @return 1 for success, 0 for error.
 */
static int changeRemAmount(Remitos *this){
	int success = 0;
	float amount;
	//system("cls"); // windows
	system("clear"); // linux
	Entity_Remito_Show(this);
	if (getNumberFloat(&amount,
		"    [MESSAGE]: Ingreses nuevo monto del remito [1-20000]: ",
		"    [ERROR]: Monto incorrecto, reingresalo.\n", 1, 20000, 5)) {
		Entity_Remitos_setMontoRemito(this, amount);
		Entity_Remito_Show(this); // muestro los datos actualizados
		printf("    [SUCCESS]: Remito actualizado con exito! \n");
		success = 1;
	}
	return success;
}

/**
 * @brief  Modify the amount of Rem or cancel the operation.
 * @param  this Entity to be modified.
 * @param  answer Pointer to cancel the operation.
 * @return return 1 for success, 0 for error.
 */
static int remEditSwitch(Remitos *this, char *answer){
	int success = 0;

	do {
		Entity_Remito_Show(this);
		switch (modifyRemitosOrPagos()) {
		case 1: /* MONTO REMITO */
			if(changeRemAmount(this)){
				success = 1;
			}
			break;
		case 2: /* SALIR */
			printf("\n    [WARNING!] Cancelando operacion.\n");
			*answer = 'n';
			success = 0;
			break;
		default:
			printf("    [ERROR]: Opcion invalida, escoja [1-5]\n");
			break;
		}
		simulatePause(); // linux
		system("clear"); // linux
	} while (*answer == 'y');

	return success;
}

int controller_editRemitos(LinkedList *this) {
	Remitos *pRemito;
	int sucess = 0;
	int idRemito;
	int maxID;
	int index;

	char pathIDRemito[128] = "Remitos_LastID.txt";
	char selectedOption = 'y';

	system("clear"); // linux
	if (this != NULL) {
		obtainID(&maxID,pathIDRemito);
		lookForIndexRem(this, &index, &idRemito, &maxID);

		if (index == -1) {
			printf("\n    [ERROR]: El Pago ID: %d  no existe.\n",idRemito);
		} else {
			pRemito = ll_get(this, index);
			//system("cls"); // windows
			system("clear"); // linux
			remEditSwitch(pRemito, &selectedOption);
		}
	}
	return sucess;
}

/**
 * @brief  Look for a index of the entity.
 * @param  this List of Entities.
 * @param  index The index of the entity. (could be -1)
 * @param  idCustomer The Id of the customer.
 * @param  maxIdCustomer The id Max of the all customers registereds.
 */
void lookForIndexCustomer(LinkedList *this, int *index,int *idCustomer, int *maxIdCustomer){
	/* Muestro Clientes y pido el ID */
		controller_ListObjectClientes(this);
		getNumberInt(idCustomer,
		"    [Message]: Ingresa el ID del Cliente: ",
		"    [ERROR]: ID incorrecto, por favor reingresalo.\n", 1, (*maxIdCustomer - 1), 5);

		/* Busco que exista el ID */
		*index = Entity_Customer_SearchForId(this, *idCustomer);
}

/**
 * @brief  Changes the name of the field razonSocial.
 * @param  this Entity to be modified.
 * @return 1 for success, 0 for error.
 */
static int changeRazonSocial(eCliente *this){
	int success = 0;
	char razonSocial[128];
	//system("cls"); // windows
	system("clear"); // linux
	Entity_Customer_Show(this);
	if (getName(razonSocial, 128,
			"    [Message]: Ingresa una nueva Razon Social: ",
			"    [ERROR]: Constelacion incorrecta, reingresala.\n",	5)) {
		uppercaselInitial(razonSocial);
		Entity_Customer_setRazonSocial(this, razonSocial);
		printf("    [SUCCESS]: Razon Social actualizada con exito!\n");
		Entity_Customer_Show(this);
		success = 1;
	}
	return success;
}

/**
 * @brief  Changes the name of the field contacto.
 * @param  this Entity to be modified.
 * @return 1 for success, 0 for error.
 */
static int changeName(eCliente *this){
	int success = 0;
	char contacto[128];
	//system("cls"); // windows
	system("clear"); // linux
	Entity_Customer_Show(this);
	if (getName(contacto, 128,
		"    [Message]: Ingrese nuevo nombre: ",
		"    [ERROR]: Nombre incorrecto, reingresalo.\n",5)) {
		uppercaselInitial(contacto);
		Entity_Customer_setDuenho(this, contacto);
		Entity_Customer_Show(this);
		printf(
				"    [SUCCESS]: Nombre actualizado con exito!\n");
		success = 1;
	}
	return success;
}

/**
 * @brief  Changes the name of the field ciudad.
 * @param  this Entity to be modified.
 * @return 1 for success, 0 for error.
 */
static int changeCity(eCliente *this){
	int success = 0;
	char city[128];
	//system("cls"); // windows
	system("clear"); // linux
	Entity_Customer_Show(this);
	if (getName(city, 128,
		"    [Message]: Ingresa una nueva Ciudad: ",
		"    [ERROR]: Ciudad incorrecta, reingresala.\n",	5)) {
		uppercaselInitial(city);
		Entity_Customer_setLocalidad(this, city);
		printf("    [SUCCESS]: Ciudad actualizada con exito!\n");
		Entity_Customer_Show(this); // muestro los datos actualizados
		success = 1;
	}
	return success;
}

/**
 * @brief  Changes the name of the field telefono.
 * @param  this Entity to be modified.
 * @return 1 for success, 0 for error.
 */
static int changePhone(eCliente *this){
	int success = 0;
	char phone[128];
	//system("cls"); // windows
	system("clear"); // linux
	Entity_Customer_Show(this);
	if (getName(phone, 128,
		"    [Message]: Ingresa una nuevo telefono: ",
		"    [ERROR]: telefono incorrecto, reingresalo.\n",	5)) {
		Entity_Customer_setTelefono(this, phone);
		printf("    [SUCCESS]: Telefono actualizado con exito!\n");
		Entity_Customer_Show(this); // muestro los datos actualizados
		success = 1;
	}
	return success;
}

/**
 * @brief  Changes the name of the field calle.
 * @param  this Entity to be modified.
 * @return 1 for success, 0 for error.
 */
static int changeStreet(eCliente *this){
	int success = 0;
	char street[128];
	//system("cls"); // windows
	system("clear"); // linux
	Entity_Customer_Show(this);
	if (getName(street, 128,
		"    [Message]: Ingresa una nueva calle: ",
		"    [ERROR]: Constelacion incorrecta, reingresala.\n",	5)) {
		uppercaselInitial(street);
		Entity_Customer_setCalle(this, street);
		printf("    [SUCCESS]: Calle actualizada con exito!\n");
		Entity_Customer_Show(this);
		success = 1;
	}
	return success;
}

/**
 * @brief  Changes the name of the field numeroDireccion.
 * @param  this Entity to be modified.
 * @return 1 for success, 0 for error.
 */
static int changeStreetNumber(eCliente *this){
	int success = 0;
	int streetNumber;
	//system("cls"); // windows
	system("clear"); // linux
	Entity_Customer_Show(this);
	if(getNumberInt(&streetNumber,
		"    [Messagge]: Ingresa en nuevo numero: ",
		"    [ERROR]: Numero incorrecto, reingresalo.\n", 1, 20000, 7)){
		Entity_Customer_setNumeroDireccion(this, streetNumber);
		printf("    [SUCCESS]: Altura actualizada con exito!\n");
		Entity_Customer_Show(this);
		success = 1;
	}
	return success;
}

/**
 * @brief  Changes some field of the entity.
 * @param  this Entity to be modified.
 * @param  answer Variable to end the loop
 * @return 1 for success, 0 for error.
 */
static int CustomerEditSwitch(eCliente *this, char *answer){
	int success = 0;

	do {
		Entity_Customer_Show(this);
		switch (modifyCustomers()) {
			case 1: /* Razon Social */
				if(changeRazonSocial(this)){
					success = 1;
				}
				break;
			case 2: /* NOMBRE */
				if(changeName(this)){
					success = 1;
				}
				break;
			case 3: /* Ciudad */
				if(changeCity(this)){
					success = 1;
				}
				break;
			case 4: /* Telefono */
				if(changePhone(this)){
					success = 1;
				}
				break;
			case 5: /* CALLE */
				if(changeStreet(this)){
					success = 1;
				}
				break;
			case 6: /* Altura */
				if(changeStreetNumber(this)){
					success = 1;
				}
				break;
			case 7: /* SALIR */
				printf("\n    [Warning!]: Cancelando operacion.\n");
				*answer = 'n';
				success = 0;
				break;
			default:
				printf("    [ERROR]: Opcion invalida, escoja [1-5]\n");
				break;
			}
		//system("pause"); // windows
		//system("cls"); // windows
		simulatePause(); // linux
		system("clear"); // linux
	} while (*answer == 'y');
	return success;
}

int controller_editCustomer(LinkedList *this) {
	eCliente *pCustomer;
	int sucess = 0;
	int idCustomer;
	int maxID;
	int index;

	char selectedOption = 'y';
	char pathIDClientes[128] = "Clientes_LastID.txt";

	//system("cls"); // windows
	system("clear"); // linux
	if (this != NULL) {
		obtainID(&maxID,pathIDClientes);
		lookForIndexCustomer(this, &index, &idCustomer, &maxID);

		if (index == -1) {
			printf(
					"\n    [Message]: El Cliente ID: %d  aun no existe.\n",
					idCustomer);
		} else {
			pCustomer = ll_get(this, index);
			//system("cls"); // windows
			system("clear"); // linux
			CustomerEditSwitch(pCustomer, &selectedOption);
		}
	}
	return sucess;
}
