#include "SocialNetwork.h"
#include <iostream>

/*Initializing the Social Network*/
void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_minAge = minAge;

	_profiles.init();
}

/*Clearing function*/
void SocialNetwork::clear()
{
	_networkName = "";
	_minAge = 0;

	_profiles.clear();
}

/*Getting the social network's name*/
std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

/*Getting the minimum age*/
int SocialNetwork::getMinAge() const
{
	return _minAge;
}

/*Adding a profile to the profile list in the social network*/
bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge) // if the owner's age is below the minumum - we won't allow him to be in the profile list
	{
		return false;
	}

	_profiles.add(profile_to_add); // if we got here - the owner's age is above the minimum, and can be added

	return true;
}

/*Getting a string with all the window devices in the social network*/
std::string SocialNetwork::getWindowsDevices() const
{
	std::string windowsDevices = ""; // reseting the string
	ProfileNode* currProfile = _profiles.get_first(); // getting the current profile
	DeviceNode* currDevice = NULL; // presenting the current device

	while (currProfile != nullptr) // while we are still in the profile list...
	{
		currDevice = currProfile->get_data().getOwner().getDevices().get_first(); // getting the current device for the profile

		while (currDevice != nullptr) // while we are still in the profile's device list..
		{
			if (currDevice->get_data().getOS().find("Windows") != std::string::npos) // if "Window" is in the OS of the device
			{
				windowsDevices += "[" + std::to_string(currDevice->get_data().getID()) + ", " + currDevice->get_data().getOS() + "], "; // adding it by format to the string
			}
			currDevice = currDevice->get_next(); // go to next device in the list
		}

		currProfile = currProfile->get_next(); // go to the next profile
	}

	if (windowsDevices.compare("")) // if the windowsDevices ISNT empty..
	{
		windowsDevices = windowsDevices.substr(0, windowsDevices.length() - 2); // delete the last two characters which are the last ', '. which we do not want.
	}

	return windowsDevices;
}