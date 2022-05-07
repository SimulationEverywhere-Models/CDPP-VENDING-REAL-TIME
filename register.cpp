/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "pmodeladm.h" 
#include "parsimu.h"
#include "queue.h"      // class Queue
#include "generat.h"    // class Generator
#include "cpu.h"        // class CPU
#include "transduc.h"   // class Transducer
#include "constgenerat.h" //class ConstGenerator

#include "coin_collector.h" // class coin_collector
#include "balance_display.h" //class balance_display
#include "change_maker.h" // class change_maker
#include "item_selector.h" // class item_selector
#include "message_queue.h" //class message_queue
#include "central_controller.h" // class central_controller
#include "item_processor.h" // class item_processor
#include "service_panel.h" // class service_panel
#include "vending_controller.h"
#include "service_controller.h"

/*
#include "hrRegister.h" // class HrReg
#include "minRegister.h" // class MinReg
#include "timeAdder.h" 	// class TimeAdder
#include "alarmRegister.h" 	// class AlarmReg
#include "timeComparator.h" 	// class TimeComp
#include "buzzerDriver.h" 	// class BuzDrv
#include "displayDriver.h" 	// class DispDrv
*/

#ifdef DEVS_AIRPORT
#include "modulo.h"
#include "selector.h"
#include "control.h"
#include "cola.h"
#include "deposito.h"
#include "salida.h"
#endif

#ifdef DEVS_NET
#include "client.h"
#include "controla.h"
#include "disco.h"
#include "multicpu.h"
#include "router.h"
#include "stopq.h"
#include "transduc2.h"
#endif

void ParallelMainSimulator::registerNewAtomics()
{
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<ConstGenerator>() , "ConstGenerator" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;

	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<BalanceDisplay>() , "BalanceDisplay" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<ChangeMaker>() , "ChangeMaker" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<ItemSelector>() , "ItemSelector" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<MessageQueue>() , "MessageQueue" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<CoinCollector>() , "CoinCollector" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<CentralControl>() , "CentralControl" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<ItemProcessor>() , "ItemProcessor" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<ServicePanel>() , "ServicePanel" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<VendingController>() , "VendingController" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<ServiceController>() , "ServiceController" ) ;

/*
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<HrReg>() , "HrReg" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<MinReg>() , "MinReg" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<AlarmReg>() , "AlarmReg" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<TimeAdder>() , "TimeAdder" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<TimeComp>() , "TimeComp" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<DispDrv>() , "DispDrv" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<BuzDrv>() , "BuzDrv" ) ;
*/

#ifdef DEVS_AIRPORT
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<modulo>() , "modulo" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<selector>() , "selector" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<control>() , "control" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<cola>() , "cola" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<deposito>() , "deposito" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<salida>() , "salida" ) ;
#endif
	
#ifdef DEVS_NET
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Client>() , "Client" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Controladora>() , "Controladora" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Disco>() , "Disco" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<MultiCPU>() , "MultiCPU" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Router>() , "Router" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<StoppableQueue>() , "StoppableQueue" ) ;
	SingleParallelModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer2>() , "Transducer2" ) ;
#endif	
	
	
}
