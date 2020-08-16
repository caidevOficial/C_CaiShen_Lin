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

#include <stdio_ext.h>//linux
#include <stdlib.h>
#include <string.h>

#include "Getters.h"
#include "../Entity_Accounts.h"

int Entity_Account_getID(Accounts *this, int *id) {
	int success = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		success = 1;
	}
	return success;
}

int Entity_Account_getIdCliente(Accounts *this, int *idCliente) {
	int success = 0;

	if (this != NULL && idCliente != NULL) {
		*idCliente = this->idCliente;
		success = 1;
	}
	return success;
}

/* Getter: [Cliente] */
int Entity_Account_getCliente(Accounts *this, char *customer) {
	int success = 0;

	if (this != NULL && customer != NULL) {
		strcpy(customer, this->cliente);
		success = 1;
	}
	return success;
}

int Entity_Account_getHaber(Accounts *this, float *haber) {
	int success = 0;

	if (this != NULL && haber != NULL) {
		*haber = this->haber;
		success = 1;
	}
	return success;
}

int Entity_Account_getDeuda(Accounts *this, float *deuda) {
	int success = 0;

	if (this != NULL && deuda != NULL) {
		*deuda = this->deuda_Actual;
		success = 1;
	}
	return success;
}

int Entity_Account_getDebe(Accounts *this, float *debe) {
	int success = 0;

	if (this != NULL && debe != NULL) {
		*debe = this->debe;
		success = 1;
	}
	return success;
}
