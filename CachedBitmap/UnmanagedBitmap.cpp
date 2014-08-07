#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>

#include "IBitmap.h"

using namespace Gdiplus;

namespace CachedBitmapUtility {
	public ref class UnmanagedBitmap : public IBitmap {
		private:
			bool _isDisposed;
			Bitmap* _bitmap;
			UnmanagedBitmap(Bitmap* bitmap) {
				_isDisposed = false;
				_bitmap = bitmap;
			}
		public:
			virtual System::IntPtr^ get_Instance() {
				return gcnew System::IntPtr(_bitmap);
			}
			static UnmanagedBitmap^ FromHicon(System::IntPtr^ hicon) {
				return gcnew UnmanagedBitmap(Bitmap::FromHICON((HICON)hicon->ToPointer()));
			}
			~UnmanagedBitmap() {
				if (_isDisposed)
					return;

				this->!UnmanagedBitmap();
				_isDisposed = true;
			}
			!UnmanagedBitmap() {
				delete _bitmap;
			}
	};
}
