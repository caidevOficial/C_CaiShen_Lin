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

#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

/**
 * @brief  Loads all the data from text.
 * @param  path directory where the file is.
 * @param  this List to save all the data loaded.
 * @return 1 for success, 0 for error.
 */
int controller_loadFromTextRemitos(char *path, LinkedList *this);

/**
 * @brief  Loads all the data from text.
 * @param  path directory where the file is.
 * @param  this List to save all the data loaded.
 * @return 1 for success, 0 for error.
 */
int controller_loadFromTextPagos(char *path, LinkedList *this);

/**
 * @brief  Loads all the data from text.
 * @param  path directory where the file is.
 * @param  this List to save all the data loaded.
 * @return 1 for success, 0 for error.
 */
int controller_loadFromTextClientes(char *path, LinkedList *this);

/**
 * @brief  Loads all the data from text.
 * @param  path directory where the file is.
 * @param  this List to save all the data loaded.
 * @return 1 for success, 0 for error.
 */
int controller_loadFromTextCuentas(char *path, LinkedList *this);

/**
 * @brief  Prints on screen the entire list of entities.
 * @param  this List with all the entities.
 * @return 1 for success, 0 for error.
 */
int controller_ListObjectRemitos(LinkedList *this);

/**
 * @brief  Prints on screen the entire list of entities.
 * @param  this List with all the entities.
 * @return 1 for success, 0 for error.
 */
int controller_ListObjectPagos(LinkedList *this);

/**
 * @brief  Prints on screen the entire list of entities.
 * @param  this List with all the entities.
 * @return 1 for success, 0 for error.
 */
int controller_ListObjectClientes(LinkedList *this);

/**
 * @brief  Prints on screen the entire list of entities.
 * @param  this List with all the entities.
 * @param  thisCustomer List of customers to take theirs ids.
 * @param  thisRemitos List of remitos to take its ids and amount.
 * @param  thisPagos List of pagos to take its ids and amount.
 * @return 1 for success, 0 for error.
 */
int controller_ListObjectCuentas(LinkedList *this, LinkedList *thisCustomer, LinkedList *thisRemitos, LinkedList *thisPagos);

/**
 * @brief  Save the data on text.
 * @param  path directory of the file to save the entire data.
 * @param  this List that contain the data to be saved.
 * @return 1 for success, 0 for error.
 */
int controller_saveAsTextAccount(char *path, LinkedList *this);

/**
 * @brief  Save the data on text.
 * @param  path directory of the file to save the entire data.
 * @param  this List that contain the data to be saved.
 * @return 1 for success, 0 for error.
 */
int controller_saveAsTextCustomer(char *path, LinkedList *this);

/**
 * @brief  Save the data on text.
 * @param  path directory of the file to save the entire data.
 * @param  this List that contain the data to be saved.
 * @return 1 for success, 0 for error.
 */
int controller_saveAsTextRemito(char *path, LinkedList *this);

/**
 * @brief  Save the data on text.
 * @param  path directory of the file to save the entire data.
 * @param  this List that contain the data to be saved.
 * @return 1 for success, 0 for error.
 */
int controller_saveAsTextPago(char *path, LinkedList *this);

#endif /* CONTROLLER_CONTROLLER_H_ */
