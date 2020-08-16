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

#ifndef ENTITY_CLIENTES_GETTERS_CUSTOMER_GETTERS_H_
#define ENTITY_CLIENTES_GETTERS_CUSTOMER_GETTERS_H_

/**
 * @brief  Get the data of the field id.
 * @param  this Entity.
 * @param  id id getted.
 * @return 1 for success, 0 for error
 */
int Entity_Customer_getID(eCliente *this, int *id);

/**
 * @brief  Get the data of the field razonSocial.
 * @param  this Entity.
 * @param  id id getted.
 * @return 1 for success, 0 for error
 */
int Entity_Customer_getRazonSocial(eCliente *this, char *razonSocial);

/**
 * @brief  Get the data of the field duenho.
 * @param  this Entity.
 * @param  id id getted.
 * @return 1 for success, 0 for error
 */
int Entity_Customer_getDuenho(eCliente *this, char *duenho);

/**
 * @brief  Get the data of the field localidad.
 * @param  this Entity.
 * @param  id id getted.
 * @return 1 for success, 0 for error
 */
int Entity_Customer_getLocalidad(eCliente *this, char *localidad);

/**
 * @brief  Get the data of the field calle.
 * @param  this Entity.
 * @param  id id getted.
 * @return 1 for success, 0 for error
 */
int Entity_Customer_getCalle(eCliente *this, char *calle);

/**
 * @brief  Get the data of the field telefono.
 * @param  this Entity.
 * @param  id id getted.
 * @return 1 for success, 0 for error
 */
int Entity_Customer_getTelefono(eCliente *this, char *telefono);

/**
 * @brief  Get the data of the field numeroDireccion.
 * @param  this Entity.
 * @param  id id getted.
 * @return 1 for success, 0 for error
 */
int Entity_Customer_getNumeroDireccion(eCliente *this, int *numeroDireccion);

/**
 * @brief  Get the data of the field idCuenta.
 * @param  this Entity.
 * @param  id id getted.
 * @return 1 for success, 0 for error
 */
int Entity_Customer_getIdCuenta(eCliente *this, int *idCuenta);

#endif /* ENTITY_CLIENTES_GETTERS_CUSTOMER_GETTERS_H_ */
