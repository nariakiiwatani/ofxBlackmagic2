//
//  ofxBlackmagic::Grabber
//
//  Created by Iwatani Nariaki on 2020/10/07.
//
//  Wrap ofxBlackmagic2 into ofBaseVideoGrabber

#pragma once

#include "ofxBlackMagic.h"
#include "ofVideoBaseTypes.h"

namespace ofxBlackmagic {
class Grabber : public ofBaseVideoGrabber
{
public:
	std::vector<ofVideoDevice> listDevices() const {
		std::vector<ofVideoDevice> ret;
		for(auto &&dev : ofxBlackmagic::Iterator::getDeviceList()) {
			ofVideoDevice of_dev;
			of_dev.id = ret.size();
			of_dev.deviceName = dev.modelName;
			of_dev.bAvailable = true;
			ret.push_back(of_dev);
		}
		return ret;
	}
	void setDeviceID(int device_id) { device_index_ = device_id; }
	void setMode(const BMDDisplayMode &mode) { mode_ = mode; }
	bool setup(int w, int h) {
		auto dev_list = ofxBlackmagic::Iterator::getDeviceList();
		if(dev_list.size() <= device_index_) {
			return false;
		}
		input_.startCapture(dev_list[device_index_], mode_);
		return input_.isRunning();
	}
	void update() { input_.update(); }
	float getWidth() const { return input_.getWidth(); }
	float getHeight() const { return input_.getHeight(); }
	bool isFrameNew() const { return input_.isFrameNew(); };
	void close() { input_.stopCapture(); }
	bool isInitialized() const { return input_.isRunning(); }
	bool setPixelFormat(ofPixelFormat pixelFormat) {
		switch(pixelFormat) {
			case OF_PIXELS_RGBA:
				return true;
		}
		ofLogWarning("ofxBlackmagic::Grabber") << "only OF_PIXELS_RGBA is supported";
		return false;
	}
	ofPixelFormat getPixelFormat() const { return OF_PIXELS_RGBA; }
	ofPixels& getPixels() { return input_.getPixels(); }
	const ofPixels& getPixels() const { return input_.getPixels(); }
protected:
	ofxBlackmagic::Input input_;
	int device_index_=0;
	BMDDisplayMode mode_=bmdModeHD1080p30;

};
}