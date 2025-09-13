void main()
{
    //INIT WEATHER BEFORE ECONOMY INIT------------------------
    Weather weather = g_Game.GetWeather();

    weather.MissionWeather(false);    // false = use weather controller from Weather.c

    weather.GetOvercast().Set(Math.RandomFloatInclusive(0.02, 0.1), 1, 0);
    weather.GetRain().Set(0, 1, 0);
    weather.GetFog().Set(0, 1, 0);

    //INIT ECONOMY--------------------------------------
    Hive ce = CreateHive();
    if (ce)
        ce.InitOffline();

    //DATE RESET AFTER ECONOMY INIT-------------------------
    int year, month, day, hour, minute;
    int reset_month = 9, reset_day = 20;
    GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if ((month == reset_month) && (day < reset_day))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
    else
    {
        if ((month == reset_month + 1) && (day > reset_day))
        {
            GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
        }
        else
        {
            if ((month < reset_month) || (month > reset_month + 1))
            {
                GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
            }
        }
    }
}

class CustomMission: MissionServer
{
    // --- WHITELIST ARRAYS ---
    ref array<string> adminMembers = new array<string>;
    ref array<string> modMembers = new array<string>;
    ref array<string> vipMembersSilver = new array<string>;
    ref array<string> vipMembersGold = new array<string>;

    void CustomMission()
    {
        InitPlayerWhitelist();
    }

    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
    {
        Entity playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
        Class.CastTo(m_player, playerEnt);
        GetGame().SelectPlayer(identity, m_player);
        return m_player;
    }

    void SetRandomHealth(EntityAI itemEnt)
    {
        if (itemEnt)
        {
            float rndHlt = Math.RandomFloat(0.25, 0.65);
            itemEnt.SetHealth01("", "", rndHlt);
        }
    }

    void addMags(PlayerBase player, string mag_type, int count)
    {
        if (count < 1)
            return;

        EntityAI mag;
        for (int i = 0; i < count; i++)
        {
            mag = player.GetInventory().CreateInInventory(mag_type);
        }
        player.SetQuickBarEntityShortcut(mag, 2, true);
    }

    void InitPlayerWhitelist()
    {
        // ADMIN MEMBERS: Replace with actual IDs
        adminMembers.Insert("76561199205606578");
        adminMembers.Insert("76561199569546626");

        // MODERATOR MEMBERS
        modMembers.Insert("ReplaceWithUniqueID");
        modMembers.Insert("ReplaceWithUniqueID");

        // Silver VIP MEMBERS
        vipMembersSilver.Insert("ReplaceWithUniqueID");
        vipMembersSilver.Insert("ReplaceWithUniqueID");

        // Non-VIP Loadout VIP MEMBERS
        vipMembersGold.Insert("ReplaceWithUniqueID");
        vipMembersGold.Insert("ReplaceWithUniqueID");
    }

