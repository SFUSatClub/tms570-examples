/*
 * SFUTasks.h
 *
 *  Created on: Feb 17, 2017
 *      Author: Richard
 */

#ifndef SFUSAT_SFUTASKS_H_
#define SFUSAT_SFUTASKS_H_
#include "FreeRTOS.h"
#include "os_task.h"
#include "os_queue.h"
#include "gio.h"
#include "sys_common.h"
#include "SFU_Serial.h"

QueueHandle_t xQueue;


void hundredBlinky(void *pvParameters);
void vTask2(void *pvParameters);

// RTOS queue example
void vSenderTask( void *pvParameters );
void vReceiverTask( void *pvParameters );


#endif /* SFUSAT_SFUTASKS_H_ */
