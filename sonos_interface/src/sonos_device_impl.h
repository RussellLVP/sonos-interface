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

#ifndef SONOS_DEVICE_IMPL_H_
#define SONOS_DEVICE_IMPL_H_

#include <sonos_interface/sonos_device.h>

class SonosDeviceImpl final : public SonosDevice {
 public:
  SonosDeviceImpl();
  virtual ~SonosDeviceImpl();

   // SonosDevice implementation.
  virtual std::string name() const;
  virtual std::string typeName() const;
};

#endif  // SONOS_DEVICE_IMPL_H_