    // --- ADMIN Loadout ---
    EntityAI adminLoadOut(PlayerBase player)
    {
    EntityAI helmet = player.GetInventory().CreateInInventory("MMG_striker_helmet_admin");
    helmet.GetInventory().CreateAttachment("mmg_gp_nvg_black");
    ItemBase nvg = ItemBase.Cast(helmet.FindAttachmentBySlotName("NVG"));
    if (nvg) nvg.GetInventory().CreateAttachment("Battery9V");
    
    player.GetInventory().CreateInInventory("MMG_combatshirt_admin");
    player.GetInventory().CreateInInventory("MMG_combatpants_admin");
    player.GetInventory().CreateInInventory("MMG_tt_vest_admin");
    player.GetInventory().CreateInInventory("JordanDread_boots_1_200");
    player.GetInventory().CreateInInventory("Armband_Expansion_Biohazard");
    player.GetInventory().CreateInInventory("MMG_balaclava_admin");
    player.GetInventory().CreateInInventory("TacticalGloves_Black");
    player.GetInventory().CreateInInventory("HipPack_Black");
    player.GetInventory().CreateInInventory("MFP_LaysBBQ");
    player.GetInventory().CreateInInventory("MFP_Jerky_Original");
    player.GetInventory().CreateInInventory("MFP_MtnDew");
    player.GetInventory().CreateInInventory("MFP_CheetosFlaminHot");
    player.GetInventory().CreateInInventory("MFP_AppleJacks");
    player.GetInventory().CreateInInventory("MFP_GummyBears");
    player.GetInventory().CreateInInventory("MFP_BagelBites");
    player.GetInventory().CreateInInventory("MFP_V8Juice");
    player.GetInventory().CreateInInventory("MFP_DuffBeer");
    player.GetInventory().CreateInInventory("MFP_DuffBeer");
    player.GetInventory().CreateInInventory("MFP_GummyWorms");
    player.GetInventory().CreateInInventory("MFP_HFlask_XMen");
    player.GetInventory().CreateInInventory("WeaponCleaningKit");
    player.GetInventory().CreateInInventory("mmg_Raidsaw");
    player.GetInventory().CreateInInventory("HuntingKnife");
    player.GetInventory().CreateInInventory("Lockpick");
    player.GetInventory().CreateInInventory("AMS_BandAid");
    
    EntityAI gun = player.GetInventory().CreateInInventory("BO_AKM_FDE");
    gun.GetInventory().CreateAttachment("BO_Holosun_HS510C_Optic");
    ItemBase optic = ItemBase.Cast(gun.FindAttachmentBySlotName("weaponOptics"));
    optic.GetInventory().CreateAttachment("Battery9V");
    Magazine magAttached = Magazine.Cast(gun.GetInventory().CreateAttachment("Mag_AKM_Drum_TEST"));
    magAttached.ServerSetAmmoCount(magAttached.GetAmmoMax());
    for (int i = 0; i < 3; i++) {
    Magazine spareMag = Magazine.Cast(player.GetInventory().CreateInInventory("Mag_AKM_Drum_TEST"));
    spareMag.ServerSetAmmoCount(spareMag.GetAmmoMax());
    }
    gun.GetInventory().CreateAttachment("NormalisedSuppressor");
    for (int j = 0; j < 3; j++) {
    player.GetInventory().CreateInInventory("NormalisedSuppressor");
    }
    
    
    EntityAI melee = player.GetInventory().CreateInInventory("NailedBaseballBat");
    player.SetQuickBarEntityShortcut(gun, 0, true);
    player.SetQuickBarEntityShortcut(melee, 1, true);
    return gun;
    }

