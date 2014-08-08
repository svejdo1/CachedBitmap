#ifndef _IGRAPHICS_H_
#define _IGRAPHICS_H_

#include "ICachedBitmap.h"
#include "Config.h"

namespace CachedBitmapUtility {
	public interface class IGraphics {
		public:
			CachedBitmapUtility::Status DrawCachedBitmap(ICachedBitmap^ cachedBitmap, int x, int y);
			void RotateTransform(REAL angle);
			void TranslateTransform(REAL x, REAL y);
			System::IntPtr^ get_Instance();
	};
}

#endif