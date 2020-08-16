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

#include "../Entity_Remito.h"

#ifndef ENTITY_REMITOS_GETTERS_GETTERS_H_
#define ENTITY_REMITOS_GETTERS_GETTERS_H_

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  id value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Remitos_getID(Remitos *this, int *id);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  customerName value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Remitos_getCliente(Remitos *this, char *customerName);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  customerId value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Remitos_getIdCliente(Remitos *this, int *customerId);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  monto value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Remitos_getMontoRemito(Remitos *this, float *monto);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  date value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Remitos_getDate(Remitos *this, char *date);

#endif /* ENTITY_REMITOS_GETTERS_GETTERS_H_ */
