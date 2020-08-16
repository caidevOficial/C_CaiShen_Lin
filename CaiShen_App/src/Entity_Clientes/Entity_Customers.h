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

#ifndef Entity_H_INCLUDED
#define Entity_H_INCLUDED

typedef struct {
    int id;
	char razonSocial[128]; //
	char nombreDuenho[128];
	char localidad[128];
	char calle[128];
	char telefono[128];
	int numeroDireccion;
	int idCuenta;
}eCliente;

/**
 * @brief  Reserv memory space for the entity.
 * @return the entity.
 */
eCliente* Entity_newClientes();

/**
 * @brief  Creates the new entity.
 * @param  id value to be putted in the field id.
 * @param  razonSocial value to be putted in the field razon social.
 * @param  nombreDuenho value to be putted in the field nombreDuenho.
 * @param  localidad value to be putted in the field localidad.
 * @param  calle value to be putted in the field calle.
 * @param  telefono value to be putted in the field telefono.
 * @param  numeroDireccion value to be putted in the field numeroDireccion.
 * @param  idCuenta value to be putted in the field idCuenta.
 * @return the entity created.
 */
eCliente* Entity_newParamClientes(char *id, char *razonSocial, char *nombreDuenho,char *localidad,
		char *calle, char *telefono, char *numeroDireccion, char *idCuenta);

/**
 * @brief  Prints in screen one entity.
 * @param  this the entity to be printed.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_Show(eCliente *this);

/**
 * @brief  Search the index of an entity by its id.
 * @param  this list of entities.
 * @param  id id of the entity to be founded.
 * @return the index if success, -1 if error.
 */
int Entity_Customer_SearchForId(LinkedList *this, int id);

/**
 * @brief Delete the entity.
 * @param this Entity to be deleted.
 */
void Entity_Customer_delete(eCliente *this);

#endif // Entity_H_INCLUDED
