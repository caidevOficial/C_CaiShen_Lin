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

/**
 * @brief  Reserve memory space for the entity.
 * @return the entity.
 */
Pagos* Entity_newPago();

/**
 * @brief  Creates the new entity.
 * @param  id value to be putted in the field id.
 * @param  idCliente value to be putted in the field idCliente.
 * @param  cliente value to be putted in the field cliente.
 * @param  monto value to be putted in the field monto.
 * @param  date value to be putted in the field date.
 * @return The entity created.
 */
Pagos* Entity_newParamPago(char *id, char *idCliente, char *cliente,char *monto, char *date);

/**
 * @brief  Search the index of an entity by its id.
 * @param  this list of entities.
 * @param  id id of the entity to be founded.
 * @return the index if success, -1 if error.
 */
int Entity_Pago_SearchForId(LinkedList *this, int id);

/**
 * @brief Delete the entity.
 * @param this Entity to be deleted.
 */
void Entity_Pago_delete(Pagos *this);

/**
 * @brief  Prints in screen one entity.
 * @param  this the entity to be printed.
 * @return 1 for success, 0 for error.
 */
int Entity_Pago_Show(Pagos *this);

#endif // ENTITY_PAGOS_H_INCLUDED_
