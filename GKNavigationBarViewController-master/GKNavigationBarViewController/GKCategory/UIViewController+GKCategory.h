//
//  UIViewController+GKCategory.h
//  GKNavigationBarViewController
//
//  Created by QuintGao on 2017/7/7.
//  Copyright © 2017年 高坤. All rights reserved.
//  使用运行时为UIViewController添加分类

#import <UIKit/UIKit.h>
#import "GKNavigationBarConfigure.h"

extern NSString *const GKViewControllerPropertyChangedNotification;

// 交给单独控制器处理
// push代理
@protocol GKViewControllerPushDelegate <NSObject>

@optional

/// 左滑push，在这里创建将要push的控制器
- (void)pushToNextViewController;

/// push手势滑动开始
- (void)viewControllerPushScrollBegan;

/// push手势滑动进度更新
/// @param progress 进度（0-1）
- (void)viewControllerPushScrollUpdate:(float)progress;

/// push手速滑动结束
/// @param finished 是否完成push操作（YES：push成功 NO：push取消）
- (void)viewControllerPushScrollEnded:(BOOL)finished;

@end

// pop代理
@protocol GKViewControllerPopDelegate <NSObject>

@optional
/// pop手势滑动开始
- (void)viewControllerPopScrollBegan;

/// pop手势滑动进度更新
/// @param progress 进度（0-1）
- (void)viewControllerPopScrollUpdate:(float)progress;

/// pop手势滑动结束
/// @param finished 是否完成pop操作（YES：pop成功 NO：pop取消）
- (void)viewControllerPopScrollEnded:(BOOL)finished;

@end

// 返回拦截
@protocol GKGesturePopHandlerProtocol <NSObject>

@optional

/// 包括点击返回的手势返回，默认YES
- (BOOL)navigationShouldPop;

/// 手势返回拦截
- (BOOL)navigationShouldPopOnGesture;

/// 点击返回拦截，包括系统返回按钮点击和自定义返回按钮点击
- (BOOL)navigationShouldPopOnClick;

@optional
/// 返回手势冲突处理，当返回手势与其他手势冲突如：WKWebView中的手势，可实现以下方法返回YES，让返回手势与其他手势共存来解决手势冲突
- (BOOL)popGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer;

@end

@interface UIViewController (GKGesture)<GKGesturePopHandlerProtocol>

/** 是否禁止当前控制器的滑动返回(包括全屏返回和边缘返回) */
@property (nonatomic, assign) BOOL gk_interactivePopDisabled;

/** 是否禁止当前控制器的全屏滑动返回 */
@property (nonatomic, assign) BOOL gk_fullScreenPopDisabled;

/// 是否禁用系统手势处理，默认NO
/// 如果设置为YES，则可以更好的回调gk_popDelegate代理方法，即拦截手势返回时也可以回调
@property (nonatomic, assign) BOOL gk_systemGestureHandleDisabled;

/** 全屏滑动时，滑动区域距离屏幕左边的最大位置，默认是0：表示全屏都可滑动 */
@property (nonatomic, assign) CGFloat gk_popMaxAllowedDistanceToLeftEdge;

/** push代理 */
@property (nonatomic, weak) id<GKViewControllerPushDelegate> gk_pushDelegate;

/** pop代理，如果设置了gk_popDelegate，原来的滑动返回手势将失效 */
@property (nonatomic, weak) id<GKViewControllerPopDelegate> gk_popDelegate;

/** 自定义push转场动画 */
@property (nonatomic, weak) id<UIViewControllerAnimatedTransitioning> gk_pushTransition;

/** 自定义pop转场动画 */
@property (nonatomic, weak) id<UIViewControllerAnimatedTransitioning> gk_popTransition;

@end

@interface UIViewController (GKCategory)

/** 设置导航栏的透明度 */
@property (nonatomic, assign) CGFloat gk_navBarAlpha;

/** 设置状态栏类型 */
@property (nonatomic, assign) UIStatusBarStyle gk_statusBarStyle;

/** 设置状态栏是否隐藏(default is NO 即不隐藏) */
@property (nonatomic, assign) BOOL gk_statusBarHidden;

/** 自定义返回按钮图片 */
@property (nonatomic, strong) UIImage *gk_backImage;

/** 设置返回按钮的类型 */
@property (nonatomic, assign) GKNavigationBarBackStyle gk_backStyle;

/** 是否禁止调整当前控制器导航栏间距，默认GKConfigure.gk_disableFixSpace */
@property (nonatomic, assign) BOOL gk_disableFixNavItemSpace;

/** 导航栏左右按钮距离屏幕边缘的距离，需在设置左右item之前设置此属性 */
@property (nonatomic, assign) CGFloat gk_navItemLeftSpace;
@property (nonatomic, assign) CGFloat gk_navItemRightSpace;

/**
 返回按钮点击
 */
- (void)backItemClick:(id)sender;

/// 获取当前controller里的最高层可见viewController（可见的意思是还会判断self.view.window是否存在）
- (UIViewController *)gk_visibleViewControllerIfExist;

@end
