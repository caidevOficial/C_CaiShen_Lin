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

#include "../LinkedList.h"
#include "../Entity_Remitos/Entity_Remito.h"

int parser_ObjectFromTextRemito(FILE *pFile, LinkedList *this) {

	Remitos* pObject;
	char id[128];
	char idCliente[128];
	char cliente[128];
	char montoRemito[128];
	char dia[20];
	char mes[20];
	char anho[20];

	char date[128];

	int success = 0;
	int firstElement = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n", dia, mes, anho, id, idCliente, cliente, montoRemito);
				firstElement = 0;
			}
			fscanf(pFile, "%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n", dia, mes, anho, id, idCliente, cliente, montoRemito);
			strcpy(date,dia);
			strcat(date,"/");
			strcat(date,mes);
			strcat(date,"/");
			strcat(date,anho);
			pObject = Entity_newParamRemito(id, idCliente, cliente, montoRemito, date);

			if (pObject != NULL) {
				ll_add(this, pObject);
				success = 1;
			}
		}
	}
	return success;
}

/*
int parser_ObjectFromTextRemito(FILE *pFile, LinkedList *this) {
	//Remitos *pObject;
	Remitos* pObject;
	char id[128];
	char idCliente[128];
	char cliente[128];
	char montoRemito[128];
	char dia[128];
	char mes[128];
	char anho[128];

	int success = 0;
	int firstElement = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^/]/%[^/]%[^,],%[^,],%[^,],%[^,],%[^\n]\n", dia, mes, anho, id, idCliente, cliente, montoRemito);
				firstElement = 0;
			}
			fscanf(pFile, "%[^/]/%[^/]%[^,],%[^,],%[^,],%[^,],%[^\n]\n", dia, mes, anho, id, idCliente, cliente, montoRemito);
			pObject = Entity_newParamRemito(id, idCliente, cliente, montoRemito, dia, mes, anho);

			if (pObject != NULL) {
				ll_add(this, pObject);
				success = 1;
			}
		}
	}
	return success;
}
*/
