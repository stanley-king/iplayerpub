#import "IMediaPlayback.h"
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

@property (nonatomic, retain) id<IJKMediaUrlOpenDelegate> segmentOpenDelegate;
@property (nonatomic, retain) id<IJKMediaUrlOpenDelegate> tcpOpenDelegate;
@property (nonatomic, retain) id<IJKMediaUrlOpenDelegate> httpOpenDelegate;
@property (nonatomic, retain) id<IJKMediaUrlOpenDelegate> liveOpenDelegate;
@property (nonatomic, retain) id<IJKMediaNativeInvokeDelegate> nativeInvokeDelegate;

@end