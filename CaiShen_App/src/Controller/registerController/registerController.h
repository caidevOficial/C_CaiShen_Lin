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

#include "../../LinkedList.h"

#ifndef CONTROLLER_REGISTERCONTROLLER_REGISTERCONTROLLER_H
#define CONTROLLER_REGISTERCONTROLLER_REGISTERCONTROLLER_H

/**
 * @brief	Read an ID from a text file.
 * @param 	*id
 * @return	Return 1 if can, else return 0.
 */
int obtainID(int* id,char* path);

/**
 * @brief	Write a text file with id+1.
 * @param 	id
 * @return	Return 1 if can, else return 0.
 */
int upgradeID(int id,char* path);

/**
 * @brief  Adds a new entity in the list 'this'.
 * @param  this List of entities remitos.
 * @param  thisCustomer List of entities type customer.
 * @return 1 for success, 0 for error.
 */
int controller_addRemito(LinkedList *this, LinkedList *thisCustomer);

/**
 * @brief  Adds a new entity in the list 'this'.
 * @param  this List of entities pagos.
 * @param  thisCustomer List of entities type customer.
 * @return 1 for success, 0 for error.
 */
int controller_addPago(LinkedList *this, LinkedList *thisCustomer);

/**
 * @brief  Adds a new entity in the list 'this'.
 * @param  this List of entities customer.
 * @param  thisAccount List of entities type account.
 * @return 1 for success, 0 for error.
 */
int controller_addCliente(LinkedList *this, LinkedList *thisAccount);

#endif /* CONTROLLER_REGISTERCONTROLLER_REGISTERCONTROLLER_H */
