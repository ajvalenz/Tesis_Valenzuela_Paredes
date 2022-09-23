/*
 * TskMeassurment.c
 *
 *  Created on: Dec 4, 2021
 *      Author: OMEN
 */

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

#include "HX711.h"
#include "globalVar.h"


void Tsk_Measurements(void *argument)
{
  /* USER CODE BEGIN Tsk_Measurements */

	power_down();
	HAL_Delay(10);
	power_up();
	begin(gain);
	set_scale(escala);// SETEA LA GANANCIA DEL SISTEMA
	tare(veces);//OFFSET
	promedio = 10;

  /* Infinite loop */
  for(;;)
  {
  lectura= read();
  cont++;
  valor= get_units(promedio);			// obtencion del peso

	 	     if(valor>(0-resolucion) && valor<(resolucion)){
	 	  		  estadoB= 0; // la balanza esta vacia y actualizando el offset
	 	  		  true_offset = valor;
	 	  	  }
	 	  	  else if( valor> (0-resolucion) && valor<(200000+resolucion)){
	 	  		  estadoB = 1 ;// se conoce que esta pesando un objeto dentro de rango adecuado
	 	  	  	  current_weight = valor - true_offset;
	 	  	  	  current_weight_lb = (current_weight*2.2);
	 	  	  }
	 	  	  else if((valor>200000+resolucion)||(valor<0-resolucion)){
	 	  	  //else >300+resolucion <0-resolucion
	 	  	  //sobrepeo o esta desconectada o CC
	 	  	  estadoB = 2 ;

	 	  	  }


	  //HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	 	  osDelay(500);
  }
  /* USER CODE END Tsk_Measurements */
}
