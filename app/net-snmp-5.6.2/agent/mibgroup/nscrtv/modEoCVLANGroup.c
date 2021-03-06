/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "modEoCVLANGroup.h"

/** Initializes the modEoCVLANGroup module */
void
init_modEoCVLANGroup(void)
{
    static oid      modEoCVLANVersionNumber_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 9, 1 };
    static oid      modEoCVLANMaxVID_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 9, 2 };
    static oid      modEoCVLANMaxSupportedVLANs_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 9, 3 };
    static oid      modEoCVLANCreatedVLANNumber_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 9, 4 };
    static oid      modEoCVLANVIDList_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 9, 5 };
    static oid      modEoCVLANNextFreeVID_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 2, 4, 9, 6 };

    DEBUGMSGTL(("modEoCVLANGroup", "Initializing\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCVLANVersionNumber",
                             handle_modEoCVLANVersionNumber,
                             modEoCVLANVersionNumber_oid,
                             OID_LENGTH(modEoCVLANVersionNumber_oid),
                             HANDLER_CAN_RONLY));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCVLANMaxVID", handle_modEoCVLANMaxVID,
                             modEoCVLANMaxVID_oid,
                             OID_LENGTH(modEoCVLANMaxVID_oid),
                             HANDLER_CAN_RONLY));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCVLANMaxSupportedVLANs",
                             handle_modEoCVLANMaxSupportedVLANs,
                             modEoCVLANMaxSupportedVLANs_oid,
                             OID_LENGTH(modEoCVLANMaxSupportedVLANs_oid),
                             HANDLER_CAN_RONLY));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCVLANCreatedVLANNumber",
                             handle_modEoCVLANCreatedVLANNumber,
                             modEoCVLANCreatedVLANNumber_oid,
                             OID_LENGTH(modEoCVLANCreatedVLANNumber_oid),
                             HANDLER_CAN_RONLY));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCVLANVIDList", handle_modEoCVLANVIDList,
                             modEoCVLANVIDList_oid,
                             OID_LENGTH(modEoCVLANVIDList_oid),
                             HANDLER_CAN_RONLY));
    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("modEoCVLANNextFreeVID",
                             handle_modEoCVLANNextFreeVID,
                             modEoCVLANNextFreeVID_oid,
                             OID_LENGTH(modEoCVLANNextFreeVID_oid),
                             HANDLER_CAN_RONLY));
}

int
handle_modEoCVLANVersionNumber(netsnmp_mib_handler *handler,
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

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCVLANVersionNumber\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCVLANMaxVID(netsnmp_mib_handler *handler,
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

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_modEoCVLANMaxVID\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCVLANMaxSupportedVLANs(netsnmp_mib_handler *handler,
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

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCVLANMaxSupportedVLANs\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCVLANCreatedVLANNumber(netsnmp_mib_handler *handler,
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

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCVLANCreatedVLANNumber\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCVLANVIDList(netsnmp_mib_handler *handler,
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

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCVLANVIDList\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}

int
handle_modEoCVLANNextFreeVID(netsnmp_mib_handler *handler,
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

    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)
                                 /* XXX: a pointer to the scalar's data */
                                 ,
                                 /*
                                  * XXX: the length of the data in bytes 
                                  */ );
        break;


    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_modEoCVLANNextFreeVID\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
