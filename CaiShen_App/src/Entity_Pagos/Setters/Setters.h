/*
 * Setters.h
 *
 *  Created on: 14 ago. 2020
 *      Author: caidev
 */

#ifndef ENTITY_PAGOS_SETTERS_SETTERS_H_
#define ENTITY_PAGOS_SETTERS_SETTERS_H_


int Entity_Pagos_setID(Pagos *this, int *id);

int Entity_Pagos_setCliente(Pagos *this, char *customerName);

int Entity_Pagos_setIdCliente(Pagos *this, int idCustomer);

int Entity_Pagos_setMontoPago(Pagos *this, float price);

int Entity_Pagos_setDate(Pagos *this, char *date);

#endif /* ENTITY_PAGOS_SETTERS_SETTERS_H_ */
