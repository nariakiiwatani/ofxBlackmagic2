#pragma once
#include "ofxBlackMagic.h"
class BlackMagicHelper
{
private:
	//Defines one input format
	struct InputMode
	{
		BMDDisplayMode BMDMode;
		int Width;
		int Height;
		double FrameRate;
	};
	//Vector holding all the supported display modes
	static std::vector<BlackMagicHelper::InputMode> BlackMagicHelper::InputModes;
	//Map display modes name(std::string) into display modes
	static std::map<std::string, BMDDisplayMode> BlackMagicHelper::DisplayModesMap;

public:
	//Returns the corresponding BlackMagic display mode - returns bmdModeUnknown on error
	static BMDDisplayMode GetDisplayMode(int Width, int Height, float FrameRate);
	static BMDDisplayMode GetDisplayMode(const std::string &mode_str);
};

