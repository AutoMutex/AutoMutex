/*###########################################################################
 * Copyright 2010- 
 */
/**
 * @file       autoMutex.h
 *
 * @note       ミューテックス自動解放クラス ソースファイル
 *
 */
/*###########################################################################*/
#include "autoMutex.h"

/*---------------------------------------------------------------------------*/
/**
 * @brief
 *    コンストラクタ
 *
 * @param[in]
 * @n hMutex				:ミューテックスハンドル
 *
 * @return
 * @n NONE
 *
 * @attention
 * @n 
 */
/*---------------------------------------------------------------------------*/
CAutoMutex::CAutoMutex(HANDLE hMutex) 
{
	DWORD	dwRet;

	if ( hMutex == NULL )	{
		m_iErr = S_FALSE;
		Exit();
		return;
	}

	m_hMutex = hMutex;

	dwRet = WaitForSingleObject(m_hMutex, INFINITE);

	if ( dwRet == WAIT_OBJECT_0 ) {
		m_iErr = S_OK;
	}
	else {
		m_iErr = S_FALSE;
		Exit();
	}
}

/*---------------------------------------------------------------------------*/
/**
 * @brief
 *    デストラクタ
 *
 * @param[in]
 * @n none
 *
 * @return
 * @n NONE
 *
 * @attention
 * @n 
 */
/*---------------------------------------------------------------------------*/
CAutoMutex::~CAutoMutex() 
{
	if ( m_hMutex != NULL )	{
		ReleaseMutex(m_hMutex);
		Exit();
	}
}

/*---------------------------------------------------------------------------*/
/**
 * @brief
 *    ロック
 *
 * @param[in]
 * @n none
 *
 * @return
 * @n S_OK					:成功
 * @n S_FALSE				:失敗
 *
 * @attention
 * @n 
 */
/*---------------------------------------------------------------------------*/
INT CAutoMutex::Lock() 
{
	DWORD dwRet;
	
	if ( m_hMutex == NULL )	{
		m_iErr = S_FALSE;
		Exit();
		return m_iErr;
	}

	dwRet = WaitForSingleObject(m_hMutex, INFINITE);

	if ( dwRet == WAIT_OBJECT_0 ) {
		m_iErr = S_OK;
	}
	else {
		m_iErr = S_FALSE;
		Exit();
	}

	return m_iErr;
}

/*---------------------------------------------------------------------------*/
/**
 * @brief
 *    アンロック
 *
 * @param[in]
 * @n none
 *
 * @return
 * @n NONE
 *
 * @attention
 * @n 
 */
/*---------------------------------------------------------------------------*/
VOID CAutoMutex::Unlock() 
{
	if ( m_hMutex != NULL )	{
		ReleaseMutex(m_hMutex);
	}
}

/*---------------------------------------------------------------------------*/
/**
 * @brief
 *    エラーチェック
 *
 * @param[in]
 * @n none
 *
 * @return
 * @n S_OK					:成功
 * @n S_FALSE				:失敗
 *
 * @attention
 * @n 
 */
/*---------------------------------------------------------------------------*/
INT CAutoMutex::CheckErr() 
{
	return m_iErr;
}

/*---------------------------------------------------------------------------*/
/**
 * @brief
 *    終了
 *
 * @param[in]
 * @n none
 *
 * @return
 * @n none
 *
 * @attention
 * @n すべての機能を無効化。デストラクタでのReleaseMutexも行わない。
 */
/*---------------------------------------------------------------------------*/
VOID CAutoMutex::Exit() 
{
	m_hMutex = NULL;
}

