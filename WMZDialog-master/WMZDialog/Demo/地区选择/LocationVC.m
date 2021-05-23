//
//  LocationVC.m
//  WMZDialog
//
//  Created by wmz on 2019/8/15.
//  Copyright © 2019年 wmz. All rights reserved.
//

#import "LocationVC.h"
#import "WMZDialog.h"
@interface LocationVC ()

@end

@implementation LocationVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dataArr = @[@"省",@"省市",@"省市区",@"pickview显示",@"tableview显示",@"自定义传入数据"];
}

- (void)action:(UIButton*)sender{
    if (sender.tag == 5) {
        [self customData];return;
    }
    Dialog()
    .wEventMenuClickSet(^(id anyID, NSInteger section, NSInteger row) {
        NSLog(@"选中 %@ %ld %ld",anyID,section,row);
    })
    .wEventOKFinishSet(^(id anyID, id otherData) {
        NSLog(@"选中 %@ %@",anyID,otherData);
    })
    //默认选中
    .wListDefaultValueSet(sender.tag<4?@[@"广东省",@(4),@"440514"]:nil) //可传地区 名字/id/index (此处4是汕头市 440514是潮南区的编号)
    //分隔符
    .wSeparatorSet(@",")
    .wChainTypeSet(sender.tag<4?ChainPickView:ChainTableView)
    .wLocationTypeSet(sender.tag<3?sender.tag+1:3)
    .wTypeSet(DialogTypeLocation)
    .wStart();
}

//自定义传入数据
- (void)customData{
     Dialog()
    //三列
    .wLocationTypeSet(3)
    .wDataSet([self customTree])
    .wTypeSet(DialogTypeLocation)
    .wStart();
}
//组合数据
- (WMZTree*)customTree{
    //需要把你的json数据组合成WMZTree结构
    
    //首 必要
    WMZTree *tree = [WMZTree new];
    //第一列 你的第一层数据
    for (int i = 0; i<10; i++) {
        WMZTree *oneTree = [[WMZTree alloc]initWithDetpth:1 withName:[NSString stringWithFormat:@"第一列%d",i] withID:@""];
        //第二列
        for (int j = 0; j<10; j++) {
            
            WMZTree *twoTree = [[WMZTree alloc]initWithDetpth:2 withName:[NSString stringWithFormat:@"第二列%d_%d",i,j] withID:@""];
            [oneTree.children addObject:twoTree];
            
            //第三列 以此类推 无限列
            for (int z = 0; z<10; z++) {
                WMZTree *threeTree = [[WMZTree alloc]initWithDetpth:3 withName:[NSString stringWithFormat:@"第三列%d_%d",j,z] withID:@""];
                [twoTree.children addObject:threeTree];
                
            }
        }
        //把第一列加进去
        [tree.children addObject:oneTree];
    }
    
    return  tree;
}
@end
