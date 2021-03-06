/*
 * syslog.c
 *
 *  Created on: 2013/09/06
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ioctl.h>

#include <shutils.h>

/* Linux specific headers */
#include <error.h>
#include <termios.h>
#include <sys/time.h>
#include <net/ethernet.h>
#include <dirent.h>
#include <malloc.h>
#include <arpa/inet.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <ctype.h>
#include <net/if_arp.h>
#include <lw_config.h>
#include "build_time.h"
#include <time_zone.h>

/****一个函数对应一个语言，每个字符串对应一个ID，由开发人员自己定义*/
/*0-255 表示模块的多种语言实现，后面256开始就由开发人员自己定*/

struct log_messg log_module_msg[STR_END] = {{M_SYSLOG_STA,"syslogd starting" ,"syslogd 鍚姩"},
									 {M_SYSLOG_EXIT,"syslogd exiting","syslogd 閫�鍑�."},
									 {M_STP_STA,"the device started running STP now","璁惧寮�濮嬭繍琛孲TP"},
									 {M_STP_EXIT,"the device stopped running STP now","璁惧鍋滄杩愯STP"},
									 {M_AAA_STA,"enter the AAA security Settings","杩涘叆AAA瀹夊叏璁剧疆"},
									 {M_AAA_STA,"exit the AAA security Settings","閫�鍑篈AA瀹夊叏璁剧疆"},
									 {M_NTP_STA,"enter the NTP module Settings","杩涘叆绯荤粺鏃堕棿妯″潡璁剧疆"},
									 {M_NTP_EXIT,"exit the NTP module Settings","閫�鍑虹郴缁熸椂闂存ā鍧楄缃�"},
									 {M_WEB_STA,"enter the WEB module","杩涘叆WEB璁剧疆妯″潡"},
									 {M_WEB_EXIT,"exit the WEB module","閫�鍑篧EB璁剧疆妯″潡"},
									 {M_TELNET_STA,"telnet enable","telnet鍔熻兘鍚姩"},
									 {M_TELNET_EXIT,"telnet diabled","telnet鍔熻兘鍏抽棴"},
									 {M_USER_STA,"enter the USER manage Settings","杩涘叆鐢ㄦ埛绠＄悊璁剧疆"},
									 {M_USER_EXIT,"exit the USER manage Settings","閫�鍑虹敤鎴风鐞嗚缃�"},
									 {M_SYSTEM_STA,"system starting","绯荤粺鍚姩"},
									 {M_SYSTEM_EXIT,"system exiting","閫�鍑虹郴缁�"},
									 {M_MVLAN_STA,"the device started running MVLAN now","璁惧寮�濮婱LAN鐨勮繍琛�"},
									 {M_MVLAN_EXIT,"the device stopped running MVLAN now","璁惧鍋滄MLAN鐨勮繍琛�"},									 
									 {M_LOOP_STA,"loop enable now","loop鍔熻兘寮�鍚�"},
									 {M_LOOP_EXIT,"loop diabled now","loop鍔熻兘鍏抽棴"},
									 {M_QOS_STA,"enter the QOS module","杩涘叆QOS璁剧疆妯″潡"},
									 {M_QOS_EXIT,"exit the QOS module","閫�鍑篞OS璁剧疆妯″潡"},
									 {M_SNMP_STA,"snmp enable now","snmp鍔熻兘寮�鍚�"},
									 {M_SNMP_EXIT,"snmp diabled now","snmp鍔熻兘鍏抽棴"},
									 {M_LOGIN," user logged in from "," 鐢ㄦ埛 admin 鐧诲綍,ip涓�"},
									 {M_LOGOUT," user logged out from "," 鐢ㄦ埛admin娉ㄩ攢,ip涓�"},
									 {M_USERNAMER,"username or password is Invalid or error",""},
									 {M_REBOOT,"the device was restarted by user","璇ヨ澶囨槸鐢辩敤鎴烽噸鏂板惎鍔�"},
									 {M_SAVECONF,"the device saved current configuration successfully","閰嶈澶囦繚瀛樺綋鍓嶉厤缃垚鍔�"},
									 {M_RECONF,"the device restored factory configuration successfully","閰嶈澶囨仮澶嶅伐鍘傞厤缃垚鍔�"},
									 {M_IPCHANGE,"ip address has been changed into ",",IP鍦板潃宸茬粡鏇存敼涓�"},
									 {M_LINKUP," is UP","鐘舵�佸凡缁忚繛鎺�"},
									 {M_LINKDOWN," is DOWN","杩炴帴鐘舵�佹柇寮�"},
									 {M_LONGLIGHT,"pon status detected always laser","pon鐘舵�佹娴嬮暱鍙戝厜"},
									 {M_OPTICALLINK,"normal optical link negotiation","鍏夐摼璺崗鍟嗘甯�"}
								   };

