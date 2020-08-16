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

#ifndef ENTITY_ACCOUNTS_H_INCLUDED
#define ENTITY_ACCOUNTS_H_INCLUDED

typedef struct {
    int id;
    int idCliente;
	char cliente[128];
	float debe;
	float haber;
	float deuda_Actual;
} Accounts;

/**
 * @brief  Reserve memory space for the entity.
 * @return the entity.
 */
Accounts* Entity_newAccount();

/**
 * @brief  Creates the new entity.
 * @param  id value to be putted in the field id.
 * @param  idCliente value to be putted in the field idCliente.
 * @param  cliente value to be putted in the field cliente.
 * @param  debe value to be putted in the field debe.
 * @param  haber value to be putted in the field haber.
 * @param  deuda_Actual value to be putted in the field deuda_Actual.
 * @return The entity created.
 */
Accounts* Entity_newParamAccounts(char *id, char *idCliente, char *cliente, char *debe,char *haber, char *deuda_Actual);

/**
 * @brief  sort by debt.
 * @param  deudor1 entity.
 * @param  deudor2 entity.
 * @return -1 if the second entity is higher, 0 if both are equal, 1 if the first entity is higher.
 */
int Entity_sortDeudaActual(void *deudor1, void *deudor2);

#endif // ENTITY_ACCOUNTS_H_INCLUDED
