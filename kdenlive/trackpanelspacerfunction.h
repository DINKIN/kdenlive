/***************************************************************************
                          trackpanelfunction.h  -  description
                             -------------------
    begin                : Sun May 18 2003
    copyright            : (C) 2003 by Jason Wood
    email                : jasonwood@blueyonder.co.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef TRACKPANELSPACERFUNCTION_H
#define TRACKPANELSPACERFUNCTION_H

#include "qcursor.h"

#include "trackpanelfunction.h"
#include "snaptogrid.h"

class QMouseEvent;
class DocTrackBase;
class KdenliveDoc;

namespace Gui {
    class KdenliveApp;
    class KTimeLine;
} namespace Command {
    class KMoveClipsCommand;
}
/**
Abstract Base Class for track panel functionality decorators. This and it's
derived classes allow different behaviours to be added to panels as required.

@author Jason Wood
*/ class TrackPanelSpacerFunction:public TrackPanelFunction
{
  Q_OBJECT public:
    TrackPanelSpacerFunction(Gui::KdenliveApp * app,
	Gui::KTimeLine * timeline, KdenliveDoc * doc);

    virtual ~ TrackPanelSpacerFunction();

	/**
	Returns true if the specified position should cause this function to activate,
	otherwise returns false.
	*/
    virtual bool mouseApplies(Gui::KTrackPanel * panel,
	QMouseEvent * event) const;

	/**
	Returns a relevant mouse cursor for the given mouse position
	*/
    virtual QCursor getMouseCursor(Gui::KTrackPanel * panel,
	QMouseEvent * event);

	/**
	A mouse button has been pressed. Returns true if we want to handle this event
	*/
    virtual bool mousePressed(Gui::KTrackPanel * panel,
	QMouseEvent * event);

	/**
	Mouse Release Events in the track view area. Returns true if we have finished
	an operation now.
	*/
    virtual bool mouseReleased(Gui::KTrackPanel * panel,
	QMouseEvent * event);

	/**
	Processes Mouse Move events in the track view area. Returns true if we are
	continuing with the drag.*/
    virtual bool mouseMoved(Gui::KTrackPanel * panel, QMouseEvent * event);
  private:
     Gui::KdenliveApp * m_app;
     Gui::KTimeLine * m_timeline;
    DocClipRef *m_clipUnderMouse;
    KdenliveDoc *m_doc;
    DocClipRef *m_masterClip;
     Command::KMoveClipsCommand * m_moveClipsCommand;

	/**
	When dragging a clip, this is the time offset that should be applied to where
	the mouse cursor to find the beginning of the master clip.
	*/
    GenTime m_clipOffset;
    SnapToGrid m_snapToGrid;
};

#endif
