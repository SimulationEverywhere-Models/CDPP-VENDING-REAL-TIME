/*atomic model message_queue*/

#include "message_queue.h"
#include "message.h"
#include "parsimu.h"
#include "strutil.h"

MessageQueue::MessageQueue (const string &name)
: Atomic (name)
, coin_controller_in( addInputPort("coin_controller_in") )
, item_selector_in ( addInputPort ( "item_selector_in" ) )
, change_request_in ( addInputPort ( "change_request_in") )
, done ( addInputPort ( "done" ) )
, message_out ( addOutputPort ("message_out") )
, preparationTime (0, 0, 5, 0) 
{
	string time(ParallelMainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &MessageQueue :: initFunction()
{ 	
	this->passivate();
	this->elements.erase(elements.begin(), elements.end() );
	return *this;
}

Model &MessageQueue::externalFunction(const ExternalMessage &msg)
{
	if (( msg.port() == coin_controller_in )||(msg.port() == item_selector_in )||(msg.port() == change_request_in))
	{
		elements.push_back (msg.value());
		if (elements.size() == 1 )
			this->holdIn ( AtomicState::active, preparationTime );
	}

	if ( msg.port() == done )
	{
		elements.pop_front();
		if ( !elements.empty() )
		{
			this->holdIn ( AtomicState::active, preparationTime );
		}
	}

	return *this;
}
Model &MessageQueue::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &MessageQueue::outputFunction( const CollectMessage &msg)
{
	this->sendOutput ( msg.time(), message_out, elements.front() );
	return *this; 
}	
