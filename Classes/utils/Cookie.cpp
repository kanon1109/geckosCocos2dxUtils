#include "Cookie.h"
bool Cookie::isSaved()
{
	if(!CCUserDefault::sharedUserDefault()->getBoolForKey("isSave"))
	{
		CCUserDefault::sharedUserDefault()->setBoolForKey("isSave", true);
		CCUserDefault::sharedUserDefault()->flush();
		return false;
	}
	return true;
}

CCUserDefault* Cookie::getShareUserData()
{
	return CCUserDefault::sharedUserDefault();
}


