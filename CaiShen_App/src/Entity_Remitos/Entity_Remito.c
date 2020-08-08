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
	//int auxDia;
	//int auxMes;
	//int auxAnho;
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

/*
Remitos* Entity_newParamRemito(char *id, char *idCliente, char *cliente, char *monto, char *dia, char *mes, char *anho) {
	Remitos *newObject;
	newObject = Entity_newRemito();

	int auxId;
	int auxIdCliente;
	int auxDia;
	int auxMes;
	int auxAnho;
	float auxprecio;

	if (newObject != NULL && id != NULL && idCliente != NULL && cliente != NULL &&
			monto != NULL && dia != NULL && mes != NULL && anho != NULL) {
		auxId = atoi(id);
		auxIdCliente = atoi(idCliente);
		auxDia = atoi(dia);
		auxMes = atoi(mes);
		auxAnho = atoi(anho);
		auxprecio = atof(monto);

		Entity_Remitos_setFecha(newObject, auxDia, auxMes, auxAnho);
		Entity_Remitos_setID(newObject, &auxId);
		Entity_Remitos_setIdCliente(newObject, auxIdCliente);
		Entity_Remitos_setCliente(newObject, cliente);
		Entity_Remitos_setMontoRemito(newObject, auxprecio);
	}
	return newObject;
}*/

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
