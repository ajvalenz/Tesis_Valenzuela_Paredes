/*
 * globalVar.h
 *
 *  Created on: Nov 17, 2021
 *      Author: OMEN
 */

#ifndef INC_GLOBALVAR_H_
#define INC_GLOBALVAR_H_

#include "stm32f4xx_hal.h"

extern long lectura;				// variable lectura del HX711
extern const int escala; 		// escala de la balanza
extern uint8_t veces; 		// obtiene el offset
extern uint8_t gain; 		// ganancia para la lectura del HX711
extern int cont; 					// contador
extern uint8_t promedio; 			//numero de veces de la lectura del peso
extern signed int  valor; 			// peso del objeto en la balanza en gramos
extern const int resolucion;		//resolucion del sistema
extern uint32_t estadoB ;				// estado de la balanza
extern uint32_t rangoB;				//calcula si el rango de medicion es el correcto
extern const int resolucionRaw ;
extern uint32_t true_offset;
extern uint32_t current_weight;
extern uint32_t current_weight_lb;

#endif /* INC_GLOBALVAR_H_
*/
