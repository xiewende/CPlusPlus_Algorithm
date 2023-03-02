#include<stdio.h>
#include<string>
#include<iostream>
#include<time.h>
#include<vector>

using namespace std;

//创建一个IntBig类别
class IntBig {

public:
    int n;
    int* a;
    int* b;    //用整形数组存大整数

    //随机初始化大整数a
    void RandomAB(int n)
    {
        a = new int[n];
        b = new int[n];
        fill(a, a + n, 0);
        fill(b, b + n, 0);
        for (int i = 0; i < n; i++)
        {
            this->a[i] = rand() % 10;
            this->b[i] = rand() % 10;
        }
        this->n = n;
    }

     //输出a,b
    void display()
    {
        cout << endl << "A=";
        for (int i = 0; i < this->n; i++)
        {
            cout << this->a[i];
        }
        cout << endl << "B=";
        for (int i = 0; i < this->n; i++)
        {
            cout << this->b[i];
        }
    }

    //普通方法求大整数相乘
    int* NomalMul()
    {
        int length = this->n;

        int* C = new int[length + length];
        fill(C, C + length + length, 0);

        int tmp = 0;
        int n = 0;
        for (int i = length-1; i >= 0; i--)
        {
            int cur = 2 * length - 1 - n;
            for (int j = length - 1; j >= 0; j--)
            {
                int c = this->a[i] * this->b[j] + tmp + C[cur];
                if (c > 9)
                {
                    C[cur] = c % 10;
                    tmp = c / 10;
                }
                else
                {
                    C[cur] = c;
                    tmp = 0;
                }
                cur--;
            }

            if (tmp != 0)
            {
                C[cur] = tmp;
                tmp = 0;
            }
            n++;
        }
        

        ////输出结果
        //if (n <= 10)
        //{
        //    cout << endl << "a*b=";
        //    for (int i = 0; i < 2 * length; i++)
        //        cout << C[i];
        //}
        return C;
    }


    //分治法求大整数相乘
    void DividMul(int* res, int sta, int la, int stb, int lb, int stc)
    {
        //若两个个位数相乘
        if (la == lb && la == 1)
        {
            res[stc + 1] += (this->a[sta] * this->b[stb]);
            res[stc] += (res[stc + 1] / 10);
            res[stc + 1] %= 10;
            return;
        }
        //因为a,b位数相同，故只可出现位数相同或者位数差为1的情况
        else if (la != lb && (la == 1 || lb == 1))
        {
            int tmp;
            if (la == 1)
            {
                tmp = (this->b[stb] * 10 + this->b[stb + 1]) * this->a[sta] + res[stc + 2];
            }
            else
            {
                tmp = (this->a[sta] * 10 + this->a[sta + 1]) * this->b[stb] + res[stc + 2];
            }
            
            res[stc + 2] = tmp % 10;
            tmp = tmp / 10 + res[stc + 1];
            res[stc + 1] = tmp % 10;
            res[stc] += (tmp / 10);
            return;
        }
        DividMul(res, sta + la / 2, la - la / 2, stb + lb / 2, lb - lb / 2, stc + la / 2 + lb / 2);
        DividMul(res, sta , la / 2, stb + lb / 2, lb - lb / 2, stc + lb / 2);
        DividMul(res, sta + la / 2, la - la / 2, stb , lb / 2, stc + la / 2 );
        DividMul(res, sta, la / 2, stb, lb / 2, stc);
    }


