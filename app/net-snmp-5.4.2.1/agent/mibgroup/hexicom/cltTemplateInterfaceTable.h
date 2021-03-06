/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef CLTTEMPLATEINTERFACETABLE_H
#define CLTTEMPLATEINTERFACETABLE_H

/*
 * function declarations 
 */
void            init_cltTemplateInterfaceTable(void);
void            initialize_table_cltTemplateInterfaceTable(void);
Netsnmp_Node_Handler cltTemplateInterfaceTable_handler;
Netsnmp_First_Data_Point cltTemplateInterfaceTable_get_first_data_point;
Netsnmp_Next_Data_Point cltTemplateInterfaceTable_get_next_data_point;

NetsnmpCacheLoad         cltTemplateInterfaceTable_load;
NetsnmpCacheFree         cltTemplateInterfaceTable_free;
void cltTemplateInterfaceTable_commit(unsigned int regNo, void *clientargs);

/*
 * column number definitions for table cltTemplateInterfaceTable 
 */
#define COLUMN_CLTTEMPLATEIFTEMPLATEID		1
#define COLUMN_CLTTEMPLATEIFINDEX		2
#define COLUMN_CLTTEMPLATEIFNAME		3
#define COLUMN_CLTTEMPLATEIFTYPE		4
#define COLUMN_CLTTEMPLATEIFVLANMODE		5
#define COLUMN_CLTTEMPLATEIFPVID		6
#define COLUMN_CLTTEMPLATEIFSPEED		7
#define COLUMN_CLTTEMPLATEIFDUPLEX		8
#define COLUMN_CLTTEMPLATEIFPRIORITY		9
#define COLUMN_CLTTEMPLATEIFFLOWCONTROL		10
#define COLUMN_CLTTEMPLATEIFINGRESSRATELIMITATION		11
#define COLUMN_CLTTEMPLATEIFEGRESSRATELIMITATION		12
#define COLUMN_CLTTEMPLATEIFADMINSTATUS		13
#endif                          /* CLTTEMPLATEINTERFACETABLE_H */
