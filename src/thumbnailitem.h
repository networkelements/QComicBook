/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005 Pawel Stolowski <yogin@linux.bydg.org>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#ifndef __THUMBNAILITEM_H
#define __THUMBNAILITEM_H

#include <qiconview.h>

namespace QComicBook
{
	class ThumbnailItem: public QIconViewItem
	{
		private:
			int pnum; //page number
			bool loaded; //has image or is it empty?

		public:
			ThumbnailItem(QIconView *view, int page, const QPixmap &pixmap);
			virtual ~ThumbnailItem();

			int page() const;
			void setLoaded(bool f);
			bool isLoaded() const;
	};
}

#endif

