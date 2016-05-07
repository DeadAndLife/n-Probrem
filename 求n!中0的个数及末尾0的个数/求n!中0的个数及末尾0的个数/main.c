//
//  main.c
//  求n!中0的个数及末尾0的个数
//
//  Created by qingyun on 16/5/7.
//  Copyright © 2016年 张小东. All rights reserved.
//

#include <stdio.h>

int zeroCount;

void ZeroCount(int subNum);
void isZero(int subNum);

int main(int argc, const char * argv[]) {
    printf("请输入\"n!\"中的n\n");
    int n;
    scanf("%d",&n);
    int count = 0;
    int sub = 1;
    for (int i = 1 ; i <= n; i++) {
        //在数字中，必须存在2 * 5才会出现10，但在运算中，2的倍数比5的倍数多了2.5倍，从1-5，2及其倍数就有2、4两个，而5只有一个，因此只需计算1-n中是5的倍数即可求出n!中末尾0的个数！！！
        if ( i %5 == 0) {
            count ++;
        }
        sub *= i;
    }
    isZero(sub);
    printf("\"n! = %d\"\n其中0的个数为:%d\n末尾的0的个数为:%d\n",sub,zeroCount,count);
    return 0;
}

void isZero(int subNum){
    //若数值非0，则判断末位值是否为0
    if (subNum != 0) {
        ZeroCount(subNum);
    }
}

void ZeroCount(int subNum){
    //若末位为0，则计数+1
    if (subNum %10 == 0) {
        zeroCount++;
    }
    //则直接对10取整
    subNum /= 10;
    //返回判断是否结束运算
    isZero(subNum);
}