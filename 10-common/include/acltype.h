//******************************************************************************
//ģ����	�� acltype
//�ļ���	�� acltype.h
//����	�� zcckm
//�汾	�� 1.0
//�ļ�����˵��:
//aclͨ�����Ͷ���
//------------------------------------------------------------------------------
//�޸ļ�¼:
//2014-12-30 zcckm ����
//******************************************************************************
#ifndef _ACL_TYPE_H_
#define _ACL_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/*-----------------------------------------------------------------------------
ϵͳ�����ļ���������Ա�Ͻ��޸�
------------------------------------------------------------------------------*/

typedef int      s32,BOOL32;
typedef unsigned int   u32;
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef short           s16;
typedef char            s8;

#ifdef _MSC_VER
typedef __int64         s64;
#else 
typedef long long       s64;
#endif 

#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else 
typedef unsigned long long u64;
#endif

#ifndef _MSC_VER
#ifndef LPSTR
#define LPSTR   char *
#endif
#ifndef LPCSTR
#define LPCSTR  const char *
#endif
#endif
/*
#ifndef NULL
#define NULL (void *)0
#endif
*/

#ifdef _WIN32

#else
#ifndef BOOL
#define BOOL int
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#endif

#ifndef INFINITE
#define INFINITE            (u32)-1  // Infinite timeout
#endif


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* _ACL_TYPE_H_ */

/* end of file acltype.h */

