/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef CLTNETWORKUNITINTERFACETABLE_H
#define CLTNETWORKUNITINTERFACETABLE_H

/*
 * function declarations 
 */
void            init_cltNetworkUnitInterfaceTable(void);
void            initialize_table_cltNetworkUnitInterfaceTable(void);
Netsnmp_Node_Handler cltNetworkUnitInterfaceTable_handler;
Netsnmp_First_Data_Point cltNetworkUnitInterfaceTable_get_first_data_point;
Netsnmp_Next_Data_Point cltNetworkUnitInterfaceTable_get_next_data_point;

NetsnmpCacheLoad         cltNetworkUnitInterfaceTable_load;
NetsnmpCacheFree         cltNetworkUnitInterfaceTable_free;
void cltNetworkUnitInterfaceTable_commit(unsigned int regNo, void *clientargs);


/*
 * column number definitions for table cltNetworkUnitInterfaceTable 
 */
#define COLUMN_CLTNETWORKUNITIFNETWORKUNITMACADDRESS		1
#define COLUMN_CLTNETWORKUNITIFINDEX		2
#define COLUMN_CLTNETWORKUNITIFTYPE		3
#define COLUMN_CLTNETWORKUNITIFNAME		4
#define COLUMN_CLTNETWORKUNITIFLINKSTATUS		5
#define COLUMN_CLTNETWORKUNITIFSPEED		6
#define COLUMN_CLTNETWORKUNITIFTXPACKETS		7
#define COLUMN_CLTNETWORKUNITIFRXPACKETS		8
#define COLUMN_CLTNETWORKUNITIFSTATUS		9
#endif                          /* CLTNETWORKUNITINTERFACETABLE_H */
