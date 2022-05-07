
/* class message_queue*/


#ifndef __MESSAGE_QUEUE_H
#define __MESSAGE_QUEUE_H

#include <list>
#include "atomic.h"

class MessageQueue : public Atomic 


{
public:
	MessageQueue ( const string &name = "MessageQueue" );

	

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const CollectMessage &);
private:
	const Port &coin_controller_in;
	Port &item_selector_in;
	Port &change_request_in;
	Port &message_out;
	Port &done;
	VTime preparationTime;
	typedef list<Value> ElementList;
	ElementList elements;
};

inline
	string MessageQueue::className() const
{
	return "MessageQueue";
}
#endif 












