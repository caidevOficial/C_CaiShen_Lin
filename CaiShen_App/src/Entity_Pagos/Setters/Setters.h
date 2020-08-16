/*
 * Setters.h
 *
 *  Created on: 14 ago. 2020
 *      Author: caidev
 */

#ifndef ENTITY_PAGOS_SETTERS_SETTERS_H_
#define ENTITY_PAGOS_SETTERS_SETTERS_H_

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  id value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Pagos_setID(Pagos *this, int *id);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  customerName value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Pagos_setCliente(Pagos *this, char *customerName);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  idCustomer value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Pagos_setIdCliente(Pagos *this, int idCustomer);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  price value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Pagos_setMontoPago(Pagos *this, float price);

/**
 * @brief  Set the data in the field id.
 * @param  this Entity to be modified.
 * @param  date value to be modified or added.
 * @return 1 for success, 0 for error.
 */
int Entity_Pagos_setDate(Pagos *this, char *date);

#endif /* ENTITY_PAGOS_SETTERS_SETTERS_H_ */
