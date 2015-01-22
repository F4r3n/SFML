#ifndef CONTACT_H
#define CONTACT_H

#include <Box2D/Box2D.h>
#include "player.h"


class ContactListener : public b2ContactListener
{
	public:
	ContactListener();
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	~ContactListener();

};

#endif
