/*
 * IMediaPlayback.m
 *
 * Copyright (c) 2013 Bilibili
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#import "IMediaPlayback.h"
#import "IJKMediaUrlOpenData.h"

NSString *const MPMediaPlaybackIsPreparedToPlayDidChangeNotification = @"MPMediaPlaybackIsPreparedToPlayDidChangeNotification";

NSString *const MPMoviePlayerPlaybackDidFinishNotification = @"MPMoviePlayerPlaybackDidFinishNotification";
NSString *const MPMoviePlayerPlaybackDidFinishReasonUserInfoKey =
    @"MPMoviePlayerPlaybackDidFinishReasonUserInfoKey";
NSString *const MPMoviePlayerPlaybackStateDidChangeNotification = @"MPMoviePlayerPlaybackStateDidChangeNotification";
NSString *const MPMoviePlayerLoadStateDidChangeNotification = @"MPMoviePlayerLoadStateDidChangeNotification";

NSString *const MPMoviePlayerIsAirPlayVideoActiveDidChangeNotification = @"MPMoviePlayerIsAirPlayVideoActiveDidChangeNotification";

NSString *const MPMovieNaturalSizeAvailableNotification = @"MPMovieNaturalSizeAvailableNotification";

NSString *const MPMoviePlayerVideoDecoderOpenNotification = @"MPMoviePlayerVideoDecoderOpenNotification";

NSString *const MPMoviePlayerFirstVideoFrameRenderedNotification = @"MPMoviePlayerFirstVideoFrameRenderedNotification";
NSString *const MPMoviePlayerFirstAudioFrameRenderedNotification = @"MPMoviePlayerFirstAudioFrameRenderedNotification";
NSString *const MPMoviePlayerFirstAudioFrameDecodedNotification  = @"MPMoviePlayerFirstAudioFrameDecodedNotification";
NSString *const MPMoviePlayerFirstVideoFrameDecodedNotification  = @"MPMoviePlayerFirstVideoFrameDecodedNotification";
NSString *const MPMoviePlayerOpenInputNotification               = @"MPMoviePlayerOpenInputNotification";
NSString *const MPMoviePlayerFindStreamInfoNotification          = @"MPMoviePlayerFindStreamInfoNotification";
NSString *const MPMoviePlayerComponentOpenNotification           = @"MPMoviePlayerComponentOpenNotification";

NSString *const MPMoviePlayerAccurateSeekCompleteNotification = @"MPMoviePlayerAccurateSeekCompleteNotification";

NSString *const MPMoviePlayerDidSeekCompleteNotification = @"MPMoviePlayerDidSeekCompleteNotification";
NSString *const MPMoviePlayerDidSeekCompleteTargetKey = @"MPMoviePlayerDidSeekCompleteTargetKey";
NSString *const MPMoviePlayerDidSeekCompleteErrorKey = @"MPMoviePlayerDidSeekCompleteErrorKey";
NSString *const MPMoviePlayerDidAccurateSeekCompleteCurPos = @"MPMoviePlayerDidAccurateSeekCompleteCurPos";

NSString *const MPMoviePlayerSeekAudioStartNotification  = @"MPMoviePlayerSeekAudioStartNotification";
NSString *const MPMoviePlayerSeekVideoStartNotification  = @"MPMoviePlayerSeekVideoStartNotification";

@implementation IJKMediaUrlOpenData {
    NSString *_url;
    BOOL _handled;
    BOOL _urlChanged;
}

- (id)initWithUrl:(NSString *)url
            event:(MediaEvent)event
     segmentIndex:(int)segmentIndex
     retryCounter:(int)retryCounter
{
    self = [super init];
    if (self) {
        self->_url          = url;
        self->_event        = event;
        self->_segmentIndex = segmentIndex;
        self->_retryCounter = retryCounter;

        self->_error        = 0;
        self->_handled      = NO;
        self->_urlChanged   = NO;
    }
    return self;
}

- (void)setHandled:(BOOL)handled
{
    _handled = handled;
}

- (BOOL)isHandled
{
    return _handled;
}

- (BOOL)isUrlChanged
{
    return _urlChanged;
}

- (NSString *)url
{
    return _url;
}

- (void)setUrl:(NSString *)url
{
    assert(url);

    _handled = YES;

    if (![self.url isEqualToString:url]) {
        _urlChanged = YES;
        _url = url;
    }
}

@end
