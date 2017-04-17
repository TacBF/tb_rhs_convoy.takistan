#include "tb_defines.hpp"

zoneList[] =
{
//ID TEAM          	SPAWNTYPE      	LINK        SYNC   	OBJECTS   	DEPEND   	DEPQTY 	ZONE_DESC
{ 0, 0, 			0,    			{}, 		{},     	{0},      	{},      	0,     	},
// You must not link first flags to attacking side's XRAY base for A&D, otherwise game ends after first flag.
{ 1, TEAM_BLUE    , SPAWN_XRAY,     {4,8,9,10}          , {}   	     ,{0}      , {}        , 0    , "USSR Main Base" },
{ 2, TEAM_RED	  , SPAWN_XRAY,     {3,4,5,6}   	, {} 	     ,{0}      , {}        , 0    , "Mujahideen Main Base" },
{ 3, TEAM_BLUE    , SPAWN_NEVER,    {1}  		, {4,5,6,7}	     ,{0}      , {}        , 0    , "HIDDEN" },
{ 4, TEAM_BLUE    , SPAWN_NEVER,    {1}  		, {3,5,6,7}	     ,{0}      , {}        , 0    , "Elevation 2324" },
{ 5, TEAM_BLUE    , SPAWN_NEVER,    {1}  		, {3,4,6,7}	     ,{0}      , {}        , 0    , "HIDDEN" },
{ 6, TEAM_BLUE    , SPAWN_NEVER,    {1}  		, {3,4,5,7}	     ,{0}      , {}        , 0    , "HIDDEN" },
{ 7, TEAM_BLUE    , SPAWN_NEVER,    {}  		, {3,4,5,6}	     ,{0}      , {}        , 0    , "HIDDEN" },
{ 8, TEAM_NEUTRAL    , SPAWN_INSTANT,    {}  		, {}	     ,{0}      , {}        , 0    , "Intersection" },
{ 9, TEAM_NEUTRAL   , SPAWN_INSTANT,    {}  		, {}	     ,{0}      , {}        , 0    , "Feruz Abad Military Base" },
{ 10, TEAM_NEUTRAL   , SPAWN_INSTANT,    {}  		, {}	     ,{0}      , {}        , 0    , "Falar" },
{ 11, TEAM_RED   , SPAWN_LARGEFB,    {}  			, {}	     ,{0}      , {2}        , 1    , "East Camp" },
{ 12, TEAM_RED   , SPAWN_LARGEFB,    {}  			, {}	     ,{0}      , {2}        , 1    , "East Camp" },
};


