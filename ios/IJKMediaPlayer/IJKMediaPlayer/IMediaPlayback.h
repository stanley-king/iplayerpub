#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, MPMovieScalingMode) {
    MPMovieScalingModeNone,       // No scaling
    MPMovieScalingModeAspectFit,  // Uniform scale until one dimension fits
    MPMovieScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
    MPMovieScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds
};

typedef NS_ENUM(NSInteger, MPMoviePlaybackState) {
    MPMoviePlaybackStateStopped,
    MPMoviePlaybackStatePlaying,
    MPMoviePlaybackStatePaused,
    MPMoviePlaybackStateInterrupted,
    MPMoviePlaybackStateSeekingForward,
    MPMoviePlaybackStateSeekingBackward
};

typedef NS_OPTIONS(NSUInteger, MPMovieLoadState) {
    MPMovieLoadStateUnknown        = 0,
    MPMovieLoadStatePlayable       = 1 << 0,
    MPMovieLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
    MPMovieLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
};

typedef NS_ENUM(NSInteger, MPMovieFinishReason) {
    MPMovieFinishReasonPlaybackEnded,
    MPMovieFinishReasonPlaybackError,
    MPMovieFinishReasonUserExited
};

// -----------------------------------------------------------------------------
// Thumbnails

typedef NS_ENUM(NSInteger, MPMovieTimeOption) {
    MPMovieTimeOptionNearestKeyFrame,
    MPMovieTimeOptionExact
};

@protocol IMediaPlayback <NSObject>
- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isMute;
- (BOOL)mute;
- (BOOL)unmute;
- (BOOL)isPlaying;
- (void)shutdown;
- (void)setPauseInBackground:(BOOL)pause;

@property(nonatomic, readonly)  UIView *view;
@property(nonatomic)            NSTimeInterval  currentPlaybackTime;
@property(nonatomic, readonly)  NSTimeInterval  duration;
@property(nonatomic, readonly)  NSTimeInterval  playableDuration;
@property(nonatomic, readonly)  NSInteger       bufferingProgress;

@property(nonatomic, readonly)  BOOL isPreparedToPlay;
@property(nonatomic, readonly)  MPMoviePlaybackState playbackState;
@property(nonatomic, readonly)  MPMovieLoadState loadState;
@property(nonatomic, readonly)  int isSeekBuffering;
@property(nonatomic, readonly)  int isAudioSync;
@property(nonatomic, readonly)  int isVideoSync;

@property(nonatomic, readonly) int64_t numberOfBytesTransferred;

@property(nonatomic, readonly) CGSize naturalSize;
@property(nonatomic) MPMovieScalingMode scalingMode;
@property(nonatomic) BOOL shouldAutoplay;

@property (nonatomic) BOOL allowsMediaAirPlay;
@property (nonatomic) BOOL isDanmakuMediaAirPlay;
@property (nonatomic, readonly) BOOL airPlayMediaActive;

@property (nonatomic) float playbackRate;
@property (nonatomic) float playbackVolume;

- (UIImage *)thumbnailImageAtCurrentTime;

#pragma mark Notifications

#ifdef __cplusplus
#define FF_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define FF_EXTERN extern __attribute__((visibility ("default")))
#endif

// -----------------------------------------------------------------------------
//  MPMediaPlayback.h

// Posted when the prepared state changes of an object conforming to the MPMediaPlayback protocol changes.
// This supersedes MPMoviePlayerContentPreloadDidFinishNotification.
FF_EXTERN NSString *const MPMediaPlaybackIsPreparedToPlayDidChangeNotification;

// -----------------------------------------------------------------------------
//  MPMoviePlayerController.h
//  Movie Player Notifications

// Posted when the scaling mode changes.
FF_EXTERN NSString* const MPMoviePlayerScalingModeDidChangeNotification;

// Posted when movie playback ends or a user exits playback.
FF_EXTERN NSString* const MPMoviePlayerPlaybackDidFinishNotification;
FF_EXTERN NSString* const MPMoviePlayerPlaybackDidFinishReasonUserInfoKey; // NSNumber (IJKMPMovieFinishReason)

// Posted when the playback state changes, either programatically or by the user.
FF_EXTERN NSString* const MPMoviePlayerPlaybackStateDidChangeNotification;

// Posted when the network load state changes.
FF_EXTERN NSString* const MPMoviePlayerLoadStateDidChangeNotification;

// Posted when the movie player begins or ends playing video via AirPlay.
FF_EXTERN NSString* const MPMoviePlayerIsAirPlayVideoActiveDidChangeNotification;

// -----------------------------------------------------------------------------
// Movie Property Notifications

// Calling -prepareToPlay on the movie player will begin determining movie properties asynchronously.
// These notifications are posted when the associated movie property becomes available.
FF_EXTERN NSString* const MPMovieNaturalSizeAvailableNotification;

// -----------------------------------------------------------------------------
//  Extend Notifications
FF_EXTERN NSString *const MPMoviePlayerVideoDecoderOpenNotification;
FF_EXTERN NSString *const MPMoviePlayerFirstVideoFrameRenderedNotification;
FF_EXTERN NSString *const MPMoviePlayerFirstAudioFrameRenderedNotification;
FF_EXTERN NSString *const MPMoviePlayerFirstAudioFrameDecodedNotification;
FF_EXTERN NSString *const MPMoviePlayerFirstVideoFrameDecodedNotification;
FF_EXTERN NSString *const MPMoviePlayerOpenInputNotification;
FF_EXTERN NSString *const MPMoviePlayerFindStreamInfoNotification;
FF_EXTERN NSString *const MPMoviePlayerComponentOpenNotification;

FF_EXTERN NSString *const MPMoviePlayerDidSeekCompleteNotification;
FF_EXTERN NSString *const MPMoviePlayerDidSeekCompleteTargetKey;
FF_EXTERN NSString *const MPMoviePlayerDidSeekCompleteErrorKey;
FF_EXTERN NSString *const MPMoviePlayerDidAccurateSeekCompleteCurPos;
FF_EXTERN NSString *const MPMoviePlayerAccurateSeekCompleteNotification;
FF_EXTERN NSString *const MPMoviePlayerSeekAudioStartNotification;
FF_EXTERN NSString *const MPMoviePlayerSeekVideoStartNotification;

@end
