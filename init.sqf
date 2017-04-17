#include "\ice\tb_main\sys\gameModes\aas_init.sqf"

#define __BLEED_01 40
#define __BLEED_02 30
#define __INDEX_01 [4]
#define __INDEX_02 [3,5,6]
if (isServer) then {

	/*---------------------------------------------------------------------------
		Set bleed per zone at round start
	---------------------------------------------------------------------------*/
	[] spawn {
		waitUntil {sleep 0.5; !(isNil "TB_server_triggers")};
		{
			if (_forEachIndex in __INDEX_01) then {
				_zoneTrigger = [_forEachIndex] call TB_zones_fnc_getZoneTrigger;
				_zoneTrigger setVariable ["TB_zoneBleed", __BLEED_01, true];
			} else {
				if (_forEachIndex in __INDEX_02) then {
					_zoneTrigger = [_forEachIndex] call TB_zones_fnc_getZoneTrigger;
					_zoneTrigger setVariable ["TB_zoneBleed", 0, true];
				};
			};
		} forEach TB_server_triggers;
	};


	/*---------------------------------------------------------------------------
		This is required because custom bleed per zone is not side dependent. Want to make sure BLUFOR never gets value on their zones
	---------------------------------------------------------------------------*/
	_fnc_updateZoneBleed = {
		params ["_zoneIndex", "_newOwner"];
		_zoneTrigger = [_zoneIndex] call TB_zones_fnc_getZoneTrigger;

		/*---------------------------------------------------------------------------
			Remove the bleed from ambush zones when blufor captures them
		---------------------------------------------------------------------------*/
		if (_zoneIndex in __INDEX_01) exitWith {
			_newOwner = param [1, sideUnknown];
			if (_newOwner == west) then {
				_zoneTrigger setVariable ["TB_zoneBleed", 0, true];
			};
		};

		/*---------------------------------------------------------------------------
			Make sure the vehicle zones only get bleed after OPFOR captured them
		---------------------------------------------------------------------------*/
		if (_zoneIndex in __INDEX_02) exitWith {
			_newOwner = param [1, sideUnknown];
			if (_newOwner == east) then {
				_zoneTrigger setVariable ["TB_zoneBleed", __BLEED_02, true];
			};
		};
	};
	[missionNamespace, "onZoneCapture", _fnc_updateZoneBleed] call BIS_fnc_addScriptedEventHandler;
};

[] spawn {
	sleep 10;
	TB_rules_FO_minZoneDist = 0;
	TB_rules_FO_minEnemyZoneDist = 100;
};


//[(call TFAR_fnc_activeLrRadio) select 0, (call TFAR_fnc_activeLrRadio) select 1, "55.5"] call TFAR_fnc_setLrFrequency;

// LR
//_frequencies = [1,99,99,1] call TFAR_fnc_generateFrequencies;
//[(call TFAR_fnc_activeLrRadio), 1, "55.5"] call TFAR_fnc_SetChannelFrequency;

//tf_same_lr_frequencies_for_side
//tf_freq_west_lr
//TFAR_fnc_generateLrSettings