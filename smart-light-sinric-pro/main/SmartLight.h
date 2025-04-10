#ifndef _SMARTLIGHT_H_
#define _SMARTLIGHT_H_

#include <SinricProDevice.h>
#include <Capabilities/PowerStateController.h>

class SmartLight 
: public SinricProDevice
, public PowerStateController<SmartLight> {
  friend class PowerStateController<SmartLight>;
public:
  SmartLight(const String &deviceId) : SinricProDevice(deviceId, "SmartLight") {};
};

#endif
