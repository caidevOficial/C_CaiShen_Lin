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

#ifndef CONTROLLER_MODIFYCONTROLLER_MODIFYCONTROLLER_H_
#define CONTROLLER_MODIFYCONTROLLER_MODIFYCONTROLLER_H_

/**
 * @brief  Look for a index of the entity.
 * @param  this list of Entities.
 * @param  index The index of the entity. (could be -1)
 * @param  idPayOut The Id of the payOut.
 * @param  maxIDPayOut The id Max of the all payOut registereds.
 */
void lookForIndexPayment(LinkedList * this, int *index, int *idPayOut, int *maxIDPayOut);

/**
 * @brief  Look for a index of the entity.
 * @param  this List of Entities.
 * @param  index The index of the entity. (could be -1)
 * @param  idRem The Id of the payOut.
 * @param  maxIDRem The id Max of the all payOut registereds.
 */
void lookForIndexRem(LinkedList *this, int *index, int *idRem, int *maxIDRem);

/**
 * @brief  Look for a index of the entity.
 * @param  this List of Entities.
 * @param  index The index of the entity. (could be -1)
 * @param  idCustomer The Id of the customer.
 * @param  maxIdCustomer The id Max of the all customers registereds.
 */
void lookForIndexCustomer(LinkedList *this, int *index,int *idCustomer, int *maxIdCustomer);

/**
 * @brief  Edit the payment amount or not.
 * @param  this List of the Entities to modify the field.
 * @return 1 for success, 0 for error.
 */
int controller_editPagos(LinkedList *this);

/**
 * @brief  Edit the Remito amount or not.
 * @param  this List of the Entities to modify the field.
 * @return 1 for success, 0 for error.
 */
int controller_editRemitos(LinkedList *this);

/**
 * @brief  Edit the fields of a customer.
 * @param  this List of the Entities to modify the field.
 * @return 1 for success, 0 for error.
 */
int controller_editCustomer(LinkedList *this);

#endif /* CONTROLLER_MODIFYCONTROLLER_MODIFYCONTROLLER_H_ */
