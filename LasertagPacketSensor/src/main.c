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
			checksum=sigConverter(49,57);	//create interger with bits 49-57

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
	 case 50: //0x032 Rank Report //Kuzco
		{
			int gameID=0;
			int teamNumber=0;
			int teamRank=0;
			int P1Rank=0;
			int P2Rank=0;
			int P3Rank=0;
			int P4Rank=0;
			int P5Rank=0;
			int P6Rank=0;
			int P7Rank=0;
			int P8Rank=0;
			int checksum=0;
			gameID=sigConverter(9,16);
			teamNumber=sigConverter(17,20);
			teamRank=sigConverter(21,24);
			P1Rank=sigConverter(25,32,);
			P2Rank=sigConverter(33,40);
			P3Rank=sigConverter(41,48);
			P4Rank=sigConverter(49,56);
			P5Rank=sigConverter(57,64);
			P6Rank=sigConverter(65,72);
			P7Rank=sigConverter(73,80);
			P8Rank=sigConverter(81,88);
			checksum=sigConverter(89,97);

			break;
		}
	 case 64: //0x040 Tag Summary
		{
			int gameID=0;
			int teamNumber=0;
			int playerNumber=0;
			int totalTagsRcvd=0;
			int timeSurvivedMinutes=0;
			int timeSurvivedSeconds=0;
			int zoneTimeMinutes=0;
			int zoneTimeSeconds=0;
			int checksum=0;
			gameID=sigConverter(9,16);
			teamNumber=sigConverter(17,20);
			playerNumber=sigConverter(21,24);
			totalTagsRcvd=sigConverter(25,32);
			timeSurvivedMinutes=sigConverter(33,40);
			timeSurvivedSeconds=sigConverter(41,48);
			zoneTimeMinutes=sigConverter(49,56);
			zoneTimeSeconds=sigConverter(57,64);
			//Flags
			//first four are reserved, disregard 65-68
			bool willSendTeam3Report=packet[69];
			bool willSendTeam2Report=packet[70];
			bool willSendTeam1Report=packet[71];
			//72 is also reserved
			checksum=sigConverter(73,81);
			break;
		}
	 case 65: //0x041 Team 1 Tag Report //Kuzco
		{
			readTeamTagReport(1);
			break;
		}
	 case 66: //0x042 Team 2 Tag Report //Kuzco
		{
			readTeamTagReport(2);
			break;
		}
	 case 67: //0x043 Team 3 Tag Report //Kuzco
		{
			readTeamTagReport(3);
			break;
		}
	 case 72: //0x048 Single Tag Report //Kuzco
		{
			int gameID=0;
			int teamNumberA=0;
			int playerNumberA=0;
			int teamNumberB=0;
			int playerNumberB=0;
			int numTagsRcvd=0;
			int checkSum=0;
			gameID=sigConverter(9,16);
			bool replayA=packet[17];
			teamNumberA=sigConverter(18,20)+1;
			playerNumberA=sigConverter(21,24);
			bool replayB=packet[25];
			teamNumberB=sigConverter(26,28)+1;
			playerNumberB=sigConverter(29,32);
			checksum=sigConverter(33,41);

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
int sigConverter(int start, int end){

	return 0;
}
/**
  * @}
  */
void readTeamTagReport(int teamReportNumber){
	int gameID=0;
	int teamNumber=0;
	int playerNumber=0;
	bool player8Included=0;
	bool player7Included=0;
	bool player6Included=0;
	bool player5Included=0;
	bool player4Included=0;
	bool player3Included=0;
	bool player2Included=0;
	bool player1Included=0;
	int NumTagsRcvdFrom1=0;
	int NumTagsRcvdFrom2=0;
	int NumTagsRcvdFrom3=0;
	int NumTagsRcvdFrom4=0;
	int NumTagsRcvdFrom5=0;
	int NumTagsRcvdFrom6=0;
	int NumTagsRcvdFrom7=0;
	int NumTagsRcvdFrom8=0;
	int checksum=0;

	gameID=sigConverter(9,16);
	teamNumber=sigConverter(17,20)+1;
	plaerNumber=(21,24);
	player8Included=packet[25];
	player7Included=packet[26];
	player6Included=packet[27];
	player5Included=packet[28];
	player4Included=packet[29];
	player3Included=packet[30];
	player2Included=packet[31];
	player1Included=packet[32];
	int index=33;
	if(player1Included){
		NumTagsRcvdFrom1=sigConverter(index,index+8); //should be 8 or 7?
		index+=8;
	}
	if(player2Included){
		NumTagsRcvdFrom2=sigConverter(index,index+8);
		index+=8;
	}
	if(player3Included){
		NumTagsRcvdFrom3=sigConverter(index,index+8);
		index+=8;
	}
	if(player4Included){
		NumTagsRcvdFrom4=sigConverter(index,index+8);
		index+=8;
	}
	if(player5Included){
		NumTagsRcvdFrom5=sigConverter(index,index+8);
		index+=8;
	}
	if(player6Included){
		NumTagsRcvdFrom6=sigConverter(index,index+8);
		index+=8;
	}
	if(player7Included){
		NumTagsRcvdFrom7=sigConverter(index,index+8);
		index+=8;
	}
	if(player8Included){
		NumTagsRcvdFrom8=sigConverter(index,index+8);
		index+=8;
	}
	checksum=sigConverter(index,index+9);
}


}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
