/*
 * TskSupervisor.c
 *
 *  Created on: Dec 6, 2021
 *      Author: OMEN
 */

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

#include "HX711.h"
#include "globalVar.h"
void Tsk_Supervisor(void *argument)
{
  /* USER CODE BEGIN Tsk_Supervisor */

  /* Infinite loop */
  for(;;)
  {


	     /*  switch (estadoB){
	  	 case 0 :
	  		 HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12); //prueba con led de la stm (verde)
	  		 osDelay(500);
	  	 case 1:
	  		 HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13); // prueba con led de la stm ( violet)
	  		 osDelay(500);
	  	 case 2:
	  		 HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14); // prueba con led de la stm(ROJO )
	  		 osDelay(500);
*/
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	   osDelay(500);
  }
  /* USER CODE END Tsk_Supervisor */

}
//}
