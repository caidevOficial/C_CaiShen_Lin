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

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../Controller.h"

#include "../../Entity_Clientes/Entity_Customers.h"
#include "../../Entity_Clientes/Getters_Customer/Getters.h"
#include "../../Entity_Clientes/Setters_Customer/Setters.h"

#include "../../Entity_Cuentas/Entity_Accounts.h"
#include "../../Entity_Cuentas/Setters_Account/Setters.h"

#include "../../Entity_Remitos/Entity_Remito.h"
#include "../../Entity_Remitos/Setters/Setters.h"
#include "../../Entity_Remitos/Getters/Getters.h"

#include "../../Entity_Pagos/Entity_Pago.h"
#include "../../Entity_Pagos/Setters/Setters.h"

#include "../../LinkedList.h"
#include "../../Validate/caidevValidate.h"

//#include "../saveMaxID_toText/saveToText_maxID.h"

int obtainID(int* id, char* path){
	int sucess = 0;
	int newID;
	//*id = 1001; //la inicializo con 1001
	FILE* pFile;
	pFile = fopen(path,"r"); // abro el archivo.
	if(pFile!=NULL){
		fscanf(pFile, "%d\n", &newID);
		//fread(&newID,sizeof(int),1,pFile); //leo la ultima id guardada.
		*id = newID;
		fclose(pFile); // lo cierro si lo pude abrir.
		sucess = 1;
	}
	return sucess;
}

int upgradeID(int id,char* path){
	int nextID = ++id; // nextID vale id+1
	// ++id es lo mismo que (id++)
	int sucess = 0;
	FILE* pFile;
	pFile = fopen(path,"w"); // abre el texto
	if(pFile!=NULL){
		fprintf(pFile,"%d\n",nextID);
		//fwrite(&nextID,sizeof(int),1,pFile); //guarda la id en binario
		fclose(pFile); // lo cierro si lo pude abrir.
		sucess = 1;
	}
	return sucess;
}

/**
 * @brief  Checks if the tntity customer exist.
 * @param thisCustomer list of entities to be checked.
 * @param this Entity to be checked.
 * @param customerId id of the entity to find its index.
 * @param lastIDCustomer id of the last entity of the list.
 * @param customerIndex index number of the entity.
 * @param customerName name of the field nombre of the entity.
 */
static void checkCustomerExistence(LinkedList *thisCustomer, eCliente *this, int *customerId, int *lastIDCustomer, int *customerIndex, char *customerName){
	//------------------- Pido Id de cliente para asociar al remito
	controller_ListObjectClientes(thisCustomer);
	getNumberInt(customerId, "   [Message] Seleccione un cliente: ", "   [ERROR] Cliente incorrecto.\n", 1, (*lastIDCustomer-1), 5);
	//customerIndex = ll_indexOf(thisCustomer, &customerId);
	*customerIndex = Entity_Customer_SearchForId(thisCustomer, *customerId);
	this = ll_get(thisCustomer,*customerIndex);
	Entity_Customer_getRazonSocial(this, customerName);

}

