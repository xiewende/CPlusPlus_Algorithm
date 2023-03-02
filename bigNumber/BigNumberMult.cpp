#include<stdio.h>
#include<string>
#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

//自定义一个大数相乘的类

class BigNumberMult{

public:
    //随机初始化一个n位的大整数
    int* random_get_num(long long n)
    {
        int *num = new int[n];
        fill(num, num + n, 0);
        for (long long i = 0; i < n; i++)
        {
            num[i] = rand() % 10;
        }
        return num;
    }

    //普通方法 num1 num2相乘的两个数，数组存储，len为num1 num2位数
    int* genera_mult(int *num1, int *num2, long long len){
        //1、建立相乘的结果并且初始化，其结果位数长度小于 len+len
        long long mult_len = 2 * len;
        int *res = new int[mult_len];
        fill(res, res + mult_len, 0);

        //2、按照普通的方法一个一个位数相乘相加即可
        for (long long i = 0; i < len; i++) { //逐位相乘
            for (long long j = 0; j < len; j++) {
                res[i + j + 1] += num1[i] * num2[j];
            }
        }
        for (long long i = mult_len-1; i >=0 ; i--) {//处理进位
            if (res[i] < 10) continue;
            res[i - 1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
        //3、判断最高位是否有进位
        return res[0]==0 ? res+1 : res;
    }

    //分治法
    int divi_multi(int*num1,int a_idx,int a_len,int*num2,int b_idx,int b_len,int move,int* res){
        //当子问题为两个个位数相乘时
        if(a_len == b_len && a_len == 1){  
            res[move + 1] += num1[a_idx] * num2[b_idx] ;
            res[move] += (res[move + 1] / 10);
            res[move + 1] %= 10;
            return 1;
        }
        //当分治切割的时候，由于两个数字位数相同，故只可出现位数相同或者位数差为1的情况
        else if (a_len != b_len && (a_len == 1 || b_len == 1))
        {
            int tmp;
            if (a_len == 1)
            {
                tmp = ( num2[b_idx] * 10 + num2[b_idx + 1] ) * num1[a_idx] + res[move + 2];
            }
            else
            {
                tmp = (num1[a_idx] * 10 + num1[a_idx + 1]) * num2[b_idx] + res[move + 2];
            }
            res[move + 2] = tmp % 10;
            tmp = tmp / 10 + res[move + 1];
            res[move + 1] = tmp % 10;
            res[move] += (tmp / 10);
            return 1;
        }
        int mid_a = a_len / 2;
        int mid_b = b_len / 2;
        //对问题的分解
        divi_multi(num1,a_idx + mid_a, a_len - mid_a,num2,b_idx + mid_b,b_len - mid_b,move + mid_a + mid_b,res);
        divi_multi(num1, a_idx , mid_a, num2,b_idx + mid_b, b_len - mid_b, move + mid_b,res);
        divi_multi(num1, a_idx + mid_a, a_len - mid_a,num2, b_idx , mid_b, move + mid_a ,res);
        divi_multi(num1, a_idx, mid_a,num2, b_idx, mid_b, move,res);
        return 1;
        }

    //改进的分治法求大整数相乘
    void divi_multi_better(int *num1,int *num2,int *res,int a_idx,int b_idx,int end_resIdx,int a_len,int b_len)
    {
        if (a_len == 1 && b_len == 1)
        {
            int tmp = num1[a_idx] * num2[b_idx];
            res[end_resIdx] = res[end_resIdx] + tmp % 10;
            res[end_resIdx - 1] = res[end_resIdx - 1] + tmp / 10;
            return;
        }
        int lbd = a_len / 2 + b_len / 2;
        int* BD = new int[lbd];
        fill(BD, BD + lbd, 0);
        divi_multi_better(num1,num2,BD, a_idx+a_len - a_len / 2, b_idx + b_len - b_len/ 2, lbd - 1, a_len / 2, b_len / 2);
        ArrayAdd(res, BD, a_len + b_len - 1, lbd - 1);
        ArrayAdd(res, BD, a_len + b_len - 1 - a_len / 2, lbd - 1);
        delete[] BD;
        int* AB = new int[a_len - a_len / 2];
        bool flag1 = ArraySub(num1, AB, a_idx, a_idx + a_len - a_len / 2 - 1, a_idx + a_len - 1, a_len - a_len / 2);
        int* CD = new int[b_len - b_len / 2];
        bool flag2 = ArraySub(num2, CD, b_idx, b_idx + b_len - b_len / 2 - 1, b_idx + b_len - 1, b_len - b_len / 2);
        int labcd = a_len - a_len / 2 + b_len - b_len / 2;
        int* ABCD = new int[labcd];
        fill(ABCD, ABCD + labcd, 0);
        divi_multi_better(AB, CD, ABCD, 0, 0, labcd - 1, a_len - a_len / 2, b_len - b_len / 2);
        if ((flag1 ^ flag2) == 0)
        {
            for (int i = 0; i < labcd; i++)
            {
                ABCD[i] = -ABCD[i];
            }
        }
        ArrayAdd(res, ABCD, a_len + b_len - 1 - a_len / 2, labcd - 1);
        delete[] AB;
        delete[] CD;
        delete[] ABCD;
        int lac = a_len - a_len / 2 + b_len - b_len / 2;
        int* AC = new int[lac];
        fill(AC, AC + lac, 0);
        divi_multi_better(num1, num2, AC, a_idx, b_idx, lac - 1, a_len - a_len / 2, b_len - b_len / 2);
        ArrayAdd(res, AC, a_len + b_len - 1 - a_len / 2, lac - 1);
        ArrayAdd(res, AC, a_len + b_len - 1 - a_len / 2 - b_len / 2, lac - 1);
        delete[] AC;
        for (int i = end_resIdx; i > 0; i--)
        {
            if (res[i] < 0)
            {
                res[i] += 10;
                res[i - 1]--;
            }
        }
    }

    //数组分为两部分并相减
    bool static  ArraySub(int* a, int* res, int sta, int mida, int enda, int lr)
    {
        fill(res, res + lr, 0);
        int i = mida;
        int j = enda;
        int k = lr - 1;
        while (j > mida)
        {
            res[k--] = a[i--] - a[j--];
        }
        if (i == sta)
            res[k] = a[i];
        k = 0;
        while (k < lr && res[k] == 0)
            k++;
        if (k == lr)
            return 1;

        bool flag = (res[k] > 0);
        i = lr - 1;
        while (i > k)
        {
            if (flag == 1 && res[i] < 0)
            {
                res[i] = 10 - abs(res[i]);
                res[i - 1]--;
            }
            else if (flag == 0 && res[i] > 0)
            {
                res[i] = 10 - abs(res[i]);
                res[i - 1]++;
            }
            else
            {
                res[i] = abs(res[i]);
            }
            i--;
        }
        res[k] = abs(res[k]);
        return flag;

    }
    
    //两个数组相加,其中A的位数比B大，且将结果存入A中
    void static ArrayAdd(int* A, int* B,int enda,int endb)
    {
        int tmp = 0;
        for (int i = endb; i >= 0; i--)
        {
            A[enda] = A[enda] + B[i] + tmp;
            tmp = A[enda] / 10;
            A[enda] %= 10;
            enda--;
        }
        while (tmp != 0 && enda >= 0)
        {
            int x = A[enda] + tmp;
            if (x > 9)
            {
                A[enda] = x % 10;
                tmp = x / 10;
                enda--;
            }
            else
            {
                A[enda] = x;
                break;
            }
        }
    }

    //输出num1 num2
    void display(int *num1,int *num2,long long len)
    {
        cout << endl << "num1=";
        for (long long i = 0; i < len; i++)
        {
            cout << num1[i];
        }
        cout << endl << "num2=";
        for (long long i = 0; i < len; i++)
        {
            cout << num2[i];
        }
        cout << endl;
    }

    //输出相乘的结果
    void print_ans(int *ans,int len){
        //去首个0
        ans = ans[0] == 0 ? ans + 1 : ans;
        for (int i = 0; i < len;i++)
        {
            if(ans[i]<0)
                break;
            cout << ans[i];
        }
        cout << endl;
    }
 };

int main()
{

    BigNumberMult bignumbermult;
    //三种方法的执行时间
    clock_t start1, start2, start3, finish1, finish2, finish3;
    double time1, time2, time3;
    long long n = 1;

    while(n <= 1000000){
        n = n * 10;
        cout << "this epochs n is " << n <<endl;
        int* num1 = bignumbermult.random_get_num(n);
        int* num2 = bignumbermult.random_get_num(n);
        //位数少计算快看不出时间
        if(n < 1000){
            //1、普通方式
            int *ans;
            start1 = clock();
            //计算1000次
            for (int i = 0; i < 1000; i++)
            {
                ans = bignumbermult.genera_mult(num1, num2, n);
            }
            finish1 = clock();
            cout << "genera_mult,ans = ";
            bignumbermult.print_ans(ans, 2 * n) ;

            //2、分治法
            int* res = new int[n + n];
            fill(res, res + n + n, 0);
            start2 = clock();
            for(int i=0;i<1000;i++)
                bignumbermult.divi_multi(num1, 0, n, num2,0, n, 0,res);
            finish2 = clock();
            cout << "divi_multi,ans = ";
            bignumbermult.print_ans(res, 2 * n) ;

            //3、改进分治
            int* res1 = new int[n + n];
            fill(res1, res1 + n + n, 0);
            start3 = clock();
            for(int i=0;i<1000;i++)
                bignumbermult.divi_multi_better(num1,num2, res1, 0, 0, n + n - 1, n, n);
            finish3 = clock();
             cout << "divi_multi_better,ans = ";
            bignumbermult.print_ans(res, 2 * n) ;


            time1 = (double)(finish1 - start1)/1000;
            time2 = (double)(finish2 - start2)/1000;
            time3 = (double)(finish3 - start3)/1000;
            cout << "genera_mult time =" << time1 << endl;
            cout << "divi_multi time =" << time2 <<endl;
            cout << "divi_multi_better time =" << time3 <<endl<<endl;
        }else{

            //1、普通方式
            int *ans;
            start1 = clock();
            ans = bignumbermult.genera_mult(num1, num2, n);
            finish1 = clock();
            //cout << "genera_mult,ans = ";
            //bignumbermult.print_ans(ans, 2 * n) ;

            //2、分治法
            int* res = new int[n + n];
            fill(res, res + n + n, 0);
            start2 = clock();
            bignumbermult.divi_multi(num1, 0, n, num2,0, n, 0,res);
            finish2 = clock();
            //cout << "divi_multi,ans = ";
            //bignumbermult.print_ans(res, 2 * n) ;

            //3、改进分治
            int* res1 = new int[n + n];
            fill(res1, res1 + n + n, 0);
            start3 = clock();
            bignumbermult.divi_multi_better(num1,num2, res1, 0, 0, n + n - 1, n, n);
            finish3 = clock();
            //cout << "divi_multi_better,ans = ";
            //bignumbermult.print_ans(res, 2 * n) ;


            time1 = (double)(finish1 - start1);
            time2 = (double)(finish2 - start2);
            time3 = (double)(finish3 - start3);
            cout << "genera_mult time =" << time1 << endl;
            cout << "divi_multi time =" << time2 <<endl;
            cout << "divi_multi_better time =" << time3 <<endl<<endl;
        }
    }    
    system("pause");
    return 0;
}
