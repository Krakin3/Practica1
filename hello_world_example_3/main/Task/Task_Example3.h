/*! @file Task_Example3.c
 * @brief This file implements the header of example task 3
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

#ifndef __TASK_EXAMPLE3_H_
#define __TASK_EXAMPLE3_H_

//! Max length of the queue
#define TASK_EXAMPLE3_MAX_LENGTH_OF_QUEUE_CONSOLE 		10
//! Priority of task example 3
#define TASK_EXAMPLE3_TASK_PRIORITY 					0

/*!@struct sQueuParameters
 * @brief Structure with the data to be sent and its length
 * @typedef tQueueParameters
 * @brief Data type related to the struct sQueueParameters
 */
typedef struct sQueueParameters{
	//! Pointer to the data to be sent
	uint8_t * pQueueData;
	//! Length of the data to be sent
	uint16_t lengthQueueData;
}tQueueParameters;

/*! This function initialize the task example 3 and its queue
 * @return Handler of the task
 */
void Task_Example3_Init( void );

/*! This function send the data to the queueConsole
 * @param[in] pData Pointer to the data to be sent to the queue
 * @return 1 if correct, 0 if error
 */
uint8_t Task_Example3_Send_Data( tQueueParameters * queueParameters );


#endif /* __TASK_EXAMPLE3_H_ */