int controller_addRemito(LinkedList *this, LinkedList *thisCustomer) {
	Remitos *pRemito;
	eCliente *pCliente;
	pRemito = Entity_newRemito();
	pCliente =Entity_newClientes();

	//--------- Setea Fecha Actual---------------
	char date[128];
	time_t fecha = time(0);
	struct tm *tlocal = localtime(&fecha);
	strftime(date,128,"%d/%m/%y",tlocal);
	//--------------------------------------------
	int sucess = 0;
	int ultimoIdCliente;
	int ultimoIdRemito;

	//----- Para hacer el remito
	int customerId;
	int customerIndex;
	char customerName[128];
	float remitoAmount;

	if (this != NULL && thisCustomer != NULL) {

		obtainID(&ultimoIdCliente,"Clientes_LastID.txt"); // Obtengo el ID al leerlo desde el archivo "ultimoIdCliente.txt" .
		obtainID(&ultimoIdRemito,"Remitos_LastID.txt"); // Obtengo el ID al leerlo desde el archivo "ultimoIdRemito.txt" .
		printf("    [Message]: El alta se asignara con el ID: %d\n",ultimoIdRemito);
		printf("    [FECHA]  %s \n",date);
		checkCustomerExistence(thisCustomer, pCliente, &customerId, &ultimoIdCliente, &customerIndex, customerName);
		printf("   [Message] Se agregara un Remito para: %s\n",customerName);
		//------------------- Pido Monto del remito
		getNumberFloat(&remitoAmount, "   [Message] Ingrese el monto del remito: ", "   [ERROR] Monto incorrecto, no puede superar los 20k\n", 0, 20000, 5);

		if (pRemito != NULL) {

			Entity_Remitos_setDate(pRemito, date);
			Entity_Remitos_setID(pRemito, &ultimoIdRemito);
			Entity_Remitos_setCliente(pRemito, customerName);
			Entity_Remitos_setIdCliente(pRemito, customerId);
			Entity_Remitos_setMontoRemito(pRemito, remitoAmount);
			ll_add(this, pRemito);
			upgradeID(ultimoIdRemito,"Remitos_LastID.txt"); // guarda en el archivo ultimoIdRemito+1 en "ultimoIdRemito.txt"
			sucess = 1;
			printf("   [SUCCESS] Remito agregado con exito!\n");
		}else{
			printf("   [ERROR] Problemas al crear el remito!\n");
		}
	}
	return sucess;
}

int controller_addPago(LinkedList *this, LinkedList *thisCustomer) {
	Pagos *pPago;
	eCliente *pCliente;
	pPago = Entity_newPago();
	pCliente =Entity_newClientes();

	//--------- Setea Fecha Actual---------------
	char date[128];
	time_t fecha = time(0);
	struct tm *tlocal = localtime(&fecha);
	strftime(date,128,"%d/%m/%y",tlocal);
	//--------------------------------------------
	int sucess = 0;
	int ultimoIdCliente;
	int ultimoIdPago;

	//----- Para hacer el Pago
	int customerId;
	int customerIndex;
	char customerName[128];
	float PagoAmount;

	if (this != NULL && thisCustomer != NULL) {

		obtainID(&ultimoIdCliente,"Clientes_LastID.txt"); // Obtengo el ID al leerlo desde el archivo "ultimoIdCliente.txt" .
		obtainID(&ultimoIdPago,"Pagos_LastID.txt"); // Obtengo el ID al leerlo desde el archivo "ultimoIdPago.txt" .
		printf("    [Message]: El alta se asignara con el ID: %d\n",ultimoIdPago);
		printf("    [FECHA]  %s \n",date);

		checkCustomerExistence(thisCustomer, pCliente, &customerId, &ultimoIdCliente, &customerIndex, customerName);
		printf("   [Message] Se agregara un Pago para: %s\n",customerName);
		//------------------- Pido Monto del Pago
		getNumberFloat(&PagoAmount, "   [Message] Ingrese el monto del Pago: ", "   [ERROR] Monto incorrecto, no puede superar los 20k\n", 0, 20000, 5);

		if (pPago != NULL) {
			Entity_Pagos_setDate(pPago, date);
			Entity_Pagos_setID(pPago, &ultimoIdPago);
			Entity_Pagos_setCliente(pPago, customerName);
			Entity_Pagos_setIdCliente(pPago, customerId);
			Entity_Pagos_setMontoPago(pPago, PagoAmount);
			ll_add(this, pPago);
			upgradeID(ultimoIdPago,"Pagos_LastID.txt"); // guarda en el archivo ultimoIdPago+1 en "ultimoIdPago.txt"
			sucess = 1;
			printf("   [SUCCESS] Pago agregado con exito!\n");
		}else{
			printf("   [ERROR] Problemas al crear el Pago!\n");
		}
	}
	return sucess;
}

