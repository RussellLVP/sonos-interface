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

#ifndef SONOS_INTERFACE_IMPL_H_
#define SONOS_INTERFACE_IMPL_H_

#include <set>

#include <sonos_interface/sonos_interface.h>

#include "sonos_device_impl.h"

class SonosInterfaceImpl final : public SonosInterface {
 public:
  SonosInterfaceImpl();
  virtual ~SonosInterfaceImpl();

  // Registers that |device| has been found, and should be added to the list of devices. Calls
  // the |OnDeviceAvailable| method on all device observers.
  void OnDeviceAvailable(SonosDeviceImpl* device);

  // Called when |device| has disconnected. Calls the |OnDeviceLost| method on all device observers.
  void OnDeviceLost(SonosDeviceImpl* device);

  // SonosInterface implementation.
  virtual void Start() override;
  virtual std::list<SonosDevice*> SonosInterfaceImpl::GetDevices() const override;
  virtual bool AddDeviceObserver(SonosDeviceObserver* observer) override;
  virtual bool RemoveDeviceObserver(SonosDeviceObserver* observer) override;

 private:
  std::set<SonosDeviceImpl*> devices_;
  std::set<SonosDeviceObserver*> device_observers_;
};

#endif  // SONOS_INTERFACE_IMPL_H_