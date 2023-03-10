/*! @file Task_Data.c
 * @brief This file implements teh tasks that gets custom data and
 * sends it to console
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
#include "Task_Data.h"
#include "Task_Example3.h"

//! Size of buffer used to send data to console
#define TASK_DATA_BUFFER_SIZE			100


//! This variable stores the parameters to be sent to queue in  task 3
static tQueueParameters queueParametersTaskData;
//! Buffer to store data to be sent to queue
static char bufferToQueue[TASK_DATA_BUFFER_SIZE];

/* static functions */
static void Task_Data( void * pParameters );

/*! This function initialize the task example 1
 *
 */
void Task_Data_Init( void )
{
	TaskHandle_t taskHandlerConsole = NULL;

	xTaskCreate( Task_Data, 												\
				 "Task_Data",												\
				 configMINIMAL_STACK_SIZE * 5,								\
				 NULL, 														\
				 TASK_DATA_TASK_PRIORITY, 									\
				 taskHandlerConsole);

}

/*! This function implements the task data to console
 * @brief
 * @param[in] pParameters Pointer to a struct of the requiered data
 * for this function, if necessary
 */
static void Task_Data( void * pParameters )
{

	while(1)
	{

		memset(bufferToQueue, 0, TASK_DATA_BUFFER_SIZE);
		sprintf(															\
				bufferToQueue, 												\
				"This is the information sent to queue in Task 3.\n");

		queueParametersTaskData.pQueueData = (uint8_t *)bufferToQueue;
		queueParametersTaskData.lengthQueueData = 							\
				strnlen(bufferToQueue, TASK_DATA_BUFFER_SIZE);

		Task_Example3_Send_Data(&queueParametersTaskData);

		vTaskDelay( 5000/portTICK_PERIOD_MS );
	}


}
