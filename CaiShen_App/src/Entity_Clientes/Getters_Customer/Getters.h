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


#ifndef ENTITY_CLIENTES_GETTERS_CUSTOMER_GETTERS_H_
#define ENTITY_CLIENTES_GETTERS_CUSTOMER_GETTERS_H_

int Entity_Customer_getID(eCliente *this, int *id);

int Entity_Customer_getRazonSocial(eCliente *this, char *razonSocial);

int Entity_Customer_getDuenho(eCliente *this, char *duenho);

int Entity_Customer_getLocalidad(eCliente *this, char *localidad);

int Entity_Customer_getCalle(eCliente *this, char *calle);

int Entity_Customer_getTelefono(eCliente *this, char *telefono);

int Entity_Customer_getNumeroDireccion(eCliente *this, int *numeroDireccion);

int Entity_Customer_getIdCuenta(eCliente *this, int *idCuenta);

#endif /* ENTITY_CLIENTES_GETTERS_CUSTOMER_GETTERS_H_ */
