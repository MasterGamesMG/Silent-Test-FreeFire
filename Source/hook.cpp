	
	BOOL IF
	
bool aimbotSilent = false;

	HOOK :
	
void (*orig_Player_OJOHLBJEIJO)(void *, float, float);
void hook_Player_OJOHLBJEIJO(void *_this, float OPKNJGBDOBB, float OMAFEKBHOAA)
{
    void *CurrentGame = GameFacadeManager::GameFacade_CurrentMatch();
    void *GetEnemy = GetClosestEnemy(GameFacadeManager::GameFacade_CurrentLocalPlayer(), GameFacadeManager::GameFacade_CurrentMatch());
    if (_this != nullptr && CurrentGame != nullptr && GetEnemy != nullptr)
    {
        if (aimbotSilent)
        {
            if (PlayerManager::Player_get_IsFiring(GameFacadeManager::GameFacade_CurrentLocalPlayer())) {
                return;
            } else {
                return orig_Player_OJOHLBJEIJO(_this, OPKNJGBDOBB, OMAFEKBHOAA);
            }
        }
    }
    return orig_Player_OJOHLBJEIJO(_this, OPKNJGBDOBB, OMAFEKBHOAA);
}

	OFFSET :
    HOOK_MASTER("libil2cpp.so", "0xB7C920", hook_Player_OJOHLBJEIJO, orig_Player_OJOHLBJEIJO); //SILENT AIM TEST
	
	
	NAME IN DUMP :
	// RVA: 0xB7C920 Offset: 0xB7C920 VA: 0xC6D74920
	private void OJOHLBJEIJO(float OPKNJGBDOBB, float OMAFEKBHOAA) { }
