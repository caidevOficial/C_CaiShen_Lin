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

#include "../../Entity_Cuentas/Entity_Accounts.h"

#ifndef ENTITY_CUENTAS_GETTERS_ACCOUNT_GETTERS_H_
#define ENTITY_CUENTAS_GETTERS_ACCOUNT_GETTERS_H_

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  id value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Account_getID(Accounts *this, int *id);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  idCliente value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Account_getIdCliente(Accounts *this, int *idCliente);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  customer value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Account_getCliente(Accounts *this, char *customer);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  debe value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Account_getDebe(Accounts *this, float *debe);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  haber value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Account_getHaber(Accounts *this, float *haber);

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  deuda value getted.
 * @return 1 for success, 0 for error
 */
int Entity_Account_getDeuda(Accounts *this, float *deuda);

#endif /* ENTITY_CUENTAS_GETTERS_ACCOUNT_GETTERS_H_ */
