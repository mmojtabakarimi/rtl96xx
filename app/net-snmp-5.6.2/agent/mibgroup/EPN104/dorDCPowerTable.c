/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 17695 2009-07-21 12:22:18Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "dorDCPowerTable.h"
#include "../product_common/snmp_ipc_interfaceTC.h"

#define DBGTOKEN  				"dorDCPowerTable"
#define DEFAULT_POWER		"N/A"
#define DEFAULT_POWER_NAME		"DC12V"

typedef struct {
    long            dorDCPowerIndex;
	#if defined(CONFIG_ZBL_SNMP)
	long            dorDCPowerVoltage;
	#else
    char            dorDCPowerVoltage[MAX_CATVINFO_SIZE];
	long           	dorDCPowerCurrent;
	#endif
	size_t          dorDCPowerVoltage_len;    
    char            dorDCPowerName[MAX_CATVINFO_SIZE];
	size_t          dorDCPowerName_len;

}snmp_DCPower_t;
snmp_DCPower_t g_DCPowerInfo;

/** Initializes the dorDCPowerTable module */
void
init_dorDCPowerTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_dorDCPowerTable();
}

//# Determine the first/last column names

/** Initialize the dorDCPowerTable table by defining its contents and how it's structured */
void
initialize_table_dorDCPowerTable(void)
{
    const oid       dorDCPowerTable_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 1, 9, 8 };
    const size_t    dorDCPowerTable_oid_len =
        OID_LENGTH(dorDCPowerTable_oid);
    netsnmp_handler_registration *reg;
    netsnmp_iterator_info *iinfo;
    netsnmp_table_registration_info *table_info;

    DEBUGMSGTL((DBGTOKEN,
                "initializing table dorDCPowerTable\n"));
#if defined(CONFIG_ZBL_SNMP)
	g_DCPowerInfo.dorDCPowerIndex = 1;
	g_DCPowerInfo.dorDCPowerVoltage = 0;
#else
	g_DCPowerInfo.dorDCPowerIndex = 0;
	strncpy(g_DCPowerInfo.dorDCPowerVoltage, DEFAULT_POWER, sizeof(g_DCPowerInfo.dorDCPowerVoltage));
	g_DCPowerInfo.dorDCPowerCurrent = 0;
#endif	
	g_DCPowerInfo.dorDCPowerVoltage_len = sizeof(g_DCPowerInfo.dorDCPowerVoltage);	
	strncpy(g_DCPowerInfo.dorDCPowerName, DEFAULT_POWER_NAME, sizeof(g_DCPowerInfo.dorDCPowerName));
	g_DCPowerInfo.dorDCPowerName_len = strlen(g_DCPowerInfo.dorDCPowerName);

    reg =
        netsnmp_create_handler_registration("dorDCPowerTable",
                                            dorDCPowerTable_handler,
                                            dorDCPowerTable_oid,
                                            dorDCPowerTable_oid_len,
                                            HANDLER_CAN_RONLY);

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    netsnmp_table_helper_add_indexes(table_info, ASN_INTEGER,   /* index: dorDCPowerIndex */
                                     0);
    table_info->min_column = COLUMN_DORDCPOWERINDEX;
    table_info->max_column = COLUMN_DORDCPOWERNAME;

    iinfo = SNMP_MALLOC_TYPEDEF(netsnmp_iterator_info);
    iinfo->get_first_data_point = dorDCPowerTable_get_first_data_point;
    iinfo->get_next_data_point = dorDCPowerTable_get_next_data_point;
    iinfo->table_reginfo = table_info;

    netsnmp_register_table_iterator(reg, iinfo);
	netsnmp_inject_handler( reg,
				netsnmp_get_cache_handler(HC_CACHE_TIMEOUT,
						dorDCPowerTable_load, dorDCPowerTable_free,
						dorDCPowerTable_oid, OID_LENGTH(dorDCPowerTable_oid)));
		DEBUGMSGTL((DBGTOKEN,
					"initialize dorDCPowerTable\n"));  

    /*
     * Initialise the contents of the table here 
     */
}

    /*
     * Typical data structure for a row entry 
     */
