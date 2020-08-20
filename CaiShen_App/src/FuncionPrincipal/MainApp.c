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

#include <ctype.h>
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#include "../Controller/Controller.h"
#include "../Controller/registerController/registerController.h"
#include "../Controller/modifyController/modifyController.h"
#include "../Controller/terminateController/terminateController.h"
#include "../LinkedList.h"
#include "../MenuPrincipal/MainMenu.h"
#include "../Read_From_Directory/ReadFiles.h"
#include "../Validate/caidevValidate.h"


#define OPEN 1 // Para definir archivo abierto.
#define CLOSED 0 // Para definir archivo cerrado.

void simulatePause(){
	printf("    [Message]: Presione una tecla para continuar...\n");
	getchar();
	__fpurge(stdin);
}

void pFunctionLoadBinCsv(char* messageError1,char* messageError2,char* messageSuccess,int* flag,int flagValue,
		int NewflagValue,char*path,LinkedList* array,int(*pFunction)(char*,LinkedList*)){
	int flagForCompare = *flag; // traigo el valor del flag para comparar despues.
	if(flagForCompare==flagValue){ // si es 1 es xq esta abierto
		//printf("\n    [ERROR 0001]: Archivo abierto/cerrado, primero guardelo/carguelo.\n");
		printf("\n%s\n",messageError1);
	}else{
		if (!pFunction(path,array)) {
			//printf("\n    [ERROR 1010]: Imposible abrir/guardar archivo.\n\n");
			printf("\n%s\n",messageError2);
		} else {
			//printf("\n    Archivo abierto/guardado con exito.\n");
			printf("\n%s\n",messageSuccess);
			*flag = NewflagValue; // Actualizo el flag a 1 si lo abri y a 0 si lo guarde.
		}
	}
}

void pFunction(char* messageError1,char* messageError2,char* messageSuccess,int* flag,int flagValue
		,LinkedList* array,int(*pFunction)(LinkedList*)){
	int flagForCompare = *flag;
	if(flagForCompare==flagValue){
		printf("\n%s\n",messageError1);
	}else{
		if (!pFunction(array)) {
			printf("\n%s\n",messageError2);
		} else {
			printf("\n%s\n",messageSuccess);
			//*flag =NewflagValue;
		}
	}
}

int log_Out(char *confirm, char *answer) {
	int success = 0;
	printf(
			"    _______________________________________________________________\n"
			"    [Message]: Gestor De Cuentas CAISHEN.\n"
			"    _______________________________________________________________\n"
			"    [Message]: Confirma Salir? S/N: ");
	__fpurge(stdin); //linux
	getString(confirm, sizeof(*confirm));
	*confirm = tolower(*confirm);
	if (*confirm == 's') {
		printf("    __________________________________________________________\n"
				"    [Message]: Gracias, Esperamos volverte a ver!\n");
		*answer = 'n';
		success = 1;
	}else if(*confirm == 'n'){
		success = -1; // usado para volver al menu y no borrar nada.
	}else{
		printf("    [ERROR] Respuesta invalida, reintentelo.\n");
		__fpurge(stdin); //linux
	}
	return success;
}

int gestionClientes(LinkedList *this, LinkedList *thisAccount){
	int success = 0;
	char respuesta = 's';
	do{
		switch(menuClientes()){
			case 1:
				controller_addCliente(this,thisAccount);
				break;
				//***************************************************************************
			case 2: /* LISTAR CLIENTES */
				if(ll_isEmpty(this)){
					printf("    [ERROR] No hay Clientes cargados!\n");
				}else{
					controller_ListObjectClientes(this);
				}
				break;
				//***************************************************************************
			case 3: /* MODIFICAR CLIENTE */
				if(ll_isEmpty(this)){
					printf("    [ERROR] No hay Clientes cargados!\n");
				}else{
					controller_editCustomer(this);
				}
				break;
				//***************************************************************************
			case 4: /* BAJA CLIENTES */
				if(ll_isEmpty(this)){
					printf("    [ERROR] No hay Clientes cargados!\n");
				}else{
					if(controller_removeCliente(this)){
						printf("    [SUCCESS] Cliente dado de baja con exito!\n");
					}
				}
				break;
				//***************************************************************************
			case 5: /* SALIR */
				respuesta = 'n';
				break;
			default:
				break;
		}
		simulatePause();
		system("clear"); // linux
	}while(respuesta == 's');
	return success;
}

