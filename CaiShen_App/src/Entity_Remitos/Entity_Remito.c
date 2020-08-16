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
