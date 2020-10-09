#include "BlackMagicHelper.h"

std::vector<BlackMagicHelper::InputMode> BlackMagicHelper::InputModes = {
	{ BMDDisplayMode::bmdModePAL, 720, 576, 25 },
	{ BMDDisplayMode::bmdModePALp, 720, 576, 50 },
	{ BMDDisplayMode::bmdModeNTSC, 720, 486, 29.97 },
	{ BMDDisplayMode::bmdModeNTSCp, 720, 486, 59.94 },
	{ BMDDisplayMode::bmdModeHD720p50, 1280, 720, 50 },
	{ BMDDisplayMode::bmdModeHD720p5994, 1280, 720, 59.94 },
	{ BMDDisplayMode::bmdModeHD720p60, 1280, 720, 60 },
	{ BMDDisplayMode::bmdModeHD1080p2398, 1920, 1080, 23.98 },
	{ BMDDisplayMode::bmdModeHD1080p24, 1920, 1080, 24 },
	{ BMDDisplayMode::bmdModeHD1080p25, 1920, 1080, 25 },
	{ BMDDisplayMode::bmdModeHD1080p2997, 1920, 1080, 29.97 },
	{ BMDDisplayMode::bmdModeHD1080p30, 1920, 1080, 30 },
	{ BMDDisplayMode::bmdModeHD1080i50, 1920, 1080, 25 },
	{ BMDDisplayMode::bmdModeHD1080i5994, 1920, 1080, 29.97 },
	{ BMDDisplayMode::bmdModeHD1080i6000, 1920, 1080, 30 },
	{ BMDDisplayMode::bmdModeHD1080p50, 1920, 1080, 50 },
	{ BMDDisplayMode::bmdModeHD1080p5994, 1920, 1080, 59.94 },
	{ BMDDisplayMode::bmdModeHD1080p6000, 1920, 1080, 60 },
	{ BMDDisplayMode::bmdMode2k2398, 2048, 1556, 23.98 },
	{ BMDDisplayMode::bmdMode2k24, 2048, 1556, 24 },
	{ BMDDisplayMode::bmdMode2k25, 2048, 1556, 25 },
	//{ BMDDisplayMode::bmdMode2kDCI2398, 2048, 1080, 23.98 },
	//{ BMDDisplayMode::bmdMode2kDCI24, 2048, 1080, 24 },
	//{ BMDDisplayMode::bmdMode2kDCI25, 2048, 1080, 25 },
	{ BMDDisplayMode::bmdMode4K2160p2398, 3840, 2160, 23.98 },
	{ BMDDisplayMode::bmdMode4K2160p24, 3840, 2160, 24 },
	{ BMDDisplayMode::bmdMode4K2160p25, 3840, 2160, 25 },
	{ BMDDisplayMode::bmdMode4K2160p2997, 3840, 2160, 29.97 },
	{ BMDDisplayMode::bmdMode4K2160p30, 3840, 2160, 30 },
	//{ BMDDisplayMode::bmdMode4K2160p50, 3840, 2160, 50 },
	//{ BMDDisplayMode::bmdMode4K2160p5994, 3840, 2160, 59.94 },
	//{ BMDDisplayMode::bmdMode4K2160p60, 3840, 2160, 60 },
	{ BMDDisplayMode::bmdMode4kDCI2398, 4096, 2160, 23.98 },
	{ BMDDisplayMode::bmdMode4kDCI24, 4096, 2160, 24 },
	{ BMDDisplayMode::bmdMode4kDCI25, 4096, 2160, 25 }
};


//Returns the corresponding BlackMagic display mode - returns bmdModeUnknown on error
BMDDisplayMode BlackMagicHelper::GetDisplayMode(int Width, int Height, float FrameRate)
{
	for (int i = 0; i < BlackMagicHelper::InputModes.size(); i++)
	{
		if ((BlackMagicHelper::InputModes[i].Width == Width) && (BlackMagicHelper::InputModes[i].Height == Height) && (BlackMagicHelper::InputModes[i].FrameRate == FrameRate))
		{
			return BlackMagicHelper::InputModes[i].BMDMode;
		}
	}


	return BMDDisplayMode::bmdModeUnknown;
}


std::map<std::string, BMDDisplayMode> BlackMagicHelper::DisplayModesMap = {
	{ "bmdModeNTSC", bmdModeNTSC },
	{ "bmdModeNTSC2398", bmdModeNTSC2398 },
	{ "bmdModePAL", bmdModePAL },
	{ "bmdModeNTSCp", bmdModeNTSCp },
	{ "bmdModePALp", bmdModePALp },
	{ "bmdModeHD1080p2398", bmdModeHD1080p2398 },
	{ "bmdModeHD1080p24", bmdModeHD1080p24 },
	{ "bmdModeHD1080p25", bmdModeHD1080p25 },
	{ "bmdModeHD1080p2997", bmdModeHD1080p2997 },
	{ "bmdModeHD1080p30", bmdModeHD1080p30 },
	{ "bmdModeHD1080i50", bmdModeHD1080i50 },
	{ "bmdModeHD1080i5994", bmdModeHD1080i5994 },
	{ "bmdModeHD1080i6000", bmdModeHD1080i6000 },
	{ "bmdModeHD1080p50", bmdModeHD1080p50 },
	{ "bmdModeHD1080p5994", bmdModeHD1080p5994 },
	{ "bmdModeHD1080p6000", bmdModeHD1080p6000 },
	{ "bmdModeHD720p50", bmdModeHD720p50 },
	{ "bmdModeHD720p5994", bmdModeHD720p5994 },
	{ "bmdModeHD720p60", bmdModeHD720p60 },
	{ "bmdMode2k2398", bmdMode2k2398 },
	{ "bmdMode2k24", bmdMode2k24 },
	{ "bmdMode2k25", bmdMode2k25 },
	{ "bmdMode4K2160p2398", bmdMode4K2160p2398 },
	{ "bmdMode4K2160p24", bmdMode4K2160p24 },
	{ "bmdMode4K2160p25", bmdMode4K2160p25 },
	{ "bmdMode4K2160p2997", bmdMode4K2160p2997 },
	{ "bmdMode4K2160p30", bmdMode4K2160p30 },
	{ "bmdMode4kDCI2398", bmdMode4kDCI2398 },
	{ "bmdMode4kDCI24", bmdMode4kDCI24 },
	{ "bmdMode4kDCI25", bmdMode4kDCI25 },
	{ "bmdModeUnknown", bmdModeUnknown }
};
//Returns the corresponding BlackMagic display mode - returns bmdModeUnknown on error
BMDDisplayMode BlackMagicHelper::GetDisplayMode(const std::string &mode_str)
{
	auto found = DisplayModesMap.find(mode_str);
	if(found == std::end(DisplayModesMap)) {
		return bmdModeUnknown;
	}
	return found->second;
}
