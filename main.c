/** Copyright:
 *
 * Author:Hzhaolan
 * Date:2014-1-5
 * Description:check whether a number is aggregated number or not
 * PS:aggregated number is like this :112233 because 11+22 = 33
 *    or 1112113 because 111+2 = 113
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<stdarg.h>
#define max(a,b) ( ((a)>(b)) ? (a):(b) )
#define min(a,b) ( ((a)>(b)) ? (b):(a) )
#define notFircall 1
int count_of_num(int num);//to count how many bits the number is.
int fetch_num(int num,int startbit,int length);//fetch a num from a longer number
int isAggrnum(int num,int firNlen,...);//judge a aggregated num;

int main()
{
    int a,nlen ;
    a = 111222333;
    nlen = (a);
    if(isAggrnum(a,1)) printf("yes!");
    return 0;

}
/*************************************************
Function:count_of_num       // 函数名称
Description:to count a number's bits    // 函数功能、性能等的描述
Calls:(none)          // 被本函数调用的函数清单
Input:int num(the num to count)          // 输入参数
Output:(none)         // 对输出参数的说明
Return:(int)the bits of the number         // 函数返回值的说明
Others:         // 其它说明
*************************************************/
int count_of_num(int num)
{
    int i = 0;//the counter
    while(num !=0)
    {
        num = num /10;
        i++;
    }
    return i;
}
/*************************************************
Function:fetch_num       // 函数名称
Description:fetch a number from a longer bigger number    // 函数功能、性能等的描述
Calls:pow()          // 被本函数调用的函数清单
Input:int num(the longer num),
      int startbit(the start bit of fetched number),
      int lenth(the lenth of fetch num)          // 输入参数
Output:(none)         // 对输出参数的说明
Return:(int)the fetched number         // 函数返回值的说明
Others:         // 其它说明
*************************************************/
int fetch_num(int num,int startbit,int lenth)
{
    return (num / (int)pow(10,startbit-lenth)%(int)pow(10,lenth));
}
/*************************************************
Function:isAggrnum       // 函数名称
Description:judge a num is "Aggregated number" or not(details in file description~)    // 函数功能、性能等的描述
Calls:count_of_num(),fetch_num;          // 被本函数调用的函数清单
Input:int num(the num to be judged),
      int firNlen = 1(the lenth of the first number)// 输入参数
Output:(none)         // 对输出参数的说明
Return:(bool)0 means is not a aggregated number,
             1 means oppsite from above = =   // 函数返回值的说明
Others:         // 其它说明
*************************************************/
int isAggrnum(int num,int firNlen,...)
{
    int num_len, //the lenth of the num that input
        fir_num; // the first num of the "longer" num
    num_len = count_of_num(num);
    fir_num = fetch_num(num,num_len,firNlen);
    if( num_len < (2*firNlen + 1))  return 0;
   // int startOfsec,
      int   i,//the loop counter,and the lenth of second number
            startOfsec;//the start bit of second number
            startOfsec = num_len - firNlen;
    for(i = 1;i<=(num_len/2 +1);i++)
    {
        if(fir_num + fetch_num(num,startOfsec,i) == fetch_num(num,startOfsec - i,max(i,firNlen)) )
        {
            if(firNlen + i + max(i,firNlen) == num_len )
            {
                return 1;
            }
            else
            {
                return isAggrnum(fetch_num(num,startOfsec,startOfsec),i);
            }
        }
        else if(fir_num + fetch_num(num,startOfsec,i) == fetch_num(num,startOfsec - i,max(i,firNlen)+1))
        {
            if(firNlen + i + max(i,firNlen)+1 == num_len )
            {
                return 1;
            }
            else
            {
                return isAggrnum(fetch_num(num,startOfsec,startOfsec),i);
            }

        }
    }
    return 0;

}
