/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005-2006 Pawel Stolowski <pawel.stolowski@wp.pl>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#ifndef __SETTINGS_H
#define __SETTINGS_H

#include "imgview.h"
#include "history.h"
#include "enummap.h"
#include <QObject>
#include <QFont>
#include <QByteArray>

class QSettings;
class QRect;
class QColor;
class QMainWindow;

namespace QComicBook
{
	using namespace Utility;

	class ComicBookSettings: public QObject
	{
		Q_OBJECT

		private:
			QSettings *cfg;
			bool smallcursor;
			bool twopages;
			bool twopagesstep;
			bool japanese;
			bool contscroll;
			bool scrollbars;
			bool preload;
			bool fscrhidemenu;
			bool fscrhidestatus;
			bool fscrhidetoolbar;
			Size pagesize;
			//Scaling scaling;
			QString lastdir;
			QColor bgcolor;
			History recent;
			int cachesize;
			int thumbsage;
			bool cacheadjust;
			bool cachethumbs;
			bool autoinfo;
			bool confirmexit;
			bool statusbar;
			bool editsupport;
			bool intbrowser;
			bool showsplash;
			QString extbrowser;
			QByteArray docklayout;
			QByteArray geometry;
			QString tmpdir;
			QFont font;

			static QString bkpath; //bookmarks path
			static QString thpath; //thumbnails cache path
			static bool dirsok; //is above dirs are ok

			static const EnumMap<Size> size2string[];
			//static const EnumMap<Scaling> scaling2string[];

		signals:
			void backgroundChanged(const QColor &color);
			//void scalingMethodChanged(Scaling s);
			void cursorChanged(bool f);

		private:
			ComicBookSettings();
			~ComicBookSettings();

		public:
			void load();

			bool smallCursor() const;
			bool twoPagesMode() const;
			bool twoPagesStep() const;
			bool japaneseMode() const;
			bool continuousScrolling() const;
			bool scrollbarsVisible() const;
			Size pageSize() const;
			//Scaling pageScaling() const;
			QString lastDir() const;
			const History& recentlyOpened() const;
			QColor background() const;
			int cacheSize() const;
			bool cacheAutoAdjust() const;
			bool cacheThumbnails() const;
			int thumbnailsAge() const;
			bool preloadPages() const;
			bool confirmExit() const;
			bool autoInfo() const;
			bool fullScreenHideMenu() const;
			bool fullScreenHideStatusbar() const;
			bool fullScreenHideToolbar() const;
			bool showStatusbar() const;
			bool useInternalBrowser() const;
			const QFont& infoFont() const;
			QString externalBrowser() const;
			void restoreGeometry(QMainWindow *w) const;
			void restoreDockLayout(QMainWindow *w);
			bool editSupport() const;
			bool showSplash() const;
			QString tmpDir() const;

			void smallCursor(bool f);
			void twoPagesMode(bool f);
			void twoPagesStep(bool f);
			void japaneseMode(bool f);
			void continuousScrolling(bool f);
			void scrollbarsVisible(bool f);
			void pageSize(Size s);
			//void pageScaling(Scaling s);
			void lastDir(const QString &d);
			void recentlyOpened(const History &hist);
			void background(const QColor &color);
			void cacheSize(int s);
			void cacheAutoAdjust(bool f);
			void cacheThumbnails(bool f);
			void thumbnailsAge(int n);
			void preloadPages(bool f);
			void confirmExit(bool f);
			void autoInfo(bool f);
			void fullScreenHideMenu(bool f);
			void fullScreenHideStatusbar(bool f);
			void fullScreenHideToolbar(bool f);
			void showStatusbar(bool f);
			void useInternalBrowser(bool f);
			void infoFont(const QFont &f);
			void externalBrowser(const QString &cmd);
			void saveDockLayout(QMainWindow *w);
			void saveGeometry(QMainWindow *w);
			void editSupport(bool f);
			void showSplash(bool f);
			void tmpDir(const QString &dir);

			static ComicBookSettings& instance();

			//
			// checks and creates .qcomicbook/ and cache subdirectories if
			// necessary
			static bool checkDirs();
			static const QString& bookmarksDir();
			static const QString& thumbnailsDir();
	};
}

#endif
