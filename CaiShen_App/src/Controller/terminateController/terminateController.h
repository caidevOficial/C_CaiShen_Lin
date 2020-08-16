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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../LinkedList.h"

#ifndef LIBRARY_CONTROLLER_TERMINATECONTROLLER_TERMINATECONTROLLER_H_
#define LIBRARY_CONTROLLER_TERMINATECONTROLLER_TERMINATECONTROLLER_H_

/**
 * @brief  Delete an Entity from the LL.
 * @param  this List of remitos.
 * @return 1 for success, 0 for error.
 */
int controller_removeRemito(LinkedList *this);

/**
 * @brief  Delete an Entity from the LL.
 * @param  this List of pagos.
 * @return 1 for success, 0 for error.
 */
int controller_removePago(LinkedList *this);

/**
 * @brief  Delete an Entity from the LL.
 * @param  this List of clientes.
 * @return 1 for success, 0 for error.
 */
int controller_removeCliente(LinkedList *this);

#endif /* LIBRARY_CONTROLLER_TERMINATECONTROLLER_TERMINATECONTROLLER_H_ */
