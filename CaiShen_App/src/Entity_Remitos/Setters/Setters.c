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

#include "../Entity_Remito.h"

int Entity_Remitos_setID(Remitos *this, int *id) {
	int success = 0;

	if (this != NULL) {
		if (id >= 0) {
			this->id = *id;
			success = 1;
		}
	}
	return success;
}

int Entity_Remitos_setCliente(Remitos *this, char *customerName) {
	int success = 0;

	if (this != NULL && customerName != NULL) {
		strncpy(this->cliente, customerName, 10);
		success = 1;
	}
	return success;
}

int Entity_Remitos_setIdCliente(Remitos *this, int idCustomer) {
	int success = 0;

	if (this != NULL) {
		if (idCustomer >= 0) {
			this->idCliente = idCustomer;
			success = 1;
		}
	}
	return success;
}

int Entity_Remitos_setMontoRemito(Remitos *this, float price) {
	int success = 0;

	if (this != NULL) {
		if (price >= 0) {
			this->monto = price;
			success = 1;
		}
	}
	return success;
}

int Entity_Remitos_setDate(Remitos *this, char *date) {
	int success = 0;

	if (this != NULL && date != NULL) {
		strncpy(this->date, date, 11);
		success = 1;
	}
	return success;
}
