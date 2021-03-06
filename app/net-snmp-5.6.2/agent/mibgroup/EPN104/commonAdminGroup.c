/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 17337 2009-01-01 14:28:29Z magfr $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "commonAdminGroup.h"

#include "../product_common/snmp_ipc_interface.h"
#include "../product_common/snmp_ipc_interfaceTC.h"

/** Initializes the commonAdminGroup module */
void
init_commonAdminGroup(void)
{
    const oid       commonNELogicalID_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 1, 3, 1, 1 };
    const oid       commonCheckCode_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 1, 3, 1, 10 };
    const oid       commonTrapCommunityString_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 1, 3, 1, 11 };
    const oid       commonDeviceOID_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 1, 3, 1, 18 };

    DEBUGMSGTL(("commonAdminGroup", "Initializing\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("commonNELogicalID", handle_commonNELogicalID,
                             commonNELogicalID_oid,
                             OID_LENGTH(commonNELogicalID_oid),
                             HANDLER_CAN_RWRITE));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("commonCheckCode", handle_commonCheckCode,
                             commonCheckCode_oid,
                             OID_LENGTH(commonCheckCode_oid),
                             HANDLER_CAN_RWRITE));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("commonTrapCommunityString",
                             handle_commonTrapCommunityString,
                             commonTrapCommunityString_oid,
                             OID_LENGTH(commonTrapCommunityString_oid),
                             HANDLER_CAN_RWRITE));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("commonDeviceOID", handle_commonDeviceOID,
                             commonDeviceOID_oid,
                             OID_LENGTH(commonDeviceOID_oid),
                             HANDLER_CAN_RONLY));
}

