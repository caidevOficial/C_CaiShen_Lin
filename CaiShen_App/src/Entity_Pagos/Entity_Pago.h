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

#ifndef ENTITY_PAGOS_H_INCLUDED_
#define ENTITY_PAGOS_H_INCLUDED_

typedef struct {
	char date[128];
	int idPago;
	char cliente[128]; //
	int idCliente;
	float monto;
	//Producto productos;
}Pagos;

Pagos* Entity_newPago();

Pagos* Entity_newParamPago(char *id, char *idCliente, char *cliente,char *monto, char *date);

int sumaDebe(void* pElement);

int Entity_Pago_SearchForId(LinkedList *this, int id);

void Entity_Pago_delete(Pagos *this);

int Entity_Pago_Show(Pagos *this);

#endif // ENTITY_PAGOS_H_INCLUDED_
