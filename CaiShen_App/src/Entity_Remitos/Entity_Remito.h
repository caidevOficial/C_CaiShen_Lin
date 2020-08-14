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

#include "../LinkedList.h"

#ifndef ENTITY_REMITO_H_INCLUDED_
#define ENTITY_REMITO_H_INCLUDED_

typedef struct{
	int idProducto;
	char nombreProducto[128];
	float precio;
}Producto;

typedef struct{
	int dia;
	int mes;
	int anho;
}Fecha;

typedef struct {
	//Fecha fecha;
	char date[128];
	int id;
	char cliente[128]; //
	int idCliente;
	float monto;
	//Producto productos;
}Remitos;


Remitos* Entity_newRemito();


//Remitos* Entity_newParamRemito(char *id, char *idCliente, char *cliente,char *monto, char *dia, char *mes, char *anho);

Remitos* Entity_newParamRemito(char *id, char *idCliente, char *cliente,char *monto, char *date);

int sumaDebe(void* pElement);

int Entity_Remito_SearchForId(LinkedList *this, int id);

void Entity_Remito_delete(Remitos *this);

int Entity_Remito_Show(Remitos *this);

#endif // ENTITY_REMITO_H_INCLUDED_
