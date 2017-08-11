//
//  NSString+JHCaculationOfStringFormula.h
//  JHKit
//
//  Created by HaoCold on 2017/7/14.
//  Copyright © 2017年 HaoCold. All rights reserved.
//  字符串公式计算

#if 0
//#define N_J_LOG(fmt,...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define N_J_LOG(fmt,...) NSLog(fmt,##__VA_ARGS__);
#else
#define N_J_LOG(...)
#endif

#import <Foundation/Foundation.h>

@interface NSString (JHCaculationOfStringFormula)
+ (NSString *)jh_caculateStringFormula:(NSString *)formulaString;
@end
