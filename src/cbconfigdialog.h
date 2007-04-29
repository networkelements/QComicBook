/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005-2006 Pawel Stolowski <yogin@linux.bydg.org>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#ifndef __CBCONFIGDIALOG_H
#define __CBCONFIGDIALOG_H

#include <QDialog>

class QCheckBox;
class QPushButton;
class QRadioButton;
class QSpinBox;
class QLabel;
class QLineEdit;
class QTabWidget;

namespace QComicBook
{
	class ComicBookSettings;
	class ComicBookCfgDialog: public QDialog
	{
		Q_OBJECT

		private:
			QTabWidget *tabs;
			ComicBookSettings *cfg;
			QCheckBox *cb_twopagesstep;
			QCheckBox *cb_smallcursor;
			QCheckBox *cb_hidemenu;
			QCheckBox *cb_hidestatus;
			QCheckBox *cb_hidetoolbar;
			QPushButton *pb_color;
			QCheckBox *cb_preload;
			QCheckBox *cb_confirmexit;
			QCheckBox *cb_splash;
			QCheckBox *cb_autoinfo;
			QSpinBox *sb_cachesize;
			QCheckBox *cb_thumbs;
			QSpinBox *sb_thumbsage;
			QColor bgcolor;
			QSpinBox *sb_fontsize;
			QCheckBox *cb_intbrowser;
			QLineEdit *le_extbrowser;
			QPushButton *pb_brbrowse;
			QLabel *fontname;
			QFont font;
			QCheckBox *cb_editing;

			void setupDisplayTab();
			void setupMiscTab();
			void setupEditTab();
			void updateFontPreview();

		protected slots:
			virtual void accept();
			void showBackgroundDialog();
			void showFontDialog();
			void browseExternalBrowser();
			void browserCheckboxToggled(bool f);

		public:
			ComicBookCfgDialog(QWidget *parent, ComicBookSettings *cfg);
			virtual ~ComicBookCfgDialog();
	};
}

#endif

