
/* class vending_controller*/


#ifndef __VENDING_CONTROLLER_H
#define __VENDING_CONTROLLER_H

#include "atomic.h"

class VendingController : public Atomic 


{
public:
	VendingController ( const string &name = "VendingController" );
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
	const Port &incp;
	Port &outm2;
	Port &outb;
	Port &outp;
	Port &outc;
	Port &outi;
	Port &outm;
	Port &outcs;
	VTime preparationTime;
	double message;
};

inline
	string VendingController::className() const
{
	return "VendingController";
}
#endif 











