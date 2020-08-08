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

#include <stdio_ext.h>//linux
#include <stdlib.h>
#include <string.h>

#include "../Entity_Remito.h"

/* Setters: [ID] */
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

/* Setters: [NOMBRE CLIENTE] */
int Entity_Remitos_setCliente(Remitos *this, char *customerName) {
	int success = 0;

	if (this != NULL && customerName != NULL) {
		strncpy(this->cliente, customerName, 10);
		success = 1;
	}
	return success;
}

/* Setters: [ID CLIENTE] */
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

/* Setters: [PRECIO REMITO] */
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


/*
int Entity_Remitos_setDia(Remitos *this, int dia) {
	int success = 0;

	if (this != NULL) {
		if (dia > 0 && dia < 32) {
			this->fecha.dia = dia;
			success = 1;
		}
	}
	return success;
}

int Entity_Remitos_setMes(Remitos *this, int mes) {
	int success = 0;

	if (this != NULL) {
		if (mes > 0 && mes < 13) {
			this->fecha.mes = mes;
			success = 1;
		}
	}
	return success;
}


int Entity_Remitos_setAnho(Remitos *this, int anho) {
	int success = 0;

	if (this != NULL) {
		if (anho >= 2020) {
			this->fecha.anho = anho;
			success = 1;
		}
	}
	return success;
}

int Entity_Remitos_setFecha(Remitos *this, int dia, int mes, int anho){
	int success = 0;
	if (this != NULL) {
		if (anho >= 2020 && (mes > 0 && mes < 13) && (dia > 0 && dia < 32)) {
			if(Entity_Remitos_setDia(this, dia) &&
			Entity_Remitos_setMes(this, mes) &&
			Entity_Remitos_setAnho(this, anho)){
				success = 1;
			}
		}
	}
	return success;
}
*/