    // Non-VIP Loadout (Default Loadout)
	EntityAI randomLoadOut(PlayerBase player) 
	{
		ref TStringArray hatArray = {"BeanieHat_Black","BaseballCap_CMMG_Black","BaseballCap_Camo","BaseballCap_Black","RadarCap_Black"};
		ref TStringArray topArray = {"Layered_Shirt_Courage","Layered_Shirt_Cheburashka","Shabby_Hoodie_Calligraphy","Shabby_Hoodie_Green","Shabby_Hoodie_Brown","Shabby_Hoodie_Black","Medium_Sleeves_Shirt_Red","Shabby_Hoodie_Grey"};
		ref TStringArray pantsArray = {"Adidas_Leggings","Fleece_Grey_Leggings","Kneepads_Jeans_Base","Kneepads_Jeans_Black","Skinny_Jeans_Black","Galife_Pants_Navy"};	
		ref TStringArray vestArray  = {""};	
		ref TStringArray glassesArray = {""};
		ref TStringArray shoesArray = {"SK8_Sneakers_Black","SK8_Sneakers_FullBlack","SK8_Sneakers_Blue","JordanDread_boots_9_200","JordanDread_boots_4_100"};	
		ref TStringArray maskArray = {"Headtorch_Black","Headtorch_Grey"};	
		ref TStringArray glovesArray = {"WorkingGloves_Brown"};		
		ref TStringArray foodArray = {"MFP_Jerky_Original","MFP_LaysBBQ"};
		ref TStringArray drinkArray = {"MFP_MtnDew","MFP_HFlask_XMen"};
		ref TStringArray backpackArray = {"TaloonBag_Blue","TaloonBag_Green","TaloonBag_Orange","TaloonBag_Violet"};
		ref TStringArray knifeArray  = {"HuntingKnife"};
		ref TStringArray meleeArray = {"NailedBaseballBat","BarbedBaseballBat"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		EntityAI mask = player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
        if (mask) mask.GetInventory().CreateAttachment("Battery9V");
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(knifeArray.GetRandomElement());
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("BO_Glock18C");  				// Weapon
		addMags(player, "BO_Mag_Glock18C_33rnd", 2); 								// Magazines								
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());	// Melee
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

    // --- MOD Loadout ---
    EntityAI modLoadOut(PlayerBase player)
    {
        return adminLoadOut(player); // reuse same loadout for now
    }

    // --- VIP Silver Loadout ---
    EntityAI vipLoadOutSilver(PlayerBase player)
    {
        player.GetInventory().CreateInInventory("BaseballCap_Red");
        player.GetInventory().CreateInInventory("Sweater_Red");
        player.GetInventory().CreateInInventory("Jeans_Blue");
        player.GetInventory().CreateInInventory("CombatBoots_Brown");
        player.GetInventory().CreateInInventory("WorkingGloves_Brown");
        player.GetInventory().CreateInInventory("BakedBeansCan");
        player.GetInventory().CreateInInventory("SodaCan_Cola");
        player.GetInventory().CreateInInventory("HuntingKnife");
        ItemBase rags = player.GetInventory().CreateInInventory("Rag"); rags.SetQuantity(4);
        ItemBase light = player.GetInventory().CreateInInventory("Flashlight"); light.GetInventory().CreateAttachment("Battery9V");

        EntityAI gun = player.GetInventory().CreateInInventory("AKS74U");
        addMags(player, "Mag_AK74_30Rnd", 2);

        EntityAI melee = player.GetInventory().CreateInInventory("FirefighterAxe");
        player.SetQuickBarEntityShortcut(gun, 0, true);
        player.SetQuickBarEntityShortcut(melee, 1, true);
        return gun;
    }


    // --- DOGTAG SYSTEM ---
    override Dogtag_Base EquipDogtag(PlayerBase player)
    {
        array<string> tags = {"Dogtag_Survivor"};

        if (!player.HasDogtag())
        {
            int slotId = InventorySlots.GetSlotIdFromString("Dogtag");
            return player.GetInventory().CreateAttachmentEx(tags.GetRandomElement(), slotId);
        }
        return null;
    }

    override void UpdatePlayersStats()
    {
        super.UpdatePlayersStats();

        array<Man> players = {};
        GetGame().GetPlayers(players);

        for (int i = 0; i < players.Count(); i++)
        {
            PlayerBase player;
            if (!PlayerBase.CastTo(player, players.Get(i)))
                continue;

            float playtime = player.StatGet("playtime"); // playtime in minutes

            if (Math.AbsFloat(playtime - 1440) < 1)       // 1 day
            {
                player.ReplaceDogtag("Dogtag_Hero");
            }
            else if (Math.AbsFloat(playtime - 4320) < 1)  // 3 days
            {
                player.ReplaceDogtag("Dogtag_Silver");
            }
            else if (Math.AbsFloat(playtime - 7200) < 1)  // 5 days
            {
                player.ReplaceDogtag("Dogtag_Granite");
            }
            else if (playtime >= 10080)                    // 7+ days
            {
                player.ReplaceDogtag("Dogtag_Cobalt");
            }
        }
    }


    // --- STARTING EQUIPMENT ---
    override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
    {
        player.RemoveAllItems();

        if (adminMembers.Find(GetUserID(player)) != -1 || adminMembers.Find(GetUserSteamID(player)) != -1) {
            adminLoadOut(player);
        } else if (modMembers.Find(GetUserID(player)) != -1 || modMembers.Find(GetUserSteamID(player)) != -1) {
            modLoadOut(player);
        } else if (vipMembersSilver.Find(GetUserID(player)) != -1 || vipMembersSilver.Find(GetUserSteamID(player)) != -1) {
            vipLoadOutSilver(player);
        } else {
            randomLoadOut(player);
        }
    }

    string GetUserID(PlayerBase player)
    {
        if (player.GetIdentity())
            return player.GetIdentity().GetPlainId();
        return "OFFLINE";
    }

    string GetUserSteamID(PlayerBase player)
    {
        if (player.GetIdentity())
            return player.GetIdentity().GetId();
        return "OFFLINE";
    }
};

Mission CreateCustomMission(string path)
{
    return new CustomMission();
}
