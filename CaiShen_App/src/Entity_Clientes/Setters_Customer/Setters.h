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

#ifndef ENTITY_CLIENTES_SETTERS_CUSTOMER_SETTERS_H_
#define ENTITY_CLIENTES_SETTERS_CUSTOMER_SETTERS_H_

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_setID(eCliente *this, int *id);

/**
 * @brief  Set the data in the field razonSocial.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_setRazonSocial(eCliente *this, char *razonSocial);

/**
 * @brief  Set the data in the field duenho.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_setDuenho(eCliente *this, char *duenho);

/**
 * @brief  Set the data in the field localidad.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_setLocalidad(eCliente *this, char *localidad);

/**
 * @brief  Set the data in the field calle.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_setCalle(eCliente *this, char *calle);

/**
 * @brief  Set the data in the field telefono.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_setTelefono(eCliente *this, char *telefono);

/**
 * @brief  Set the data in the field numeroDireccion.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_setNumeroDireccion(eCliente *this, int numeroDireccion);

/**
 * @brief  Set the data in the field idCuenta.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Customer_setIdCuenta(eCliente *this, int idCuenta);

#endif /* ENTITY_CLIENTES_SETTERS_CUSTOMER_SETTERS_H_ */
