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

#include "sonos_interface_impl.h"

#include <sonos_interface/sonos_device_observer.h>

SonosInterface* CreateSonosInterface() {
  return new SonosInterfaceImpl();
}

SonosInterfaceImpl::SonosInterfaceImpl() {
}

SonosInterfaceImpl::~SonosInterfaceImpl() {
}

void SonosInterfaceImpl::OnDeviceAvailable(SonosDeviceImpl* device) {
  devices_.insert(device);

  for (auto iter = device_observers_.begin(); iter != device_observers_.end(); ++iter)
    (*iter)->OnDeviceAvailable(device);
}

void SonosInterfaceImpl::OnDeviceLost(SonosDeviceImpl* device) {
  devices_.erase(device);

  for (auto iter = device_observers_.begin(); iter != device_observers_.end(); ++iter)
    (*iter)->OnDeviceLost(device);
}

void SonosInterfaceImpl::Start() {
  SonosDeviceImpl* device = new SonosDeviceImpl();

  OnDeviceAvailable(device);
  OnDeviceLost(device);
}

std::list<SonosDevice*> SonosInterfaceImpl::GetDevices() const {
  std::list<SonosDevice*> devices(devices_.size());
  for (auto iter = devices_.begin(); iter != devices_.end(); ++iter)
    devices.push_back(*iter);

  return devices;
}

bool SonosInterfaceImpl::AddDeviceObserver(SonosDeviceObserver* observer) {
  return device_observers_.insert(observer).second;
}

bool SonosInterfaceImpl::RemoveDeviceObserver(SonosDeviceObserver* observer) {
  return device_observers_.erase(observer) != 0;
}