int gestionRemitos(LinkedList *this, LinkedList *thisCustomer){
	int success = 0;
	char respuesta = 's';
	do{
		switch(menuRemitos()){
		case 1: /* CARGAR REMITOS */
			if(ll_isEmpty(thisCustomer)){
				printf("    [ERROR] No hay Clientes cargados!\n");
			}else{
				controller_addRemito(this, thisCustomer);
			}
			break;
			//***************************************************************************
		case 2: /* LISTAR REMITOS */
			if(ll_isEmpty(this)){
				printf("    [ERROR] No hay Remitos cargados!\n");
			}else{
				controller_ListObjectRemitos(this);
			}
			break;
			//***************************************************************************
		case 3: /* MODIFICAR REMITO */
			if(ll_isEmpty(this)){
				printf("    [ERROR] No hay Remitos cargados!\n");
			}else{
				controller_editRemitos(this);
			}
			break;
		case 4: /* BAJA REMITOS */
			if(ll_isEmpty(this)){
				printf("    [ERROR] No hay Remitos cargados!\n");
			}else{
				if(controller_removeRemito(this)){
					printf("    [SUCCESS] Ramito dado de baja con exito!\n");
				}
			}
			break;
			//***************************************************************************
			case 5: /* SALIR */
				respuesta = 'n';
				break;
			default:
				break;
		}
		simulatePause();
		system("clear"); // linux
	}while(respuesta == 's');
	return success;
}

int gestionPagos(LinkedList *this, LinkedList *thisCustomer){
	int success = 0;
	char respuesta = 's';
	do{
		switch(menuPagos()){
		case 1: /* CARGAR PAGOS */
			if(ll_isEmpty(thisCustomer)){
				printf(" [ERROR] No hay Clientes cargados!\n");
			}else{
				controller_addPago(this, thisCustomer);
			}
			break;
			//***************************************************************************
		case 2: /* LISTAR PAGOS */
			if(ll_isEmpty(this)){
				printf(" [ERROR] No hay Pagos cargados!\n");
			}else{
				controller_ListObjectPagos(this);
			}
			break;
			//***************************************************************************
		case 3: /* MODIFICAR PAGOS */
			if(ll_isEmpty(this)){
				printf("    [ERROR] No hay Pagos cargados!\n");
			}else{
				controller_editPagos(this);
			}
			break;
		case 4: /* BAJA PAGOS */
			if(ll_isEmpty(this)){
				printf(" [ERROR] No hay Pagos cargados!\n");
			}else{
				if(controller_removePago(this)){
					printf("    [SUCCESS] Pagos dado de baja con exito!\n");
				}
			}
			break;
			//***************************************************************************
			case 5: /* SALIR */
				respuesta = 'n';
				break;
			default:
				break;
		}
		simulatePause();
		system("clear"); // linux
	}while(respuesta == 's');
	return success;
}

static int initLists(LinkedList *Rem, LinkedList *payments, LinkedList *customers, LinkedList *accounts,
						char *pathRem, char *pathPay, char *pathCustomer, char *pathAccounts){
	int success = 0;
	int remOK = 0;
	int payOK = 0;
	int customerOK = 0;
	int accountOK = 0;
	//---------- Control de inicializaciones.
	if(ll_isEmpty(Rem)){ //chequeo que la lista no este vacia.
		//printf("    [Message]: Lista Remitos inicializada con exito!\n");
		if(controller_loadFromTextRemitos(pathRem, Rem)){
			//printf("    [Message]: Datos Remitos Cargados con exito!\n");
			remOK = 1;
		}
	}

	if(ll_isEmpty(payments)){ //chequeo que la lista no este vacia.
		//printf("    [Message]: Lista Pagos inicializada con exito!\n");
		if(controller_loadFromTextPagos(pathPay, payments)){
			//printf("    [Message]: Datos Pagos Cargados con exito!\n");
			payOK = 1;
		}
	}

	if(ll_isEmpty(customers)){ //chequeo que la lista no este vacia.
		//printf("    [Message]: Lista Clientes inicializada con exito!\n");
		if(controller_loadFromTextClientes(pathCustomer, customers)){
			//printf("    [Message]: Datos Clientes Cargados con exito!\n");
			customerOK = 1;
		}
	}

	if(ll_isEmpty(accounts)){ //chequeo que la lista no este vacia.
		//printf("    [Message]: Lista Cuenta_Clientes inicializada con exito!\n");
		if(controller_loadFromTextCuentas(pathAccounts, accounts)){
			//printf("    [Message]: Datos Cuentas Cargados con exito!\n"
			//"    __________________________________________________________\n");
			accountOK = 1;
		}
	}

	if(remOK && accountOK && customerOK && payOK){
		success = 1;
		printf("    [SUCCESS]: Listas y Datos Cargados con exito!\n"
		"    __________________________________________________________\n");
	}

	return success;
}

