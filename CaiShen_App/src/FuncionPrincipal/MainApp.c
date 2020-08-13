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

#include <ctype.h>
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#include "../LinkedList.h"
#include "../Validate/caidevValidate.h"
#include "../MenuPrincipal/MainMenu.h"
#include "../Read_From_Directory/ReadFiles.h"
#include "../Controller/registerController/registerController.h"
#include "../Controller/terminateController/terminateController.h"
#include "../Controller/Controller.h"


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
			"    [Message]: Menu de ABM\n"
			"    _______________________________________________________________\n"
			"    [Message]: Confirma Salir? Y/N: ");
	__fpurge(stdin); //linux
	getString(confirm, sizeof(*confirm));
	*confirm = tolower(*confirm);
	if (*confirm == 'y') {
		printf("    __________________________________________________________\n"
				"    [Message]: Gracias, Esperamos volverte a ver!\n");
		*answer = 'n';
		success = 1;
	}else if(*confirm == 'n'){
		success = -1; // usado para vovler al menu y no borrar nada.
	}else{
		printf("    [ERROR] Respuesta invalida, reintentelo.\n");
		__fpurge(stdin); //linux
	}
	return success;
}

int Control_De_Cuentas() {

	char confirm;
	char answer = 'y';
	char pathClientes[128] = "registro_Clientes.csv";
	char pathCuentas[128] = "registro_Cuentas.csv";
	char pathRemitos[128] = "registro_Remitos.csv";
	int valorSalida;

	LinkedList* Remitos= ll_newLinkedList();
	LinkedList* Clientes = ll_newLinkedList();
	LinkedList* Cuenta_Clientes = ll_newLinkedList();

	if(ll_isEmpty(Remitos)){ //chequeo que la lista no este vacia.
		printf("    [Message]: Lista Remitos inicializada con exito!\n");
		if(controller_loadFromTextRemitos(pathRemitos, Remitos)){
			printf("    [Message]: Datos Remitos Cargados con exito!\n");
		}
	}

	if(ll_isEmpty(Clientes)){ //chequeo que la lista no este vacia.
		printf("    [Message]: Lista Clientes inicializada con exito!\n");
		if(controller_loadFromTextClientes(pathClientes, Clientes)){
			printf("    [Message]: Datos Clientes Cargados con exito!\n");
		}
	}

	if(ll_isEmpty(Cuenta_Clientes)){ //chequeo que la lista no este vacia.
		printf("    [Message]: Lista Cuenta_Clientes inicializada con exito!\n");
		if(controller_loadFromTextCuentas(pathCuentas, Cuenta_Clientes)){
			printf("    [Message]: Lista Cuenta_Clientes inicializada con exito!\n"
			"    __________________________________________________________\n");
		}
	}


	do {
		switch (menu()) {
		case 0: /* Mostrar Archivos en directorio root */
			Read_Directory();
			break;
		case 1: /* CARGA CLIENTES */
			controller_addCliente(Clientes,Cuenta_Clientes);
			break;
			//***************************************************************************
		case 2: /* LISTAR CLIENTES */
			if(ll_isEmpty(Clientes)!=0){
				printf(" [ERROR] No hay Clientes cargados!\n");
			}else{
				controller_ListObjectClientes(Clientes);
			}
			break;
			//***************************************************************************
		case 3: /* MODIFICAR CLIENTE */
			break;
			//***************************************************************************
		case 4: /* BAJA CLIENTES */
			if(ll_isEmpty(Clientes)!=0){
				printf(" [ERROR] No hay Clientes cargados!\n");
			}else{
				if(controller_removeCliente(Clientes)){
					printf("    [SUCCESS] Cliente dado de baja con exito!\n");
				}
			}
			break;
			//***************************************************************************
		case 5: /* CARGAR REMITOS */
			if(ll_isEmpty(Clientes)!=0){
				printf(" [ERROR] No hay Clientes cargados!\n");
			}else{
				controller_addRemito(Remitos, Clientes);
			}
			break;
			//***************************************************************************
		case 6: /* LISTAR REMITOS */
			if(ll_isEmpty(Remitos)!=0){
				printf(" [ERROR] No hay Remitos cargados!\n");
			}else{
				controller_ListObjectRemitos(Remitos);
			}
			break;
			//***************************************************************************
		case 7: /* MODIFICAR REMITO */
			break;
		case 8: /* BAJA REMITOS */
			if(ll_isEmpty(Remitos)!=0){
				printf(" [ERROR] No hay Remitos cargados!\n");
			}else{
				if(controller_removeRemito(Remitos)){
					printf("    [SUCCESS] Ramito dado de baja con exito!\n");
				}
			}
			break;
			//***************************************************************************
		case 9: /* LISTAR CUENTAS */
			if(ll_isEmpty(Cuenta_Clientes)!=0){
				printf(" [ERROR] No hay Cuantas ni Clientes cargados!\n");
			}else{
				controller_ListObjectCuentas(Cuenta_Clientes,Clientes,Remitos);
			}
			break;
			//***************************************************************************
		case 10: /* GUARDAR CAMBIOS */
			break;
			//***************************************************************************
		case 11: /* VACIO */
			break;
			//***************************************************************************
		case 12: /* Salir */
			valorSalida = log_Out(&confirm, &answer);
			if(valorSalida==1){ //pregunto para salir y guardo en csv y bin.
				ll_deleteLinkedList(Clientes); // Limpio la lista de filtrados.
				ll_deleteLinkedList(Remitos); // Limpio la lista original.
				ll_deleteLinkedList(Cuenta_Clientes); // Limpio la lista de paises mas castigados.
				//loadOrWrite = 0;
			}else if(!valorSalida){
				__fpurge(stdin);
			}
			break;
			//***************************************************************************
		default:
			printf(	"    __________________________________________________________\n"
					"    [Message]: [ERROR 1101]: Opcion incorrecta, use [0-12].\n");
			break;
			//***************************************************************************
		}
		simulatePause();
		system("clear"); // linux
	} while (answer == 'y');

	return 0;
}
