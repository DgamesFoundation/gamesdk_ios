#import "ViewController.h"
#import <DGamesSDK/DGamesSDK.h>
#import <DGamesSDK/SuspendBall.h>

@interface ViewController () <SuspendBallDelegte>
@property (weak, nonatomic) IBOutlet UITextField *inputTextField;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    DGamesSDKConfig *sdkConfig = [[DGamesSDKConfig alloc] init];
    sdkConfig.landscape = NO;
    sdkConfig.appId = @"V431rSWOMpq3xGGJYSQTGH5oxlMBiXjJRw";
    sdkConfig.gameRechargeAddress = @"VwD125l3OU_ehHDY0yFgVzbmUSFPTu7kbw";
    sdkConfig.dgameRechargeAddress = @"0x75b9abcf3220637e9fc2733c06d3408271c42aeb";
    sdkConfig.apiBrowse = @"https://query.fb.dgame.org:4490";
    sdkConfig.precision = @"100000000";
    sdkConfig.amount = @"1";
    sdkConfig.orderId = @"6.074545446483526E7";
    sdkConfig.comment = @"";
    sdkConfig.language = @"cn";
    sdkConfig.isDebug = false;
    [[DGamesSDK sharedInstance] setUpSDKConfig:sdkConfig];
    
    SuspendBall *suspendBall = [SuspendBall suspendBallWithFrame:CGRectMake(0, 64, 50, 50) delegate:self subBallImageArray:@[]];
    [self.view addSubview:suspendBall];
}

- (IBAction)loginAction:(id)sender {
    [self presentViewController:DGamesSDK.sharedInstance.login animated:NO completion:nil];

}

- (IBAction)personCenterAction:(id)sender {
    [self presentViewController:DGamesSDK.sharedInstance.personalCenter animated:NO completion:nil];
}

- (IBAction)payAction:(id)sender {
    [DGamesSDK sharedInstance].gamesSDKConfig.amount = self.inputTextField.text;
    [self presentViewController:DGamesSDK.sharedInstance.pay animated:NO completion:nil];
}

#pragma mark - SuspendBallDelegte
- (void)suspendBall:(UIButton *)subBall didSelectTag:(NSInteger)tag {
    [self presentViewController:DGamesSDK.sharedInstance.personalCenter animated:NO completion:nil];
}

@end
