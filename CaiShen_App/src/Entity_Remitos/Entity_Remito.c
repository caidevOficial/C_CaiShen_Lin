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

#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>

#include "Entity_Remito.h"
#include "Setters/Setters.h"
#include "Getters/Getters.h"

// Constructors
Remitos* Entity_newRemito() {
	Remitos *newObject;
	newObject = (Remitos*) calloc(sizeof(Remitos), 1);

	return newObject;
}

Remitos* Entity_newParamRemito(char *id, char *idCliente, char *cliente, char *monto, char *date) {
	Remitos *newObject;
	newObject = Entity_newRemito();

	int auxId;
	int auxIdCliente;
	float auxprecio;

	if (newObject != NULL && id != NULL && idCliente != NULL && cliente != NULL &&
			monto != NULL && date != NULL) {
		auxId = atoi(id);
		auxIdCliente = atoi(idCliente);
		auxprecio = atof(monto);

		Entity_Remitos_setDate(newObject, date);
		Entity_Remitos_setID(newObject, &auxId);
		Entity_Remitos_setIdCliente(newObject, auxIdCliente);
		Entity_Remitos_setCliente(newObject, cliente);
		Entity_Remitos_setMontoRemito(newObject, auxprecio);
	}
	return newObject;
}

//***************************************
// funcion para ll_count
//***************************************
int sumaHaber(void* pElement){
	float haber = -1;
	Remitos* an_Object;
	if(pElement!=NULL){
		an_Object = (Remitos*)pElement;
		if(an_Object!=NULL){
			Entity_Remitos_getMontoRemito(an_Object, &haber);
		}
	}
	return haber;
}

//***************************************
// funcion para ll_count
//***************************************
int sumaDebe(void* pElement){
	float debe = -1;
	Remitos* an_Object;
	if(pElement!=NULL){
		an_Object = (Remitos*)pElement;
		if(an_Object!=NULL){
			Entity_Remitos_getMontoRemito(an_Object, &debe);
		}
	}

	return debe;
}

int Entity_Remito_SearchForId(LinkedList *this, int id) {
    int retorno = -1;
    int idAux;
	Remitos *pRemito;

	for (int index = 0; index < ll_len(this); index++) {
		pRemito = ll_get(this, index);
		if (Entity_Remitos_getID(pRemito, &idAux) == 1 &&
           idAux == id){
            retorno = index;
        }
    }

    return retorno;
}

int Entity_Remito_Show(Remitos *this) {
	int sucess = 0;
	int id;
	int idCustomer;
	char date[128];
	char customer[128];
	float amount;

	if (this != NULL) {
		Entity_Remitos_getDate(this, date);
		Entity_Remitos_getID(this, &id);
		Entity_Remitos_getCliente(this, customer);
		Entity_Remitos_getIdCliente(this, &idCustomer);
		Entity_Remitos_getMontoRemito(this, &amount);

		printf("    __________________________________________________________\n"
		"       Fecha     ID    Cliente   ID_Clien  Monto\n");
		printf("    [%10s] [%02d] [%-10s] [%02d] [%-8.2f]\n", date, id, customer,idCustomer, amount);
		printf(	"    __________________________________________________________\n");
		sucess = 1;
	}

	return sucess;
}

//Destructors
void Entity_Remito_delete(Remitos *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}





/* Function/SortBy: [Infectados] */
/*
int Entity_sortInfectados(void *infect1, void *infect2) {
int infect_1;
int infect_2;
int success = 0; // si los tiempos son iguales, devuelve 0

Entity_getInfected(infect1, &infect_1);
Entity_getInfected(infect2, &infect_2);

if (infect_1 > infect_2) {
	success = 1;
} else if (infect_1 < infect_2) {
	success = -1;
	}
	return success;
}
*/
