/*#############################################################################
 * Copyright 2010- 
 */
/**
 * @file       utility.h
 *
 * @note       ���[�e�B���e�B�w�b�_�t�@�C��
 *
 * @author     (TOA) Shigeharu kamiya
 *
 */
/*###########################################################################*/
#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <windows.h>

/*-------------------------------------------
	�N���X��`
--------------------------------------------*/
//���������t�~���[�e�b�N�X
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