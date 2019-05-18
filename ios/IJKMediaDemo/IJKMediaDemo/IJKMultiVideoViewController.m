//
// Created by stanley on 2019-05-09.
// Copyright (c) 2019 bilibili. All rights reserved.
//

#import "IJKMultiVideoViewController.h"
#import "IJKVideoViewController.h"
#import "IJKDemoHistory.h"

@implementation IJKMultiVideoViewController

+ (void)presentFromViewController:(UIViewController *)viewController withTitle:(NSString *)title URL:(NSURL *)url completion:(void (^)())completion {
    IJKDemoHistoryItem *historyItem = [[IJKDemoHistoryItem alloc] init];

    historyItem.title = title;
    historyItem.url = url;
    [[IJKDemoHistory instance] add:historyItem];

    [viewController presentViewController:[[IJKMultiVideoViewController alloc] initWithURL:url] animated:YES completion:completion];
}

- (instancetype)initWithURL:(NSURL *)url {
    self = [self initWithNibName:@"IJKMultiVideoViewController" bundle:nil];
    if (self) {
        self.url = url;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

//    IJKVideoViewController *vc = [[IJKVideoViewController alloc] init];
    {
        IJKVideoViewController *vc = [[IJKVideoViewController alloc] initWithURL:self.url];
        [self addChildViewController:vc];
        [self.view addSubview:vc.view];

        CGRect frame = self.view.frame;
        frame.origin.x = 0;
        frame.origin.y = 0;

        frame.size.width = frame.size.width / 2.0;
        vc.view.frame = frame;

    }

    {
//        IJKVideoViewController *vc = [[IJKVideoViewController alloc] initWithURL:self.url];

        NSString* strurl = @"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear2/prog_index.m3u8";

        NSURL* url  = [NSURL URLWithString:strurl];

        IJKVideoViewController *vc = [[IJKVideoViewController alloc] initWithURL:url];
        [self addChildViewController:vc];
        [self.view addSubview:vc.view];

        CGRect frame = self.view.frame;
        frame.origin.x =  frame.size.width / 2.0;
        frame.origin.y = 0;
        frame.size.width = frame.size.width / 2.0;
        vc.view.frame = frame;

    }
}

@end