struct dorDCPowerTable_entry {
    /*
     * Index values 
     */
    long            dorDCPowerIndex;

    /*
     * Column values 
     */
    //long            dorDCPowerIndex;
	#if defined(CONFIG_ZBL_SNMP)
	long            dorDCPowerVoltage;
	#else
    char            dorDCPowerVoltage[MAX_CATVINFO_SIZE];
	long            dorDCPowerCurrent;
	#endif
    size_t          dorDCPowerVoltage_len;    
    char            dorDCPowerName[MAX_CATVINFO_SIZE];
    size_t          dorDCPowerName_len;

    /*
     * Illustrate using a simple linked list 
     */
    int             valid;
    struct dorDCPowerTable_entry *next;
};

struct dorDCPowerTable_entry *dorDCPowerTable_head;

/*
 * create a new row in the (unsorted) table 
 */
struct dorDCPowerTable_entry *
dorDCPowerTable_createEntry(struct dorDCPowerTable_entry *dorDCPowerTable)
{
    struct dorDCPowerTable_entry *entry;	

    entry = SNMP_MALLOC_TYPEDEF(struct dorDCPowerTable_entry);
    if (!entry)
        return NULL;

    //entry->dorDCPowerIndex = dorDCPowerIndex;
	memcpy(entry, dorDCPowerTable, sizeof(*entry));
    entry->next = dorDCPowerTable_head;
    dorDCPowerTable_head = entry;
    return entry;
}

/*
 * remove a row from the table 
 */
void
dorDCPowerTable_removeEntry(struct dorDCPowerTable_entry *entry)
{
    struct dorDCPowerTable_entry *ptr, *prev;

    if (!entry)
        return;                 /* Nothing to remove */

    for (ptr = dorDCPowerTable_head, prev = NULL;
         ptr != NULL; prev = ptr, ptr = ptr->next) {
        if (ptr == entry)
            break;
    }
    if (!ptr)
        return;                 /* Can't find it */

    if (prev == NULL)
        dorDCPowerTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE(entry);           /* XXX - release any other internal resources */
}

void dorDCPowerTable_removeAllEntry(void )
{
    struct dorDCPowerTable_entry *ptr, *pnext;

    for (ptr = dorDCPowerTable_head; ptr != NULL; ptr = pnext) {
		 pnext = ptr->next;
		 SNMP_FREE(ptr); 
    }
	dorDCPowerTable_head = NULL;
}

void dorDCPowerTable_setEntry(
				struct dorDCPowerTable_entry *entry, 
				snmp_DCPower_t *pinfo
				)
{

	memset(entry, 0, sizeof(*entry));
	
	entry->dorDCPowerIndex = pinfo->dorDCPowerIndex;
	#if defined(CONFIG_ZBL_SNMP)
	entry->dorDCPowerVoltage = pinfo->dorDCPowerVoltage;
	#else
	strncpy(entry->dorDCPowerVoltage, pinfo->dorDCPowerVoltage, sizeof(entry->dorDCPowerVoltage));
	entry->dorDCPowerCurrent =pinfo->dorDCPowerCurrent;
	#endif
	entry->dorDCPowerVoltage_len = pinfo->dorDCPowerVoltage_len;	
	strncpy(entry->dorDCPowerName, pinfo->dorDCPowerName, sizeof(entry->dorDCPowerName));
	entry->dorDCPowerName_len = pinfo->dorDCPowerName_len;
}


/*
 * Example iterator hook routines - using 'get_next' to do most of the work 
 */
netsnmp_variable_list *
dorDCPowerTable_get_first_data_point(void **my_loop_context,
                                     void **my_data_context,
                                     netsnmp_variable_list *
                                     put_index_data,
                                     netsnmp_iterator_info *mydata)
{
    *my_loop_context = dorDCPowerTable_head;
    return dorDCPowerTable_get_next_data_point(my_loop_context,
                                               my_data_context,
                                               put_index_data, mydata);
}

