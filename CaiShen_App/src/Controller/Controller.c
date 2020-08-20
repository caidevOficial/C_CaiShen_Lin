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

#define CUSTOMER 0
#define REMITO 1
#define PAGO 2

#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "saveMaxID_toText/saveToText_maxID.h"

#include "../Entity_Clientes/Entity_Customers.h"
#include "../Entity_Clientes/Getters_Customer/Getters.h"

#include "../Entity_Cuentas/Entity_Accounts.h"
#include "../Entity_Cuentas/Getters_Account/Getters.h"
#include "../Entity_Cuentas/Setters_Account/Setters.h"

#include "../Entity_Pagos/Entity_Pago.h"
#include "../Entity_Pagos/Getters/Getters.h"

#include "../Entity_Remitos/Entity_Remito.h"
#include "../Entity_Remitos/Getters/Getters.h"

#include "../LinkedList.h"
#include "../Parser/parserRemito.h"
#include "../Parser/parserCustomer.h"
#include "../Parser/parserAccount.h"
#include "../Parser/parserPagos.h"


int controller_loadFromTextRemitos(char *path, LinkedList *this) {
	FILE *pFile; // para leer los objetos
	FILE *pFile2;

	int sucess = 0;
	pFile = fopen(path, "r");
	pFile2 = fopen("Remitos_LastID.txt", "w");
	if (pFile != NULL) {
		if(parser_ObjectFromTextRemito(pFile, this)){
			fclose(pFile);
			sucess = 1;
		}
		else{
			printf("    ERROR: No se pudo parsear Remito.\n");
		}

	}else{
		printf("    ERROR: El archivo es NULL");
	}

	if (controller_saveAsTextMaxID(pFile2, "Remitos_LastID.txt", this,REMITO)) {
		fclose(pFile2);
	}

	return sucess;
}


int controller_loadFromTextPagos(char *path, LinkedList *this) {
	FILE *pFile; // para leer los objetos
	FILE *pFile2;

	int sucess = 0;
	pFile = fopen(path, "r");
	pFile2 = fopen("Pagos_LastID.txt", "w");
	if (pFile != NULL) {
		if(parser_ObjectFromTextPago(pFile, this)){
			fclose(pFile);
			sucess = 1;
		}
		else{
			printf("    ERROR: No se pudo parsear Pagos.\n");
		}

	}else{
		printf("    ERROR: El archivo es NULL");
	}

	if (controller_saveAsTextMaxID(pFile2, "Pagos_LastID.txt", this,PAGO)) {
		fclose(pFile2);
	}

	return sucess;
}

int controller_loadFromTextClientes(char *path, LinkedList *this) {
	FILE *pFile; // para leer los objetos
	FILE *pFile2;

	int sucess = 0;
	pFile = fopen(path, "r");
	pFile2 = fopen("Clientes_LastID.txt", "w");
	if (pFile != NULL) {
		if(parser_ObjectFromTextCliente(pFile, this)){
			fclose(pFile);
			sucess = 1;
		}
		else{
			printf("    ERROR: No se pudo parsear Clientes.\n");
		}

	}else{
		printf("    ERROR: El archivo es NULL");
	}

	if (controller_saveAsTextMaxID(pFile2, "Clientes_LastID.txt", this, CUSTOMER)) {
		fclose(pFile2);
	}

	return sucess;
}

int controller_loadFromTextCuentas(char *path, LinkedList *this) {
	FILE *pFile; // para leer los objetos

	int sucess = 0;
	pFile = fopen(path, "r");
	if (pFile != NULL) {
		if(parser_ObjectFromTextCuenta(pFile, this)){
			fclose(pFile);
			sucess = 1;
		}
		else{
			printf("    ERROR: No se pudo parsear Cuentas.\n");
		}

	}else{
		printf("    ERROR: El archivo es NULL");
	}

	return sucess;
}

