//
//  PJAudioManager.h
//  PJAVedio_Gather
//
//  Created by PlatoJobs on 2019/2/22.
//  Copyright © 2019 David. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "faac.h"
#define kNumberOfRecordBuffers 3
#define Bitrate 200//码率

NS_ASSUME_NONNULL_BEGIN

@interface PJAudioManager : NSObject

{
    AudioStreamBasicDescription basicDescription;
    AudioQueueRef               queueRef;
    AudioQueueBufferRef         buffer[3];
    
    BOOL                        recording;
    BOOL                        running;
    
    faacEncHandle               audioEncoder;
    unsigned long               inputSamples;
    unsigned long               maxOutputBytes;
    unsigned long               maxInputBytes;
    unsigned char*              outputBuffer;
    
    FILE *fp;
}

+ (instancetype)pj_GetInstance;

/**
 *  初始化编码
 */
- (void)pj_InitRecording;

/**
 *  开始录制
 */
- (void)pj_StartRecording;

/**
 *  暂停录制
 */
- (void)pj_PauseRecording;

/**
 *  结束录制
 */
- (void)pj_StopRecording;

@end

NS_ASSUME_NONNULL_END
