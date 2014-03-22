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

#ifndef SONOS_DEVICE_OBSERVER_H_
#define SONOS_DEVICE_OBSERVER_H_

class SonosDevice;

class SonosDeviceObserver {
 public:
  //
  virtual void OnDeviceAvailable(SonosDevice* device) = 0;

  //
  virtual void OnDeviceLost(SonosDevice* device) = 0;
};

#endif  // SONOS_DEVICE_OBSERVER_H_
