/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "serial_uart.h"// ibncluimos la libreria de serial uart
#include "eeprom_mamalona.h"// incluimos la libreria de eeprom mamalona
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

uint32_t hexPage;//esta varaible si es indispensable
uint32_t readData;//esta varaible no es necesaria, solo es ara guardar los datos recibidos de varaibles eneteras


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */


//inicializacion de la memoria eeprom
hexPage = getHexAddressPage(DATA_PAGE);            //Get our hex page // nos devuelve los dat
SerialUartSendString("Iniciando el programa eeprom mamalona\n");



/*Estas son las varaibles que usare para simular los numeros telefonicos y los permisos */
	int numero_1[10]={5,5,6,6,2,9,4,2,3,6};
	int numero_2[10]={5,6,1,4,3,9,9,5,2,4};
	int numero_3[10]={1,2,3,4,5,6,7,8,9,0};
	int numero_4[10]={5,5,6,7,1,1,1,1,1,0};
	int numero_5[10]={1,3,4,3,4,8,9,3,1,2};
	int numero_6[10]={6,6,6,6,6,6,6,6,6,6};
	int numero_7[10]={7,7,7,7,7,7,7,7,7,7};
	int numero_8[10]={8,8,8,8,8,8,8,8,8,8};
	int numero_9[10]={9,9,9,9,9,9,9,9,9,9};
	int numero_10[10]={1,1,1,1,1,1,1,1,1,1};
	int numero_11[10]={2,2,2,2,2,2,2,2,2,2};
	int numero_12[10]={3,3,3,3,3,3,3,3,3,3};
	int numero_13[10]={4,4,4,4,4,4,4,4,4,4};
	int numero_14[10]={8,8,8,8,8,8,8,8,8,8};
	int numero_15[10]={9,9,9,9,9,9,9,9,9,9};
	int numero_16[10]={1,1,1,1,2,2,2,2,2,2};
	int numero_17[10]={6,6,6,6,6,6,6,6,6,5};
	int numero_18[10]={3,3,3,3,3,3,3,2,4,8};
	int numero_19[10]={8,9,7,8,6,1,2,3,1,0};
	int numero_20[10]={4,6,5,7,8,9,3,6,6,6};


	int comodin[10];//Esta fucnion nos seriva para guardar momentaneamente los valores de numeros telefonicos
	int comodin_pass[5];//este vectos nos sirve para guardar momentaneamente

//estos son los permisos que tiene que tener las varaibles

	int llave_1=0;
	int llave_2=1;
	int llave_3=2;
	int llave_4=3;
	int llave_5=4;
	int llave_6=5;
	int llave_7=6;
	int llave_8=7;
	int llave_9=8;
	int llave_10=9;
	int llave_11=10;
	int llave_12=11;
	int llave_13=12;
	int llave_14=13;
	int llave_15=14;
	int llave_16=15;
	int llave_17=16;
	int llave_18=17;
	int llave_19=18;
	int llave_20=19;
	int pass[5]={1,2,3,4,5};
	int pass_mas[5]={6,4,8,9,2};


HAL_Delay(100);

/*Usamos esta funcion para guardar toda la lista blanca, el arguemnto hexPage no se debe de mover
 * Recuerda que todo debe ser int, si no no funciona, aun no se proque jejejejejeje*/
