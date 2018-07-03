// Add this one here to make sure ofxBlackMagic compile fine 
// with other networking addons
#ifdef _WIN32
#include <winsock2.h>
#endif

#include "Iterator.h"
#include "Input.h"
#include "Output.h"
#include "DeviceList.h"

#undef small