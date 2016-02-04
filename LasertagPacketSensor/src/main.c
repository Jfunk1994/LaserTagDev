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

/** @addtogroup STM32F3_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup SysTick_Example
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
typedef enum { false, true } bool;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;
static __IO uint32_t TimingDelay;


/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nTime);
int sigConverter(int start, int end);

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
			int gameID;				//Current Game Id
			int time;				//time to game start, values above 30 may be unstable
			int team1PlayerCount;	//Number of players on team 1
			int team2PlayerCount;	//Number of players on team 2
			int team3PlayerCount;	//Number of players on team 3
			int checksum;			//Checksum signature

			gameID=sigConverter(9,16);	//create integer with bits 9-16
			time=sigConverter(17,24);	//create integer with bits 17-24
			team1PlayerCount=sigConverter(25,32); //create integer with bits 25-32
			team2PlayerCount=sigConverter(33,40); //create integer with bits 33-40
			team3PlayerCount=sigConverter(41,48); //create integer with bits 41-48
			checksum=sigConverter(49,57);	//create integer with bits 49-57

			printf("Countdown packet");	//print name of
			printf("Game Id is %i",gameID);		//print the game id
			printf("Time until start is %i",time);	//print the time remaining
			printf("Players on team 1: %i",team1PlayerCount); //Print number of players on team 1
			printf("Players on team 2: %i",team2PlayerCount); //print number of players on team 2
			printf("Players on team 3: %i",team3PlayerCount); //print number of players on team 3

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
			int gameID;				//Current Game Id
			int requestPlayerNum;	//Player number of receiving player
			int requestTeamNum;	//Team number of receiving player
			int checksum;			//Checksum signature

			gameID=sigConverter(9,16);	//create integer with bits 9-16
			requestPlayerNum=sigConverter(17,20);	//create integer with bits 17-20
			requestTeamNum=sigConverter(21,24); //create integer with bits 21-24
			checksum=sigConverter(41,49);	//create integer with bits 25-33

			printf("Request Assistance Packet"); //print packet type
			printf("gameID is: %i",gameID);	//print gameID
			printf("Requesting player's player number is: %i",requestPlayerNum);	//print requesting player's player number
			printf("Requesting player's team number is: %i",requestTeamNum);	//print requesting player's team number
			break;
		}
	 case 33: //0x021 Send assistance
		{
			int gameID;				//Current Game Id
			int receivePlayerNum;				//Player number of receiving player
			int receiveTeamNum;	//Team number of receiving player
			int sendPlayerNum;	//Player number of sending player
			int sendTeamNum;	//Team number of sending player
			int tagsSent;	//Number of tags sent
			int checksum;			//Checksum signature

			gameID=sigConverter(9,16);	//create integer with bits 9-16
			receivePlayerNum=sigConverter(17,20);	//create integer with bits 17-20
			receiveTeamNum=sigConverter(21,24); //create integer with bits 21-24
			sendPlayerNum=sigConverter(25,28); //create integer with bits 25-28
			sendTeamNum=sigConverter(29,32); //create integer with bits 29-32
			tagsSent=sigConverter(33,40); //create integer with bits 33-40
			checksum=sigConverter(41,49);	//create integer with bits 41-49

			printf("Send Assistance Packet"); //print packet type
			printf("gameID is: %i",gameID);	//print gameID
			printf("Requesting player's player number is: %i",receivePlayerNum);	//print requesting player's player number
			printf("Requesting player's team number is: %i",receiveTeamNum);	//print requesting player's team number
			printf("Sending player's team number is: %i",sendPlayerNum);	//print sending player's player number
			printf("Sending player's team number is: %i",sendTeamNum);	//print sending player's team number
			printf("# of tags sent: %i", tagsSent); //print number of tags sent
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
			//ASCII codes dec 32( ), 33(!), 45-6(- & .), 48-58(0-9 & :), 63(?), 65-90(A-Z), 95(_), 126(~)
			//ASCII codes hex
			int nullTerm;			//Null Terminator (0x00)
			int checksum;			//Checksum signature




			checksum=sigConverter(41,49);	//create integer with bits 41-49
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
int sigConverter(int start, int end){

	return 0;
}
/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
