ofxBlackmagic2
==============

<img src="https://raw.github.com/elliotwoods/ofxBlackmagic2/master/ofxaddons_thumbnail.png" />

This fork of Elliot Woods ofxBlackmagic2 addon for openframeworks has been altered to work with openframeworks 0.1.0 and vs2017 as well as working with the project generator, it no longer adheres to Elliot Wood's addon pattern (sorry, great system, but I neeeded a fast fix) and does not require ofxaddonlib.

Features:

* Uses DeckLink SDK for colour conversion (much faster/more efficient than hand-rolled solutions)
* Designed for use with multiple devices (and devices with multiple inputs, e.g. DeckLink Quad)
* Object oriented with namespaces
* Lockable frames for threading

Alternatives:

* https://github.com/jamezilla/ofxBlackmagic 
* https://github.com/kylemcdonald/ofxBlackmagic

Installation
------------

This addon has been tested on Windows, but it should also work on OSX and Linux (by including the DeckLink SDK's for those platforms in your project and ignoring DeckLinkAPI_i.c, DeckLinkAPI_i.h).

On Windows, install BlackMagic Desktop Video (not the SDK), then try out an example.

Designed to work with all DeckLink products, e.g.:

* Intensity Pro/Shuttle/Thunderbolt
* DeckLink Quad
* DeckLink SDI
* UltraStudio 4K
* UltraStudio Mini Recorder
* etc

Tested with:

* DeckLink Quad
* Blackmagic Production Camera 4k
* Intensity Pro

Warning
-------

Due to particular type names in DeckLinkAPI.h, ofxBlackMagic.h must be included before ofMain.h (or addons which include ofMain.h) in your ofApp.h (or elsewhere).

Setting up new projects
------------


#### Include Order

ofxBlackmagic2 is a little finicky about the order it is added in, and must be included before everything else in your program.

1. Make sure `ofxBlackMagic2.h` is included above everything else in your `ofApp.h` file (or wherever else you are using it).
    ```
    #pragma once

    #include "ofxBlackmagic.h"
    #include "ofMain.h"

    ...
    ```
2. Make sure `ofApp.h` (or whichever file is including the addon) is included above everything else in your `main.cpp` file.
    ```
    #include "ofApp.h"
    #include "ofMain.h"

    //========================================================================
    int main(){
        ...
    }
    ```

License
-------

MIT License
http://opensource.org/licenses/MIT
