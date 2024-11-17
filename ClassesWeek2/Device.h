#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType {PHONE, PC, LAPTOP, TABLET};		     //
													     //
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
													     //
/// ///////////////////////////////////////////////////////


class Device
{
public:
	void init(unsigned int id, DeviceType type, std::string os); // initialization function - therefore won't be const.
	unsigned int getID() const; // all getter functions are consts!
	DeviceType getType() const;
	std::string getOS() const;
	bool isActive() const; // no changes happening to any fields, therefore -> const.
	void activate(); // changes the _activated field
	void deactivate(); // changes the _activated field

private:
	// fields
	unsigned int _id;
	DeviceType _type;
	std::string _os;
	bool _activated;
};

