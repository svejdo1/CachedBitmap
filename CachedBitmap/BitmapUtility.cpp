#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>

using namespace Gdiplus;

namespace CachedBitmapUtility {
	public ref class BitmapUtility {
		public:
			static void* CreateCachedBitmapPtr(void* bitmapPtr, void* graphicsHdc) {
				Graphics graphics((HDC)graphicsHdc);
				CachedBitmap* result = new CachedBitmap((Bitmap*)bitmapPtr, &graphics);
				return result;
			}
			static void DisposeCachedBitmap(void* cachedBitmapPtr) {
				delete (CachedBitmap*)cachedBitmapPtr;
			}
			static void DisposeBitmap(void* bitmapPtr) {
				delete (Bitmap*)bitmapPtr;
			}
			static void* GetBitmapPtrFromHICON(void* hicon) {
				return (void*)Bitmap::FromHICON((HICON)hicon);
			}
			static void DrawCachedBitmap(void* hdc, void* cachedBitmapPtr, int x, int y) {
				Graphics graphics((HDC)hdc);
				graphics.DrawCachedBitmap((CachedBitmap*)cachedBitmapPtr, x, y);

			}
	};
}