/*
eeprom_write_list(hexPage,
		numero_1,
		numero_2,
		numero_3,
		numero_4,
		numero_5,
		numero_6,
		numero_7,
		numero_8,
		numero_9,
		numero_10,
		numero_11,
		numero_12,
		numero_13,
		numero_14,
		numero_15,
		numero_16,
		numero_17,
		numero_18,
		numero_19,
		numero_20,
		pass,
		pass_mas,
		llave_1,
		llave_2,
		llave_3,
		llave_4,
		llave_5,
		llave_6,
		llave_7,
		llave_8,
		llave_9,
		llave_10,
		llave_11,
		llave_12,
		llave_13,
		llave_14,
		llave_15,
		llave_16,
		llave_17,
		llave_18,
		llave_19,
		llave_20

);
*/



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */



	  //leer un numero telefonico usando eeprom_read_tel_number
	  //enviasmo hexPage,el index del telefono y el vector donde queremos guardar el vector

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_1, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 1:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres, si queremos podemos borras esta fucnion
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_2, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 2:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_3, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 3:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_4, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 4:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_5, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 5:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_6, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 6:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_7, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 7:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_8, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 8:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_9, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 9:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_10, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 10:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_11, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 11:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_12, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 12:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_13, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 13:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_14, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 14:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_15, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 15:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_16, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 16:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_17, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 17:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_18, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 18:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_19, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 19:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  //leer numero 1 desde eeprom
	  eeprom_read_tel_number(hexPage, tel_20, comodin);//guardamos el telefono 1 en comodin
	  SerialUartSendString("NUMERO 20:");
	  imprimir_vector(comodin, 10);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");




	  eeprom_read_tel_number(hexPage, pass, comodin);//guardamos la contraseña
	  SerialUartSendString("contrasena:");
	  imprimir_vector(comodin, 5);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");


	  eeprom_read_tel_number(hexPage, mpass, comodin);//guardamos la contraseña maestra
	  SerialUartSendString("contrasena maestra:");
	  imprimir_vector(comodin, 5);//imrpirmios vector comodi y le decimos que tiene 10 caracteres
	  SerialUartSendString("\n");

	  SerialUartSendString("Permisos...\n");

	  readData = eeprom_read_key(hexPage,permiso_n_1);
	  SerialUartSendVarInt("Permiso telefono 1: %d",readData );
	  SerialUartSendString("\n");

	  readData = eeprom_read_key(hexPage,permiso_n_2);
	  SerialUartSendVarInt("Permiso telefono 2: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_3);
	  SerialUartSendVarInt("Permiso telefono 3: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_4);
	  SerialUartSendVarInt("Permiso telefono 4: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_5);
	  SerialUartSendVarInt("Permiso telefono 5: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_6);
	  SerialUartSendVarInt("Permiso telefono 6: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_6);
	  SerialUartSendVarInt("Permiso telefono 7: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_8);
	  SerialUartSendVarInt("Permiso telefono 8: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_9);
	  SerialUartSendVarInt("Permiso telefono 9: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_10);
	  SerialUartSendVarInt("Permiso telefono 10: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_11);
	  SerialUartSendVarInt("Permiso telefono 11: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_12);
	  SerialUartSendVarInt("Permiso telefono 12: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_13);
	  SerialUartSendVarInt("Permiso telefono 13: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_14);
	  SerialUartSendVarInt("Permiso telefono 14: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_15);
	  SerialUartSendVarInt("Permiso telefono 15: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_16);
	  SerialUartSendVarInt("Permiso telefono 16: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_17);
	  SerialUartSendVarInt("Permiso telefono 17: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_18);
	  SerialUartSendVarInt("Permiso telefono 18: %d",readData );
	  SerialUartSendString("\n");
	  readData = eeprom_read_key(hexPage,permiso_n_19);
	  SerialUartSendVarInt("Permiso telefono 19: %d",readData );
	  SerialUartSendString("\n");

	  readData = eeprom_read_key(hexPage,permiso_n_20);
	  SerialUartSendVarInt("Permiso telefono 20: %d",readData );
	  SerialUartSendString("\n");

	  HAL_Delay(30000);
/*
	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 1));

	  SerialUartSendVarInt("Dato 1: %d", readData);
	  SerialUartSendString("\n");
	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 2));
	  SerialUartSendVarInt("Dato 2: %d", readData);
	  SerialUartSendString("\n");
	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 3));
	  SerialUartSendVarInt("Dato 3: %d", readData);
	  SerialUartSendString("\n");

	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 4));
	  SerialUartSendVarInt("Dato 4: %d", readData);
	  SerialUartSendString("\n");

	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 5));
	  SerialUartSendVarInt("Dato 5: %d", readData);
	  SerialUartSendString("\n");

	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 6));
	  SerialUartSendVarInt("Dato 6: %d", readData);
	  SerialUartSendString("\n");

	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 7));
	  SerialUartSendVarInt("Dato 7: %d", readData);
	  SerialUartSendString("\n");

	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 8));
	  SerialUartSendVarInt("Dato 8: %d", readData);
	  SerialUartSendString("\n");

	  readData = retrieveDataFromAddress(hexPage + (DATA_SPACE * 9));
	  SerialUartSendVarInt("Dato 9: %d", readData);
	  SerialUartSendString("\n");


	  HAL_Delay(1000);*/

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
