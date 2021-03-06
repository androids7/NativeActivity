#pragma once

#include "NativeActivity.h"
#include "IAndroidHandler.h"
#include "AssetManager.h"
#include "NotificationManager.h"

namespace Android
{
	void PollEvents();
	void SetEventCallback( MessageCallbackFunction pCallback );
	void SetEventHandler( IAndroidHandler* pHandler );

	void SetJNI( JNIEnv* pEnv, jobject pObj, INativeInterface** pInterface );

	ANativeWindow* GetWindow();
	bool IsWindowVisible();

	void ShowKeyboard();
	void HideKeyboard();

	AssetManager& GetAssetManager();
	const char* GetAppDir();

	JNIEnv* GetJNIEnv();
	jobject GetJNIActivity();

	ClassLoader& GetClassLoader();
	NotificationManager& GetNotificationManager();

	NativeActivity& GetNativeActivity();
};

#ifndef _LIB
extern "C"
{
	void init_native_activity( JNIEnv* pEnv, jobject pObj, Android::INativeInterface** pInterface );
}

#endif
