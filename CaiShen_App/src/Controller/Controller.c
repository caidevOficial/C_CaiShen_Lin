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

#define CUSTOMER 0
#define REMITO 1

#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../LinkedList.h"
#include "../Parser/parserRemito.h"
#include "../Parser/parserCustomer.h"
#include "../Parser/parserAccount.h"

#include "../Entity_Remitos/Entity_Remito.h"
#include "../Entity_Remitos/Getters/Getters.h"

#include "../Entity_Clientes/Entity_Customers.h"
#include "../Entity_Clientes/Getters_Customer/Getters.h"

#include "../Entity_Cuentas/Entity_Accounts.h"
#include "../Entity_Cuentas/Getters_Account/Getters.h"
#include "saveMaxID_toText/saveToText_maxID.h"


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
			printf("    ERROR: No se pudo parsear Texto.");
		}

	}else{
		printf("    ERROR: El archivo es NULL");
	}

	if (controller_saveAsTextMaxID(pFile2, "Remitos_LastID.txt", this,REMITO)) {
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
			printf("    ERROR: No se pudo parsear Texto.");
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
			printf("    ERROR: No se pudo parsear Texto.");
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
	char cliente[128];
	char date[128];

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

int controller_ListObjectClientes(LinkedList *this) {
	eCliente *pObject;
	int sucess = 0;

	char razonSocial[128];
	char nombreDuenho[128];
	char localidad[128];
	char calle[128];
	char telefono[128];

	int id;
	int numeroDireccion;
	int idCuenta;

	if (this == NULL) {
		printf("\n    No se puede listar objetos ya que la lista es NULL.\n");
	} else {
		printf("   _________________________________________________________________________________\n"
				"    ID  RazonSocia   Contacto   Telefono      Localidad     Calle    Altura Cuenta\n"
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
			printf("   [%2d] [%8s]  [%8s] [%10s] [%8s] [%8s] [%4d]  [%2d]\n",
			id, razonSocial, nombreDuenho, telefono, localidad, calle, numeroDireccion, idCuenta);
		}
	}
	return sucess;
}

int controller_ListObjectCuentas(LinkedList *this, LinkedList *thisCustomer, LinkedList *thisRemitos) {
	Accounts *pObject;
	Remitos * pRemito;

	int sucess = 0;

	// Seccion Cuentas
	int id;
	int idCliente;
	int idClienteCuenta;
	char cliente[128];
	float debe;
	float haber;
	float deuda;

	// Seccion Remitos
	int idClienteRemito;
	float montoRemito;

	if (this == NULL) {
		printf("\n    No se puede listar objetos ya que la lista es NULL.\n");
	} else {
		printf("   __________________________________________________________________\n"
				"    ID ID_Cliente    Cliente       Debe       Haber      Adeudado \n"
				"   ___________________________________________________________________\n");
		sucess = 1;

		// ARREGLAR ERROR LOOP INFINITO
		// Recorro las cuentas
		for (int i = 0; i < ll_len(this); i++) {
			pObject = ll_get(this, i);

			if (pObject!=NULL){
				Entity_Account_getIdCliente(pObject, &idClienteCuenta);
				// Recorro los remitos comparando iDCliente

				for(int r = 0;i<ll_len(thisRemitos);r++){
					pRemito = ll_get(thisRemitos, r);

					if(pRemito!=NULL){
						Entity_Remitos_getIdCliente(pRemito, &idClienteRemito);

						// Si son iguales, Sumo el Debe.
						if(idClienteRemito==idClienteCuenta){
							Entity_Remitos_getMontoRemito(pRemito, &debe);
							montoRemito += ll_count(thisRemitos, sumaDebe);
						}
					}else{
						printf("    [ERROR] Objeto de Remito es NULL.\n");
					}
				}

				Entity_Account_getID(pObject, &id);
				Entity_Account_getIdCliente(pObject, &idCliente);
				Entity_Account_getCliente(pObject, cliente);
				//Entity_Account_getDebe(pObject, &montoRemito);
				Entity_Account_getHaber(pObject, &haber);
				Entity_Account_getDeuda(pObject, &deuda);
				printf("   [%02d]   [%02d]    [%-10s] [$%8.2f] [$%8.2f] [$%8.2f]\n", id, idCliente, cliente, montoRemito, haber, deuda);

			}else{
				printf("    [ERROR] Objeto de cuentas es NULL.\n");
			}
		}
	}
	return sucess;
}

//-----------------------------------------------------------------------------

int saveAsTextCustomer(FILE *pFile, LinkedList *this) {
	eCliente *pObject; //entidad para guardar como texto

	char nombreCliente[128];
	char telefono[128];
	char calle[128];
	char contacto[128];
	char localidad[128];

	int idCliente;
	int numeroDireccion;
	int idCuenta;
	int len_LL;
	int sucess = 0;
	int flagHeader = 1;

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

int saveAsTextAccount(FILE *pFile, LinkedList *this) {
	Accounts *pObject; //entidad para guardar como texto

	char razonSocial[128];

	int idCuenta;
	int idCliente;

	float debe;
	float haber;
	float deudaTotal;

	int len_LL;
	int sucess = 0;
	int flagHeader = 1;

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
				fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", "ID_Cuenta", "RazonSocial", "ID_Cliente", "DEBE", "HABER", "DEUDA");
				flagHeader = 0;
			}
			fprintf(pFile, "%d,%s,%d,%f,%f,%f\n",
			idCuenta, razonSocial, idCliente, debe, haber, deudaTotal); //escribo los datos de cada caballero en el archivo.
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
/*
int saveAsTextRemito(FILE *pFile, LinkedList *this) {
	Remitos *pObject; //entidad para guardar como texto

	char cliente[128];

	int idRemito;
	int idCliente;
	int dia;
	int mes;
	int anho;
	float monto;

	int len_LL;
	int sucess = 0;
	int flagHeader = 1;

	if (pFile != NULL && this != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(this); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			pObject = ll_get(this, i);
			//getters aca
			Entity_Remitos_getFecha(pObject, &dia, &mes, &anho);
			Entity_Remitos_getID(pObject, &idRemito);
			Entity_Remitos_getCliente(pObject, cliente);
			Entity_Remitos_getIdCliente(pObject, &idCliente);
			Entity_Remitos_getMontoRemito(pObject, &monto);
			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s\n","Fecha", "ID_Remito", "RazonSocial", "ID_Cliente", "Monto");
				flagHeader = 0;
			}
			fprintf(pFile, "%d/%d/%d,%d,%s,%d,%f\n", dia,mes,anho,idRemito, cliente,idCliente, monto); //escribo los datos de cada caballero en el archivo.
			sucess = 1;
		}
	}
	else{
		printf("    ERROR: El archivo o el array son NULL.\n");
	}
	return sucess;
}
*/

int saveAsTextRemito(FILE *pFile, LinkedList *this) {
	Remitos *pObject; //entidad para guardar como texto

	char cliente[128];
	char date[128];

	int idRemito;
	int idCliente;
	float monto;

	int len_LL;
	int sucess = 0;
	int flagHeader = 1;

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
			fprintf(pFile, "%s,%d,%s,%d,%f\n", date,idRemito, cliente,idCliente, monto); //escribo los datos de cada caballero en el archivo.
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
