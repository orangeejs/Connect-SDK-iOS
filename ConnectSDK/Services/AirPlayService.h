//
//  AirPlayService.h
//  Connect SDK
//
//  Created by Jeremy White on 4/18/14.
//  Copyright (c) 2014 LG Electronics.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#define kConnectSDKAirPlayServiceId @"AirPlay"

#import <Foundation/Foundation.h>
#import "DeviceService.h"
#import "AirPlayHTTPService.h"
#import "AirPlayMirroredService.h"
#import "MediaPlayer.h"
#import "MediaControl.h"
#import "WebAppLauncher.h"

/*!
 * This enum defines how the AirPlayService should behave, in terms of sending commands to the AirPlay device.
 */
typedef enum {
    AirPlayServiceModeMirrored = 0, /*! Requires AirPlay mirroring to be enabled on the iOS device */
    AirPlayServiceModeHTTP, /*! Sends commands to the AirPlay device via HTTP request */
    AirPlayServiceModeMixed /*! Mixes the mirrored & HTTP modes (HTTP for photo/media, mirrored for web app launcher) */
} AirPlayServiceMode;

@interface AirPlayService : DeviceService <MediaPlayer, MediaControl, WebAppLauncher>

@property (nonatomic, readonly) AirPlayHTTPService *httpService;
@property (nonatomic, readonly) AirPlayMirroredService *mirroredService;

/*!
 * Returns the AirPlayServiceMode
 */
+ (AirPlayServiceMode) serviceMode;

/*!
 * Sets the AirPlayService mode. For consistency's sake, this property should be set before DiscoveryManager is set for the first time.
 */
+ (void) setAirPlayServiceMode:(AirPlayServiceMode)serviceMode;

@end