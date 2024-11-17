#include "Page.h"
#include <iostream>

/*Initialization function - resets the status and posts strings*/
void Page::init()
{
	_status = "";
	_posts = "";
}

/*Getting the page's posts*/
std::string Page::getPosts() const
{
	return _posts;
}

/*Getting the page's status*/
std::string Page::getStatus() const
{
	return _status;
}

/*Clearing the page's posts - NOT CHANGING THE STATUS!*/
void Page::clearPage()
{
	_posts = "";
}

/*Setting the status of the page to something new*/
void Page::setStatus(std::string status)
{
	_status = status;
}

/*Adding a line to the string that represents the posts.*/
void Page::addLineToPosts(std::string new_line)
{
	if (!_posts.compare("")) // if the posts are empty... compare returns 0 in case the two strings are the same - !0 is true, since 0 is false.
	{
		_posts += new_line; // only add the new line
	}
	else // if the posts aren't empty - it isnt the first line to be added...
	{
		_posts += '\n' + new_line; // make a new line, and then copy the new line
	}
}