//
//  PJX264Manager.h
//  PJAVedio_Gather
//
//  Created by PlatoJobs on 2019/2/22.
//  Copyright © 2019 David. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "x264.h"
#import <CoreMedia/CoreMedia.h>
NS_ASSUME_NONNULL_BEGIN

@interface PJX264Manager : NSObject

{
    x264_param_t * p264Param;
    x264_picture_t * p264Pic;
    x264_t *p264Handle;
    x264_nal_t  *p264Nal;
    FILE *fp;
    unsigned char sps[30];
    unsigned char pps[10];
}

- (void)pj_initForX264WithWidth:(int)width height:(int)height;


- (void)pj_encoderToH264:(CMSampleBufferRef)sampleBuffer;

+(PJX264Manager*)getInstance;

- (void)pj_stopEncoding;


@end

NS_ASSUME_NONNULL_END