int controller_ListObjectRemitos(LinkedList *this) {
	Remitos *pObject;
	int sucess = 0;
	int id;
	int idCliente;
	float monto;
	char date[128];
	char cliente[128];

	if (this == NULL) {
		printf("\n    No se puede listar objetos ya que la lista es NULL.\n");
	} else {
		printf("   ______________________________________________________________\n"
		"      Fecha   ID_Remito      Cliente     ID_Cliente  Monto_Remito\n"
		"   ______________________________________________________________\n");
		sucess = 1;

		for (int i = 0; i < ll_len(this); i++) {
			pObject = ll_get(this, i);
			Entity_Remitos_getDate(pObject, date);
			Entity_Remitos_getID(pObject, &id);
			Entity_Remitos_getCliente(pObject, cliente);
			Entity_Remitos_getIdCliente(pObject, &idCliente);
			Entity_Remitos_getMontoRemito(pObject, &monto);
			printf("   [%10s] [%3d]      [%10s]     [%02d]     [$%8.2f]\n", date, id, cliente, idCliente, monto);
		}
	}
	return sucess;
}


int controller_ListObjectPagos(LinkedList *this) {
	Pagos *pObject;
	int sucess = 0;
	int id;
	int idCliente;
	float monto;
	char date[128];
	char cliente[128];

	if (this == NULL) {
		printf("\n    No se puede listar objetos ya que la lista es NULL.\n");
	} else {
		printf("   ______________________________________________________________\n"
		"      Fecha    ID_Pago        Cliente    ID_Cliente   Monto_Pago\n"
		"   ______________________________________________________________\n");
		sucess = 1;

		for (int i = 0; i < ll_len(this); i++) {
			pObject = ll_get(this, i);
			Entity_Pagos_getDate(pObject, date);
			Entity_Pagos_getID(pObject, &id);
			Entity_Pagos_getCliente(pObject, cliente);
			Entity_Pagos_getIdCliente(pObject, &idCliente);
			Entity_Pagos_getMontoPago(pObject, &monto);
			printf("   [%10s] [%3d]      [%10s]     [%02d]     [$%8.2f]\n", date, id, cliente, idCliente, monto);
		}
	}
	return sucess;
}

int controller_ListObjectClientes(LinkedList *this) {
	eCliente *pObject;
	int sucess = 0;
	int id;
	int idCuenta;
	int numeroDireccion;

	char calle[128];
	char telefono[128];
	char localidad[128];
	char razonSocial[128];
	char nombreDuenho[128];

	if (this == NULL) {
		printf("\n    No se puede listar objetos ya que la lista es NULL.\n");
	} else {
		printf("   _________________________________________________________________________________\n"
				"    ID   RazonSocia      Contacto    Telefono    Localidad      Calle     Altura Cuenta\n"
				"   _________________________________________________________________________________\n");
		sucess = 1;

		for (int i = 0; i < ll_len(this); i++) {
			pObject = ll_get(this, i);
			//poner getters
			Entity_Customer_getID(pObject, &id);
			Entity_Customer_getRazonSocial(pObject, razonSocial);
			Entity_Customer_getDuenho(pObject, nombreDuenho);
			Entity_Customer_getLocalidad(pObject, localidad);
			Entity_Customer_getCalle(pObject, calle);
			Entity_Customer_getTelefono(pObject, telefono);
			Entity_Customer_getNumeroDireccion(pObject, &numeroDireccion);
			Entity_Customer_getIdCuenta(pObject, &idCuenta);
			printf("   [%2d] [%-10s] [%-10s] [%11s] [%-10s] [%-10s] [%4d]  [%2d]\n",
			id, razonSocial, nombreDuenho, telefono, localidad, calle, numeroDireccion, idCuenta);
		}
	}
	return sucess;
}

/**
 * @brief  Obtain the ID_Customer of the entity remito.
 * @param  pElement entity.
 * @return return the id.
 */
