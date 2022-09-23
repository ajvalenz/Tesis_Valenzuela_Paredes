/*
 * globalVar.c
 *
 *  Created on: Dec 4, 2021
 *      Author: OMEN
 */
#include "globalVar.h"



long lectura;				// variable lectura del HX711
const int escala = 2.212; 		// escala de la balanza
uint8_t veces = 100; 		// obtiene el offset
uint8_t gain = 128; 		// ganancia para la lectura del HX711
int cont; 					// contador
uint8_t promedio; 			//numero de veces de la lectura del peso
signed int  valor; 			// peso del objeto en la balanza en gramos
const int resolucion = 50;		//resolucion del sistema
uint32_t estadoB ;				// estado de la balanza
uint32_t rangoB;				//calcula si el rango de medicion es el correcto

const int resolucionRaw ;
uint32_t true_offset;
uint32_t current_weight;
uint32_t current_weight_lb;