/**
 * @brief  gets all the data of the new entity.
 * @param  customerName name of the customer bussiness.
 * @param  name name of the customer.
 * @param  city city where the customer is.
 * @param  street address of the customer.
 * @param  phone phone number of the entity.
 * @param  streetNumber number of the address.
 */
static void getCustomerData(char *customerName, char *name, char *city, char *street, char *phone, int *streetNumber){
	//------------------- Pido datos de cliente
	int textLength = 128;
	getName(customerName, textLength, "   [Message] Ingrese razon social sin espacios: ", "   [ERROR] Razon social Erronea.\n", 5);
	uppercaselInitial(customerName);
	getName(name, textLength, "   [Message] Ingrese nombre de contacto sin espacios: ", "   [ERROR] Nombre incorrecto.\n", 5);
	uppercaselInitial(name);
	getName(city, textLength, "   [Message] Ingrese localidad sin espacios: ", "   [ERROR] Localidad incorrecta.\n", 7);
	uppercaselInitial(city);
	getName(street, textLength, "   [Message] Ingrese nombre de calle [sin espacios]: ", "   [ERROR] Calle incorrecta.\n", 7);
	uppercaselInitial(street);
	getNumberInt(streetNumber, "   [Message] Ingrese altura: ", "   [ERROR] Incorrecto, excede el limite de 15k.\n", 0, 15000, 7);
	getPhoneNumber(phone, 12, "   [Message] Ingrese telefono de contacto [solo numeros]: ", "   [ERROR] Telefono incorrecto.\n", 7);
}

int controller_addCliente(LinkedList *this, LinkedList *thisAccount){
	eCliente *pCliente;
	Accounts *pAccount;
	pCliente =Entity_newClientes();
	pAccount = Entity_newAccount();

	int sucess = 0;
	int ultimoIdCliente;
	int numeroDireccion;

	char calle[128];
	char telefono[12];
	char localidad[128];
	char customerName[128];
	char nombreDuenho[128];

	if (this != NULL) {

		obtainID(&ultimoIdCliente,"Clientes_LastID.txt"); // Obtengo el ID al leerlo desde el archivo "ultimoIdCliente.txt" .
		printf("    [Message]: El alta se asignara con el ID: %d\n",ultimoIdCliente);
		getCustomerData(customerName, nombreDuenho, localidad, calle, telefono, &numeroDireccion);

		if (pCliente != NULL && pAccount != NULL) {

			// CREO ENTIDAD CLIENTE
			Entity_Customer_setID(pCliente, &ultimoIdCliente);
			Entity_Customer_setRazonSocial(pCliente, customerName);
			Entity_Customer_setDuenho(pCliente, nombreDuenho);
			Entity_Customer_setLocalidad(pCliente, localidad);
			Entity_Customer_setCalle(pCliente, calle);
			Entity_Customer_setTelefono(pCliente, telefono);
			Entity_Customer_setNumeroDireccion(pCliente, numeroDireccion);
			Entity_Customer_setIdCuenta(pCliente, ultimoIdCliente);

			// CREO ENTIDAD CUENTA
			Entity_Account_setID(pAccount, &ultimoIdCliente);
			Entity_Account_setIDCliente(pAccount, &ultimoIdCliente);
			Entity_Account_setCliente(pAccount, customerName);
			Entity_Account_setDebe(pAccount, 0);
			Entity_Account_setHaber(pAccount, 0);
			Entity_Account_setDeudaActual(pAccount, 0);

			ll_add(thisAccount, pAccount);
			if(!ll_add(this, pCliente)){
				printf("   [SUCCESS] Cliente agregado con exito!\n");
				upgradeID(ultimoIdCliente, "Cuentas_LastID.txt");
				upgradeID(ultimoIdCliente,"Clientes_LastID.txt"); // guarda en el archivo ultimoIdCliente+1 en "ultimoIdCliente.txt"
				sucess = 1;
			}
		}
	}
	return sucess;
}
