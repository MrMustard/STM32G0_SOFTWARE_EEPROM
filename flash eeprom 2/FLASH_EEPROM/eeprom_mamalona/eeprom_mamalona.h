/*
 * eeprom_mamalona.h
 *
 *  Created on: Feb 24, 2023
 *      Author: pc
 */

#ifndef EEPROM_MAMALONA_H_
#define EEPROM_MAMALONA_H_

#include "main.h"
#include "stm32g0xx_hal_flash.h"


typedef enum
{
permiso_n_1,
permiso_n_2,
permiso_n_3,
permiso_n_4,
permiso_n_5,
permiso_n_6,
permiso_n_7,
permiso_n_8,
permiso_n_9,
permiso_n_10,
permiso_n_11,
permiso_n_12,
permiso_n_13,
permiso_n_14,
permiso_n_15,
permiso_n_16,
permiso_n_17,
permiso_n_18,
permiso_n_19,
permiso_n_20

}permiso_t;


typedef enum
{
tel_1,
tel_2,
tel_3,
tel_4,
tel_5,
tel_6,
tel_7,
tel_8,
tel_9,
tel_10,
tel_11,
tel_12,
tel_13,
tel_14,
tel_15,
tel_16,
tel_17,
tel_18,
tel_19,
tel_20,
pass, //password
mpass,//master password
}tel_t;

#define FLASH_INIT  0x08000000  //This is the page zero of our flash
#define DATA_SPACE  8            //Samples between each saved element
#define PAGE_SECTOR 2048         //Page size
#define DATA_PAGE   31           //Page that will store our data

uint32_t getHexAddressPage(int dataPage);                               //Here receive our page on int format and we get the address on hex format
uint32_t retrieveDataFromAddress(uint32_t hexAddress);                  //Retrieve our stored data
void writeThreeData(uint32_t hexPage, int dataA, int dataB, int dataC); //Write our desired values in to flash
void memoryPageErase(uint32_t memoryPage);                              //Erase a memory page from the flash retrieve
/*Inicializacion de la memoria eeprom*/
void eeprom_init();
//funcion para escribir una varaible en el index
void writeData(uint32_t page,uint32_t index, int Data);


void eeprom_write_list(uint32_t hexPage,int number_1[],

		int number_2[],
		int number_3[],
		int number_4[],
		int number_5[],
		int number_6[],
		int number_7[],
		int number_8[],
		int number_9[],
		int number_10[],
		int number_11[],
		int number_12[],
		int number_13[],
		int number_14[],
		int number_15[],
		int number_16[],
		int number_17[],
		int number_18[],
		int number_19[],
		int number_20[],
		int password[],		//contraseña volatil
		int password_mamalon[], // contraseña maestra
		int key_1,
		int key_2,
		int key_3,
		int key_4,
		int key_5,
		int key_6,
		int key_7,
		int key_8,
		int key_9,
		int key_10,
		int key_11,
		int key_12,
		int key_13,
		int key_14,
		int key_15,
		int key_16,
		int key_17,
		int key_18,
		int key_19,
		int key_20
					 );

/*Funcion para leer los permisos de cada numero*/

uint32_t eeprom_read_key(uint32_t hexPage,uint16_t index);


/*Funcion para ;leer los numeros de telefono*/
void eeprom_read_tel_number(uint32_t hexPage,uint16_t index,int buffer[]);

/*Esta fucnion la podemos borrar si queremos */

void imprimir_vector(int vector[], int vector_number);

#endif /* EEPROM_MAMALONA_H_ */
