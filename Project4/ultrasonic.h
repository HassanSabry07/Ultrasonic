/*
 ================================================================================================
 Module		 : ULTRASONIC

 Name        : ultrasonic.h

 Author      : Hassan Sabry Ahmed Shahin

 Description : header file for ULTRASONIC

 Date        : Apr 20, 2023
 ================================================================================================
 */


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Ultrasonic trigger HW Ports and Pins Ids */
#define ULTRASONIC_TRIGGER_PORT_ID                 PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID                  PIN5_ID


#define ULTRASONIC_NUM_OF_EDGES               		2

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initialize the ultrasonic drive by:
 *Initialize the ICU driver as required.
 *Initialize  Setup the ICU call back function.
 *Initialize the trigger pin direction.
 */
void Ultrasonic_init(void);


/*
 * Description:
 * Send the Trigger pulse to the ultrasonic.
 */
void Ultrasonic_Trigger(void);


/*
 * Description:
 *Send the trigger pulse by using Ultrasonic_Trigger function.
 *Send Start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_readDistance(void);


/*
 * Description:
 * This is the call back function called by the ICU driver.
 * This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
