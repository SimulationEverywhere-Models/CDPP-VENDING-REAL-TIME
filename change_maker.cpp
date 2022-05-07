/*atomic model change_maker*/

#include "change_maker.h"
#include "message.h"
#include "parsimu.h"
#include "strutil.h"

ChangeMaker::ChangeMaker (const string &name)
: Atomic (name)
, request_in( addInputPort("request_in") )
, central_control_in ( addInputPort ( "central_control_in" ))
, request_out ( addOutputPort("request_out") )
, change_out ( addOutputPort ("change_out") )
, preparationTime (0, 0, 5, 0) 
{
	string time(ParallelMainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &ChangeMaker :: initFunction()
{ 	
	this->passivate();
	change = 0;
	return *this;
}
Model &ChangeMaker::externalFunction( const ExternalMessage &msg)
{
	if ( msg.port() == request_in )


       	this->sendOutput ( msg.time(), request_out, -1 );



	if ( msg.port() == central_control_in )



		change = msg.value();

		this->holdIn (AtomicState::active, preparationTime);




	return *this;
}
Model &ChangeMaker::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &ChangeMaker::outputFunction( const CollectMessage &msg)
{
	this->sendOutput ( msg.time(), change_out, change );
	return *this; 
}	
