#pragma once
#include "ProfileList.h"

class SocialNetwork
{
public:
	void init(std::string networkName, int minAge); // initialization function
	void clear(); // clearing function

	std::string getNetworkName() const; // getters
	int getMinAge() const;
	std::string getWindowsDevices() const;

	// adding profile to the profile list
	bool addProfile(Profile profile_to_add);

private:
	// fields
	std::string _networkName;
	ProfileList _profiles;
	int _minAge;
};