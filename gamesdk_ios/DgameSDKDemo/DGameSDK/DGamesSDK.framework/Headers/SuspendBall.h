#import <UIKit/UIKit.h>
typedef void(^ShowOrClose)(BOOL);
typedef void(^FunctionClickAction)(UIButton *);

@protocol SuspendBallDelegte <NSObject>

@optional
- (void)suspendBall:(UIButton *)subBall didSelectTag:(NSInteger)tag;

@end

@interface SuspendBall : UIButton

+ (instancetype)suspendBallWithFrame:(CGRect)ballFrame
                            delegate:(id<SuspendBallDelegte>)delegate
                   subBallImageArray:(NSArray *)imageArray;


@property (nonatomic, strong) NSArray *imageNameGroup;


@property (nonatomic, strong) UIColor *superBallBackColor;
@property (nonatomic ,assign) BOOL showFunction;
@property (nonatomic ,assign) BOOL stickToScreen;

@property (nonatomic, copy) ShowOrClose show;
@property (nonatomic, copy) ShowOrClose close;

@property (nonatomic, strong) UIView *functionMenu;
@property (nonatomic, weak) id<SuspendBallDelegte> delegate;

- (void)suspendBallShow;
@end
