class ICE
{
    class vehicles
  {
        class optics
        {
	  enableTIEquipment = 0;
        }; 
        class armaments
        {
            startFullyRearmed = 1;
        };
    }
   class assets
   {
      class FO
      {
         maxAllowed = 10;
      };
      class SRP
      {
         maxAllowed = 10;
      };
      class HO
      {
         maxAllowed = 10;
      };
      class TRP
      {
         maxAllowed = 30;
      };
   };
  class zones
  {
    #include "zoneList.hpp"
  };
  class firstAid
  {
    bleedoutTimeSteps[] = {200, 100, 0}; // Controls the bleedout time steps
    bleedoutTimeReset = 300; // Controls the time that you should go incapped within to go down a step. 2 * this time takes you a step back up.
  };
  class mission
  {
    gameMode = "A&S";
    missionScale = "large";
    recommendedTotalPlayers = 50;
    //attackingSide = "east"; // required for A&D
	
         class briefings {
            class west { original = "briefing_blue.hpp"; };
            class east { original = "briefing_red.hpp"; };
        };

		class factions // or sides
		{
			class faction
			{
				bluFor = "BLU_F";
				opFor = "OPF_G_F";
			};
			class teamName
			{
				bluFor = "USSR";
				opFor = "Mujahideen";
			};
			class teamFlag
			{
				bluFor = "flags\flag_ussr_co.paa"; // "flags" is a sub-folder in mission folder
				opFor = "\ice\ice_main\Images\flags\Taliban.paa";
			};
		};
    class scoring
    {
      class tickets
      {
        // In A&D, specify the tickets per zone. It is usually a 7:5 ratio, for attackers/defenders respectively.
        bluFor = 70; // "_rate" is dependent on the "missionScale".
        opFor = 40;
      };
    };
  };
  class respawn
  {
    class FO
    {
      minSpacingDist = 400;
      maxFriendlySiteDist = 1500;
      //minZoneDist = 0;
      minEnemyFBDist = 400;
      minEnemyBaseDist = 600;
    };
    class SRP
    {
      maxFriendlySiteDist = 0;
     // minEnemyFBDist = 2500;
      //minEnemyBaseDist = 600;
      //minSpacingDist = 10;
      //minZoneDist = 2500;
    };
    class HO
    {
      minSpacingDist = 2000;
      maxFriendlySiteDist = 2500;
    };
		class infantry
		{
			baseDuration = 40;
			class unevenTeamsPenaltyTime
			{
				ratioDuration = 60; // "pivot value" where low player count differences result in small time penalties, 
				// but large differences result in exponential time penalties
				maxDuration = 240;
			};
		};
 class vehicles
		{
            class respawnDelay
			{
                multiplier = 1;
            };
        };
  };
  class gameModes
  {
    class objectives
    {
      class zones
      {
        class captureRates
        {
          // Eg: A higher value (eg: 2 to 3) is ideal for smaller missions.
          heldZoneMultiplier = 1; // Decimal value between 0 and N. (> 0, < 1 will reduce capture rate), (> 1 will increase capture rate). Eg: 0.25, 0.5, 0.75, 1.0, 1.25, 1.5

          // This value is a cumulative multiplier with 'captureRateMultiplier'. (So if captureRateMultiplier == 2 and neutralZoneCaptureRateMultiplier == 3, then overall rate is 6 times faster.)
          // Eg: A value of 2 is ideal for missions which have very few neutral zones at the start.
          // Eg: A high value (eg: 3 to 6) is ideal for missions which have many neutral zones at the start or for smaller missions.
          neutralZoneMultiplier = 10; // Decimal value between 0 and N. (> 0, < 1 will reduce capture rate), (> 1 will increase capture rate)

          negateNeutral = 1; // set to 1 to make both Multipliers totally independent, not a "cumulative multiplier".
        
