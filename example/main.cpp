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

#include <memory>
#include <iostream>
#include <Windows.h>

#include <sonos_interface/sonos_interface.h>

#include <sonos_interface/sonos_device.h>
#include <sonos_interface/sonos_device_observer.h>

namespace {
// Returns whether |left| and |right| are equal to each other, ignoring character casing.
bool equalsIgnoreCase(const std::string& left, const std::string& right) {
  if (left.length() != right.length())
    return false;

  for (size_t index = 0; index < left.length(); ++index) {
    if (tolower(left.at(index)) != tolower(right.at(index)))
      return false;
  }

  return true;
}
}  // namespace

class MyDeviceObserver : public SonosDeviceObserver {
 public:
  virtual void OnDeviceAvailable(SonosDevice* device) override {
    std::cout << ">> Sonos device available: " << device->name() << " (" << device->typeName() << ")\n";
  }

  virtual void OnDeviceLost(SonosDevice* device) override {
    std::cout << ">> Sonos device lost: " << device->name() << ".\n";
  }
};

// Command: "HELP".
// Displays a list of options available in this command line program.
void displayHelp() {
  std::cout << ">> The following commands are available:\n";
  std::cout << ">>     HELP       Displays this message.\n";
  std::cout << ">>     QUIT       Shuts down the program.\n";
  std::cout << ">>\n";

  std::cout << ">>     DEVICES    Lists all available Sonos devices.\n";
}

// Command: "DEVICES".
// Displays a list of the currently connected SONOS devices.
void displayDevices(SonosInterface& sonos) {
  const std::list<SonosDevice*> devices = sonos.GetDevices();
  if (devices.size() == 0) {
    std::cout << ">> No Sonos devices are available.\n";
    return;
  }

  for (auto iter = devices.begin(); iter != devices.end(); ++iter)
    std::cout << ">> " << (*iter)->name() << " (" << (*iter)->typeName() << ").\n";
}

int main(int argc, char** argv) {
  std::unique_ptr<SonosInterface> sonos;
  sonos.reset(CreateSonosInterface());

  sonos->AddDeviceObserver(new MyDeviceObserver());
  sonos->Start();

  std::string command;
  while (std::getline(std::cin, command)) {
    if (equalsIgnoreCase(command, "QUIT") || equalsIgnoreCase(command, "EXIT"))
      break;

    if (equalsIgnoreCase(command, "HELP"))
      displayHelp();
    else if (equalsIgnoreCase(command, "DEVICES"))
      displayDevices(*sonos);
    else
      std::cout << ">> Unrecognized command: " << command << "\n";
  }

  return 0;
}
