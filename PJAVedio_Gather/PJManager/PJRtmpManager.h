//
//  PJRtmpManager.h
//  PJAVedio_Gather
//
//  Created by PlatoJobs on 2019/2/22.
//  Copyright © 2019 David. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "rtmp.h"
NS_ASSUME_NONNULL_BEGIN

@interface PJRtmpManager : NSObject

{
    RTMP* rtmp;
    double start_time;
    dispatch_queue_t workQueue;//异步Queue
}

@property (nonatomic,copy) NSString* rtmpUrl;//rtmp服务器流地址

- (RTMP*)pj_getCurrentRtmp;

/**
 *  获取单例
 *
 *  @return 单例
 */
+ (instancetype)pj_getInstance;

/**
 *  开始连接服务器
 *
 *  @return 是否成功
 */
- (BOOL)pj_startRtmpConnect;

/**
 *  停止连接服务器
 *
 *  @return 是否成功
 */
- (BOOL)pj_stopRtmpConnect;

/**
 *  sps and pps帧
 *
 *  @param sps     第一帧
 *  @param sps_len 第一帧长度
 *  @param pps     第二帧
 *  @param pps_len 第二帧长度
 */
- (void)pj_send_video_sps_pps:(unsigned char*)sps andSpsLength:(int)sps_len andPPs:(unsigned char*)pps andPPsLength:(uint32_t)pps_len;

/**
 *  发送视频
 *
 *  @param buf 关键帧或者非关键帧
 *  @param len 长度
 */
- (void)pj_send_rtmp_video:(unsigned char*)buf andLength:(uint32_t)len;

/**
 *  发送音频
 *
 *  @param buf 音频数据（aac）
 *  @param len 音频长度
 */
- (void)pj_send_rtmp_audio:(unsigned char*)buf andLength:(uint32_t)len;

/**
 *  发送音频spec
 *
 *  @param spec_buf spec数据
 *  @param spec_len spec长度
 */
- (void)pj_send_rtmp_audio_spec:(unsigned char *)spec_buf andLength:(uint32_t) spec_len;


@end

NS_ASSUME_NONNULL_END