int
handle_commonNELogicalID(netsnmp_mib_handler *handler,
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
	char val[COMMONDEVICESID_MAX] = {0};
	u_char buf[COMMONDEVICESID_MAX+1] = {0};
	int i = 0;
	strncpy(val, " ", sizeof(val));
	commonAdminGroup_t pinfo ;
	ipc_commonAdminGroup_ack_t *pack_send = NULL;

	ipc_commonAdminGroup_ack_t *pack = NULL;
	
	memset(&pinfo, 0, sizeof(commonAdminGroup_t));
	pack = ipc_commonAdminGroup(ipc_fd, IPC_CONFIG_GET, IPC_APPLY_NONE, NULL);
	if(pack && pack->hdr.status == IPC_STATUS_OK) 
	{		
		memcpy(&pinfo, &pack->commonAdminGroup, sizeof(commonAdminGroup_t));
		memcpy(val, pinfo.commonNELogicalID, sizeof(val));
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
    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 (u_char *)val
                                 /* XXX: a pointer to the scalar's data */
                                 ,strlen(val)
                                 /*
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
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_OCTET_STR);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
         #if 0
        if ( /* XXX if malloc, or whatever, failed: */ ) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_RESOURCEUNAVAILABLE);
        }
		#endif
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
        #if 1 
        if (requests->requestvb->val.string) 
        {        	
			if(0 != memcmp(requests->requestvb->val.string, val, requests->requestvb->val_len))
			{
				memcpy(buf,requests->requestvb->val.string,
                       requests->requestvb->val_len);
				for(i=0; i<requests->requestvb->val_len; i++)
				{	
					if(buf)
					{
						if((buf[i] < 0x20) || (buf[i] > 0x7e) || (buf[i] == '\\') || 
						 (buf[i] == '\/') || (buf[i] == '\"')  || (buf[i] == '\'') ||
						 (buf[i] == '\;') || (buf[i] == '#') || ((0 == i) && (buf[i] == ' ')))
						{
							DEBUGMSGTL(("system_mib","invaid value=0x%02x\n", buf[i]));
							return SNMP_ERR_GENERR;
						}
					}
				}
				memset(pinfo.commonNELogicalID, 0, sizeof(pinfo.commonNELogicalID));

				memcpy(pinfo.commonNELogicalID, requests->requestvb->val.string, requests->requestvb->val_len);

				pack_send = ipc_commonAdminGroup(ipc_fd, IPC_CONFIG_SET, IPC_APPLY_NOW, &pinfo);
				if((!pack_send) || (pack_send->hdr.status != IPC_STATUS_OK)) 
				{		
					if(pack_send)
					{
						free(pack_send);
					}
					return SNMP_ERR_GENERR;
				}
				if(pack_send)
				{
					free(pack_send);
				}
				ret = ipc_system_request(IPC_SYS_NVRAM_COMMIT);
				if(IPC_STATUS_OK != ret)
			    {
			        printf("System running config saved to flash memory failed!");	   
				}
			}
		}
		else {
            netsnmp_set_request_error(reqinfo, requests, /* some error */SNMP_ERR_BADVALUE
                                      );
        }
		#endif
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
         #if 0
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_COMMITFAILED);
        }
		#endif
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
         #if 0
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_UNDOFAILED);
        }
		#endif
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_commonNELogicalID\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_commonCheckCode(netsnmp_mib_handler *handler,
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
	unsigned long commonCheckCode = 0x47013600;
	commonAdminGroup_t pinfo ;
	ipc_commonAdminGroup_ack_t *pack_send = NULL;
#if 1
	ipc_commonAdminGroup_ack_t *pack = NULL;
	memset(&pinfo, 0, sizeof(commonAdminGroup_t));
	pack = ipc_commonAdminGroup(ipc_fd, IPC_CONFIG_GET, IPC_APPLY_NONE, NULL);
	if(pack && pack->hdr.status == IPC_STATUS_OK) 
	{		
		memcpy(&pinfo, &pack->commonAdminGroup, sizeof(commonAdminGroup_t));
		commonCheckCode = pinfo.commonCheckCode;
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
    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)&commonCheckCode
                                 /* XXX: a pointer to the scalar's data */
                                 ,sizeof(&commonCheckCode)
                                 /*
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
        }
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
         #if 0
        if ( /* XXX if malloc, or whatever, failed: */ ) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_RESOURCEUNAVAILABLE);
        }
		#endif
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
        #if 0
       	if (requests->requestvb->val.integer) 
        {
			if(*requests->requestvb->val.integer != commonCheckCode)
			{
				pinfo.commonCheckCode = *requests->requestvb->val.integer;

				pack_send = ipc_commonAdminGroup(ipc_fd, IPC_CONFIG_SET, IPC_APPLY_NOW, &pinfo);
				if((!pack_send) || (pack_send->hdr.status != IPC_STATUS_OK)) 
				{		
					if(pack_send)
					{
						free(pack_send);
					}
					return SNMP_ERR_GENERR;
				}
				if(pack_send)
				{
					free(pack_send);
				}
				ret = ipc_system_request(IPC_SYS_NVRAM_COMMIT);
				if(IPC_STATUS_OK != ret)
			    {
			        printf("System running config saved to flash memory failed!");	   
				}
			}
		}
		else {
            netsnmp_set_request_error(reqinfo, requests, /* some error */SNMP_ERR_BADVALUE
                                      );
        }
		#endif
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
         #if 0
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_COMMITFAILED);
        }
		#endif
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
         #if 0
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_UNDOFAILED);
        }
		#endif
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_commonCheckCode\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_commonTrapCommunityString(netsnmp_mib_handler *handler,
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
	char val[MAX_COMMUNITY_SIZE] = {0}; 
	memcpy(val, "public", sizeof(val));
	commonAdminGroup_t pinfo ;
	ipc_commonAdminGroup_ack_t *pack_send = NULL;

	ipc_commonAdminGroup_ack_t *pack = NULL;
	
	memset(&pinfo, 0, sizeof(commonAdminGroup_t));
	pack = ipc_commonAdminGroup(ipc_fd, IPC_CONFIG_GET, IPC_APPLY_NONE, NULL);
	if(pack && pack->hdr.status == IPC_STATUS_OK) 
	{		
		memcpy(&pinfo, &pack->commonAdminGroup, sizeof(commonAdminGroup_t));
		memcpy(val, pinfo.commonTrapCommunityString, sizeof(val));
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
    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 (u_char *)val
                                 /* XXX: a pointer to the scalar's data */
                                 ,strlen(val)
                                 /*
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
        ret = netsnmp_check_vb_type(requests->requestvb, ASN_OCTET_STR);
        if (ret != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, ret);
        }
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
         #if 0
        if ( /* XXX if malloc, or whatever, failed: */ ) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_RESOURCEUNAVAILABLE);
        }
		#endif
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
        #if 1			
        if (requests->requestvb->val_len) 
        {
			if(0 != memcmp(requests->requestvb->val.string, val, requests->requestvb->val_len))
			{
				memcpy(pinfo.commonTrapCommunityString, requests->requestvb->val.string, sizeof(pinfo.commonTrapCommunityString));

				pack_send = ipc_commonAdminGroup(ipc_fd, IPC_CONFIG_SET, IPC_APPLY_NOW, &pinfo);
				if((!pack_send) || (pack_send->hdr.status != IPC_STATUS_OK)) 
				{		
					if(pack_send)
					{
						free(pack_send);
					}
					return SNMP_ERR_GENERR;
				}
				if(pack_send)
				{
					free(pack_send);
				}
				ret = ipc_system_request(IPC_SYS_NVRAM_COMMIT);
				if(IPC_STATUS_OK != ret)
			    {
			        printf("System running config saved to flash memory failed!");	   
				}
			}
		}
		else  {
            netsnmp_set_request_error(reqinfo, requests, /* some error */SNMP_ERR_BADVALUE
                                      );
        }
		#endif
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
         #if 0
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_COMMITFAILED);
        }
		#endif
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
         #if 0
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_UNDOFAILED);
        }
		#endif
        break;

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_commonTrapCommunityString\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_commonDeviceOID(netsnmp_mib_handler *handler,
                       netsnmp_handler_registration *reginfo,
                       netsnmp_agent_request_info *reqinfo,
                       netsnmp_request_info *requests)
{
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */
	const oid		commonDeviceOID_oid[] =
				{ 1, 3, 6, 1, 4, 1, 17409, 1, 9 };

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_OBJECT_ID,
                                 (u_char *)commonDeviceOID_oid
                                 /* XXX: a pointer to the scalar's data */
                                 ,sizeof(commonDeviceOID_oid)
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_commonDeviceOID\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
