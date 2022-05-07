/*atomic model coin_collector*/

#include "vending_controller.h"
#include "message.h"
#include "parsimu.h"
#include "strutil.h"

VendingController :: VendingController(const string &name)
: Atomic (name)
, inc( addInputPort("inc") )
, ini( addInputPort("ini") )
, inm( addInputPort("inm") )
, ins( addInputPort("ins") )
, incm( addInputPort("incm") )
, incb( addInputPort("incb") )
, incp( addInputPort("incp") )
, outm2 ( addOutputPort("outm2") )
, outb ( addOutputPort("outb") )
, outp ( addOutputPort("outp") )
, outc ( addOutputPort("outc") )
, outi ( addOutputPort("outi") )
, outm ( addOutputPort("outm") )
, outcs ( addOutputPort("outcs") )
, preparationTime (0, 0, 1, 0) 
{
	string time(ParallelMainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &VendingController:: initFunction()
{ 	
	message = 0;
	this->passivate();
	return *this;
}
Model &VendingController:: externalFunction( const ExternalMessage &msg)
{
	message = msg.value();
	if(msg.port() == inc)
		this->sendOutput (msg.time(), outc, message );
	if(msg.port() == ini)
		this->sendOutput (msg.time(), outi, message);
	if(msg.port() == inm)
		this->sendOutput (msg.time(), outm, message);
	if(msg.port() == ins)
		this->sendOutput (msg.time(), outcs, message);
	if(msg.port() == incm)
		this->sendOutput (msg.time(), outm2, message);
	if(msg.port() == incb)
		this->sendOutput (msg.time(), outb, message);
	if(msg.port() == incp)
		this->sendOutput (msg.time(), outp, message);
       	this->holdIn ( AtomicState::active, preparationTime );
	return *this;
}
Model &VendingController:: internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &VendingController::outputFunction( const CollectMessage &msg )
{
	return *this; 
}	
