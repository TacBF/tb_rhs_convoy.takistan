// SU - Army (M88)
// Author: Cole

class TB_BLUBasicAmmunitionBox
{
	transportClear = 1;
	proxyObject = "TB_BLUBasicAmmunitionBox";
	class transportCargo
	{
		transportMagazines[] = {
			{"rhs_30Rnd_762x39mm", 20},
			{"rhs_10Rnd_762x54mmR_7N1", 10},
			{"rhs_100Rnd_762x54mmR", 5},
			{"SmokeShell", 10},
			{"rhs_mag_rgd5", 10},
			{"rhs_VOG25", 10},
			{"rhs_rpg7_PG7VL_mag", 2},
			{"DemoCharge_Remote_Mag", 4}
		};
		transportWeapons[] = {{"rhs_weap_rsp30_red", 10}, {"rhs_weap_akm",2}};
		//transportBackpacks[] = {};
		//transportItems[] = {};
	};
};
class TB_Box_West_Mines_F
{
	transportClear = 1;
	proxyObject = "TB_Box_West_Mines_F";
	class transportCargo
	{
		transportMagazines[] = {
			{"rhs_mine_tm62m_mag", 2},
			{"SLAMDirectionalMine_Wire_Mag", 0},
			{"rhs_mine_pmn2_mag", 6},
			{"APERSBoundingMine_Range_Mag", 0},
			{"APERSTripMine_Wire_Mag", 2},
			{"ClaymoreDirectionalMine_Remote_Mag", 2}
		};
		//transportWeapons[] = {};
		transportBackpacks[] = {{"rhs_sidor", 2}};
		transportItems[] = {{"MineDetector", 2}, {"ToolKit", 1}};
	};
};