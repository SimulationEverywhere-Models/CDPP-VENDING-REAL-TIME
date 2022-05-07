
/* class item_selector*/


#ifndef __ITEM_SELECTOR_H
#define __ITEM_SELECTOR_H

#include "atomic.h"

class ItemSelector: public Atomic
{
public:
	ItemSelector ( const string &name = "ItemSelector" );

	virtual string className() const
	{ return "ItemSelector"; };

protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const CollectMessage &);
private:
	const Port &item_in;
	Port &out;
	int item_id;
	VTime preparationTime;
};

#endif 











