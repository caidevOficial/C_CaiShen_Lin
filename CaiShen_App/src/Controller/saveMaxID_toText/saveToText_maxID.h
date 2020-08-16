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

#ifndef CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_
#define CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_

/**
 * @brief  saves in a file the next id of the entities.
 * @param  pFile file to save the number.
 * @param  path path where the file is.
 * @param  this list of entities to be traversed.
 * @param  tipo type of entity.
 * @return 1 for success, 0 for error.
 */
int controller_saveAsTextMaxID(FILE *pFile, char *path,	LinkedList *this, int tipo);

#endif /* CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_ */
