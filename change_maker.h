
/* class change_maker*/


#ifndef __CHANGE_MAKER_H
#define __CHANGE_MAKER_H

#include "atomic.h"

class ChangeMaker: public Atomic 
{
public:
	ChangeMaker ( const string &name = "ChangeMaker" );

	

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const CollectMessage &);
private:
	const Port &request_in;
	Port &central_control_in;
	Port &change_out;
	Port &request_out;
	float change;
	VTime preparationTime;
};

inline
	string ChangeMaker::className() const
{
	return "ChangeMaker";
}
#endif 











