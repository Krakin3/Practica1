/*! @file Task_Example3.c
 * @brief This file implements the example task 3 and includes
 * the use of a queue in freeRTOS
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
#include "Task_Example3.h"

//! Size of buffer used to send data to console in task 3
#define TASK_EXAMPLE3_SIZE_BUFFER			100

//! Handler of the console queue
QueueHandle_t queueConsole;
//! Queue structure used to send console data
static 	tQueueParameters readData;
//! Buffer used to send data to console
static char bufferToConsole[TASK_EXAMPLE3_SIZE_BUFFER];

/* static functions */
static void Task_Example3( void * pParameters );

/*! This function initialize the task example 3 and its queue
 *
 */
void Task_Example3_Init( void )
{
	TaskHandle_t taskHandlerConsole = NULL;

	queueConsole = xQueueCreate( TASK_EXAMPLE3_MAX_LENGTH_OF_QUEUE_CONSOLE, \
									 sizeof( tQueueParameters));

	if( NULL == queueConsole){
		ESP_LOGE("Task_Console: ", "Console queue was not created");
	};

	xTaskCreate( Task_Example3, 											\
				 "Task_Example3",											\
				 configMINIMAL_STACK_SIZE * 5,								\
				 NULL, 														\
				 TASK_EXAMPLE3_TASK_PRIORITY, 								\
				 taskHandlerConsole);

}

/*! This function implements the task example 3
 * @param[in] pParameters Pointer to a struct of the requiered data
 * for this function, if necessary
 */
static void Task_Example3( void * pParameters )
{

	while(1)
	{
		if( xQueueReceive( queueConsole, 									\
						   &readData,										\
						   ( TickType_t ) 100) == pdPASS)
		{
			memset(bufferToConsole, 0, TASK_EXAMPLE3_SIZE_BUFFER);
			memcpy(															\
					bufferToConsole, 										\
					readData.pQueueData, 									\
					readData.lengthQueueData);

			printf(bufferToConsole);

		}


		vTaskDelay( 1000/portTICK_PERIOD_MS );
	}
}

/*! This function send the data to the queueConsole
 * @param[in] pData Pointer to the data to be sent to the queue
 * @return 1 if correct, 0 if error
 */
uint8_t Task_Example3_Send_Data( tQueueParameters * queueParameters )
{

	if( NULL == queueParameters->pQueueData ){
		return 0;
	}

	if( queueParameters->lengthQueueData >= TASK_EXAMPLE3_SIZE_BUFFER)
	{
		return 0;
	}

	if( xQueueSend( queueConsole,											\
					queueParameters,										\
					( TickType_t ) 10) == pdPASS ){
		return 1;
	}else{
		return 0;
	}
}
