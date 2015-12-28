/* 
* FeedSettingsLoader.cpp
*
* Created: 28.12.2015 22:50:17
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "FeedSettingsLoader.h"
#include "BaseTypes/EEPROM.h"
//---------------------------------------------------------------------------

#define StartEEPROMIndex 4
#define SettingsEntrySize 3

// default constructor
FeedSettingsLoader::FeedSettingsLoader()
{
} //FeedSettingsLoader
//---------------------------------------------------------------------------

// default destructor
FeedSettingsLoader::~FeedSettingsLoader()
{
} //~FeedSettingsLoader
//---------------------------------------------------------------------------
void FeedSettingsLoader::SaveSettings(FeedLaunchSettings settings, int index)
{
	EEPROM::Write(StartEEPROMIndex + (SettingsEntrySize * index), settings.feedTime.hour);
	EEPROM::Write(StartEEPROMIndex + (SettingsEntrySize * index) + 1, settings.feedTime.minute);
	EEPROM::Write(StartEEPROMIndex + (SettingsEntrySize * index) + 2, settings.lengthInSeconds);
}
//---------------------------------------------------------------------------

void FeedSettingsLoader::LoadSettings(FeedLaunchSettings& settings, int index)
{
	uint8_t hour = EEPROM::Read(StartEEPROMIndex + (SettingsEntrySize * index));
	uint8_t minute = EEPROM::Read(StartEEPROMIndex + (SettingsEntrySize * index) + 1);
	uint8_t lengthInSeconds = EEPROM::Read(StartEEPROMIndex + (SettingsEntrySize * index) + 2);
	
	settings.feedTime.hour = hour;
	settings.feedTime.minute = minute;
	settings.lengthInSeconds = lengthInSeconds;
	settings.isEnabled = lengthInSeconds != 0 ? 1 : 0;
}
//---------------------------------------------------------------------------