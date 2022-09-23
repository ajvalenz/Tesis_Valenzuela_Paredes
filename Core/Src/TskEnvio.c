/*
 * TskEnvio.c
 *
 *  Created on: Dec 6, 2021
 *      Author: OMEN
 */
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "HX711.h"
#include "globalVar.h"

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void Tsk_Envio(void *argument)
{
  /* USER CODE BEGIN Tsk_Envio */
	    unsigned char str[2] = {};
		char message[10] = {};
		int cont_uart = 0;
		char command ;
		unsigned char overflow[8] = {"Overflow"};
		//unsigned char cmd_ok[6] = {"Cmd OK"};
		//unsigned char cmd_nok[9] = {"Cmd NO OK"};

		char response[10] = {};


  /* Infinite loop */
  for(;;)
  {
//	  HAL_UART_Transmit(&huart4, overflow, 8, HAL_MAX_DELAY);

	      HAL_UART_Receive(&huart4, str, 1, HAL_MAX_DELAY);
	 	  message[cont_uart] = str[0];
	 	  cont_uart++;

	 	  if (cont_uart > 3)
	 	  {
	 		  cont_uart = 0;
	 		  strcpy(message, "         ");
	 		  HAL_UART_Transmit(&huart4, overflow, 8, HAL_MAX_DELAY);
	 	  }
	 	  switch (command)
	 	  {
	 	  	  case 'k':
	 	  		  //  k gets the value of weight in kg
	 	  		  itoa(current_weight, response, 10);
	 	  		  HAL_UART_Transmit(&huart4, response, 6, HAL_MAX_DELAY);
	 	  		  break;

	 	  	  case 'l':
	 	  		  // l gets the value of weight in lb
	 	  		itoa(current_weight_lb, response, 10);
	 	  		HAL_UART_Transmit(&huart4, response, 6, HAL_MAX_DELAY);
	 	  		  break;

	 	  }

  }
  /* USER CODE END Tsk_Envio */
}
