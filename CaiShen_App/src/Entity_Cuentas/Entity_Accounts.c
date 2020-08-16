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

#include "Entity_Accounts.h"

#include "Getters_Account/Getters.h"
#include "Setters_Account/Setters.h"

// Constructors
Accounts* Entity_newAccount() {
	Accounts *newObject;
	newObject = (Accounts*) calloc(sizeof(Accounts), 1);

	return newObject;
}

Accounts* Entity_newParamAccounts(char *id, char *idCliente, char *cliente, char *debe,char *haber, char *deuda_Actual) {
	Accounts *newObject;
	newObject = Entity_newAccount();

	int auxId;
	int auxIdCLiente;
	float auxDebe;
	float auxHaber;
	float auxDeudaActual;

	if (newObject != NULL && id != NULL && idCliente!=NULL && cliente != NULL && debe != NULL && haber != NULL && deuda_Actual != NULL ) {
		auxId = atoi(id);
		auxIdCLiente = atoi(idCliente);
		auxDebe = atof(debe);
		auxHaber = atof(haber);
		auxDeudaActual = atof(deuda_Actual);

		Entity_Account_setID(newObject, &auxId);
		Entity_Account_setIDCliente(newObject, &auxIdCLiente);
		Entity_Account_setCliente(newObject, cliente);
		Entity_Account_setDebe(newObject, auxDebe);
		Entity_Account_setHaber(newObject, auxHaber);
		Entity_Account_setDeudaActual(newObject, auxDeudaActual);
	}
	return newObject;
}

/* Function/SortBy: [Deuda Actual] */
int Entity_sortDeudaActual(void *deudor1, void *deudor2) {
float deudor_1;
float deudor_2;
int success = 0; // si los deudores deben lo mismo, devuelve 0

Entity_Account_getDeuda(deudor1, &deudor_1);
Entity_Account_getDeuda(deudor2, &deudor_2);

if (deudor_1 > deudor_2) {
	success = 1;
} else if (deudor_1 < deudor_2) {
	success = -1;
	}
	return success;
}
