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
#include <string.h>

#include "Getters.h"
#include "../Entity_Pago.h"

int Entity_Pagos_getID(Pagos *this, int *id) {
	int success = 0;

	if (this != NULL && id != NULL) {
		*id = this->idPago;
		success = 1;
	}
	return success;
}

int Entity_Pagos_getCliente(Pagos *this, char *customerName) {
	int success = 0;

	if (this != NULL && customerName != NULL) {
		strcpy(customerName, this->cliente);
		success = 1;
	}
	return success;
}

int Entity_Pagos_getIdCliente(Pagos *this, int *customerId) {
	int success = 0;

	if (this != NULL && customerId != NULL) {
		*customerId = this->idCliente;
		success = 1;
	}
	return success;
}

int Entity_Pagos_getMontoPago(Pagos *this, float *monto) {
	int success = 0;

	if (this != NULL && monto != NULL) {
		*monto = this->monto;
		success = 1;
	}
	return success;
}

int Entity_Pagos_getDate(Pagos *this, char *date) {
	int success = 0;

	if (this != NULL && date != NULL) {
		strcpy(date, this->date);
		success = 1;
	}
	return success;
}
