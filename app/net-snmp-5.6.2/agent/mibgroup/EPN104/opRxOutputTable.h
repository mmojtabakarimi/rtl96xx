/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef OPRXOUTPUTTABLE_H
#define OPRXOUTPUTTABLE_H
config_add_mib(EPN104ZG-MIB-V1)
config_require(util_funcs/header_generic)
config_require(EPN104/opRxOutputTable)

/*
 * function declarations 
 */
void            init_opRxOutputTable(void);
void            initialize_table_opRxOutputTable(void);
Netsnmp_Node_Handler opRxOutputTable_handler;
Netsnmp_First_Data_Point opRxOutputTable_get_first_data_point;
Netsnmp_Next_Data_Point opRxOutputTable_get_next_data_point;
NetsnmpCacheLoad         opRxOutputTable_load;
NetsnmpCacheFree         opRxOutputTable_free;
void opRxOutputTable_commit(unsigned int regNo, void *clientargs);

/*
 * column number definitions for table opRxOutputTable 
 */
#define COLUMN_DOROUTPUTINDEX		1
#define COLUMN_DOROUTPUTCONTROL		2
#define COLUMN_DOROUTPUTGAINTYPE		3
#define COLUMN_DOROUTPUTLEVEL		4
#define COLUMN_DORCONFIGURATIONOUTPUTLEVEL		5
#define COLUMN_DOROUTPUTRFLEVELATT		6
#define COLUMN_DORCONFIGURATIONOUTPUTRFLEVELATT		7
#define COLUMN_DOROUTPUTRFNAME		8
#endif                          /* OPRXOUTPUTTABLE_H */
