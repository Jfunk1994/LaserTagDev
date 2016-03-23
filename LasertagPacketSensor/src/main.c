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
bool packet[100];

/* Private function prototypes -----------------------------------------------*/
int sigConverter(int start, int end);
char ToDecimal(char);
/*
 * The least significant bit of each packet is sent first
 * Thus, the first bit of each packet is the least significant of the corresponding integer
 *
 */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	while(1)
	{
	//Begin defining packet types

	 int ptype=sigConverter(0,8);

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
			printf("Time until start is %i",(int)ToDecimal((char)time));	//print the time remaining
			printf("Players on team 1: %i",team1PlayerCount); //Print number of players on team 1
			printf("Players on team 2: %i",team2PlayerCount); //print number of players on team 2
			printf("Players on team 3: %i",team3PlayerCount); //print number of players on team 3

			break;
		}
	 case 1: //0x001 Assign Player
		{
			int gameID;		// Current game ID
			int taggerID;	// Tagger ID
			int flags;		// Flags
			int checksum;	// Checksum

			gameID=sigConverter(9,16);
			taggerID=sigConverter(17,24);
			flags=sigConverter(25,32);
				int teamPlrNum=sigConverter(28,32);
			checksum=sigConverter(33,41);

			printf("Assign Player Packet");
			printf("Game ID is %i", gameID);
			printf("Tagger ID is %i", taggerID);
			printf("Packed Team and Player Number is %i", teamPlrNum);
			break;
		}
	 case 2: //0x002 Announce Custom Lazer Tag Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 3: //0x003 Announce Custom Laser Tag (2 Teams) Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 4: //0x004 Announce Custom Lazer Tag (3 Teams) Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 5: //0x005 Announce Hide And seek Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 6: //0x006 Announce Hunt the Prey Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 7: //0x007 Announce Kings (2 Teams) Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 8: //0x008 Announce Kings (3 Teams) Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 9: //0x009 Announce Own the Zone Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 10: //0x00A Announce Own the Zone (2 Teams) Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 11: //0x00B Announce Own the Zone (3 Teams) Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);


			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);

			numTeams = sigConverter(71, 72);
			checksum=sigConverter(73,81);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);

			break;
		}
	 case 12: //0x00C Announce Special Game
		{
			int gameID;		// Current game ID
			int gameLength;	// Game length in minutes
			int tags;		// Amount of tags allocated to taggers
			int reloads;	// Amount of reloads
			int shields;	// Amount of shields allocated to taggers
			int megas;		// Amount of mega-tags allocated to taggers
			int numTeams;	// Number of teams
			int gameName;   // Name of the game
			int checksum; 	// Checksum

			gameID=sigConverter(9,16);
			gameLength=sigConverter(17,24);
			tags=sigConverter(25,32);
			reloads=sigConverter(33,40);
			shields=sigConverter(41,48);
			megas=sigConverter(49,56);

			int neut10 = sigConverter(57, 57);
			int limReloads = sigConverter(58, 58);
			int limMegs = sigConverter(59, 59);
			int teamTags = sigConverter(60, 60);
			int medicMode = sigConverter(61, 61);
			int slowTags = sigConverter(62, 62);
			int huntPrey = sigConverter(63, 63);
			int huntDir = sigConverter(64, 64);

			int contZones = sigConverter(65, 65);
			int teamAssociated = sigConverter(66, 66);
			int neut15 = sigConverter(67, 67);
			int supplyUnNeut = sigConverter(68, 68);
			int supplyRefill = sigConverter(69, 69);
			int hostile = sigConverter(70, 70);
			numTeams = sigConverter(71, 72);
			gameName = sigConverter(73, 104);
			checksum=sigConverter(105,113);

			printf("Announce Custom Game Packet");
			printf("Game ID is %i", gameID);
			printf("Game Length = %i", gameLength);
			printf("#Tags =  %i", tags);
			printf("#Reloads = %i", reloads);
			printf("#Shields = %i", shields);
			printf("#Megas = %i", megas);


			// Flags
			if (neut10)
				printf("10 Tag Neutralization");
			if (limReloads)
				printf("Limited Reloads");
			if (limMegs)
				printf("Limited Mega Tags");
			if (teamTags)
				printf("Team Tags");
			if (medicMode)
				printf("Medic Mode");
			if (slowTags)
				printf("Max of 1 tag / second");
			if (huntPrey)
				printf("Hunt the Prey Activated");
			if (huntDir)
					printf("Team 2 hunts first");
				else
					printf("Team 1 hunts first");
			if (contZones)
				printf("Contested Zones Activated");
			if (teamAssociated)
				printf("Zones are associated with teams");
			if (neut15)
				printf("15 Second Neutralization when tagged");
			if (supplyUnNeut)
				printf("Supply Zones Un-neutralize players");
			if (supplyRefill)
				printf("Supply Zones Refill Tags");
			if (hostile)
				printf("Hostile Zones Activated");

			printf("The number of teams is %i", numTeams);
			printf("The game name is %i", gameName);
			break;
		}
	 case 15: //0x00F Assign Player Fail
		{
			int gameID; // Game ID
			int taggerID; // Tagger ID
			int checksum; // Checksum

			gameID=sigConverter(9,16);
			taggerID=sigConverter(17,24);
			checksum=sigConverter(25,33);

			printf("Assign Player Fail Packet");
			printf("Game ID is %i", gameID);
			printf("Tagger ID is %i", taggerID);
			break;
		}
	 case 16: //0x010 Request Join Game
		{
			int gameID;
			int taggerID;
			int teamPreferred;
			int checkSum;

			gameID=sigConverter(9,16);	// game ID
			taggerID = sigConverter(17, 24); // tagger ID
			teamPreferred = sigConverter(31, 32); // Preferred team (0 if no preference)
			checkSum = sigConverter(33, 41); // checksum

			printf("gameID is: %i",gameID);	//print gameID
			printf("Tagger ID is: %i", taggerID); // print tagger ID
			printf("Preferred team is %i", teamPreferred); // print preferred team

			break;
		}
	 case 17: //0x011 Acknowledge Player Assignment
		{
			int gameID; // Game ID
			int taggerID; // Tagger ID
			int checksum; // Checksum

			gameID=sigConverter(9,16);
			taggerID=sigConverter(17,24);
			checksum=sigConverter(25,33);

			printf("Acknowledge Player Assignment Packet");
			printf("Game ID is %i", gameID);
			printf("Tagger ID is %i", taggerID);
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
			int gameID;
			int teamNum;
			int playerNum;
			int team3Request;
			int team2Request;
			int team1Request;
			int tagSummaryRequest;
			int checkSum;

			gameID = sigConverter(9, 16);
			teamNum = sigConverter(17, 20);
			playerNum = sigConverter(21, 24);
			team3Request = sigConverter(29, 29);
			team2Request = sigConverter(30, 30);
			team1Request = sigConverter(31, 31);
			tagSummaryRequest = sigConverter(32, 32);
			checkSum = sigConverter(33, 41);

			printf("gameID is: %i",gameID);
			printf("Team Number is: %i",teamNum);
			printf("Player Number is: %i",playerNum);
			if (team3Request)
				printf("Request team 3 tag report");
			if (team2Request)
				printf("Request team 2 tag report");
			if (team1Request)
				printf("Request team 1 tag report");
			if (tagSummaryRequest)
				printf("Request Tag Summary");
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
			P1Rank=sigConverter(25,32);
			P2Rank=sigConverter(33,40);
			P3Rank=sigConverter(41,48);
			P4Rank=sigConverter(49,56);
			P5Rank=sigConverter(57,64);
			P6Rank=sigConverter(65,72);
			P7Rank=sigConverter(73,80);
			P8Rank=sigConverter(81,88);
			checksum=sigConverter(89,97);
			printf("game ID: %i", gameID);
			printf("team number: %i", teamNumber);
			printf("team rank: %i", teamRank);
			printf("player 1 rank: %i", P1Rank);
			printf("player 2 rank: %i", P2Rank);
			printf("player 3 rank: %i", P3Rank);
			printf("player 4 rank: %i", P4Rank);
			printf("player 5 rank: %i", P5Rank);
			printf("player 6 rank: %i", P6Rank);
			printf("player 7 rank: %i", P7Rank);
			printf("player 8 rank: %i", P8Rank);
			printf("Checksum: %i", checksum);

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
			printf("Game ID: %i", gameID);
			printf("Team Number: %i", teamNumber);
			printf("Player Number: %i", playerNumber);
			printf("Total Tags received: %i", totalTagsRcvd);
			printf("Time survived minutes: %i", timeSurvivedMinutes);
			printf("Time survived seconds: %i", timeSurvivedSeconds);
			printf("Zone Time Minutes: %i", zoneTimeMinutes);
			printf("Zone Time Seconds: %i", zoneTimeSeconds);
			printf("Checksum: %i", checksum);
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
			int checksum=0;
			gameID=sigConverter(9,16);
			bool replyA=packet[17];
			teamNumberA=sigConverter(18,20)+1;
			playerNumberA=sigConverter(21,24);
			bool replyB=packet[25];
			teamNumberB=sigConverter(26,28)+1;
			playerNumberB=sigConverter(29,32);
			checksum=sigConverter(33,41);
			printf("Game ID : %i", gameID);
			printf("Team Number A : %i",teamNumberA);
			printf("Player Number A : %i",playerNumberA);
			printf("Team Number B : %i",teamNumberB);
			printf("Player Number B : %i",playerNumberB);
			printf("Number of Tags Received : %i",numTagsRcvd);
			printf("Checksum : %i",checksum);

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
	 default:
	 	 {
	 		 break;
	 	 }
	 }

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
	playerNumber=(21,24);
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
		NumTagsRcvdFrom1=sigConverter(index,index+7); //should be 7 I think
		index+=8;
	}
	if(player2Included){
		NumTagsRcvdFrom2=sigConverter(index,index+7);
		index+=8;
	}
	if(player3Included){
		NumTagsRcvdFrom3=sigConverter(index,index+7);
		index+=8;
	}
	if(player4Included){
		NumTagsRcvdFrom4=sigConverter(index,index+7);
		index+=8;
	}
	if(player5Included){
		NumTagsRcvdFrom5=sigConverter(index,index+7);
		index+=8;
	}
	if(player6Included){
		NumTagsRcvdFrom6=sigConverter(index,index+7);
		index+=8;
	}
	if(player7Included){
		NumTagsRcvdFrom7=sigConverter(index,index+7);
		index+=8;
	}
	if(player8Included){
		NumTagsRcvdFrom8=sigConverter(index,index+7);
		index+=8;
	}
	checksum=sigConverter(index,index+8);
	printf("Team number : %i",teamNumber);
	printf("Player Number : %i",playerNumber);
	printf("NumTagsRcvdFrom1 : %i",NumTagsRcvdFrom1);
	printf("NumTagsRcvdFrom2 : %i",NumTagsRcvdFrom2);
	printf("NumTagsRcvdFrom3 : %i",NumTagsRcvdFrom3);
	printf("NumTagsRcvdFrom4 : %i",NumTagsRcvdFrom4);
	printf("NumTagsRcvdFrom5 : %i",NumTagsRcvdFrom5);
	printf("NumTagsRcvdFrom6 : %i",NumTagsRcvdFrom6);
	printf("NumTagsRcvdFrom7 : %i",NumTagsRcvdFrom7);
	printf("NumTagsRcvdFrom8 : %i",NumTagsRcvdFrom8);
	printf("Checksum : %i",checksum);
}

/*
 * ** bounds are inclusive
 * subject to change based on order of MSB or LSB stored, read
 */

char ToDecimal(char bcd)
{
	if (bcd == 0xff) return bcd;
	return (((bcd >> 4) & 0xf) * 10) + (bcd & 0xf);
}

char ToBinaryCodedDecimal(char dec)
{
	if (dec == 0xff) return dec;
	return (char)(((dec / 10) << 4) | (dec % 10));
}

int sigConverter(int start, int end){
	int returnValue=0;
	int i=start;
	while( i<=end ){
		//enum makes implicit conversion of true/false to 1/0
		returnValue ^= (-packet[i] ^ returnValue) & (1 << i-start); //found on http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c-c
		i++;
	}
	return returnValue;

}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
