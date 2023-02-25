/*
 * eeprom_mamalona.c
 *
 *  Created on: Feb 24, 2023
 *      Author: pc
 */



#include "eeprom_mamalona.h"//incluimos la libreria de eeprom mamalona
#include  "serial_uart.h"

#define flash_delay 10
uint32_t getHexAddressPage(int dataPage){
	uint32_t bits       = PAGE_SECTOR * dataPage;
	uint32_t hexAddress = FLASH_INIT + bits;
	return hexAddress;
}

void memoryPageErase(uint32_t memoryPage){
	HAL_StatusTypeDef eraseHandler = HAL_FLASH_Unlock();

	eraseHandler = FLASH_WaitForLastOperation(500);
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR);
	FLASH_PageErase(0,memoryPage);

	eraseHandler = FLASH_WaitForLastOperation(500);
	CLEAR_BIT(FLASH->CR, FLASH_CR_PER);
	HAL_FLASH_Lock();
}

void writeThreeData(uint32_t hexPage, int dataA, int dataB, int dataC){
	memoryPageErase(DATA_PAGE);

	HAL_FLASH_Unlock();

	HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage, dataA);
	HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + DATA_SPACE, dataB);
	HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*2), dataC);

	HAL_FLASH_Lock();
}

uint32_t retrieveDataFromAddress(uint32_t hexAddress){
	return *(uint32_t*)hexAddress;
}


//funcion para escribir una varaible en el index
void writeData(uint32_t page,uint32_t index, int Data)
{


	memoryPageErase(DATA_PAGE);
	HAL_FLASH_Unlock();
	HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, page+(DATA_SPACE*index), Data);
	HAL_FLASH_Lock();

}


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
		)
{

	memoryPageErase(DATA_PAGE);

		HAL_FLASH_Unlock();

		/*HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage+ (DATA_SPACE*0), number_1[0]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*1), number_1[1]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*2), number_1[2]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*3), number_1[3]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*4), number_1[4]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*5), number_1[5]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*6), number_1[6]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*7), number_1[7]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*8), number_1[8]);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*9), number_1[9]);*/

		//numero 1
		uint8_t index_vector=0;
		for(uint16_t contador=0; contador<=9; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_1[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);

		}

		//numero 2
		index_vector=0;
		for(uint16_t contador=10; contador<=19; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_2[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}

		//numero 3
		index_vector=0;
		for(uint16_t contador=20; contador<=29; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_3[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 4

		index_vector=0;
		for(uint16_t contador=30; contador<=39; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_4[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 5

		index_vector=0;
		for(uint16_t contador=40; contador<=49; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_5[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 6

		index_vector=0;
		for(uint16_t contador=50; contador<=59; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_6[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 7

		index_vector=0;
		for(uint16_t contador=60; contador<=69; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_7[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 8

		index_vector=0;
		for(uint16_t contador=70; contador<=79; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_8[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 9

		index_vector=0;
		for(uint16_t contador=80; contador<=89; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_9[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 10

		index_vector=0;
		for(uint16_t contador=90; contador<=99; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_10[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 11

		index_vector=0;
		for(uint16_t contador=100; contador<=109; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_11[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 12

		index_vector=0;
		for(uint16_t contador=110; contador<=119; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_12[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 13

		index_vector=0;
		for(uint16_t contador=120; contador<=129; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_13[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 14

		index_vector=0;
		for(uint16_t contador=130; contador<=139; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_14[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 15

		index_vector=0;
		for(uint16_t contador=140; contador<=149; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_15[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 16

		index_vector=0;
		for(uint16_t contador=150; contador<=159; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_16[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 17

		index_vector=0;
		for(uint16_t contador=160; contador<=169; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_17[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 18

		index_vector=0;
		for(uint16_t contador=170; contador<=179; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_18[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 19

		index_vector=0;
		for(uint16_t contador=180; contador<=189; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_19[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}
		//numero 20

		index_vector=0;
		for(uint16_t contador=190; contador<=199; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), number_20[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}

		//contraseña voltatil


		index_vector=0;
		for(uint16_t contador=200; contador<=204; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), password[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}

		index_vector=0;
		for(uint16_t contador=205; contador<=209; contador++)
		{

			HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*contador), password_mamalon[index_vector]);
			index_vector++;
			HAL_Delay(flash_delay);
		}


		//ahora guardamso las key


		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*210), key_1);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*211), key_2);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*212), key_3);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*213), key_4);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*214), key_5);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*215), key_6);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*216), key_7);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*217), key_8);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*218), key_9);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*219), key_10);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*220), key_11);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*221), key_12);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*222), key_13);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*223), key_14);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*224), key_15);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*225), key_16);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*226), key_17);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*227), key_18);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*228), key_19);
		HAL_Delay(flash_delay);
		HAL_FLASH_Program(TYPEPROGRAM_DOUBLEWORD, hexPage + (DATA_SPACE*229), key_20);
		HAL_Delay(flash_delay);





		HAL_FLASH_Lock();
}


