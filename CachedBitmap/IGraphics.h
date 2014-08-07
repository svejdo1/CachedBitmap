#ifndef _IGRAPHICS_H_
#define _IGRAPHICS_H_

#include "ICachedBitmap.h"

namespace CachedBitmapUtility {
	public interface class IGraphics {
		public:
			void DrawCachedBitmap(ICachedBitmap^ cachedBitmap, int x, int y);
			System::IntPtr^ get_Instance();
	};
}

#endif