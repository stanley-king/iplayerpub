#import "IMediaPlayback.h"

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

+ (void)setLogReport:(BOOL)preferLogReport;
+ (void)setLogLevel:(LogLevel)logLevel;

@end
