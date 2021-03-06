/*
 * Copyright (C) 2012 Realtek Semiconductor Corp. 
 * All Rights Reserved.
 *
 * This program is the proprietary software of Realtek Semiconductor
 * Corporation and/or its licensors, and only be used, duplicated, 
 * modified or distributed under the authorized license from Realtek. 
 *
 * ANY USE OF THE SOFTWARE OTHER THAN AS AUTHORIZED UNDER 
 * THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED. 
 *
 */



#ifndef __MIB_ETHPMHISTORYDATA3_TABLE_H__
#define __MIB_ETHPMHISTORYDATA3_TABLE_H__

/* Table SWImage attribute len, only string attrubutes have length definition */

/* Table EthPmHistoryData3 attribute index */
#define MIB_TABLE_ETHPMHISTORYDATA3_ATTR_NUM (17)
#define MIB_TABLE_ETHPMHISTORYDATA3_ENTITYID_INDEX ((MIB_ATTR_INDEX)1)
#define MIB_TABLE_ETHPMHISTORYDATA3_INTERVALENDTIME_INDEX ((MIB_ATTR_INDEX)2)
#define MIB_TABLE_ETHPMHISTORYDATA3_THRESHOLDDATA12ID_INDEX ((MIB_ATTR_INDEX)3)
#define MIB_TABLE_ETHPMHISTORYDATA3_DROPEVENTS_INDEX ((MIB_ATTR_INDEX)4)
#define MIB_TABLE_ETHPMHISTORYDATA3_OCTETS_INDEX ((MIB_ATTR_INDEX)5)
#define MIB_TABLE_ETHPMHISTORYDATA3_PACKETS_INDEX ((MIB_ATTR_INDEX)6)
#define MIB_TABLE_ETHPMHISTORYDATA3_BROADCASTPACKETS_INDEX ((MIB_ATTR_INDEX)7)
#define MIB_TABLE_ETHPMHISTORYDATA3_MULTICASTPACKETS_INDEX ((MIB_ATTR_INDEX)8)
#define MIB_TABLE_ETHPMHISTORYDATA3_UNDERSIZEPACKETS_INDEX ((MIB_ATTR_INDEX)9)
#define MIB_TABLE_ETHPMHISTORYDATA3_FRAGMENTS_INDEX ((MIB_ATTR_INDEX)10)
#define MIB_TABLE_ETHPMHISTORYDATA3_JABBERS_INDEX ((MIB_ATTR_INDEX)11)
#define MIB_TABLE_ETHPMHISTORYDATA3_PACKETS64OCTETS_INDEX ((MIB_ATTR_INDEX)12)
#define MIB_TABLE_ETHPMHISTORYDATA3_PACKETS65TO127OCTETS_INDEX ((MIB_ATTR_INDEX)13)
#define MIB_TABLE_ETHPMHISTORYDATA3_PACKETS128TO255OCTETS_INDEX ((MIB_ATTR_INDEX)14)
#define MIB_TABLE_ETHPMHISTORYDATA3_PACKETS256TO511OCTETS_INDEX ((MIB_ATTR_INDEX)15)
#define MIB_TABLE_ETHPMHISTORYDATA3_PACKETS512TO1023OCTETS_INDEX ((MIB_ATTR_INDEX)16)
#define MIB_TABLE_ETHPMHISTORYDATA3_PACKETS1024TO1518OCTETS_INDEX ((MIB_ATTR_INDEX)17)

/* Table EthPmHistoryData3 attribute len, only string attrubutes have length definition */
typedef struct {
	UINT16   EntityId;
	UINT8    IntervalEndTime;
	UINT8    resv0[1];
	UINT32   ThresholdData12Id;
	UINT32   DropEvents;
	UINT32   Octets;
	UINT32   Packets;
	UINT32   BroadcastPackets;
	UINT32   MulticastPackets;
	UINT32   UndersizePackets;
	UINT32   Fragments;
	UINT32   Jabbers;
	UINT32   Packets64Octets;
	UINT32   Packets65to127Octets;
	UINT32   Packets128to255Octets;
	UINT32   Packets256to511Octets;
	UINT32   Packets512to1023Octets;
	UINT32   Packets1024to1518Octets;
} MIB_TABLE_ETHPMHISTORYDATA3_T;

#endif /* __MIB_ETHPMHISTORYDATA3_TABLE_H__ */