static int obtainIDRemito(void* pElement){
	int idCustomer = -1;
	Remitos* an_Object;
	if(pElement!=NULL){
		an_Object = (Remitos*)pElement;
		if(an_Object!=NULL){
			Entity_Remitos_getIdCliente(an_Object, &idCustomer);
		}
	}
	return idCustomer;
}

/**
 * @brief  Obtain the ID_Customer of the entity payments.
 * @param  pElement entity.
 * @return return the id.
 */
static int obtainIDPago(void* pElement){
	int idCustomer = -1;
	Pagos *an_Object;
	if(pElement!=NULL){
		an_Object = (Pagos*)pElement;
		if(an_Object!=NULL){
			Entity_Pagos_getIdCliente(an_Object, &idCustomer);
		}
	}
	return idCustomer;
}

/**
 * @brief  travel across the remitos and payments and upgrade the fields in accounts.
 * @param  this list of accounts.
 * @param  thisRemitos list of remitos.
 * @param  thisPagos list of payments.
 * @return 1 for success, 0 for error.
 * @author FacuFalcone.
 */
static int controller_UpgradeAccountsStatus(LinkedList *this, LinkedList *thisRemitos, LinkedList *thisPagos){
	Accounts *pAccount;
	int success = 0;
	int accountLenght;
	int idAccount;
	float sumaDebe = 0;
	float sumaHaber = 0;
	float deudaTotal = 0;

	if(this != NULL && thisRemitos != NULL && thisPagos != NULL){
		accountLenght = ll_len(this);
		for (int a = 0; a<accountLenght;a++){
			pAccount = ll_get(this, a);
			if(pAccount != NULL){
				Entity_Account_getIdCliente(pAccount, &idAccount); //Agarro el id de cliente
				sumaDebe = ll_compareAndcount(REMITO, thisRemitos, idAccount, obtainIDRemito);
				sumaHaber = ll_compareAndcount(PAGO, thisPagos, idAccount, obtainIDPago);
				deudaTotal = (sumaDebe - sumaHaber);
				Entity_Account_setDebe(pAccount, sumaDebe);
				Entity_Account_setHaber(pAccount, sumaHaber);
				Entity_Account_setDeudaActual(pAccount, (deudaTotal));
				success = 1;
			}
		}
	}

	return success;
}

int controller_ListObjectCuentas(LinkedList *this, LinkedList *thisCustomer, LinkedList *thisRemitos, LinkedList *thisPagos) {
	Accounts *pObject;

	int sucess = 0;
	// Seccion Cuentas
	int id;
	int idCliente;
	char cliente[128];
	float debe;
	float haber;
	float deuda;

	if (this == NULL) {
		printf("\n    No se puede listar objetos ya que la lista es NULL.\n");
	} else {

		printf("   __________________________________________________________________\n"
				"    ID ID_Cliente    Cliente       Debe       Haber      Adeudado \n"
				"   ___________________________________________________________________\n");
		sucess = 1;
		if(controller_UpgradeAccountsStatus(this, thisRemitos, thisPagos)){
		// Recorro las cuentas
			for (int i = 0; i < ll_len(this); i++) {
				pObject = ll_get(this, i);

				if (pObject!=NULL){

					Entity_Account_getID(pObject, &id);
					Entity_Account_getIdCliente(pObject, &idCliente);
					Entity_Account_getCliente(pObject, cliente);
					Entity_Account_getDebe(pObject, &debe);
					Entity_Account_getHaber(pObject, &haber);
					Entity_Account_getDeuda(pObject, &deuda);
					printf("   [%02d]   [%02d]    [%-10s] [$%8.2f] [$%8.2f] [$%8.2f]\n", id, idCliente, cliente, debe, haber, deuda);

				}else{
					printf("    [ERROR] Objeto de cuentas es NULL.\n");
				}
			}
		}
	}
	return sucess;
}

//-----------------------------------------------------------------------------

