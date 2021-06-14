//
//  SPPageContentView.h
//  Radio
//
//  Created by sparrow on 09/02/2017.
//  Copyright © 2017 qzone. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SPPageProtocol.h"

@interface SPPageContentView : UIScrollView<UIScrollViewDelegate>

- (CGRect)calcVisibleViewControllerFrameWithIndex:(NSInteger)index;
- (CGPoint)calOffsetWithIndex:(NSInteger)index;
- (NSInteger)calcIndex;

- (void)setItem:(id<SPPageControllerDataSource>)item;

@end