netsnmp_variable_list *
dorDCPowerTable_get_next_data_point(void **my_loop_context,
                                    void **my_data_context,
                                    netsnmp_variable_list * put_index_data,
                                    netsnmp_iterator_info *mydata)
{
    struct dorDCPowerTable_entry *entry =
        (struct dorDCPowerTable_entry *) *my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if (entry) {
        snmp_set_var_typed_integer(idx, ASN_INTEGER,
                                   entry->dorDCPowerIndex);
        idx = idx->next_variable;
        *my_data_context = (void *) entry;
        *my_loop_context = (void *) entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the dorDCPowerTable table */
int
dorDCPowerTable_handler(netsnmp_mib_handler *handler,
                        netsnmp_handler_registration *reginfo,
                        netsnmp_agent_request_info *reqinfo,
                        netsnmp_request_info *requests)
{

    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    struct dorDCPowerTable_entry *table_entry;
	catvinfo_t *info = NULL;
	ipc_catvinfo_ack_t *pack = NULL;

    DEBUGMSGTL((DBGTOKEN, "Processing request (%d)\n",
                reqinfo->mode));

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            table_entry = (struct dorDCPowerTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			
            switch (table_info->colnum) {
            case COLUMN_DORDCPOWERINDEX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->dorDCPowerIndex);
                break;
            case COLUMN_DORDCPOWERVOLTAGE:				
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
			#if defined(CONFIG_ZBL_SNMP)
				snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->dorDCPowerVoltage);
			#else
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->dorDCPowerVoltage,
                                         table_entry->dorDCPowerVoltage_len);
			#endif
                break;
			#if !defined(CONFIG_ZBL_SNMP)
            case COLUMN_DORDCPOWERCURRENT:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->dorDCPowerCurrent);
                break;
			#endif
            case COLUMN_DORDCPOWERNAME:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->dorDCPowerName,
                                         table_entry->dorDCPowerName_len);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

    }
    return SNMP_ERR_NOERROR;
}

int dorDCPowerTable_load(netsnmp_cache *cache, void *vmagic)
{
	struct dorDCPowerTable_entry entry;
	int ret = 0;
	int i =0;
	snmp_DCPower_t *pinfo = NULL;
	int DCPower_num = 0;

	char val[MAX_CATVINFO_SIZE] = {0};

	//COMMIT_PENDING_ASSERT();

	/* Free All */

	dorDCPowerTable_removeAllEntry();

	/* Load All */
	DCPower_num = 1;
	/*alarms_num =ipc_snmp_alarm_num(&agent)*/
	if (DCPower_num == 0){
		DBG_ASSERT(0, "RxDCPower num is 0");
		return 0;
	}

	pinfo = &g_DCPowerInfo;
	
	#ifdef CONFIG_CATVCOM
	catvinfo_t *info = NULL;
	ipc_catvinfo_ack_t *pack = NULL;
	pack = ipc_catv_config(ipc_fd, IPC_CONFIG_GET, IPC_APPLY_NONE, NULL);
	if(pack && pack->hdr.status == IPC_STATUS_OK) 
	{		
		info = &pack->catvinfo;
		#if defined(CONFIG_ZBL_SNMP)
		pinfo->dorDCPowerVoltage = info->power_12v;
		#else
		strncpy(pinfo->dorDCPowerVoltage, info->power_12v, sizeof(info->power_12v));
		#endif
		g_DCPowerInfo.dorDCPowerVoltage_len = sizeof(info->power_12v);
		if(pack)
		{
			free(pack);
		}
	}
	else
	{	
		if(pack)
		{
			free(pack);
		}
		return SNMP_ERR_GENERR;
	}
	#endif
	
	for (i = 0; i < DCPower_num; i ++)
	{
		dorDCPowerTable_setEntry(&entry, &pinfo[i]);	
		dorDCPowerTable_createEntry(&entry);	
	}

safe_exit:
	
	HC_IPC_ASSERT(ret);
	
    return ret; 
} 


void dorDCPowerTable_free(netsnmp_cache *cache, void *magic)
{
	DEBUGMSGTL((DBGTOKEN, "Free opRxInputTable Group\n"));  
}

