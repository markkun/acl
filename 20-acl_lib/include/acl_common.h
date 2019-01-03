//******************************************************************************
//ģ����	�� acl_common
//�ļ���	�� acl_common.h
//����	�� zcckm
//�汾	�� 1.0
//�ļ�����˵��:
//ACL ����ģ����޸ĺ꣬�ڲ����ú������ṹ�嶨��ȣ���������
//------------------------------------------------------------------------------
//�޸ļ�¼:
//2015-02-05 zcckm ����
//2015-08-31 zcckm �޸Ĺ���
//******************************************************************************
#ifndef _ACL_COMMON_H_
#define _ACL_COMMON_H_
#include "acl_c.h"
#include <map>
#include <string>
typedef enum 
{
    MSG_3A            = 1,  //3A mess
    MSG_QUTE          = 2,//quit message
    MSG_HBMSG_REQ     = 3,//HB req
    MSG_HB_MSG,
    MSG_HB_MSG_ACK,
	MSG_DISCONNECT_NTF,
	MSG_3A_CHECK_REQ,//S->C 3A�������
	MSG_3A_CHECK_ACK,//C->S 3A���������Ӧ
	MSG_TRY_NEGOT,
	MSG_NEGOT_CONFIM
}E_ACLSysMsg;

#define FLEX_LEN 0
typedef struct tagIDNegot
{
	E_ACLSysMsg m_msgIDNegot;
	u32 m_dwSessionID;
	u32 m_dwPayLoadLen;
	unsigned char m_arrPayLoad[FLEX_LEN];
}TIDNegot;

//MSG_3A_CHECK_REQ,MSG_3A_CHECK_ACK
typedef struct tag3ACheck
{
	u32 m_dwIsBigEden;
	u32 m_MagicNum;
}T3ACheckReq,T3ACheckAck;

//Э�� MSG_TRY_NEGOT,MSG_NEGOT_CONFIM CS�˷�����ͬ�ṹ��
typedef struct tagTryNegot
{
	u32 m_dwSessionID;
}TTryNegot;

typedef enum
{
    MSGMASK_DEFAULT = 0,
    MSGMASK_THROW_AWAY =1,
}ACL_MSG_MASK;

//heart beat time out 
#define HB_TIMEOUT 6000
//heart beat check time interval
#define HB_CHECK_ITRVL 2000


//ACL inner APP definition
#define MAX_APP_NAME_LEN 256 //max APP name Len
#define MAX_APP_NUM      20  //max APP number

#define NWPUSH_APP_NUM 0//����������Ϣ���͵�APP
#define NETWORK_MSG_PUSH_INST_NUM 1

#define HBDET_APP_NUM 21//������������APP
#define HB_DETECT_INST_NUM 1

#define TIMER_CB_APP_NUM 22//���ڶ�ʱ���ص������ķ��봦��(�������ۺ��ļ����߳�)
#define TIMER_CB_INST_NUM 10

//3A
#define TEMP_3A_CHECK_NUM 0x32

#define DEFAULT_INST_MSG_NUM 1000


typedef enum
{
    E_INST_STATE_INVALID = -1,
    E_INST_STATE_IDLE     = 0,
    E_INST_STATE_BUSY     = 1,
}INST_STATUS_;

//�û�����app�����ṹ
typedef struct tagAclAppParam
{
	s8 m_achAppName[MAX_APP_NAME_LEN];      //app����
	u16 m_wAppId;                           //app ��    
	u8 m_byAppPrity;                        //app���ȼ���Ĭ��Ϊ 80
	u16 m_wAppMailBoxSize;                  //app ���������Ϣ��.Ĭ��ֵΪ 80
	u32 m_dwInstStackSize;                  //app ��ջ��С.Ĭ��Ϊ64K.
	u32 m_dwInstNum;                        //���ص�ʵ����Ŀ
	u32 m_dwInstDataLen;                    //ÿ��ʵ���Զ������ݳ���
	CBMsgEntry m_pMsgCB;                    //��Ϣ��ڻص�����ָ��
	void * m_pExtAppData;                   //app �����չ����ָ��
}TAclAppParam;

//socket
typedef enum
{
    E_LET_IT_GO   = 0,
    ESELECT_READ  = 0x01,//listen also using this for handle new connect
    ESELECT_WRITE = 0x02,
    ESELECT_ERROR = 0x04,
    ESELECT_CONN  = 0x08
} ESELECT;
static std::map<u16, std::string> mapSelectTypePrint =
{
	{ E_LET_IT_GO, "E_LET_IT_GO" },
	{ ESELECT_READ, "ESELECT_READ" },
	{ ESELECT_WRITE, "ESELECT_WRITE" },
	{ ESELECT_ERROR, "ESELECT_ERROR" },
	{ ESELECT_CONN, "ESELECT_CONN" }
};


typedef enum
{
    E_DATA_PROC = 0,
    E_3A_CONNECT = 1,
}ESOCKET_MANAGE;

#define MAX_NODE_SUPPORT 40

#ifndef WIN32
#define INVALID_SOCKET  (int)(~0)
#endif

typedef s32 (*FEvSelect)(H_ACL_SOCKET nFd, ESELECT eEvent, void* pContext);

//begin lock
#ifdef WIN32

#else

#ifndef INFINITE
#define INFINITE ((u32)(-1)>>1)
#endif

#endif
//end lock

#ifdef __cplusplus
extern "C" {
#endif //extern "C"


#ifdef __cplusplus
}
#endif //extern "C"

#endif

