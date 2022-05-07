/*atomic model coin_collector*/

#include "service_controller.h"
#include "message.h"
#include "parsimu.h"
#include "strutil.h"

ServiceController :: ServiceController(const string &name)
: Atomic (name)
, inc( addInputPort("inc") )
, ini( addInputPort("ini") )
, inm( addInputPort("inm") )
, ins( addInputPort("ins") )
, outm ( addOutputPort("outm") )
, outb ( addOutputPort("outb") )
, outp ( addOutputPort("outp") )
, incm( addInputPort("incm") )
, incb( addInputPort("incb") )
, inp( addInputPort("inp") )
, outc ( addOutputPort("outc") )
, outi ( addOutputPort("outi") )
, outm2 ( addOutputPort("outm2") )
, outs ( addOutputPort("outs") )
, preparationTime (0, 0, 1, 0) 
{
	string time(ParallelMainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &ServiceController:: initFunction()
{ 	
	message = 0;
	this->passivate();
	return *this;
}
Model &ServiceController:: externalFunction( const ExternalMessage &msg)
{
	message = msg.value();
	if(msg.port() == inc)
		this->sendOutput (msg.time(), outc, message );
	if(msg.port() == ini)
		this->sendOutput (msg.time(), outi, message);
	if(msg.port() == inm)
		this->sendOutput (msg.time(), outm2, message);
	if(msg.port() == ins)
		this->sendOutput (msg.time(), outs, message);
	if(msg.port() == incm)
		this->sendOutput (msg.time(), outm, message);
	if(msg.port() == incb)
		this->sendOutput (msg.time(), outb, message);
	if(msg.port() == inp)
		this->sendOutput (msg.time(), outp, message);
       	this->holdIn ( AtomicState::active, preparationTime );
	return *this;
}
Model &ServiceController:: internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}

Model &ServiceController::outputFunction( const CollectMessage &msg )
{
	return *this; 
}	
