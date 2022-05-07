
/* class item_processor*/


#ifndef __ITEM_PROCESSOR_H
#define __ITEM_PROCESSOR_H

#include "atomic.h"

class ItemProcessor: public Atomic 


{
public:
	ItemProcessor ( const string &name = "ItemProcessor" );

	

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const CollectMessage &);
private:
	const Port &control_item_in;
	Port &item_out;
	int item;
	VTime preparationTime;
};

inline
	string ItemProcessor::className() const
{
	return "ItemProcessor";
}
#endif 











