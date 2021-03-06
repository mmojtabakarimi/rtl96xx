/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "cltNetworkUnitInterfaceTable.h"

#include "ipc_interfaceTC.h"

#ifndef DBGID
#define DBGID  "hc:cltcnu"
#endif

#ifndef DBGID
#define DBGID "defalut"
#endif 


LOCAL_COMMIT_DECLARE();

#define local_commit()  LOCAL_COMMIT(500, cltNetworkUnitInterfaceTable_commit, NULL)


/** Initializes the cltNetworkUnitInterfaceTable module */
void
init_cltNetworkUnitInterfaceTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_cltNetworkUnitInterfaceTable();
}

//# Determine the first/last column names

/** Initialize the cltNetworkUnitInterfaceTable table by defining its contents and how it's structured */
void
initialize_table_cltNetworkUnitInterfaceTable(void)
{
    static oid      cltNetworkUnitInterfaceTable_oid[] =
        { 1, 3, 6, 1, 4, 1, 36368, 1, 1, 1, 1, 4, 3, 7 };
    size_t          cltNetworkUnitInterfaceTable_oid_len =
        OID_LENGTH(cltNetworkUnitInterfaceTable_oid);
    netsnmp_handler_registration *reg;
    netsnmp_iterator_info *iinfo;
    netsnmp_table_registration_info *table_info;

	DEBUGMSGTL((DBGID, "Initializing\n"));

    reg =
        netsnmp_create_handler_registration("cltNetworkUnitInterfaceTable",
                                            cltNetworkUnitInterfaceTable_handler,
                                            cltNetworkUnitInterfaceTable_oid,
                                            cltNetworkUnitInterfaceTable_oid_len,
                                            HANDLER_CAN_RWRITE);

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    netsnmp_table_helper_add_indexes(table_info, ASN_OCTET_STR, /* index: cltNetworkUnitMACAddress */
                                     ASN_INTEGER,       /* index: cltNetworkUnitIfIndex */
                                     0);
    table_info->min_column = COLUMN_CLTNETWORKUNITIFNETWORKUNITMACADDRESS;
    table_info->max_column = COLUMN_CLTNETWORKUNITIFSTATUS;

    iinfo = SNMP_MALLOC_TYPEDEF(netsnmp_iterator_info);
    iinfo->get_first_data_point =
        cltNetworkUnitInterfaceTable_get_first_data_point;
    iinfo->get_next_data_point =
        cltNetworkUnitInterfaceTable_get_next_data_point;
    iinfo->table_reginfo = table_info;

    netsnmp_register_table_iterator(reg, iinfo);

    netsnmp_inject_handler( reg,
		    netsnmp_get_cache_handler(HC_CACHE_TIMEOUT,
			   		cltNetworkUnitInterfaceTable_load, cltNetworkUnitInterfaceTable_free,
					cltNetworkUnitInterfaceTable_oid, OID_LENGTH(cltNetworkUnitInterfaceTable_oid)));
    DEBUGMSGTL((DBGID,
                "initialize cltNetworkUnitInterfaceTable\n"));     

    /*
     * Initialise the contents of the table here 
     */
}

    /*
     * Typical data structure for a row entry 
     */
struct cltNetworkUnitInterfaceTable_entry {
    /*
     * Index values 
     */
    unsigned char            cltNetworkUnitMACAddress[HC_MAC_ADDRESS_SIZE];
    size_t          cltNetworkUnitMACAddress_len;
    long            cltNetworkUnitIfIndex;

    /*
     * Column values 
     */
    unsigned char            cltNetworkUnitIfNetworkUnitMACAddress[HC_MAC_ADDRESS_SIZE];
    size_t          cltNetworkUnitIfNetworkUnitMACAddress_len;
 //   long            cltNetworkUnitIfIndex;
    long            cltNetworkUnitIfType;
    char            cltNetworkUnitIfName[HC_IFNAME_SIZE];
    size_t          cltNetworkUnitIfName_len;
    long            cltNetworkUnitIfLinkStatus;
    long            cltNetworkUnitIfSpeed;
    u_long          cltNetworkUnitIfTXPackets;
    u_long          cltNetworkUnitIfRXPackets;
    long            cltNetworkUnitIfStatus;
    long            old_cltNetworkUnitIfStatus;

