/**
  ******************************************************************************
  * @file    SysTick_Example/main.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    20-September-2012
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

//#define USE_STDPERIPH_DRIVER 1

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdint.h>

typedef enum { false, true } bool;

/** @addtogroup STM32F3_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup SysTick_Example
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;
static __IO uint32_t TimingDelay;

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nTime);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
int main(void)
{

	//Begin defining packet types

	 bool packet[100];
	 int ptype=0;

//not finished implementing switch structure, currently only a shell
	 switch(ptype)
	 {
	 case 0: //0x000 countdown
		{
			break;
		}
	 case 1: //0x001 Assign Player
		{
			break;
		}
	 case 2: //0x002 Announce Custom Lazer Tag Game
		{
			break;
		}
	 case 3: //0x003 Announce Custom Laser Tag (2 Teams) Game
		{
			break;
		}
	 case 4: //0x004 Announce Custom Lazer Tag (3 Teams) Game
		{
			break;
		}
	 case 5: //0x005 Announce Hide And seek Game
		{
			break;
		}
	 case 6: //0x006 Announce Hunt the Prey Game
		{
			break;
		}
	 case 7: //0x007 Announce Kings (2 Teams) Game
		{
			break;
		}
	 case 8: //0x008 Announce Kings (3 Teams) Game
		{
			break;
		}
	 case 9: //0x009 Announce Own the Zone Game
		{
			break;
		}
	 case 10: //0x00A Announce Own the Zone (2 Teams) Game
		{
			break;
		}
	 case 11: //0x00B Announce Own the Zone (3 Teams) Game
		{
			break;
		}
	 case 12: //0x00C Announce Special Game
		{
			break;
		}
	 case 15: //0x00F Assign Player Fail
		{
			break;
		}
	 case 16: //0x010 Request Join Game
		{
			break;
		}
	 case 17: //0x011 Acknowledge Player Assignment
		{
			break;
		}
	 case 32: //0x020 Request Assistance
		{
			break;
		}
	 case 33: //0x021 Send assistance
		{
			break;
		}
	 case 49: //0x031 Request Tag Report
		{
			break;
		}
	 case 50: //0x032 Rank Report
		{
			break;
		}
	 case 64: //0x040 Tag Summary
		{
			break;
		}
	 case 65: //0x041 Team 1 Tag Report
		{
			break;
		}
	 case 66: //0x042 Team 2 Tag Report
		{
			break;
		}
	 case 67: //0x043 Team 3 Tag Report
		{
			break;
		}
	 case 72: //0x048 Single Tag Report
		{
			break;
		}
	 case 128: //0x080 Text Message
		{
			break;
		}
	 case 144: //0x090 Special Attack
		{
			break;
		}
	 }
	 while(1);

}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
