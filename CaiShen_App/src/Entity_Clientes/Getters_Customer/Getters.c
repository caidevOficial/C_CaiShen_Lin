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

#include "../Entity_Customers.h"

int Entity_Customer_getID(eCliente *this, int *id) {
	int success = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		success = 1;
	}
	return success;
}

int Entity_Customer_getRazonSocial(eCliente *this, char *razonSocial) {
	int success = 0;

	if (this != NULL && razonSocial != NULL) {
		strcpy(razonSocial, this->razonSocial);
		success = 1;
	}
	return success;
}

int Entity_Customer_getDuenho(eCliente *this, char *duenho) {
	int success = 0;

	if (this != NULL && duenho != NULL) {
		strcpy(duenho, this->nombreDuenho);
		success = 1;
	}
	return success;
}

int Entity_Customer_getLocalidad(eCliente *this, char *localidad) {
	int success = 0;

	if (this != NULL && localidad != NULL) {
		strcpy(localidad, this->localidad);
		success = 1;
	}
	return success;
}

int Entity_Customer_getCalle(eCliente *this, char *calle) {
	int success = 0;

	if (this != NULL && calle != NULL) {
		strcpy(calle, this->calle);
		success = 1;
	}
	return success;
}

int Entity_Customer_getTelefono(eCliente *this, char *telefono) {
	int success = 0;

	if (this != NULL && telefono != NULL) {
		strcpy(telefono, this->telefono);
		success = 1;
	}
	return success;
}

int Entity_Customer_getNumeroDireccion(eCliente *this, int *numeroDireccion) {
	int success = 0;

	if (this != NULL && numeroDireccion != NULL) {
		*numeroDireccion = this->numeroDireccion;
		success = 1;
	}
	return success;
}

int Entity_Customer_getIdCuenta(eCliente *this, int *idCuenta) {
	int success = 0;

	if (this != NULL && idCuenta != NULL) {
		*idCuenta = this->idCuenta;
		success = 1;
	}
	return success;
}
