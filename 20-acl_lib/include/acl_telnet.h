//******************************************************************************
//ģ����	�� acl_telnet
//�ļ���	�� acl_telnet.h
//����	�� zcckm
//�汾	�� 1.0
//�ļ�����˵��:
//ACL telnet ����
//------------------------------------------------------------------------------
//�޸ļ�¼:
//2015-01-20 zcckm ����
//******************************************************************************
#ifndef _ACL_TELNET_H_
#define _ACL_TELNET_H_

#include "acl_c.h"

// #ifdef __cplusplus
// extern "C" {
// #endif //extern "C"

//++++++++Telnet Interface
ACL_API int aclPrintf(int bOpenPrint,int bSaveLog,const char * param,...);
ACL_API int aclRegCommand(const char * pCmd, void * pFunc, const char * pPrompt);
ACL_API int setTelnetPrompt(int nPort, const char * pPrompt);
//--------Telnet Interface



ACL_API int ACL_DEBUG(int MODULE, int TYPE,const char * param,...);

//Debug info filter

/*
��ӡ�������ã�
1.����ģ���ӡ(����Socket���ڴ棬����)
2.������Ϣ���ʹ�ӡ(������Ϣ���ޣ�����,֪ͨ�����棬����)
ͨ��telnet��������
*/
typedef enum
{
    E_TYPE_NONE = 0,
	E_TYPE_ERROR,
	E_TYPE_WARNNING,
	E_TYPE_KEY,
    E_TYPE_NOTIF,    
	E_TYPE_DEBUG,
    E_TYPE_RESERVED_0,
    E_TYPE_RESERVED_1,
    E_TYPE_ALL
}EDEBUG_TYPE;

typedef enum
{
    E_MOD_NONE = 0,
    E_MOD_LOCK,//��
    E_MOD_NETWORK,//�����շ���أ�ƫ����Socket
    E_MOD_HB,//����
    E_MOD_MSG,//message,��Ϣ�շ��߼����
    E_MOD_MANAGE,//����
    E_MOD_TELNET,//telnet
    E_MOD_TIMER,//��ʱ��
    E_MOD_ALL //����ģ��
}EDEBUG_MODULE;


// #ifdef __cplusplus
// }
// #endif //extern "C"

#endif

