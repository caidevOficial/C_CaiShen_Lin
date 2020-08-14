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

#ifndef ENTITY_REMITOS_SETTERS_REMITOS_SETTERS_H_
#define ENTITY_REMITOS_SETTERS_REMITOS_SETTERS_H_

int Entity_Remitos_setID(Remitos *this, int *id);

int Entity_Remitos_setCliente(Remitos *this, char *customerName);

int Entity_Remitos_setIdCliente(Remitos *this, int idCustomer);

int Entity_Remitos_setMontoRemito(Remitos *this, float price);

//int Entity_Remitos_setFecha(Remitos *this, int dia, int mes, int anho);
int Entity_Remitos_setDate(Remitos *this, char *date);

#endif /* ENTITY_REMITOS_SETTERS_REMITOS_SETTERS_H_ */
