#import "IMediaPlayback.h"
#import "FFMpegMonitor.h"
#import "FFMpegOptions.h"
#import "ISDLGLView.h"

typedef enum LogLevel {
    kLOG_UNKNOWN = 0,
    kLOG_DEFAULT = 1,
    kLOG_VERBOSE = 2,
    kLOG_DEBUG   = 3,
    kLOG_INFO    = 4,
    kLOG_WARN    = 5,
    kLOG_ERROR   = 6,
    kLOG_FATAL   = 7,
    kLOG_SILENT  = 8,
} LogLevel;

@interface FFMpegPlayerController : NSObject <IMediaPlayback>

- (id)initWithContentURL:(NSURL *)aUrl;
- (id)initWithContentURLString:(NSString *)aUrlString;
- (id)initWithMoreContent:(NSURL *)aUrl
               withGLView:(UIView<ISDLGLView> *)glView;
- (id)initWithMoreContentString:(NSString *)aUrlString
                     withGLView:(UIView<ISDLGLView> *)glView;

- (void)setHudValue:(NSString *)value forKey:(NSString *)key;
+ (void)setLogReport:(BOOL)preferLogReport;
+ (void)setLogLevel:(LogLevel)logLevel;

@property(nonatomic, readonly) CGFloat fpsInMeta;
@property(nonatomic, readonly) CGFloat fpsAtOutput;
@property(nonatomic) BOOL shouldShowHudView;

- (void)setOptionValue:(NSString *)value
                forKey:(NSString *)key
            ofCategory:(FFOptionCategory)category;

- (void)setOptionIntValue:(int64_t)value
                   forKey:(NSString *)key
               ofCategory:(FFOptionCategory)category;

- (void)setFormatOptionValue:       (NSString *)value forKey:(NSString *)key;
- (void)setCodecOptionValue:        (NSString *)value forKey:(NSString *)key;
- (void)setSwsOptionValue:          (NSString *)value forKey:(NSString *)key;
- (void)setPlayerOptionValue:       (NSString *)value forKey:(NSString *)key;

- (void)setFormatOptionIntValue:    (int64_t)value forKey:(NSString *)key;
- (void)setCodecOptionIntValue:     (int64_t)value forKey:(NSString *)key;
- (void)setSwsOptionIntValue:       (int64_t)value forKey:(NSString *)key;
- (void)setPlayerOptionIntValue:    (int64_t)value forKey:(NSString *)key;

@property (nonatomic, retain) id<IJKMediaUrlOpenDelegate> segmentOpenDelegate;
@property (nonatomic, retain) id<IJKMediaUrlOpenDelegate> tcpOpenDelegate;
@property (nonatomic, retain) id<IJKMediaUrlOpenDelegate> httpOpenDelegate;
@property (nonatomic, retain) id<IJKMediaUrlOpenDelegate> liveOpenDelegate;
@property (nonatomic, retain) id<IJKMediaNativeInvokeDelegate> nativeInvokeDelegate;

#pragma mark KVO properties
@property (nonatomic, readonly) FFMpegMonitor *monitor;
@end