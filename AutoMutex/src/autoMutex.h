/*#############################################################################
 * Copyright 2010- 
 */
/**
 * @file       utility.h
 *
 * @note       ユーティリティヘッダファイル
 *
 * @author     (TOA) Shigeharu kamiya
 *
 */
/*###########################################################################*/
#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <windows.h>

/*-------------------------------------------
	クラス定義
--------------------------------------------*/
//自動解除付ミューテックス
class CAutoMutex
{
private:
	HANDLE	m_hMutex;
	INT		m_iErr;

public:
	CAutoMutex(HANDLE hMutex);
	~CAutoMutex();
	INT		Lock();
	VOID	Unlock();
	INT		CheckErr();
	VOID	Exit();
};


#endif  /* __UTILITY_H__ */