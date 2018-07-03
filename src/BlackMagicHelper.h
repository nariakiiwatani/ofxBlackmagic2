#pragma once
#include <ofxBlackmagic2\src\ofxBlackMagic.h>
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

public:
	//Returns the corresponding BlackMagic display mode - returns bmdModeUnknown on error
	static BMDDisplayMode GetDisplayMode(int Width, int Height, float FrameRate);
};

