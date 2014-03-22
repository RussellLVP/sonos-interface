/**
* Copyright (c) 2014 The Sonos Interface Developers
*
* This program is free software: you can redistribute it and/or modify it under the terms of the
* GNU General Public License as published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
* even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SONOS_INTERFACE_H_
#define SONOS_INTERFACE_H_

#include <list>

#include <sonos_interface/sonos_common.h>

class SonosDevice;
class SonosDeviceObserver;

class SonosInterface {
 public:
  //
  virtual void Start() = 0;

  //
  virtual std::list<SonosDevice*> GetDevices() const = 0;

  //
  virtual bool AddDeviceObserver(SonosDeviceObserver* observer) = 0;

  //
  virtual bool RemoveDeviceObserver(SonosDeviceObserver* observer) = 0;

  //
  virtual ~SonosInterface() { }
};

// Creates a new interface, allowing interaction with SONOS devices on the local network. The caller
// of this method must assume ownership of the created instance.
SONOS_EXPORT SonosInterface* CreateSonosInterface();

#endif  // SONOS_INTERFACE_H_