/**
 * @brief  Save in text all the fields of the entity.
 * @param  pFile file to be saved the data.
 * @param  this list to be saved.
 * @return 1 for success, 0 for error.
 */
static int saveAsTextCustomer(FILE *pFile, LinkedList *this) {
	eCliente *pObject; //entidad para guardar como texto

	int sucess = 0;
	int len_LL;
	int idCliente;
	int idCuenta;
	int flagHeader = 1;
	int numeroDireccion;

	char calle[128];
	char contacto[128];
	char telefono[128];
	char localidad[128];
	char nombreCliente[128];

	if (pFile != NULL && this != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(this); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			pObject = ll_get(this, i);
			//getters aca
			Entity_Customer_getID(pObject, &idCliente);
			Entity_Customer_getRazonSocial(pObject, nombreCliente);
			Entity_Customer_getDuenho(pObject, contacto);
			Entity_Customer_getTelefono(pObject, telefono);
			Entity_Customer_getLocalidad(pObject, localidad);
			Entity_Customer_getCalle(pObject, calle);
			Entity_Customer_getNumeroDireccion(pObject, &numeroDireccion);
			Entity_Customer_getIdCuenta(pObject, &idCuenta);
			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s,%s,%s,%s\n",	"id_cliente", "RazonSocial", "Contacto", "Telefono", "Localidad", "Calle","Altura","idCuenta");
				flagHeader = 0;
			}
			fprintf(pFile, "%d,%s,%s,%s,%s,%s,%d,%d\n", idCliente, nombreCliente,contacto, telefono, localidad, calle, numeroDireccion, idCuenta); //escribo los datos de cada caballero en el archivo.
			sucess = 1;
		}
	}
	else{
		printf("    ERROR: El archivo o el array son NULL.\n");
	}

	return sucess;
}

int controller_saveAsTextCustomer(char *path, LinkedList *this) {
	int sucess = 0;
	FILE *pFile = fopen(path, "w"); // abro el archivo

	if (pFile != NULL && saveAsTextCustomer(pFile, this)) { //si el archivo no es null y pude escribir, retorno 1
		sucess = 1;
	}
	fclose(pFile); // cierro el archivo.
	ll_clear(this); //vacio el array
	return sucess;
}

//-----------------------------------------------------------------------------

/**
 * @brief  Save in text all the fields of the entity.
 * @param  pFile file to be saved the data.
 * @param  this list to be saved.
 * @return 1 for success, 0 for error.
 */
static int saveAsTextAccount(FILE *pFile, LinkedList *this) {
	Accounts *pObject; //entidad para guardar como texto

	int sucess = 0;
	int len_LL;
	int idCuenta;
	int idCliente;
	int flagHeader = 1;

	float debe;
	float haber;
	float deudaTotal;

	char razonSocial[128];

	if (pFile != NULL && this != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(this); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			pObject = ll_get(this, i);
			//getters aca
			Entity_Account_getID(pObject, &idCuenta);
			Entity_Account_getCliente(pObject, razonSocial);
			Entity_Account_getIdCliente(pObject, &idCliente);
			Entity_Account_getDebe(pObject, &debe);
			Entity_Account_getHaber(pObject, &haber);
			Entity_Account_getDeuda(pObject, &deudaTotal);

			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", "ID_Cuenta", "ID_Cliente", "RazonSocial", "DEBE", "HABER", "DEUDA");
				flagHeader = 0;
			}
			fprintf(pFile, "%d,%d,%s,%8.2f,%8.2f,%8.2f\n",
			idCuenta, idCliente, razonSocial, debe, haber, deudaTotal); //escribo los datos de cada caballero en el archivo.
			sucess = 1;
		}
	}
	else{
		printf("    ERROR: El archivo o el array son NULL.\n");
	}
	return sucess;
}

