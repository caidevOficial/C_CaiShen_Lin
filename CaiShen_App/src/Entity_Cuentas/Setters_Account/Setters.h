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

#ifndef ENTITY_CUENTAS_SETTERS_ACCOUNT_SETTERS_H_
#define ENTITY_CUENTAS_SETTERS_ACCOUNT_SETTERS_H_

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Account_setID(Accounts *this, int *id);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  customer value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Account_setCliente(Accounts *this, char *customer);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  idCliente value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Account_setIDCliente(Accounts *this, int *idCliente);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  debe value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Account_setDebe(Accounts *this, float debe);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  haber value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Account_setHaber(Accounts *this, float haber);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  deudaActual value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Account_setDeudaActual(Accounts *this, float deudaActual);

#endif /* ENTITY_CUENTAS_SETTERS_ACCOUNT_SETTERS_H_ */
