/*atomic model item_selector*/

#include "item_selector.h"
#include "message.h"
#include "parsimu.h"
#include "strutil.h"


ItemSelector :: ItemSelector ( const string &name )
: Atomic (name)
, item_in( addInputPort("item_in") )
, out ( addOutputPort("out") )
, preparationTime (0, 0, 3, 0) 
{
	string time(ParallelMainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &ItemSelector :: initFunction()
{
	this->passivate();
	item_id = 0;
	return *this;
}
Model &ItemSelector :: externalFunction( const ExternalMessage &msg)
{
	item_id = msg.value();
	this->holdIn ( AtomicState::active, preparationTime );
	return *this;
}
Model &ItemSelector :: internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &ItemSelector :: outputFunction( const CollectMessage &msg)
{
	this->sendOutput ( msg.time(), out, item_id );
	return *this; 
}	
