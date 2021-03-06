/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "cltConfigNetworking.h"

#include "hexicomTC.h"

#ifndef DBGID
#define DBGID  "hc:cltnetwork"
#endif 

#ifndef DBGID
#define DBGID "defalut"
#endif 


LOCAL_COMMIT_DECLARE();

#define local_commit()  LOCAL_COMMIT(500, cltConfigNetworking_commit, NULL)


static sys_network_t info;



static oid	cltConfigNetworking_oid[] = { HC_CLT_OBJ_OID, 2, 1, 3};



void init_cltConfigNetworking(void)
{
    netsnmp_handler_registration *reginfo;

    /*
     * register ourselves with the agent as a group of scalars...
     */
		
	DEBUGMSGTL((DBGID, "Initializing\n"));

    reginfo = netsnmp_create_handler_registration("cltConfigNetworking", cltConfigNetworking_handler,
		    cltConfigNetworking_oid, OID_LENGTH(cltConfigNetworking_oid), HANDLER_CAN_RWRITE);
	
    netsnmp_register_scalar_group(reginfo, CLTCONFIGNETWORKHOSTNAME, CLTCONFIGNETWORKALTERNATIVEDNS);


    netsnmp_inject_handler( reginfo,
		    netsnmp_get_cache_handler(  HC_CACHE_TIMEOUT,
			   		cltConfigNetworking_load, cltConfigNetworking_free,
					cltConfigNetworking_oid, OID_LENGTH(cltConfigNetworking_oid)));

}



