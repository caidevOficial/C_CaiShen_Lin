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

#ifndef PARSER_PARSERREMITO_H_
#define PARSER_PARSERREMITO_H_

/**
 * @brief  Parser the file to get all the data.
 * @param  pFile file to get the data.
 * @param  this listo to save the data.
 * @return 1 for success, 0 for error.
 */
int parser_ObjectFromTextRemito(FILE *pFile, LinkedList *this);

#endif /* PARSER_H_ */
