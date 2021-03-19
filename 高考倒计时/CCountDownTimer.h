#pragma once

#ifndef _CCOUNTDOWNTIMER_H
#define _CCOUNTDOWNTIMER_H
/********************
  ͷ�ļ����궨����
********************/
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//#include "sciter-x.h"
//#include "sciter-x-host-callback.h"
#include "sciter-x-window.hpp"
#define debugLogs(logs) pwin->call_function("IA_debugLogs",sciter::value(logs))

/********************
	ǰ��������
********************/
using namespace std;
class MainWindow;

/********************
	ȫ�ֱ���������
********************/
extern MainWindow *pwin;
extern string g_iniPath;
extern HINSTANCE ghInstance;

/********************
	��ͨ����������
********************/
string	getCurrentWorkDir();
string getWindowStyle();


/********************
	  ��������
********************/

class MainWindow : public sciter::window {
public:
BEGIN_FUNCTION_MAP
	FUNCTION_0("Test", Test);
	FUNCTION_0("NA_getWorkDir", NA_getWorkDir); //NA means native
	FUNCTION_0("NA_getStyle", NA_getStyle);
	FUNCTION_0("NA_getTime", NA_getTime);
	FUNCTION_1("NA_setStyle", NA_setStyle);
	FUNCTION_1("NA_setTime", NA_setTime);
	FUNCTION_0("NA_getPos", NA_getPos);
	FUNCTION_1("NA_setPos", NA_setPos);
END_FUNCTION_MAP
	sciter::value  Test();
	sciter::value NA_getWorkDir();
	sciter::value NA_getStyle();
	sciter::value NA_getTime();
	sciter::value NA_setStyle(sciter::value style);
	sciter::value NA_setTime(sciter::value time);
	sciter::value NA_getPos();
	sciter::value NA_setPos(sciter::value pos);
	void onReady();
	MainWindow() : window(SW_ALPHA | SW_MAIN | SW_ENABLE_DEBUG) {}
};

#endif