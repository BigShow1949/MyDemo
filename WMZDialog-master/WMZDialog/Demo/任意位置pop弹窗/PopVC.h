//
//  PopVC.h
//  WMZDialog
//
//  Created by wmz on 2019/9/16.
//  Copyright © 2019 wmz. All rights reserved.
//

#import "BaseVC.h"
NS_ASSUME_NONNULL_BEGIN

@interface PopVC :BaseVC

@end


@interface WXCell:UITableViewCell
@property(nonatomic,strong)UILabel *myLa;
@property(nonatomic,strong)UIImageView *myImage;
@property(nonatomic,strong)UIView *myLine;
@end

NS_ASSUME_NONNULL_END