/*Funcion para leer los permisos de cada numero*/

uint32_t eeprom_read_key(uint32_t hexPage,uint16_t index)

{

switch(index)
{

case permiso_n_1 :

	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 210));//key 1
	break;


case permiso_n_2:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 211));//key 1
	break;

case permiso_n_3:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 212));//key 1
	break;

case permiso_n_4:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 213));//key 1
	break;

case permiso_n_5:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 214));//key 1
	break;

case permiso_n_6:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 215));//key 1
	break;

case permiso_n_7:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 216));//key 1
	break;

case permiso_n_8:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 217));//key 1
	break;

case permiso_n_9:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 218));//key 1
	break;

case permiso_n_10:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 219));//key 1
	break;

case permiso_n_11:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 220));//key 1
	break;

case permiso_n_12:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 221));//key 1
	break;

case permiso_n_13:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 222));//key 1
	break;
case permiso_n_14:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 223));//key 1
	break;

case permiso_n_15:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 224));//key 1
	break;

case permiso_n_16:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 225));//key 1
	break;

case permiso_n_17:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 226));//key 1
	break;

case permiso_n_18:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 227));//key 1
	break;

case permiso_n_19:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 228));//key 1
	break;

case permiso_n_20:
	return retrieveDataFromAddress(hexPage + (DATA_SPACE * 229));//key 1
	break;

default:
	return 0;
	break;




}


}




/*Funcion para ;leer los numeros de telefono*/
void eeprom_read_tel_number(uint32_t hexPage,uint16_t index,int buffer[])
{


uint16_t indexador=0;
switch(index)
{
case tel_1:


	indexador=0;
		for(uint16_t conta=0; conta<=9; conta++)
			  {
				  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

				 	  indexador++;
			  }


	break;
case tel_2:


	indexador=0;
	for(uint16_t conta=10; conta<=19; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_3:

	indexador=0;
	for(uint16_t conta=20; conta<=29; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_4:
	indexador=0;
	for(uint16_t conta=30; conta<=39; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_5:
	indexador=0;
	for(uint16_t conta=40; conta<=49; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_6:
	indexador=0;
	for(uint16_t conta=50; conta<=59; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_7:
	indexador=0;
	for(uint16_t conta=60; conta<=69; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_8:
	indexador=0;
	for(uint16_t conta=70; conta<=79; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_9:
	indexador=0;
	for(uint16_t conta=80; conta<=89; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_10:
	indexador=0;
	for(uint16_t conta=90; conta<=99; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_11:
	indexador=0;
	for(uint16_t conta=100; conta<=109; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_12:
	indexador=0;
	for(uint16_t conta=110; conta<=119; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_13:
	indexador=0;
	for(uint16_t conta=120; conta<=129; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_14:
	indexador=0;
	for(uint16_t conta=130; conta<=139; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_15:
	indexador=0;
	for(uint16_t conta=140; conta<=149; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_16:
	indexador=0;
	for(uint16_t conta=150; conta<=159; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_17:
	indexador=0;
	for(uint16_t conta=160; conta<=169; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_18:
	indexador=0;
	for(uint16_t conta=170; conta<=179; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_19:
	indexador=0;
	for(uint16_t conta=180; conta<=189; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case tel_20:
	indexador=0;
	for(uint16_t conta=190; conta<=199; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;
case pass://pasword
	indexador=0;
	for(uint16_t conta=200; conta<=204; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;

case mpass: //master password
	indexador=0;
	for(uint16_t conta=205; conta<=209; conta++)
		  {
			  buffer[indexador] = retrieveDataFromAddress(hexPage + (DATA_SPACE * conta));

			 	  indexador++;
		  }
	break;

}




}


/*Esta fucnion la podemos borrar si queremos */

void imprimir_vector(int vector[], int vector_number)
{
		vector_number=vector_number-1;

	  for(uint8_t c =0; c<=vector_number;c++)
	  {
		  SerialUartSendVarInt("%d", vector[c]);

	  }

}

/*Inicializacion de la memoria eeprom*/
void eeprom_init()
{




}
