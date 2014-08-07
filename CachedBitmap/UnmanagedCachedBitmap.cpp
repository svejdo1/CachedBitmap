#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>

#include "IBitmap.h"
#include "ICachedBitmap.h"
#include "IGraphics.h"

using namespace Gdiplus;

namespace CachedBitmapUtility {
	public ref class UnmanagedCachedBitmap : public ICachedBitmap {
		private:
			bool _isDisposed;
			CachedBitmap* _bitmap;
		public private:
			UnmanagedCachedBitmap(Bitmap* bitmap, Graphics* graphics) {
				_isDisposed = false;
				_bitmap = new CachedBitmap(bitmap, graphics);
			}
		public:
			UnmanagedCachedBitmap(IBitmap^ bitmap, IGraphics^ graphics) {
				_isDisposed = false;
				_bitmap = new CachedBitmap((Bitmap*)bitmap->get_Instance()->ToPointer(), (Graphics*)graphics->get_Instance()->ToPointer());
			}
			virtual System::IntPtr^ get_Instance() {
				return gcnew System::IntPtr(_bitmap);
			}
			~UnmanagedCachedBitmap() {
				if (_isDisposed)
					return;

				this->!UnmanagedCachedBitmap();
				_isDisposed = true;
			}
			!UnmanagedCachedBitmap() {
				delete _bitmap;
			}
	};
}