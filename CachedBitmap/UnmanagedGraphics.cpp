#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>

#include "IGraphics.h"
#include "Config.h"
#include "ICachedBitmap.h"

using namespace Gdiplus;

namespace CachedBitmapUtility {
	public ref class UnmanagedGraphics : public IGraphics {
		private:
			bool _isDisposed;
			Graphics* _graphics;
		public private:
			UnmanagedGraphics(HDC hdc) {
				_isDisposed = false;
				_graphics = new Graphics(hdc);
			}
		public:
			UnmanagedGraphics(System::IntPtr^ hdc) {
				_isDisposed = false;
				_graphics = new Graphics((HDC)hdc->ToPointer());
			}
			virtual CachedBitmapUtility::Status DrawCachedBitmap(ICachedBitmap^ cachedBitmap, int x, int y) {
				CachedBitmap* bitmap = (CachedBitmap*)cachedBitmap->get_Instance()->ToPointer();
				Gdiplus::Status status = _graphics->DrawCachedBitmap(bitmap, x, y);
				return (CachedBitmapUtility::Status)((int)status);
			}
			virtual void ResetTransform() {
				_graphics->ResetTransform();
			}
			virtual void RotateTransform(REAL angle) {
				_graphics->RotateTransform(angle);
			}
			virtual void TranslateTransform(REAL x, REAL y) {
				_graphics->TranslateTransform(x, y);
			}
			virtual System::IntPtr^ get_Instance() {
				return gcnew System::IntPtr(_graphics);
			}
			~UnmanagedGraphics() {
				if (_isDisposed)
					return;

				this->!UnmanagedGraphics();
				_isDisposed = true;
			}
			!UnmanagedGraphics() {
				delete _graphics;
			}
	};
}