    /*
     * Illustrate using a simple linked list 
     */
    int             valid;
    struct cltNetworkUnitInterfaceTable_entry *next;
};

struct cltNetworkUnitInterfaceTable_entry
    *cltNetworkUnitInterfaceTable_head;

/*
 * create a new row in the (unsorted) table 
 */
struct cltNetworkUnitInterfaceTable_entry *
cltNetworkUnitInterfaceTable_createEntry(unsigned char *cltNetworkUnitMACAddress,
                                         size_t
                                         cltNetworkUnitMACAddress_len,
                                         long cltNetworkUnitIfIndex,
										struct cltNetworkUnitInterfaceTable_entry
										    *cltNetworkUnitInterfaceTable )
{
    struct cltNetworkUnitInterfaceTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct cltNetworkUnitInterfaceTable_entry);
    if (!entry)
        return NULL;
	memcpy(entry, cltNetworkUnitInterfaceTable, sizeof(*entry));

    memcpy(entry->cltNetworkUnitMACAddress, cltNetworkUnitMACAddress,
           cltNetworkUnitMACAddress_len);
    entry->cltNetworkUnitMACAddress_len = cltNetworkUnitMACAddress_len;
    entry->cltNetworkUnitIfIndex = cltNetworkUnitIfIndex;
    entry->next = cltNetworkUnitInterfaceTable_head;
    cltNetworkUnitInterfaceTable_head = entry;
    return entry;
}

/*
 * remove a row from the table 
 */
void
cltNetworkUnitInterfaceTable_removeEntry(struct
                                         cltNetworkUnitInterfaceTable_entry
                                         *entry)
{
    struct cltNetworkUnitInterfaceTable_entry *ptr, *prev;

    if (!entry)
        return;                 /* Nothing to remove */

    for (ptr = cltNetworkUnitInterfaceTable_head, prev = NULL;
         ptr != NULL; prev = ptr, ptr = ptr->next) {
        if (ptr == entry)
            break;
    }
    if (!ptr)
        return;                 /* Can't find it */

    if (prev == NULL)
        cltNetworkUnitInterfaceTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE(entry);           /* XXX - release any other internal resources */
}


void cltNetworkUnitInterfaceTable_removeAllEntry(void )
{
    struct cltNetworkUnitInterfaceTable_entry *ptr, *pnext;

    for (ptr = cltNetworkUnitInterfaceTable_head; ptr != NULL; ptr = pnext) {
		 pnext = ptr->next;
		 SNMP_FREE(ptr); 
    }
	cltNetworkUnitInterfaceTable_head = NULL;
}


void cltNetworkUnitInterfaceTable_setEntry(
				struct cltNetworkUnitInterfaceTable_entry *entry, 
				ipc_cnu_info_t *cnu, struct device_stats *stats, int portid)
{
	ipc_cnu_port_mib_t *p = &stats->ports[portid];
	static char *ifname[] = {"Cable", "Ethernet 0", "Ethernet 1", "Ethernet 2", "Ethernet 3"};

	if (portid >= cnu->ports){
		snmp_log(LOG_ERR, "CNU Port index exceed cnu->ports");
		return ;
	}
	
	memcpy(	entry->cltNetworkUnitIfNetworkUnitMACAddress, cnu->mac.octet, sizeof(ether_addr_t));
	entry->cltNetworkUnitIfNetworkUnitMACAddress_len = sizeof(ether_addr_t);
	entry->cltNetworkUnitIfType = (portid == 0) ? IFType_cable : IFType_ethernet;
	safe_strncpy(entry->cltNetworkUnitIfName, ifname[portid], sizeof(entry->cltNetworkUnitIfName));
	entry->cltNetworkUnitIfName_len = strlen(entry->cltNetworkUnitIfName);

	if (stats->valid_port_mibs){
		entry->cltNetworkUnitIfLinkStatus = p->link ? IFLink_on : IFLink_off;
		entry->cltNetworkUnitIfSpeed = p->spd ? IFSpeed_100m : IFSpeed_10m;
		entry->cltNetworkUnitIfTXPackets = p->txpacket;
		entry->cltNetworkUnitIfRXPackets = p->rxpacket;		
		entry->cltNetworkUnitIfStatus = CNUTopologyStatus_active;
	}else {
		entry->cltNetworkUnitIfLinkStatus = IFLink_off;
		entry->cltNetworkUnitIfSpeed = IFSpeed_100m;
		entry->cltNetworkUnitIfTXPackets = 0;
		entry->cltNetworkUnitIfRXPackets = 0;			
		entry->cltNetworkUnitIfStatus = CNUTopologyStatus_nonInService;
	}
}