int
handle_cltConfigNetworkHostname(netsnmp_mib_handler *handler,
                                netsnmp_handler_registration *reginfo,
                                netsnmp_agent_request_info *reqinfo,
                                netsnmp_request_info *requests)
{
    int             ret;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 (u_char *)info.hostname,
                                 strlen(info.hostname));
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_OCTET_STR);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
			break;
        }
        ret = netsnmp_check_vb_max_size(requests->requestvb, sizeof(info.hostname) - 1);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
			break;
        }		

		if (!valid_hostname(vb_strdup(requests->requestvb))){
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
			break;			
		}

        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
        vb_str_set(requests->requestvb, info.hostname);
		
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
		local_commit();		
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_cltConfigNetworkHostname\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_cltConfigNetworkIPMode(netsnmp_mib_handler *handler,
                              netsnmp_handler_registration *reginfo,
                              netsnmp_agent_request_info *reqinfo,
                              netsnmp_request_info *requests)
{
    int             ret;
	static int value = 0;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
		value = (info.ip_proto == IP_PROTO_STATIC) ? IPMode_static : IPMode_dynamic;
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)&value
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 HC_INTEGER_SIZE/*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
			break;
        }		

		if (!validIPMode(vb_int(requests->requestvb))){
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
			break;			
		}		
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */

        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
        info.ip_proto = (vb_int(requests->requestvb) == IPMode_static) ? IP_PROTO_STATIC : IP_PROTO_DYNAMIC;
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
		local_commit();
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_cltConfigNetworkIPMode\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_cltConfigNetworkIPAddress(netsnmp_mib_handler *handler,
                                 netsnmp_handler_registration *reginfo,
                                 netsnmp_agent_request_info *reqinfo,
                                 netsnmp_request_info *requests)
{
    int             ret;
	struct in_addr ip;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_IPADDRESS,
                                 (u_char *)&info.netif.ip.s_addr
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 HC_IP_ADDRESS_SIZE/*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_IPADDRESS);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }

        ret = netsnmp_check_vb_size(requests->requestvb, HC_IP_ADDRESS_SIZE);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
			break;
        }		
		ip.s_addr = vb_int(requests->requestvb);
		if (!valid_ip(ip)){
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
			break;			
		}			
		
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */

        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
        info.netif.ip.s_addr = vb_int(requests->requestvb);
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
		local_commit();

        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_cltConfigNetworkIPAddress\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_cltConfigNetworkSubnetMask(netsnmp_mib_handler *handler,
                                  netsnmp_handler_registration *reginfo,
                                  netsnmp_agent_request_info *reqinfo,
                                  netsnmp_request_info *requests)
{
    int             ret;
	struct in_addr ip;	
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_IPADDRESS,
                                 (u_char *)&info.netif.subnet.s_addr
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 HC_IP_ADDRESS_SIZE/*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_IPADDRESS);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        ret = netsnmp_check_vb_size(requests->requestvb, HC_IP_ADDRESS_SIZE);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
			break;
        }		
		ip.s_addr = vb_int(requests->requestvb);
		if (!valid_subnet_mask(ip, ip)){
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
			break;			
		}			
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */

        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
	 info.netif.subnet.s_addr = vb_int(requests->requestvb);			
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
		local_commit();

        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_cltConfigNetworkSubnetMask\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_cltConfigNetworkDefaultGateway(netsnmp_mib_handler *handler,
                                      netsnmp_handler_registration
                                      *reginfo,
                                      netsnmp_agent_request_info *reqinfo,
                                      netsnmp_request_info *requests)
{
    int             ret;
	struct in_addr ip;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_IPADDRESS,
                                 (u_char *)&info.netif.gateway.s_addr
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 HC_IP_ADDRESS_SIZE/*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_IPADDRESS);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        ret = netsnmp_check_vb_size(requests->requestvb, HC_IP_ADDRESS_SIZE);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
			break;
        }		
		ip.s_addr = vb_int(requests->requestvb);
		if (!valid_ip(ip)){
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
			break;			
		}			
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
		info.netif.gateway.s_addr = vb_int(requests->requestvb);			
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
		local_commit();
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_cltConfigNetworkDefaultGateway\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_cltConfigNetworkDNS(netsnmp_mib_handler *handler,
                           netsnmp_handler_registration *reginfo,
                           netsnmp_agent_request_info *reqinfo,
                           netsnmp_request_info *requests)
{
    int             ret;
	struct in_addr ip;	
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_IPADDRESS,
                                 (u_char *)&info.netif.dns[0].s_addr
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 HC_IP_ADDRESS_SIZE/*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_IPADDRESS);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        ret = netsnmp_check_vb_size(requests->requestvb, HC_IP_ADDRESS_SIZE);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
			break;
        }		
		ip.s_addr = vb_int(requests->requestvb);
		if (!valid_ip(ip)){
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
			break;			
		}		
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */

        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
		info.netif.dns[0].s_addr = vb_int(requests->requestvb);	         
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
		local_commit();

        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_cltConfigNetworkDNS\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_cltConfigNetworkAlternativeDNS(netsnmp_mib_handler *handler,
                                      netsnmp_handler_registration
                                      *reginfo,
                                      netsnmp_agent_request_info *reqinfo,
                                      netsnmp_request_info *requests)
{
    int             ret;
	struct in_addr ip;	
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_IPADDRESS,
                                 (u_char *)&info.netif.dns[1].s_addr
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                HC_IP_ADDRESS_SIZE/*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_IPADDRESS);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        ret = netsnmp_check_vb_size(requests->requestvb, HC_IP_ADDRESS_SIZE);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
			break;
        }		
		ip.s_addr = vb_int(requests->requestvb);
		if (!valid_ip(ip)){
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
			break;			
		}

		
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */

        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
		info.netif.dns[1].s_addr = vb_int(requests->requestvb);	
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
		local_commit();

        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_cltConfigNetworkAlternativeDNS\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}




int cltConfigNetworking_handler(netsnmp_mib_handler          *handler,
             netsnmp_handler_registration *reginfo,
             netsnmp_agent_request_info   *reqinfo,
             netsnmp_request_info         *requests)
{
    netsnmp_request_info  *request;
    netsnmp_variable_list *requestvb;
    oid      subid;

    /*
     * The cached data should already have been loaded by the
     *    cache handler, higher up the handler chain.
     * But just to be safe, check this and load it manually if necessary
     */

    if (((reqinfo->mode == MODE_GET) || (reqinfo->mode == MODE_SET_ACTION)) 
		&& !netsnmp_cache_is_valid(reqinfo, reginfo->handlerName)) {
        netsnmp_assert(!"cache == valid"); /* always false */
        cltConfigNetworking_load( NULL, NULL );	/* XXX - check for failure */
    }

    DEBUGMSGTL((DBGID, "Handler - mode %s\n",
                    se_find_label_in_slist("agent_mode", reqinfo->mode)));

	for (request=requests; request; request=request->next) {
		requestvb = request->requestvb;
		subid = requestvb->name[OID_LENGTH(cltConfigNetworking_oid)];  /* XXX */

		HC_DBG_OID(requestvb);
		
		switch(subid){
		case CLTCONFIGNETWORKHOSTNAME:
			handle_cltConfigNetworkHostname(handler, reginfo, reqinfo, request);
			break;
		case CLTCONFIGNETWORKIPMODE:
			handle_cltConfigNetworkIPMode(handler, reginfo, reqinfo, request);
			break;
		case CLTCONFIGNETWORKIPADDRESS:
			handle_cltConfigNetworkIPAddress(handler, reginfo, reqinfo, request);
			break;			
		case CLTCONFIGNETWORKSUBNETMASK:
			handle_cltConfigNetworkSubnetMask(handler, reginfo, reqinfo, request);
			break;
		case CLTCONFIGNETWORKDEFAULTGATEWAY:
			handle_cltConfigNetworkDefaultGateway(handler, reginfo, reqinfo, request);
			break;
		case CLTCONFIGNETWORKDNS:
			handle_cltConfigNetworkDNS(handler, reginfo, reqinfo, request);
			break;			
		case CLTCONFIGNETWORKALTERNATIVEDNS:
			handle_cltConfigNetworkAlternativeDNS(handler, reginfo, reqinfo, request);
			break;
		}
	
	}

   return SNMP_ERR_NOERROR;
}



int cltConfigNetworking_load(netsnmp_cache *cache, void *vmagic)
{
    long            ret_value = -1;
	ret_value = ipc_get_sys_networking(&info);
	
    if (HC_IPC_ERROR(ret_value)) {
		CLR_VALID();
		DEBUGMSGTL((DBGID, "Failed to load cltConfigNetworking Group\n"));
    } else {
		SET_VALID();
        DEBUGMSGTL((DBGID, "Loaded cltConfigNetworking Group\n"));
    }

	HC_IPC_ASSERT(ret_value);

    return ret_value;
}


void cltConfigNetworking_free(netsnmp_cache *cache, void *magic)
{
	DEBUGMSGTL((DBGID, "Free cltConfigNetworking Group\n"));
}


void cltConfigNetworking_commit(unsigned int regNo, void *clientargs)
{
	long ret_value;
	ipc_network_t req;

	HC_VALID_ASSERT();

	memcpy(req.hostname, info.hostname, sizeof(req.hostname));
	req.ip_proto = info.ip_proto;
	memcpy(&req.netif, &info.netif, sizeof(req.netif));

	if (req.ip_proto == IP_PROTO_DYNAMIC){
		req.action = ACTION_RENEW;
	}

	ret_value = ipc_set_sys_networking(&req);
	if (HC_IPC_ERROR(ret_value)) {
		DEBUGMSGTL((DBGID, "Failed to commit cltConfigNetworking Group\n"));
	} else {
		DEBUGMSGTL((DBGID, "Commited cltConfigNetworking Group\n"));
	}

	HC_IPC_ASSERT1(ret_value);
}


