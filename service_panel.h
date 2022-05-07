
/* class service_panel*/


#ifndef __SERVICE_PANEL_H
#define __SERVICE_PANEL_H

#include "atomic.h"

class ServicePanel: public Atomic 


{
public:
	ServicePanel ( const string &name = "ServicePanel" );

	

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

    Model &outputFunction( const CollectMessage &);

private:
	const Port &service_in;
	Port &service_message_out;
	int message;
	VTime preparationTime;
};

inline
	string ServicePanel::className() const
{
	return "ServicePanel";
}
#endif 











