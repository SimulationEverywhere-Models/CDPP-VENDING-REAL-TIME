
/* class Balance_display*/


#ifndef __BALANCE_DISPLAY_H
#define __BALANCE_DISPLAY_H

#include "atomic.h"



class BalanceDisplay : public Atomic
{
public:
	BalanceDisplay ( const string &name = "BalanceDisplay" );
	virtual string className() const
	{	return "BalanceDisplay"; };

protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const CollectMessage &);

private:
	const Port &in;
	Port &out;
	float balance;
	VTime preparationTime;
};

#endif 











