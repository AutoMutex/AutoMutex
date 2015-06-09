/*#############################################################################
 * Copyright 2010- 
 */
/**
 * @file       autoMutex.h
 *
 * @note       ミューテックス自動解放クラス ヘッダーファイル
 *
 */
/*###########################################################################*/
#ifndef __AUTO_MUTEX__
#define __AUTO_MUTEX__

#include <windows.h>

/*-------------------------------------------
	クラス定義
--------------------------------------------*/
//ミューテックス自動解放クラス
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


#endif  /* __AUTO_MUTEX__ */