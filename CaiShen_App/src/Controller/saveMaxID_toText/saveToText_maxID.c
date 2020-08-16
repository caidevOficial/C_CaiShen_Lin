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

//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../Entity_Clientes/Entity_Customers.h"
#include "../../Entity_Clientes/Getters_Customer/Getters.h"

#include "../../Entity_Pagos/Entity_Pago.h"
#include "../../Entity_Pagos/Getters/Getters.h"

#include "../../Entity_Remitos/Entity_Remito.h"
#include "../../Entity_Remitos/Getters/Getters.h"

#include "../../LinkedList.h"
#include "../../Parser/parserCustomer.h"
#include "../../Validate/caidevValidate.h"

static int saveAsText_maxIDCustomers(FILE *pFile, LinkedList *this, int *maxID, int tipo) {
	eCliente *pCustomer;
	Remitos *pRemito;
	Pagos *pPago;

    int ID;
    int len_LL;
    int sucess = 0;
    int biggerID;
    int flag = 0;

	if (pFile != NULL && this != NULL) {//si el archivo y el array no son null..
		len_LL = ll_len(this);// obtengo el tamanho del array.

        for(int i=0; i<len_LL; i++){	// recorro el array.
        	switch(tipo){
        		case 0:
        			pCustomer = ll_get(this, i);// copio la estructura del cliente del indice.
					Entity_Customer_getID(pCustomer, &ID); //obtengo el id del cliente.
        			break;
        		case 1:
        			pRemito = ll_get(this, i);// copio la estructura del cliente del indice.
        			Entity_Remitos_getID(pRemito, &ID);
        			break;
        		case 2:
        			pPago = ll_get(this, i);// copio la estructura del cliente del indice.
					Entity_Pagos_getID(pPago, &ID);
        			break;
        	}
        	//pCustomer = ll_get(this, i);// copio la estructura del cliente del indice.
			//Entity_Customer_getID(pCustomer, &ID); //obtengo el id del cliente.

			if(flag==0 || ID>biggerID){
            	biggerID = ID;
            	flag=1;
            }
            sucess = 1;
        }
    }
    *maxID = biggerID;
    return sucess;
}

int controller_saveAsTextMaxID(FILE *pFile, char *path,	LinkedList *this, char tipo) {
    int sucess = 0;
    int maxID;

	if (pFile != NULL && saveAsText_maxIDCustomers(pFile, this, &maxID, tipo)) {
		//si el archivo no es null y pude escribir, retorno 1
        sucess = 1;
        fprintf(pFile,"%d\n",maxID+1);	//escribo los datos de cada empleado en el archivo.
    }
    return sucess;
}
