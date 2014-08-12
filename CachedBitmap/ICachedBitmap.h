#ifndef _ICACHEDBITMAP_H_
#define _ICACHEDBITMAP_H_

using namespace System;

namespace CachedBitmapUtility {
	public interface class ICachedBitmap {
		System::IntPtr^ get_Instance();
	};
}

#endif