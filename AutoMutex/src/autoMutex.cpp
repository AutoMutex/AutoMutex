/*###########################################################################
 * Copyright 2010- 
 */
/**
 * @file       autoMutex.h
 *
 * @note       �~���[�e�b�N�X��������N���X �\�[�X�t�@�C��
 *
 */
/*###########################################################################*/
#include "autoMutex.h"

/*---------------------------------------------------------------------------*/
/**
 * @brief
 *    �R���X�g���N�^
 *
 * @param[in]
 * @n hMutex				:�~���[�e�b�N�X�n���h��
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
 *    �f�X�g���N�^
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
 *    ���b�N
 *
 * @param[in]
 * @n none
 *
 * @return
 * @n S_OK					:����
 * @n S_FALSE				:���s
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
 *    �A�����b�N
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
 *    �G���[�`�F�b�N
 *
 * @param[in]
 * @n none
 *
 * @return
 * @n S_OK					:����
 * @n S_FALSE				:���s
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
 *    �I��
 *
 * @param[in]
 * @n none
 *
 * @return
 * @n none
 *
 * @attention
 * @n ���ׂĂ̋@�\�𖳌����B�f�X�g���N�^�ł�ReleaseMutex���s��Ȃ��B
 */
/*---------------------------------------------------------------------------*/
VOID CAutoMutex::Exit() 
{
	m_hMutex = NULL;
}