int ACCOUNT_MANAGER_CAISHEN() {

	char confirm;
	char answer = 's';
	char guardarAntesDeSalir = 's';
	//--------------- PATHS
	char pathClientes[128] = "Docs/registro_Clientes.csv";
	char pathCuentas[128] = "Docs/registro_Cuentas.csv";
	char pathRemitos[128] = "Docs/registro_Remitos.csv";
	char pathPagos[128] = "Docs/registro_Pagos.csv";
	char pathMaxIDRemitos[128] = "Remitos_LastID.txt";
	char pathMaxIDClientes[128] = "Clientes_LastID.txt";
	char pathMaxIDCuentas_Clientes[128] = "Cuentas_LastID.txt";
	char pathMaxIdPagos[128] = "Pagos_LastID.txt";

	int valorSalida;

	LinkedList* Remitos= ll_newLinkedList();
	LinkedList* Clientes = ll_newLinkedList();
	LinkedList* Cuenta_Clientes = ll_newLinkedList();
	LinkedList* Pagos = ll_newLinkedList();

	initLists(Remitos, Pagos, Clientes, Cuenta_Clientes,pathRemitos, pathPagos, pathClientes, pathCuentas);

	do {
		switch (menu()) {
		case 0: /* Mostrar Archivos en directorio root */
			Read_Directory();
			//***************************************************************************
			break;
		case 1: /* CLIENTES */
			gestionClientes(Clientes, Cuenta_Clientes);
			break;
			//***************************************************************************
		case 2: /* REMITOS */
			gestionRemitos(Remitos, Clientes);
			break;
			//***************************************************************************
		case 3: /* PAGOS */
			gestionPagos(Pagos, Clientes);
			break;
			//***************************************************************************
		case 4: /* CUENTAS */
			if(ll_isEmpty(Cuenta_Clientes)!=0){
				printf(" [ERROR] No hay Cuentas ni Clientes cargados!\n");
			}else{
				controller_ListObjectCuentas(Cuenta_Clientes,Clientes,Remitos,Pagos);
			}
			break;
			//***************************************************************************
		case 5: /* Salir */
			printf("    [WARNING] Desea Guardar cambios antes de salir [s/n]?: ");
			getString(&guardarAntesDeSalir, sizeof(guardarAntesDeSalir));
			if(guardarAntesDeSalir=='s'){
				if(controller_saveAsTextAccount(pathCuentas, Cuenta_Clientes) &&
				controller_saveAsTextCustomer(pathClientes, Clientes) &&
				controller_saveAsTextRemito(pathRemitos, Remitos)){
					printf("    [SUCESS] Cambios guardados con exito!.\n\n");
					valorSalida = log_Out(&confirm, &answer);
					if(valorSalida==1){ //pregunto para salir y guardo en csv y bin.
						ll_deleteLinkedList(Clientes); // Limpio la lista de filtrados.
						ll_deleteLinkedList(Remitos); // Limpio la lista original.
						ll_deleteLinkedList(Cuenta_Clientes); // Limpio la lista Cuentas.
						ll_deleteLinkedList(Pagos); // Limpio la lista Pagos
						remove(pathMaxIDRemitos); // Borra archivo auxiliar de ids
						remove(pathMaxIDClientes); // Borra archivo auxiliar de ids
						remove(pathMaxIDCuentas_Clientes); // Borra archivo auxiliar de ids
						remove(pathMaxIdPagos); // Borra archivo auxiliar de ids
					}else if(!valorSalida){
						__fpurge(stdin);
					}
				}
			}
			break;
			//***************************************************************************
		default:
			printf(	"    __________________________________________________________\n"
					"    [ERROR]: Opcion incorrecta, use [0-5].\n");
			break;
			//***************************************************************************
		}
		simulatePause();
		system("clear"); // linux
	} while (answer == 'y');

	return 1;
}
