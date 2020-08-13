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
 *
 * Version     : Beta 3.3.0 [Beta v3.3.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Controller.h"
#include "../../LinkedList.h"

#include "../../Entity_Remitos/Entity_Remito.h"
#include "../../Entity_Remitos/Getters/Getters.h"

//#include "../../Parser/parser.h"
#include "../../Validate/caidevValidate.h"
#include "../registerController/registerController.h"

int controller_removeRemito(LinkedList *this) {
	Remitos *pRemito;

	int sucess = 0;
	int index;
	int idRemito;
	int obtainedID;
	int confirmOption;
	int maxID;

	obtainID(&maxID, "Remitos_LastID.txt");
	if (this != NULL) {
		//controller_ListKnightZodiac(this); // imprimo lista
		controller_ListObjectRemitos(this);
		getNumberInt(&idRemito,
		"    [Message]: Ingrese ID a dar de baja\n    [De la Lista]: ", //pido el ID a borrar
		"    [Message]: ID incorrecto, reingrese. ", 1,(maxID - 1), 5);

		index = Entity_Remito_SearchForId(this, idRemito);// busco el indice de la ID

		pRemito = ll_get(this, index); // obtengo el elemento del indice
		Entity_Remitos_getID(pRemito, &obtainedID);// obtengo la id del indice
		//KnightZodiac_getID(pRemito, &obtainedID);

		if (obtainedID == idRemito) {
			//showKnightZodiac(pRemito); // muestro al Remito seleccionado
			Entity_Remito_Show(pRemito);
			//controller_ListObjectRemitos(pRemito);
			getNumberInt(&confirmOption,
			"\n\n    [Message]: Dar de baja el remito [no se podra recuperar]?"
			"\n    [1] Dar de baja Remito."
			"\n    [2] Cancelar."
			"\n    [Message]: Ingrese opcion: ",
			"    [Message]: Error, escoja opciones [1-2]: ", 1, 2, 3);

			switch (confirmOption) {
			case 1:
				ll_remove(this, index); // borro el empleado
				Entity_Remito_delete(pRemito);// borro el auxiliar de la funcion
				sucess = 1;
				break;
			case 2:
				sucess = 0;
				break;
			default:
				break;
			}
		}
	}
	return sucess;
}
