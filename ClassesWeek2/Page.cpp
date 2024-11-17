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
	_posts += new_line + '\n';
}