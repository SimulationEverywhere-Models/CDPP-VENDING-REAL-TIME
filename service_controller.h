
/* class coin_collector*/


#ifndef __SERVICE_CONTROLLER_H
#define __SERVICE_CONTROLLER_H

#include "atomic.h"

class ServiceController : public Atomic 


{
public:
	ServiceController ( const string &name = "ServiceController" );
	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

    Model &outputFunction( const CollectMessage & );

private:
	const Port &inc;
	const Port &ini;
	const Port &inm;
	const Port &ins;
	const Port &incm;
	const Port &incb;
	const Port &inp;
	Port &outm;
	Port &outb;
	Port &outp;
	Port &outc;
	Port &outi;
	Port &outm2;
	Port &outs;
	VTime preparationTime;
	double message;
};

inline
	string ServiceController::className() const
{
	return "ServiceController";
}
#endif 











