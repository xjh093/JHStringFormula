
参考：用Objective-C实现简单的数学字符串公式的计算

之前想改进一下 自动布局：JHAutoLayout中

UIView  
.jhView()  
.jh_addToView(self.view)  
.jh_frame(@"[x:10,y:80,w:2_w(0)-15,h:110]")  
.jh_bgColor(({  
    UIColor *color = [UIColor lightGrayColor];  
    color;  
})).jh_tag(@(100));  
里面

jh_frame(@"[x:10,y:80,w:2_w(0)-15,h:110]") 
想用一个数学字符串公式来表示x,y,w,h.

于是网上搜索到了这个：用Objective-C实现简单的数学字符串公式的计算

测试之后，发现还是会有一些小问题
然后就在它的基础之上进行了改进：
1.负数的情况
2.两个运算符在一起的情况(比如，加上一个负数)

对比效果：

//计算结果1：改进之前

//计算结果2：改进之后

//计算结果3：直接的数学公式计算

第一种：OK

    NSString *formula;

    formula = @"300";
    NSLog(@"计算结果1：%@",[FormulaStringCalcUtility calcComplexFormulaString:formula]);
    NSLog(@"计算结果2：%@",[NSString jh_caculateStringFormula:formula]);
    NSLog(@"计算结果3：%@",@([formula floatValue]));
    /**< 
     计算结果1：300.00
     计算结果2：300.00
     计算结果3：300
     */
第二种：OK

    formula = @"3*3+6/2";
    NSLog(@"计算结果1：%@",[FormulaStringCalcUtility calcComplexFormulaString:formula]);
    NSLog(@"计算结果2：%@",[NSString jh_caculateStringFormula:formula]);
    NSLog(@"计算结果3：%@",@(3*3+6/2.0));
    /**<
     计算结果1：12.00
     计算结果2：12.00
     计算结果3：12
     */
第三种：OK

    formula = @"(3+2*2+(1+2))*2-1*5+(5/10-10)";
    NSLog(@"计算结果1：%@",[FormulaStringCalcUtility calcComplexFormulaString:formula]);
    NSLog(@"计算结果2：%@",[NSString jh_caculateStringFormula:formula]);
    NSLog(@"计算结果3：%@",@((3+2*2+(1+2))*2-1*5+(5/10.0-10)));
    /**<
     计算结果1：5.50
     计算结果2：5.50
     计算结果3：5.5
     */
第四种：OK

    formula = @"-113+9/-3*5-20";
    NSLog(@"计算结果1：%@",[FormulaStringCalcUtility calcComplexFormulaString:formula]);
    NSLog(@"计算结果2：%@",[NSString jh_caculateStringFormula:formula]);
    NSLog(@"计算结果3：%@",@(-113+9/(-3.0)*5-20));
    /**<
     计算结果1：148.00
     计算结果2：148.00
     计算结果3：148
     */
第五种：NOT OK

    formula = @"-(1+(2-(3*(4.0/(5+6-8/2.0*4)))))";
    NSLog(@"计算结果1：%@",[FormulaStringCalcUtility calcComplexFormulaString:formula]);
    NSLog(@"计算结果2：%@",[NSString jh_caculateStringFormula:formula]);
    NSLog(@"计算结果3：%@",@(-(1+(2-(3*(4.0/(5+6-8/2.0*4)))))));
    /**<
     计算结果1：1.80
     计算结果2：5.40
     计算结果3：5.4
     */
第六种：NOT OK

    formula = @"-(1+(2-(3*(4/(5+6-7*8/9-(1+(2-(3*(4/(5+6-8/2*4))))))))))";
    NSLog(@"计算结果1：%@",[FormulaStringCalcUtility calcComplexFormulaString:formula]);
    NSLog(@"计算结果2：%@",[NSString jh_caculateStringFormula:formula]);
    NSLog(@"计算结果3：%@",@(-(1+(2-(3*(4.0/(5+6-7*8.0/9.0-(1+(2-(3*(4.0/(5+6-8/2.0*4))))))))))));
    
    /**<
     计算结果1：-1.02
     计算结果2：-22.285723
     计算结果3：-22.28571428571427
     */
测的不全，更复杂的估计，会有问题。
