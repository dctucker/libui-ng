// 10 june 2019
#include "test_windows.h"

static HWND osVtableNopHandle(uiControl *c, void *implData)
{
	return NULL;
}

static const uiControlOSVtable osVtable = {
	.Size = sizeof (uiControlOSVtable),
	.Handle = osVtableNopHandle,
};

const uiControlOSVtable *testOSVtable(void)
{
	return &osVtable;
}

Test(WrongControlOSVtableSizeIsProgrammerError)
{
	uiControlVtable vtable;
	uiControlOSVtable osvt;
	void *ctx;

	testControlLoadNopVtable(&vtable);
	ctx = beginCheckProgrammerError("uiRegisterControlType(): wrong size 1 for uiControlOSVtable");
	memset(&osvt, 0, sizeof (uiControlOSVtable));
	osvt.Size = 1;
	uiRegisterControlType("name", &vtable, &osvt, 0);
	endCheckProgrammerError(ctx);
}

Test(ControlOSVtableWithMissingHandleMethodIsProgrammerError)
{
	uiControlVtable vtable;
	uiControlOSVtable osvt;
	void *ctx;

	testControlLoadNopVtable(&vtable);
	ctx = beginCheckProgrammerError("uiRegisterControlType(): required uiControlOSVtable method Handle() missing for uiControl type name");
	osvt = osVtable;
	osvt.Handle = NULL;
	uiRegisterControlType("name", &vtable, &osvt, 0);
	endCheckProgrammerError(ctx);
}

Test(GettingWindowsHandleOfNullControlIsProgrammerError)
{
	void *ctx;

	ctx = beginCheckProgrammerError("uiWindowsControlHandle(): invalid null pointer for uiControl");
	uiWindowsControlHandle(NULL);
	endCheckProgrammerError(ctx);
}