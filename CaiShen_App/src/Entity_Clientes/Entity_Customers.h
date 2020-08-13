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

#ifndef Entity_H_INCLUDED
#define Entity_H_INCLUDED

typedef struct {
    int id;
	char razonSocial[128]; //
	char nombreDuenho[128];
	char localidad[128];
	char calle[128];
	char telefono[128];
	int numeroDireccion;
	int idCuenta;
}eCliente;


eCliente* Entity_newClientes();


eCliente* Entity_newParamClientes(char *id, char *razonSocial, char *nombreDuenho,char *localidad,
		char *calle, char *telefono, char *numeroDireccion, char *idCuenta);

int Entity_Customer_Show(eCliente *this);

int Entity_Customer_SearchForId(LinkedList *this, int id);

void Entity_Customer_delete(eCliente *this);

#endif // Entity_H_INCLUDED
