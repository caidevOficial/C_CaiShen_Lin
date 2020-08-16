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

#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>

#include "Entity_Customers.h"

#include "Getters_Customer/Getters.h"
#include "Setters_Customer/Setters.h"

// Constructors
eCliente* Entity_newClientes() {
	eCliente *newObject;
	newObject = (eCliente*) calloc(sizeof(eCliente), 1);

	return newObject;
}

eCliente* Entity_newParamClientes(char *id, char *razonSocial, char *nombreDuenho,char *localidad,
		char *calle, char *telefono, char *numeroDireccion, char *idCuenta) {
	eCliente *newObject;
	newObject = Entity_newClientes();

	int auxId;
	int auxNumeroDireccion;
	int auxIdCuenta;

	if (newObject != NULL && id != NULL && razonSocial != NULL && nombreDuenho != NULL && localidad != NULL &&
			calle != NULL && telefono!=NULL && numeroDireccion!=NULL && idCuenta!=NULL) {
		auxId = atoi(id);
		auxNumeroDireccion = atoi(numeroDireccion);
		auxIdCuenta = atoi(idCuenta);

		Entity_Customer_setID(newObject, &auxId);
		Entity_Customer_setRazonSocial(newObject, razonSocial);
		Entity_Customer_setDuenho(newObject, nombreDuenho);
		Entity_Customer_setLocalidad(newObject, localidad);
		Entity_Customer_setCalle(newObject, calle);
		Entity_Customer_setTelefono(newObject, telefono);
		Entity_Customer_setNumeroDireccion(newObject, auxNumeroDireccion);
		Entity_Customer_setIdCuenta(newObject, auxIdCuenta);
	}
	return newObject;
}

int Entity_Customer_Show(eCliente *this) {
	int sucess = 0;
	int idCustomer;
	int numberAdress;
	int idAccount;
	char razonSocial[128];
	char contacto[128];
	char city[128];
	char phone[128];
	char street[128];

	if (this != NULL) {
		Entity_Customer_getID(this, &idCustomer);
		Entity_Customer_getRazonSocial(this, razonSocial);
		Entity_Customer_getDuenho(this, contacto);
		Entity_Customer_getLocalidad(this, city);
		Entity_Customer_getCalle(this, street);
		Entity_Customer_getNumeroDireccion(this, &numberAdress);
		Entity_Customer_getTelefono(this, phone);
		Entity_Customer_getIdCuenta(this, &idAccount);

		printf("   _________________________________________________________________________________\n"
		"    ID  RazonSocia   Contacto   Telefono      Localidad     Calle    Altura Cuenta\n"
		"   _________________________________________________________________________________\n");
		printf("   [%02d] [%-8s]  [%-8s] [%-10s] [%-8s] [%-8s] [%04d]  [%02d]\n",
				idCustomer, razonSocial, contacto,phone, city, street, numberAdress, idAccount);
		printf(	"   _________________________________________________________________________________\n");
		sucess = 1;
	}

	return sucess;
}

int Entity_Customer_SearchForId(LinkedList *this, int id) {
    int retorno = -1;
    int idAux;
	eCliente *pCliente;

	for (int index = 0; index < ll_len(this); index++) {
		pCliente = ll_get(this, index);
		if (Entity_Customer_getID(pCliente, &idAux) && idAux == id){
            retorno = index;
        }
    }

    return retorno;
}

//Destructors
void Entity_Customer_delete(eCliente *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}
