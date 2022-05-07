/*atomic model Balance_display*/

#include "balance_display.h"
#include "message.h"
#include "parsimu.h"
#include "strutil.h"


BalanceDisplay :: BalanceDisplay ( const string &name )
: Atomic (name)
, in( addInputPort("in") )
, out ( addOutputPort("out") )
, preparationTime (0, 0, 3, 0) 
{
	string time(ParallelMainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;
}

Model &BalanceDisplay :: initFunction()
{
	this->passivate();
	balance = 0;
	return *this;
}
Model &BalanceDisplay :: externalFunction( const ExternalMessage &msg)
{
	balance =  msg.value();
	this->holdIn ( AtomicState::active, preparationTime );
	return *this;
}
Model &BalanceDisplay :: internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &BalanceDisplay :: outputFunction( const CollectMessage &msg)
{
	this->sendOutput ( msg.time(), out, balance );
	return *this; 
}	

