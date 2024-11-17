#include "Profile.h"
#include <iostream>

/*Initialization function*/
void Profile::init(User owner)
{
	_owner.init(owner.getID(), owner.getUserName(), owner.getAge()); // initializing the owner's user
	_page.init(); // initializing the profile's page
	_friends.init(); // initializing the friends list
}

/*Clearing function - cleaning the object, and also freeing all allocated memory*/
void Profile::clear()
{
	_owner.clear(); // clearing the user owner

	_page.clearPage(); // clearing the posts in the page
	_page.setStatus(""); // clearing the status in the page

	_friends.clear(); // clearing the friend list
}

/*Making a COPY of the owner's user, and returning it
It will be a const function since it does not change or send any refrence to a field in the object.*/
User Profile::getOwner() const
{
	User ownerReplica; // making a replica of the owner user
	ownerReplica.init(_owner.getID(), _owner.getUserName(), _owner.getAge()); // initializing the information in the replica

	return ownerReplica;
}

/*Setting the status of the profile*/
void Profile::setStatus(std::string new_status)
{
	_page.setStatus(new_status);
}

/*Adding a post to the profile*/
void Profile::addPostToProfilePage(std::string post)
{
	_page.addLineToPosts(post);
}

/*Adding a friend to the friend list*/
void Profile::addFriend(User friend_to_add)
{
	_friends.add(friend_to_add);
}

/*Getting the page's contents in a format*/
std::string Profile::getPage() const
{
	// returning the format of the profile
	return("Status: " + _page.getStatus() + "\n*******************\n*******************\n" + _page.getPosts());
}

/*Getting a string with all the names of the friends in the friends list*/
std::string Profile::getFriends() const
{
	std::string friendsString = ""; // reseting a string for the friends
	UserNode* curr = _friends.get_first(); // the current friend in the friend list

	while (curr != nullptr) // while we are still in the friend list
	{
		friendsString += curr->get_data().getUserName() + ","; // add to the string the friend's name
		curr = curr->get_next(); // going to the next friend
	}

	if (friendsString.compare("")) // if the friendString ISNT empty..
	{
		friendsString = friendsString.substr(0, friendsString.length() - 1); // delete the last character which is the last ','. which we do not want.
	}

	return friendsString; // return the string which contains all of the owner's friends
}

/*Getting a string with the names of all the friends in the friends list that
their names are the same length as the owner's name*/
std::string Profile::getFriendsWithSameNameLength() const
{
	std::string friendsString = ""; // reseting a string for the friends
	UserNode* curr = _friends.get_first(); // the current friend in the friend list

	while (curr != nullptr) // while we are still in the friend list
	{
		// checking if the current friend's name is the same length as the owner name's length
		if (curr->get_data().getUserName().length() == _owner.getUserName().length())
		{
			friendsString += curr->get_data().getUserName() + ","; // add to the string the friend's name
		}

		curr = curr->get_next(); // going to the next friend
	}

	if (friendsString.compare("")) // if the friendString ISNT empty..
	{
		friendsString = friendsString.substr(0, friendsString.length() - 1); // delete the last character which is the last ','. which we do not want.
	}

	return friendsString; // return the string which contains all of the owner's friends
}