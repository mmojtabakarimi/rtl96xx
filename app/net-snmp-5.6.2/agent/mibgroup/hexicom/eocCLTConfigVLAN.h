/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */
#ifndef EOCCLTCONFIGVLAN_H
#define EOCCLTCONFIGVLAN_H

/*
 * function declarations 
 */
void            init_eocCLTConfigVLAN(void);
Netsnmp_Node_Handler handle_cltConfigVLANMode;
Netsnmp_Node_Handler handle_cltConfigVLANTotalNumber;

int cltConfigVLANMode_load(netsnmp_cache *cache, void *vmagic);
void cltConfigVLANMode_free(netsnmp_cache *cache, void *vmagic);
void cltConfigVLANMode_commit(unsigned int regNo, void *clientargs);


#endif                          /* EOCCLTCONFIGVLAN_H */