		  delayedActivation = 0;
		};
      };
    };
    class AAS
    {
      class ticketBleedRate
      {
        bluFor = 0;
        opFor = 0;
      };
			class ticketLossForLosingZone
			{
				// specify the tickets lost for losing a zone. It is usually the same for both sides.
				// Typically, for each mission size, it would be around [-5,-10,-15,-20,-25]
				// Note: value can be positive or negative here, but absolute value will be subtracted when used.
				bluFor = 0;
				opFor = 0;
			};
		};
    };
    class gear
    {
        #include "tb_kitDefines.sqh" // Unconfirmed. These files might need to be copied local to mission.
        #include "tb_magazineExclusions.hpp"
	    class NVGogglesForAll
        {
            west = 0;
            east = 0;
            resistance = 0;
            civilian = 0;
        };
    class roles
    {
      #define __unlimited -99
      kits[] =
      {
        // BLUFOR or ALL factions
        {
          // {id, caption, ratio, minimum, minTeamSize, minSquadSize}
          {__ICE_gear_Rifleman, "Rifleman", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Grenadier, "Grenadier", 5, 0, 0, 2, 3},
          {__ICE_gear_MG, "MG", 5, 0, 0, 2, 3},
          {__ICE_gear_Medic, "Medic", 4, 3, 0, 2, 3},
          {__ICE_gear_CombatEngineer, "Combat Engineer", 5, 1, 0, 2, 3},
          {__ICE_gear_LightAT, "Light AT", 5, 1, 0, 2, 3},
          {__ICE_gear_HeavyAT, "Heavy AT", 0, 0, 0, 2, 3},
          {__ICE_gear_AA, "Anti-Air", 0, 0, 0, 0, 0},
          {__ICE_gear_Marksman, "Marksman", 12, 0, 0, 2, 3},
          {__ICE_gear_Sniper, "Sniper", 16, 0, 0, 2, 3},
          {__ICE_gear_SL, "Squad Leader", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Crewman, "Crewman", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Pilot, "Pilot", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Diver, "Political Commissar", 0, 0, 0, 0, 0}
                },
                // OPFOR (delete OPFOR array or leave OPFOR array empty, to re-use (copy) BLUFOR array for both sides)
                {
          // {id, caption, ratio, minimum, minTeamSize, minSquadSize}
          {__ICE_gear_Rifleman, "Rifleman", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Grenadier, "Grenadier", 6, 0, 0, 2, 3},
          {__ICE_gear_MG, "MG", 6, 0, 0, 2, 3},
          {__ICE_gear_Medic, "Medic", 4, 3, 0, 2, 3},
          {__ICE_gear_CombatEngineer, "Combat Engineer", 5, 0, 0, 2, 3},
          {__ICE_gear_LightAT, "Light AT", 0, 6, 0, 2, 3},
          {__ICE_gear_HeavyAT, "Heavy AT", 0, 3, 0, 2, 3},
          {__ICE_gear_AA, "Anti-Air", 0, 0, 0, 0, 0},
          {__ICE_gear_Marksman, "Marksman", 12, 0, 0, 2, 3},
          {__ICE_gear_Sniper, "Sniper", 16, 0, 0, 2, 3},
          {__ICE_gear_SL, "Squad Leader", __unlimited, 0, 0, 0, 0},
          {__ICE_gear_Crewman, "Crewman", 0, 0, 0, 0, 0},
          {__ICE_gear_Pilot, "Pilot", 0, 0, 0, 0, 0},
          {__ICE_gear_Diver, "CIA Operative", 0, 0, 0, 0, 0}
        };
      };
    };
    class armaments
    {
        
      class BLU_F
      {
        defaultGear = "factions\BLU_F.sqh";
        #include "factions\_common_smallItems.sqh"
        #include "factions\BLU_F_gear.sqh"
        #include "factions\BLU_F_uniforms.sqh"
      };
      class OPF_G_F
      {
        defaultGear = "factions\OPF_G_F.sqh";
        #include "factions\_common_smallItems.sqh"
        #include "factions\OPF_G_F_gear.sqh"
        #include "factions\OPF_G_F_uniforms.sqh"
      };
    };
  };
};