struct log_mod log_module[MODULE_MAX] = {{SYSLOG, "SYSLOG","绯荤粺鏃ュ織"}, 
									 {STP, "STP" ,"STP"}, 
									 {AAA, "AAA" , "AAA" },
									 {NTP, "NTP" ,"NTP"  },
									 {WEB, "WEB" ,"WEB"  }, 
									 {TELNET, "TELNET" ,"TELNET"},
									 {USER, "USER" ,"USER"	}, 
									 {SYSTEM, "SYSTEM" ,"SYSTEM"},
									 {MVLAN, "MVLAN", "MVLAN"}, 
									 {LOOP, "LOOP" ,"LOOP"},
									 {QOS, "QOS" ,"QOS" }, 
									 {SNMP, "SNMP" ,"SNMP"}


};

int getStrById_EN(unsigned int module_id, unsigned int mesg_id,char *module_str, char *msg_str, unsigned int module_size,unsigned int msg_size)
{
	char *pStr = NULL;
	char *Str = NULL;
	int i = 0;
	int y = 0;

	if(module_id>MODULE_MAX)
	{
		return -1;
	}

	if(mesg_id>STR_END)
	{
		return -1;
	}
	if((!module_str)||(!msg_str))
	{
		return -1;
	} 
	//login_out(id,login_msg,sizeof(login_msg));
	for(i = SYSLOG;i<MODULE_MAX;i++)
	{
		if(log_module[i].id == module_id)
		{
			pStr = log_module[i].mod_en;
			safe_strncpy(module_str, pStr, module_size);
			break;
		}
	}
	for(y = M_SYSLOG_STA;y<STR_END;y++)
	{
		if(log_module_msg[y].id == mesg_id)
		{
			Str = log_module_msg[y].msg_en;
			safe_strncpy(msg_str, Str, msg_size);
			break;
		}
	}
}


int getStrById_CN(unsigned int module_id, unsigned int mesg_id,char *module_str, char *msg_str, unsigned int module_size,unsigned int msg_size)
{
	char *pStr = NULL;
	char *Str = NULL;
	int i = 0;
	int y = 0;

	if(module_id>MODULE_MAX)
	{
		return -1;
	}

	if(mesg_id>STR_END)
	{
		return -1;
	}
	if((!module_str)||(!msg_str))
	{
		return -1;
	} 
	//login_out(id,login_msg,sizeof(login_msg));
	for(i = SYSLOG;i<MODULE_MAX;i++)
	{
		if(log_module[i].id == module_id)
		{
			pStr = log_module[i].mod_cn;
			safe_strncpy(module_str, pStr, module_size);
			break;
		}
	}
	for(y = M_SYSLOG_STA;y<STR_END;y++)
	{
		if(log_module_msg[y].id == mesg_id)
		{
			Str = log_module_msg[y].msg_cn;
			safe_strncpy(msg_str, Str, msg_size);
			break;
		}
	}
}

#if 1
int (*MesFunc[LANG_MAX])(unsigned int,unsigned int, char *,char *,unsigned int,unsigned int);
void Syslog_Init(void)
{
	MesFunc[EN] = getStrById_EN;
	MesFunc[CN] = getStrById_CN;
	/*here add the Func_Init*/
}
#endif

int LangId = EN;

void USER_LOG(unsigned int lang_id,unsigned int module_id,unsigned int priority,unsigned int msg_id,unsigned char *left_fmt,unsigned char *right_fmt)
{
	char msg_str[1024] = {0};
	char module_str[64]={0};
	
	if(!right_fmt||!left_fmt)
	{
		return -1;
	} 
	if(NULL !=(*MesFunc[lang_id]))
	{
		(*MesFunc[lang_id])(module_id,msg_id, module_str,msg_str,sizeof(module_str),sizeof(msg_str));
		openlog(module_str,0,0);
		//(*MesFunc[lang_id])(msg_id, msg_str, sizeof(msg_str));
		syslog(priority, "%s:%s%s%s",module_str,left_fmt,msg_str,right_fmt);
		closelog();
	}
	else
	{
		printf("get module OR lang_id error!!\n");
		return -1;
	}
}
/*end by leijinbao 2013/9/2*/
