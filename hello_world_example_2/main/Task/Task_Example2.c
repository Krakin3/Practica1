/*! @file Task_Example2.c
 * @brief This file implements the custom message to console example task 2
 *
 * @author A BLUE THING IN THE CLOUD S.L.U.
 *    ===  When the technology becomes art ===
 *
 * http://abluethinginthecloud.com
 * j.longares@abluethinginthecloud
 *
 * (c) A BLUE THING IN THE CLOUD S.L.U.
 *
 *
 *

        ██████████████    ██    ██    ██  ██████    ██████████████
        ██          ██      ████████████████  ██    ██          ██
        ██  ██████  ██  ██████  ██    ██        ██  ██  ██████  ██
        ██  ██████  ██    ██████    ██      ██      ██  ██████  ██
        ██  ██████  ██      ██      ████  ██████    ██  ██████  ██
        ██          ██    ██      ██████    ████    ██          ██
        ██████████████  ██  ██  ██  ██  ██  ██  ██  ██████████████
                        ██████  ████  ██████  ████
        ██████  ██████████  ████    ████████      ████      ██
        ██  ████  ██    ██  ████        ████    ████████  ██    ██
            ██  ██  ████  ██      ██      ██      ██  ████  ██████
        ████  ████    ██      ██          ████  ██  ██        ██
            ██████████          ██      ██    ██  ████    ██  ████
          ██  ████    ██      ██████    ██  ██████████    ██    ██
        ██  ████  ████████████████  ██    ██        ████████  ████
                ████        ██  ██████  ██████████      ████  ██
        ██████  ████████████████    ████  ██    ██████    ██  ████
            ████████  ██████  ██    ██████      ██        ████  ██
        ██    ██  ████████  ██    ██        ██    ██          ████
          ████  ████          ██      ████████████  ██  ████  ██
        ██  ██████  ████  ██    ██      ████    ██████████
                        ██    ██████    ██      ██      ██  ██████
        ██████████████  ██  ██████  ██  ████  ████  ██  ████  ████
        ██          ██  ██      ████████  ██    ██      ████  ████
        ██  ██████  ██  ████  ██    ██████      ██████████    ████
        ██  ██████  ██    ██████    ██  ██  ████      ████  ██████
        ██  ██████  ██  ████      ██    ████  ██        ████    ██
        ██          ██  ██    ██      ██████████████  ██      ██
        ██████████████  ██████  ██        ██  ████    ██████  ████



*/

#include <stdint.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "Task_Example2.h"

#define TASK_EXAMPLE2_SIZE_BUFFER			100

/*! @struct sPresentationMessage
 * @brief Data structure containing presentation struct
 * @typedef tPresentationMessage
 * @brief Data type related to the structure sPresentationMessage
 */
typedef struct sPresentationMessage{
    //! Pointer to the name of the person to be presented
    char *name;
    //! Age of the person
    uint8_t age;
}tPresentationMessage;

//! Buffer used to send data to console
static char bufferToConsole[TASK_EXAMPLE2_SIZE_BUFFER];

/* static functions */
static void Task_Example2( void * pParameters );

/*! This function initialize the task example 2
 *
 */
void Task_Example2_Init( void )
{
	TaskHandle_t taskHandlerConsole = NULL;

	xTaskCreate( Task_Example2, 											\
				 "Task_Example2",											\
				 configMINIMAL_STACK_SIZE * 5,								\
				 NULL, 														\
				 TASK_EXAMPLE2_TASK_PRIORITY, 								\
				 taskHandlerConsole);

}

/*! This function implements the task console
 * @param[in] pParameters Pointer to a struct of the requiered data
 * for this function, if necessary
 */
static void Task_Example2( void * pParameters )
{

	tPresentationMessage myPresentation;

	while(1)
	{

		printf("Task Example 2 says: Hello world!\n");

		myPresentation.name = "Sonia";
		myPresentation.age = 27;

		memset(bufferToConsole, 0, TASK_EXAMPLE2_SIZE_BUFFER);

		sprintf(															\
				bufferToConsole, 											\
				"My name is %s and I am %d years old.\n", 					\
				myPresentation.name, 										\
				myPresentation.age = 27);

		printf(bufferToConsole);

		vTaskDelay( 1000/portTICK_PERIOD_MS );
	}


}
