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


#include "app_basic.h"
#include "omci_defs.h"

MIB_TABLE_INFO_T gMibOnt2gTableInfo;
MIB_ATTR_INFO_T  gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ATTR_NUM];
MIB_TABLE_ONT2G_T gMibOnt2gDefRow;
MIB_TABLE_OPER_T  gMibOnt2gOper;

GOS_ERROR_CODE Ont2gDumpMib(void *pData)
{
	MIB_TABLE_ONT2G_T *pOnt2g = (MIB_TABLE_ONT2G_T*)pData;

	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"%s","Ont2G");	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"EntityID: 0x%02x",pOnt2g->EntityID);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"EqtID: %d",pOnt2g->EqtID);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"Mode: %d",pOnt2g->Mode);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"NumOfGemPort: %d",pOnt2g->NumOfGemPort);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"NumOfPriQ: %d",pOnt2g->NumOfPriQ);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"NumOfScheduler: %d",pOnt2g->NumOfScheduler);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"OMCCVer: %d",pOnt2g->OMCCVer);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"SecCapability: %d",pOnt2g->SecCapability);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"SecMode: %d",pOnt2g->SecMode);	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"VPCode: %d",pOnt2g->VPCode);	
	
	return GOS_OK;
}


GOS_ERROR_CODE Ont2gDrvCfg(void* pOldRow,void* pNewRow,MIB_OPERA_TYPE  operationType)
{
	OMCI_LOG(OMCI_LOG_LEVEL_LOW,"%s: process end\n",__FUNCTION__);
	return GOS_OK;
}


GOS_ERROR_CODE Ont2g_Init(void)
{
    gMibOnt2gTableInfo.Name = "Ont2g";
    gMibOnt2gTableInfo.Desc = "Ont2-g";
    gMibOnt2gTableInfo.MaxEntry = (UINT32)(1);
    gMibOnt2gTableInfo.ClassId = (UINT32)(257);
    gMibOnt2gTableInfo.InitType = (UINT32)(PON_ME_INIT_TYPE_AUTO);
    gMibOnt2gTableInfo.StdType = (UINT32)(PON_ME_STD_TYPE_STD);
    gMibOnt2gTableInfo.ActionType = (UINT32)(PON_ME_ACTION_SET | PON_ME_ACTION_GET);
    gMibOnt2gTableInfo.pAttributes = &(gMibOnt2gAttrInfo[0]);
	gMibOnt2gTableInfo.attrNum = MIB_TABLE_ONT2G_ATTR_NUM;
	gMibOnt2gTableInfo.entrySize = sizeof(MIB_TABLE_ONT2G_T);
	gMibOnt2gTableInfo.pDefaultRow = &gMibOnt2gDefRow;
	

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Name = "EntityID";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].Name = "EqtID";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].Name = "OMCCVer";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "VPCode";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].Name = "SecCapability";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "SecMode";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].Name = "NumOfPriQ";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].Name = "NumOfScheduler";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "Mode";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].Name = "NumOfGemPort";
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].Name = "SysUpTime";

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Entity ID";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Equipment ID";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "OMCC Version";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Vendor Product Code";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Security Capability";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Security Mode";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Total Priority Queue Number";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Total Traffic Scheduler Number";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Mode";
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Total GEM port-ID number";	
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "System up time";

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_STR;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT32;


    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].Len = 20;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].Len = 4; 

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;	
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;	
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_CHAR;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = TRUE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;	
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;

    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_EQTID_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_OMCCVER_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_VPCODE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECCAPABILITY_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SECMODE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFPRIQ_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFSCHEDULER_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_MODE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_NUMOFGEMPORT_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
	gMibOnt2gAttrInfo[MIB_TABLE_ONT2G_SYSUPTIME_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;


    memset(&(gMibOnt2gDefRow.EntityID), 0x00, sizeof(gMibOnt2gDefRow.EntityID));
    memset(gMibOnt2gDefRow.EqtID, ' ', MIB_TABLE_ONT2G_EQTID_LEN);
    gMibOnt2gDefRow.EqtID[MIB_TABLE_ONT2G_EQTID_LEN] = '\0';
    gMibOnt2gDefRow.OMCCVer = 0x80; /*G.984.4 06/04*/
    memset(&(gMibOnt2gDefRow.VPCode), 0x00, sizeof(gMibOnt2gDefRow.VPCode));
    gMibOnt2gDefRow.SecCapability = MIB_ATTR_DEF_SPACE;
    gMibOnt2gDefRow.SecMode = MIB_ATTR_DEF_SPACE;
	gMibOnt2gDefRow.NumOfPriQ = 128;
    gMibOnt2gDefRow.NumOfScheduler = 32;
    gMibOnt2gDefRow.Mode = MIB_ATTR_DEF_SPACE;
    gMibOnt2gDefRow.NumOfGemPort = 128;

	gMibOnt2gOper.meOperDrvCfg = Ont2gDrvCfg;
	gMibOnt2gOper.meOperConnCheck = NULL;
	gMibOnt2gOper.meOperDump = Ont2gDumpMib;
	gMibOnt2gOper.meOperConnCfg = NULL;

	MIB_Register(MIB_TABLE_ONT2G_INDEX,&gMibOnt2gTableInfo,&gMibOnt2gOper);

    return GOS_OK;
}