/*
 * Example iterator hook routines - using 'get_next' to do most of the work 
 */
netsnmp_variable_list *
cltNetworkUnitInterfaceTable_get_first_data_point(void **my_loop_context,
                                                  void **my_data_context,
                                                  netsnmp_variable_list *
                                                  put_index_data,
                                                  netsnmp_iterator_info
                                                  *mydata)
{
    *my_loop_context = cltNetworkUnitInterfaceTable_head;
    return
        cltNetworkUnitInterfaceTable_get_next_data_point(my_loop_context,
                                                         my_data_context,
                                                         put_index_data,
                                                         mydata);
}

netsnmp_variable_list *
cltNetworkUnitInterfaceTable_get_next_data_point(void **my_loop_context,
                                                 void **my_data_context,
                                                 netsnmp_variable_list *
                                                 put_index_data,
                                                 netsnmp_iterator_info
                                                 *mydata)
{
    struct cltNetworkUnitInterfaceTable_entry *entry =
        (struct cltNetworkUnitInterfaceTable_entry *) *my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if (entry) {
        snmp_set_var_value(idx, entry->cltNetworkUnitMACAddress,
                           sizeof(entry->cltNetworkUnitMACAddress));
        idx = idx->next_variable;
        snmp_set_var_typed_integer(idx, ASN_INTEGER,
                                   entry->cltNetworkUnitIfIndex);
        idx = idx->next_variable;
        *my_data_context = (void *) entry;
        *my_loop_context = (void *) entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the cltNetworkUnitInterfaceTable table */
int
cltNetworkUnitInterfaceTable_handler(netsnmp_mib_handler *handler,
                                     netsnmp_handler_registration *reginfo,
                                     netsnmp_agent_request_info *reqinfo,
                                     netsnmp_request_info *requests)
{
	int ret;
    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    struct cltNetworkUnitInterfaceTable_entry *table_entry;

	netsnmp_variable_list *requestvb;	

    if (((reqinfo->mode == MODE_GET) || (reqinfo->mode == MODE_SET_ACTION)) 
		&& !netsnmp_cache_is_valid(reqinfo, reginfo->handlerName)) {
        netsnmp_assert(!"cache == valid"); /* always false */
        cltNetworkUnitInterfaceTable_load( NULL, NULL );	/* XXX - check for failure */
    }

    DEBUGMSGTL((DBGID, "Handler - mode %s\n",
                    se_find_label_in_slist("agent_mode", reqinfo->mode)));

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltNetworkUnitInterfaceTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);		

            switch (table_info->colnum) {
            case COLUMN_CLTNETWORKUNITIFNETWORKUNITMACADDRESS:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->
                                         cltNetworkUnitIfNetworkUnitMACAddress,
                                         table_entry->
                                         cltNetworkUnitIfNetworkUnitMACAddress_len);
                break;
            case COLUMN_CLTNETWORKUNITIFINDEX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltNetworkUnitIfIndex);
                break;
            case COLUMN_CLTNETWORKUNITIFTYPE:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltNetworkUnitIfType);
                break;
            case COLUMN_CLTNETWORKUNITIFNAME:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->
                                         cltNetworkUnitIfName,
                                         table_entry->
                                         cltNetworkUnitIfName_len);
                break;
            case COLUMN_CLTNETWORKUNITIFLINKSTATUS:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltNetworkUnitIfLinkStatus);
                break;
            case COLUMN_CLTNETWORKUNITIFSPEED:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltNetworkUnitIfSpeed);
                break;
            case COLUMN_CLTNETWORKUNITIFTXPACKETS:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_COUNTER,
                                           table_entry->
                                           cltNetworkUnitIfTXPackets);
                break;
            case COLUMN_CLTNETWORKUNITIFRXPACKETS:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_COUNTER,
                                           table_entry->
                                           cltNetworkUnitIfRXPackets);
                break;
            case COLUMN_CLTNETWORKUNITIFSTATUS:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltNetworkUnitIfStatus);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

        /*
         * Write-support
         */
    case MODE_SET_RESERVE1:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltNetworkUnitInterfaceTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);		

            switch (table_info->colnum) {
            case COLUMN_CLTNETWORKUNITIFSTATUS:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
				if (!validCNUTopologyStatus(vb_int(requestvb))){
                    netsnmp_set_request_error(reqinfo, request, SNMP_ERR_WRONGVALUE);
                    return SNMP_ERR_NOERROR;
				}
								
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_ERR_NOTWRITABLE);
                return SNMP_ERR_NOERROR;
            }
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltNetworkUnitInterfaceTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);		

            switch (table_info->colnum) {
            case COLUMN_CLTNETWORKUNITIFSTATUS:
                table_entry->old_cltNetworkUnitIfStatus =
                    table_entry->cltNetworkUnitIfStatus;
                table_entry->cltNetworkUnitIfStatus =
                    *request->requestvb->val.integer;
                break;
            }
        }
        break;

    case MODE_SET_UNDO:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltNetworkUnitInterfaceTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);		

            switch (table_info->colnum) {
            case COLUMN_CLTNETWORKUNITIFSTATUS:
                table_entry->cltNetworkUnitIfStatus =
                    table_entry->old_cltNetworkUnitIfStatus;
                table_entry->old_cltNetworkUnitIfStatus = 0;
                break;
            }
        }
        break;

    case MODE_SET_COMMIT:
		local_commit();
        break;
    }
    return SNMP_ERR_NOERROR;
}

