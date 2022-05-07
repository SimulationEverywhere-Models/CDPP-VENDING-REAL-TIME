
/* class coin_collector*/


#ifndef __COIN_COLLECTOR_H
#define __COIN_COLLECTOR_H

#include "atomic.h"

class CoinCollector : public Atomic 


{
public:
	CoinCollector ( const string &name = "CoinCollector" );

	

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const CollectMessage &);
private:
	const Port &coin_in;
	Port &out;
	float coin_amount;
	VTime preparationTime;
};

inline
	string CoinCollector::className() const
{
	return "CoinCollector";
}
#endif 











