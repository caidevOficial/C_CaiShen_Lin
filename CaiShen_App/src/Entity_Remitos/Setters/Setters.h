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

#ifndef ENTITY_REMITOS_SETTERS_REMITOS_SETTERS_H_
#define ENTITY_REMITOS_SETTERS_REMITOS_SETTERS_H_

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Remitos_setID(Remitos *this, int *id);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  customerName value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Remitos_setCliente(Remitos *this, char *customerName);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  idCustomer value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Remitos_setIdCliente(Remitos *this, int idCustomer);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  price value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Remitos_setMontoRemito(Remitos *this, float price);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  date value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Remitos_setDate(Remitos *this, char *date);

#endif /* ENTITY_REMITOS_SETTERS_REMITOS_SETTERS_H_ */
