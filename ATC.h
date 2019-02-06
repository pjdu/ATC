#ifndef _ATC_H
#define _ATC_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include "ATCConfig.h"
#include "usart.h"
#include "cmsis_os.h"

//###################################################################################
typedef struct
{
	uint8_t		*RxData;
	uint8_t		RxTmp;
	uint16_t	RxIndex;
	uint16_t	RxSize;
	uint32_t	RxTime;
	uint8_t		Timeout;
	
}ATC_Buff_t;
//########
typedef struct
{
	uint8_t								ID;
	uint8_t								Busy;
	char									Name[16];
	UART_HandleTypeDef		uart;
	ATC_Buff_t						Buff;	
	char									Answer[_ATC_MAX_SEARCH_PARAMETER_FOR_AT_ANSWER][32];
	uint8_t								AnswerFound;
	
}ATC_t;
//########


//###################################################################################
void		ATC_RxCallBack(ATC_t *atc);
bool		ATC_Init(ATC_t *atc,char	*Name,UART_HandleTypeDef SelectUart,uint16_t	RxSize,uint8_t	Timeout_Package,osPriority Priority);

void		ATC_TransmitString(ATC_t *atc,char *Buff);
uint8_t	ATC_Send(ATC_t *atc,char *AtCommand,uint32_t Wait_ms,...);

//###################################################################################

#endif