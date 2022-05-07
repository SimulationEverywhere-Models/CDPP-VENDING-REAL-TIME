/*atomic model item_processor*/

#include "item_processor.h"
#include "message.h"
#include "parsimu.h"
#include "strutil.h"

ItemProcessor::ItemProcessor (const string &name)
: Atomic (name)
, control_item_in( addInputPort("control_item_in") )
, item_out ( addOutputPort("item_out") )
, preparationTime (0, 0, 5, 0) 
{
	string time(ParallelMainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &ItemProcessor :: initFunction()
{ 	
	this->passivate();
	item = 0;
	return *this;
}
Model &ItemProcessor::externalFunction( const ExternalMessage &msg)
{
	
		item = msg.value();
		this->holdIn (AtomicState::active, preparationTime);


	return *this;
}
Model &ItemProcessor::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &ItemProcessor::outputFunction( const CollectMessage &msg)
{
	this->sendOutput ( msg.time(), item_out, item );
	return *this; 
}	
