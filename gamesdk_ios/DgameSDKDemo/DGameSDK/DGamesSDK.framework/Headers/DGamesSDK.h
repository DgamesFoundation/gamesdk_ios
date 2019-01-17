//
//  DGamesSDK.h
//  DGamesSDK
//
//  Created by Zhang on 2018/8/1.
//  Copyright © 2018年 DGames. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DGamesSDKConfig : NSObject

@property (nonatomic, assign) BOOL landscape;

@property (nonatomic, copy) NSString *appId;

@property (nonatomic, copy) NSString *gameRechargeAddress;

@property (nonatomic, copy) NSString *dgameRechargeAddress;

@property (nonatomic, copy) NSString *apiBrowse;

@property (nonatomic, copy) NSString *precision;

@property (nonatomic, copy) NSString *amount;

@property (nonatomic, copy) NSString *orderId;

@property (nonatomic, copy) NSString *comment;

@property (nonatomic, copy) NSString *language;

@property (nonatomic, assign) BOOL isDebug;

@end

typedef void(^loginResult)(NSDictionary *result);

typedef void(^payResult)(NSDictionary *result);

@interface DGamesSDK : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, strong, readonly) DGamesSDKConfig *gamesSDKConfig;

@property (nonatomic, copy) loginResult loginResult;

- (void)startGamesWhenFinishLaunch;

- (void)startGamesWhenForeGround;

- (void)stopGamesWhenBackground;

- (void)setUpSDKConfig:(DGamesSDKConfig *)sdkConfig;

- (NSMutableDictionary *)queryUserBalance:(NSString *)address;

- (NSMutableDictionary *)queryDgasBanlance:(NSString *)address;

/**
 login
 */
- (UIViewController *)login;

/**
 personalCenter
 */
- (UIViewController *)personalCenter;

/**
 pay
 */
- (UIViewController *)pay;

@end
