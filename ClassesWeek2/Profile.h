#pragma once
#include "UserList.h"
#include "Page.h"

class Profile
{
public:
	void init(User owner); // initialization function
	void clear(); // clearing the object and freeing all allocated memory

	User getOwner() const; // getters
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;

	void setStatus(std::string new_status); // setter

	void addPostToProfilePage(std::string post); // adding post to the profile page
	void addFriend(User friend_to_add); // adding friend to the friend list

private:
	// fields
	User _owner;
	Page _page;
	UserList _friends;
};