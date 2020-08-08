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

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../../LinkedList.h"
#include "../../Validate/caidevValidate.h"

#include "../../Entity_Remitos/Entity_Remito.h"
#include "../../Entity_Clientes/Entity_Customers.h"
#include "../../Entity_Clientes/Getters_Customer/Getters.h"
#include "../../Entity_Clientes/Setters_Customer/Setters.h"
#include "../../Entity_Cuentas/Entity_Accounts.h"

#include "../../Entity_Remitos/Setters/Setters.h"
#include "../../Entity_Remitos/Getters/Getters.h"
#include "../../Entity_Cuentas/Setters_Account/Setters.h"

#include "../Controller.h"

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
 * @brief lee la ultima id del bin y la actualiza con la nueva.
 */
/*
void controllerAlta(){
	int id;
	obtainID(&id); //obtiene la proxima id
	printf("ID: %d",id); // la muestro por si acaso
	upgradeID(id); //actualizo con la nueva id que obtuve
}*/

// Searchers
int Entity_Customer_SearchForId(LinkedList *this, int id) {
    int retorno = -1;
    int idAux;
	eCliente *pCustomer;

	for (int index = 0; index < ll_len(this); index++) {
		pCustomer = ll_get(this, index);
		if (Entity_Customer_getID(pCustomer, &idAux) == 1 &&
           idAux == id){
            retorno = index;
        }
    }
    return retorno;
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

		//------------------- Pido Id de cliente para asociar al remito
		controller_ListObjectClientes(thisCustomer);

		getNumberInt(&customerId, " Seleccione un cliente: ", " Cliente incorrecto.\n", 1, (ultimoIdCliente-1), 5);

		//customerIndex = ll_indexOf(thisCustomer, &customerId);
		customerIndex = Entity_Customer_SearchForId(thisCustomer, customerId);
		pCliente = ll_get(thisCustomer,customerIndex);

		Entity_Customer_getRazonSocial(pCliente, customerName);

		printf("   [Mesage] Se agregara un remito para: %s\n",customerName);

		//------------------- Pido Monto del remito
		getNumberFloat(&remitoAmount, " Ingrese el monto del remito: ", " Monto incorrecto, no puede superar los 20k\n", 0, 20000, 5);

		if (pRemito != NULL) {

			Entity_Remitos_setDate(pRemito, date);
			Entity_Remitos_setID(pRemito, &ultimoIdRemito);
			Entity_Remitos_setCliente(pRemito, customerName);
			Entity_Remitos_setIdCliente(pRemito, customerId);
			Entity_Remitos_setMontoRemito(pRemito, remitoAmount);
			ll_add(this, pRemito);
			upgradeID(ultimoIdRemito,"Remitos_LastID.txt"); // guarda en el archivo ultimoIdRemito+1 en "ultimoIdRemito.txt"
			sucess = 1;
			printf("    [Mesage] Remito agregado con exito!\n");
		}else{
			printf("    [ERROR] Problemas al crear el remito!\n");
		}
	}
	return sucess;
}

int controller_addCliente(LinkedList *this, LinkedList *thisAccount){
	eCliente *pCliente;
	Accounts *pAccount;
	pCliente =Entity_newClientes();
	pAccount = Entity_newAccount();

	int sucess = 0;
	int ultimoIdCliente;
	int textLength = 128;

	//----- Para hacer el remito
	//int customerId;
	char customerName[128];
	char nombreDuenho[128];
	char localidad[128];
	char calle[128];
	char telefono[128];

	int numeroDireccion;

	if (this != NULL) {

		obtainID(&ultimoIdCliente,"Clientes_LastID.txt"); // Obtengo el ID al leerlo desde el archivo "ultimoIdCliente.txt" .
		printf("    [Message]: El alta se asignara con el ID: %d\n",ultimoIdCliente);

		//------------------- Pido datos de cliente

		getName(customerName, textLength, " Ingrese razon social sin espacios: ", " Razon social Erronea.\n", 5);
		uppercaselInitial(customerName);
		getName(nombreDuenho, textLength, " Ingrese nombre de contacto sin espacios: ", " Nombre incorrecto.\n", 5);
		uppercaselInitial(nombreDuenho);
		getName(localidad, textLength, " Ingrese localidad sin espacios: ", " Localidad incorrecta.\n", 7);
		uppercaselInitial(localidad);
		getName(calle, textLength, " Ingrese nombre de calle [sin espacios]: ", " Calle incorrecta.\n", 7);
		uppercaselInitial(calle);

		getNumberInt(&numeroDireccion, " Ingrese altura: ", " Incorrecto, excede el limite de 15k.\n", 0, 15000, 7);
		getPhoneNumber(telefono, 128, " Ingrese telefono de contacto [solo numeros]: ", " Telefono incorrecto.\n", 7);

		if (pCliente != NULL && pAccount != NULL) {
			Entity_Customer_setID(pCliente, &ultimoIdCliente);
			Entity_Customer_setRazonSocial(pCliente, customerName);
			Entity_Customer_setDuenho(pCliente, nombreDuenho);
			Entity_Customer_setLocalidad(pCliente, localidad);
			Entity_Customer_setCalle(pCliente, calle);
			Entity_Customer_setTelefono(pCliente, telefono);
			Entity_Customer_setNumeroDireccion(pCliente, numeroDireccion);
			Entity_Customer_setIdCuenta(pCliente, ultimoIdCliente);

			Entity_Account_setID(pAccount, &ultimoIdCliente);
			Entity_Account_setIDCliente(pAccount, &ultimoIdCliente);
			Entity_Account_setCliente(pAccount, customerName);
			Entity_Account_setDebe(pAccount, 0);
			Entity_Account_setHaber(pAccount, 0);
			Entity_Account_setDeudaActual(pAccount, 0);

			ll_add(thisAccount, pAccount);
			ll_add(this, pCliente);
			upgradeID(ultimoIdCliente, "Cuentas_LastID.txt");
			upgradeID(ultimoIdCliente,"Clientes_LastID.txt"); // guarda en el archivo ultimoIdCliente+1 en "ultimoIdCliente.txt"
			sucess = 1;
		}
	}
	return sucess;
}
