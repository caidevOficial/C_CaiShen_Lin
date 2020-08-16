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

#ifndef MENU_MAINMENU_H_
#define MENU_MAINMENU_H_

/**
 * @brief  Prints on the screen all the menu options.
 * @return Return the selected option.
 */
int menu();

/**
 * @brief  Prints on the screen all the options of the customer section.
 * @return Return the selected option.
 */
int menuClientes();

/**
 * @brief  Prints on the screen all the options of the remitos section.
 * @return Return the selected option.
 */
int menuRemitos();

/**
 * @brief  Prints on the screen all the options of the payments section.
 * @return Return the selected option.
 */
int menuPagos();

// Menus modificaciones.

/**
 * @brief  Prints on the screen all the options of the modify customer section.
 * @return Return the selected option.
 */
int modifyCustomers();

/**
 * @brief  Prints on the screen all the options of the modify [remito/payments] section.
 * @return Return the selected option.
 */
int modifyRemitosOrPagos();

#endif /* MENU_MAINMENU_H_ */
