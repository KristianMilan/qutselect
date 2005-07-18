/* vim:set ts=2 nowrap: ****************************************************

 qRDesktop - A simple Qt4 based GUI frontend for rdesktop
 Copyright (C) 2005 by Jens Langner <Jens.Langner@light-speed.de>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 $Id$

**************************************************************************/

#include <QApplication>

#include "CRDesktopWindow.h"

#include "config.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int returnCode = 1; // 0 is no error

  // You want this, unless you mix streams output with C output.
  // Read  http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#8 for an explanation.
  std::ios::sync_with_stdio(false);

	// lets init the resource (images and so on)
	Q_INIT_RESOURCE(qrdesktop);

	// let us generate the console application object now.
  QApplication app(argc, argv);

	// now we check wheter the user requests some options
	// to be enabled
	bool dtLoginCall = false;
	if(argc > 1)
	{
		if(QString(argv[1]).toLower() == "-dtlogin")
			dtLoginCall = true;
	}

	// now we instanciate our main CRDesktopWindow class
	CRDesktopWindow* mainWin = new CRDesktopWindow(dtLoginCall);
	if(dtLoginCall)
	{
		mainWin->setKeepAlive(true);
		mainWin->setFullScreenOnly(true);
	}

	// show the mainwindow now
	mainWin->show();

		
	// now we do execute our application
	returnCode = app.exec();

  return returnCode;
}
