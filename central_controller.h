
/* class central_control*/


#ifndef __CENTRAL_CONTROLLER_H
#define __CENTRAL_CONTROLLER_H

#include <stdio.h>
#include "atomic.h"

class CentralControl: public Atomic 


{
public:
	CentralControl ( const string &name = "CentralControl" );

	virtual string className() const;
protected:
	
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);

	Model &outputFunction( const CollectMessage &);
private:
	const Port &message_in;
	Port &service_panel_in;
	Port &control_item_out;
	Port &control_change_out;
	Port &balance_out;
	Port &queue_out;
	VTime preparationTime;
	
	double price1;
	int quantity1;
	double price2;
	int quantity2;
	//int quantityList[5];
	//FoodList m_list;
	//float message;
	double balance;
	int returnPort;
	int itemCount;

	double processMsg(double);
	void processService (double);
};

inline
	string CentralControl::className() const
{
	return "CentralControl";
}
#endif 












