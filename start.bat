@echo off
:start
::Server name
set serverName=BoogieNights
::Server files location
set serverLocation="C:\Program Files (x86)\Steam\steamapps\common\DayZServer"
::Server Port
set serverPort=2302
::Server config
set serverConfig=serverDZ.cfg
::Logical CPU cores to use (Equal or less than available)
set serverCPU=2
::Sets title for terminal (DONT edit)
title %serverName% batch
::DayZServer location (DONT edit)
cd "%serverLocation%"
echo (%time%) %serverName% started.
::Launch parameters (edit end: -config=|-port=|-profiles=|-doLogs|-adminLog|-netLog|-freezeCheck|-filePatching|-BEpath=|-cpuCount=)
start "DayZ Server" /min "DayZServer_x64.exe" -config=%serverConfig% -port=%serverPort% "-profiles=config" "-mod=@DayZ-Expansion-Licensed;@DayZ-Expansion-Bundle;@Dabs Framework;@DayZ Editor Loader;@VPPAdminTools;@CF;@SNAFU Weapons;@BaseBuildingPlus;@Dread jordan shoes;@WindstridesClothingPack;@MMG - Mightys Military Gear;@MMG Base Storage NoCodeLock;@BuilderItems;@DayZ-Expansion-Animations;@CJ187-PokemonCards;@MegaFoodPack;@DNA Keycards;@Yuretskiy Creatures;@[LEGACY] AJs Creatures;@BaseBuildingItemStackandRepair;@BulletStacksPlusPlusEnhanced;@AdditionalMedicSupplies;@Cl0ud's Military Gear;@AmmunitionExpansion;@EDO_WEAPONS;@Alevaric's Clothing Overhaul;@DrugsPLUS;@CannabisPlus;@RUSForma_vehicles;@Flag_Pack;@Breachingcharge;@BBP_Vanilla_Dmg;@CodeLock to ExpansionCodeLock Bridge;@Dogtags;@DayZ-Dog" -cpuCount=%serverCPU% -dologs -adminlog -netlog -freezecheck
::Time in seconds before kill server process (14400 = 4 hours)
timeout 14390
taskkill /im DayZServer_x64.exe /F
::Time in seconds to wait before..
timeout 10
::Go back to the top and repeat the whole cycle again
goto start