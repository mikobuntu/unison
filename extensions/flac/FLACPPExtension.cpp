/*
 * FLACPPExtension.cpp
 *
 * Copyright (c) 2010 Paul Giblock <pgib/at/users.sourceforge.net>
 *
 * This file is part of Unison - http://unison.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#include "FLACPPExtension.h"
#include "FLACPPBufferReader.h"

#include <extensionsystem/ExtensionManager.h>

#include <QtPlugin>

using namespace FLACPP;
using namespace FLACPP::Internal;

FLACPPExtension::FLACPPExtension()
{
  m_bufferReader = new FLACPPBufferReader();
}


FLACPPExtension::~FLACPPExtension()
{
  removeObject(m_bufferReader);
  delete m_bufferReader;
}


bool FLACPPExtension::initialize(const QStringList &arguments, QString *errorMessage)
{
  Q_UNUSED(errorMessage)
  Q_UNUSED(arguments)
  addObject(m_bufferReader);
  return true;
}


void FLACPPExtension::extensionsInitialized()
{
}


void FLACPPExtension::remoteCommand(const QStringList &options, const QStringList &args)
{
  Q_UNUSED(options)
  Q_UNUSED(args)
}


void FLACPPExtension::shutdown()
{
}

EXPORT_EXTENSION(FLACPPExtension)

// vim: ts=8 sw=2 sts=2 et sta noai
