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

int Entity_Customer_setID(eCliente *this, int *id) {
	int success = 0;

	if (this != NULL) {
		if (id >= 0) {
			this->id = *id;
			success = 1;
		}
	}
	return success;
}

int Entity_Customer_setRazonSocial(eCliente *this, char *razonSocial) {
	int success = 0;

	if (this != NULL && razonSocial != NULL) {
		strncpy(this->razonSocial, razonSocial, 10);
		success = 1;
	}
	return success;
}

int Entity_Customer_setDuenho(eCliente *this, char *duenho) {
	int success = 0;

	if (this != NULL && duenho != NULL) {
		strncpy(this->nombreDuenho, duenho, 10);
		success = 1;
	}
	return success;
}

int Entity_Customer_setLocalidad(eCliente *this, char *localidad) {
	int success = 0;

	if (this != NULL && localidad != NULL) {
		strncpy(this->localidad, localidad, 10);
		success = 1;
	}
	return success;
}

int Entity_Customer_setCalle(eCliente *this, char *calle) {
	int success = 0;

	if (this != NULL && calle != NULL) {
		strncpy(this->calle, calle, 10);
		success = 1;
	}
	return success;
}

int Entity_Customer_setNumeroDireccion(eCliente *this, int numeroDireccion) {
	int success = 0;

	if (this != NULL) {
		if (numeroDireccion >= 0) {
			this->numeroDireccion = numeroDireccion;
			success = 1;
		}
	}
	return success;
}

int Entity_Customer_setTelefono(eCliente *this, char *telefono) {
	int success = 0;

	if (this != NULL) {
		if (telefono >= 0) {
			strncpy(this->telefono,telefono,12);
			success = 1;
		}
	}
	return success;
}

int Entity_Customer_setIdCuenta(eCliente *this, int idCuenta) {
	int success = 0;

	if (this != NULL) {
		if (idCuenta >= 0) {
			this->idCuenta = idCuenta;
			success = 1;
		}
	}
	return success;
}
