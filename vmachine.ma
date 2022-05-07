[top]
components : coin@CoinCollector
components : item@ItemSelector
components : changemaker@ChangeMaker
components : balance@BalanceDisplay
components : ServiceController
in : coin_in item_in request_in service_in
out : change_out out item_out
Link : coin_in coin_in@coin
Link : out@coin inc@ServiceController
Link : item_in item_in@item
Link : out@item ini@ServiceController
Link : request_in request_in@changemaker
Link : request_out@changemaker inm@ServiceController
Link : outm@ServiceController central_control_in@changemaker
Link : change_out@changemaker change_out
Link : outb@ServiceController in@balance
Link : out@balance out
Link : outp@ServiceController item_out
Link : service_in ins@ServiceController 

[ServiceController]
components : VendingController
components : itemProc@ItemProcessor
components : service@ServicePanel
in : inc ini inm ins
out : outm outb outp
Link : inc inc@VendingController
Link : ini ini@VendingController
Link : inm inm@VendingController
Link : ins service_in@service 
Link : outm2@VendingController outm
Link : outb@VendingController outb
Link : item_out@itemProc outp
Link : service_message_out@service ins@VendingController
Link : outp@VendingController control_item_in@itemProc

[VendingController]
components : message@MessageQueue
components : central@CentralControl
in :  inc ini inm ins
out : outm2 outb outp
Link : inc coin_controller_in@message
Link : ini item_selector_in@message
Link : inm change_request_in@message
Link : ins service_panel_in@central
Link : control_change_out@central outm2
Link : balance_out@central outb
Link : control_item_out@central outp
Link : queue_out@central done@message
Link : message_out@message message_in@central


[coin]
preparation : 0:0:1:0

[item]
preparation : 0:0:2:0

[changemaker]
preparation : 0:0:2:0

[balance]
preparation : 0:0:0:0

[itemProc]
preparation : 0:0:3:0

[service]
preparation : 0:0:1:0

[message]
preparation : 0:0:0:0

[central]
preparation : 0:0:1:0

[ServiceController]
preparation : 0:0:0:0

[VendingController]
preparation : 0:0:0:0