int cltNetworkUnitInterfaceTable_load(netsnmp_cache *cache, void *vmagic)
{
   int ret, i, n;
   struct cltNetworkUnitInterfaceTable_entry entry;
   struct device_stats *p, stats;
	   
   ret = device_topology_update(0);
   
   if (HC_IPC_ERROR(ret)) {
	   CLR_VALID();
	   DEBUGMSGTL((DBGID, "Failed to load cltNetworkUnitInterfaceTable Group\n"));
   } else {
	   SET_VALID();
	   DEBUGMSGTL((DBGID, "Loaded cltNetworkUnitInterfaceTable Group\n"));
   }
   
   HC_IPC_ASSERT(ret);
   
   for (i = 0; i < device_topology_num; i ++){
   	   p = device_stats_search(&device_topology[i].mac);
	   if (p == NULL){
			device_stats_init(&stats, &device_topology[i]);
			p = &stats;
	   }
	   for (n = 0; n < device_topology[i].ports; n ++){
		   cltNetworkUnitInterfaceTable_setEntry(&entry, &device_topology[i], p, n);
		   cltNetworkUnitInterfaceTable_createEntry(device_topology[i].mac.octet,
								sizeof(ether_addr_t), n + 1, &entry);			
	   }
   }
   
   return ret; 

} 

void cltNetworkUnitInterfaceTable_free(netsnmp_cache *cache, void *magic)
{
	DEBUGMSGTL((DBGID, "Free cltNetworkUnitInterfaceTable Group\n"));  
	
	cltNetworkUnitInterfaceTable_removeAllEntry();
}


void cltNetworkUnitInterfaceTable_commit(unsigned int regNo, void *clientargs)
{
	long ret;
	struct cltNetworkUnitInterfaceTable_entry *ptr;
	ether_addr_t mac;
	
	HC_VALID_ASSERT();

// refresh if any
	for (ptr = cltNetworkUnitInterfaceTable_head; ptr != NULL; ptr = ptr->next) {
		if (ptr->cltNetworkUnitIfStatus == CNUTopologyStatus_refresh){
			memcpy(mac.octet, ptr->cltNetworkUnitMACAddress, sizeof(ether_addr_t));
			ret = device_port_mibs_update(&mac);
		}
	}
	DEBUGMSGTL((DBGID, "Commited cltNetworkUnitInterfaceTable Group\n"));  	
}


