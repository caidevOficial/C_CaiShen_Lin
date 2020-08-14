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
 *
 * Version     : Beta 3.3.0 [Beta v3.3.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

#include "../../LinkedList.h"

#ifndef LIBRARY_KnightZodiac_REGISTERKnightZodiac_REGISTERKnightZodiac_H_
#define LIBRARY_KnightZodiac_REGISTERKnightZodiac_REGISTERKnightZodiac_H_

int controller_addRemito(LinkedList *this, LinkedList *thisCustomer);

int controller_addPago(LinkedList *this, LinkedList *thisCustomer);

int controller_addCliente(LinkedList *this, LinkedList *thisAccount);

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

#endif /* LIBRARY_KnightZodiac_REGISTERKnightZodiac_REGISTERKnightZodiac_H_ */