int controller_saveAsTextAccount(char *path, LinkedList *this) {
	int sucess = 0;
	FILE *pFile = fopen(path, "w"); // abro el archivo

	if (pFile != NULL && saveAsTextAccount(pFile, this)) { //si el archivo no es null y pude escribir, retorno 1
		sucess = 1;
	}
	fclose(pFile); // cierro el archivo.
	ll_clear(this); //vacio el array
	return sucess;
}


//-----------------------------------------------------------------------------

/**
 * @brief  Save in text all the fields of the entity.
 * @param  pFile file to be saved the data.
 * @param  this list to be saved.
 * @return 1 for success, 0 for error.
 */
static int saveAsTextRemito(FILE *pFile, LinkedList *this) {
	Remitos *pObject; //entidad para guardar como texto

	int sucess = 0;
	int len_LL;
	int idRemito;
	int idCliente;
	int flagHeader = 1;

	float monto;

	char cliente[128];
	char date[128];

	if (pFile != NULL && this != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(this); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			pObject = ll_get(this, i);
			//getters aca
			Entity_Remitos_getDate(pObject, date);
			Entity_Remitos_getID(pObject, &idRemito);
			Entity_Remitos_getCliente(pObject, cliente);
			Entity_Remitos_getIdCliente(pObject, &idCliente);
			Entity_Remitos_getMontoRemito(pObject, &monto);
			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s\n","Fecha", "ID_Remito", "RazonSocial", "ID_Cliente", "Monto");
				flagHeader = 0;
			}
			fprintf(pFile, "%s,%d,%s,%d,%8.2f\n", date,idRemito, cliente,idCliente, monto); //escribo los datos de cada caballero en el archivo.
			sucess = 1;
		}
	}
	else{
		printf("    ERROR: El archivo o el array son NULL.\n");
	}
	return sucess;
}

int controller_saveAsTextRemito(char *path, LinkedList *this) {
	int sucess = 0;
	FILE *pFile = fopen(path, "w"); // abro el archivo

	if (pFile != NULL && saveAsTextRemito(pFile, this)) { //si el archivo no es null y pude escribir, retorno 1
		sucess = 1;
	}
	fclose(pFile); // cierro el archivo.
	ll_clear(this); //vacio el array
	return sucess;
}

//-----------------------------------------------------------------------------

/**
 * @brief  Save in text all the fields of the entity.
 * @param  pFile file to be saved the data.
 * @param  this list to be saved.
 * @return 1 for success, 0 for error.
 */
static int saveAsTextPago(FILE *pFile, LinkedList *this) {
	Pagos *pObject; //entidad para guardar como texto

	int sucess = 0;
	int idPago;
	int len_LL;
	int idCliente;
	int flagHeader = 1;

	float monto;

	char date[128];
	char cliente[128];

	if (pFile != NULL && this != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(this); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			pObject = ll_get(this, i);
			//getters aca
			Entity_Pagos_getDate(pObject, date);
			Entity_Pagos_getID(pObject, &idPago);
			Entity_Pagos_getCliente(pObject, cliente);
			Entity_Pagos_getIdCliente(pObject, &idCliente);
			Entity_Pagos_getMontoPago(pObject, &monto);
			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s\n","Fecha", "ID_Remito", "RazonSocial", "ID_Cliente", "Monto");
				flagHeader = 0;
			}
			fprintf(pFile, "%s,%d,%s,%d,%8.2f\n", date,idPago, cliente,idCliente, monto); //escribo los datos de cada caballero en el archivo.
			sucess = 1;
		}
	}
	else{
		printf("    ERROR: El archivo o el array son NULL.\n");
	}
	return sucess;
}

int controller_saveAsTextPago(char *path, LinkedList *this) {
	int sucess = 0;
	FILE *pFile = fopen(path, "w"); // abro el archivo

	if (pFile != NULL && saveAsTextPago(pFile, this)) { //si el archivo no es null y pude escribir, retorno 1
		sucess = 1;
	}
	fclose(pFile); // cierro el archivo.
	ll_clear(this); //vacio el array
	return sucess;
}