    //改进的分治法求大整数相乘
    void DividMulBetter(int *a,int *b,int *c,int sta,int stb,int endc,int la,int lb)
    {
        if (la == 1 && lb == 1)
        {
            int tmp = this->a[sta] * this->b[stb];
            c[endc] = c[endc] + tmp % 10;
            c[endc - 1] = c[endc - 1] + tmp / 10;
            return;
        }

        int lbd = la / 2 + lb / 2;
        int* BD = new int[lbd];
        fill(BD, BD + lbd, 0);
        DividMulBetter(a,b,BD, sta+la - la / 2, stb + lb - lb/ 2, lbd - 1, la / 2, lb / 2);
        ArrayAdd(c, BD, la + lb - 1, lbd - 1);
        ArrayAdd(c, BD, la + lb - 1 - la / 2, lbd - 1);
        delete[] BD;

        int* AB = new int[la - la / 2];
        bool flag1 = ArraySub(a, AB, sta, sta + la - la / 2 - 1, sta + la - 1, la - la / 2);
        int* CD = new int[lb - lb / 2];
        bool flag2 = ArraySub(b, CD, stb, stb + lb - lb / 2 - 1, stb + lb - 1, lb - lb / 2);
        int labcd = la - la / 2 + lb - lb / 2;
        int* ABCD = new int[labcd];
        fill(ABCD, ABCD + labcd, 0);
        DividMulBetter(AB, CD, ABCD, 0, 0, labcd - 1, la - la / 2, lb - lb / 2);
        if ((flag1 ^ flag2) == 0)
        {
            for (int i = 0; i < labcd; i++)
            {
                ABCD[i] = -ABCD[i];
            }
        }
        ArrayAdd(c, ABCD, la + lb - 1 - la / 2, labcd - 1);
        delete[] AB;
        delete[] CD;
        delete[] ABCD;

        int lac = la - la / 2 + lb - lb / 2;
        int* AC = new int[lac];
        fill(AC, AC + lac, 0);
        DividMulBetter(a, b, AC, sta, stb, lac - 1, la - la / 2, lb - lb / 2);
        ArrayAdd(c, AC, la + lb - 1 - la / 2, lac - 1);
        ArrayAdd(c, AC, la + lb - 1 - la / 2 - lb / 2, lac - 1);
        delete[] AC;

        for (int i = endc; i > 0; i--)
        {
            if (c[i] < 0)
            {
                c[i] += 10;
                c[i - 1]--;
            }
        }
    }

    //数组分为两部分并相减
    bool ArraySub(int* a, int* res, int sta, int mida, int enda, int lr)
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
    void ArrayAdd(int* A, int* B,int enda,int endb)
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

};

int main(void)
{
    IntBig data;
    clock_t start1, start2, start3, finish1, finish2, finish3;
    double time1, time2, time3;
    long int n = 1;

    while (n <= 10000000000)
    {
        n *= 10;

        if (n < 1000)
        {
            // printf("when n is %d:\n", n);
            cout << n << endl;
            data.RandomAB(n);
            start1 = clock();
            for (int i = 1; i < 1000; i++)
            {
                data.NomalMul();
            }
            finish1 = clock();

            int* res = new int[n + n];
            fill(res, res + n + n, 0);

            start2 = clock();
            for(int i=0;i<1000;i++)
                data.DividMul(res, 0, n, 0, n, 0);
            finish2 = clock();


            int* res1 = new int[n + n];
            fill(res1, res1 + n + n, 0);

            start3 = clock();
            for(int i=0;i<1000;i++)
                data.DividMulBetter(data.a, data.b, res1, 0, 0, n + n - 1, n, n);
            finish3 = clock();

            time1 = (double)(finish1 - start1)/1000;
            time2 = (double)(finish2 - start2)/1000;
            time3 = (double)(finish3 - start3)/1000;
            printf("Normal Time:%f\n", time1);
            printf("DividMethod Time:%f\n", time2);
            printf("ImprovedDividMethod Time:%f\n", time3);
        }
        else
        {
            printf("when n is %d:\n", n);
            data.RandomAB(n);
            start1 = clock();
            data.NomalMul();
            finish1 = clock();

            int* res = new int[n + n];
            fill(res, res + n + n, 0);

            start2 = clock();
            data.DividMul(res, 0, n, 0, n, 0);
            finish2 = clock();


            int* res1 = new int[n + n];
            fill(res1, res1 + n + n, 0);

            start3 = clock();
            data.DividMulBetter(data.a, data.b, res1, 0, 0, n + n - 1, n, n);
            finish3 = clock();

            time1 = (double)(finish1 - start1);
            time2 = (double)(finish2 - start2);
            time3 = (double)(finish3 - start3);

            printf("Normal Time:%f\n", time1);
            printf("DividMethod Time:%f\n", time2);
            printf("ImprovedDividMethod Time:%f\n", time3);
        }
       
    }
    system("pause");
    return 0;
}