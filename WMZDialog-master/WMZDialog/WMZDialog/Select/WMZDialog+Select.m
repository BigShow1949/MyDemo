
//
//  WMZDialog+Select.m
//  WMZDialog
//
//  Created by wmz on 2019/6/20.
//  Copyright © 2019年 wmz. All rights reserved.
//

#import "WMZDialog+Select.h"
@implementation WMZDialog (Select)
- (UIView*)selectAction{
    
    [self.mainView addSubview:self.titleLabel];
     self.titleLabel.frame = CGRectMake(self.wMainOffsetX, self.wTitle.length?self.wMainOffsetY:0, self.wWidth-self.wMainOffsetX*2, [WMZDialogTool sizeForTextView:CGSizeMake(self.wWidth-self.wMainOffsetX*2, CGFLOAT_MAX) text:self.titleLabel.text font:self.titleLabel.font.pointSize].height);

     [self.mainView addSubview:self.textLabel];
     self.textLabel.frame =  CGRectMake(self.wMainOffsetX,CGRectGetMaxY(self.titleLabel.frame)+ (self.wMessage.length?self.wMainOffsetY:0), self.wWidth-self.wMainOffsetX*2, [WMZDialogTool sizeForTextView:CGSizeMake(self.wWidth-self.wMainOffsetX*2, CGFLOAT_MAX) text:self.textLabel.text font:self.textLabel.font.pointSize].height);

    self.tableView.frame = CGRectMake(0, CGRectGetMaxY(self.textLabel.frame)+ (self.wMessage.length||self.wTitle.length?self.wMainOffsetY:0), self.wWidth, self.wCellHeight*([(NSArray*)self.wData count]>self.wListScrollCount?self.wListScrollCount:[(NSArray*)self.wData count]));
    [self.mainView addSubview:self.tableView];
    
    
    if (self.wAddBottomView||
        self.wMultipleSelection) {
        UIView *view =  [self addBottomView:CGRectGetMaxY(self.tableView.frame)];
        [self reSetMainViewFrame:CGRectMake(0, 0, self.wWidth,CGRectGetMaxY(view.frame))];
        [self.OKBtn removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
        [self.OKBtn addTarget:self action:@selector(mySelectAction:) forControlEvents:UIControlEventTouchUpInside];
    }else{
        [self reSetMainViewFrame:CGRectMake(0, 0, self.wWidth,CGRectGetMaxY(self.tableView.frame))];
    }
    
    
    return self.mainView;
}

- (void)mySelectAction:(UIButton*)btn{
    DialogWeakSelf(self)
    [self closeView:^{
        DialogStrongSelf(weakObject)
        if (strongObject.wEventOKFinish) {
            if (self.wMultipleSelection) {
                strongObject.wEventOKFinish(strongObject.selectArr, strongObject.pathArr);
            }else{
                strongObject.wEventOKFinish(strongObject.selectArr.count?strongObject.selectArr.firstObject:nil,
                                          strongObject.pathArr.count?strongObject.pathArr.firstObject:nil);
                
            }
        }
    }];
}

@end
