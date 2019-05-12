//
// Created by stanley on 2019-05-09.
// Copyright (c) 2019 bilibili. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IJKMediaFramework/IJKMediaFramework.h>

@class IJKVideoViewController;

@interface IJKMultiVideoViewController : UIViewController
- (id)initWithURL:(NSURL *)url;
+ (void)presentFromViewController:(UIViewController *)viewController withTitle:(NSString *)title URL:(NSURL *)url completion:(void(^)())completion;

@property(atomic,strong) NSURL *url;

@end