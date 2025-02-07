#ifndef __LIBUI_DRAW_HPP__
#define __LIBUI_DRAW_HPP__

// TODO resolve overlap between this and the other hpp files (some functions leaked into uipriv_windows.hpp)

// draw.cpp
extern ID2D1Factory *d2dfactory;
struct uiDrawContext {
	ID2D1RenderTarget *rt;
	// TODO find out how this works
	std::vector<struct drawState> *states;
	ID2D1PathGeometry *currentClip;
};

struct uiDrawBitmap {
	int Width;
	int Height;
	int Stride;

	ID2D1Bitmap* bmp;
};

// drawpath.cpp
extern ID2D1PathGeometry *pathGeometry(uiDrawPath *p);

// drawmatrix.cpp
extern void m2d(uiDrawMatrix *m, D2D1_MATRIX_3X2_F *d);

#endif

