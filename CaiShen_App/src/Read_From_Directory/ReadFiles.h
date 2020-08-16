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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#ifndef READFILE_READFILES_H_
#define READFILE_READFILES_H_

/**
 * @brief Prints a message with the error.
 * @param s String error to print.
 * @author  FacuFalcone.
 */
void error(const char *s);

/**
 * @brief Process the actual file in the directory.
 * @param pFile The file to be processed.
 * @author  FacuFalcone.
 */
void processFile(char *pFile);

/**
 * @brief   Tries to read and list all the files in the actual directory
 * @return  return 1 if the files was listed, else return 0.
 * @author  FacuFalcone.
 */
int Read_Directory();

#endif /* READFILE_READFILES_H_ */
