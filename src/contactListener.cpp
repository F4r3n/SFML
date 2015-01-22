#include "contactListener.h"
#include <iostream>
ContactListener::ContactListener() {}

ContactListener::~ContactListener() {}

void ContactListener::BeginContact(b2Contact* contact) {

	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	std::cout << "yop" << std::endl;

}

void ContactListener::EndContact(b2Contact* contact) {

	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();


}
