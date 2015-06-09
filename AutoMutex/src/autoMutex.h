/*#############################################################################
 * Copyright 2010- 
 */
/**
 * @file       autoMutex.h
 *
 * @note       �~���[�e�b�N�X��������N���X �w�b�_�[�t�@�C��
 *
 */
/*###########################################################################*/
#ifndef __AUTO_MUTEX__
#define __AUTO_MUTEX__

#include <windows.h>

/*-------------------------------------------
	�N���X��`
--------------------------------------------*/
//�~���[�e�b�N�X��������N���X
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