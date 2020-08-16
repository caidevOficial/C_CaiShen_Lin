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

#include "Setters.h"
#include "../Entity_Accounts.h"

/* Setters: [ID] */
int Entity_Account_setID(Accounts *this, int *id) {
	int success = 0;

	if (this != NULL) {
		if (id >= 0) {
			this->id = *id;
			success = 1;
		}
	}
	return success;
}

/* Setters: [CLIENTE] */
int Entity_Account_setCliente(Accounts *this, char *customer) {
	int success = 0;

	if (this != NULL && customer != NULL) {
		strncpy(this->cliente, customer, 10);
		success = 1;
	}
	return success;
}

/* Setters: [ID] */
int Entity_Account_setIDCliente(Accounts *this, int *idCliente) {
	int success = 0;

	if (this != NULL) {
		if (idCliente >= 0) {
			this->idCliente = *idCliente;
			success = 1;
		}
	}
	return success;
}


/* Setters: [DEBE] */
int Entity_Account_setDebe(Accounts *this, float debe) {
	int success = 0;

	if (this != NULL) {
		if (debe >= 0) {
			this->debe = debe;
			success = 1;
		}
	}
	return success;
}

/* Setters: [HABER] */
int Entity_Account_setHaber(Accounts *this, float haber) {
	int success = 0;

	if (this != NULL) {
		if (haber >= 0) {
			this->haber = haber;
			success = 1;
		}
	}
	return success;
}

/* Setters: [DEUDA] */
int Entity_Account_setDeudaActual(Accounts *this, float deudaActual) {
	int success = 0;

	if (this != NULL) {
		if (deudaActual > (-10000)) {
			this->deuda_Actual = deudaActual;
			success = 1;
		}
	}
	return success;
}
