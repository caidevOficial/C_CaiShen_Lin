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
 * Type: Recuperatorio segundo parcial - Laboratorio 1.
 * Version     : Beta 1.1.2 [Beta v1.1.2] - FacuFalcone_ABM_Pandemia_[Linux]
 * ============================================================================
 */

#include "../../Entity_Cuentas/Entity_Accounts.h"

#ifndef ENTITY_CUENTAS_SETTERS_ACCOUNT_SETTERS_H_
#define ENTITY_CUENTAS_SETTERS_ACCOUNT_SETTERS_H_
int Entity_Account_setID(Accounts *this, int *id);

int Entity_Account_setCliente(Accounts *this, char *customer);

int Entity_Account_setIDCliente(Accounts *this, int *idCliente);

int Entity_Account_setDebe(Accounts *this, float debe);

int Entity_Account_setHaber(Accounts *this, float haber);

int Entity_Account_setDeudaActual(Accounts *this, float deudaActual);

#endif /* ENTITY_CUENTAS_SETTERS_ACCOUNT_SETTERS_H_ */
