# AutoMutex
ミューテックス自動解放クラス

■説明

	関数を抜けると自動的にミューテックスを解放するクラス

■動作確認済み環境

	Visual Studio 2008

■クラス名

	CAutoMutex

■公開メソッド

	CAutoMutex(HANDLE hMutex);
	~CAutoMutex();
	INT		Lock();
	VOID	Unlock();
	INT		CheckErr();
	VOID	Exit();

■使い方


	①初期処理を行う関数にて実施
	
		//ミューテックスを作成する
		m_hMutex = CreateMutex(NULL, FALSE, NULL);

	②排他制御する関数にて実施
	
		//作成したミューテックスを引数にして、CAutoMutexのインスタンスを生成する
		
          /*	コンストラクタでミューテックスを取得する
	       *	関数を抜ける(デストラクタが呼ばれる)とミューテックスが開放される
	       */
		CAutoMutex inAutoMutex(m_hMutex);
		
		//生成エラーチェック
		if ( inAutoMutex.CheckErr() ) {
			return inAutoMutex.CheckErr();
		}
		
		//関数処理の途中でミューテックスを開放する場合
		inAutoMutex.Unlock();
		
		//関数処理の途中でミューテックスを再取得する場合
		inAutoMutex.Lock();
		
	  
	③終了処理を行う関数にて実施
	
		//ミューテックスを取得する
		CAutoMutex inAutoMutex(m_hMutex);

		//生成エラーチェック
		if ( inAutoMutex.CheckErr() ) {
			return inAutoMutex.CheckErr();
		}		
	
		//ミューテックスを削除する
		CloseHandle(m_hMutex);
		m_hMutex = NULL;
		
		//自動解除をオフにする
		inAutoMutex.Exit();

