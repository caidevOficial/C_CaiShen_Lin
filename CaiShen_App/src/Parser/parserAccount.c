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

#include <stdio_ext.h>//linux
#include <stdlib.h>

#include "../Entity_Cuentas/Entity_Accounts.h"
#include "../LinkedList.h"

int parser_ObjectFromTextCuenta(FILE *pFile, LinkedList *this) {
	Accounts *pObject;
	char id[128];
	char idCliente[128];
	char cliente[128];
	char debe[128];
	char haber[128];
	char deuda[128];

	int success = 0;
	int firstElement = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, idCliente, cliente, debe, haber, deuda);
				firstElement = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, idCliente, cliente, debe, haber, deuda);
			pObject = Entity_newParamAccounts(id, idCliente, cliente, debe, haber, deuda);

			if (pObject != NULL) {
				ll_add(this, pObject);
				success = 1;
			}
		}
	}
	return success;
}
